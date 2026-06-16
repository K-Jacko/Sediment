#pragma once
#include <unordered_map>
#include <vector>
#include <cstdint>
#include <memory>

class World 
{
  public:
    using Entity = uint32_t;
    void addEntity(Entity e);

  template<typename T>
    void addComponentToEntity(Entity e, T component);

  template<typename T>
    bool has(Entity e);

  template<typename T>
    T& get(Entity e);

  private:
    Entity _nextEntity = 0;

    std::vector<Entity> entities;

    template<typename T>
      std::unordered_map<Entity, T>& _getComponentStorage();
};
