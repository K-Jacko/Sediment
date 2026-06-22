#pragma once
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <memory>
#include "Entity.h"
#include "components/Component.h"
#include "interface/ISystem.h"

class World
{
  public:
    void addEntity(Entity e);
    std::vector<Entity> getEntities();
    void updateSystems();

  template<typename T>
    void addComponentToEntity(Entity e, T component)
    {
      _getComponentStorage<T>()[e] = component;
    }

  template<typename T>
    bool has(Entity e)
    {
      return _getComponentStorage<T>().contains(e);
    }

  template<typename T>
    T& get(Entity e)
    {
      return _getComponentStorage<T>().at(e);
    }

  template<typename T>
    std::vector<T> getComponentsOfType()
    {
      std::vector<T> components;
      auto& storage = _getComponentStorage<T>();

      components.reserve(storage.size());

      for (auto& [entity, _] : storage)
        components.push_back(_);

      return components;
    };

  private:
    std::uint32_t _nextEntity = 0;
    std::vector<Entity> _entities;
    std::vector<std::unique_ptr<ISystem>> _systems;

    template<typename T>
      std::unordered_map<std::uint32_t, T>& _getComponentStorage()
      {
        static std::unordered_map<std::uint32_t, T> storage;
        return storage;
      }
};
