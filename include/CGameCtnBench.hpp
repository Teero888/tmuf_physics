#ifndef CGAMECTNBENCH_HPP
#define CGAMECTNBENCH_HPP

#include "typedefs.h"

struct CGameCtnBench {
    void** vftable;
    byte _padding_0x4[32];
    int * field_0x24; // accesses: 1
    byte _padding_0x28[16];
    uint field_0x38; // accesses: 5
    int field_0x3c; // accesses: 5
    uint field_0x40; // accesses: 1
    int field_0x44; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CGameCtnBench *this,CInputPortDx8 *param_1);
    void __thiscall Start(CGameCtnBench *this,CGameCtnBench *param_1);
};

#endif // CGAMECTNBENCH_HPP
