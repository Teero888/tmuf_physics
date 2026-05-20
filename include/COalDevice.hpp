#ifndef COALDEVICE_HPP
#define COALDEVICE_HPP

#include "typedefs.h"

struct COalDevice {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined * field_0x20; // accesses: 1
    byte _padding_0x24[8];
    undefined4 field_0x2c; // accesses: 1
    undefined * field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined * field_0x38; // accesses: 1

    // Member Functions
    void __thiscall COalDevice(COalDevice *this,COalDevice *param_1);
};

#endif // COALDEVICE_HPP
