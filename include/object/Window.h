#pragma once
#include <SDL.h>
#include <string>

class Window
{
public:
	Window(int width, int height) : _width(width), _height(height){};
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
	Window(Window&& other) noexcept;
	Window& operator=(Window&& other) noexcept;
	~Window();
	bool Initialize(std::string name, Uint32 flags, bool vsync);
  void Update();
	void Draw();
	SDL_Renderer* getRenderer();
	void SetWidth(int width);
	void SetHeight(int height);
	int GetWidth();
	int GetHeight();
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
