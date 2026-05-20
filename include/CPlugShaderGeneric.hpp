#ifndef CPLUGSHADERGENERIC_HPP
#define CPLUGSHADERGENERIC_HPP

#include "typedefs.h"

struct CPlugShaderGeneric {
    void** vftable; // accesses: 1
    byte _final_padding[0x11]; // Total size: 0x15

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
