#pragma once
#include "interface/ISystem.h"


class AnimationSystem : public ISystem
{
public:
    AnimationSystem() = default;
    void update() override;
};
