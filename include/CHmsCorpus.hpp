#ifndef CHMSCORPUS_HPP
#define CHMSCORPUS_HPP

#include "typedefs.h"

struct CHmsZoneElem;

struct CHmsCorpus {
    void** vftable; // accesses: 5
    byte _padding_0x4[56];
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    int * field_0x48; // accesses: 6
    undefined4 field_0x4c; // accesses: 2
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    CHmsZoneElem * field_0x58; // accesses: 20

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CHmsCorpus *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCHmsCorpus(void);
    int __thiscall MwIsKindOf(CHmsCorpus *this,CMwCmdAffectParam *param_1,ulong param_2);
    int __thiscall OnCrashDump(CHmsCorpus *this,CMwNod *param_1,CFastString *param_2);
    int __thiscall WaterGetPlaneEqInZone(CHmsCorpus *this,CHmsCorpus *param_1,GmVec4 *param_2);
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
