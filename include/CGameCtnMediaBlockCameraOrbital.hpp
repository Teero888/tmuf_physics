#ifndef CGAMECTNMEDIABLOCKCAMERAORBITAL_HPP
#define CGAMECTNMEDIABLOCKCAMERAORBITAL_HPP

#include "typedefs.h"

struct CGameCtnMediaBlockCameraOrbital {
    void** vftable;
    byte _final_padding[0x64]; // Total size: 0x68

    // Member Functions
    CFastBufferKeyBase * __thiscall GetFastBufferKey (CGameCtnMediaBlockCameraOrbital *this,CGameCtnMediaBlockFxBlurDepth *param_1);
};

#endif // CGAMECTNMEDIABLOCKCAMERAORBITAL_HPP
