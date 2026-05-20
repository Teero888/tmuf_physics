#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "typedefs.h"

struct CSceneToySea;

struct CScene {
    byte _padding_0x0[24];
    int field_0x18; // accesses: 5
    byte _padding_0x1c[52];
    undefined4 field_0x50; // accesses: 1
    CSceneToySea * field_0x54; // accesses: 2
    byte _padding_0x58[68];
    undefined4 field_0x9c; // accesses: 2

    // Member Functions
    CMotionManager * __thiscall GetManager(CScene *this,CScene *param_1,ulong param_2);
    CMotionManager * __thiscall QueryManager(CScene *this,CScene *param_1,ulong param_2);
    CSceneToySea * __thiscall SeaGet(CScene *this,CScene *param_1,CSceneSector *param_2);
    ulong __thiscall FindManagerFromClassId(CScene *this,CScene *param_1,ulong param_2);
    void __thiscall CScene(CScene *this,CScene *param_1);
    void __thiscall CameraPropertiesUpdate(CScene *this,CScene *param_1);
    void __thiscall ReleaseManager(CScene *this,CScene *param_1,ulong param_2);
    void __thiscall RemoveManagedMotion(CScene *this,CScene *param_1,ulong param_2,CMotion *param_3);
};

#endif // CSCENE_HPP
