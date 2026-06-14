#pragma once
#include <memory>
#include <interface/IFactory.h>
#include <object/Window.h>

class WindowFactory : public IFactory
{
public:

	static std::unique_ptr<Window> CreateSDLWindow(const std::string& name, unsigned int width, unsigned int height, Uint32 flags, bool vsync);
};