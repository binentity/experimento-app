#include "world.h"
#include "base-system.h"
#include "renderer.h"

World::World()
    : screenWidth(2550)
    , screenHeight(1440)
    , screenVector(screenWidth, screenHeight)
    , windowTitle("Happiness")
    , window(nullptr)
    , difference(0)
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    const sf::VideoMode mode(screenVector);
    window = std::make_shared<sf::RenderWindow>(
        sf::RenderWindow(mode, windowTitle, sf::State::Windowed, settings));

    events = {};
}

void World::tick()
{
    difference = timer.restart().asSeconds();
}

void World::execute()
{
    sf::CircleShape originShape(5.f);
    originShape.setPosition(sf::Vector2f(10.f, 10.f));

    shapes.push_back(std::make_shared<sf::CircleShape>(originShape));
    systems.push_back(std::make_unique<BaseSystem>());

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
        //events.push_back(std::make_shared<std::optional<sf::Event>>(event));
        for (const auto &system : systems) {
            system->update(event, window);
        }
    }
}