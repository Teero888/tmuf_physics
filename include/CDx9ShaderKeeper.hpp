#ifndef CDX9SHADERKEEPER_HPP
#define CDX9SHADERKEEPER_HPP

#include "typedefs.h"

struct CPlugShader;

struct CDx9ShaderKeeper {
    byte _padding_0x0[4];
    CPlugShader * field_0x4; // accesses: 2
    byte _padding_0x8[4];
    CPlugShader * field_0xc; // accesses: 3
    byte _padding_0x10[4];
    int field_0x14; // accesses: 3
    byte _padding_0x18[4];
    CPlugShader * field_0x1c; // accesses: 6
    uint field_0x20; // accesses: 3
    byte _padding_0x24[4];
    float field_0x28; // accesses: 1
    byte _padding_0x2c[32];
    uint field_0x4c; // accesses: 3
    byte _padding_0x50[36];
    int field_0x74; // accesses: 1
    byte _padding_0x78[8];
    uint field_0x80; // accesses: 5
    byte _padding_0x84[1028];
    uint field_0x488; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetShaderBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,ulong param_2,CPlugBitmap *param_3, CPlugBitmapSampler *param_4,EGxTexFilter *param_5);
    void __thiscall ContextAllSetShaderConstants (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CMwId *param_2,GmVec4 *param_3, ulong param_4,int param_5);
    void __thiscall ParseBitmapPixelUpdates (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShader *param_2);
    void __thiscall SetKeeperAllBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShaderApply *param_2, CPlugBitmap *param_3);
};

#endif // CDX9SHADERKEEPER_HPP
