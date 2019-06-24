#ifndef SOCKETUDPCONTRACTPRESENTER_H
#define SOCKETUDPCONTRACTPRESENTER_H

#include "QString"

class SocketUdpContractPresenter
{
public:
    virtual ~SocketUdpContractPresenter() = 0;
    virtual void datagramArrived(QString datagram) = 0;
};

#endif // SOCKETUDPCONTRACTPRESENTER_H
