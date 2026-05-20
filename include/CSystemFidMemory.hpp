#ifndef CSYSTEMFIDMEMORY_HPP
#define CSYSTEMFIDMEMORY_HPP

#include "typedefs.h"

struct CSystemFidMemory {
    byte _padding_0x0[24];
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[80];
    undefined4 field_0x6c; // accesses: 1
    byte _padding_0x70[4];
    undefined4 * field_0x74; // accesses: 3
    int field_0x78; // accesses: 2

    // Member Functions
    void __thiscall CSystemFidMemory(CSystemFidMemory *this,CSystemFidMemory *param_1);
    void __thiscall ~CSystemFidMemory(CSystemFidMemory *this,CSystemFidMemory *param_1);
};

#endif // CSYSTEMFIDMEMORY_HPP
