#include "receivestrategy.h"

ReceiveStrategy::ReceiveStrategy()
{
    manager = new EventManager();
}

ReceiveStrategy::~ReceiveStrategy()
{
    delete manager;
}
