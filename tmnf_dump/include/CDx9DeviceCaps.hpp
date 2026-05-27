#ifndef CDX9DEVICECAPS_HPP
#define CDX9DEVICECAPS_HPP

#include "typedefs.h"

struct SStringParam;

struct CDx9DeviceCaps {
    void** vftable;
    byte _padding_0x4[1072];
    char * field_0x434; // accesses: 2
    SStringParam * field_0x438; // accesses: 3
    ulong field_0x43c; // accesses: 2
    undefined4 field_0x440; // accesses: 1
    byte _padding_0x444[28];
    int field_0x460; // accesses: 3
    byte _final_padding[0x304]; // Total size: 0x768

    // Member Functions
    void __thiscall BeforeCreateDevice (CDx9DeviceCaps *this,CDx9DeviceCaps *param_1,IDirect3D9 *param_2,ulong param_3, _D3DDEVTYPE param_4);
};

#endif // CDX9DEVICECAPS_HPP
