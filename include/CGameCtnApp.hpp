#ifndef CGAMECTNAPP_HPP
#define CGAMECTNAPP_HPP

#include "typedefs.h"

struct CGameAdvertising;
struct CInputBindingsConfig;
struct CInputPort;
struct CMwNod;

struct CGameCtnApp {
    struct SNationConfig {
        void** vftable; // accesses: 1
        undefined * field_0x4; // accesses: 2

        // Member Functions
        void __thiscall ~SNationConfig(void *this,SNationConfig *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[104];
    CInputPort * field_0x6c; // accesses: 6
    byte _padding_0x70[188];
    int field_0x12c; // accesses: 2
    byte _padding_0x130[56];
    CMwNod * field_0x168; // accesses: 3
    byte _padding_0x16c[8];
    int field_0x174; // accesses: 1
    byte _padding_0x178[28];
    int * field_0x194; // accesses: 5
    byte _padding_0x198[120];
    CGameAdvertising * field_0x210; // accesses: 4
    byte _padding_0x214[96];
    int field_0x274; // accesses: 1
    byte _padding_0x278[16];
    undefined1 * field_0x288; // accesses: 2
    void * field_0x28c; // accesses: 1
    byte _padding_0x290[52];
    CInputBindingsConfig * field_0x2c4; // accesses: 1
    CInputBindingsConfig * field_0x2c8; // accesses: 1
    CInputBindingsConfig * field_0x2cc; // accesses: 1
    CInputBindingsConfig * field_0x2d0; // accesses: 1
    byte _padding_0x2d4[104];
    int field_0x33c; // accesses: 2
    int field_0x340; // accesses: 3
    float field_0x344; // accesses: 2
    uint field_0x348; // accesses: 3
    byte _final_padding[0xc4]; // Total size: 0x410

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CInputBindingsConfig * __thiscall GetCurrentInputBindings(CGameCtnApp *this,CGameCtnApp *param_1,int param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CGameCtnApp *this,CInputPortDx8 *param_1);
    CGameCtnMasterServer * __thiscall GetMasterServer(CGameCtnApp *this,CGameCtnApp *param_1);
    CSystemFidsFolder * __thiscall GetWritableDir(CGameCtnApp *this,CGameCtnApp *param_1,EDirectory param_2);
    void __cdecl GetVehicleDisplayName(CMwId *param_1,CFastStringInt *param_2,CFastString *param_3);
    void __thiscall Advertising_SetZone (CGameCtnApp *this,CGameCtnApp *param_1,CGameCtnChallenge *param_2,int param_3);
    void __thiscall HideDialogs(CGameCtnApp *this,CGameCtnMenus *param_1);
    void __thiscall InputsInitActions (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2, _func___cdecl_void_CInputBindingsConfig_ptr *param_3);
    void __thiscall InputsSetDefault (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2, _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *param_3);
    void __thiscall InputsSetToDefaultUnbidedDevices (CGameCtnApp *this,CGameCtnApp *param_1,CInputBindingsConfig *param_2, _func___cdecl_void_CInputBindingsConfig_ptr_CInputDevice_ptr_ulong *param_3);
    void __thiscall SaveValidationReplay (CGameCtnApp *this,CGameCtnApp *param_1,CGameCtnReplayRecord *param_2,int param_3);
    void __thiscall ShowDialogs(CGameCtnApp *this,CGameCtnMenus *param_1,CControlFrame *param_2);
};

#endif // CGAMECTNAPP_HPP
