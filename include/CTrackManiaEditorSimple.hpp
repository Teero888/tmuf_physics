#ifndef CTRACKMANIAEDITORSIMPLE_HPP
#define CTRACKMANIAEDITORSIMPLE_HPP

#include "typedefs.h"

struct CGameCtnChallenge;

struct CTrackManiaEditorSimple {
    byte _padding_0x0[32];
    CGameCtnChallenge * field_0x20; // accesses: 4
    byte _padding_0x24[152];
    int field_0xbc; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x00445833) */ /* WARNING: Removing unreachable block (ram,0x00445888) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CTrackManiaEditorSimple::CreateDefaultParams (CTrackManiaEditorSimple *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorSimple *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORSIMPLE_HPP
