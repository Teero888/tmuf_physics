#ifndef CGAMEREMOTEBUFFER_HPP
#define CGAMEREMOTEBUFFER_HPP

#include "typedefs.h"

struct CGameRemoteBuffer {
    void** vftable;
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    int __thiscall CleanRequestingUser (CGameRemoteBuffer *this,CGameRemoteBuffer *param_1,SUser *param_2);
    int __thiscall Unregister(CGameRemoteBuffer *this,CGameRemoteBuffer *param_1,ulong param_2);
    ulong __thiscall InternalGetNewUserSlot(CGameRemoteBuffer *this,CGameRemoteBuffer *param_1);
    ulong __thiscall Register (CGameRemoteBuffer *this,CGameRemoteBuffer *param_1, CFastCallback3P<unsigned_long,unsigned_long,int&> *param_2, CFastCallback2P<unsigned_long,unsigned_long> *param_3,CFastCallback1P<int> *param_4);
};

#endif // CGAMEREMOTEBUFFER_HPP
