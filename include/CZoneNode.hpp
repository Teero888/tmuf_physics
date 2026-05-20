#ifndef CZONENODE_HPP
#define CZONENODE_HPP

#include "typedefs.h"

struct CZoneNode {
    byte _padding_0x0[8];
    int field_0x8; // accesses: 1

    // Member Functions
    ulong __thiscall GetHeightStep(void *this,CZoneNode *param_1);
};

#endif // CZONENODE_HPP
