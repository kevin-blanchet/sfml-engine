#pragma once
#include "Manager.h"
#include <string>

#define LM ae::LogManager::getInstance()

namespace ae {

class LogManager :
    public Manager
{
public:
    static LogManager& getInstance();

    bool initialize();
    void terminate();

    void consoleLog(const char* fmt, ...);
    /* TODO : output error log to file */
    void errorLog(const char* fmt, ...);
    std::string  getTimeString();
private:
    LogManager(); //Singleton - Le constructeur est privé
    LogManager(const LogManager&) = delete; //Singleton - pas de copie
    LogManager& operator=(const LogManager&) = delete; //Singleton - pas d'assignation
};

} // namespace ae