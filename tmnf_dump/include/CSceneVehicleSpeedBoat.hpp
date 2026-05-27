#ifndef CSCENEVEHICLESPEEDBOAT_HPP
#define CSCENEVEHICLESPEEDBOAT_HPP

#include "typedefs.h"

struct CHmsItem;
struct CScene;

struct CSceneVehicleSpeedBoat {
    void** vftable;
    byte _padding_0x4[16];
    CScene * field_0x14; // accesses: 2
    byte _padding_0x18[16];
    CHmsItem * field_0x28; // accesses: 29
    byte _padding_0x2c[36];
    float field_0x50; // accesses: 1
    float field_0x54; // accesses: 1
    float field_0x58; // accesses: 4
    byte _padding_0x5c[8];
    int field_0x64; // accesses: 4
    byte _padding_0x68[632];
    undefined4 field_0x2e0; // accesses: 3
    undefined4 field_0x2e4; // accesses: 2
    float field_0x2e8; // accesses: 5
    byte _final_padding[0x204]; // Total size: 0x4f0

    // Member Functions
    float __thiscall GetWaterElevation (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,GmVec3 param_2);
    float __thiscall LimitTo (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3);
    float __thiscall Max8 (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3, float param_4,float param_5,float param_6,float param_7,float param_8,float param_9);
    float __thiscall Min8 (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3, float param_4,float param_5,float param_6,float param_7,float param_8,float param_9);
    float __thiscall MultCoeff (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2,float param_3);
    void __thiscall AbsorbContact (CSceneVehicleSpeedBoat *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall ComputeForces (CSceneVehicleSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
    void __thiscall ComputeImpulse (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1,float param_2, GmMat3 *param_3,float param_4,GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7, GmVec3 *param_8);
    void __thiscall ComputeIntertiaMatrix (CSceneVehicleSpeedBoat *this,CSceneVehicleSpeedBoat *param_1);
};

#endif // CSCENEVEHICLESPEEDBOAT_HPP
