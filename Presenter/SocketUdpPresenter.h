#ifndef SOCKETUDPPRESENTER_H
#define SOCKETUDPPRESENTER_H

#include <QObject>

#include <Model/SocketUdpModel.h>

#include <Contract/SocketUdpContractPresenter.h>
#include <Contract/SocketUdpContractView.h>


const QStringList STATUS_BAR_MESSAGE = {"Данные утверждены","Параметр успешно удален","Выберите строку для удаления","Параметр успешно добавлен"};
enum StatusMessage {ACCEPTED,LINE_DELETED,CHOOSE_LINE,LINE_ADDED};

const QStringList START_BUTTON_MESSAGE = {"Запуск","Остановка"};
enum StartButtonMessage {START,STOP};

class SocketUdpPresenter: public QObject, public SocketUdpContractPresenter
{
private:
    Q_OBJECT
    SocketUdpModel* socketModel;
    DataModel* dataModel;
    SocketUdpContractView* view;
    Status status;
private:
    void stopReceiver();
    void startReceiver();
    void addDatagramToList(QString datagram);
public:
    SocketUdpPresenter(SocketUdpContractView* view);
    ~SocketUdpPresenter();
    void onStartButtonPressed();
    void onClearButtonPressed();
    // SocketUdpContractPresenter interface
public:
    void statusBarMessageChanged(QString message);
    void datagramArrived(QString datagram);
};

#endif // SOCKETUDPPRESENTER_H
