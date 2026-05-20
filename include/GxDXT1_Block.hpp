#ifndef GXDXT1_BLOCK_HPP
#define GXDXT1_BLOCK_HPP

#include "typedefs.h"

struct ulong;
struct ushort;

struct GxDXT1_Block {
    void** vftable; // accesses: 4
    ushort field_0x2; // accesses: 1

    // Member Functions
    GxDXT1_Block * __thiscall GetTexel(void *this,GxDXT1_Block *param_1,ulong param_2,ulong param_3);
};

#endif // GXDXT1_BLOCK_HPP
