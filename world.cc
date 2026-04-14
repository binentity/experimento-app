#include "world.h"
#include "base-system.h"

World::World()
    : screen_width(2550)
    , screen_height(1440)
    , screen_vector(screen_width, screen_height)
    , windowTitle("Happiness")
    , screenMode(screen_vector)
    , window(screenMode, windowTitle)
    , difference(0)
{
    auto figure = std::make_unique<sf::CircleShape>(sf::CircleShape(50.f));
    figure->setPosition(sf::Vector2f(100.f, 100.f));

    shapes.push_back(std::move(figure));

    systems.push_back(std::make_unique<BaseSystem>());
}

void World::tick()
{
    difference = timer.restart().asSeconds();
}

void World::execute()
{
    while (window.isOpen()) {
        tick();

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        update();
        display();
    }
}

void World::update() const
{
    for (const auto &system : systems) {
        system->apply(difference);
    }
}

void World::display()
{
    window.clear(sf::Color::Green);
    window.display();
}