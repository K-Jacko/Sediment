#include <singleton/GameManager.h>

#include "systems/RenderSystem.h"

GameManager* GameManager::_instance = nullptr;

GameManager* GameManager::Instance()
{
	if (_instance == nullptr)
	{
		std::cout << "Creating new GameManager Instance" << std::endl;
		_instance = new GameManager();
	}
	return _instance;
};

bool GameManager::Initialize()
{
	std::cout << "Engine Launching" << std::endl;

	_dataManager = DataManager::Instance();
	if (!_dataManager->Initialize())
	{
		std::cout << "DataManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	_windowManager = WindowManager::Instance();
	if (!_windowManager->Initialize())
	{
		std::cout << "WindowManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	_assetManager = AssetManager::Instance();
	if (!_assetManager->Initialize())
	{
		std::cout << "AssetManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	_world = std::make_unique<World>();
	_world->addSystem<RenderSystem>(_world.get(), _windowManager->defaultWindow()->getRenderer());
	_world->start();

	_isRunning = true;
	std::cout << "Engine Running" << std::endl;
	return true;

	//Window Manager
	//Input Manager
	//Asset Manager Can be split it "management" and "factory"
	//// Asset Factory can produce asset on request and AssetManager manages their refference count and memory management in the assigned Total Memory Assigned.
	//Entity Manager // Can be split into a management class and a factory.
	//Config Manager

}

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
	WindowManager::Instance()->Update();
	_world->updateSystems();
};

void GameManager::Draw()
{
	WindowManager::Instance()->Draw();
}

