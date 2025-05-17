#include <cstdint>
#include <string>
#include "object/Vector2Int.h"

class Asset
{
public:
    Asset()
    {
        // Calculate size
        _id = "";
        _name = "";
    }
    std::string _id;
    std::string _name;
    uint64_t _assetSizeInBytes;
};

class SpriteAsset : Asset
{
public:
    SpriteAsset(): resolution(Vector2Int(0, 0))
    {
    }

    Vector2Int resolution;
};

class AudioAsset : Asset
{
public:
    AudioAsset()
    {

    }

};
