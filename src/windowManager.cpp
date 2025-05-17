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

bool WindowManager::Initialize()
{
	IManager::Initialize();
	std::cout << "WindowManager Initializing" << std::endl;
	SCF* data = DataManager::Instance()->getSCF();
	if (!data->isValid())
	{
		std::cout << "SCF Data no valid!" << std::endl;
	}

	Window* window = CreateSDLWindow(data->displayDetails.screen_details[0]);

	return true;
}

Window* WindowManager::CreateSDLWindow(ScreenDetail data)
{
	if (_windows.find(data.title) == _windows.end())
	{
		std::cout << "Creating Window \"" << data.title << "\"" << std::endl;
		Window* window = _windowFactory->CreateSDLWindow(data.title,  data.getScreenResolution()._x,  data.getScreenResolution()._y,  false,  false,  false,  true, true);
		return window;
	}
	return nullptr;
}


void WindowManager::OpenWindow()
{

}
