#pragma once
#include "interface/IManager.h"
#include <singleton/DataManager.h>
#include <singleton/WindowManager.h>
#include <object/World.h>

#include "AssetManager.h"

class GameManager : public IManager
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
  AssetManager* _assetManager = nullptr;
  private:
  static GameManager* _instance;
  std::unique_ptr<World> _world;
};
