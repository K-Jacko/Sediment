#pragma once
#include <cstdint>
#include <vector>
#include "Vector2Int.h"

class Grid
{
public:
    Grid(std::uint32_t w, std::uint32_t h, std::uint32_t cS) : width(w), height(h), cellSize(cS)
    {
        grid.reserve(width * height);

        for (int x = 0; x < width; ++x)
        {
            for (int y = 0; y < height; ++y)
            {
                grid.emplace_back(Vector2Int{
                    static_cast<int>(x * cellSize),
                    static_cast<int>(y * cellSize)
                });
            }
        }
    };
    void update()
    {
        // for(GLOBAL::MATH::Vector2D* vec : m_cellPositions)
        // {
        //     vec->x -= Camera::Instance().view.x;
        // }
    };
    std::vector<Vector2Int*> getBottomRow()
    {
        std::vector<Vector2Int*> result;
        result.reserve(width);

        for (int x = 0; x < width; ++x)
        {
            int index = (x * height) + (height - 1);
            result.push_back(&grid[index]);
        }

        return result;
    }
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t cellSize;
    std::vector<Vector2Int> grid;
};
