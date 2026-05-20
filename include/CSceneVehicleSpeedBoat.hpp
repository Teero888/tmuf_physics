#ifndef CSCENEVEHICLESPEEDBOAT_HPP
#define CSCENEVEHICLESPEEDBOAT_HPP

#include "typedefs.h"

struct CHmsItem;
struct CScene;
struct CSceneSector;
struct GmMat3;
struct GmVec3;

struct CSceneVehicleSpeedBoat {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 12
    float field_0x8; // accesses: 12
    float field_0xc; // accesses: 1
    float field_0x10; // accesses: 9
    CScene * field_0x14; // accesses: 11
    float field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    float field_0x20; // accesses: 1
    GmVec3 * field_0x24; // accesses: 1
    int field_0x28; // accesses: 32
    float field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    float field_0x38; // accesses: 2
    float field_0x3c; // accesses: 4
    int field_0x40; // accesses: 1
    float field_0x44; // accesses: 2
    short field_0x48; // accesses: 1
    byte _padding_0x4a[2];
    float field_0x4c; // accesses: 1
    float field_0x50; // accesses: 5
    float field_0x54; // accesses: 5
    float field_0x58; // accesses: 8
    byte _padding_0x5c[8];
    int field_0x64; // accesses: 4
    float field_0x68; // accesses: 3
    float field_0x6c; // accesses: 3
    float field_0x70; // accesses: 3
    CSceneVehicleSpeedBoat * field_0x74; // accesses: 1
    float field_0x78; // accesses: 3
    byte _padding_0x7c[16];
    GmMat3 * field_0x8c; // accesses: 1
    byte _padding_0x90[8];
    GmMat3 * field_0x98; // accesses: 1
    byte _padding_0x9c[8];
    float field_0xa4; // accesses: 1
    byte _padding_0xa8[4];
    float field_0xac; // accesses: 1
    byte _padding_0xb0[12];
    float field_0xbc; // accesses: 1
    float field_0xc0; // accesses: 2
    float field_0xc4; // accesses: 1
    float field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    float field_0xd0; // accesses: 1
    float field_0xd4; // accesses: 1
    float field_0xd8; // accesses: 17
    float field_0xdc; // accesses: 2
    GmMat3 * field_0xe0; // accesses: 1
    CSceneSector * field_0xe4; // accesses: 1
    float field_0xe8; // accesses: 3
    byte _padding_0xec[4];
    float field_0xf0; // accesses: 3
    float field_0xf4; // accesses: 1
    float field_0xf8; // accesses: 1
    byte _padding_0xfc[4];
    undefined4 field_0x100; // accesses: 1
    float field_0x104; // accesses: 1
    float field_0x108; // accesses: 1
    float field_0x10c; // accesses: 2
    float field_0x110; // accesses: 1
    byte _padding_0x114[4];
    float field_0x118; // accesses: 2
    byte _padding_0x11c[4];
    GmVec3 * field_0x120; // accesses: 1
    GmMat3 * field_0x124; // accesses: 1
    CSceneVehicleSpeedBoat * field_0x128; // accesses: 1
    float field_0x12c; // accesses: 2
    float field_0x130; // accesses: 1
    byte _padding_0x134[16];
    float field_0x144; // accesses: 2
    float field_0x148; // accesses: 1
    float field_0x14c; // accesses: 1
    float field_0x150; // accesses: 2
    float field_0x154; // accesses: 1
    byte _padding_0x158[32];
    GmMat3 * field_0x178; // accesses: 1
    byte _padding_0x17c[356];
    int field_0x2e0; // accesses: 3
    undefined4 field_0x2e4; // accesses: 2
    float field_0x2e8; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall LimitTo (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AbsorbContact (CSceneVehicleSpeedBoat *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForces (CSceneVehicleSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeImpulse (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2, GmMat3 *param_3,float param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7, GmVec3 *param_8);
    float __thiscall GetWaterElevation (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,GmVec3 param_2);
    float __thiscall Max8 (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3, float param_4,float param_5,float param_6,float param_7,float param_8,float param_9);
    float __thiscall Min8 (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3, float param_4,float param_5,float param_6,float param_7,float param_8,float param_9);
    float __thiscall MultCoeff (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3);
    void __thiscall ComputeIntertiaMatrix (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1);
};

#endif // CSCENEVEHICLESPEEDBOAT_HPP
