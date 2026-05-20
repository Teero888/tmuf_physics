#ifndef CCALLBACKSCENETOYBOATCOMPUTEFORCES_HPP
#define CCALLBACKSCENETOYBOATCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneToyBoat;

struct CCallbackSceneToyBoatComputeForces {
    byte _padding_0x0[64];
    CSceneToyBoat * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneToyBoatComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENETOYBOATCOMPUTEFORCES_HPP
