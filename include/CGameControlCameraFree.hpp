#ifndef CGAMECONTROLCAMERAFREE_HPP
#define CGAMECONTROLCAMERAFREE_HPP

#include "typedefs.h"

struct CGameControlCameraFree {
    byte _padding_0x0[456];
    CGameControlCameraFree * field_0x1c8; // accesses: 1
    SInputActionDesc * field_0x1cc; // accesses: 1
    SInputActionDesc * field_0x1d0; // accesses: 1
    SInputActionDesc * field_0x1d4; // accesses: 1
    SInputActionDesc * field_0x1d8; // accesses: 1
    SInputActionDesc * field_0x1dc; // accesses: 1
    SInputActionDesc * field_0x1e0; // accesses: 1

    // Member Functions
    void __thiscall SetKeysAction (CGameControlCameraFree *this,CGameControlCameraFree *param_1,SInputActionDesc *param_2, SInputActionDesc *param_3,SInputActionDesc *param_4,SInputActionDesc *param_5, SInputActionDesc *param_6,SInputActionDesc *param_7,SInputActionDesc *param_8);
};

#endif // CGAMECONTROLCAMERAFREE_HPP
