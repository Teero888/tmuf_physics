#ifndef CSCENETOYSEA_HPP
#define CSCENETOYSEA_HPP

#include "typedefs.h"

struct CSceneToySeaHouleTable;
struct CSystemFileMemMapped;
struct GmVec4;
struct ulong;

struct CSceneToySea {
    byte _padding_0x0[192];
    CSceneToySeaHouleTable * field_0xc0; // accesses: 7
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
