#ifndef CLOADGEOMDYNASPRITE_HPP
#define CLOADGEOMDYNASPRITE_HPP

#include "typedefs.h"

struct CMwNod;

struct CLoadGeomDynaSprite {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[4];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[16];
    int field_0x28; // accesses: 1
    byte _padding_0x2c[64];
    undefined4 field_0x6c; // accesses: 1
    byte _padding_0x70[256];
    CMwNod * field_0x170; // accesses: 1
    CMwNod * field_0x174; // accesses: 1
};

#endif // CLOADGEOMDYNASPRITE_HPP
