#ifndef EXPERIMENTO_APP_SYSTEM_H
#define EXPERIMENTO_APP_SYSTEM_H

class System
{
public:
    virtual void apply(float dt) = 0;
    virtual ~System() = default;
};

#endif //EXPERIMENTO_APP_SYSTEM_H
