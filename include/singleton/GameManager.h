#pragma once
#include <interface/IManager.h>

class GameManager : IManager
{
  public:
    GameManager();
    ~GameManager() override;
    static GameManager& Instance();
    void Initialize() override;
    void Update() override;
    void Draw();
    bool _isRunning;
  private:
};