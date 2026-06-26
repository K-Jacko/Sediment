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
  bool isRunning = false;
  static float deltaTime;
  float elapsedTime = 0.0f;

  DataManager* dataManager = nullptr;
  WindowManager* windowManager = nullptr;
  AssetManager* assetManager = nullptr;
  private:
  static GameManager* _instance;
  Uint64 _lastCounter = 0;
  std::unique_ptr<World> _world;
  SDL_Event _event;
};
