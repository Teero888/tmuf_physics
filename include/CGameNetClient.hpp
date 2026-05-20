#ifndef CGAMENETCLIENT_HPP
#define CGAMENETCLIENT_HPP

#include "typedefs.h"

struct CNetConnection;

struct CGameNetClient {
    byte _padding_0x0[348];
    CNetConnection * field_0x15c; // accesses: 2

    // Member Functions
    int __thiscall IsConnected(CGameNetClient *this,CCrystalVertex *param_1);
};

#endif // CGAMENETCLIENT_HPP
