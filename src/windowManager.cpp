#include "../include/singleton/WindowManager.h"


WindowManager& WindowManager::Instance()
{
	static WindowManager instance;
	return instance;
}

WindowManager::WindowManager(WindowFactory& factory)
	: _factory(factory)
{

}

void WindowManager::Initialize()
{
	IManager::Initialize();
	//Consume relative data from DataManager
	//If no screens make screens
	//Register Screens to publicly available methods
}

Window* WindowManager::CreateSDLWindow()
{
	if (_windows.find(name) == _windows.end())
	{
		std::cerr << "Window \"" << name << "\" does not exist!" << std::endl;
		return nullptr;
	}

	Window* window = _factory.CreateSDLWindow(name,  width,  height,  fullscreen,  hidden,  borderless,  resizable, vsync);
}
