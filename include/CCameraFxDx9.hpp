#ifndef CCAMERAFXDX9_HPP
#define CCAMERAFXDX9_HPP

#include "typedefs.h"

struct CVisionViewportDx9;

struct CCameraFxDx9 {
    byte _padding_0x0[20];
    CVisionViewportDx9 * field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 2
};

#endif // CCAMERAFXDX9_HPP
