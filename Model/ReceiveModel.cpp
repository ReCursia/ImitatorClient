#include "ReceiveModel.h"
#include "QDebug"
#include <Model/ReceiveStrategies/namedpipereceivestrategy.h>
#include <Model/ReceiveStrategies/sharedmemoryreceivestrategy.h>
#include <Model/ReceiveStrategies/socketudpreceivestrategy.h>

ReceiveModel::ReceiveModel(){
    //Status
    status = OFF;
    //Strategy
    receiveStrategy = new SocketUdpReceiveStrategy();
}

ReceiveModel::~ReceiveModel(){
    delete receiveStrategy;
}

Status ReceiveModel::getCurrentStatus()
{
    return status;
}

void ReceiveModel::startReceiver()
{
    status = ON;
}

void ReceiveModel::stopReceiver()
{
    status = OFF;
}

void ReceiveModel::setReceiveStrategy(ReceiveStrategy *newStrategy)
{
    //delete receiveStrategy;
    //receiveStrategy = newStrategy;
}

void ReceiveModel::subscribe(DataListener *newListener)
{
    receiveStrategy->manager->subscribe(newListener);
}

bool ReceiveModel::isWorking()
{
    return (status == ON);
}
