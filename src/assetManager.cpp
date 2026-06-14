#include "DataManager.h"
#include "singleton/AssetManager.h"

AssetManager* AssetManager::_instance = 0;
AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{

}

AssetManager* AssetManager::Instance()
{
    if (_instance == 0)
    {
        std::cout << "Creating new AssetManager Instance" << std::endl;
        _instance = new AssetManager();
    }
    return _instance;
}

Asset* AssetManager::getAsset(const std::string assetID)
{
    return nullptr;
}

bool AssetManager::Initialize()
{
    // Grab Data from DataManager if its initialised
    // Using the Asset data make the appropriate Assets using the Factories
    // vector to hold all the Assets
    std::cout << "AssetManager Initializing" << std::endl;

    for (auto assetData : DataManager::Instance()->getSCF()->assetDetails.assets)
    {
        switch (assetData.type)
        {
        case Texture :
            // Texture Asset Factory

            break;
        case Sprite:
            // Sprite Asset Factory

            break;
        case Shader :
            //Shader Asset Factory

            break;
        case Audio :
            // Audio Asset Factory

            break;
        default :
            // Asset Factory + Debug

            break;
        }
    }
    return true;
}

void AssetManager::Update()
{
    IManager::Update();
}
