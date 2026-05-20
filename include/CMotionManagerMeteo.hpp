#ifndef CMOTIONMANAGERMETEO_HPP
#define CMOTIONMANAGERMETEO_HPP

#include "typedefs.h"

struct CInputPortDx8;
struct CMotionManagerMeteoPuffLull;
struct CSystemFileMemMapped;

struct CMotionManagerMeteo {
    byte _padding_0x0[28];
    CSystemFileMemMapped * field_0x1c; // accesses: 2
    int field_0x20; // accesses: 2
    byte _padding_0x24[8];
    int field_0x2c; // accesses: 1
    byte _padding_0x30[132];
    float field_0xb4; // accesses: 1
    byte _padding_0xb8[56];
    float field_0xf0; // accesses: 1
    byte _padding_0xf4[56];
    CMotionManagerMeteoPuffLull * field_0x12c; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall StreamGetDirectionAndIntensityAt (CMotionManagerMeteo *this,CMotionManagerMeteo *param_1,GmVec2 *param_2,float *param_3, float *param_4);
    void __thiscall UpdateAsync(CMotionManagerMeteo *this,CInputPortDx8 *param_1);
    void __thiscall WindGetDirectionAndIntensityAt (CMotionManagerMeteo *this,CMotionManagerMeteo *param_1,GmVec2 *param_2,float *param_3, float *param_4,CMotionWindBlocker *param_5);
};

#endif // CMOTIONMANAGERMETEO_HPP
