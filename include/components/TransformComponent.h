#pragma once
#include "Component.h"
#include <SDL.h>

struct TransformComponent : Component
{
  int x;
  int y;
  int width;
  int height;
  SDL_Rect* rect() const
  {
    SDL_Rect* rect = new SDL_Rect;
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
    return rect;
  }
};
