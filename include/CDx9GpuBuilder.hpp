#ifndef CDX9GPUBUILDER_HPP
#define CDX9GPUBUILDER_HPP

#include "typedefs.h"

struct CDx9GpuBuilder {
    byte _padding_0x0[51];
    undefined4 field_0x33; // accesses: 1

    // Member Functions
    /* WARNING: Control flow encountered bad instruction data */ /* WARNING: Instruction at (ram,0x009a545d) overlaps instruction at (ram,0x009a545c) */ /* WARNING: Unable to track spacebase fully for stack */ void __thiscall CDx9GpuBuilder::CDx9GpuBuilder(CDx9GpuBuilder *this,CDx9GpuBuilder *param_1);
    void __thiscall BuildVHlsl (CDx9GpuBuilder *this,CDx9GpuBuilder *param_1,CMwNodRef<class_CPlugFileGPUV> *param_2, EStdGpuV param_3,SStdGpuMask param_4,CFastString *param_5);
};

#endif // CDX9GPUBUILDER_HPP
