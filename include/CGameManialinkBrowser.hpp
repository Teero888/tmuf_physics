#ifndef CGAMEMANIALINKBROWSER_HPP
#define CGAMEMANIALINKBROWSER_HPP

#include "typedefs.h"

struct CAudioPort;
struct CAudioSound;
struct CGameApp;
struct CMwNod;

struct CGameManialinkBrowser {
    byte _padding_0x0[4];
    int field_0x4; // accesses: 1
    byte _padding_0x8[12];
    CGameApp_MenuContext * field_0x14; // accesses: 4
    int field_0x18; // accesses: 3
    int field_0x1c; // accesses: 1
    byte _padding_0x20[4];
    int * field_0x24; // accesses: 4
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 3
    int field_0x30; // accesses: 4
    int field_0x34; // accesses: 2
    undefined1 * field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 3
    CAudioPort * field_0x44; // accesses: 4
    byte _padding_0x48[52];
    undefined4 field_0x7c; // accesses: 1
    byte _padding_0x80[28];
    int field_0x9c; // accesses: 1
    int * field_0xa0; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ApplyActiveAndEnabled (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    int __thiscall IsActive(CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    void __thiscall ManialinkBrowser_CleanPage (CGameManialinkBrowser *this,CGameManialinkBrowser *param_1);
    void __thiscall SetIsEnabled(CGameManialinkBrowser *this,COalAudioPort *param_1,int param_2);
};

#endif // CGAMEMANIALINKBROWSER_HPP
