#pragma once
#include <cstdint>

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;
    std::uint32_t id = 0;
    std::string name = "";
};

namespace std
{
    template<>
    struct hash<Entity>
    {
        size_t operator()(const Entity& e) const noexcept
        {
            return std::hash<uint32_t>{}(e.id);
        }
    };
}