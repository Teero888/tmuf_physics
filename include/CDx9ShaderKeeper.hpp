#ifndef CDX9SHADERKEEPER_HPP
#define CDX9SHADERKEEPER_HPP

#include "typedefs.h"

struct CPlugShader;

struct CDx9ShaderKeeper {
    byte _padding_0x0[12];
    int * field_0xc; // accesses: 3
    byte _padding_0x10[4];
    int field_0x14; // accesses: 1
    byte _padding_0x18[52];
    uint field_0x4c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetShaderBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,ulong param_2,CPlugBitmap *param_3, CPlugBitmapSampler *param_4,EGxTexFilter *param_5);
    void __thiscall ContextAllSetShaderConstants (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CMwId *param_2,GmVec4 *param_3, ulong param_4,int param_5);
    void __thiscall ParseBitmapPixelUpdates (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShader *param_2);
    void __thiscall SetKeeperAllBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShaderApply *param_2, CPlugBitmap *param_3);
};

#endif // CDX9SHADERKEEPER_HPP
