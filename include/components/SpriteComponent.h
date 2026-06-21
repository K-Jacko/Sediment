#pragma once
#include <cstdint>
#include "Component.h"
#include "object/TextureAsset.h"

struct SpriteComponent : Component
{
  uint32_t width = 0;
  uint32_t height = 0;
  TextureAsset _texture;
};
