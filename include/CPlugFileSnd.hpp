#ifndef CPLUGFILESND_HPP
#define CPLUGFILESND_HPP

#include "typedefs.h"

struct ushort;

struct CPlugFileSnd {
    byte _padding_0x0[20];
    short field_0x14; // accesses: 1
    byte _padding_0x16[2];
    int field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    ushort field_0x20; // accesses: 2
    byte _padding_0x22[2];
    uint field_0x24; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetLength(CPlugFileSnd *this,CPlugFileSnd *param_1);
    ulong __thiscall GetNbBlocks(CPlugFileSnd *this,CPlugFileSnd *param_1);
};

#endif // CPLUGFILESND_HPP
