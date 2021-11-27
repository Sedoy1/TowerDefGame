#ifndef UNTITLED4_LOGGER_H
#define UNTITLED4_LOGGER_H
#include "GameObject.h"

enum {
    NONE,
    CONSOLE_OUT,
    FILE_OUT,
    ALL_INCLUSIVE,
};

class Logger {
private:
    void GetLogs2File();
    void GetLogs2Console();
    std::shared_ptr<GameObject> object;
    int LogsFormat;
public:
    void SetLogsFormat(int formatLog=NONE);
    void AddObject(std::shared_ptr<GameObject> object);
    void GetLogs();
};



#endif //UNTITLED4_LOGGER_H
