#pragma once
#include <SDL_rect.h>
#include <string>
#include "Component.h"


struct ColliderComponent : public Component
{
    ColliderComponent(){};
    std::string tag;
};
