#include "base-system.h"

#include <iostream>

BaseSystem::BaseSystem()
= default;

void BaseSystem::apply(const std::vector<std::shared_ptr<MessageBox>>& shapes, const float dt)
{
    for (const auto &box : shapes) {
        box->setText(std::to_string(dt));
    }
}

void BaseSystem::update(
    const std::optional<sf::Event> &event)
{
}