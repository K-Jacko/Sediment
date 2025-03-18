#include <iostream>
#include <singleton/GameManager.h>

int main()
{
    GameManager::Instance()->Initialize();
}