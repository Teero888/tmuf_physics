#ifndef CHMSCORPUS_HPP
#define CHMSCORPUS_HPP

#include "typedefs.h"

struct CHmsZoneElem;

struct CHmsCorpus {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[8];
    code * field_0x14; // accesses: 1
    code * field_0x18; // accesses: 3
    code * field_0x1c; // accesses: 1
    uint field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[16];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    int field_0x48; // accesses: 6
    undefined4 field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    int field_0x58; // accesses: 20
    byte _padding_0x5c[716];
    int field_0x328; // accesses: 1
    int field_0x32c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall WaterGetPlaneEqInZone(CHmsCorpus *this,CHmsCorpus *param_1,GmVec4 *param_2);
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsCorpus *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsCorpus(void);
    int __thiscall MwIsKindOf(CHmsCorpus *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall OnCrashDump(CHmsCorpus *this,CMwNod *param_1,CFastString *param_2);
    ulong __thiscall GetMwClassId(CHmsCorpus *this,CControlStyle *param_1);
    void * __thiscall _vector_deleting_destructor_(CHmsCorpus *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CHmsCorpus(CHmsCorpus *this,CHmsCorpus *param_1);
    void __thiscall ComputeCurrentState(CHmsCorpus *this,CHmsCorpus *param_1,float param_2);
    void __thiscall GetLocation(CHmsCorpus *this,GmLocFreeVal *param_1,GmIso4 *param_2);
    void __thiscall OldRestoreStaticState (CHmsCorpus *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3, uchar param_4,int param_5);
    void __thiscall RefreshFromSolid(CHmsCorpus *this,CHmsCorpus *param_1);
    void __thiscall Reset(CHmsCorpus *this,GmFrustumIso4 *param_1);
    void __thiscall RestoreStaticState (CHmsCorpus *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3, ulong param_4,ulong param_5,int param_6);
    void __thiscall RotateOf(CHmsCorpus *this,CHmsCorpus *param_1,GmMat3 *param_2);
    void __thiscall SetItem(CHmsCorpus *this,CHmsCorpus *param_1,CHmsItem *param_2);
    void __thiscall SetLocation(CHmsCorpus *this,CPlugTree *param_1,GmIso4 *param_2);
    void __thiscall SetTranslation(CHmsCorpus *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall ~CHmsCorpus(CHmsCorpus *this,CHmsCorpus *param_1);
};

#endif // CHMSCORPUS_HPP
