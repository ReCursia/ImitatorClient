#include "sharedmemoryreceivestrategy.h"

#include <QBuffer>
#include <QDebug>

void SharedMemoryReceiveStrategy::run()
{
    while(true){
        freeToRead->acquire();
        sharedMemory->attach();
        QBuffer buffer;
        buffer.setData((char*)sharedMemory->constData(),sharedMemory->size());
        buffer.open(QBuffer::ReadOnly);
        QString data = buffer.readAll();
        //qDebug() << data;
        manager->notifiy(data);
        sharedMemory->detach();
        freeToWrite->release();
    }
}

SharedMemoryReceiveStrategy::SharedMemoryReceiveStrategy()
{
    sharedMemory = new QSharedMemory();
    sharedMemory->setKey(SHARED_MEMORY_NAME);
    freeToRead = new QSystemSemaphore(SEMAPHORE_NAME_READ,0,QSystemSemaphore::Open);
    freeToWrite = new QSystemSemaphore(SEMAPHORE_NAME_WRITE,0,QSystemSemaphore::Open);
    this->start();
}

SharedMemoryReceiveStrategy::~SharedMemoryReceiveStrategy()
{
    delete sharedMemory;
    delete freeToRead;
    delete freeToWrite;
}
