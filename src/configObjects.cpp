#include <string>
#include <vector>

namespace BasicConfig
{
	class ScreenFlags
	{
	public:
		bool fullscreen;
		bool hidden;
		bool borderless;
		bool resizable;
		bool vsync;
	};
	class ScreenDetails
	{
	public:
		ScreenDetails() = default;
		~ScreenDetails() = default;
		int resolutionWidth, resolutionHeight = 0;
		int positionX, positionY = 0;
		std::string title;
		ScreenFlags flags;
		web::json::value toJson() const
		{
			web::json::value json;
			json[U("resolutionWidth")] = web::json::value::number(resolutionWidth);
			json[U("resolutionHeight")] = web::json::value::number(resolutionHeight);
			json[U("positionX")] = web::json::value::number(positionX);
			json[U("positionY")] = web::json::value::number(positionY);
			json[U("title")] = web::json::value(title.c_str());
			return json;
		}

		void fromJson(const web::json::value& json)
		{
			web::json::value jsonData;
			if (jsonData.has_field(U("resolutionWidth")))
			{
				resolutionWidth = jsonData.at(U("resolutionWidth")).as_integer();
			}
		}
	};

	enum AssetType
	{
		Texture,
		Shader,
		Audio
	};
	class AssetDetails
	{
	public:
		AssetDetails();
		~AssetDetails();
		std::string id;
		std::string name;
		std::string path;
		AssetType type;
		float sizeInBytes;
	};


	class DisplayDetails
	{
	public:
		DisplayDetails() = default;
		~DisplayDetails() = default;
		std::vector<ScreenDetails> screen_details;

	};

	class Config
	{
	public:
		Config();
		~Config();
		std::string id;
		std::string name;
		DisplayDetails displayDetails;
		AssetDetails assetDetails;
	};
}
