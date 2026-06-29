#include "WindowManager.h"
#include "components/ColliderComponent.h"
#include "components/TransformComponent.h"
#include "systems/CollisionSystem.h"

CollisionSystem::CollisionSystem(World* world)
{
    _world = world;
}

void CollisionSystem::update()
{
    std::vector<Entity> colliders;
    auto renderer = WindowManager::Instance()->defaultWindow()->getRenderer();

    _world->forEach<ColliderComponent, TransformComponent>(
        [&](Entity e, ColliderComponent&, TransformComponent& transform)
        {
            SDL_Rect rect; rect.x = transform.x; rect.y = transform.y; rect.w = transform.width; rect.h = transform.height; SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); SDL_RenderDrawRect(renderer, &rect);
            colliders.push_back(e);
        });

    for (size_t i = 0; i < colliders.size(); i++)
    {
        for (size_t j = i + 1; j < colliders.size(); j++)
        {
            Entity a = colliders[i];
            Entity b = colliders[j];

            auto& aTransform = _world->get<TransformComponent>(a);
            auto& bTransform = _world->get<TransformComponent>(b);

            SDL_Rect ra {
                (int)aTransform.x,
                (int)aTransform.y,
                (int)aTransform.width,
                (int)aTransform.height
            };

            SDL_Rect rb {
                (int)bTransform.x,
                (int)bTransform.y,
                (int)bTransform.width,
                (int)bTransform.height
            };

            if (SDL_HasIntersection(&ra, &rb))
            {
                std::cout << "Collision: " << a.id << " vs " << b.id << "\n";
            }
        }
    }
}
