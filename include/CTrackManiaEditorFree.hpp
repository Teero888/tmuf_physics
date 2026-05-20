#ifndef CTRACKMANIAEDITORFREE_HPP
#define CTRACKMANIAEDITORFREE_HPP

#include "typedefs.h"

struct CTrackManiaEditorFree {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    uint field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 3
    undefined4 field_0x18; // accesses: 3
    float field_0x1c; // accesses: 3
    int field_0x20; // accesses: 4
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[100];
    uint field_0xa8; // accesses: 1
    byte _padding_0xac[4];
    uint field_0xb0; // accesses: 1
    byte _padding_0xb4[8];
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[84];
    int field_0x114; // accesses: 1
    byte _padding_0x118[1020];
    int field_0x514; // accesses: 2

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x004a00d1) */ /* WARNING: Removing unreachable block (ram,0x004a0126) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaEditorFree::CreateDefaultParams (CTrackManiaEditorFree *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorFree *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORFREE_HPP
