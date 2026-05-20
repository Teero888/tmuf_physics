#ifndef CSCENEVEHICLETUNING_HPP
#define CSCENEVEHICLETUNING_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CFuncKeysReal;
struct CMwNod;

struct CSceneVehicleTuning {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 2
    byte _padding_0x8[16];
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 15

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateDefaultData(CSceneVehicleTuning *this,CCrystal *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicleTuning *this,CFuncSegment *param_1);
    int __thiscall MwIsKindOf(CSceneVehicleTuning *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CSceneVehicleTuning *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneVehicleTuning *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CSceneVehicleTuning *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _vector_deleting_destructor_ (CSceneVehicleTuning *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall Chunk (CSceneVehicleTuning *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ~CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1);
};

#endif // CSCENEVEHICLETUNING_HPP
