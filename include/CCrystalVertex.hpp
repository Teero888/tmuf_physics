#ifndef CCRYSTALVERTEX_HPP
#define CCRYSTALVERTEX_HPP

#include "typedefs.h"

struct CCrystalVertex {
    void** vftable;
    byte _padding_0x4[52];
    int field_0x38; // accesses: 1

    // Member Functions
    int __thiscall IsConnected(CCrystalVertex *this,CCrystalVertex *param_1);
};

#endif // CCRYSTALVERTEX_HPP
