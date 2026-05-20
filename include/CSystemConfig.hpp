#ifndef CSYSTEMCONFIG_HPP
#define CSYSTEMCONFIG_HPP

#include "typedefs.h"

struct CSystemConfigDisplay;

struct CSystemConfig {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 1
    undefined4 field_0x18; // accesses: 1
    undefined * field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 4
    undefined4 field_0x24; // accesses: 6
    CSystemConfigDisplay * field_0x28; // accesses: 3
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 5
    int field_0x40; // accesses: 5
    undefined4 field_0x44; // accesses: 3
    undefined * field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    undefined4 field_0x50; // accesses: 1
    undefined4 field_0x54; // accesses: 1
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined * field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 2
    undefined4 field_0x70; // accesses: 1
    undefined * field_0x74; // accesses: 1
    undefined4 field_0x78; // accesses: 1
    undefined * field_0x7c; // accesses: 1
    byte _padding_0x80[20];
    undefined4 field_0x94; // accesses: 1
    undefined4 field_0x98; // accesses: 1
    undefined * field_0x9c; // accesses: 1
    undefined4 field_0xa0; // accesses: 1
    undefined4 field_0xa4; // accesses: 1
    undefined4 field_0xa8; // accesses: 1
    undefined * field_0xac; // accesses: 1
    undefined4 field_0xb0; // accesses: 1
    undefined4 field_0xb4; // accesses: 1
    undefined4 field_0xb8; // accesses: 1
    byte _padding_0xbc[12];
    undefined4 field_0xc8; // accesses: 1
    undefined4 field_0xcc; // accesses: 1
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 1
    undefined4 field_0xd8; // accesses: 1
    undefined4 field_0xdc; // accesses: 1
    undefined4 field_0xe0; // accesses: 1
    undefined4 field_0xe4; // accesses: 1
    undefined * field_0xe8; // accesses: 1
    undefined4 field_0xec; // accesses: 1
    undefined * field_0xf0; // accesses: 1
    undefined4 field_0xf4; // accesses: 1
    undefined4 field_0xf8; // accesses: 1
    undefined4 field_0xfc; // accesses: 1
    undefined4 field_0x100; // accesses: 1
    undefined4 field_0x104; // accesses: 1
    undefined4 field_0x108; // accesses: 1
    undefined4 field_0x10c; // accesses: 1
    undefined4 field_0x110; // accesses: 1
    undefined * field_0x114; // accesses: 1
    undefined4 field_0x118; // accesses: 1
    undefined4 field_0x11c; // accesses: 1
    undefined4 field_0x120; // accesses: 1
    undefined4 field_0x124; // accesses: 1
    undefined4 field_0x128; // accesses: 1
    undefined4 field_0x12c; // accesses: 1
    undefined * field_0x130; // accesses: 1
    undefined4 field_0x134; // accesses: 1
    undefined4 field_0x138; // accesses: 1
    undefined4 field_0x13c; // accesses: 1
    undefined4 field_0x140; // accesses: 1
    undefined4 field_0x144; // accesses: 1
    undefined4 field_0x148; // accesses: 6
    undefined4 field_0x14c; // accesses: 5
    undefined4 field_0x150; // accesses: 5
    undefined4 field_0x154; // accesses: 5
    undefined4 field_0x158; // accesses: 8
    undefined4 field_0x15c; // accesses: 8
    undefined4 field_0x160; // accesses: 7
    undefined4 field_0x164; // accesses: 6
    undefined4 field_0x168; // accesses: 1
    undefined4 field_0x16c; // accesses: 11
    undefined4 field_0x170; // accesses: 10
    undefined4 field_0x174; // accesses: 1
    undefined4 field_0x178; // accesses: 1
    undefined4 field_0x17c; // accesses: 1
    undefined4 field_0x180; // accesses: 1
    undefined4 field_0x184; // accesses: 1
    undefined4 field_0x188; // accesses: 1
    undefined4 field_0x18c; // accesses: 1
    undefined4 field_0x190; // accesses: 1
    undefined * field_0x194; // accesses: 1
    undefined4 field_0x198; // accesses: 1
    undefined * field_0x19c; // accesses: 1
    undefined4 field_0x1a0; // accesses: 1
    byte _padding_0x1a4[20];
    undefined4 field_0x1b8; // accesses: 2
    undefined4 field_0x1bc; // accesses: 2
    undefined4 field_0x1c0; // accesses: 2
    undefined4 field_0x1c4; // accesses: 2
    undefined4 field_0x1c8; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetAutoOrPresetTM(CSystemConfig *this,CSystemConfig *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SetAutoOrPresetVsk3(CSystemConfig *this,CSystemConfig *param_1);
    int __thiscall GetNetworkIsFireWallTested(CSystemConfig *this,CSystemConfig *param_1);
    int __thiscall ParentalLock_ComputeIsLocked(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall ApplyDynamicPresets(CSystemConfig *this,CSystemConfigDisplay *param_1);
    void __thiscall CSystemConfig(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetAutoOrPresetAll(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultLanguage(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsAdvertising(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsAll(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsAudio(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsDisplay(CSystemConfig *this,CSystemConfigDisplay *param_1);
    void __thiscall SetDefaultsFileTransfer(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsGameCommon(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsInputs(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsLauncherSettings(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsNetwork(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsParentalLock(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsTM(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetDefaultsVsk3(CSystemConfig *this,CSystemConfig *param_1);
    void __thiscall SetNetworkIsFireWallTested(CSystemConfig *this,CSystemConfig *param_1);
};

#endif // CSYSTEMCONFIG_HPP
