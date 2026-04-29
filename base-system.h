#ifndef EXPERIMENTO_APP_BASE_SYSTEM_H
#define EXPERIMENTO_APP_BASE_SYSTEM_H

#include "system.h"

class BaseSystem : public System
{
public:
    void apply(float dt) override;
    void update(
        const std::optional<sf::Event> &event,
        const std::shared_ptr<sf::RenderWindow> &window) override;
};

#endif //EXPERIMENTO_APP_BASE_SYSTEM_H
