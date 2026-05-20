#ifndef CTRACKMANIAEDITORPUZZLE_HPP
#define CTRACKMANIAEDITORPUZZLE_HPP

#include "typedefs.h"

struct CGameCtnChallenge;
struct CTrackManiaEditorInterface;

struct CTrackManiaEditorPuzzle {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 2
    undefined4 field_0xc; // accesses: 1
    byte _padding_0x10[8];
    undefined4 field_0x18; // accesses: 1
    float field_0x1c; // accesses: 1
    int field_0x20; // accesses: 6
    float field_0x24; // accesses: 1
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[24];
    undefined4 field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 2
    byte _padding_0x58[96];
    CTrackManiaEditorInterface * field_0xb8; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CreateDefaultParams (CTrackManiaEditorPuzzle *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorPuzzle *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORPUZZLE_HPP
