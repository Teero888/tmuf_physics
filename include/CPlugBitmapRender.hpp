#ifndef CPLUGBITMAPRENDER_HPP
#define CPLUGBITMAPRENDER_HPP

#include "typedefs.h"

struct CPlugTree;

struct CPlugBitmapRender {
    byte _padding_0x0[20];
    uint field_0x14; // accesses: 1
    byte _padding_0x18[232];
    undefined4 field_0x100; // accesses: 2
    CPlugTree * field_0x104; // accesses: 4
};

#endif // CPLUGBITMAPRENDER_HPP
