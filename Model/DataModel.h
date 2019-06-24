#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QList"
#include "QStringListModel"

const QStringList CHECK_SUM_MESSAGE = {"КС: ОК","КС: FAIL"};
enum CheckSum {OK,FAIL};

class DataModel
{
private:
    QStringList values;
    QStringListModel* model;
    QString getCheckSumMessage(double firstValue,double secondValue);
public:
    DataModel();
    ~DataModel();
    void addDatagram(QString datagram);
    void clear();
    QStringListModel* getModel();
};

#endif // DATAMODEL_H
