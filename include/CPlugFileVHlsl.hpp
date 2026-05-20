#ifndef CPLUGFILEVHLSL_HPP
#define CPLUGFILEVHLSL_HPP

#include "typedefs.h"

struct CPlugGpuCompileCache;

struct CPlugFileVHlsl {
    void** vftable; // accesses: 3
    byte _padding_0x4[4];
    int field_0x8; // accesses: 2
    byte _padding_0xc[20];
    undefined4 field_0x20; // accesses: 2
    byte _padding_0x24[136];
    CPlugGpuCompileCache * field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    void * field_0xb4; // accesses: 1
    int * field_0xb8; // accesses: 2
    byte _padding_0xbc[32];
    undefined4 field_0xdc; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugFileVHlsl * __cdecl GetFixedVHlsl(CPlugShader *param_1);
    void __cdecl LoadCommonVHlsl(void);
    void __thiscall ApplyFidParameter_Crypted (CPlugFileVHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2);
    void __thiscall CPlugFileVHlsl(CPlugFileVHlsl *this,CPlugFileVHlsl *param_1);
    void __thiscall Compile(CPlugFileVHlsl *this,CDx9PixelShader *param_1,int param_2);
};

#endif // CPLUGFILEVHLSL_HPP
