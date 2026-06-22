#pragma once
#include <cstdint>
#include "Component.h"
#include "object/TextureAsset.h"

struct SpriteComponent : Component
{
  uint32_t width = 0;
  uint32_t height = 0;
  SDL_Rect crop = {0 ,0, 0,0};
  TextureAsset texture;
};
