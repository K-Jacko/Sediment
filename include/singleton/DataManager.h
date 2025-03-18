#pragma once
#include <interface/IManager.h>
#include <cpprest/json.h>
#include "../src/configObjects.cpp"

class DataManager : public IManager
{
public:
	DataManager();
	~DataManager() override;
	static DataManager* Instance();
	void loadFromFile(const std::string& filePath);
	void loadFromHTTP(const std::string& url);
	const web::json::value& getData();
private:
	BasicConfig::Config _localKCF;
	BasicConfig::Config _volKCF;
	BasicConfig::Config _backupKCF;
};