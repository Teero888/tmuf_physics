#ifndef SVEHICLESTATE_HPP
#define SVEHICLESTATE_HPP

#include "typedefs.h"

struct SVehicleState {
    void** vftable; // accesses: 3
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 3
    float field_0xc; // accesses: 3
    float field_0x10; // accesses: 3
    undefined4 field_0x14; // accesses: 2
    float field_0x18; // accesses: 3
    undefined4 field_0x1c; // accesses: 2
    float field_0x20; // accesses: 3
    float field_0x24; // accesses: 3
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 3
    float field_0x30; // accesses: 3
    byte _padding_0x34[48];
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 2
    float field_0x6c; // accesses: 4
    float field_0x70; // accesses: 4
    float field_0x74; // accesses: 4
    float field_0x78; // accesses: 3
    float field_0x7c; // accesses: 3
};

#endif // SVEHICLESTATE_HPP
