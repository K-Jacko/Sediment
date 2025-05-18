#include "object/Asset.h"

Asset::Asset()
{
    // Calculate size
    id = "";
    name = "";
    _assetSizeInBytes = 0;
}

Asset::Asset(std::string name, std::string id): name(name), id(id)
{
}

SpriteAsset::SpriteAsset(): _resolution(0,0)
{

}

AudioAsset::AudioAsset()
{

}
