#ifndef CMWCMDFASTCALLUSER_HPP
#define CMWCMDFASTCALLUSER_HPP

#include "typedefs.h"

struct CMwNod;

struct CMwCmdFastCallUser {
    byte _padding_0x0[28];
    _func___cdecl_void_ulong * field_0x1c; // accesses: 1
    CMwNod * field_0x20; // accesses: 1
    ulong field_0x24; // accesses: 1

    // Member Functions
    void __thiscall CMwCmdFastCallUser (CMwCmdFastCallUser *this,CMwCmdFastCallUser *param_1,CMwNod *param_2, _func___cdecl_void_ulong *param_3,ulong param_4);
};

#endif // CMWCMDFASTCALLUSER_HPP
