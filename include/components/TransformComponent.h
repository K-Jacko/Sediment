#pragma once
#include <cstdint>
#include "Component.h"

struct TransformComponent : Component
{
  uint32_t x;
  uint32_t y;
};
