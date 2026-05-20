#ifndef CCONTROLSTYLE_HPP
#define CCONTROLSTYLE_HPP

#include "typedefs.h"

struct CMwNod;

struct CControlStyle {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    undefined4 field_0x8; // accesses: 4
    undefined4 field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 9
    undefined4 field_0x18; // accesses: 8
    undefined4 field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 3
    undefined4 field_0x28; // accesses: 6
    undefined4 field_0x2c; // accesses: 6
    undefined4 field_0x30; // accesses: 6
    undefined4 field_0x34; // accesses: 6
    undefined4 field_0x38; // accesses: 3
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    undefined4 field_0x44; // accesses: 3
    undefined4 field_0x48; // accesses: 3
    undefined4 field_0x4c; // accesses: 6
    undefined4 field_0x50; // accesses: 13
    undefined4 field_0x54; // accesses: 5
    undefined4 field_0x58; // accesses: 5
    byte _padding_0x5c[4];
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    byte _padding_0x70[12];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 1
    byte _padding_0x8c[12];
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    byte _padding_0xa8[8];
    undefined4 field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 3
    undefined4 field_0xb8; // accesses: 6
    undefined4 field_0xbc; // accesses: 6
    undefined4 field_0xc0; // accesses: 6
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 3
    undefined4 field_0xcc; // accesses: 3
    undefined4 field_0xd0; // accesses: 6
    undefined4 field_0xd4; // accesses: 6
    undefined4 field_0xd8; // accesses: 6
    undefined4 field_0xdc; // accesses: 3
    undefined4 field_0xe0; // accesses: 3
    undefined4 field_0xe4; // accesses: 3
    undefined4 field_0xe8; // accesses: 3
    undefined4 field_0xec; // accesses: 6
    undefined4 field_0xf0; // accesses: 3
    undefined4 field_0xf4; // accesses: 3
    undefined4 field_0xf8; // accesses: 3
    undefined4 field_0xfc; // accesses: 3
    undefined4 field_0x100; // accesses: 6
    undefined4 field_0x104; // accesses: 6
    undefined4 field_0x108; // accesses: 6
    undefined4 field_0x10c; // accesses: 3
    undefined4 field_0x110; // accesses: 3
    undefined4 field_0x114; // accesses: 3
    undefined4 field_0x118; // accesses: 3
    undefined4 field_0x11c; // accesses: 3
    undefined4 field_0x120; // accesses: 3
    undefined4 field_0x124; // accesses: 3
    undefined4 field_0x128; // accesses: 3
    undefined4 field_0x12c; // accesses: 3
    undefined4 field_0x130; // accesses: 3
    undefined4 field_0x134; // accesses: 3
    undefined4 field_0x138; // accesses: 3
    undefined4 field_0x13c; // accesses: 3
    undefined4 field_0x140; // accesses: 3
    undefined4 field_0x144; // accesses: 3
    undefined4 field_0x148; // accesses: 3
    undefined4 field_0x14c; // accesses: 3
    undefined4 field_0x150; // accesses: 3
    undefined4 field_0x154; // accesses: 3
    undefined4 field_0x158; // accesses: 3
    undefined4 field_0x15c; // accesses: 3
    undefined4 field_0x160; // accesses: 3
    undefined4 field_0x164; // accesses: 3
    undefined4 field_0x168; // accesses: 3
    undefined4 field_0x16c; // accesses: 3
    undefined4 field_0x170; // accesses: 3
    undefined4 field_0x174; // accesses: 3
    undefined4 field_0x178; // accesses: 3
    undefined4 field_0x17c; // accesses: 6
    undefined4 field_0x180; // accesses: 6

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CControlStyle(CControlStyle *this,CControlStyle *param_1);
    CControlStyle * __cdecl Fork(CControlStyle *param_1);
    int __thiscall InternalShouldFontBeTakenFromMaster (CControlStyle *this,CControlStyle *param_1,ETextMode param_2);
    ulong __thiscall GetMwClassId(CControlStyle *this,CControlStyle *param_1);
    void __thiscall InternalDetachFromStyleSheet (CControlStyle *this,CControlStyle *param_1,CControlStyleSheet *param_2);
    void __thiscall InternalGetTextSettings (CControlStyle *this,CControlStyle *param_1,ETextMode param_2,STextSettings *param_3, CControlStyleSheet *param_4);
    void __thiscall SetFocusGainedScript (CControlStyle *this,CControlStyle *param_1,CMwCmdBlockMain *param_2);
    void __thiscall SetFocusLostScript (CControlStyle *this,CControlStyle *param_1,CMwCmdBlockMain *param_2);
};

#endif // CCONTROLSTYLE_HPP
