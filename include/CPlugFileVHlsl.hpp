#ifndef CPLUGFILEVHLSL_HPP
#define CPLUGFILEVHLSL_HPP

#include "typedefs.h"

struct CFastString;
struct CMwNod;
struct CPlugFileGpuBuilder;
struct CPlugGpuCompileCache;

struct CPlugFileVHlsl {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 15
    int field_0x8; // accesses: 3
    char * field_0xc; // accesses: 1
    int field_0x10; // accesses: 2
    char * field_0x14; // accesses: 4
    CPlugFileGpuBuilder * field_0x18; // accesses: 1
    CPlugFileGpuBuilder * field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 3
    CPlugFileVHlsl * field_0x24; // accesses: 7
    byte _padding_0x28[8];
    uint field_0x30; // accesses: 3
    int field_0x34; // accesses: 2
    int field_0x38; // accesses: 2
    byte _padding_0x3c[8];
    float field_0x44; // accesses: 2
    int field_0x48; // accesses: 3
    uint field_0x4c; // accesses: 3
    byte _padding_0x50[60];
    uint field_0x8c; // accesses: 8
    byte _padding_0x90[28];
    CPlugGpuCompileCache * field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    void * field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 2
    byte _padding_0xbc[32];
    undefined4 field_0xdc; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CPlugFileVHlsl * __cdecl GetFixedVHlsl(CPlugShader *param_1);
    void __cdecl LoadCommonVHlsl(void);
    void __thiscall ApplyFidParameter_Crypted (CPlugFileVHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2);
    void __thiscall CPlugFileVHlsl(CPlugFileVHlsl *this,CPlugFileVHlsl *param_1);
    void __thiscall Compile(CPlugFileVHlsl *this,CDx9PixelShader *param_1,int param_2);
};

#endif // CPLUGFILEVHLSL_HPP
