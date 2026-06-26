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

	Window* window = CreateSDLWindow(data->displayDetails.screen_details[0]);
	if (!window)
	{
		std::cerr << "Failed to create main window!" << std::endl;
		return false;
	}

	return true;
}

void WindowManager::Update()
{
  for (const auto& [name, window] : _windows)
	{
		window->Update();
	}

}

void WindowManager::Draw()
{
	for (const auto& [name, window] : _windows)
	{
		window->Draw();
	}
}

Window* WindowManager::defaultWindow() const
{
  if (_windows.empty())
  {
    return nullptr;
  }

  return _windows.begin()->second.get();
}

Window* WindowManager::CreateSDLWindow(ScreenDetail data)
{
	if (_windows.find(data.title) == _windows.end())
	{
		auto window = _windowFactory->CreateSDLWindow(
			data.title,
			data.resolutionWidth,
			data.resolutionHeight,
			data.flags,
			data.vsync
		);
		if (!window) return nullptr;

		Window* rawPtr = window.get();
		_windows[data.title] = std::move(window);
		return rawPtr;
	}

	return nullptr;
}



void WindowManager::OpenWindow()
{

}
