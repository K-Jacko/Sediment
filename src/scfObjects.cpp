#include <object/SCF.h>

std::string SCF::getName() const
{
    return _name;
}

std::string SCF::getID() const
{
    return _id;
}

void SCF::fromJson(const nlohmann::json& json)
{
    if (json.contains("id") && json["id"].is_string())
            _id = json.at("id");
    if (json.contains("name") && json["name"].is_string())
        _name = json.at("name");
    if (json.contains("display_details") && json["display_details"].is_object())
        displayDetails.fromJson(json["display_details"]);
    if (json.contains("asset_details") && json["asset_details"].is_object())
        assetDetails.fromJson(json["asset_details"]);

    _initialized = !_id.empty() && !_name.empty();
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

SCF::SCF()
{
    _initialized = false;
    _id = "";
    _name = "";
    displayDetails = DisplayDetails();
    assetDetails = AssetDetails();
}

nlohmann::json ScreenDetail::toJson() const
{
    return {{"resolutionWidth", _resolutionWidth},{"resolutionHeight", _resolutionHeight},{"positionX", _positionX},{"positionY", _positionY},{"title", title}};
}

void ScreenDetail::fromJson(const nlohmann::json& json)
{
    if (json.contains("resolution_width"))
        _resolutionWidth = json.at("resolution_width").get<int>();
    if (json.contains("resolution_height"))
        _resolutionHeight = json.at("resolution_height").get<int>();
    if (json.contains("positionX"))
        _positionX = json.at("positionX").get<int>();
    if (json.contains("positionY"))
        _positionY = json.at("positionY").get<int>();
    if (json.contains("title"))
        title = json.at("title").get<std::string>();
    if (json.contains("id"))
        _id = json.at("id").get<std::string>();
}

Vector2Int ScreenDetail::getScreenResolution()
{
    return Vector2Int(_resolutionWidth, _resolutionHeight);
}

Vector2Int ScreenDetail::getScreenPosition()
{
    return Vector2Int(_positionX, _positionY);
}

std::string ScreenDetail::getID()
{
    return _id;
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