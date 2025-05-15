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
  void Start();
  void Update() override;
  void Draw();
  void Stop();
  bool _isRunning = false;

  DataManager* _dataManager = nullptr;
  WindowManager* _windowManager = nullptr;
  private:

  static GameManager* _instance;
};
