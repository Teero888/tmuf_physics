#ifndef CCRYSTALLINK_HPP
#define CCRYSTALLINK_HPP

#include "typedefs.h"

struct CCrystalLink {
    void** vftable;
    int field_0x4; // accesses: 2
    byte _padding_0x8[4];
    int field_0xc; // accesses: 2
    byte _padding_0x10[52];
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 2

    // Member Functions
    void __thiscall Disable(CCrystalLink *this,CCrystalLink *param_1);
};

#endif // CCRYSTALLINK_HPP
