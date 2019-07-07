#ifndef NAMEDPIPERECEIVESTRATEGY_H
#define NAMEDPIPERECEIVESTRATEGY_H

#include <QLocalSocket>
#include <QObject>
#include <Utilities/receivestrategy.h>

const QString PIPE_NAME = "PipeName";

class NamedPipeReceiveStrategy: public QObject, public ReceiveStrategy
{
private:
    Q_OBJECT
    QLocalSocket* client;
private slots:
    void readDatagram();
public:
    NamedPipeReceiveStrategy();
    ~NamedPipeReceiveStrategy();
};

#endif // NAMEDPIPERECEIVESTRATEGY_H
