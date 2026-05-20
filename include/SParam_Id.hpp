#ifndef SPARAM_ID_HPP
#define SPARAM_ID_HPP

#include "typedefs.h"

struct SParam_Id {
    void** vftable; // accesses: 1
    byte _padding_0x4[12];
    int field_0x10; // accesses: 2
    EParamType field_0x14; // accesses: 6
};

#endif // SPARAM_ID_HPP
