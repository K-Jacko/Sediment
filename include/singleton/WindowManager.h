#pragma once
#include "interface/IManager.h"
#include "factory/WindowFactory.h"
#include <object/SCF.h>


class WindowManager : public IManager
{
public:
  WindowManager() = default;
  ~WindowManager() override;
  static WindowManager* Instance();
  explicit WindowManager(WindowFactory* factory);
  void Initialize() override;
  Window* CreateSDLWindow(ScreenDetail details);
private:
  static WindowManager* _instance;
  WindowFactory* _factory;
  std::unordered_map<std::string, Window*> _windows;
  std::vector<std::unique_ptr<Window>> _activeWindows;
};