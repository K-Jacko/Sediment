#include "../include/systems/RenderSystem.h"
#include "components/SpriteComponent.h"
#include "components/TransformComponent.h"
#include <vector>

#include "WindowManager.h"

RenderSystem::RenderSystem(World* world, SDL_Renderer* renderer)
{
  _world = world;
  _renderer = renderer;
}

void RenderSystem::update()
{
  std::vector<Entity> renderables;

  _world->forEach<SpriteComponent, TransformComponent>(
    [&](Entity e, SpriteComponent& sprite, TransformComponent& transform)
    {
      renderables.push_back(e);

    });

  std::sort(renderables.begin(), renderables.end(),[&](Entity a, Entity b)
  {
      return _world->get<SpriteComponent>(a).layer <
             _world->get<SpriteComponent>(b).layer;
  });

  for (Entity e : renderables)
  {
    auto& sprite = _world->get<SpriteComponent>(e);
    auto& transform = _world->get<TransformComponent>(e);

    SDL_Rect tRec{(int)transform.x, (int)transform.y, (int)transform.width, (int)transform.height };
    SDL_RenderCopy(
      _renderer,
      sprite.texture->getTexture(),
      &sprite.rect,
      &tRec
    );
  }

}
