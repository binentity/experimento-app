#include "world.h"

constexpr std::string WINDOW_TITLE = "Happiness";

void World::execute() const
{
    const sf::VideoMode mode(screenVector);
    sf::RenderWindow window(mode, WINDOW_TITLE);

    sf::Clock clock;

    while (window.isOpen()) {
        const float dt = clock.restart().asSeconds();

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        update(dt);

        window.clear(sf::Color::Green);

        window.display();
    }
}

void World::update(const float dt) const
{
    for (const auto& system : systems) {
        system->apply(dt);
    }
}