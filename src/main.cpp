#define SDL_MAIN_HANDLED
#include <singleton/GameManager.h>
#include <cstdio>

int main(int argc, char* args[])
{
    GameManager::Instance()->Start();
    while (GameManager::Instance()->_isRunning)
    {
        GameManager::Instance()->Update();

        GameManager::Instance()->Draw();
    }
    return 0;
}