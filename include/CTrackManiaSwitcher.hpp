#ifndef CTRACKMANIASWITCHER_HPP
#define CTRACKMANIASWITCHER_HPP

#include "typedefs.h"

struct CGameApp;
struct CTrackMania;

struct CTrackManiaSwitcher {
    void** vftable;
    byte _padding_0x4[16];
    CControlUiDockable * field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    CGameApp * field_0x1c; // accesses: 18
    byte _final_padding[0x4c]; // Total size: 0x6c

    // Member Functions
    void __thiscall Switch(CTrackManiaSwitcher *this,CControlUiDockable *param_1);
    void __thiscall SwitchToEditor(CTrackManiaSwitcher *this,CGameCtnMediaTracker *param_1);
    void __thiscall SwitchToEndRaceReplay(CTrackManiaSwitcher *this,CTrackManiaSwitcher *param_1);
};

#endif // CTRACKMANIASWITCHER_HPP
