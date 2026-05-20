#ifndef CNETCONNECTION_HPP
#define CNETCONNECTION_HPP

#include "typedefs.h"

struct CClassicBufferMemory;
struct CNetNod;

struct CNetConnection {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 5
    EProtocol field_0x8; // accesses: 1
    int * field_0xc; // accesses: 1
    byte _padding_0x10[12];
    int field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    ulong field_0x28; // accesses: 1
    byte _padding_0x2c[4];
    ulong field_0x30; // accesses: 2
    byte _padding_0x34[60];
    CNetNod * field_0x70; // accesses: 3
    byte _padding_0x74[20];
    int field_0x88; // accesses: 1
    byte _padding_0x8c[4];
    int field_0x90; // accesses: 3
    byte _padding_0x94[8];
    int field_0x9c; // accesses: 4
    int * field_0xa0; // accesses: 4
    int * field_0xa4; // accesses: 4
    byte _padding_0xa8[12];
    int field_0xb4; // accesses: 2
    int field_0xb8; // accesses: 2
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[12];
    int field_0xcc; // accesses: 2
    int field_0xd0; // accesses: 2
    int field_0xd4; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CNetMasterServerRequest * __thiscall Disconnect(CNetConnection *this,CGameMasterServer *param_1);
    EState __thiscall GetState(CNetConnection *this,CMwCmdFiber *param_1);
    SNetConfig * __thiscall GetConfig(CNetConnection *this,CNetConnection *param_1);
    void __thiscall Poll(CNetConnection *this,CNetServer *param_1);
    void __thiscall Send(CNetConnection *this,CNetConnectedClient *param_1,CNetNod *param_2);
    void __thiscall SendTCP (CNetConnection *this,CNetConnection *param_1,CClassicBufferMemory *param_2,ulong param_3, _func___cdecl_void_ulong *param_4);
    void __thiscall SendUDP (CNetConnection *this,CNetConnection *param_1,CClassicBufferMemory *param_2, _func___cdecl_void_ulong *param_3);
    void __thiscall UpdateSendingInfo (CNetConnection *this,CNetServer *param_1,ulong param_2,EProtocol param_3);
    void __thiscall UpdateSendingNodInfo(CNetConnection *this,CNetServer *param_1,EProtocol param_2);
};

#endif // CNETCONNECTION_HPP
