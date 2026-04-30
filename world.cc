#include "world.h"
#include "base-system.h"
#include "gui/message-box.h"
#include "renderer.h"
#include <iostream>

World::World()
    : screenSize(2550, 1440)
    , windowTitle("Happiness")
    , window(nullptr)
    , dt(0)
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    const sf::VideoMode mode(screenSize);
    window = std::make_shared<sf::RenderWindow>(
        sf::RenderWindow(mode, windowTitle, sf::State::Windowed, settings));
}

void World::execute()
{
    shapes.push_back(std::make_shared<MessageBox>(MessageBox("../resources/font.ttf")));
    systems.push_back(std::make_unique<BaseSystem>());

    const Renderer renderer(shapes);
    while (window->isOpen()) {
        tick();
        processSystems();
        renderer.render(window);
    }
}

void World::processMainEvents() const
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
        for (const auto &system : systems) {
            system->update(event);
        }
    }
}

void World::processSystems() const
{
    processMainEvents();
    for (const auto &system : systems) {
        system->apply(shapes, dt);
    }
}

void World::tick()
{
    dt = timer.restart().asSeconds();
}