#ifndef CNETCONNECTEDCLIENT_HPP
#define CNETCONNECTEDCLIENT_HPP

#include "typedefs.h"

struct CNetConnection;

struct CNetConnectedClient {
    void** vftable; // accesses: 6
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    uint field_0xc; // accesses: 2

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Poll(void *this,CNetServer *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2);
};

#endif // CNETCONNECTEDCLIENT_HPP
