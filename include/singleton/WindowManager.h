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
  bool Initialize() override;
  void Update() override;
  Window* CreateSDLWindow(ScreenDetail details);
  void OpenWindow();
  void Draw();
  Window* defaultWindow() const;
private:
  static WindowManager* _instance;
  std::unique_ptr<WindowFactory> _windowFactory;
  std::unordered_map<std::string, std::unique_ptr<Window>> _windows;
};