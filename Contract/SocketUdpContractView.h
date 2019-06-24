#ifndef SOCKETUDPCONTRACT_H
#define SOCKETUDPCONTRACT_H

#include <QObject>
#include<QStringListModel>

class SocketUdpContractView
{
public:
    virtual ~SocketUdpContractView() = 0;
    //Start button
    virtual void setStartButtonLabel(QString str) = 0;
    //Status bar
    virtual void setStatusBarMessage(QString message) = 0;
    //Led
    virtual void lightOnLed() = 0;
    virtual void lightOffLed() = 0;
    //List view
    virtual void setListModel(QStringListModel* model) = 0;
    virtual void scrollListToBottom() = 0;
};

#endif // SOCKETUDPCONTRACT_H
