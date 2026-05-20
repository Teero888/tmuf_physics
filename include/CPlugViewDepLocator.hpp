#ifndef CPLUGVIEWDEPLOCATOR_HPP
#define CPLUGVIEWDEPLOCATOR_HPP

#include "typedefs.h"

struct GmIso4;

struct CPlugViewDepLocator {
    byte _padding_0x0[8];
    float field_0x8; // accesses: 4
    float field_0xc; // accesses: 2
    float field_0x10; // accesses: 1
    int field_0x14; // accesses: 7
    float field_0x18; // accesses: 2
    GmIso4 * field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    float field_0x24; // accesses: 2
    float field_0x28; // accesses: 4
    float field_0x2c; // accesses: 2
    float field_0x30; // accesses: 2
    float field_0x34; // accesses: 2
    float field_0x38; // accesses: 2
    float field_0x3c; // accesses: 2
    byte _padding_0x40[16];
    float field_0x50; // accesses: 2
    float field_0x54; // accesses: 2
    float field_0x58; // accesses: 2
    float field_0x5c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AdaptFrustum (CPlugViewDepLocator *this,CPlugViewDepLocator *param_1,GmIso4 *param_2,GmIso4 *param_3, GmFrustum *param_4,GmMat4 *param_5);
};

#endif // CPLUGVIEWDEPLOCATOR_HPP
