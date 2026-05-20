#ifndef CINPUTBINDINGSCONFIG_HPP
#define CINPUTBINDINGSCONFIG_HPP

#include "typedefs.h"

struct CInputBindingsConfig {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 5
    undefined4 field_0x8; // accesses: 2
    byte _padding_0xc[56];
    undefined4 field_0x44; // accesses: 1
    undefined * field_0x48; // accesses: 1
    ulong field_0x4c; // accesses: 2

    // Member Functions
    int __thiscall IsDeviceConfigured (CInputBindingsConfig *this,CInputBindingsConfig *param_1,CMwId *param_2);
    ulong __thiscall FindAction (CInputBindingsConfig *this,CInputBindingsConfig *param_1,SInputActionDesc *param_2);
    void __thiscall CInputBindingsConfig(CInputBindingsConfig *this,CInputBindingsConfig *param_1);
    void __thiscall ClearActions(CInputBindingsConfig *this,CInputBindingsConfig *param_1);
    void __thiscall ClearAllBindings (CInputBindingsConfig *this,CInputBindingsConfig *param_1,CMwId *param_2);
    void __thiscall ClearBindings (CInputBindingsConfig *this,CInputBindingsConfig *param_1,ulong param_2,CMwId *param_3);
    void __thiscall GetBindings (CInputBindingsConfig *this,CInputBindingsConfig *param_1,ulong param_2, CFastBuffer<struct_CInputBindingsConfig::SBinding> *param_3,CMwId *param_4);
    void __thiscall Init (CInputBindingsConfig *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CINPUTBINDINGSCONFIG_HPP
