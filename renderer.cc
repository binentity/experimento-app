#include "renderer.h"

void Renderer::render(const std::shared_ptr<sf::RenderWindow> &device) const
{
    device->clear(sf::Color(80, 80, 80, 0));
    for (const auto &shape : shapes) {
        device->draw(*shape);
    }
    device->display();
}

Renderer::Renderer(const std::vector<std::shared_ptr<sf::CircleShape>> &shapes)
    : shapes(shapes)
{}