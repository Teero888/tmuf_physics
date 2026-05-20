#ifndef CGAMEMANIALINKENTRY_HPP
#define CGAMEMANIALINKENTRY_HPP

#include "typedefs.h"

struct CGameManialinkEntry {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined * field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1

    // Member Functions
    void __thiscall CGameManialinkEntry(CGameManialinkEntry *this,CGameManialinkEntry *param_1);
};

#endif // CGAMEMANIALINKENTRY_HPP
