#ifndef CFUNCPUFFLULL_HPP
#define CFUNCPUFFLULL_HPP

#include "typedefs.h"

struct CFuncPuffLull {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    undefined4 field_0x8; // accesses: 5
    undefined4 field_0xc; // accesses: 2
    float field_0x10; // accesses: 2
    uint field_0x14; // accesses: 2
    byte _padding_0x18[16];
    float field_0x28; // accesses: 2
    byte _padding_0x2c[28];
    float field_0x48; // accesses: 2
    byte _padding_0x4c[8];
    float field_0x54; // accesses: 2
    byte _padding_0x58[4];
    float field_0x5c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateStateCurrent (CFuncPuffLull *this,CFuncPuffLull *param_1,ulong param_2,EState param_3,float param_4);
};

#endif // CFUNCPUFFLULL_HPP
