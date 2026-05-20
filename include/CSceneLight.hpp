#ifndef CSCENELIGHT_HPP
#define CSCENELIGHT_HPP

#include "typedefs.h"

struct CHmsLight;

struct CSceneLight {
    void** vftable; // accesses: 1
    byte _padding_0x4[44];
    CHmsLight * field_0x30; // accesses: 4
    byte _final_padding[0x4]; // Total size: 0x38

    // Member Functions
    ESceneLight __thiscall GetKindLight(CSceneLight *this,CSceneLight *param_1);
    void __thiscall CSceneLight(CSceneLight *this,CSceneLight *param_1);
    void __thiscall SetLight(CSceneLight *this,CMotionLight *param_1,GxLight *param_2);
    void __thiscall SetLightUpdate(CSceneLight *this,CSceneLight *param_1,ESceneLightUpdate param_2);
};

#endif // CSCENELIGHT_HPP
