#ifndef CGAMEAPP_HPP
#define CGAMEAPP_HPP

#include "typedefs.h"

struct CAudioPort;
struct CAudioSound;
struct CGameCtnCatalog;
struct CGameDialogs;
struct CGameManialinkBrowser;
struct CGameNetwork;
struct CHmsViewport;
struct CMwNod;
struct CScenePickerManager;

struct CGameApp {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 1
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 5
    int * field_0x18; // accesses: 13
    undefined4 field_0x1c; // accesses: 5
    undefined4 field_0x20; // accesses: 5
    undefined4 field_0x24; // accesses: 6
    int field_0x28; // accesses: 9
    undefined4 field_0x2c; // accesses: 5
    undefined4 field_0x30; // accesses: 5
    undefined4 field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 2
    byte _padding_0x40[4];
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 1
    byte _padding_0x4c[4];
    int field_0x50; // accesses: 1
    byte _padding_0x54[16];
    CMwNod * field_0x64; // accesses: 2
    CAudioPort * field_0x68; // accesses: 7
    CMwNod * field_0x6c; // accesses: 1
    byte _padding_0x70[8];
    int field_0x78; // accesses: 10
    int field_0x7c; // accesses: 1
    byte _padding_0x80[16];
    int field_0x90; // accesses: 2
    byte _padding_0x94[120];
    CGameManialinkBrowser * field_0x10c; // accesses: 1
    CGameDialogs * field_0x110; // accesses: 1
    int field_0x114; // accesses: 4
    byte _padding_0x118[20];
    int field_0x12c; // accesses: 2
    int field_0x130; // accesses: 2
    int field_0x134; // accesses: 4
    byte _padding_0x138[48];
    int field_0x168; // accesses: 6
    byte _padding_0x16c[4];
    CMwNod * field_0x170; // accesses: 1
    CMwNod * field_0x174; // accesses: 1
    CMwNod * field_0x178; // accesses: 1
    CAudioPort * field_0x17c; // accesses: 13
    undefined4 field_0x180; // accesses: 6
    byte _padding_0x184[12];
    int field_0x190; // accesses: 3
    byte _padding_0x194[700];
    float field_0x450; // accesses: 1
    float field_0x454; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl PlaySound(CPlugSound *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetCursorPos(CGameApp *this,CGameApp *param_1,GmVec2 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall StopMusics(CGameApp *this,CGameApp *param_1,int param_2);
    /* WARNING: Removing unreachable block (ram,0x0059d906) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CGameApp::PlayMusic(CGameApp *this,CGameApp *param_1,EInterfaceMusic param_2,int param_3);
    CAudioSound * __thiscall GetSound(CGameApp *this,CGameApp *param_1,EInterfaceSound param_2);
    CGameCtnMediaContext * __thiscall MediaContextCreate(CGameApp *this,CGameApp *param_1);
    CGameDialogs * __thiscall GetBasicDialogs(CGameApp *this,CGameApp *param_1);
    CGameManialinkBrowser * __thiscall GetManialinkBrowser(CGameApp *this,CGameApp *param_1);
    CGameMenu * __thiscall GetCurrentMenu(CGameApp *this,CGameApp *param_1);
    CPlugMusic * __thiscall GetNextMusic(CGameApp *this,CGameApp *param_1,EInterfaceMusic param_2);
    EAccountType __thiscall GetPayingAccountType(CGameApp *this,CGameApp *param_1);
    int __thiscall IsPayingInstall(CGameApp *this,CGameApp *param_1);
    int __thiscall IsPayingSolo(CGameApp *this,CGameApp *param_1);
    int __thiscall IsPickEnabled(CGameApp *this,CGameApp *param_1);
    int __thiscall Profile_IsAvatarsEnabled(CGameApp *this,CGameApp *param_1);
    int __thiscall Profile_IsChatEnabled(CGameApp *this,CGameApp *param_1);
    int __thiscall Profile_IsPackDescParentalLocked (CGameApp *this,CGameApp *param_1,CSystemPackDesc *param_2);
    int __thiscall Profile_IsSkinsEnabled (CGameApp *this,CGameApp *param_1,int param_2,CSystemPackDesc *param_3);
    void __thiscall EnablePick(CGameApp *this,CGameApp *param_1);
    void __thiscall HideMenu(CGameApp *this,CGameApp_MenuContext *param_1,CGameMenu *param_2);
    void __thiscall ShowMenu(CGameApp *this,CGameApp_MenuContext *param_1,CGameMenu *param_2);
    void __thiscall UpdateMusic(CGameApp *this,CGameApp *param_1);
};

#endif // CGAMEAPP_HPP
