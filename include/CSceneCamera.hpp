#ifndef CSCENECAMERA_HPP
#define CSCENECAMERA_HPP

#include "typedefs.h"

struct CHmsCamera;
struct GmFrustum;

struct CSceneCamera {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    byte _padding_0x18[24];
    int field_0x30; // accesses: 4
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    GmFrustum * field_0x3c; // accesses: 2
    float field_0x40; // accesses: 2

    // Member Functions
    void __thiscall GetCamVal(CSceneCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2);
    void __thiscall SetCamVal (CSceneCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4);
    void __thiscall SetSceneProperties(CSceneCamera *this,CSceneCamera *param_1);
};

#endif // CSCENECAMERA_HPP
