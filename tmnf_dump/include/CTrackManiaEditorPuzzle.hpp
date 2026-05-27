#ifndef CTRACKMANIAEDITORPUZZLE_HPP
#define CTRACKMANIAEDITORPUZZLE_HPP

#include "typedefs.h"

struct CGameCtnChallenge;
struct CTrackManiaEditorInterface;

struct CTrackManiaEditorPuzzle {
    void** vftable; // accesses: 2
    byte _padding_0x4[28];
    CGameCtnChallenge * field_0x20; // accesses: 5
    byte _padding_0x24[148];
    CTrackManiaEditorInterface * field_0xb8; // accesses: 1
    byte _final_padding[0x460]; // Total size: 0x51c

    // Member Functions
    void __thiscall CreateDefaultParams (CTrackManiaEditorPuzzle *this,CTrackManiaEditor *param_1,SStartParameters *param_2);
    void __thiscall Start(CTrackManiaEditorPuzzle *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITORPUZZLE_HPP
