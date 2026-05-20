#ifndef CPLUGMATERIAL_HPP
#define CPLUGMATERIAL_HPP

#include "typedefs.h"

struct CPlugMaterial {
    struct CMwNod;
    struct CPlugShader;
    struct CSystemFid;

    struct SDeviceMat {
        byte _padding_0x0[20];
        CSystemFid * field_0x14; // accesses: 2
        CMwNod * field_0x18; // accesses: 9

        // Member Functions
        CPlugShader * __thiscall LoadShader(void *this,SDeviceMat *param_1,CPlugMaterialCustom *param_2);
        void __thiscall ReleaseShaders(void *this,SDeviceMat *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 3
    int * field_0x1c; // accesses: 4
    byte _padding_0x20[8];
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2

    // Member Functions
    CPlugMaterialFx * __thiscall AddMobil_GetMatFx(CPlugMaterial *this,CPlugMaterialFxs *param_1);
    CPlugShader * __thiscall GetSupportedShader(CPlugMaterial *this,CPlugMaterial *param_1);
    int __thiscall DoesContainShader (CPlugMaterial *this,CPlugMaterial *param_1,CPlugShader *param_2,ulong *param_3);
    ulong __thiscall GetModifyMask(CPlugMaterial *this,CPlugMaterialFxFur *param_1);
    ulong __thiscall GetSupportedDeviceMatIndex(CPlugMaterial *this,CPlugMaterial *param_1);
    void __thiscall CPlugMaterial(CPlugMaterial *this,CPlugMaterial *param_1,CPlugShader *param_2);
    void __thiscall CommonConstructor(CPlugMaterial *this,CPlugMaterial *param_1);
    void __thiscall ForceParam(CPlugMaterial *this,CPlugMaterial *param_1,EParam param_2);
};

#endif // CPLUGMATERIAL_HPP
