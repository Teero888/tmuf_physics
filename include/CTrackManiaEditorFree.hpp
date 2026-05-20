#ifndef CTRACKMANIAEDITORFREE_HPP
#define CTRACKMANIAEDITORFREE_HPP

#include "typedefs.h"

struct CTrackManiaEditorFree {
    void** vftable;
    byte _padding_0x4[28];
    int field_0x20; // accesses: 3
    byte _padding_0x24[152];
    int field_0xbc; // accesses: 2
    byte _padding_0xc0[1108];
    int field_0x514; // accesses: 2
    byte _final_padding[0x4]; // Total size: 0x51c

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x004a00d1) */ /* WARNING: Removing unreachable block (ram,0x004a0126) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaEditorFree::CreateDefaultParams (CTrackManiaEditorFree *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorFree *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORFREE_HPP
