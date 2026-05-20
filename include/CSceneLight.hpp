#ifndef CSCENELIGHT_HPP
#define CSCENELIGHT_HPP

#include "typedefs.h"

struct CHmsLight;

struct CSceneLight {
    byte _padding_0x0[48];
    int field_0x30; // accesses: 4
    byte _padding_0x34[48];
    CSceneLight * field_0x64; // accesses: 1

    // Member Functions
    ESceneLight __thiscall GetKindLight(CSceneLight *this,CSceneLight *param_1);
    void __thiscall CSceneLight(CSceneLight *this,CSceneLight *param_1);
    void __thiscall SetLight(CSceneLight *this,CMotionLight *param_1,GxLight *param_2);
    void __thiscall SetLightUpdate(CSceneLight *this,CSceneLight *param_1,ESceneLightUpdate param_2);
};

#endif // CSCENELIGHT_HPP
