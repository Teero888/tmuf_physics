#ifndef CCONTROLSIMI2_HPP
#define CCONTROLSIMI2_HPP

#include "typedefs.h"

struct CControlSimi2 {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    int field_0x14; // accesses: 9
    int field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 1
    float field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1

    // Member Functions
    float __thiscall Update(CControlSimi2 *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
};

#endif // CCONTROLSIMI2_HPP
