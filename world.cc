#include "world.h"
#include "base-system.h"
#include "renderer.h"

World::World()
    : screen_width(2550)
    , screen_height(1440)
    , screenVector(screen_width, screen_height)
    , windowTitle("Happiness")
    , screenMode(screenVector)
    , window(std::make_unique<sf::RenderWindow>(sf::RenderWindow(screenMode, windowTitle)))
    , difference(0)
{
    sf::CircleShape originShape(5.f);
    originShape.setPosition(sf::Vector2f(10.f, 10.f));

    shapes.push_back(std::make_shared<sf::CircleShape>(originShape));
    systems.push_back(std::make_unique<BaseSystem>());
}

void World::tick()
{
    difference = timer.restart().asSeconds();
}

void World::execute()
{
    const Renderer renderer(shapes);
    while (window->isOpen()) {
        tick();
        update();
        renderer.render(window);
    }
}

void World::update() const
{
    eventExecute();

    for (const auto &system : systems) {
        system->apply(difference);
    }
}

void World::eventExecute() const
{
    while (const std::optional<sf::Event> event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }

        if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::NumpadDecimal) {
                window->close();
            }
        }
    }
}