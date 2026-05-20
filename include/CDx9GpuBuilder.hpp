#ifndef CDX9GPUBUILDER_HPP
#define CDX9GPUBUILDER_HPP

#include "typedefs.h"

struct CDx9GpuBuilder {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall BuildVHlsl (CDx9GpuBuilder *this,CDx9GpuBuilder *param_1,CMwNodRef<class_CPlugFileGPUV> *param_2, EStdGpuV param_3,SStdGpuMask param_4,CFastString *param_5);
    void __thiscall CDx9GpuBuilder(CDx9GpuBuilder *this,CDx9GpuBuilder *param_1);
};

#endif // CDX9GPUBUILDER_HPP
