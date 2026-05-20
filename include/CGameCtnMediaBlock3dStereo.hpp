#ifndef CGAMECTNMEDIABLOCK3DSTEREO_HPP
#define CGAMECTNMEDIABLOCK3DSTEREO_HPP

#include "typedefs.h"

struct CGameCtnMediaBlock3dStereo {
    void** vftable;
    byte _padding_0x4[32];
    int field_0x24; // accesses: 1
    byte _padding_0x28[12];
    float * field_0x34; // accesses: 1

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlock3dStereo *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCK3DSTEREO_HPP
