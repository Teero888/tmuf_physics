#ifndef CHMSAMBIENTOCC_HPP
#define CHMSAMBIENTOCC_HPP

#include "typedefs.h"

struct CHmsAmbientOcc {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1

    // Member Functions
    void __thiscall CHmsAmbientOcc(CHmsAmbientOcc *this,CHmsAmbientOcc *param_1);
};

#endif // CHMSAMBIENTOCC_HPP
