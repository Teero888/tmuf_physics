#ifndef CNETTCPCONNECTEDSOCKET_HPP
#define CNETTCPCONNECTEDSOCKET_HPP

#include "typedefs.h"

struct CNetTcpConnectedSocket {

    // Member Functions
    int __thiscall Shutdown(void *this,CNetTcpConnectedSocket *param_1);
    int __thiscall Writable(void *this,CNetTcpConnectedSocket *param_1);
    void __thiscall Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2);
};

#endif // CNETTCPCONNECTEDSOCKET_HPP
