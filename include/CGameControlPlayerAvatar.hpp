#ifndef CGAMECONTROLPLAYERAVATAR_HPP
#define CGAMECONTROLPLAYERAVATAR_HPP

#include "typedefs.h"

struct CControlBase;
struct CGameAvatar;

struct CGameControlPlayerAvatar {
    void** vftable; // accesses: 5
    byte _padding_0x4[44];
    CGameAvatar * field_0x30; // accesses: 2

    // Member Functions
    void __thiscall Display (void *this,CGameControlPlayerAvatar *param_1,CGamePlayerInfo *param_2, EAvatarVariant param_3);
};

#endif // CGAMECONTROLPLAYERAVATAR_HPP
