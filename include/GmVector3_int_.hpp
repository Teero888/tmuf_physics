#ifndef GMVECTOR3_INT__HPP
#define GMVECTOR3_INT__HPP

#include "typedefs.h"

struct GmVector3<int> {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    int field_0x8; // accesses: 2

    // Member Functions
    void __thiscall Clamp (void *this,GmVector3<int> *param_1,GmVector3<int> *param_2,GmVector3<int> *param_3);
};

#endif // GMVECTOR3_INT__HPP
