#pragma once
#include <SDL.h>
#include "Component.h"

class TextureAsset;

struct SpriteComponent : Component
{
  SpriteComponent(TextureAsset* tex, SDL_Rect rec, std::uint32_t lay = 0) : texture(tex)
  {
    rect = rec;
    x = rec.x;
    y = rec.y;
    width = rec.w;
    height = rec.h;
    layer = lay;
  };
  int width;
  int height;
  int x;
  int y;
  TextureAsset* texture;
  SDL_Rect rect;
  std::uint32_t layer;
};
