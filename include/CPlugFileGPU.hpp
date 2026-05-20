#ifndef CPLUGFILEGPU_HPP
#define CPLUGFILEGPU_HPP

#include "typedefs.h"

struct CPlugFileGpuBuilder;

struct CPlugFileGPU {
    struct SLoadDesc {
        byte _padding_0x0[4];
        uint field_0x4; // accesses: 2

        // Member Functions
        ulong __thiscall GetNextRegisterIndex (void *this,SLoadDesc *param_1,CFastArray<struct_SPlugGpuLoadFx> *param_2);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[12];
    int field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    uint field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 2
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 3
    byte _padding_0x4c[84];
    undefined4 field_0xa0; // accesses: 1
    byte _padding_0xa4[8];
    undefined4 field_0xac; // accesses: 1
    byte _padding_0xb0[4];
    ID3DXConstantTable * field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 3
    undefined4 field_0xbc; // accesses: 5
    undefined4 field_0xc0; // accesses: 4

    // Member Functions
    CFastString * __thiscall DefineGetValue(CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2);
    SPlugGpuLoadFx * __thiscall LoadFxFindByName (CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2,ulong *param_3);
    void __thiscall AddDxDefines (CPlugFileGPU *this,CPlugFileGPU *param_1, CFastBuffer<struct_CPlugFileGPU::SDxDefine> *param_2);
    void __thiscall CPlugFileGPU(CPlugFileGPU *this,CPlugFileGPU *param_1);
    void __thiscall DefineAddOrSet (CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2,CFastString *param_3);
    void __thiscall DefineIdUpdateFromText(CPlugFileGPU *this,CPlugFileGPU *param_1);
    void __thiscall LoadDescsOnUpdate(CPlugFileGPU *this,CPlugFileGPU *param_1);
    void __thiscall UpdatePlugFromByteCode(CPlugFileGPU *this,CPlugFileGPU *param_1,int param_2);
};

#endif // CPLUGFILEGPU_HPP
