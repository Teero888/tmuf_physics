#ifndef CGAMECTNGHOST_HPP
#define CGAMECTNGHOST_HPP

#include "typedefs.h"

struct SStringParam;

struct CGameCtnGhost {
    byte _padding_0x0[4];
    SStringParam * field_0x4; // accesses: 1
    byte _padding_0x8[224];
    CGameCtnGhost * field_0xe8; // accesses: 1
    ulong field_0xec; // accesses: 1
    ulong field_0xf0; // accesses: 1
    byte _padding_0xf4[12];
    EReplayGhostVersion field_0x100; // accesses: 2

    // Member Functions
    int __thiscall CanValidate (CGameCtnGhost *this,CGameCtnGhost *param_1,CGameApp *param_2,CFastStringInt *param_3);
    int __thiscall IsSameSystem(CGameCtnGhost *this,CGameCtnGhost *param_1,CFastStringInt *param_2);
    void __thiscall SetContextSettings(CGameCtnGhost *this,CGameCtnGhost *param_1,CFastString *param_2);
    void __thiscall SetRaceTime (CGameCtnGhost *this,CGameCtnGhost *param_1,ulong param_2,ulong param_3,ulong param_4);
};

#endif // CGAMECTNGHOST_HPP
