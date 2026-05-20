#ifndef CPLUGSOLID_HPP
#define CPLUGSOLID_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CMwNod;
struct CPlugTree;
struct GmVec3;

struct CPlugSolid {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 5
    int field_0x8; // accesses: 15
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 11
    byte _padding_0x1c[4];
    int field_0x20; // accesses: 1
    int field_0x24; // accesses: 1
    int field_0x28; // accesses: 1
    byte _padding_0x2c[8];
    float field_0x34; // accesses: 1
    float field_0x38; // accesses: 1
    float field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 3
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    byte _padding_0x4c[8];
    CClassicArchive * field_0x54; // accesses: 1
    CClassicArchive * field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 6
    undefined4 field_0x60; // accesses: 5
    undefined4 field_0x64; // accesses: 43
    undefined4 field_0x68; // accesses: 27
    undefined4 field_0x6c; // accesses: 6
    undefined4 field_0x70; // accesses: 10

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateDefaultData(CPlugSolid *this,CCrystal *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ExclusionEllipsoidRadiusCompute(CPlugSolid *this,CPlugSolid *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CPlugSolid *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCPlugSolid(void);
    CPlugSolid * __cdecl LoadFromFidForBeingUseAsAModel(CSystemFid *param_1,int param_2);
    CPlugSolid * __thiscall CreateModelInstance(CPlugSolid *this,CPlugSolid *param_1);
    CPlugTree * __thiscall GetPlugFromId(CPlugSolid *this,CPlugSolid *param_1,CMwId *param_2);
    int __thiscall ExclusionEllipsoidRadiusIsCulled (CPlugSolid *this,CPlugSolid *param_1,GmFrustum *param_2,GmIso4 *param_3);
    int __thiscall MwIsKindOf(CPlugSolid *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall OnCrashDump(CPlugSolid *this,CMwNod *param_1,CFastString *param_2);
    ulong __thiscall GetChunkInfo(CPlugSolid *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CPlugSolid *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CPlugSolid *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Get (CPlugSolid *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set(CPlugSolid *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_(CPlugSolid *this,CPfmHeap *param_1,uint param_2);
    void __cdecl AddTree(CPlugTree *param_1);
    void __thiscall ApplyFidParameters (CPlugSolid *this,CPlugFontBitmap *param_1,CSystemFidParameters *param_2, CSystemFidParameters *param_3,CFastBuffer<struct_CMwNod::SManuallyLoadedFid> *param_4);
    void __thiscall CPlugSolid(CPlugSolid *this,CPlugSolid *param_1);
    void __thiscall Chunk(CPlugSolid *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall DisconnectFromModel(CPlugSolid *this,CPlugSolid *param_1,int param_2);
    void __thiscall GivePlugId(CPlugSolid *this,CPlugSolid *param_1,CMwId *param_2);
    void __thiscall InternalConnectSubTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2);
    void __thiscall InternalDisconnectSubTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2);
    void __thiscall MakeTreeIdsUnique(CPlugSolid *this,CPlugSolid *param_1);
    void __thiscall OnNodLoaded(CPlugSolid *this,CDx9DeviceCaps *param_1);
    void __thiscall SetModel(CPlugSolid *this,CPlugSolid *param_1,CPlugSolid *param_2);
    void __thiscall SetTree(CPlugSolid *this,CPlugSolid *param_1,CPlugTree *param_2,int param_3);
    void __thiscall SetUseModel(CPlugSolid *this,CPlugSolid *param_1,int param_2);
    void __thiscall ~CPlugSolid(CPlugSolid *this,CPlugSolid *param_1);
};

#endif // CPLUGSOLID_HPP
