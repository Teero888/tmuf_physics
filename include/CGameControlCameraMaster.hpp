#ifndef CGAMECONTROLCAMERAMASTER_HPP
#define CGAMECONTROLCAMERAMASTER_HPP

#include "typedefs.h"

struct CMwNod;
struct ulong;

struct CGameControlCameraMaster {
    struct SSwitch {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        int * field_0x8; // accesses: 3
        int * field_0xc; // accesses: 3
        undefined4 field_0x10; // accesses: 2
        undefined4 field_0x14; // accesses: 3
        undefined4 field_0x18; // accesses: 3
        undefined4 field_0x1c; // accesses: 3
        undefined4 field_0x20; // accesses: 2
        float field_0x24; // accesses: 1
        float field_0x28; // accesses: 1
        float field_0x2c; // accesses: 1
        byte _padding_0x30[36];
        float field_0x54; // accesses: 1
        float field_0x58; // accesses: 1
        float field_0x5c; // accesses: 1
        byte _padding_0x60[224];
        float field_0x140; // accesses: 5
        float field_0x144; // accesses: 9

        // Member Functions
        float __thiscall Update (void *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3);
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSwitch(void *this,SSwitch *param_1);
    };

    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 3
    byte _padding_0x18[80];
    CMwNod * field_0x68; // accesses: 13
    ulong field_0x6c; // accesses: 5
    undefined4 field_0x70; // accesses: 4
    undefined4 field_0x74; // accesses: 1
    byte _padding_0x78[4];
    int * field_0x7c; // accesses: 2
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
