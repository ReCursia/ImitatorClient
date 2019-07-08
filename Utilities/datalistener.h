#ifndef DATALISTENER_H
#define DATALISTENER_H

#include <QString>

class DataListener
{
public:
    virtual ~DataListener();
    virtual void dataArrived(QString data) = 0;
};

#endif // DATALISTENER_H
