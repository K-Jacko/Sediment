#pragma once
#include "factory/AssetFactory.h"

class TextureAssetFactory : public AssetFactory
{
public:
    TextureAssetFactory();
    ~TextureAssetFactory() override;
    std::unique_ptr<TextureAsset> createFromFile(std::string id, std::string name, std::string path);
};