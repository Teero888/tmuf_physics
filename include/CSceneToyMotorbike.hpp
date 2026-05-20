#ifndef CSCENETOYMOTORBIKE_HPP
#define CSCENETOYMOTORBIKE_HPP

#include "typedefs.h"

struct CHmsItem;

struct CSceneToyMotorbike {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    CHmsItem * field_0x14; // accesses: 3

    // Member Functions
    void __thiscall UpdateFromDynamicState (CSceneToyMotorbike *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2, ulong param_3,ulong param_4);
};

#endif // CSCENETOYMOTORBIKE_HPP
