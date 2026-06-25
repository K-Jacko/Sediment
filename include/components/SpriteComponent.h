#pragma once
#include <SDL.h>
#include "Component.h"

class TextureAsset;

struct SpriteComponent : Component
{
  SpriteComponent(TextureAsset* tex, SDL_Rect rec) : texture(tex)
  {
    rect = rec;
    x = rec.x;
    y = rec.y;
    width = rec.w;
    height = rec.h;
  };
  int width;
  int height;
  int x;
  int y;
  TextureAsset* texture;
  SDL_Rect rect;
};
