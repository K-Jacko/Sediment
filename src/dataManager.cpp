#include <singleton/DataManager.h>

DataManager* DataManager::_instance = 0;

DataManager::DataManager()
{
	_scfFactory = std::make_unique<SCFFactory>();
	_localSCF = nullptr;
	_volatile_SCF = nullptr;
	_persistent_SCF = nullptr;
}

DataManager::~DataManager()
{
}

DataManager* DataManager::Instance()
{
	if (_instance == nullptr)
	{
		std::cout << "Creating new DataManager Instance" << std::endl;
		_instance = new DataManager();
		return _instance;
	}
	return nullptr;
}

bool DataManager::Initialize()
{
	std::cout << "DataManager Initializing" << std::endl;

	//TODO: Make sure to add GameName or OrgName to local file Dir
	const std::string localPath = getAppDataPath() + "\\WakeIndustries";
	if (!std::filesystem::exists(localPath))
	{
		std::filesystem::create_directory(localPath);
		std::cout << "Created SCF directory: " << localPath << std::endl;
	}

	const std::string localSCFPath = localPath + "\\LSCF.json";

	if (fileExists(localSCFPath))
	{
		_localSCF = _scfFactory->createSCF(localSCFPath);
		return true;
	}
	else
	{
		std::cout << "Local SCF not found at " + localSCFPath +  ". looking for Persistent SCF... " << std::endl ;
		std::string persistentPath =  localPath + "\\PSCF.json";

		if (fileExists(persistentPath))
		{
			SCF* persistentConfig = _scfFactory->createSCF(localSCFPath);
			return true;

		}
		else
		{
			std::cout << "Persistent SCF File failed to load!" << std::endl;
			return false;
		}
	}
}

void DataManager::loadSCFFromFile(const std::string& filePath)
{


}

void DataManager::loadFromHTTP(const std::string& url)
{

}

std::string DataManager::getAppDataPath()
{
#ifdef _WIN32
	// Windows: Use %APPDATA% or %LOCALAPPDATA%
	char* appData = getenv("LOCALAPPDATA");
	return appData ? std::string(appData) : "";
#elif __APPLE__
	// macOS: Use ~/Library/Application Support
	const char* home = getenv("HOME");
	return home ? std::string(home) + "/Library/Application Support" : "";
#else
	// Linux: Use ~/.local/share
	const char* home = getenv("HOME");
	return home ? std::string(home) + "/.local/share" : "";
#endif
}


const nlohmann::json& DataManager::getData()
{
	// if (!_volKCF.isEmpty()) return _volKCF.getJson();
	// if (!_localKCF.isEmpty()) return _localKCF.getJson();
	// return _backupKCF.getJson();
	return nullptr;
}

bool DataManager::fileExists(const std::string& filePath)
{
	std::filesystem::path pathObj(filePath);
	return std::filesystem::exists(filePath);
}

std::string getAppDataPath()
{
#ifdef _WIN32
	char path[MAX_PATH];
	if (SUCCEEDED( SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, path))) {
		return std::string(path) + "\\YourApp\\";
	}
#elif __APPLE__
	return std::string(getenv("HOME")) + "/Library/Application Support/YourApp/";
#elif __linux__
	return std::string(getenv("HOME")) + "/.config/YourApp/";
#else
	return ""; // Unsupported OS
#endif
return "";
}
