#pragma once
#include "Manager.h"

#define GM ae::GameManager::getInstance()

namespace ae {

class GameManager :
    public Manager
{
public:
    static GameManager& getInstance();

    bool initialize();
    void run();
    void terminate();

    void setRunning(bool running = false);
    bool isRunning();

private:
    bool bRunning;

    GameManager(); //Singleton - Le constructeur est privé
    GameManager(const GameManager&) = delete; //Singleton - pas de copie
    GameManager& operator=(const GameManager&) = delete; //Singleton - pas d'assignation
};

} // namespace ae