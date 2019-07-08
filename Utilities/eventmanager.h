#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "datalistener.h"

class EventManager
{
private:
    DataListener* listener;
public:
    EventManager();
    ~EventManager();
    void subscribe(DataListener* newListener);
    void notifiy(QString data);
};

#endif // EVENTMANAGER_H
