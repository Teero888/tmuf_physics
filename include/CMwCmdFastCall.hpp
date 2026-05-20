#ifndef CMWCMDFASTCALL_HPP
#define CMWCMDFASTCALL_HPP

#include "typedefs.h"

struct CMwNod;

struct CMwCmdFastCall {
    byte _padding_0x0[28];
    _func___cdecl_void * field_0x1c; // accesses: 1
    CMwNod * field_0x20; // accesses: 1

    // Member Functions
    void __thiscall CMwCmdFastCall (CMwCmdFastCall *this,CMwCmdFastCall *param_1,CMwNod *param_2,_func___cdecl_void *param_3, ulong param_4);
};

#endif // CMWCMDFASTCALL_HPP
