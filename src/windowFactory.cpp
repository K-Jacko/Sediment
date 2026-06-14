#include <iostream>
#include <ostream>
#include <object/Window.h>
#include "factory/WindowFactory.h"

std::unique_ptr<Window> WindowFactory::CreateSDLWindow(
	const std::string& name,
	unsigned int width,
	unsigned int height,
	Uint32 flags,
	bool vsync)
{
	std::cout << "Factory:: " << "Creating Window \"" << name << "\"" << std::endl;

	auto window = std::make_unique<Window>();

	if (!window->Initialize(name, width, height, flags, vsync)) {
		std::cerr << "Failed to create window" << std::endl;
		return nullptr;
	}
	std::cout << "Factory:: " << "Window: \"" << name << "\" Created!" << std::endl;

	return window;
}

