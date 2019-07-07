#ifndef SOCKETUDPRECEIVESTRATEGY_H
#define SOCKETUDPRECEIVESTRATEGY_H

#include <Utilities/receivestrategy.h>

#include <QObject>
#include <QUdpSocket>

const quint16 RECEIVER_PORT = 3456;

class SocketUdpReceiveStrategy: public QObject, public ReceiveStrategy
{
private:
    Q_OBJECT
    QUdpSocket* socket;
    QHostAddress address;
private slots:
    void readDatagram();
public:
    SocketUdpReceiveStrategy();
    ~SocketUdpReceiveStrategy();
};

#endif // SOCKETUDPRECEIVESTRATEGY_H
