#ifndef SDESC_HPP
#define SDESC_HPP

#include "typedefs.h"

struct ulong;

struct SDesc {
    void** vftable; // accesses: 2
    ulong field_0x4; // accesses: 2
    ulong field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 8
};

#endif // SDESC_HPP
