#ifndef CSCENEOBJECT_HPP
#define CSCENEOBJECT_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CFuncSegment;
struct CHmsItem;
struct CMotions;
struct CMwNod;
struct CSceneMobil;
struct CSceneObjectLink;

struct CSceneObject {
    void** vftable; // accesses: 18
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 5
    byte _padding_0x18[4];
    undefined4 field_0x1c; // accesses: 1
    CClassicArchive * field_0x20; // accesses: 28
    undefined4 field_0x24; // accesses: 5
    byte _padding_0x28[16];
    CHmsItem * field_0x38; // accesses: 1

    // Member Functions
    CMotion * __thiscall SetMotion(CSceneObject *this,CSceneObject *param_1,CMwNod *param_2,int param_3);
    SSceneLoc __thiscall SceneLocGet(CSceneObject *this,CSceneObject *param_1);
    ulong __thiscall GetChunkInfo(CSceneObject *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Add (CSceneObject *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Get (CSceneObject *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set (CSceneObject *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Sub (CSceneObject *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    void __thiscall CSceneObject(CSceneObject *this,CSceneObject *param_1);
    void __thiscall Chunk(CSceneObject *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall OnEnterScene(CSceneObject *this,CSceneToyBroomstick *param_1);
    void __thiscall OnLeaveScene(CSceneObject *this,CSceneToyRock *param_1);
    void __thiscall OnNodLoaded(CSceneObject *this,CDx9DeviceCaps *param_1);
    void __thiscall RemoveFromScene(CSceneObject *this,CSceneObject *param_1);
    void __thiscall RemoveMotion(CSceneObject *this,CSceneObject *param_1,CMotion *param_2);
    void __thiscall ~CSceneObject(CSceneObject *this,CSceneObject *param_1);
};

#endif // CSCENEOBJECT_HPP
