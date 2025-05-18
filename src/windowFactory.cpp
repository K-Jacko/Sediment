#include <iostream>
#include <ostream>
#include <object/Window.h>
#include "factory/WindowFactory.h"

WindowFactory::WindowFactory()
{

}

WindowFactory::~WindowFactory()
{

}

std::unique_ptr<Window> WindowFactory::CreateSDLWindow(
	const std::string& name,
	unsigned int width,
	unsigned int height,
	Uint32 flags,
	bool vsync)
{
	auto window = std::make_unique<Window>();

	if (!window->Initialize(name, width, height, flags, vsync)) {
		std::cerr << "Failed to create window" << std::endl;
		return nullptr;
	}
	std::cout << "Window: \"" << name << "\" Created!" << std::endl;

	return window;
}

