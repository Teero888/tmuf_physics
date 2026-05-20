#ifndef GMFIELD2BASE_HPP
#define GMFIELD2BASE_HPP

#include "typedefs.h"

struct GmField2Base {
    void** vftable; // accesses: 2
    float field_0x4; // accesses: 3
    float field_0x8; // accesses: 2
    byte _padding_0xc[8];
    float field_0x14; // accesses: 1
    float field_0x18; // accesses: 1
    uint field_0x1c; // accesses: 6
    uint field_0x20; // accesses: 6

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall GetBoundingCoords (GmField2Base *this,GmField2Base *param_1,GmVec2 *param_2,GmNat2 *param_3,GmNat2 *param_4, GmVec2 *param_5);
};

#endif // GMFIELD2BASE_HPP
