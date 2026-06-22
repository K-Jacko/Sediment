#pragma once

class ScreenFlags
{
public:
    bool fullscreen;
    bool hidden;
    bool borderless;
    bool resizable;
    bool vsync;
};

enum AssetType
{
    Texture,
    Sprite,
    Shader,
    Audio
};
