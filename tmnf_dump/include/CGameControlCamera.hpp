#ifndef CGAMECONTROLCAMERA_HPP
#define CGAMECONTROLCAMERA_HPP

#include "typedefs.h"

struct CGameControlCamera {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    int field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 2
    byte _padding_0x20[148];
    CGameControlCamera * field_0xb4; // accesses: 4
    byte _final_padding[0x68]; // Total size: 0x120

    // Member Functions
    void __thiscall GetGameCamVal (CGameControlCamera *this,CGameControlCamera *param_1,SGameCamVal *param_2);
    void __thiscall SetFollowedGameMobilId (CGameControlCamera *this,CGameControlCamera *param_1,ulong param_2);
};

#endif // CGAMECONTROLCAMERA_HPP
