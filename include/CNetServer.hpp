#ifndef CNETSERVER_HPP
#define CNETSERVER_HPP

#include "typedefs.h"

struct CNetServer {
    void** vftable; // accesses: 2
    byte _padding_0x4[152];
    int field_0x9c; // accesses: 1

    // Member Functions
    CNetMasterServerRequest * __thiscall Disconnect(CNetServer *this,CGameMasterServer *param_1);
};

#endif // CNETSERVER_HPP
