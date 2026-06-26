#define SDL_MAIN_HANDLED
#include <singleton/GameManager.h>
#include <cstdio>

int main(int argc, char* args[])
{
    GameManager::Instance()->Initialize();
    while (GameManager::Instance()->isRunning)
    {
        GameManager::Instance()->Update();
        GameManager::Instance()->Draw();
    }
    return 0;
}