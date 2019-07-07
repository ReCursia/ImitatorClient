#include "ReceiveModel.h"
#include "QDebug"

#include <Model/ReceiveStrategies/sharedmemoryreceivestrategy.h>
#include <Model/ReceiveStrategies/socketudpreceivestrategy.h>

ReceiveModel::ReceiveModel(SocketUdpContractPresenter* presenter){
    this->presenter = presenter;
    //Status
    status = OFF;
    //Strategy
    receiveStrategy = new SharedMemoryReceiveStrategy();
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

bool ReceiveModel::isWorking()
{
    return (status == ON);
}
