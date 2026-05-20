#ifndef CSCENEOBJECTLINK_HPP
#define CSCENEOBJECTLINK_HPP

#include "typedefs.h"

struct CMwNod;
struct CPlugTree;
struct CSceneMobil;
struct CSceneToyBroomstick;

struct CSceneObjectLink {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    uint field_0x14; // accesses: 7
    CSceneObjectLink * field_0x18; // accesses: 5
    CSceneMobil * field_0x1c; // accesses: 4
    CMwNod * field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 1
    byte _padding_0x28[52];
    CSceneToyBroomstick * field_0x5c; // accesses: 5
    CMwNod * field_0x60; // accesses: 8

    // Member Functions
    void __thiscall CSceneObjectLink(CSceneObjectLink *this,CSceneObjectLink *param_1);
    void __thiscall InternalUpdateIsInstalled(CSceneObjectLink *this,CSceneObjectLink *param_1);
    void __thiscall OnEnterScene(CSceneObjectLink *this,CSceneToyBroomstick *param_1);
    void __thiscall OnLeaveScene(CSceneObjectLink *this,CSceneToyRock *param_1);
    void __thiscall SetIsActive(CSceneObjectLink *this,CSceneObjectLink *param_1,int param_2);
    void __thiscall SetMobil(CSceneObjectLink *this,CSceneObjectLink *param_1,CSceneMobil *param_2);
    void __thiscall SetMobilTree(CSceneObjectLink *this,CSceneObjectLink *param_1,CPlugTree *param_2);
    void __thiscall SetObject(CSceneObjectLink *this,CSceneObjectLink *param_1,CSceneObject *param_2);
};

#endif // CSCENEOBJECTLINK_HPP
