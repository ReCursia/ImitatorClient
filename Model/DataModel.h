#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "QList"
#include "QStringListModel"
class DataModel
{
private:
    QStringList values;
    QStringListModel* model; 
public:
    DataModel();
    ~DataModel();
    void addDatagram(QString datagram);
    void clear();
    QStringListModel* getModel();
};

#endif // DATAMODEL_H
