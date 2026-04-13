#include "base-system.h"

#include <iostream>

void BaseSystem::apply(float dt)
{
    std::cout << "base system has been applied..." << dt << std::endl;
}