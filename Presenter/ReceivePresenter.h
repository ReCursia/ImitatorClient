#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Model/ReceiveModel.h>
#include <Contract/SocketUdpContractPresenter.h>
#include <Contract/SocketUdpContractView.h>

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

class ReceivePresenter: public QObject, public SocketUdpContractPresenter
{
private:
    Q_OBJECT
    ReceiveModel* receiveModel;
    DataModel* dataModel;
    SocketUdpContractView* view;
private:
    void stopReceiver();
    void startReceiver();
    void addDatagramToList(QString datagram);
public:
    ReceivePresenter(SocketUdpContractView* view);
    ~ReceivePresenter();
    void onStartButtonPressed();
    void onClearButtonPressed();
    void datagramArrived(QString datagram);
};

#endif // SOCKETUDPPRESENTER_H
