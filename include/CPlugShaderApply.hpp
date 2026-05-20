#ifndef CPLUGSHADERAPPLY_HPP
#define CPLUGSHADERAPPLY_HPP

#include "typedefs.h"

struct CPlugShaderApply {
    byte _padding_0x0[32];
    EGxTexOp field_0x20; // accesses: 2
    byte _padding_0x24[108];
    undefined4 field_0x90; // accesses: 1
    byte _padding_0x94[8];
    undefined4 field_0x9c; // accesses: 10
    undefined4 field_0xa0; // accesses: 3

    // Member Functions
    CPlugBitmapApply * __thiscall AddTextureApply (CPlugShaderApply *this,CPlugShaderApply *param_1,CPlugBitmap *param_2,EGxTexOp param_3, ulong param_4);
    void __thiscall CPlugShaderApply(CPlugShaderApply *this,CPlugShaderApply *param_1);
    void __thiscall SetAlphaCmp_Pass (CPlugShaderApply *this,CPlugShaderApply *param_1,EGxAlphaCmp param_2,uchar param_3);
    void __thiscall SetBlendOpPC2(CPlugShaderApply *this,CPlugShaderApply *param_1,EGxBlendOp param_2);
    void __thiscall SetBlending (CPlugShaderApply *this,CPlugShaderPass *param_1,EGxBlendFactor param_2, EGxBlendFactor param_3);
    void __thiscall SetForceIsAlphaBlend(CPlugShaderApply *this,CPlugShaderApply *param_1,int param_2);
};

#endif // CPLUGSHADERAPPLY_HPP
