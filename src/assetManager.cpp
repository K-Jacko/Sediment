#include "DataManager.h"
#include "singleton/AssetManager.h"

AssetManager* AssetManager::_instance = 0;
AssetManager::AssetManager(){}

AssetManager::~AssetManager(){}

AssetManager* AssetManager::Instance()
{
    if (_instance == 0)
    {
        std::cout << "Creating new AssetManager Instance" << std::endl;
        _instance = new AssetManager();
    }
    return _instance;
}

Asset* AssetManager::getAsset(const std::string id)
{
  auto it = _cache.find(id);
  if (it == _cache.end()) return nullptr;
  return it->second.get();
}

TextureAsset* AssetManager::getTexture(const std::string id)
{
  auto it = _textureAssetCache.find(id);
  if (it == _textureAssetCache.end())
    return nullptr;

  return it->second.get();
}


bool AssetManager::Initialize()
{
    // Grab Data from DataManager if its initialised
    // Using the Asset data make the appropriate Assets using the Factories
    // vector to hold all the Assets
    std::cout << "AssetManager Initializing" << std::endl;

    for (AssetDetail assetData : DataManager::Instance()->getSCF()->assetDetails.assets)
    {
        switch (assetData.type)
        {
        case Texture :
          {
            // Texture Asset Factory
            auto tex = TextureAssetFactory::createFromFile(assetData.id, assetData.name, assetData.path);
            try {
              _textureAssetCache.emplace(assetData.name, std::move(tex));
              std::cout << "Asset :" << assetData.name << ": added to cache" << std::endl;
            }
            catch (const std::exception& e)
            {
              std::cout << "Error loading texture:" << e.what() << std::endl;
            };

            break;
          }
        case Sprite:
          {
            // Sprite Asset Factory
            break;
          }
        case Shader :
          {
            //Shader Asset Factory
            break;
          }
        case Audio :
          {
            // Audio Asset Factory
            break;
          }
        default :
          {
            // Asset Factory + Debug
            break;
          }
        }
    }

    return true;
}

void AssetManager::Update()
{
    IManager::Update();
}
