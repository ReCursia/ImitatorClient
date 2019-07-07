#ifndef SHAREDMEMORYRECEIVESTRATEGY_H
#define SHAREDMEMORYRECEIVESTRATEGY_H

#include <Utilities/receivestrategy.h>

#include <QSharedMemory>
#include <QSystemSemaphore>
#include <QThread>

const QString SEMAPHORE_NAME = "SemaphoreName";
const QString SHARED_MEMORY_NAME = "SharedMemoryName";

class SharedMemoryReceiveStrategy : public QThread, public ReceiveStrategy
{
private:
    Q_OBJECT
    QSharedMemory* sharedMemory;
    QSystemSemaphore* semaphore;
protected:
    void run();
public:
    SharedMemoryReceiveStrategy();
    ~SharedMemoryReceiveStrategy();
};

#endif // SHAREDMEMORYRECEIVESTRATEGY_H
