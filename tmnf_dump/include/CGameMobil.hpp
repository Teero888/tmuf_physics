#ifndef CGAMEMOBIL_HPP
#define CGAMEMOBIL_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameMobil {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    CMwNod * field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 2
    undefined * field_0x28; // accesses: 3
    CMwNod * field_0x2c; // accesses: 3
    undefined4 field_0x30; // accesses: 1
    byte _final_padding[0x4]; // Total size: 0x38

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CGameMobil *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCGameMobil(void);
    int __thiscall MwIsKindOf(CGameMobil *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CGameMobil *this,CControlStyle *param_1);
    void * __thiscall _scalar_deleting_destructor_(CGameMobil *this,CPfmHeap *param_1,uint param_2);
    void __thiscall CGameMobil(CGameMobil *this,CGameMobil *param_1);
    void __thiscall ~CGameMobil(CGameMobil *this,CGameMobil *param_1);
};

#endif // CGAMEMOBIL_HPP
