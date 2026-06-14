#include <singleton/DataManager.h>

DataManager* DataManager::_instance = 0;

DataManager::DataManager()
{
	_scfFactory = std::make_unique<SCFFactory>();
	_localSCF = nullptr;
	_backupSCF = nullptr;
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
	}
	return _instance;
}

bool DataManager::Initialize()
{
	std::cout << "DataManager Initializing" << std::endl;

	//TODO: Make sure to add GameName or OrgName to local file Dir
	const std::string localPath = getAppDataPath() + _corporationPath;
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

	std::cout << "Local SCF not found at " + localSCFPath +  ". looking for Backup SCF... " << std::endl ;
	std::string backupPath =  "asset/BSCF.json";

	if (fileExists(backupPath))
	{
		_backupSCF = _scfFactory->createSCF(backupPath);
		std::cout << "Backup Config Loaded: \"" + _backupSCF.get()->getName() << "\"" << std::endl;
		return true;

	}

	std::cout << "Backup SCF File failed to load!" << std::endl;
	return false;
}

void DataManager::loadSCFFromFile(const std::string& filePath)
{


}

void DataManager::loadFromHTTP(const std::string& url)
{

}

SCF* DataManager::getSCF()
{
	if (_localSCF) return _localSCF.get();
	if (_backupSCF) return _backupSCF.get();
	std::cerr << "No SCF (local or backup) loaded." << std::endl;
	return nullptr;
}

std::string DataManager::getAppDataPath()
{
#ifdef _WIN32
	char* appData = getenv("LOCALAPPDATA");
	if (appData) {
		return std::string(appData);
	} else {
		std::cerr << "LOCALAPPDATA not set!" << std::endl;
		return "";
	}
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

bool DataManager::fileExists(const std::string& filePath)
{
	std::filesystem::path pathObj(filePath);
	return std::filesystem::exists(filePath);
}

