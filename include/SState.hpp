#ifndef SSTATE_HPP
#define SSTATE_HPP

#include "typedefs.h"

struct ushort;

struct SState {
    void** vftable; // accesses: 9
    float field_0x4; // accesses: 9
    float field_0x8; // accesses: 9
    ushort field_0xc; // accesses: 13
    byte _padding_0xe[2];
    undefined4 field_0x10; // accesses: 17
    undefined4 field_0x14; // accesses: 17
};

#endif // SSTATE_HPP
