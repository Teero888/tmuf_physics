#ifndef CPLUGSHADERGENERIC_HPP
#define CPLUGSHADERGENERIC_HPP

#include "typedefs.h"

struct CPlugShaderGeneric {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 6
    float field_0x8; // accesses: 6
    float field_0xc; // accesses: 4
    byte _padding_0x10[40];
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    undefined4 field_0x40; // accesses: 2
    float field_0x44; // accesses: 5
    float field_0x48; // accesses: 5
    float field_0x4c; // accesses: 4
    float field_0x50; // accesses: 5
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 3
    undefined4 field_0x68; // accesses: 3
    undefined4 field_0x6c; // accesses: 3
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    uint field_0x8c; // accesses: 32

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugShaderGeneric(CPlugShaderGeneric *this,CPlugShaderGeneric *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetDiffuseSrc (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,GxColor *param_3);
    void __thiscall SetClassicLighting (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,GxColor *param_2,int param_3, int param_4);
    void __thiscall SetClassicVertexLighting (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,int param_3);
    void __thiscall SetEmissive (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,int param_2,GmVec3 *param_3, int param_4);
    void __thiscall SetMaterial (CPlugShaderGeneric *this,CPlugMaterialCustom *param_1,CPlugMaterial *param_2);
    void __thiscall SetVertexColor (CPlugShaderGeneric *this,CPlugShaderGeneric *param_1,EPlugShaderVertexColor param_2, GxColor *param_3);
};

#endif // CPLUGSHADERGENERIC_HPP
