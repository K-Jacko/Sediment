#pragma once
#include "Component.h"

struct RigidBodyComponent : public Component
{
    float velocityX = 0.0f;
    float velocityY = 0.0f;

    float accelerationX = 0.0f;
    float accelerationY = 0.0f;

    float mass = 1.0f;

    float linearDrag = 0.0f;
    float gravityScale = 1.0;

    bool isKinematic = false;
    bool isGrounded = false;
};
