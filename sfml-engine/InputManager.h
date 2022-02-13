#pragma once
#include "Manager.h"

#define IM ae::InputManager::getInstance()

namespace ae {

class InputManager :
    public Manager
{
public:
    static InputManager& getInstance();

    bool initialize();
    void terminate();

    void getInput();
private:
    InputManager(); //Singleton - Le constructeur est privé
    InputManager(const InputManager&) = delete; //Singleton - pas de copie
    InputManager& operator=(const InputManager&) = delete; //Singleton - pas d'assignation
};

} // namespace ae