#ifndef CTRACKMANIAMENUS_HPP
#define CTRACKMANIAMENUS_HPP

#include "typedefs.h"

struct CGameApp;
struct CGameNetwork;
struct CTrackMania;
struct CTrackManiaNetwork;

struct CTrackManiaMenus {
    void** vftable; // accesses: 2
    byte _padding_0x4[120];
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[1664];
    undefined4 field_0x700; // accesses: 1
    undefined4 field_0x704; // accesses: 1
    byte _padding_0x708[124];
    CTrackMania * field_0x784; // accesses: 10
    int field_0x788; // accesses: 1
    byte _padding_0x78c[180];
    CGameNetwork * field_0x840; // accesses: 3

    // Member Functions
    void __thiscall DialogInGameMenu_OnRetire(CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuCreateChallenge_OnAdvanced(CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuCreateChallenge_OnOk(CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuEditors_OnLoadChallenge_OnAdvanced (CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuEditors_OnLoadChallenge_OnOk(CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuMultiPlayerNetworkCreate_OnAdvanced (CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuMultiPlayerNetworkCreate_RefreshDisplay (CTrackManiaMenus *this,CTrackManiaMenus *param_1);
    void __thiscall MenuPlayChallenge_Edit(CTrackManiaMenus *this,CTrackManiaMenus *param_1);
};

#endif // CTRACKMANIAMENUS_HPP
