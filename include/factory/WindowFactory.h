#pragma once
#include <interface/IFactory.h>
#include <object/Window.h>

class WindowFactory : public IFactory
{
public:
	WindowFactory() = default;
	~WindowFactory() override;
	static Window* CreateSDLWindow(const std::string& name, unsigned int width, unsigned int height, bool fullscreen, bool hidden, bool borderless, bool resizable, bool vsync);
};