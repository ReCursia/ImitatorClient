#include "DataModel.h"


DataModel::DataModel()
{
    model = new QStringListModel();
    model->setStringList(values); //TODO исправить! каждый раз переопредять лист для модели? Возможно некорректно?
}

DataModel::~DataModel()
{
    delete model;
}

QString DataModel::getString(int i)
{
    return values.value(i);
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
    //maybe epsilon
    if(sum == strings[strings.size()-1].toDouble()){
        result.append("КС: ОК");
    }
    else{
        result.append("КС: FAIL");
    }
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
