#ifndef CSCENEVEHICLETUNINGS_HPP
#define CSCENEVEHICLETUNINGS_HPP

#include "typedefs.h"

struct CSceneVehicleTunings {
    void** vftable; // accesses: 2
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    uint field_0x24; // accesses: 3

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CSceneVehicleTunings *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCSceneVehicleTunings(void);
    int __thiscall MwIsKindOf (CSceneVehicleTunings *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CSceneVehicleTunings *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CSceneVehicleTunings *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CSceneVehicleTunings *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall VirtualParam_Add (CSceneVehicleTunings *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Get (CSceneVehicleTunings *this,CPlugBlendShapes *param_1,CMwStack *param_2, CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set (CSceneVehicleTunings *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    ulong __thiscall VirtualParam_Sub (CSceneVehicleTunings *this,CGameCtnDecorationMood *param_1,CMwStack *param_2, void *param_3);
    void * __thiscall _vector_deleting_destructor_ (CSceneVehicleTunings *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CSceneVehicleTunings(CSceneVehicleTunings *this,CSceneVehicleTunings *param_1);
    void __thiscall Chunk (CSceneVehicleTunings *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ~CSceneVehicleTunings (CSceneVehicleTunings *this,CSceneVehicleTunings *param_1);
};

#endif // CSCENEVEHICLETUNINGS_HPP
