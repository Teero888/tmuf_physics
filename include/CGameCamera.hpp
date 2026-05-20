#ifndef CGAMECAMERA_HPP
#define CGAMECAMERA_HPP

#include "typedefs.h"

struct CSceneCamera;

struct CGameCamera {
    byte _padding_0x0[68];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 2
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    CSceneCamera * field_0x74; // accesses: 1

    // Member Functions
    void __thiscall SetGameCamVal(CGameCamera *this,CGameCamera *param_1,SGameCamVal *param_2);
};

#endif // CGAMECAMERA_HPP
