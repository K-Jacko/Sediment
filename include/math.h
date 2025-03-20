#pragma once

class Vector2
{
public:
    Vector2(int x, int y) : _x{x}, _y{y}{}
    ~Vector2() = default;
private:
    int _x, _y;
};