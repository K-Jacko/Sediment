#include "singleton/GameManager.h"
#include "systems/AnimationSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/RenderSystem.h"

GameManager* GameManager::_instance = nullptr;

float GameManager::deltaTime = 0.0f;

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
	_lastCounter = SDL_GetPerformanceCounter();

	dataManager = DataManager::Instance();
	if (!dataManager->Initialize())
	{
		std::cout << "DataManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	windowManager = WindowManager::Instance();
	if (!windowManager->Initialize())
	{
		std::cout << "WindowManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	assetManager = AssetManager::Instance();
	if (!assetManager->Initialize())
	{
		std::cout << "AssetManager Failed to Initialize!" << std::endl;
		Stop();
		return false;
	}

	_world = std::make_unique<World>();
	_world->addSystem<RenderSystem>(_world.get(), windowManager->defaultWindow()->getRenderer());
	_world->addSystem<AnimationSystem>(_world.get());
	_world->addSystem<CollisionSystem>(_world.get());
	_world->start();

	isRunning = true;
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
	isRunning = false;
}



void GameManager::Update()
{
	//Instance().UpdateEvents();
	//Instance().UpdateCamera();
	//Instance().UpdateEverythingElse(){};
	//Instance().UpdateCollision();
	SDL_PollEvent(&_event);

	Uint64 currentCounter = SDL_GetPerformanceCounter();
	deltaTime = static_cast<float>(currentCounter - _lastCounter) / SDL_GetPerformanceFrequency();
	_lastCounter = currentCounter;
	elapsedTime += deltaTime;
	WindowManager::Instance()->Update();
	_world->updateSystems();
};

void GameManager::Draw()
{
	WindowManager::Instance()->Draw();
}

