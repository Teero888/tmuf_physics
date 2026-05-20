#ifndef CNETCONNECTEDCLIENT_HPP
#define CNETCONNECTEDCLIENT_HPP

#include "typedefs.h"

struct CNetConnection;
struct ulong;

struct CNetConnectedClient {
    void** vftable; // accesses: 8
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    int field_0xc; // accesses: 2
    byte _padding_0x10[12];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 2
    ulong field_0x24; // accesses: 2
    float field_0x28; // accesses: 1

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Poll(void *this,CNetServer *param_1);
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall Send(void *this,CNetConnectedClient *param_1,CNetNod *param_2);
};

#endif // CNETCONNECTEDCLIENT_HPP
