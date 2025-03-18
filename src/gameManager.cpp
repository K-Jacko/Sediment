#include <interface/IManager.h>
#include <singleton/GameManager.h>


GameManager::GameManager()
{

}

GameManager* GameManager::Instance()
{
	static GameManager instance;
	return &instance;
};

void GameManager::Initialize()
{
	IManager::Initialize();
	//Window Manager
	//Input Manager
	//Asset Manager Can be split it "management" and "factory"
	//// Asset Factory can produce asset on request and AssetManager manages their refference count and memory management in the assigned Total Memory Assigned.
	//Entity Manager // Can be split into a management class and a factory.
	//Config Manager

};



void GameManager::Update()
{

};

