#include <object/SCFObjects.h>

std::string SCF::getName() const
{
    return _name;
}

std::string SCF::getID() const
{
    return _id;
}

void SCF::fromJson(const web::json::value& json)
{
    if (json.has_field(U("id")))
        _id = utility::conversions::to_utf8string(json.at(U("id")).as_string());
    if (json.has_field(U("name")))
        _name = utility::conversions::to_utf8string(json.at(U("name")).as_string());
    if (json.has_field(U("display")))
        displayDetails.fromJson(json.at(U("display_details")));
}

void DisplayDetails::fromJson(const web::json::value& json)
{
    if (json.has_field(U("screen_details")))
    {
        const auto& screen_detail_array = json.at(U("screen_details"));
        for (const auto& screen_detail : screen_detail_array)
        {
            ScreenDetail screenDetail;
            screenDetail.fromJson(screen_detail.toJson());
            screen_details.push_back(screenDetail);
        }
    }
}

web::json::value ScreenDetail::toJson() const
{
    web::json::value json;
    json[U("resolutionWidth")] = web::json::value::number(_resolutionWidth);
    json[U("resolutionHeight")] = web::json::value::number(_resolutionHeight);
    json[U("positionX")] = web::json::value::number(_positionX);
    json[U("positionY")] = web::json::value::number(_positionY);
    json[U("title")] = web::json::value(_title.c_str());
    return json;
}

void ScreenDetail::fromJson(const web::json::value& json)
{
    if (json.has_field(U("resolution_width")))
        _resolutionWidth = json.at(U("resolution_width")).as_integer();
    if (json.has_field(U("resolution_height")))
        _resolutionHeight = json.at(U("resolution_height")).as_integer();
    if (json.has_field(U("positionX")))
        _positionX = json.at(U("positionX")).as_integer();
    if (json.has_field(U("positionY")))
        _positionY = json.at(U("positionY")).as_integer();
    if (json.has_field(U("title")))
        _title = utility::conversions::to_utf8string(json.at(U("title")).as_string());
}

Vector2 ScreenDetail::getScreenResolution()
{
    return Vector2(_resolutionWidth, _resolutionHeight);
}

Vector2 ScreenDetail::getScreenPosition()
{
    return Vector2(_positionX, _positionY);
}