#ifndef EXPERIMENTO_APP_BASE_SYSTEM_H
#define EXPERIMENTO_APP_BASE_SYSTEM_H

#include "system.h"

class BaseSystem : public System
{
public:
    void apply(float dt) override;
};



#endif //EXPERIMENTO_APP_BASE_SYSTEM_H
