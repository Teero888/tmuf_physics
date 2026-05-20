#ifndef CPLUGMUSICTYPE_HPP
#define CPLUGMUSICTYPE_HPP

#include "typedefs.h"

struct CPlugMusicType {
    byte _padding_0x0[28];
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[24];
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[44];
    undefined4 field_0x70; // accesses: 1

    // Member Functions
    void __thiscall CPlugMusicType(CPlugMusicType *this,CPlugMusicType *param_1);
};

#endif // CPLUGMUSICTYPE_HPP
