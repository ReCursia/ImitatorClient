#include "ReceivePresenter.h"

#include <Model/ReceiveStrategies/namedpipereceivestrategy.h>
#include <Model/ReceiveStrategies/sharedmemoryreceivestrategy.h>
#include <Model/ReceiveStrategies/socketudpreceivestrategy.h>

ReceivePresenter::ReceivePresenter(ReceiverContractView* view)
{
    this->view = view;
    receiveModel = new ReceiveModel();
    //Subscribe
    receiveModel->subscribe(this);
    //Data model
    dataModel = new DataModel();
    //Connect model to listView
    view->setListModel(dataModel->getModel());
    //Led is OFF
    view->lightOffLed();
    //Combo box
    //TODO FIX THAT
    for(int i = 0; i < 3; i++){
        ComboBoxValues value = static_cast<ComboBoxValues>(i);
        view->addItemToComboBox(COMBO_BOX_VALUES[value]);
    }
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

void ReceivePresenter::dataArrived(QString data)
{
    switch(receiveModel->getCurrentStatus()){
    case OFF:
        //NOTHING
        break;
    case ON:
        addDatagramToList(data);
        break;
    }
}

void ReceivePresenter::onCurrentComboBoxIndexChanged(int index)
{
    switch(index){
    case UDP:
        receiveModel->setReceiveStrategy(new SocketUdpReceiveStrategy());
        break;
    case NAMED_PIPE:
        receiveModel->setReceiveStrategy(new NamedPipeReceiveStrategy());
        break;
    case SHARED_MEMORY:
        receiveModel->setReceiveStrategy(new SharedMemoryReceiveStrategy());
        break;
    }
}
