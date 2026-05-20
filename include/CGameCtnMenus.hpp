#ifndef CGAMECTNMENUS_HPP
#define CGAMECTNMENUS_HPP

#include "typedefs.h"

struct CControlContainer;
struct CGameApp;
struct CGameCtnApp;
struct CHmsZone;
struct CMwNod;
struct CSceneObject;

struct CGameCtnMenus {
    struct SFrameLadderRankingsStepOld {

        // Member Functions
        void __thiscall ~SFrameLadderRankingsStepOld (void *this,SFrameLadderRankingsStepOld *param_1);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    undefined4 field_0x8; // accesses: 1
    byte _padding_0xc[148];
    CHmsZone * field_0xa0; // accesses: 1
    byte _padding_0xa4[152];
    undefined4 field_0x13c; // accesses: 1
    byte _padding_0x140[36];
    int field_0x164; // accesses: 2
    byte _padding_0x168[140];
    int field_0x1f4; // accesses: 1
    int field_0x1f8; // accesses: 1
    byte _padding_0x1fc[32];
    undefined4 field_0x21c; // accesses: 3
    undefined4 field_0x220; // accesses: 1
    byte _padding_0x224[24];
    undefined4 field_0x23c; // accesses: 1
    undefined4 field_0x240; // accesses: 1
    undefined4 field_0x244; // accesses: 1
    byte _padding_0x248[860];
    undefined4 field_0x5a4; // accesses: 6
    undefined4 field_0x5a8; // accesses: 3
    byte _padding_0x5ac[112];
    undefined4 field_0x61c; // accesses: 3
    undefined4 field_0x620; // accesses: 2
    byte _padding_0x624[128];
    CControlContainer * field_0x6a4; // accesses: 1
    byte _padding_0x6a8[88];
    undefined4 field_0x700; // accesses: 1
    byte _padding_0x704[128];
    CGameCtnApp * field_0x784; // accesses: 9
    int field_0x788; // accesses: 3
    int field_0x78c; // accesses: 4

    // Member Functions
    void __thiscall DialogCardGrid_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall DialogGrid_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall DialogInGameMenu_OnAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall DialogLadderRankings_PushStep (CGameCtnMenus *this,CGameCtnMenus *param_1,CGameMasterServerRequestParams *param_2);
    void __thiscall DialogPlayerProfile_DestroyVehicleScene(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall DialogRefereeStatus_PushMessage (CGameCtnMenus *this,CGameCtnMenus *param_1,CFastStringInt *param_2);
    void __thiscall HideDialogs(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall MenuChooseChallenge_ResetCurrentSelection(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall MenuProfileAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall MenuProfileAdvanced_SetTrailColor (CGameCtnMenus *this,CGameCtnMenus *param_1,GmVec3 *param_2,int param_3);
    void __thiscall MenuProfile_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall MenuProfile_OnAdvanced(CGameCtnMenus *this,CGameCtnMenus *param_1);
    void __thiscall MenuProfile_TagsAdmin_Clean(CGameCtnMenus *this,CGameCtnMenus *param_1);
};

#endif // CGAMECTNMENUS_HPP
