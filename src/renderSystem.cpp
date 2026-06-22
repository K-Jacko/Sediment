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
  const std::vector<SpriteComponent> spriteComponents = _world->getComponentsOfType<SpriteComponent>();
  const std::vector<TransformComponent> transformComponents = _world->getComponentsOfType<TransformComponent>();

  for (int i = 0; i < _world->getComponentsOfType<SpriteComponent>().size(); i++)
  {
    SDL_RenderCopy(
        _renderer,
        spriteComponents[i].texture.getTexture(),
        &spriteComponents[i].crop,
        transformComponents[i].rect()
      );
  }
}
