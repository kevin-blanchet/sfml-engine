#include "GameManager.h"
#include "LogManager.h"
#include "SceneManager.h"
#include "DisplayManager.h"
#include "InputManager.h"

namespace ae {

GameManager& GameManager::getInstance()
{
    static GameManager* gameManager = new GameManager();
    return *gameManager;
}

bool GameManager::initialize()
{
    if (!Manager::initialize()) return false;
    LM.initialize();
    SM.initialize();
    DM.initialize();
    IM.initialize();
    return true;
}

void GameManager::run()
{
    int i = 0;
    while (this->bRunning) {
        IM.getInput();
        SM.update();
        SM.draw();
        DM.display();
        //this->terminate();
    }
}

void GameManager::terminate()
{
    SM.terminate();
    Manager::terminate();
    this->setRunning(false);
}

void GameManager::setRunning(bool running)
{
    this->bRunning = running;
}

bool GameManager::isRunning()
{
    return this->bRunning;
}

GameManager::GameManager()
{
    this->setType("GameManager");
    this->setRunning(true);
}

} // namespace ae