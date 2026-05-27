#ifndef CZONENODE_HPP
#define CZONENODE_HPP

#include "typedefs.h"

struct CZoneNode {
    void** vftable;
    byte _padding_0x4[4];
    int field_0x8; // accesses: 1

    // Member Functions
    ulong __thiscall GetHeightStep(void *this,CZoneNode *param_1);
};

#endif // CZONENODE_HPP
