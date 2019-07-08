#include "DataModel.h"
#include "QDebug"
#include "sysinfoapi.h"

QString DataModel::getCheckSumMessage(int firstValue,int secondValue)
{
    return firstValue == secondValue ? CHECK_SUM_MESSAGE[OK] : CHECK_SUM_MESSAGE[FAIL];
}

DataModel::DataModel()
{
    model = new QStringListModel();
    model->setStringList(values);
}

DataModel::~DataModel()
{
    delete model;
}


void DataModel::addDatagram(QString datagram)
{
    QStringList strings = datagram.split(' ');
    QString result;
    int sum = 0;
    for(int i = 0; i < strings.size()-2;i++){
        sum += strings[i].toInt();
    }
    //Check sum
    int dataCheckSum = strings.at(strings.size()-2).toInt();
    result.append(getCheckSumMessage(sum,dataCheckSum)).append("; ");
    //Delta
    unsigned long time_delta = strings.at(strings.size()-1).toUInt();
    result.append("Delta time = ").append(QString::number(GetTickCount()-time_delta));

    values.append(result);
    model->setStringList(values);
}

void DataModel::clear()
{
    values.clear();
    model->setStringList(values);
}

QStringListModel *DataModel::getModel()
{
    return model;
}
