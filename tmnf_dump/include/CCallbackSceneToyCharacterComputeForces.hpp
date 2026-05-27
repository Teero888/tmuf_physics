#ifndef CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP
#define CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP

#include "typedefs.h"

struct CCallbackSceneToyCharacterComputeForces {
    void** vftable;

    // Member Functions
    void __thiscall ComputeForces (CCallbackSceneToyCharacterComputeForces *this, CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,float param_3);
};

#endif // CCALLBACKSCENETOYCHARACTERCOMPUTEFORCES_HPP
