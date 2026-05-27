#ifndef CSCENECAMERA_HPP
#define CSCENECAMERA_HPP

#include "typedefs.h"

struct CHmsCamera;

struct CSceneCamera {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    int field_0x14; // accesses: 1
    byte _padding_0x18[24];
    CHmsCamera * field_0x30; // accesses: 3
    byte _final_padding[0x1c]; // Total size: 0x50

    // Member Functions
    void __thiscall GetCamVal(CSceneCamera *this,GmCamFreeVal *param_1,GmCamVal *param_2);
    void __thiscall SetCamVal (CSceneCamera *this,CSceneCamera *param_1,GmCamVal *param_2,GmVec3 *param_3,int param_4);
    void __thiscall SetSceneProperties(CSceneCamera *this,CSceneCamera *param_1);
};

#endif // CSCENECAMERA_HPP
