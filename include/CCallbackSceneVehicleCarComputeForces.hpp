#ifndef CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
#define CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneVehicleCar;

struct CCallbackSceneVehicleCarComputeForces {
    byte _padding_0x0[64];
    CSceneVehicleCar * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneVehicleCarComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
