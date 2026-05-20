#ifndef CGAMEPLAYERCAMERASET_HPP
#define CGAMEPLAYERCAMERASET_HPP

#include "typedefs.h"

struct CGameControlCamera;
struct CGameControlCameraMaster;

struct CGamePlayerCameraSet {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 4
    CGameControlCameraMaster * field_0x18; // accesses: 10
    CGameControlCamera * field_0x1c; // accesses: 7
    byte _padding_0x20[96];
    undefined4 field_0x80; // accesses: 1

    // Member Functions
    CGameControlCamera * __thiscall CamPtrGet (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2);
    CGameControlCamera * __thiscall CamPtrGetCur(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1);
    ulong __thiscall CamGetCount(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1);
    ulong __thiscall CamGetCur(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1);
    void __thiscall CamSwitchTo (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2);
    void __thiscall CamsReset(CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1);
    void __thiscall PlayerGameMobilIdSet (CGamePlayerCameraSet *this,CGamePlayerCameraSet *param_1,ulong param_2);
    void __thiscall UpdateAsync(CGamePlayerCameraSet *this,CInputPortDx8 *param_1);
};

#endif // CGAMEPLAYERCAMERASET_HPP
