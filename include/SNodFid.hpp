#ifndef SNODFID_HPP
#define SNODFID_HPP

#include "typedefs.h"

struct CSystemEngine;

struct SNodFid {
    SNodFid * field_0x0; // accesses: 2
    int field_0x4; // accesses: 1

    // Member Functions
    void __thiscall SetNoDuplicate(void *this,SNodFid *param_1,CMwNod *param_2);
};

#endif // SNODFID_HPP
