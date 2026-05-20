#ifndef CVISIONSHADERKEEPER_HPP
#define CVISIONSHADERKEEPER_HPP

#include "typedefs.h"

struct CVisionShaderKeeper {
    byte _padding_0x0[8];
    undefined4 * field_0x8; // accesses: 4
    CVisionShaderKeeper * field_0xc; // accesses: 2
    uint field_0x10; // accesses: 16
    byte _padding_0x14[12];
    uint field_0x20; // accesses: 1

    // Member Functions
    ulong __thiscall ShaderAddRef(CVisionShaderKeeper *this,CVisionShaderKeeper *param_1);
    ulong __thiscall ShaderRelease (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,CPlugShader *param_2);
    void __thiscall SetCanBeShared (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,int param_2);
    void __thiscall SetIndexToSort (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,ulong param_2);
    void __thiscall SetSaveBuffer (CVisionShaderKeeper *this,CVisionShaderKeeper *param_1,CClassicBufferMemory *param_2);
    void __thiscall Undirty(CVisionShaderKeeper *this,CDx9IndexBuffer *param_1);
};

#endif // CVISIONSHADERKEEPER_HPP
