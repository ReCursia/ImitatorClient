#include "sharedmemoryreceivestrategy.h"

#include <QBuffer>
#include <QDebug>

void SharedMemoryReceiveStrategy::run()
{
    while(true){
        qDebug() << "НУКА БЛЕ";
        semaphore->acquire();
        sharedMemory->setKey(SHARED_MEMORY_NAME);
        QBuffer buffer;
        buffer.setData((char*)sharedMemory->constData(),sharedMemory->size());
        buffer.open(QBuffer::ReadOnly);
        QString data = buffer.readAll();
        qDebug() << data;
        semaphore->release();
    }
}

SharedMemoryReceiveStrategy::SharedMemoryReceiveStrategy()
{
    sharedMemory = new QSharedMemory();
    semaphore = new QSystemSemaphore(SEMAPHORE_NAME,0,QSystemSemaphore::Open);
    this->start();
}

SharedMemoryReceiveStrategy::~SharedMemoryReceiveStrategy()
{
    delete sharedMemory;
    delete semaphore;
}
