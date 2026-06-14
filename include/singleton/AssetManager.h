#pragma once
#include "interface/IManager.h"

class Asset;

class AssetManager : IManager
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

private:
    //AssetFactory -> Detects what factory to use from asset type. Keep previous factory active until change
};
