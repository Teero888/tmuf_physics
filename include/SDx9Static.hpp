#ifndef SDX9STATIC_HPP
#define SDX9STATIC_HPP

#include "typedefs.h"

struct SDx9Static {
    byte _padding_0x0[4];
    int * field_0x4; // accesses: 4
    byte _padding_0x8[4];
    undefined4 field_0xc; // accesses: 2

    // Member Functions
    void __thiscall FullScreenAddMode (void *this,SDx9Static *param_1,ulong param_2,ulong param_3,int param_4,ulong param_5);
    void __thiscall FullScreenRetrieveModes(void *this,SDx9Static *param_1,_D3DFORMAT param_2);
};

#endif // SDX9STATIC_HPP
