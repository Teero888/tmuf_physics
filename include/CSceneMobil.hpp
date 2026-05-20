#ifndef CSCENEMOBIL_HPP
#define CSCENEMOBIL_HPP

#include "typedefs.h"

struct CHmsItem;
struct CHmsZone;
struct CMotions;
struct CMwNod;
struct CPlugSolid;
struct CSceneMessageHandler;
struct CSceneObject;
struct CSceneToyBroomstick;

struct CSceneMobil {
    void** vftable; // accesses: 19
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 11
    byte _padding_0x18[8];
    int * field_0x20; // accesses: 13
    byte _padding_0x24[4];
    CHmsItem * field_0x28; // accesses: 56
    CMwNod * field_0x2c; // accesses: 8
    int * field_0x30; // accesses: 26
    int * field_0x34; // accesses: 13
    byte _padding_0x38[12];
    CMwNod * field_0x44; // accesses: 13

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Set (CSceneMobil *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall AddSolidMotionFromTree(CSceneMobil *this,CSceneMobil *param_1);
    CMotion * __thiscall SetMotion(CSceneMobil *this,CSceneObject *param_1,CMwNod *param_2,int param_3);
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneMobil *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCSceneMobil(void);
    CPlugSolid * __thiscall CreateModelInstance(CSceneMobil *this,CPlugSolid *param_1);
    CPlugTree * __thiscall AddVisual (CSceneMobil *this,CSceneMobil *param_1,CPlugVisual *param_2,CPlugShader *param_3, CPlugMaterial *param_4);
    CPlugTree * __thiscall FindOrAddNewTreeWithId(CSceneMobil *this,CSceneMobil *param_1,CMwId *param_2);
    CPlugTree * __thiscall GetTree(CSceneMobil *this,SVolatileTreePointer *param_1);
    CSceneMobil * __thiscall GetModel(CSceneMobil *this,CSceneMobil *param_1);
    CSceneSector * __thiscall GetSector(CSceneMobil *this,CScenePoc *param_1);
    GmIso4 * __thiscall GetInterpolatedLocation(CSceneMobil *this,CSceneObject *param_1,CSceneSector *param_2);
    int __thiscall DoesMotionChangeLocations(CSceneMobil *this,CSceneMobil *param_1);
    int __thiscall GetIsVisible(CSceneMobil *this,CControlBase *param_1);
    int __thiscall IsZombie(CSceneMobil *this,CSceneMobil *param_1);
    int __thiscall MwIsKindOf(CSceneMobil *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CSceneMobil *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneMobil *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CSceneMobil *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall LinkAdd(CSceneMobil *this,CSceneMobil *param_1,CSceneObjectLink *param_2);
    ulong __thiscall LinkFind(CSceneMobil *this,CSceneMobil *param_1,CSceneObjectLink *param_2);
    ulong __thiscall LinkFindFromObjectId(CSceneMobil *this,CSceneMobil *param_1,CMwId *param_2);
    ulong __thiscall VirtualParam_Add (CSceneMobil *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Get (CSceneMobil *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Sub (CSceneMobil *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CSceneMobil *this,CPfmHeap *param_1,uint param_2);
    void __cdecl AddTree(CPlugTree *param_1);
    void __cdecl DoMobilPtr(CSceneMobil **param_1,CClassicArchive *param_2,EDoMobilPtrVersion param_3);
    void __thiscall AbsorbContact (CSceneMobil *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2, CHmsPhysicalContact *param_3);
    void __thiscall AddMotionSolid(CSceneMobil *this,CSceneMobil *param_1,CMotion *param_2);
    void __thiscall AddObject (CSceneMobil *this,CSceneMobil *param_1,CSceneObject *param_2,CSceneObjectLink **param_3);
    void __thiscall ArchiveOwnDataOld(CSceneMobil *this,CSceneToyTrain *param_1,CClassicArchive *param_2);
    void __thiscall CSceneMobil(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall Chunk(CSceneMobil *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CopyLinksFromMobil(CSceneMobil *this,CSceneMobil *param_1,CSceneMobil *param_2);
    void __thiscall CreateDefaultData(CSceneMobil *this,CCrystal *param_1);
    void __thiscall DisconnectFromModel(CSceneMobil *this,CPlugSolid *param_1,int param_2);
    void __thiscall EnableAbsorbContactCallback(CSceneMobil *this,CSceneMobil *param_1,int param_2);
    void __thiscall GetEdBoundingBox(CSceneMobil *this,CSceneSoundSource *param_1,GmBoxAligned *param_2);
    void __thiscall GetLocation(CSceneMobil *this,GmLocFreeVal *param_1,GmIso4 *param_2);
    void __thiscall GetNodsNotToDuplicate (CSceneMobil *this,CSceneMobil *param_1,CFastBuffer<class_CMwNod*> *param_2);
    void __thiscall GetTranslation (CSceneMobil *this,CSceneMobil *param_1,GmVec3 *param_2,CSceneSector *param_3);
    void __thiscall Hide(CSceneMobil *this,CSceneToyMotorbike *param_1);
    void __thiscall InstallRenderBeforeMechanism(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall LinkRemove(CSceneMobil *this,CSceneMobil *param_1,ulong param_2);
    void __thiscall MoveOneCorpusOf (CSceneMobil *this,CSceneMobil *param_1,CHmsCorpus *param_2,float param_3,float param_4, float param_5,GmIso4 *param_6);
    void __thiscall OnEnterScene(CSceneMobil *this,CSceneToyBroomstick *param_1);
    void __thiscall OnEnterSector (CSceneMobil *this,CSceneLocation *param_1,CSceneSector *param_2,GmIso4 *param_3);
    void __thiscall OnLeaveScene(CSceneMobil *this,CSceneToyRock *param_1);
    void __thiscall OnLeaveSector(CSceneMobil *this,CSceneLocation *param_1,CSceneSector *param_2);
    void __thiscall OnRenderBefore (CSceneMobil *this,CMotionTrack *param_1,CHmsCamera *param_2,int *param_3);
    void __thiscall OnStillDrag(CSceneMobil *this,CSceneMobil *param_1,CSceneInfoDrag *param_2);
    void __thiscall OnStillFocus (CSceneMobil *this,CSceneMessageHandler *param_1,CSceneMobil *param_2, CSceneInfoFocus *param_3,CSceneInfoFocus *param_4);
    void __thiscall OnVisibleGained(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall OnVisibleLost(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall ParseTreeLight(CSceneMobil *this,CSceneMobil *param_1,CPlugTree *param_2,int param_3);
    void __thiscall ParseTreeLightInternal (CSceneMobil *this,CSceneMobil *param_1,CPlugTree *param_2,int param_3, SParseTreeLight *param_4);
    void __thiscall RotateOneCorpusOf (CSceneMobil *this,CSceneMobil *param_1,CHmsCorpus *param_2,float param_3,float param_4, float param_5,GmIso4 *param_6,GmVec3 *param_7);
    void __thiscall SetIsVisible(CSceneMobil *this,CPlugTree *param_1,int param_2);
    void __thiscall SetLocation(CSceneMobil *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetMessageHandler(CSceneMobil *this,CSceneMobil *param_1,CSceneMessageHandler *param_2);
    void __thiscall SetModel(CSceneMobil *this,CPlugSolid *param_1,CPlugSolid *param_2);
    void __thiscall SetSolid(CSceneMobil *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2);
    void __thiscall SetTranslation(CSceneMobil *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall SetTree(CSceneMobil *this,CPlugSolid *param_1,CPlugTree *param_2,int param_3);
    void __thiscall SetVisual(CSceneMobil *this,CVisionVisualKeeper *param_1,CPlugVisual *param_2);
    void __thiscall SetZombie(CSceneMobil *this,CSceneMobil *param_1,int param_2);
    void __thiscall Show(CSceneMobil *this,CSceneToyMotorbike *param_1);
    void __thiscall SolidObjectsAdd(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall SolidObjectsRefresh(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall SolidObjectsRemove(CSceneMobil *this,CSceneMobil *param_1);
    void __thiscall VehicleBlockSpeed2Set(CSceneMobil *this,CSceneMobil *param_1,int param_2);
    void __thiscall ~CSceneMobil(CSceneMobil *this,CSceneMobil *param_1);
};

#endif // CSCENEMOBIL_HPP
