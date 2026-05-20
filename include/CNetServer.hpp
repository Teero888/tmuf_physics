#ifndef CNETSERVER_HPP
#define CNETSERVER_HPP

#include "typedefs.h"

struct CNetMasterServerRequest;

struct CNetServer {
    byte _padding_0x0[28];
    CNetMasterServerRequest * field_0x1c; // accesses: 1
    byte _padding_0x20[112];
    undefined4 field_0x90; // accesses: 2
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 1

    // Member Functions
    CNetMasterServerRequest * __thiscall Disconnect(CNetServer *this,CGameMasterServer *param_1);
};

#endif // CNETSERVER_HPP
