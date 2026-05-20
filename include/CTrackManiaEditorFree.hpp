#ifndef CTRACKMANIAEDITORFREE_HPP
#define CTRACKMANIAEDITORFREE_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CTrackManiaEditorFree {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 7
    byte _padding_0x8[24];
    int field_0x20; // accesses: 3
    byte _padding_0x24[152];
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[1108];
    undefined4 field_0x514; // accesses: 2

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x004a00d1) */ /* WARNING: Removing unreachable block (ram,0x004a0126) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaEditorFree::CreateDefaultParams (CTrackManiaEditorFree *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorFree *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORFREE_HPP
