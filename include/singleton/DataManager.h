#pragma once
#ifdef _WIN32
#include <windows.h>
#include <shlobj.h> // For SHGetFolderPath
#endif
#include <interface/IManager.h>
#include <nlohmann/json.hpp>
#include <object/SCF.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>


class DataManager : public IManager
{
public:
	DataManager();
	~DataManager() override;
	static DataManager* Instance();
	void Initialize() override;
	void loadSCFFromFile(const std::string& filePath);
	void loadFromHTTP(const std::string& url);
	const nlohmann::json& getData();
	bool fileExists(const std::string& filePath);
	std::string getAppDataPath();
private:
	static DataManager* _instance;
	SCF* _localSCF;
	SCF* _volatile_SCF;
	SCF* _persistent_SCF;
};