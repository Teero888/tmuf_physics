#ifndef CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
#define CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CCallbackSceneVehicleCarComputeForces {
    void** vftable;

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneVehicleCarComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENEVEHICLECARCOMPUTEFORCES_HPP
