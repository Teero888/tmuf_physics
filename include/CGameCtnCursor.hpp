#ifndef CGAMECTNCURSOR_HPP
#define CGAMECTNCURSOR_HPP

#include "typedefs.h"

struct CGameOutlineBox;
struct CMwNod;
struct CPlugTree;
struct CSceneMobil;

struct CGameCtnCursor {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 4
    undefined4 field_0x24; // accesses: 4
    undefined4 field_0x28; // accesses: 4
    undefined4 field_0x2c; // accesses: 4
    undefined4 field_0x30; // accesses: 4
    undefined4 field_0x34; // accesses: 4
    undefined4 field_0x38; // accesses: 3
    undefined4 field_0x3c; // accesses: 1
    CMwNod * field_0x40; // accesses: 12
    CSceneMobil * field_0x44; // accesses: 17
    CMwNod * field_0x48; // accesses: 11
    CPlugTree * field_0x4c; // accesses: 16
    CGameOutlineBox * field_0x50; // accesses: 20
    int field_0x54; // accesses: 3
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    undefined4 field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 2
    undefined4 field_0x7c; // accesses: 2
    undefined4 field_0x80; // accesses: 2
    ESpriteColor0 * field_0x84; // accesses: 2
    undefined4 field_0x88; // accesses: 1
    undefined4 field_0x8c; // accesses: 1
    undefined4 field_0x90; // accesses: 1
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined4 field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined4 field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 2
    undefined4 field_0xbc; // accesses: 2
    undefined4 field_0xc0; // accesses: 2
    undefined4 field_0xc4; // accesses: 2
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    CSceneMobil * field_0xd8; // accesses: 3
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined4 field_0xe8; // accesses: 1
    undefined4 field_0xec; // accesses: 1
    undefined4 field_0xf0; // accesses: 1
    SVolatileTreePointer * field_0xf4; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall Update(CGameCtnCursor *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameCtnCursor(CGameCtnCursor *this,CGameCtnCursor *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateCursorColor(CGameCtnCursor *this,CGameCtnCursor *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateShadow (CGameCtnCursor *this,CGameCtnCursor *param_1,CGameCtnBlockInfo *param_2,int param_3);
    void __thiscall AddBlocksToCursor (CGameCtnCursor *this,CGameCtnCursor *param_1,CGameCtnBlockInfo *param_2,int param_3, ulong param_4);
    void __thiscall GetMobilLocation(CGameCtnCursor *this,CGameCtnCursor *param_1,GmIso4 *param_2);
    void __thiscall UpdateColor (CGameCtnCursor *this,CGameCtnCursor *param_1,int param_2,int param_3,int param_4, int param_5,int param_6,int param_7,int param_8);
};

#endif // CGAMECTNCURSOR_HPP
