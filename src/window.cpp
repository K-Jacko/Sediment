#include <iostream>
#include <object/Window.h>


Window::~Window()
{
	if (_sdl_renderer)
	{
		SDL_DestroyRenderer(_sdl_renderer);
		_sdl_renderer = nullptr;
	}
	if (_sdl_window)
	{
		SDL_DestroyWindow(_sdl_window);
		_sdl_window = nullptr;
	}
}

bool Window::Initialize(std::string name, unsigned int width, unsigned int height, Uint32 flags, bool vsync)
{
	std::cout << "Window: " << name << " Initializing" << std::endl;

	WindowName = const_cast<char*>(name.c_str());

	Uint32 rendererFlags = 0;
	rendererFlags |= SDL_RENDERER_ACCELERATED;
	if (vsync)
		rendererFlags |= SDL_RENDERER_PRESENTVSYNC;

	_sdl_window = SDL_CreateWindow(
		WindowName.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		flags

		);
	if (!_sdl_window)
	{
		std::cout << "Window: " << name << " Failed to Initialize..." << std::endl;
		std::cout << "sdl_window null" << std::endl;
		return false;
	}

	_sdl_renderer = SDL_CreateRenderer(
		_sdl_window,
		-1,
		rendererFlags
		);
	if (!_sdl_renderer)
	{
		SDL_DestroyWindow(_sdl_window);
		_sdl_window = nullptr;
		std::cout << "Window: " << name << " Failed to Initialize..." << std::endl;
		std::cout << "sdl_renderer null" << std::endl;
		return false;
	}
	return true;
}




Window::Window(Window&& other) noexcept{}

void Window::SetWidth(unsigned int width){_width = width;}
void Window::SetHeight(unsigned int height){_height = height;}
unsigned int Window::GetWidth(){return _width;}
unsigned int Window::GetHeight(){return _height;}

void Window::Draw()
{
	SDL_RenderClear(_sdl_renderer);
	SDL_RenderPresent(_sdl_renderer);
}

SDL_Renderer* Window::getRenderer()
{
	return _sdl_renderer;
}

Window& Window::operator=(Window&& other) noexcept
{
	if (this != &other)
	{
		if (_sdl_renderer) SDL_DestroyRenderer(_sdl_renderer);
		if (_sdl_window) SDL_DestroyWindow(_sdl_window);

		_sdl_window = other._sdl_window;
		_sdl_renderer = other._sdl_renderer;
		_width = other._width;
		_height = other._height;
		WindowName = other.WindowName;
		ID = other.ID;

		other._sdl_renderer = nullptr;
		other._sdl_window = nullptr;
	}
	return *this;
}
