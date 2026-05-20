#ifndef CGAMEPLAYER_HPP
#define CGAMEPLAYER_HPP

#include "typedefs.h"

struct CMwNod;

struct CGamePlayer {
    void** vftable; // accesses: 2
    byte _padding_0x4[24];
    undefined4 field_0x1c; // accesses: 4
    CMwNod * field_0x20; // accesses: 3
    CMwNod * field_0x24; // accesses: 11
    CMwNod * field_0x28; // accesses: 4
    byte _padding_0x2c[4];
    undefined4 field_0x30; // accesses: 2
    undefined * field_0x34; // accesses: 3
    byte _padding_0x38[12];
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[492];
    CGamePlayer * field_0x238; // accesses: 1

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CGamePlayer *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCGamePlayer(void);
    int __thiscall IsLocalPlayer(CGamePlayer *this,CGamePlayer *param_1);
    int __thiscall MwIsKindOf(CGamePlayer *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CGamePlayer *this,CControlStyle *param_1);
    void * __thiscall _vector_deleting_destructor_(CGamePlayer *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall CGamePlayer(CGamePlayer *this,CGamePlayer *param_1);
    void __thiscall SetControlPlayer(CGamePlayer *this,CGamePlayer *param_1,CGameControlPlayer *param_2);
    void __thiscall SetName(CGamePlayer *this,CGameBuddy *param_1,CFastStringInt *param_2);
    void __thiscall SetPlayerInfo(CGamePlayer *this,CGamePlayer *param_1,CGamePlayerInfo *param_2);
    void __thiscall UpdatePlayer(CGamePlayer *this,CGamePlayer *param_1,ulong param_2);
    void __thiscall UpdatePlayerAsync(CGamePlayer *this,CGamePlayer *param_1,ulong param_2);
    void __thiscall ~CGamePlayer(CGamePlayer *this,CGamePlayer *param_1);
};

#endif // CGAMEPLAYER_HPP
