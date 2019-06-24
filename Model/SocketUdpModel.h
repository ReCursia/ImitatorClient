#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"
#include "QStringListModel"
#include "DataModel.h"
#include <Contract/SocketUdpContractPresenter.h>

enum Status {OFF,ON};

class SocketUdpModel: public QObject
{
private:
    Q_OBJECT
    bool isWorking;
    Status status;
    QUdpSocket* socket;
    QHostAddress address;
    SocketUdpContractPresenter* presenter;
private:
    QString getCurrentStatusMessage();
private slots:
    void readDatagram();
public:
    SocketUdpModel(SocketUdpContractPresenter* presenter);
    ~SocketUdpModel();
    Status getCurrentStatus();
};


#endif // SOCKETUDPMODEL_H
