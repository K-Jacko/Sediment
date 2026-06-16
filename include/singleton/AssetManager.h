#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "interface/IManager.h"
#include "object/Asset.h"

class AssetManager : public IManager
{
public:
    AssetManager();
    ~AssetManager() override;
    static AssetManager* Instance();
    bool Initialize() override;
    Asset* getAsset(const std::string assetID);
    void Update() override;

private:
    static AssetManager* _instance;
    std::unordered_map<std::string, std::unique_ptr<Asset>> cache;

private:
};
