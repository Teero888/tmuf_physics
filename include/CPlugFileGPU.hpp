#ifndef CPLUGFILEGPU_HPP
#define CPLUGFILEGPU_HPP

#include "typedefs.h"

struct CPlugFileGPU {
    struct SLoadDesc {
        void** vftable; // accesses: 1
        int field_0x4; // accesses: 2

        // Member Functions
        ulong __thiscall GetNextRegisterIndex (void *this,SLoadDesc *param_1,CFastArray<struct_SPlugGpuLoadFx> *param_2);
    };

    void** vftable; // accesses: 6

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
