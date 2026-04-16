#include "base-system.h"

#include <iostream>

void BaseSystem::apply(const float dt)
{
    std::cout << "Delta time: " << dt << std::endl;
}