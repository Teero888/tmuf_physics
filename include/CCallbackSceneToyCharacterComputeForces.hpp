#ifndef CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP
#define CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CSceneToyCharacter;

struct CCallbackSceneToyCharacterComputeForces {
    byte _padding_0x0[64];
    CSceneToyCharacter * field_0x40; // accesses: 1

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneToyCharacterComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP
