#include <iostream>
#include <singleton/GameManager.h>

int main()
{
    GameManager::Instance().Initialize();
    while (GameManager::Instance()._isRunning)
    {
        GameManager::Instance().Update();

        GameManager::Instance().Draw();
    }
}