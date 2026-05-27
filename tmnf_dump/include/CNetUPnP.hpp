#ifndef CNETUPNP_HPP
#define CNETUPNP_HPP

#include "typedefs.h"

struct CNetUPnP {
    void** vftable;
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 3
    int * field_0x18; // accesses: 5

    // Member Functions
    int __thiscall ForceAdd(CNetUPnP *this,CNetUPnP *param_1,EProtocol param_2,ushort param_3, CNetIPAddress *param_4,ushort param_5,CFastStringInt *param_6);
    int __thiscall InitCollection(CNetUPnP *this,CNetUPnP *param_1);
    void __thiscall Remove(CNetUPnP *this, CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *param_1, ulong param_2);
};

#endif // CNETUPNP_HPP
