#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"
#include "QStringListModel"
#include "DataModel.h"
#include <Contract/SocketUdpContractPresenter.h>
#include <Utilities/receivestrategy.h>

enum Status {OFF,ON};

class ReceiveModel: public QObject
{
private:
    Q_OBJECT
    Status status;
    SocketUdpContractPresenter* presenter;
    ReceiveStrategy* receiveStrategy;
    bool isWorking();
public:
    ReceiveModel(SocketUdpContractPresenter* presenter);
    ~ReceiveModel();
    Status getCurrentStatus();
    void startReceiver();
    void stopReceiver();
};


#endif // SOCKETUDPMODEL_H
