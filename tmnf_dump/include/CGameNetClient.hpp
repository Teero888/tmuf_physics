#ifndef CGAMENETCLIENT_HPP
#define CGAMENETCLIENT_HPP

#include "typedefs.h"

struct CNetConnection;

struct CGameNetClient {
    void** vftable;
    byte _padding_0x4[344];
    CNetConnection * field_0x15c; // accesses: 2

    // Member Functions
    int __thiscall IsConnected(CGameNetClient *this,CCrystalVertex *param_1);
};

#endif // CGAMENETCLIENT_HPP
