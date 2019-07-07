#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Model/ReceiveModel.h>
#include <Contract/SocketUdpContractPresenter.h>
#include <Contract/ReceiverContractView.h>

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

const QStringList COMBO_BOX_VALUES = {"UDP","Named pipe","Shared memory"};
enum ComboBoxValues {UDP,NAMED_PIPE,SHARED_MEMORY};

class ReceivePresenter: public QObject, public SocketUdpContractPresenter
{
private:
    Q_OBJECT
    ReceiveModel* receiveModel;
    DataModel* dataModel;
    ReceiverContractView* view;
private:
    void stopReceiver();
    void startReceiver();
    void addDatagramToList(QString datagram);
public:
    ReceivePresenter(ReceiverContractView* view);
    ~ReceivePresenter();
    void onStartButtonPressed();
    void onClearButtonPressed();
    void datagramArrived(QString datagram);
    void onCurrentComboBoxIndexChanged(int index);
};

#endif // SOCKETUDPPRESENTER_H
