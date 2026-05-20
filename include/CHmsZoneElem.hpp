#ifndef CHMSZONEELEM_HPP
#define CHMSZONEELEM_HPP

#include "typedefs.h"

struct CHmsZoneElem {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1);
    void __thiscall ~CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1);
};

#endif // CHMSZONEELEM_HPP
