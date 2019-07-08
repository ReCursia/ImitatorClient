#ifndef RECEIVESTRATEGY_H
#define RECEIVESTRATEGY_H

#include "eventmanager.h"

class ReceiveStrategy
{
public:
    EventManager* manager;
    ReceiveStrategy();
    virtual ~ReceiveStrategy();
};

#endif // RECEIVESTRATEGY_H
