#ifndef CMWNOD_HPP
#define CMWNOD_HPP

#include "typedefs.h"

struct CMwEngineInfo;
struct CMwParam;

struct CMwNod {
    byte _padding_0x0[4];
    CMwNod * field_0x4; // accesses: 18
    CMwParam * field_0x8; // accesses: 12
    int field_0xc; // accesses: 19
    int field_0x10; // accesses: 18
    int field_0x14; // accesses: 5
    CMwEngineInfo * field_0x18; // accesses: 21
    code * field_0x1c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall Param_Check(CMwNod *this,CMwNod *param_1,CMwStack *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ ulong __thiscall VirtualParam_Get (CMwNod *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl StaticInit(void);
    CMwClassInfo * __cdecl StaticGetClassInfo(ulong param_1);
    CMwNod * __cdecl CreateByMwClassId(ulong param_1);
    int __cdecl StaticMwIsKindOf(ulong param_1,ulong param_2);
    int __thiscall OnCrashDump(CMwNod *this,CMwNod *param_1,CFastString *param_2);
    ulong __thiscall GetChunkInfo(CMwNod *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall MwAddRef(CMwNod *this,CMwNod *param_1);
    ulong __thiscall MwForceRef(CMwNod *this,CMwNod *param_1,ulong param_2);
    ulong __thiscall MwGetNearestFather(CMwNod *this,CMwClassInfo *param_1,ulong param_2,ulong *param_3);
    ulong __thiscall MwRelease(CMwNod *this,CMwNod *param_1);
    ulong __thiscall Param_Add(CMwNod *this,CMwNod *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall Param_Get(CMwNod *this,CMwNod *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall Param_Set(CMwNod *this,CMwNod *param_1,CFastString *param_2,CFastStringInt *param_3);
    ulong __thiscall Param_Sub(CMwNod *this,CMwNod *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Add(CMwNod *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Set(CMwNod *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Sub (CMwNod *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3);
    void __thiscall AddClass(CMwNod *this,CMwEngineInfo *param_1,CMwClassInfo *param_2);
    void __thiscall CMwNod(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall Chunk(CMwNod *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall DependantSendMwIsKilled(CMwNod *this,CMwNod *param_1);
    void __thiscall MwAddDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall MwAddReceiver(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall MwFinalSubDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall MwIsUnreferenced(CMwNod *this,CVisionViewportDx9 *param_1,CMwNod *param_2);
    void __thiscall MwSendMessage(CMwNod *this,CMwNod *param_1,ulong param_2,ulong *param_3);
    void __thiscall MwSubDependant(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall MwSubDependantSafe(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall MwSubReceiver(CMwNod *this,CMwNod *param_1,CMwNod *param_2);
    void __thiscall ~CMwNod(CMwNod *this,CMwNod *param_1);
};

#endif // CMWNOD_HPP
