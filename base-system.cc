#include "base-system.h"

#include <iostream>

void BaseSystem::apply(const float dt)
{
    std::cout << "Delta time: " << dt << std::endl;
}

void BaseSystem::update(
    const std::optional<sf::Event> &event, const std::shared_ptr<sf::RenderWindow>& window)
{
    if (event->is<sf::Event::Closed>()) {
        window->close();
    }

    if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::NumpadDecimal) {
            window->close();
        }
    }
}