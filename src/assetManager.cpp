#include "singleton/AssetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

AssetManager* AssetManager::Instance()
{
}

Asset* AssetManager::getAsset(const std::string assetID)
{
}

bool AssetManager::Initialize()
{
    // Grab Data from DataManager if its initialised
    // Using the Asset data make the appropriate Assets using the Factories
    // vector to hold all the Assets

}

void AssetManager::Update()
{
    IManager::Update();
}
