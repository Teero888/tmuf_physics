#ifndef CCONTROLCOLORCHOOSER_HPP
#define CCONTROLCOLORCHOOSER_HPP

#include "typedefs.h"

struct CPlugFileGen;
struct CPlugTree;
struct CPlugVisualQuads2D;
struct GmVec3;

struct CControlColorChooser {
    void** vftable; // accesses: 5
    undefined4 field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 4
    byte _padding_0xc[340];
    int field_0x160; // accesses: 2
    undefined4 * field_0x164; // accesses: 1
    undefined4 * field_0x168; // accesses: 1
    byte _padding_0x16c[8];
    CPlugTree * field_0x174; // accesses: 2
    CPlugVisualQuads2D * field_0x178; // accesses: 2
    float field_0x17c; // accesses: 3
    float field_0x180; // accesses: 3
    GmVec3 * field_0x184; // accesses: 1
    float field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 8
    undefined4 field_0x190; // accesses: 8
    undefined4 field_0x194; // accesses: 8
    float field_0x198; // accesses: 4
    byte _padding_0x19c[4];
    int * field_0x1a0; // accesses: 4
    CPlugFileGen * field_0x1a4; // accesses: 4
    undefined4 field_0x1a8; // accesses: 4

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetCursorPosition (CControlColorChooser *this,CControlColorChooser *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetCursorPositionFromNormedPos (CControlColorChooser *this,CControlColorChooser *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetParamsFromRGB (CControlColorChooser *this,CControlColorChooser *param_1,GmVec3 *param_2,int param_3, int param_4,int param_5,int param_6);
    void __thiscall SetColorCursor (CControlColorChooser *this,CControlColorChooser *param_1,GxColor *param_2);
};

#endif // CCONTROLCOLORCHOOSER_HPP
