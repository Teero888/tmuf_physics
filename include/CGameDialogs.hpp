#ifndef CGAMEDIALOGS_HPP
#define CGAMEDIALOGS_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameDialogs {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 4
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    byte _padding_0x2c[16];
    int field_0x3c; // accesses: 1
    CMwNod * field_0x40; // accesses: 1
    _func___cdecl_void * field_0x44; // accesses: 1
    byte _padding_0x48[40];
    int field_0x70; // accesses: 3
    int * field_0x74; // accesses: 2
    byte _padding_0x78[56];
    int field_0xb0; // accesses: 1
    byte _padding_0xb4[88];
    undefined4 field_0x10c; // accesses: 2

    // Member Functions
    void __cdecl AdjustQuadBgSize(CControlFrame *param_1,int param_2);
    void __thiscall DoMessage (CGameDialogs *this,CGameDialogs *param_1,CFastStringInt *param_2,CFastStringInt *param_3, CMwNod *param_4,_func___cdecl_void *param_5);
    void __thiscall HideDialogs(CGameDialogs *this,CGameCtnMenus *param_1);
};

#endif // CGAMEDIALOGS_HPP
