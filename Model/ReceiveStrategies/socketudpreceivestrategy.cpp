#include "socketudpreceivestrategy.h"

void SocketUdpReceiveStrategy::readDatagram()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPort);
    qDebug() << QString::fromStdString(buffer.toStdString());
    //Notify presenter about new data
    //if(isWorking()) presenter->datagramArrived(QString::fromStdString(buffer.toStdString()));
}

SocketUdpReceiveStrategy::SocketUdpReceiveStrategy()
{
    //Address
    address.setAddress(QHostAddress::LocalHost);
    //Socket
    socket = new QUdpSocket(this);
    socket->bind(address,RECEIVER_PORT);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readDatagram()));
}

SocketUdpReceiveStrategy::~SocketUdpReceiveStrategy()
{
    delete socket;
}
