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
  TransformComponent(int x, int y, int width, int height, int scale = 1)
  {
    _x = x;
    _y = y;
    _width = width * scale;
    _height = height * scale;
    _scale = scale;
    rect.x = _x;
    rect.y = _y;
    rect.w = _width;
    rect.h = _height;
  };
  int _width;
  int _height;
  int _x;
  int _y;
  int _scale = 1;
  SDL_Rect rect;
};
