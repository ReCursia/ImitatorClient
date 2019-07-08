#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>
#include <Model/ReceiveModel.h>
#include <Contract/ReceiverContractView.h>

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

const QStringList COMBO_BOX_VALUES = {"UDP","Named pipe","Shared memory"};
enum ComboBoxValues {UDP,NAMED_PIPE,SHARED_MEMORY};

class ReceivePresenter: public QObject, public DataListener
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
    void onCurrentComboBoxIndexChanged(int index);
    void dataArrived(QString data);
};

#endif // SOCKETUDPPRESENTER_H
