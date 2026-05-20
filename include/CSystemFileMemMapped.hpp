#ifndef CSYSTEMFILEMEMMAPPED_HPP
#define CSYSTEMFILEMEMMAPPED_HPP

#include "typedefs.h"

struct CSystemFileMemMapped {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 3
    undefined4 field_0x24; // accesses: 3

    // Member Functions
    ulong __thiscall GetActualSize(CSystemFileMemMapped *this,CClassicBufferMemory *param_1);
    void __thiscall Close(CSystemFileMemMapped *this,CClassicLog *param_1);
};

#endif // CSYSTEMFILEMEMMAPPED_HPP
