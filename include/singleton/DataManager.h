#pragma once
#ifdef _WIN32
#include <windows.h>
#include <shlobj.h> // For SHGetFolderPath
#endif
#include <interface/IManager.h>
#include <nlohmann/json.hpp>
#include <object/SCF.h>
#include <string>

#include "factory/SCFFactory.h"


class DataManager : public IManager
{
public:
	DataManager();
	~DataManager() override;
	static DataManager* Instance();
	bool Initialize() override;
	void loadSCFFromFile(const std::string& filePath);
	void loadFromHTTP(const std::string& url);
	SCF* getSCF();
	bool fileExists(const std::string& filePath);
	std::string getAppDataPath();
private:
	static DataManager* _instance;
	std::unique_ptr<SCFFactory> _scfFactory;
	std::unique_ptr<SCF> _localSCF;
	std::unique_ptr<SCF> _backupSCF;
};
