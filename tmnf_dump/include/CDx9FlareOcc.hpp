#ifndef CDX9FLAREOCC_HPP
#define CDX9FLAREOCC_HPP

#include "typedefs.h"

struct CDx9FlareOcc {
    void** vftable;
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1

    // Member Functions
    void __thiscall CDx9FlareOcc(void *this,CDx9FlareOcc *param_1);
};

#endif // CDX9FLAREOCC_HPP
