#include "SocketUdpModel.h"
#include "QDebug"

SocketUdpModel::SocketUdpModel(SocketUdpContractPresenter* presenter){
    this->presenter = presenter;
    //Status
    status = OFF;
    //Address
    address.setAddress(QHostAddress::LocalHost);
    //Socket
    socket = new QUdpSocket(this);
    socket->bind(address,RECEIVER_PORT);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readDatagram()));
}

SocketUdpModel::~SocketUdpModel(){
    delete socket;
    delete presenter;
}

Status SocketUdpModel::getCurrentStatus()
{
    return status;
}

QString SocketUdpModel::getCurrentStatusMessage()
{
    switch(status){
    case OFF:
        return "Передача прекращена";
    case ON:
        return "Передача началась";
    }
}

void SocketUdpModel::readDatagram()
{
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;
    socket->readDatagram(buffer.data(),buffer.size(),&sender,&senderPort);
    presenter->datagramArrived(QString::fromStdString(buffer.toStdString()));
}
