#ifndef CGAMECTNMEDIABLOCK3DSTEREO_HPP
#define CGAMECTNMEDIABLOCK3DSTEREO_HPP

#include "typedefs.h"

struct CGameCtnMediaBlock3dStereo {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 2
    float field_0x8; // accesses: 2
    byte _padding_0xc[24];
    int field_0x24; // accesses: 1
    byte _padding_0x28[12];
    float * field_0x34; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ GmVec3 __thiscall GetValue (CGameCtnMediaBlock3dStereo *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCK3DSTEREO_HPP
