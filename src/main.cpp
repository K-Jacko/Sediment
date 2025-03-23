#include <iostream>
#include <SDL.h>
#include <singleton/GameManager.h>

int main(int argc, char* args[])
{
    GameManager::Instance().Initialize();
    while (GameManager::Instance()._isRunning)
    {
        GameManager::Instance().Update();

        GameManager::Instance().Draw();
    }
    return 0;
}