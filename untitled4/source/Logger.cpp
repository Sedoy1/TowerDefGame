#include <iostream>
#include <fstream>
#include "../headers/Logger.h"

void Logger::AddObject(std::shared_ptr<GameObject> newObject){
    object = newObject;
}


void Logger::SetLogsFormat(int formatLog) {
    LogsFormat = formatLog;
}


void Logger::GetLogs() {
    if (object != nullptr) {
        switch (LogsFormat) {
            case CONSOLE_OUT:
                GetLogs2Console();
                break;
            case FILE_OUT:
                GetLogs2File();
                break;
            case ALL_INCLUSIVE:
                GetLogs2Console();
                GetLogs2File();
                break;
            default:
                break;
        }
    }
}

void Logger::GetLogs2File() {
    std::ofstream out;
    out.open("/home/oleg/CLionProjects/TowerDefGame/untitled4/Logs.txt",std::ios_base::app);
    out<<*object;
    out.close();
}

void Logger::GetLogs2Console() {
    std::cout<<*object;
}

