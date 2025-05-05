#include <singleton/DataManager.h>

DataManager* DataManager::_instance = 0;

DataManager::DataManager()
{
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
		_instance = new DataManager();
	}
	return nullptr;
}

void DataManager::Initialize()
{
	//Check if Persistent_SCF exists
	//Check if Local_SCF exists
	//Bonus:: To ensure the application always has a valid config file we can have a standard backup SCF that sits on a server
	//We can then download it to our local file
	std::string localPath = getAppDataPath();
	if (!std::filesystem::exists(localPath))
	{
		std::filesystem::create_directory(localPath);
		std::cout << "Created directory: " << localPath << std::endl;
	}
	std::string persistentPath =  localPath + "PSCF.json";
	if (fileExists(persistentPath))
	{
		loadSCFFromFile(persistentPath);
	}
	else
	{
		std::cout << "Local SCF JSON File does not exist" << std::endl;
	}


}

void DataManager::loadSCFFromFile(const std::string& filePath)
{
	if (filePath.empty())
	{
		std::cout << "File Path is empty" << std::endl;
	}

	if (!std::filesystem::exists(filePath))
	{
		std::cout << "File does not exist at path:" << filePath << std::endl;
		return;
	}

	std::ifstream file(filePath);
	if (!file)
	{
		std::cout << "File is empty: " << filePath << std::endl;
		return;
	}

	try
	{
		nlohmann::json jsonData;
		std::stringstream buffer;
		buffer << file.rdbuf();
		jsonData = nlohmann::json::parse(buffer.str());

		SCF* scf = new SCF();
		scf->fromJson(jsonData);
		if (scf->isValid())
		{
			std::cout << "Successfully loaded SCF from:" << filePath << std::endl;
			_localSCF = scf;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error parsing JSON" << e.what() << std::endl;
	}
	std::cout << "Loading SCF from local path" << std::endl;

}

void DataManager::loadFromHTTP(const std::string& url)
{

}

std::string DataManager::getAppDataPath()
{
	return nullptr;
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
