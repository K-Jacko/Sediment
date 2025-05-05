#include "../include/singleton/WindowManager.h"

WindowManager* WindowManager::_instance = 0;

WindowManager* WindowManager::Instance()
{
	if (_instance == 0)
	{
		std::cout << "Creating new WindowManager Instance" << std::endl;
		_instance = new WindowManager();
	}
	return _instance;
}

WindowManager::WindowManager(WindowFactory* factory)
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

Window* WindowManager::CreateSDLWindow(ScreenDetail data)
{
	if (_windows.find(data.name) == _windows.end())
	{
		std::cerr << "Creating Window \"" <<data.name << "\" does not exist!" << std::endl;
		Window* window = _factory->CreateSDLWindow(data.name,  data.getScreenResolution()._x,  data.getScreenResolution()._y,  false,  false,  false,  true, true);
		return window;
	}
	return nullptr;
}
