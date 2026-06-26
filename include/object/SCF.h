#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <SDL_stdinc.h>

#include "SCFObjects.h"

struct BackgroundDetail
{
    std::string id;
    std::string name;
    std::string texture;
    int animationType;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int scale = 1;
    void fromJson(const nlohmann::json& json);

};

struct SpriteCrop
{
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    void fromJson(const nlohmann::json& json);
};

struct SpriteTransform
{
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    void fromJson(const nlohmann::json& json);
};

struct SpriteDetail
{
    std::string id;
    std::string name;
    std::string texture;
    SpriteTransform transform;
    SpriteCrop crop;
    void fromJson(const nlohmann::json& json);
};

struct SpriteDetails
{
    std::vector<std::string> dependencies;
    std::vector<SpriteDetail> sprites;
    std::vector<BackgroundDetail> backgrounds;
    SpriteDetail* getSpriteData(std::string name);
    void fromJson(const nlohmann::json& json);
};

struct AssetDetail
{
    std::string id;
    std::string name;
    std::string path;
    AssetType type;
    float sizeInBytes;
    void fromJson(const nlohmann::json& json);
};

struct AssetDetails
{
    std::string asset_pack_name;
    std::vector<AssetDetail> assets;
    void fromJson(const nlohmann::json& json);
};

struct ScreenDetail
{
    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& json);
    std::string title;
    Uint32 flags;
    bool vsync;
    std::string id;
    int resolutionWidth = 0;
    int resolutionHeight = 0;
    int positionX = 0;
    int positionY = 0;
};

struct DisplayDetails
{
    std::vector<ScreenDetail> screen_details;
    void fromJson(const nlohmann::json& json);
};

struct SCF
{
    std::string id;
    std::string name;
    DisplayDetails displayDetails;
    AssetDetails assetDetails;
    SpriteDetails spriteDetails;
    bool isValid() const {return _initialized;}
    void fromJson(const nlohmann::json& json);

private:
    bool _initialized = false;
};
