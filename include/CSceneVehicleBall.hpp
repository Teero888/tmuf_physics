#ifndef CSCENEVEHICLEBALL_HPP
#define CSCENEVEHICLEBALL_HPP

#include "typedefs.h"

struct CHmsItem;

struct CSceneVehicleBall {
    struct SVehicleBallState {
        void** vftable; // accesses: 2
        undefined4 field_0x4; // accesses: 2
        undefined4 field_0x8; // accesses: 2
        undefined4 field_0xc; // accesses: 2
        undefined4 field_0x10; // accesses: 2
        undefined4 field_0x14; // accesses: 2
        undefined4 field_0x18; // accesses: 2
        undefined4 field_0x1c; // accesses: 2
        undefined4 field_0x20; // accesses: 2
        undefined4 field_0x24; // accesses: 2
        undefined4 field_0x28; // accesses: 2
        undefined4 field_0x2c; // accesses: 2
        undefined4 field_0x30; // accesses: 2
        byte _padding_0x34[48];
        undefined4 field_0x64; // accesses: 2
        undefined4 field_0x68; // accesses: 2
        undefined4 field_0x6c; // accesses: 2
        undefined4 field_0x70; // accesses: 2
        undefined4 field_0x74; // accesses: 2
        undefined4 field_0x78; // accesses: 2
        undefined4 field_0x7c; // accesses: 2

        // Member Functions
        void __thiscall BallStateReset(void *this,SVehicleBallState *param_1);
        void __thiscall BallStateSet (void *this,SVehicleBallState *param_1,SVehicleBallState *param_2);
        void __thiscall BallStateSetBlend (void *this,SVehicleBallState *param_1,SVehicleBallState *param_2, SVehicleBallState *param_3,float param_4);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[36];
    int field_0x28; // accesses: 2
    byte _padding_0x2c[36];
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    byte _padding_0x5c[448];
    undefined4 field_0x21c; // accesses: 1
    byte _padding_0x220[16];
    undefined4 field_0x230; // accesses: 1
    byte _padding_0x234[260];
    undefined4 field_0x338; // accesses: 1
    undefined4 field_0x33c; // accesses: 1
    undefined4 field_0x340; // accesses: 1
    byte _padding_0x344[284];
    float field_0x460; // accesses: 1
    byte _padding_0x464[4];
    undefined4 field_0x468; // accesses: 1
    undefined4 field_0x46c; // accesses: 1
    undefined4 field_0x470; // accesses: 1
    byte _padding_0x474[16];
    undefined4 field_0x484; // accesses: 1
    undefined4 field_0x488; // accesses: 1
    byte _padding_0x48c[8];
    float field_0x494; // accesses: 1
    float field_0x498; // accesses: 1
    float field_0x49c; // accesses: 1
    float field_0x4a0; // accesses: 1
    float field_0x4a4; // accesses: 1
    float field_0x4a8; // accesses: 1
    float field_0x4ac; // accesses: 1
    float field_0x4b0; // accesses: 1
    float field_0x4b4; // accesses: 1
    byte _padding_0x4b8[20];
    float field_0x4cc; // accesses: 1
    float field_0x4d0; // accesses: 1
    float field_0x4d4; // accesses: 1

    // Member Functions
    void __thiscall AfterContacts (CSceneVehicleBall *this,CCallbackSceneVehicleBallAfterContacts *param_1,CHmsItem *param_2 );
    void __thiscall AsyncStateCompute(CSceneVehicleBall *this,CSceneVehicleBall *param_1);
    void __thiscall VehicleReset(CSceneVehicleBall *this,CSceneVehicleBall *param_1);
    void __thiscall VehicleUpdateAsync(CSceneVehicleBall *this,CSceneVehicleBall *param_1);
};

#endif // CSCENEVEHICLEBALL_HPP
