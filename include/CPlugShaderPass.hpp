#ifndef CPLUGSHADERPASS_HPP
#define CPLUGSHADERPASS_HPP

#include "typedefs.h"

struct CMwNod;
struct CPlugShader;

struct CPlugShaderPass {
    void** vftable; // accesses: 1
    byte _padding_0x4[48];
    CMwNod * field_0x34; // accesses: 7
    undefined4 field_0x38; // accesses: 8
    byte _padding_0x3c[8];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[8];
    undefined4 field_0x54; // accesses: 1

    // Member Functions
    void __thiscall AttachShader (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugShader *param_2,ulong param_3);
    void __thiscall CPlugShaderPass(CPlugShaderPass *this,CPlugShaderPass *param_1);
    void __thiscall LoadFxReplaceFromGpu (CPlugShaderPass *this,CPlugShaderPass *param_1,EPlugGpuPipeline param_2);
    void __thiscall SetBlending (CPlugShaderPass *this,CPlugShaderPass *param_1,EGxBlendFactor param_2, EGxBlendFactor param_3);
    void __thiscall SetFileGpu (CPlugShaderPass *this,CPlugShaderPass *param_1,EPlugGpuPipeline param_2, CPlugFileGPU *param_3);
    void __thiscall SetPixelShader (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugFileGPUP *param_2);
    void __thiscall SetVertexShader (CPlugShaderPass *this,CPlugShaderPass *param_1,CPlugFileGPUV *param_2);
};

#endif // CPLUGSHADERPASS_HPP
