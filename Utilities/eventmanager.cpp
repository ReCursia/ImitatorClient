#include "eventmanager.h"

EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}

void EventManager::subscribe(DataListener *newListener)
{
    listener = newListener;
}

void EventManager::notifiy(QString data)
{
    listener->dataArrived(data);
}

