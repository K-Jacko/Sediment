#pragma once
#include "object/World.h"
#include <SDL.h>


class RenderSystem : public ISystem
{
public:
    RenderSystem(World* world, SDL_Renderer* renderer);
    void update() override;

private:
    World* _world = nullptr;
    SDL_Renderer* _renderer = nullptr;
};
