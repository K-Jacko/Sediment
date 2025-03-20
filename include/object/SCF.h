#pragma once
#include <cpprest/json.h>
#include <string>
#include <vector>
#include <math.h>

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
    Shader,
    Audio
};

class AssetDetail
{
public:
    AssetDetail();
    ~AssetDetail();
    std::string id;
    std::string name;
    std::string path;
    AssetType type;
    float sizeInBytes;
};

class ScreenDetail
{
public:
    ScreenDetail() = default;
    ~ScreenDetail() = default;
    Vector2 getScreenResolution();
    Vector2 getScreenPosition();
    web::json::value toJson() const;
    void fromJson(const web::json::value& json);

private:
    int _resolutionWidth, _resolutionHeight = 0;
    int _positionX, _positionY = 0;
    std::string _title;
    ScreenFlags flags;
};

class DisplayDetails
{
public:
    DisplayDetails() = default;
    ~DisplayDetails() = default;
    std::vector<ScreenDetail> screen_details;
    void fromJson(const web::json::value& json);

};

class SCF
{
public:
    SCF();
    ~SCF();
    std::string getName() const;
    std::string getID() const;
    DisplayDetails displayDetails;
    AssetDetail assetDetails;
    bool isValid() const {return _initialized;}
    void fromJson(const web::json::value& json);

private:
    bool _initialized;
    std::string _id;
    std::string _name;
};