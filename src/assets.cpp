#include "object/Asset.h"

Asset::Asset()
{
    // Calculate size
    _id = "";
    _name = "";
    _assetSizeInBytes = 0;
    _path = "";
}

Asset::Asset(std::string id, std::string name): _name(name), _id(id)
{
}

std::string Asset::getName()
{
    return _name;
}

std::string Asset::getID()
{
  return _id;
}

SpriteAsset::SpriteAsset(): _resolution(0,0)
{

}

AudioAsset::AudioAsset()
{

}
