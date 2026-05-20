#ifndef CSCENE2D_HPP
#define CSCENE2D_HPP

#include "typedefs.h"

struct CMwNod;

struct CScene2d {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 2
    byte _padding_0x10[144];
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 7
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2
    undefined4 field_0xb0; // accesses: 2
    undefined4 field_0xb4; // accesses: 2
    byte _padding_0xb8[132];
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CScene2d(CScene2d *this,CScene2d *param_1);
    void __cdecl SetVisibleInterface(CScene2d *param_1,int param_2);
    void __thiscall CreateOverlay(CScene2d *this,CScene2d *param_1,GmRectAligned *param_2);
    void __thiscall SetVisible(CScene2d *this,CScene2d *param_1,int param_2);
};

#endif // CSCENE2D_HPP
