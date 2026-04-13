#ifndef EXPERIMENTO_APP_WORLD_H
#define EXPERIMENTO_APP_WORLD_H

#include "system.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

constexpr unsigned int WIDTH = 2550;
constexpr unsigned int HEIGHT = 1440;
constexpr sf::Vector2u screenVector(WIDTH, HEIGHT);

class World
{
    std::vector<std::unique_ptr<System>> systems;

public:
    void execute() const;
    void update(float dt) const;

    World();
    ~World() = default;
};

#endif //EXPERIMENTO_APP_WORLD_H
