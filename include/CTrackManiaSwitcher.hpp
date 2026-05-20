#ifndef CTRACKMANIASWITCHER_HPP
#define CTRACKMANIASWITCHER_HPP

#include "typedefs.h"

struct CGameApp;
struct CGameCtnMediaClipViewer;
struct CMwNod;
struct CSceneObjectLink;
struct CTrackMania;

struct CTrackManiaSwitcher {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    int * field_0x1c; // accesses: 18
    byte _padding_0x20[88];
    CGameCtnMediaContext * field_0x78; // accesses: 4
    byte _padding_0x7c[52];
    int field_0xb0; // accesses: 2
    byte _padding_0xb4[16];
    CSceneObjectLink * field_0xc4; // accesses: 1
    byte _padding_0xc8[168];
    int field_0x170; // accesses: 2
    byte _padding_0x174[16];
    CGameCtnMediaClipViewer * field_0x184; // accesses: 1
    CGameCtnMediaClipViewer * field_0x188; // accesses: 1
    byte _padding_0x18c[648];
    int * field_0x414; // accesses: 2

    // Member Functions
    void __thiscall Switch(CTrackManiaSwitcher *this,CControlUiDockable *param_1);
    void __thiscall SwitchToEditor(CTrackManiaSwitcher *this,CGameCtnMediaTracker *param_1);
    void __thiscall SwitchToEndRaceReplay(CTrackManiaSwitcher *this,CTrackManiaSwitcher *param_1);
};

#endif // CTRACKMANIASWITCHER_HPP
