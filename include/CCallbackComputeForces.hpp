#ifndef CCALLBACKCOMPUTEFORCES_HPP
#define CCALLBACKCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneVehicleGlider;

struct CCallbackComputeForces {
    byte _padding_0x0[64];
    CSceneVehicleGlider * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall ComputeForces (CCallbackComputeForces *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKCOMPUTEFORCES_HPP
