#include "../include/singleton/WindowManager.h"

WindowManager* WindowManager::_instance = 0;
WindowManager::WindowManager()
{
	_windowFactory = std::make_unique<WindowFactory>();
}
WindowManager::~WindowManager()
{

}

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
	: _windowFactory(factory)
{

}

bool WindowManager::Initialize()
{
	IManager::Initialize();
	std::cout << "WindowManager Initializing" << std::endl;
	//Use factory to make the window
	//Open using OpenWindow()
	//ReLaunch
	return true;
}

Window* WindowManager::CreateSDLWindow(ScreenDetail data)
{
	if (_windows.find(data.name) == _windows.end())
	{
		std::cerr << "Creating Window \"" <<data.name << "\" does not exist!" << std::endl;
		Window* window = _windowFactory->CreateSDLWindow(data.name,  data.getScreenResolution()._x,  data.getScreenResolution()._y,  false,  false,  false,  true, true);
		return window;
	}
	return nullptr;
}

void WindowManager::OpenWindow()
{

}
