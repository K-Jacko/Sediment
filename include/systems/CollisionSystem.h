#pragma once
#include "interface/ISystem.h"
#include "object/World.h"

class CollisionSystem : public ISystem
{
public:
    CollisionSystem(World* world);
    void update() override;
private:
    World* _world;
};
