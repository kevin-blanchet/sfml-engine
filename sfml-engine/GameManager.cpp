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
    while (this->bRunning) {
        this->delta = this->clock.resetDelta();
        float updateTime = this->delta;
        IM.getInput();
        SM.update();
        while (updateTime >= this->fixedDelta)
        {
            SM.fixedUpdate();
            updateTime -= this->fixedDelta;
        }
        SM.draw();
        DM.display();
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

float GameManager::getDelta()
{
    return this->delta;
}

float GameManager::getFixedDelta()
{
    return this->fixedDelta;
}

GameManager::GameManager()
{
    this->setType("GameManager");
    this->setRunning(true);

    this->delta = this->clock.getDelta();
    this->fixedDelta = 0.03f;
}

} // namespace ae