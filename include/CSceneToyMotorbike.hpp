#ifndef CSCENETOYMOTORBIKE_HPP
#define CSCENETOYMOTORBIKE_HPP

#include "typedefs.h"

struct CSceneToyMotorbike {
    void** vftable; // accesses: 1
    byte _final_padding[0x53c]; // Total size: 0x540

    // Member Functions
    void __thiscall UpdateFromDynamicState (CSceneToyMotorbike *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2, ulong param_3,ulong param_4);
};

#endif // CSCENETOYMOTORBIKE_HPP
