#ifndef EXPERIMENTO_APP_BASE_SYSTEM_H
#define EXPERIMENTO_APP_BASE_SYSTEM_H

#include "gui/message-box.h"
#include "system.h"
#include <SFML/Graphics/CircleShape.hpp>

class BaseSystem : public System
{
public:
    BaseSystem();
    void apply(const std::vector<std::shared_ptr<MessageBox>>& shapes, float dt) override;
    void update(const std::optional<sf::Event> &event) override;
};

#endif //EXPERIMENTO_APP_BASE_SYSTEM_H
