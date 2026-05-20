#ifndef CFUNCSEGMENT_HPP
#define CFUNCSEGMENT_HPP

#include "typedefs.h"

struct CFuncSegment {
    void** vftable; // accesses: 18
    int field_0x4; // accesses: 2
    int field_0x8; // accesses: 19
    byte _padding_0xc[4];
    int field_0x10; // accesses: 4
};

#endif // CFUNCSEGMENT_HPP
