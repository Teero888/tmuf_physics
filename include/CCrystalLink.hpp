#ifndef CCRYSTALLINK_HPP
#define CCRYSTALLINK_HPP

#include "typedefs.h"

struct CCrystalLink {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    int field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[40];
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 2

    // Member Functions
    void __thiscall Disable(CCrystalLink *this,CCrystalLink *param_1);
};

#endif // CCRYSTALLINK_HPP
