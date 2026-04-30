#ifndef EXPERIMENTO_APP_SYSTEM_H
#define EXPERIMENTO_APP_SYSTEM_H
#include "gui/message-box.h"
#include <SFML/Window/Event.hpp>
#include <optional>

class System
{
public:
    virtual void apply(const std::vector<std::shared_ptr<MessageBox>>& shapes, float dt) = 0;
    virtual void update(const std::optional<sf::Event> &event) = 0;
    virtual ~System() = default;
};

#endif //EXPERIMENTO_APP_SYSTEM_H
