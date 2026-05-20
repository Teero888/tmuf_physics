#ifndef CHMSITEM_HPP
#define CHMSITEM_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CHmsZone;
struct CMwCmdBufferCore;
struct CMwNod;
struct CPlugSolid;
struct CSceneToyMotorbike;
struct GmMat3;

struct CHmsItem {
    struct CCallback {

        // Member Functions
        void __thiscall ~CCallback(CCallback *this,CCallback *param_1);
    };

    struct CCallbackRenderBeforeTree {

        // Member Functions
        void __thiscall ~CCallbackRenderBeforeTree (CCallbackRenderBeforeTree *this,CCallbackRenderBeforeTree *param_1);
    };

    struct SCallbackList {

        // Member Functions
        void __thiscall SCallbackList(void *this,SCallbackList *param_1);
        void __thiscall ~SCallbackList(void *this,SCallbackList *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 56
    GmMat3 * field_0x8; // accesses: 11
    undefined4 field_0xc; // accesses: 6
    int * field_0x10; // accesses: 7
    CPlugSolid * field_0x14; // accesses: 21
    ulong field_0x18; // accesses: 116
    ushort field_0x1c; // accesses: 69
    byte _padding_0x1e[2];
    undefined2 field_0x20; // accesses: 28
    byte _padding_0x22[2];
    int * field_0x24; // accesses: 10
    byte _padding_0x28[4];
    int field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    byte _padding_0x38[8];
    undefined4 field_0x40; // accesses: 2
    undefined4 field_0x44; // accesses: 3
    int field_0x48; // accesses: 4
    int field_0x4c; // accesses: 4
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 3
    int field_0x58; // accesses: 4
    byte _padding_0x5c[64];
    uint field_0x9c; // accesses: 12

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetAsyncBlendBetweenPreviousAndNextStates(CHmsItem *this,CHmsItem *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CHmsItem(CHmsItem *this,CHmsItem *param_1);
    /* WARNING: Type propagation algorithm not settling */ void __thiscall TransformOf(CHmsItem *this,CHmsItem *param_1,GmIso4 *param_2);
    CGameCtnZone * __thiscall GetZone(CHmsItem *this,CGameCtnCollection *param_1,CMwId *param_2);
    CHmsCorpus * __thiscall GetCorpus(CHmsItem *this,CHmsItem *param_1,CHmsZone *param_2);
    CHmsCorpus * __thiscall GetCurrentCorpus(CHmsItem *this,CHmsItem *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsItem *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsItem(void);
    EHmsCorpusCat __thiscall GetCorpusCat(CHmsItem *this,CHmsItem *param_1);
    int __thiscall IsStateDifferentFrom(CHmsItem *this,CHmsItem *param_1,GmIso4 *param_2);
    int __thiscall MwIsKindOf(CHmsItem *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall OnCrashDump(CHmsItem *this,CMwNod *param_1,CFastString *param_2);
    ulong __thiscall GetChunkInfo(CHmsItem *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetCorpusIndex(CHmsItem *this,CHmsItem *param_1,CHmsZone *param_2);
    ulong __thiscall GetMwClassId(CHmsItem *this,CControlStyle *param_1);
    ulong __thiscall GetSaveStateSize (CHmsItem *this,CMwClassInfoCSceneToyBoat *param_1,EMobilStateQuality param_2);
    ulong __thiscall GetUidChunkFromIndex(CHmsItem *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Get (CHmsItem *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set(CHmsItem *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CHmsItem *this,CPfmHeap *param_1,uint param_2);
    void __cdecl CallbackSetRenderBeforeTree(CCallbackRenderBeforeTree *param_1);
    void __cdecl StaticInit(void);
    void __thiscall AddCorpus(CHmsItem *this,SZone *param_1,CHmsCorpus *param_2);
    void __thiscall AddForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall AddImpulse(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall AddStateForPrediction (CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3, ulong param_4);
    void __thiscall AddTorque(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall CallbackSet(CHmsItem *this,CHmsItem *param_1,ECallback param_2,CCallback *param_3);
    void __thiscall Chunk(CHmsItem *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CreateDefaultData(CHmsItem *this,CCrystal *param_1);
    void __thiscall CreatePortal(CHmsItem *this,CHmsItem *param_1,CHmsPortal **param_2,CPlugTree *param_3);
    void __thiscall GetAngularSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetLinearSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall GetLocation(CHmsItem *this,GmLocFreeVal *param_1,GmIso4 *param_2);
    void __thiscall IsVisibleSet(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall OldRestoreStaticState (CHmsItem *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3, uchar param_4,int param_5);
    void __thiscall OnNodLoaded(CHmsItem *this,CDx9DeviceCaps *param_1);
    void __thiscall OnVisible_WakeOrKeepAwake(CHmsItem *this,CHmsItem *param_1);
    void __thiscall PickDisable(CHmsItem *this,CHmsItem *param_1);
    void __thiscall PickEnableAtLevel(CHmsItem *this,CHmsItem *param_1,ulong param_2);
    void __thiscall RemoveCorpus(CHmsItem *this,CHmsZoneOverlay *param_1,CHmsCorpus *param_2);
    void __thiscall RemovePortal(CHmsItem *this,CHmsItem *param_1,CHmsPortal *param_2);
    void __thiscall ResetDynamicState(CHmsItem *this,CHmsItem *param_1);
    void __thiscall RestoreStaticState (CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3, ulong param_4,ulong param_5,int param_6);
    void __thiscall RotateOf(CHmsItem *this,CHmsCorpus *param_1,GmMat3 *param_2);
    void __thiscall SaveState(CHmsItem *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2, ulong *param_3,ulong param_4);
    void __thiscall SetAngularSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetCollisionGroup(CHmsItem *this,CHmsItem *param_1,ECollisionGroup param_2);
    void __thiscall SetContactInterest(CHmsItem *this,CHmsItem *param_1,EContactInterest param_2);
    void __thiscall SetCountShadowTexCasted(CHmsItem *this,CHmsItem *param_1,uchar param_2,int param_3);
    void __thiscall SetDynamicType(CHmsItem *this,CHmsItem *param_1,EDynamicType param_2);
    void __thiscall SetForce(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetIsBackground(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetIsCollisionStatic(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetIsForcePointDynamicCollisionResponse(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetIsKinematicOnly(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetIsVisionStatic(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetIsZombie(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetLightEmitter(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetLightLensFlareEnable(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetLinearSpeed(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall SetLocation(CHmsItem *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetOccluderForLightMap(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetShadowCasterGroupMask(CHmsItem *this,CHmsItem *param_1,ulong param_2);
    void __thiscall SetShadowFakeEnable(CHmsItem *this,CHmsItem *param_1,int param_2);
    void __thiscall SetShadowReceiverGroupMask(CHmsItem *this,CHmsItem *param_1,ulong param_2);
    void __thiscall SetSolid(CHmsItem *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2);
    void __thiscall SetTorque(CHmsItem *this,CHmsItem *param_1,GmVec3 *param_2);
    void __thiscall UpdateCorpusCat(CHmsItem *this,CHmsItem *param_1);
    void __thiscall UpdateIsBuild(CHmsItem *this,CHmsItem *param_1);
    void __thiscall VisibleIdSet(CHmsItem *this,CHmsItem *param_1,SPlugVisibleId *param_2);
    void __thiscall ~CHmsItem(CHmsItem *this,CHmsItem *param_1);
};

#endif // CHMSITEM_HPP
