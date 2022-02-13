#pragma once
#include "Manager.h"

#include "GameObject.h"
#include "GameObjectList.h"

#define SM ae::SceneManager::getInstance()

namespace ae {

const int MAX_DISPLAY_LAYER = 20;

class SceneManager :
    public Manager
{
public:
    static SceneManager& getInstance();

    bool initialize();
    void terminate();

    void insertGameObject(GameObject* go);
    void removeGameObject(GameObject* go);
    GameObjectList getAllObjects() const;
    GameObjectList getObjectOfType(std::string type) const;

    void update();
    void draw();

    bool markForDelete(GameObject* go);
private:
    SceneManager(); //Singleton - Le constructeur est privé
    SceneManager(const SceneManager&) = delete; //Singleton - pas de copie
    SceneManager& operator=(const SceneManager&) = delete; //Singleton - pas d'assignation

    GameObjectList aliveList;
    GameObjectList deleteList;

    void deleteAllGameObjectsInList(GameObjectList list);
};

} // namespace ae