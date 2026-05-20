#ifndef CNETCONNECTION_HPP
#define CNETCONNECTION_HPP

#include "typedefs.h"

struct CClassicBufferMemory;
struct CNetNod;

struct CNetConnection {
    void** vftable;
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2

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
