#include "namedpipereceivestrategy.h"

void NamedPipeReceiveStrategy::readDatagram()
{
    QString data = client->readAll();
    //NOTIFY

    //Is needed??
    //client->abort();
    //client->connectToServer(PIPE_NAME);
}

NamedPipeReceiveStrategy::NamedPipeReceiveStrategy()
{
    client = new QLocalSocket();
    client->connectToServer(PIPE_NAME);
    connect(client,SIGNAL(readyRead()),this,SLOT(readData()));
}

NamedPipeReceiveStrategy::~NamedPipeReceiveStrategy()
{
    delete client;
}
