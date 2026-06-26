#include "GameManager.h"
#include "components/AnimationComponent.h"
#include "components/TransformComponent.h"
#include "systems/AnimationSystem.h"

AnimationSystem::AnimationSystem(World* world)
{
    _world = world;
}

void AnimationSystem::update()
{
    //Transform based animation
    _world->forEach<AnimationComponent, TransformComponent>(
        [&](Entity e, AnimationComponent& animation, TransformComponent& transform)
        {
            switch (animation.type)
            {
                case Scroll :
                    {
                        transform.x += 100 * GameManager::deltaTime;
                        break;
                    }
                case Float :
                    {
                        float time = GameManager::Instance()->elapsedTime;
                        transform.y = animation.baseY +std::sin(time + animation.phase) * animation.amplitude;
                        break;
                    }
                case Wave :
                    {
                        float time = GameManager::Instance()->elapsedTime;
                        transform.x =
                            animation.baseY +
                            std::sin(
                                time + animation.frequency +
                                animation.phase + 2
                            ) * animation.amplitude;

                        break;
                    }
                case None :
                    {
                        break;
                    }
                default :
                    {
                        break;
                    }
            }
        });
}
