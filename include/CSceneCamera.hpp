#ifndef CSCENECAMERA_HPP
#define CSCENECAMERA_HPP

#include "typedefs.h"

struct CHmsCamera;

struct CSceneCamera {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 1
    byte _padding_0x18[24];
    int field_0x30; // accesses: 3
    byte _padding_0x34[4];
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[260];
    CHmsCamera * field_0x148; // accesses: 1
    undefined4 field_0x14c; // accesses: 1
    undefined4 field_0x150; // accesses: 1
    undefined4 field_0x154; // accesses: 1
    byte _padding_0x158[184];
    int field_0x210; // accesses: 1

    // Member Functions
    void __thiscall GetCamVal(CSceneCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2);
    void __thiscall SetCamVal (CSceneCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4);
    void __thiscall SetSceneProperties(CSceneCamera *this,CSceneCamera *param_1);
};

#endif // CSCENECAMERA_HPP
