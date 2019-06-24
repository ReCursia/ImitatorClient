#include "DataModel.h"


QString DataModel::getCheckSumMessage(double firstValue,double secondValue)
{
    return qFuzzyCompare(firstValue,secondValue) ? CHECK_SUM_MESSAGE[OK] : CHECK_SUM_MESSAGE[FAIL];
}

DataModel::DataModel()
{
    model = new QStringListModel();
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

DataModel::~DataModel()
{
    delete model;
}


void DataModel::addDatagram(QString datagram)
{
    QStringList strings = datagram.split(' ');

    QString result;
    double sum = 0;
    for(int i = 0; i < strings.size()-1;i++){
        result.append(strings[i]).append("; ");
        sum += strings[i].toDouble();
    }

    double dataCheckSum = strings.last().toDouble();
    result.append(getCheckSumMessage(sum,dataCheckSum));

    values.append(result);
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

void DataModel::clear()
{
    values.clear();
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

QStringListModel *DataModel::getModel()
{
    return model;
}
