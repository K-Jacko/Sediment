#include <singleton/DataManager.h>


void DataManager::Initialize()
{
	//Check if Persistent_SCF exists
	//Check if Local_SCF exists
	//Bonus:: To ensure the application always has a valid config file we can have a standard backup SCF that sits on a server
	//We can then download it to our local file 

	if (_persistent_SCF.isValid())
	{

	}
	else
	{
		std::cout << "Persistent ConfigFile not valid" << std::endl;
		if (_local_SCF.isValid())
		{
			//
		}
		else
		{
			std::cout << "Local ConfigFile not valid" << std::endl;
			return;
		}
	}

}

void DataManager::loadFromFile(const std::string& filePath)
{
	if (filePath.empty())
	{
		std::cout << "File Path is empty" << std::endl;
	}
	std::cout << "Loading SCF from local path" << std::endl;
}


const web::json::value& DataManager::getData()
{
	// if (!_volKCF.isEmpty()) return _volKCF.getJson();
	// if (!_localKCF.isEmpty()) return _localKCF.getJson();
	// return _backupKCF.getJson();
}
