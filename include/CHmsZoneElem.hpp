#ifndef CHMSZONEELEM_HPP
#define CHMSZONEELEM_HPP

#include "typedefs.h"

struct CHmsZoneElem {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    void __thiscall CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1);
    void __thiscall ~CHmsZoneElem(CHmsZoneElem *this,CHmsZoneElem *param_1);
};

#endif // CHMSZONEELEM_HPP
