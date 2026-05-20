#ifndef CHMSPHYSICALCONTACT_HPP
#define CHMSPHYSICALCONTACT_HPP

#include "typedefs.h"

struct CHmsPhysicalContact {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    float field_0x18; // accesses: 2
    float field_0x1c; // accesses: 2
    float field_0x20; // accesses: 2
    byte _padding_0x24[4];
    float field_0x28; // accesses: 2
    float field_0x2c; // accesses: 2
    byte _padding_0x30[4];
    float field_0x34; // accesses: 4
    float field_0x38; // accesses: 4
    undefined4 field_0x3c; // accesses: 1
    int field_0x40; // accesses: 1
};

#endif // CHMSPHYSICALCONTACT_HPP
