#ifndef EXPERIMENTO_APP_SYSTEM_H
#define EXPERIMENTO_APP_SYSTEM_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>

class System
{
public:
    virtual void apply(float dt) = 0;
    virtual void update(
        const std::optional<sf::Event> &event, const std::shared_ptr<sf::RenderWindow> &window) = 0;
    virtual ~System() = default;
};

#endif //EXPERIMENTO_APP_SYSTEM_H
