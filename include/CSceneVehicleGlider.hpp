#ifndef CSCENEVEHICLEGLIDER_HPP
#define CSCENEVEHICLEGLIDER_HPP

#include "typedefs.h"

struct CHmsItem;

struct CSceneVehicleGlider {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 8
    byte _padding_0x2c[692];
    float field_0x2e0; // accesses: 1
    float field_0x2e4; // accesses: 1
    float field_0x2e8; // accesses: 2
    byte _padding_0x2ec[264];
    float field_0x3f4; // accesses: 1
    float field_0x3f8; // accesses: 1
    float field_0x3fc; // accesses: 1
    float field_0x400; // accesses: 1
    float field_0x404; // accesses: 1
    float field_0x408; // accesses: 1
    float field_0x40c; // accesses: 1
    float field_0x410; // accesses: 2
    float field_0x414; // accesses: 1
    float field_0x418; // accesses: 1
    float field_0x41c; // accesses: 1
    float field_0x420; // accesses: 2
    float field_0x424; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeForces (CSceneVehicleGlider *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
};

#endif // CSCENEVEHICLEGLIDER_HPP
