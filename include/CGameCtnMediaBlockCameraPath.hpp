#ifndef CGAMECTNMEDIABLOCKCAMERAPATH_HPP
#define CGAMECTNMEDIABLOCKCAMERAPATH_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockCameraPath {
    void** vftable;
    byte _final_padding[0x50]; // Total size: 0x54

    // Member Functions
    GmVec3 __thiscall GetValue (CGameCtnMediaBlockCameraPath *this,CFuncColorGradient *param_1,float param_2);
};

#endif // CGAMECTNMEDIABLOCKCAMERAPATH_HPP
