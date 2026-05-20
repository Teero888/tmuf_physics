#ifndef CGAMECTNBENCH_HPP
#define CGAMECTNBENCH_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CGameCtnBench {
    void** vftable; // accesses: 3
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[8];
    int * field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 6
    undefined4 field_0x3c; // accesses: 6
    undefined4 field_0x40; // accesses: 2
    int field_0x44; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CGameCtnBench *this,CInputPortDx8 *param_1);
    void __thiscall Start(CGameCtnBench *this,CGameCtnBench *param_1);
};

#endif // CGAMECTNBENCH_HPP
