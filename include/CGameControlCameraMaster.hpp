#ifndef CGAMECONTROLCAMERAMASTER_HPP
#define CGAMECONTROLCAMERAMASTER_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameControlCameraMaster {
    struct SSwitch {

        // Member Functions
        float __thiscall Update (void *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSwitch(void *this,SSwitch *param_1);
    };

    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 4
    byte _padding_0x18[80];
    undefined4 field_0x68; // accesses: 13
    undefined4 field_0x6c; // accesses: 5
    undefined4 field_0x70; // accesses: 4
    undefined4 field_0x74; // accesses: 1
    byte _padding_0x78[4];
    int field_0x7c; // accesses: 2
    byte _padding_0x80[4];
    int field_0x84; // accesses: 1

    // Member Functions
    CGameControlCamera * __thiscall CamGet (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,ulong param_2);
    int __thiscall SwitchFromCurrentTo (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,ulong param_2, ulong param_3);
    void __thiscall ApplyGlobalEffectsOn (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,GmCamVal *param_2);
    void __thiscall CGameControlCameraMaster (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1);
    void __thiscall GetCamVal (CGameControlCameraMaster *this,GmCamFreeVal *param_1,GmCamVal *param_2);
    void __thiscall Install(CGameControlCameraMaster *this,CMwCmdFiber *param_1);
    void __thiscall ResetAllCameras (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1);
    void __thiscall StopSwitching (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1);
    void __thiscall SwitchToNone (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1);
    void __thiscall Uninstall(CGameControlCameraMaster *this,CMwCmdContainer *param_1);
    void __thiscall UpdateAsync(CGameControlCameraMaster *this,CInputPortDx8 *param_1);
    void __thiscall UpdateCameras (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,float param_2);
    void __thiscall UpdateSwitchs (CGameControlCameraMaster *this,CGameControlCameraMaster *param_1,float param_2);
};

#endif // CGAMECONTROLCAMERAMASTER_HPP
