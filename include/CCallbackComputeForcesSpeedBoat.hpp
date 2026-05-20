#ifndef CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP
#define CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP

#include "typedefs.h"

struct CSceneVehicleSpeedBoat;

struct CCallbackComputeForcesSpeedBoat {
    byte _padding_0x0[64];
    CSceneVehicleSpeedBoat * field_0x40; // accesses: 1

    // Member Functions
    void * __thiscall _vector_deleting_destructor_ (CCallbackComputeForcesSpeedBoat *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall ComputeForces (CCallbackComputeForcesSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP
