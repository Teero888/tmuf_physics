#ifndef SVEHICLECARSTATE_HPP
#define SVEHICLECARSTATE_HPP

#include "typedefs.h"

struct ushort;

struct SVehicleCarState {
    void** vftable; // accesses: 4
    float field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    ushort field_0xc; // accesses: 3
    byte _padding_0xe[2];
    int field_0x10; // accesses: 4
    int field_0x14; // accesses: 4
};

#endif // SVEHICLECARSTATE_HPP
