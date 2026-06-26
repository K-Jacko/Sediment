#include <object/SCF.h>
#include <SDL.h>
#include <iostream>

void SCF::fromJson(const nlohmann::json& json)
{
    if (json.contains("id") && json["id"].is_string())
        id = json.at("id");
    if (json.contains("name") && json["name"].is_string())
        name = json.at("name");
    if (json.contains("display_details") && json["display_details"].is_object())
        displayDetails.fromJson(json["display_details"]);
    if (json.contains("asset_details") && json["asset_details"].is_object())
        assetDetails.fromJson(json["asset_details"]);
    if (json.contains("sprite_details") && json["sprite_details"].is_object())
        spriteDetails.fromJson(json["sprite_details"]);

    _initialized = !id.empty() && !name.empty();
}

void DisplayDetails::fromJson(const nlohmann::json& json) {
    if (json.contains("screen_details") && json["screen_details"].is_array()) {
        screen_details.clear();
        for (const auto& screen_detail : json["screen_details"]) {
            ScreenDetail screenDetail;
            screenDetail.fromJson(screen_detail);
            screen_details.push_back(screenDetail);
        }
    }
}


nlohmann::json ScreenDetail::toJson() const
{
    return {{"resolutionWidth", resolutionWidth},{"resolutionHeight", resolutionHeight},{"positionX", positionX},{"positionY", positionY},{"title", title}};
}

void ScreenDetail::fromJson(const nlohmann::json& json)
{
    if (json.contains("resolution_width"))
        resolutionWidth = json.at("resolution_width").get<int>();
    if (json.contains("resolution_height"))
        resolutionHeight = json.at("resolution_height").get<int>();
    if (json.contains("positionX"))
        positionX = json.at("positionX").get<int>();
    if (json.contains("positionY"))
        positionY = json.at("positionY").get<int>();
    if (json.contains("title"))
        title = json.at("title").get<std::string>();
    if (json.contains("id"))
        id = json.at("id").get<std::string>();

    flags = 0;
    if (json.contains("flags"))
    {
        const auto& jsonFlags = json["flags"];

        vsync = jsonFlags.value("vsync", false);

        if (jsonFlags.value("fullscreen", false))
            flags |= SDL_WINDOW_FULLSCREEN;
        if (jsonFlags.value("borderless", false))
            flags |= SDL_WINDOW_BORDERLESS;
        if (jsonFlags.value("resizeable", false))
            flags |= SDL_WINDOW_RESIZABLE;
        if (jsonFlags.value("focused", false))
        {
            flags |= SDL_WINDOW_INPUT_FOCUS;
            flags |= SDL_WINDOW_MOUSE_FOCUS;
        }
        flags |= SDL_WINDOW_INPUT_FOCUS;
        flags |= SDL_WINDOW_MOUSE_GRABBED;
    }
}

void AssetDetails::fromJson(const nlohmann::json& json)
{
    if (json.contains("assets") && json["assets"].is_array()) {
        assets.clear();
        for (const auto& asset_detail : json["assets"]) {
            AssetDetail assetDetail;
            assetDetail.fromJson(asset_detail);
            assets.push_back(assetDetail);
        }
    }
}

void AssetDetail::fromJson(const nlohmann::json& json)
{
    if (json.contains("id") && json.at("id").is_string())
        id = json.at("id");
    if (json.contains("name") && json.at("name").is_string())
        name = json.at("name");
    if (json.contains("path") && json.at("path").is_string())
        path = json.at("path");
    if (json.contains("type"))
        type = json.at("type");
    if (json.contains("size_in_bytes"))
        sizeInBytes = json.at("size_in_bytes");

    if (!id.empty() && !name.empty() && path.empty() && sizeInBytes < 0)
        std::cout << "Error parsing Asset detail from Json" << std::endl;
}

SpriteDetail* SpriteDetails::getSpriteData(std::string name)
{
    for (SpriteDetail& spriteData : sprites)
    {
        if (spriteData.name == name)
        {
            return &spriteData;
        }
    }
}

void SpriteDetails::fromJson(const nlohmann::json& json)
{
    if (json.contains("dependencies") && json["dependencies"].is_array()) {
        dependencies.clear();
        for (const auto& asset_detail : json["dependencies"]) {
            std::string dep;
            dependencies.push_back(dep);
        }
    };

    if (json.contains("sprites") && json["sprites"].is_array()) {
        sprites.clear();
        for (const auto& asset_detail : json["sprites"]) {
            SpriteDetail spriteDetail;
            spriteDetail.fromJson(asset_detail);
            sprites.push_back(spriteDetail);
        }
    };

    if (json.contains("backgrounds") && json["backgrounds"].is_array()) {
        backgrounds.clear();
        for (const auto& asset_detail : json["backgrounds"]) {
            BackgroundDetail backgroundDetail;
            backgroundDetail.fromJson(asset_detail);
            backgrounds.push_back(backgroundDetail);
        }
    };
}

void SpriteDetail::fromJson(const nlohmann::json& json)
{
    if (json.contains("id") && json.at("id").is_string())
        id = json.at("id");
    if (json.contains("name") && json.at("name").is_string())
        name = json.at("name");
    if (json.contains("texture") && json.at("texture").is_string())
        texture = json.at("texture");
    if (json.contains("transform"))
        transform.fromJson(json["transform"]);
    if (json.contains("crop"))
        crop.fromJson(json["crop"]);
}

void SpriteTransform::fromJson(const nlohmann::json& json)
{
    if (json.contains("x") )
        x = json.at("x");
    if (json.contains("y"))
        y = json.at("y");
    if (json.contains("width"))
        width = json.at("width");
    if (json.contains("height"))
        height = json.at("height");
}

void BackgroundDetail::fromJson(const nlohmann::json& json)
{
    if (json.contains("id") && json.at("id").is_string())
        id = json.at("id");
    if (json.contains("name") && json.at("name").is_string())
        name = json.at("name");
    if (json.contains("texture") && json.at("texture").is_string())
        texture = json.at("texture");
    if (json.contains("animationType"))
        animationType = json.at("animationType");
    if (json.contains("x") )
        x = json.at("x");
    if (json.contains("y"))
        y = json.at("y");
    if (json.contains("width"))
        width = json.at("width");
    if (json.contains("height"))
        height = json.at("height");
    if (json.contains("scale"))
        scale = json.at("scale");
}

void SpriteCrop::fromJson(const nlohmann::json& json)
{
    if (json.contains("x") )
        x = json.at("x");
    if (json.contains("y"))
        y = json.at("y");
    if (json.contains("width"))
        width = json.at("width");
    if (json.contains("height"))
        height = json.at("height");
}

