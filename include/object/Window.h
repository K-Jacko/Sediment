#pragma once
#include <SDL.h>
#include <string>

class Window
{
public:
	Window() : _width(800), _height(600),_positionX(100),_positionY(100) {};
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&& other) noexcept;
	Window& operator=(Window&& other) noexcept;
	~Window();
	bool Initialize(std::string name, unsigned int width, unsigned int height, Uint32 flags);
	void SetWidth(unsigned int width);
	void SetHeight(unsigned int height);
	unsigned int GetWidth();
	unsigned int GetHeight();
	std::string WindowName = "";
	std::string ID = "";
private:
	unsigned int _width = 0;
	unsigned int _height = 0;
	int _positionX = 0;
	int _positionY = 0;
	SDL_DisplayMode _sdl_display_mode {};
	SDL_Window* _sdl_window = nullptr;
	SDL_Renderer* _sdl_renderer = nullptr;

};
