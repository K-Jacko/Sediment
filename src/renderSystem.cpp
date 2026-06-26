#include "../include/systems/RenderSystem.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include <vector>

RenderSystem::RenderSystem(World* world, SDL_Renderer* renderer)
{
  _world = world;
  _renderer = renderer;
}

void RenderSystem::update()
{
  _world->forEach<SpriteComponent, TransformComponent>(
    [&](Entity e, SpriteComponent& sprite, TransformComponent& transform)
    {
      SDL_RenderCopy(
        _renderer,
        sprite.texture->getTexture(),
        &sprite.rect,
        &transform.rect
      );
    });
}
