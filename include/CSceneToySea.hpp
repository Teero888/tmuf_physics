#ifndef CSCENETOYSEA_HPP
#define CSCENETOYSEA_HPP

#include "typedefs.h"

struct CPlugAudio;
struct CSceneToySeaHouleTable;
struct CSystemFileMemMapped;
struct GmVec4;

struct CSceneToySea {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 1
    byte _padding_0x8[12];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[4];
    SPlugGpuLoadFx * field_0x1c; // accesses: 2
    SPlugGpuLoadFx * field_0x20; // accesses: 1
    byte _padding_0x24[28];
    CPlugVolumeProjector * field_0x40; // accesses: 1
    CPlugVolumeProjector * field_0x44; // accesses: 1
    byte _padding_0x48[120];
    int field_0xc0; // accesses: 7
    byte _padding_0xc4[16];
    GmVec4 * field_0xd4; // accesses: 1
    byte _padding_0xd8[8];
    GmVec4 * field_0xe0; // accesses: 1
    GmVec4 * field_0xe4; // accesses: 1
    GmVec4 * field_0xe8; // accesses: 1
    GmVec4 * field_0xec; // accesses: 1
    GmVec4 * field_0xf0; // accesses: 1
    byte _padding_0xf4[56];
    CSystemFileMemMapped * field_0x12c; // accesses: 2

    // Member Functions
    ulong __thiscall SetSamplingTime_Async(CSceneToySea *this,CSceneToySea *param_1,int param_2);
    void __thiscall GetPointElevation (CSceneToySea *this,CSceneToySeaHouleFixe *param_1,float param_2,float param_3, float *param_4);
    void __thiscall GetPointElevationAssiette (CSceneToySea *this,CSceneToySeaHouleTable *param_1,float param_2,float param_3, float *param_4);
    void __thiscall UpdateShaderFromHoule(CSceneToySea *this,CSceneToySea *param_1,CPlugShader *param_2);
};

#endif // CSCENETOYSEA_HPP
