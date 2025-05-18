#pragma once
#include <cstdint>
#include <string>

#include "Vector2Int.h"

class Asset
{
public:
    Asset();
    Asset(std::string name, std::string id);
    std::string id;
    std::string name;
private:
    uint64_t _assetSizeInBytes;
};

class SpriteAsset : public Asset
{
public:
    SpriteAsset();
    Vector2Int _resolution;
};

class AudioAsset : public Asset
{
public:
    AudioAsset();
};