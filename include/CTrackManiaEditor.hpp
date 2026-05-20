#ifndef CTRACKMANIAEDITOR_HPP
#define CTRACKMANIAEDITOR_HPP

#include "typedefs.h"

struct CGameCtnChallenge;
struct CGameCtnEditorScenePocLink;
struct CMwId;
struct CMwNod;
struct CSceneMobil;
struct CSceneObjectLink;
struct CTrackManiaEditorInterface;

struct CTrackManiaEditor {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 1
    undefined4 field_0x10; // accesses: 1
    int field_0x14; // accesses: 4
    int field_0x18; // accesses: 4
    CMwId * field_0x1c; // accesses: 2
    CGameCtnChallenge * field_0x20; // accesses: 4
    byte _padding_0x24[4];
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    ECardinalDir field_0x34; // accesses: 1
    int field_0x38; // accesses: 5
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    byte _padding_0x44[56];
    undefined4 field_0x7c; // accesses: 1
    undefined4 field_0x80; // accesses: 1
    byte _padding_0x84[8];
    undefined4 field_0x8c; // accesses: 1
    byte _padding_0x90[40];
    CTrackManiaEditorInterface * field_0xb8; // accesses: 1
    int field_0xbc; // accesses: 4
    byte _padding_0xc0[4];
    CMwNod * field_0xc4; // accesses: 11
    byte _padding_0xc8[12];
    CGameCtnChallenge * field_0xd4; // accesses: 2
    byte _padding_0xd8[764];
    int * field_0x3d4; // accesses: 5
    undefined4 field_0x3d8; // accesses: 1
    undefined4 field_0x3dc; // accesses: 1
    undefined4 field_0x3e0; // accesses: 1
    byte _padding_0x3e4[120];
    undefined4 field_0x45c; // accesses: 1
    undefined4 field_0x460; // accesses: 1
    byte _padding_0x464[24];
    int field_0x47c; // accesses: 1
    byte _padding_0x480[100];
    undefined4 field_0x4e4; // accesses: 1
    byte _padding_0x4e8[32];
    undefined4 field_0x508; // accesses: 1
    undefined4 field_0x50c; // accesses: 1
    undefined4 field_0x510; // accesses: 1
    undefined4 field_0x514; // accesses: 1

    // Member Functions
    int __thiscall IsPuzzlePlaceType(CTrackManiaEditor *this,CTrackManiaEditor *param_1);
    void __thiscall ButtonBackStepOnClick(CTrackManiaEditor *this,CTrackManiaEditor *param_1);
    void __thiscall Start(CTrackManiaEditor *this,CGameCtnBench *param_1);
};

#endif // CTRACKMANIAEDITOR_HPP
