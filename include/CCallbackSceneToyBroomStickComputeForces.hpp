#ifndef CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP
#define CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneToyBoat;
struct CSceneToyBroomstick;
struct CSceneToyCharacter;
struct CSceneVehicleCar;
struct CSceneVehicleGlider;
struct CSceneVehicleSpeedBoat;

struct CCallbackSceneToyBroomStickComputeForces {
    byte _padding_0x0[52];
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[8];
    CSceneVehicleSpeedBoat * field_0x40; // accesses: 6

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneToyBroomStickComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP
