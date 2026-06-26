#pragma once
#include <SDL_rect.h>
#include <vector>
#include "Component.h"

class TextureAsset;

struct BackgroundComponent : public Component
{
    BackgroundComponent();
    std::vector<TextureAsset*> textures;
    std::vector<SDL_Rect> transforms;
};
