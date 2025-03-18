#pragma once
#include <interface/IManager.h>

class GameManager : IManager
{
  public:
    GameManager();
    ~GameManager() override;
    static GameManager* Instance();
    void Initialize() override;
    void Update() override;
    bool _isRunning;
  private:
    void Render();
};