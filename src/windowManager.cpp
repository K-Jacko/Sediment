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
		std::cout << "SCF Data not valid!" << std::endl;
		return false;
	}

	auto window = CreateSDLWindow(data->displayDetails.screen_details[0]);
	if (!window)
	{
		std::cerr << "Failed to create main window!" << std::endl;
		return false;
	}

	return true;
}

void WindowManager::Update()
{
	IManager::Update();
}

void WindowManager::Draw()
{
	for (auto& window : _activeWindows)
	{
		window.get()->ClearRenderer();
		window.get()->PresentRenderer();
	}
}


Window* WindowManager::CreateSDLWindow(ScreenDetail data)
{
	if (_windows.find(data.title) == _windows.end())
	{
		std::cout << "Creating Window \"" << data.title << "\"" << std::endl;

		auto window = _windowFactory->CreateSDLWindow(
			data.title,
			data.getScreenResolution()._x,
			data.getScreenResolution()._y,
			data.flags,
			data.vsync
		);
		if (!window) return nullptr;

		Window* rawPtr = window.get();
		_activeWindows.push_back(std::move(window));
		_windows[data.title] = rawPtr;
		return rawPtr;
	}

	return nullptr;
}



void WindowManager::OpenWindow()
{

}
