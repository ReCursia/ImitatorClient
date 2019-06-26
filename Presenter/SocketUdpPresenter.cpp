#include "SocketUdpPresenter.h"

SocketUdpPresenter::SocketUdpPresenter(SocketUdpContractView* view)
{
    this->view = view;
    socketModel = new SocketUdpModel(this);
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
}

SocketUdpPresenter::~SocketUdpPresenter()
{
    delete socketModel;
    delete dataModel;
    delete view;
}

void SocketUdpPresenter::stopReceiver()
{
    socketModel->stopReceiver();
    view->lightOffLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void SocketUdpPresenter::startReceiver()
{
    socketModel->startReceiver();
    view->lightOnLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[STOP]);
}

void SocketUdpPresenter::addDatagramToList(QString datagram)
{
    dataModel->addDatagram(datagram);
    view->scrollListToBottom();
}

void SocketUdpPresenter::onStartButtonPressed()
{
    switch(socketModel->getCurrentStatus()){
    case OFF:
        startReceiver();
        break;
    case ON:
        stopReceiver();
        break;
    }
}

void SocketUdpPresenter::onClearButtonPressed()
{
    dataModel->clear();
}

void SocketUdpPresenter::datagramArrived(QString datagram)
{
    addDatagramToList(datagram);
}
