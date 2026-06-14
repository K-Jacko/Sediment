#pragma once
#include <windows.h>
#include <intrin.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <object/Vector2Int.h>
#include <iostream>
#include <SDL_stdinc.h>
#include <SDL.h>


class ScreenFlags
{
public:
    bool fullscreen;
    bool hidden;
    bool borderless;
    bool resizable;
    bool vsync;
};

enum AssetType
{
    Texture,
    Sprite,
    Shader,
    Audio
};

class AssetDetail
{
public:
    AssetDetail() = default;
    ~AssetDetail() = default;
    std::string id;
    std::string name;
    std::string path;
    AssetType type;
    float sizeInBytes;
    void fromJson(const nlohmann::json& json);
};

class AssetDetails
{
public:
    AssetDetails() = default;
    ~AssetDetails() = default;
    std::string asset_pack_name;
    std::vector<AssetDetail> assets;
    void fromJson(const nlohmann::json& json);
};

class ScreenDetail
{
public:
    ScreenDetail() = default;
    ~ScreenDetail() = default;
    Vector2Int getScreenResolution();
    Vector2Int getScreenPosition();
    std::string getID();
    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& json);
    std::string title;
    Uint32 flags;
    bool vsync;
private:
    std::string _id;
    int _resolutionWidth = 0;
    int _resolutionHeight = 0;
    int _positionX = 0;
    int _positionY = 0;
};

class DisplayDetails
{
public:
    DisplayDetails() = default;
    ~DisplayDetails() = default;
    std::vector<ScreenDetail> screen_details;
    void fromJson(const nlohmann::json& json);

};

class SCF
{
public:
    SCF();
    ~SCF() = default;
    std::string getName() const;
    std::string getID() const;
    DisplayDetails displayDetails;
    AssetDetails assetDetails;
    bool isValid() const {return _initialized;}
    void fromJson(const nlohmann::json& json);

private:
    bool _initialized;
    std::string _id;
    std::string _name;
};