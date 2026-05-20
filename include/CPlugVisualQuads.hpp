#ifndef CPLUGVISUALQUADS_HPP
#define CPLUGVISUALQUADS_HPP

#include "typedefs.h"

struct GmVec3;
struct GxColor;

struct CPlugVisualQuads {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    float field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateQuadZ (CPlugVisualQuads *this,CPlugVisualQuads *param_1,GmVec3 param_2,float param_3, float param_4,GxColor *param_5,ulong param_6,GmVec3 *param_7);
    void __thiscall BoxQuadAdd (CPlugVisualQuads *this,CPlugVisualQuads *param_1,float param_2,ulong param_3, GxColor *param_4);
    void __thiscall CPlugVisualQuads(CPlugVisualQuads *this,CPlugVisualQuads *param_1);
};

#endif // CPLUGVISUALQUADS_HPP
