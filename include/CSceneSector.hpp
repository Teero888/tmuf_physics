#ifndef CSCENESECTOR_HPP
#define CSCENESECTOR_HPP

#include "typedefs.h"

struct CSceneSector {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneSector(CSceneSector *this,CSceneSector *param_1);
};

#endif // CSCENESECTOR_HPP
