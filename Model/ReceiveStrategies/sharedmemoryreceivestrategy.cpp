#include "sharedmemoryreceivestrategy.h"

#include <QBuffer>
#include <QDebug>

void SharedMemoryReceiveStrategy::run()
{
    while(true){
        qDebug() << "НУКА БЛЕ";
        freeToRead->acquire();
        sharedMemory->setKey(SHARED_MEMORY_NAME);
        QBuffer buffer;
        buffer.setData((char*)sharedMemory->constData(),sharedMemory->size());
        buffer.open(QBuffer::ReadOnly);
        QString data = buffer.readAll();
        qDebug() << data;
        freeToWrite->release();
    }
}

SharedMemoryReceiveStrategy::SharedMemoryReceiveStrategy()
{
    sharedMemory = new QSharedMemory();
    freeToRead = new QSystemSemaphore(SEMAPHORE_NAME_READ,0,QSystemSemaphore::Open);
    freeToWrite = new QSystemSemaphore(SEMAPHORE_NAME_WRITE,0,QSystemSemaphore::Open);
    this->start();
}

SharedMemoryReceiveStrategy::~SharedMemoryReceiveStrategy()
{
    delete sharedMemory;
    delete semaphore;
}
