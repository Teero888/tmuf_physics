#ifndef CPLUGSOUND_HPP
#define CPLUGSOUND_HPP

#include "typedefs.h"

struct CPlugSound {
    void** vftable; // accesses: 1
    byte _padding_0x4[20];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1

    // Member Functions
    void __thiscall CPlugSound(CPlugSound *this,CPlugSound *param_1);
};

#endif // CPLUGSOUND_HPP
