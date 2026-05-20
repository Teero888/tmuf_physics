#ifndef CSCENETOYTRAIN_HPP
#define CSCENETOYTRAIN_HPP

#include "typedefs.h"

struct CSceneToyTrain {

    // Member Functions
    void __thiscall CheckContacts(CSceneToyTrain *this,CSceneToyTrain *param_1);
    void __thiscall UpdateFromDynamicState (CSceneToyTrain *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3, ulong param_4);
};

#endif // CSCENETOYTRAIN_HPP
