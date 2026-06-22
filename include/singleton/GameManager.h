#pragma once
#include "interface/IManager.h"
#include "singleton/DataManager.h"
#include "singleton/WindowManager.h"
#include "singleton/AssetManager.h"
#include <object/World.h>

class GameManager : public IManager
{
public:
  static GameManager* Instance();
  bool Initialize() override;
  void Update() override;
  void Draw();
  void Stop();
  bool _isRunning = false;

  DataManager* _dataManager = nullptr;
  WindowManager* _windowManager = nullptr;
  AssetManager* _assetManager = nullptr;
  private:
  static GameManager* _instance;
  std::unique_ptr<World> _world;
};
