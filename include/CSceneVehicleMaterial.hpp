#ifndef CSCENEVEHICLEMATERIAL_HPP
#define CSCENEVEHICLEMATERIAL_HPP

#include "typedefs.h"

struct CSceneVehicleMaterial {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    byte _padding_0x38[4];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _final_padding[0x4]; // Total size: 0x48

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicleMaterial (CSceneVehicleMaterial *this,CSceneVehicleMaterial *param_1);
};

#endif // CSCENEVEHICLEMATERIAL_HPP
