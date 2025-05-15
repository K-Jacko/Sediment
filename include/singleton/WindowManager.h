#pragma once
#include "interface/IManager.h"
#include "factory/WindowFactory.h"
#include "singleton/DataManager.h"
#include <object/SCF.h>


class WindowManager : public IManager
{
public:
  WindowManager();
  ~WindowManager() override;
  static WindowManager* Instance();
  explicit WindowManager(WindowFactory* factory);
  bool Initialize() override;
  Window* CreateSDLWindow(ScreenDetail details);
  void OpenWindow();
private:
  static WindowManager* _instance;
  std::unique_ptr<WindowFactory> _windowFactory;
  std::unordered_map<std::string, Window*> _windows;
  std::vector<std::unique_ptr<Window>> _activeWindows;
};