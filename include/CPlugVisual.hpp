#ifndef CPLUGVISUAL_HPP
#define CPLUGVISUAL_HPP

#include "typedefs.h"

struct CPlugVisual {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[4];
    uint field_0x1c; // accesses: 15
    byte _padding_0x20[20];
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    undefined4 field_0x4c; // accesses: 1
    byte _padding_0x50[28];
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall AddTexCoordSet (CPlugVisual *this,CPlugVisualSprite *param_1,float param_2,float param_3,ulong param_4, float param_5,float param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugVisual(CPlugVisual *this,CPlugVisual *param_1,CPlugVisual *param_2);
    int __thiscall IsVisible(CPlugVisual *this,CPlugVisual *param_1,GmFrustum *param_2,GmIso4 *param_3);
    int __thiscall UpdateVisualFromShaderRequirement (CPlugVisual *this,CPlugVisual *param_1,CPlugShader **param_2,CPlugShader *param_3);
    void __thiscall EnableVertexColor(CPlugVisual *this,CPlugVisual *param_1,int param_2);
    void __thiscall EnableVertexNormal(CPlugVisual *this,CPlugVisual *param_1,int param_2);
    void __thiscall RemoveTexCoordSetAll(CPlugVisual *this,CPlugVisual *param_1);
    void __thiscall SetBoundingBox(CPlugVisual *this,CPlugVisual *param_1,GmBoxAligned *param_2);
    void __thiscall SetBoundingMinMax (CPlugVisual *this,CPlugVisual *param_1,GmVec3 *param_2,GmVec3 *param_3);
};

#endif // CPLUGVISUAL_HPP
