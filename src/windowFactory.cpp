#include <iostream>
#include <ostream>
#include <object/Window.h>
#include "factory/WindowFactory.h"

Window* WindowFactory::CreateSDLWindow(const std::string& name, unsigned int width, unsigned int height, bool fullscreen, bool hidden, bool borderless, bool resizable, bool vsync)
{
	Uint32 flags = 0;
	if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	if (hidden) flags |= SDL_WINDOW_HIDDEN;
	if (borderless) flags |= SDL_WINDOW_BORDERLESS;
	if (resizable) flags |= SDL_WINDOW_RESIZABLE;

	Window* window = new Window();
	if (!window->Initialize(name, width, height,flags))
	{
		delete window;
		std::cerr << "Failed to create window" << std::endl;
		return nullptr;
	}
	return window;
}
