#pragma once
#include "interface/ISystem.h"
#include "object/World.h"


class AnimationSystem : public ISystem
{
public:
    AnimationSystem(World* world);
    void update() override;
private:
    World* _world;
};
