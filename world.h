#ifndef EXPERIMENTO_APP_WORLD_H
#define EXPERIMENTO_APP_WORLD_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "system.h"
#include <deque>

class World
{
    const unsigned int screenWidth;
    const unsigned int screenHeight;

    const sf::Vector2u screenVector;
    const std::string windowTitle;

    sf::Clock timer;

    std::shared_ptr<sf::RenderWindow> window;
    float difference;

    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::shared_ptr<sf::CircleShape>> shapes;
    std::vector<std::shared_ptr<std::optional<sf::Event>>> events;

    void tick();
    void update() const;
    void eventExecute() const;

public:
    void execute();
    World();
    virtual ~World() = default;
};
#endif //EXPERIMENTO_APP_WORLD_H
