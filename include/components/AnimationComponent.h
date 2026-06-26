#pragma once
#include "Component.h"

enum AnimationType
{
    None,
    Scroll,
    Float,
    Wave,
    Frame,
    Parallax
};

struct AnimationComponent : public Component
{
    AnimationComponent(float amp, float freq, float ph, AnimationType t, int bY = 0)
    {
        amplitude = amp;
        frequency = freq;
        phase = ph;
        type = t;
        baseY = bY;
    }

    float amplitude = 0.0f;
    float frequency = 0.0f;
    float phase = 0.0f;
    AnimationType type;
    int baseY = 0;
};