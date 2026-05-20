#ifndef CNETCONNECTEDCLIENT_HPP
#define CNETCONNECTEDCLIENT_HPP

#include "typedefs.h"

struct CNetConnectedClient {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 2
    ulong field_0x24; // accesses: 2
    float field_0x28; // accesses: 1
    byte _padding_0x2c[100];
    int field_0x90; // accesses: 1

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Poll(void *this,CNetServer *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2);
};

#endif // CNETCONNECTEDCLIENT_HPP
