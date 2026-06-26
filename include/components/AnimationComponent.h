#pragma once
#include "Component.h"


struct AnimationComponent : public Component
{
    AnimationComponent();
    float amplitude = 0.0f;
    float frequency = 0.0f;
    float phase = 0.0f;
};