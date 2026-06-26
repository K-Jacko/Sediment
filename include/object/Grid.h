#pragma once
#include <cstdint>
#include <vector>
#include "Vector2Int.h"

class Grid
{
public:
    Grid(std::uint32_t w, std::uint32_t h, std::uint32_t cS) : width(w), height(h), cellSize(cS)
    {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                auto vec = Vector2Int(x * cellSize,y * cellSize);
                grid.push_back(vec);
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
        for (auto& vec : grid)
        {
            // std::cout << height  * cellSize - cellSize << std::endl;
            // std::cout << vec.y << std::endl;
            if (vec.y == height * cellSize  - cellSize)
            {
                result.push_back(&vec);
            }
        }
        return result;
    }
    std::uint32_t width;
    std::uint32_t height;
    std::uint32_t cellSize;
    std::vector<Vector2Int> grid;
};
