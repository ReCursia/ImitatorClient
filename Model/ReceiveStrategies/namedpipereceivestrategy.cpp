#include "namedpipereceivestrategy.h"

void NamedPipeReceiveStrategy::readDatagram()
{
    QString data = client->readAll();
    manager->notifiy(data);
    client->disconnectFromServer();
    client->connectToServer(PIPE_NAME);
}

NamedPipeReceiveStrategy::NamedPipeReceiveStrategy()
{
    client = new QLocalSocket();
    client->waitForConnected();
    client->connectToServer(PIPE_NAME);
    connect(client,SIGNAL(readyRead()),this,SLOT(readDatagram()));
}

NamedPipeReceiveStrategy::~NamedPipeReceiveStrategy()
{
    delete client;
}
