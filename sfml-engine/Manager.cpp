#include "Manager.h"
#include "SceneManager.h"
#include "GameObject.h"

#include <vector>

namespace ae {

Manager::Manager()
{
    initialize();
}

Manager::~Manager()
{
    terminate();
}

bool Manager::initialize()
{
    bStarted = true;
    return true;
}

void Manager::terminate()
{
}

std::string Manager::getType() const
{
    return this->type;
}

bool Manager::isStarted() const
{
    return this->bStarted;
}

int Manager::onEvent(const Event* pEvent) const
{
    int count = 0;

    std::vector<GameObject*> gameObjects = SM.getAllObjects();
    for (auto& i : gameObjects)
    {
        i->eventHandler(pEvent);
        ++count;
    }

    return count;
}

void Manager::setType(std::string newType)
{
    this->type = newType;
}

} // namespace ae