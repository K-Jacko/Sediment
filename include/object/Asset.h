#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "Vector2Int.h"
#include <cstdint>

// The AssetsObjects need to only hold the data that an asset has
// This means that the SDL_Texture shared_ptr will not be held here
// Instead an AssetManager, when queried from something (likely a sprite)
// Will use the data in the AssetManagers AssetObj to generate the actual asset
// This should leave render references out of these classes
// isCached = Check if the asset is in the Cache Map

class Asset
{
public:
    Asset();
    ~Asset() = default;
    Asset(std::string name, std::string id);
    std::string getName();
    std::string getID();
protected:
    std::string _id;
    std::string _name;
    std::string _path;
    uint64_t _assetSizeInBytes;
};

///

///

class SpriteAsset : public Asset
{
public:
    SpriteAsset();
    Vector2Int _resolution;
private:

};

///

class AudioAsset : public Asset
{
public:
    AudioAsset();
};
