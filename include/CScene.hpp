#ifndef CSCENE_HPP
#define CSCENE_HPP

#include "typedefs.h"

struct CSceneToySea;

struct CScene {
    void** vftable; // accesses: 1
    byte _final_padding[0x2]; // Total size: 0x6

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
