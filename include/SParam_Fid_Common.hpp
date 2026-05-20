#ifndef SPARAM_FID_COMMON_HPP
#define SPARAM_FID_COMMON_HPP

#include "typedefs.h"

struct CSystemPackDesc;
struct ulong;

struct SParam_Fid_Common {
    void** vftable; // accesses: 1
    byte _padding_0x4[12];
    ulong field_0x10; // accesses: 1
    CSystemPackDesc * field_0x14; // accesses: 1
    byte _padding_0x18[8];
    undefined4 field_0x20; // accesses: 1
};

#endif // SPARAM_FID_COMMON_HPP
