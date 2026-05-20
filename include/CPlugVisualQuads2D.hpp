#ifndef CPLUGVISUALQUADS2D_HPP
#define CPLUGVISUALQUADS2D_HPP

#include "typedefs.h"

struct CPlugVisualQuads2D {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 12
    undefined4 field_0x8; // accesses: 7
    undefined4 field_0xc; // accesses: 7
    undefined4 field_0x10; // accesses: 5
    undefined4 field_0x14; // accesses: 5
    undefined4 field_0x18; // accesses: 5
    undefined4 field_0x1c; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateQuad (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,GmVec2 param_2,float param_3, float param_4,GxColor *param_5,ulong param_6,float param_7);
    void __thiscall CPlugVisualQuads2D(CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1);
    void __thiscall SetQuadColors (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2,GxColor *param_3, GxColor *param_4,GxColor *param_5,GxColor *param_6);
    void __thiscall SetQuadCount(CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2);
    void __thiscall SetQuadUVs (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2,GmVec2 *param_3, GmVec2 *param_4);
};

#endif // CPLUGVISUALQUADS2D_HPP
