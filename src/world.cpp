#include "../include/object/World.h"

void World::addEntity(Entity e)
{
  _nextEntity++;
  _entities.push_back(e);
}

std::vector<Entity> World::getEntities()
{
  return _entities;
}

void World::updateSystems()
{
  for (std::unique_ptr<ISystem>& sys : _systems)
  {
    sys->update();
  }
}
