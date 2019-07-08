#ifndef SOCKETUDPMODEL_H
#define SOCKETUDPMODEL_H

#include "QByteArray"
#include "QUdpSocket"
#include "QTimer"
#include "QStringListModel"
#include "DataModel.h"
#include <Utilities/receivestrategy.h>

enum Status {OFF,ON};

class ReceiveModel: public QObject
{
private:
    Q_OBJECT
    Status status;
    ReceiveStrategy* receiveStrategy;
    bool isWorking();
public:
    ReceiveModel();
    ~ReceiveModel();
    Status getCurrentStatus();
    void startReceiver();
    void stopReceiver();
    void setReceiveStrategy(ReceiveStrategy* newStrategy);
    void subscribe(DataListener* newListener);
};


#endif // SOCKETUDPMODEL_H
