#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include "Entity.h"
#include "interface/ISystem.h"
#include "components/SpriteComponent.h"
#include "AssetManager.h"
#include "DataManager.h"


class World
{
  public:
    void addEntity(Entity e);
    std::vector<Entity> getEntities();
    void updateSystems();
    void start();

  template<typename T, typename... Args>
  void addSystem(Args&&... args)
  {
    _systems.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    std::cout << "System " << typeid(T).name() << " Added to world" << std::endl;
  }

  template<typename T>
    void addComponentToEntity(Entity e, T component)
    {
      _getComponentStorage<T>().emplace(e.id, std::move(component));
      std::cout << "Component " << typeid(T).name() << " Added to entity " << e.id << std::endl;
    }

  template<typename T>
    bool has(Entity e)
    {
      return _getComponentStorage<T>().contains(e.id);
    }

  template<typename T>
    T& get(Entity e)
    {
      return _getComponentStorage<T>().at(e.id);
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

  template<typename T>
    std::unordered_map<std::uint32_t, T>& getStorage()
    {
      return _getComponentStorage<T>();
    }

  template<typename A, typename B, typename Func>
    void forEach(Func func)
    {
      auto& storage = _getComponentStorage<A>();

      for (auto& [id, componentA] : storage)
      {
        Entity e;
        e.id = id;
        if (has<B>(e))
        {
          func(e, componentA, get<B>(e));
        }
      }
    }

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
