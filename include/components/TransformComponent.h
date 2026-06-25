#pragma once
#include "Component.h"
#include <SDL.h>

struct TransformComponent : Component
{
  TransformComponent(int x, int y)
  {
    _x = x;
    _y = y;
  };
  TransformComponent(int x, int y, int width, int height)
  {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;

  };
  int _width;
  int _height;
  int _x;
  int _y;
  SDL_Rect rect;
};
