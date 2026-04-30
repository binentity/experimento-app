#ifndef EXPERIMENTO_APP_WORLD_H
#define EXPERIMENTO_APP_WORLD_H

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "gui/message-box.h"
#include "system.h"

class World
{
    const sf::Vector2u screenSize;
    const std::string windowTitle;

    sf::Clock timer;

    std::shared_ptr<sf::RenderWindow> window;
    float dt;

    std::vector<std::unique_ptr<System>> systems;
    std::vector<std::shared_ptr<MessageBox>> shapes;

    void tick();
    void processSystems() const;
    void processMainEvents() const;

public:
    void execute();
    World();
    virtual ~World() = default;
};
#endif //EXPERIMENTO_APP_WORLD_H
