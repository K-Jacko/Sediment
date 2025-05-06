#include <singleton/GameManager.h>

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

GameManager* GameManager::Instance()
{
	if (_instance == nullptr)
	{
		std::cout << "Creating new GameManager Instance" << std::endl;
		_instance = new GameManager();
	}
	return _instance;
};

void GameManager::Start()
{
	std::cout << "Engine Launching" << std::endl;
	if (_dataManager->Initialize())
	{
		if (_windowManager->Initialize())
		{

		}
		else
		{
			Stop();
		}
	}
	else
	{
		std::cout << "DataManager Failed to Initialize!" << std::endl;
		Stop();
	}
	//Window Manager
	//Input Manager
	//Asset Manager Can be split it "management" and "factory"
	//// Asset Factory can produce asset on request and AssetManager manages their refference count and memory management in the assigned Total Memory Assigned.
	//Entity Manager // Can be split into a management class and a factory.
	//Config Manager

};

void GameManager::Stop()
{
	std::cout << "Stopping Engine!" << std::endl;
	_isRunning = false;
}



void GameManager::Update()
{
	//Instance().UpdateEvents();
	//Instance().UpdateCamera();
	//Instance().UpdateEverythingElse(){};
	//Instance().UpdateCollision();
};

void GameManager::Draw()
{

}

