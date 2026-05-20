#ifndef SPARAM_FIDS_HPP
#define SPARAM_FIDS_HPP

#include "typedefs.h"

struct CSystemFids;
struct SParam;

struct SParam_Fids {
    void** vftable; // accesses: 3
    SParam * field_0x4; // accesses: 3
    byte _padding_0x8[8];
    int field_0x10; // accesses: 2
    int field_0x14; // accesses: 2
    int * field_0x18; // accesses: 4
    int * field_0x1c; // accesses: 3
    byte _padding_0x20[4];
    CSystemFids * field_0x24; // accesses: 3
};

#endif // SPARAM_FIDS_HPP
