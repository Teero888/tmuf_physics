#ifndef CGAMECTNMEDIACLIPVIEWER_HPP
#define CGAMECTNMEDIACLIPVIEWER_HPP

#include "typedefs.h"

struct CGameCtnBench;
struct CGameCtnMediaClipGroup;
struct CGameCtnMediaClipPlayer;
struct CMwNod;

struct CGameCtnMediaClipViewer {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    CGameCtnBench * field_0x1c; // accesses: 3
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 2
    CGameCtnMediaClipViewer * field_0x28; // accesses: 1
    CGameCtnMediaClipPlayer * field_0x2c; // accesses: 13
    CGameCtnMediaClipPlayer * field_0x30; // accesses: 23
    CMwNod * field_0x34; // accesses: 6
    CMwNod * field_0x38; // accesses: 7
    undefined4 field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    CGameCtnMediaClipGroup * field_0x44; // accesses: 11
    undefined4 field_0x48; // accesses: 1
    CGameCtnMediaClipPlayer * field_0x4c; // accesses: 12
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 2
    undefined4 field_0x68; // accesses: 2
    undefined4 field_0x6c; // accesses: 2
    undefined4 field_0x70; // accesses: 2
    CMwNod * field_0x74; // accesses: 6
    CGameCtnMediaClipViewer * field_0x78; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameCtnMediaClipViewer (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1);
    void __thiscall ClipGroupSet (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1, CGameCtnMediaClipGroup *param_2);
    void __thiscall ClipSet (CGameCtnMediaClipViewer *this,CGameCtnMediaClipPlayer *param_1,CGameCtnMediaClip *param_2 );
    void __thiscall Start(CGameCtnMediaClipViewer *this,CGameCtnBench *param_1);
    void __thiscall StatusSet (CGameCtnMediaClipViewer *this,CGameCtnMediaClipViewer *param_1,EStatus param_2);
};

#endif // CGAMECTNMEDIACLIPVIEWER_HPP
