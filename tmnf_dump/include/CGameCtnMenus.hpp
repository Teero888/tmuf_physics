#ifndef CGAMECTNMENUS_HPP
#define CGAMECTNMENUS_HPP

#include "typedefs.h"

struct CControlContainer;
struct CGameApp;
struct CGameCtnApp;
struct CMwNod;
struct CSceneObject;

struct CGameCtnMenus {
    struct SFrameLadderRankingsStepOld {
        void** vftable;
        byte _padding_0x4[4];
        undefined4 field_0x8; // accesses: 1
        undefined * field_0xc; // accesses: 2

        // Member Functions
        void __thiscall ~SFrameLadderRankingsStepOld (void *this,SFrameLadderRankingsStepOld *param_1);
    };

    void** vftable; // accesses: 2
    byte _final_padding[0x132]; // Total size: 0x136

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
