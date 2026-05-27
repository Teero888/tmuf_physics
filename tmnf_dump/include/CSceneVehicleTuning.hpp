#ifndef CSCENEVEHICLETUNING_HPP
#define CSCENEVEHICLETUNING_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CFuncKeysReal;
struct CMwNod;

struct CSceneVehicleTuning {
    void** vftable; // accesses: 2

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicleTuning *this,CFuncSegment *param_1);
    int __thiscall MwIsKindOf(CSceneVehicleTuning *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CSceneVehicleTuning *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneVehicleTuning *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CSceneVehicleTuning *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _vector_deleting_destructor_ (CSceneVehicleTuning *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1);
    void __thiscall Chunk (CSceneVehicleTuning *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall CreateDefaultData(CSceneVehicleTuning *this,CCrystal *param_1);
    void __thiscall ~CSceneVehicleTuning(CSceneVehicleTuning *this,CSceneVehicleTuning *param_1);
};

#endif // CSCENEVEHICLETUNING_HPP
