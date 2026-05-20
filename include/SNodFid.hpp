#ifndef SNODFID_HPP
#define SNODFID_HPP

#include "typedefs.h"

struct SNodFid {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1

    // Member Functions
    void __thiscall SetNoDuplicate(void *this,SNodFid *param_1,CMwNod *param_2);
};

#endif // SNODFID_HPP
