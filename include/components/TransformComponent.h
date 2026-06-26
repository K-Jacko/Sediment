#pragma once
#include "Component.h"
#include <SDL.h>

struct TransformComponent : Component
{
  TransformComponent(int x, int y)
  {
    x = x;
    y = y;
  };
  TransformComponent(float X, float Y, float w, float h, int s = 1)
  {
    x = X;
    y = Y;
    width = w * s;
    height = h * s;
    scale = s;

  };
  float width;
  float height;
  float x;
  float y;
  int scale = 1;
};
