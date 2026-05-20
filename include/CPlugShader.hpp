#ifndef CPLUGSHADER_HPP
#define CPLUGSHADER_HPP

#include "typedefs.h"

struct CPlugShader {
    void** vftable; // accesses: 17
    undefined * field_0x4; // accesses: 1
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 19
    undefined4 field_0x20; // accesses: 7
    undefined4 field_0x24; // accesses: 2
    undefined2 field_0x28; // accesses: 2
    byte _padding_0x2a[10];
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[12];
    float field_0x44; // accesses: 2
    float field_0x48; // accesses: 2
    float field_0x4c; // accesses: 2
    byte _padding_0x50[60];
    uint field_0x8c; // accesses: 8

    // Member Functions
    CPlugBitmapAddress * __thiscall FindLayerByName(CPlugShader *this,CPlugShader *param_1,CFastString *param_2);
    CPlugBitmapRender * __thiscall FindBitmapRenderByClassId (CPlugShader *this,CPlugShader *param_1,ulong param_2,CPlugBitmap **param_3, CPlugBitmapAddress **param_4);
    GmVec4 * __thiscall GetLoadFxValue (CPlugShader *this,CPlugShader *param_1,CMwId *param_2,SPlugGpuLoadFx **param_3, CPlugShaderPass **param_4,EPlugGpuPipeline *param_5,ulong *param_6);
    int __thiscall GetLoadFxValues (CPlugShader *this,CPlugShader *param_1,CFastBuffer<struct_CPlugShader::SFxValue> *param_2 ,CMwId *param_3);
    ulong __thiscall FindLayerIndexByName(CPlugShader *this,CPlugShader *param_1,CFastString *param_2);
    void __thiscall CPlugShader(CPlugShader *this,CPlugShader *param_1);
    void __thiscall GenerateVshFromFixedPipe(CPlugShader *this,CPlugShader *param_1);
    void __thiscall RemovePasses(CPlugShader *this,CPlugShader *param_1);
    void __thiscall SetBiasZ(CPlugShader *this,CPlugShader *param_1,uchar param_2);
    void __thiscall SetDirty(CPlugShader *this,CPlugVertexStream *param_1,int param_2);
    void __thiscall SetDoubleSided(CPlugShader *this,CPlugShader *param_1,int param_2);
    void __thiscall SetFogEnable(CPlugShader *this,CPlugShader *param_1,int param_2,int param_3);
    void __thiscall SetIgnoreUserClipPlanes(CPlugShader *this,CPlugShader *param_1,int param_2);
    void __thiscall SetPixelShader(CPlugShader *this,CPlugShaderPass *param_1,CPlugFileGPUP *param_2);
    void __thiscall SetReceiverDisable(CPlugShader *this,CPlugShader *param_1);
    void __thiscall SetReceiverShadowGroupMask(CPlugShader *this,CPlugShader *param_1,ulong param_2);
    void __thiscall SetVertexShader(CPlugShader *this,CPlugShaderPass *param_1,CPlugFileGPUV *param_2);
    void __thiscall SetVisibleId(CPlugShader *this,CPlugShader *param_1,SPlugVisibleId *param_2);
};

#endif // CPLUGSHADER_HPP
