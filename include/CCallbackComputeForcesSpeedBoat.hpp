#ifndef CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP
#define CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP

#include "typedefs.h"

struct CCallbackComputeForcesSpeedBoat {
    void** vftable;

    // Member Functions
    void * __thiscall _vector_deleting_destructor_ (CCallbackComputeForcesSpeedBoat *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall ComputeForces (CCallbackComputeForcesSpeedBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1, CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKCOMPUTEFORCESSPEEDBOAT_HPP
