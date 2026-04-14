#ifndef EXPERIMENTO_APP_WORLD_H
#define EXPERIMENTO_APP_WORLD_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "system.h"

class World
{
    const unsigned int screen_width;
    const unsigned int screen_height;

    const sf::Vector2u screen_vector;
    const std::string windowTitle;
    const sf::VideoMode screenMode;

    sf::Clock timer;

    sf::RenderWindow window;
    float difference;

    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::unique_ptr<sf::CircleShape>> shapes;

    void tick();
    void update() const;
    void display();

public:
    void execute();
    World();
    virtual ~World() = default;
};
#endif //EXPERIMENTO_APP_WORLD_H
