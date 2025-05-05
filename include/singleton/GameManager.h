#pragma once
#include <interface/IManager.h>
#include <singleton/DataManager.h>
#include <singleton/WindowManager.h>

class GameManager : IManager
{
public:
  GameManager();
  ~GameManager() override;
  static GameManager* Instance();
  void Initialize() override;
  void Update() override;
  void Draw();
  bool _isRunning = false;

  DataManager* _dataManager = DataManager::Instance();
  WindowManager* _windowManager = WindowManager::Instance();
  private:

  static GameManager* _instance;
};
