#ifndef SHAREDMEMORYRECEIVESTRATEGY_H
#define SHAREDMEMORYRECEIVESTRATEGY_H

#include <Utilities/receivestrategy.h>

#include <QSharedMemory>
#include <QSystemSemaphore>

const QString SEMAPHORE_NAME = "SemaphoreName";
const QString SHARED_MEMORY_NAME = "SharedMemoryName";

class SharedMemoryReceiveStrategy : public ReceiveStrategy
{
private:
    QSharedMemory* sharedMemory;
    QSystemSemaphore* semaphore;
    void readDatagram();
public:
    SharedMemoryReceiveStrategy();
    ~SharedMemoryReceiveStrategy();
};

#endif // SHAREDMEMORYRECEIVESTRATEGY_H
