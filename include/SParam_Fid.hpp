#ifndef SPARAM_FID_HPP
#define SPARAM_FID_HPP

#include "typedefs.h"

struct CSystemFid;

struct SParam_Fid {
    void** vftable; // accesses: 1
    byte _padding_0x4[32];
    CSystemFid * field_0x24; // accesses: 1
};

#endif // SPARAM_FID_HPP
