#ifndef SMANIALINKFORMAT_HPP
#define SMANIALINKFORMAT_HPP

#include "typedefs.h"

struct CMwNod;

struct SManialinkFormat {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    CMwNod * field_0x34; // accesses: 5

    // Member Functions
    void __thiscall SManialinkFormat(void *this,SManialinkFormat *param_1);
};

#endif // SMANIALINKFORMAT_HPP
