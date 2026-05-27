#ifndef CSCENE2D_HPP
#define CSCENE2D_HPP

#include "typedefs.h"

struct CMwNod;

struct CScene2d {
    void** vftable; // accesses: 1
    byte _padding_0x4[156];
    undefined4 field_0xa0; // accesses: 2
    CMwNod * field_0xa4; // accesses: 7
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2
    undefined4 field_0xb0; // accesses: 2
    undefined4 field_0xb4; // accesses: 2

    // Member Functions
    void __cdecl SetVisibleInterface(CScene2d *param_1,int param_2);
    void __thiscall CScene2d(CScene2d *this,CScene2d *param_1);
    void __thiscall CreateOverlay(CScene2d *this,CScene2d *param_1,GmRectAligned *param_2);
    void __thiscall SetVisible(CScene2d *this,CScene2d *param_1,int param_2);
};

#endif // CSCENE2D_HPP
