#ifndef CTRACKMANIAEDITORSIMPLE_HPP
#define CTRACKMANIAEDITORSIMPLE_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CTrackManiaEditorSimple {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    uint field_0x8; // accesses: 1
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[12];
    float field_0x1c; // accesses: 1
    int field_0x20; // accesses: 5
    float field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    float field_0x30; // accesses: 1
    byte _padding_0x34[116];
    uint field_0xa8; // accesses: 1
    byte _padding_0xac[4];
    uint field_0xb0; // accesses: 1
    byte _padding_0xb4[8];
    int field_0xbc; // accesses: 1
    byte _padding_0xc0[84];
    int field_0x114; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00445833) */ /* WARNING: Removing unreachable block (ram,0x00445888) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaEditorSimple::CreateDefaultParams (CTrackManiaEditorSimple *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorSimple *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORSIMPLE_HPP
