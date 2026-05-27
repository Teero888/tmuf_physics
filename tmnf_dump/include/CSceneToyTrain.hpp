#ifndef CSCENETOYTRAIN_HPP
#define CSCENETOYTRAIN_HPP

#include "typedefs.h"

struct CSceneToyTrain {
    void** vftable; // accesses: 1
    byte _final_padding[0xf8]; // Total size: 0xfc

    // Member Functions
    void __thiscall CheckContacts(CSceneToyTrain *this,CSceneToyTrain *param_1);
    void __thiscall UpdateFromDynamicState (CSceneToyTrain *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3, ulong param_4);
};

#endif // CSCENETOYTRAIN_HPP
