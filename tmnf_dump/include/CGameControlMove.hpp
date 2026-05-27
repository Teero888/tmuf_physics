#ifndef CGAMECONTROLMOVE_HPP
#define CGAMECONTROLMOVE_HPP

#include "typedefs.h"

struct CGameControlMove {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    byte _padding_0x1c[36];
    undefined4 field_0x40; // accesses: 1
    undefined4 field_0x44; // accesses: 1
    undefined4 field_0x48; // accesses: 1
    byte _padding_0x4c[36];
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    int field_0x7c; // accesses: 3
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1

    // Member Functions
    void __thiscall CGameControlMove(CGameControlMove *this,CGameControlMove *param_1);
    void __thiscall LocationRefUpdate(CGameControlMove *this,CGameControlMove *param_1);
    void __thiscall LocationSet(CGameControlMove *this,CGameControlMove *param_1,GmIso4 *param_2);
};

#endif // CGAMECONTROLMOVE_HPP
