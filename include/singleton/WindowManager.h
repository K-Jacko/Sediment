#pragma once
#include "interface/IManager.h"
#include "factory/WindowFactory.h"

class WindowManager : public IManager
{
public:
  WindowManager(const WindowManager&) = delete;
  ~WindowManager() override;
  static WindowManager& Instance();
  explicit WindowManager(WindowFactory& factory);
  void Initialize() override;
  Window* CreateSDLWindow();
private:
  WindowManager();
  WindowFactory& _factory;
  std::unordered_map<std::string, Window*> _windows;
  std::vector<SDL_Window&> _activeWindows;
};