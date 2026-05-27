#ifndef SPARAMEFFECTMASTER_HPP
#define SPARAMEFFECTMASTER_HPP

#include "typedefs.h"

struct CMwNod;

struct SParamEffectMaster {
    int * field_0x0; // accesses: 5
    CMwNod * field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[24];
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    byte _padding_0x34[12];
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    int * field_0x50; // accesses: 5
    byte _padding_0x54[24];
    undefined4 field_0x6c; // accesses: 1

    // Member Functions
    void __thiscall SParamEffectMaster(void *this,SParamEffectMaster *param_1);
    void __thiscall ~SParamEffectMaster(void *this,SParamEffectMaster *param_1);
};

#endif // SPARAMEFFECTMASTER_HPP
