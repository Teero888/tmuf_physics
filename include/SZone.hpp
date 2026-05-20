#ifndef SZONE_HPP
#define SZONE_HPP

#include "typedefs.h"

struct CHmsItem;
struct CHmsZone;
struct CMwNod;
struct SPlugFaceCull;

struct SZone {
    void** vftable; // accesses: 1
    undefined4 * field_0x4; // accesses: 2
    int * field_0x8; // accesses: 1
    int * field_0xc; // accesses: 2
    byte _padding_0x10[4];
    CHmsZone * field_0x14; // accesses: 1
    byte _padding_0x18[48];
    CHmsItem * field_0x48; // accesses: 3
    byte _padding_0x4c[12];
    int field_0x58; // accesses: 2
};

#endif // SZONE_HPP
