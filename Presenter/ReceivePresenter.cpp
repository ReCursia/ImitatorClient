#include "ReceivePresenter.h"

ReceivePresenter::ReceivePresenter(SocketUdpContractView* view)
{
    this->view = view;
    receiveModel = new ReceiveModel(this);
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
}

ReceivePresenter::~ReceivePresenter()
{
    delete receiveModel;
    delete dataModel;
    delete view;
}

void ReceivePresenter::stopReceiver()
{
    receiveModel->stopReceiver();
    view->lightOffLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[START]);
}

void ReceivePresenter::startReceiver()
{
    receiveModel->startReceiver();
    view->lightOnLed();
    view->setStartButtonLabel(START_BUTTON_MESSAGE[STOP]);
}

void ReceivePresenter::addDatagramToList(QString datagram)
{
    dataModel->addDatagram(datagram);
    view->scrollListToBottom();
}

void ReceivePresenter::onStartButtonPressed()
{
    switch(receiveModel->getCurrentStatus()){
    case OFF:
        startReceiver();
        break;
    case ON:
        stopReceiver();
        break;
    }
}

void ReceivePresenter::onClearButtonPressed()
{
    dataModel->clear();
}

void ReceivePresenter::datagramArrived(QString datagram)
{
    addDatagramToList(datagram);
}
