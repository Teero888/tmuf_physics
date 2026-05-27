#ifndef CNETSERVER_HPP
#define CNETSERVER_HPP

#include "typedefs.h"

struct CNetServer {
    void** vftable; // accesses: 1
    byte _final_padding[0x15]; // Total size: 0x19

    // Member Functions
    CNetMasterServerRequest * __thiscall Disconnect(CNetServer *this,CGameMasterServer *param_1);
};

#endif // CNETSERVER_HPP
