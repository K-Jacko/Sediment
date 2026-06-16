#include "../include/object/World.h"

void World::addEntity(Entity e)
{
  _nextEntity++;
}

template<typename T>
void World::addComponentToEntity(Entity e, T component)
{
  _getComponentStorage<T>()[e] = component;
}

template<typename T>
bool World::has(Entity e)
{
  return _getComponentStorage<T>().find(e) != _getComponentStorage<T>().end();
}

template<typename T>
T& World::get(Entity e)
{
  return _getComponentStorage<T>().at(e);
}

template<typename T>
std::unordered_map<World::Entity, T>& World::_getComponentStorage()
{
  static std::unordered_map<Entity, T> storage;
  return storage;
}

