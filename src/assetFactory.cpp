#include "factory/AssetFactory.h"



AssetFactory::AssetFactory()
{
}

AssetFactory::~AssetFactory()
{
}

void AssetFactory::Destroy()
{

}

std::unique_ptr<Asset> AssetFactory::CreateAsset(std::string assetID, std::string assetName)
{
    auto asset = std::make_unique<Asset>(assetID, assetName);
    std::cout << asset.get()->getName() << std::endl;
    return asset;
}
