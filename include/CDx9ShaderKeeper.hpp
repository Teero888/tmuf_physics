#ifndef CDX9SHADERKEEPER_HPP
#define CDX9SHADERKEEPER_HPP

#include "typedefs.h"

struct CPlugShader;

struct CDx9ShaderKeeper {
    void** vftable;
    byte _padding_0x4[8];
    int * field_0xc; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetShaderBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,ulong param_2,CPlugBitmap *param_3, CPlugBitmapSampler *param_4,EGxTexFilter *param_5);
    void __thiscall ContextAllSetShaderConstants (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CMwId *param_2,GmVec4 *param_3, ulong param_4,int param_5);
    void __thiscall ParseBitmapPixelUpdates (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShader *param_2);
    void __thiscall SetKeeperAllBitmapNoDirty (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShaderApply *param_2, CPlugBitmap *param_3);
};

#endif // CDX9SHADERKEEPER_HPP
