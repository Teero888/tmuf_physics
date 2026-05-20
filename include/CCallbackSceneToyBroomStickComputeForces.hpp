#ifndef CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP
#define CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneToyBroomstick;

struct CCallbackSceneToyBroomStickComputeForces {
    byte _padding_0x0[64];
    CSceneToyBroomstick * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneToyBroomStickComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENETOYBROOMSTICKCOMPUTEFORCES_HPP
