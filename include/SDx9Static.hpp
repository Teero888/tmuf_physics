#ifndef SDX9STATIC_HPP
#define SDX9STATIC_HPP

#include "typedefs.h"

struct SDx9Static {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 2
    byte _padding_0x8[8];
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall FullScreenAddMode (void *this,SDx9Static *param_1,ulong param_2,ulong param_3,int param_4,ulong param_5);
    void __thiscall FullScreenRetrieveModes(void *this,SDx9Static *param_1,_D3DFORMAT param_2);
};

#endif // SDX9STATIC_HPP
