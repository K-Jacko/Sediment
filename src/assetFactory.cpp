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
    
    if (asset == nullptr)
    {
      std::cout << "Failed to create BaseAsset with ID : " << asset.get()->getID() << std::endl;

      return nullptr;
    }

    return asset;
}
