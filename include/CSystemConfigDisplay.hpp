#ifndef CSYSTEMCONFIGDISPLAY_HPP
#define CSYSTEMCONFIGDISPLAY_HPP

#include "typedefs.h"

struct CSystemConfigDisplay {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 2
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 2
    undefined4 field_0x1c; // accesses: 2
    undefined4 field_0x20; // accesses: 2
    undefined4 field_0x24; // accesses: 2
    undefined4 field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 2
    undefined4 field_0x30; // accesses: 2
    undefined4 field_0x34; // accesses: 3
    undefined4 field_0x38; // accesses: 3
    undefined4 field_0x3c; // accesses: 3
    undefined4 field_0x40; // accesses: 7
    undefined4 field_0x44; // accesses: 6
    undefined4 field_0x48; // accesses: 10
    undefined4 field_0x4c; // accesses: 16
    undefined4 field_0x50; // accesses: 4
    undefined4 field_0x54; // accesses: 16
    undefined4 field_0x58; // accesses: 3
    undefined4 field_0x5c; // accesses: 12
    undefined4 field_0x60; // accesses: 9
    undefined4 field_0x64; // accesses: 8
    undefined4 field_0x68; // accesses: 13
    undefined4 field_0x6c; // accesses: 7
    undefined4 field_0x70; // accesses: 7
    undefined4 field_0x74; // accesses: 7
    undefined4 field_0x78; // accesses: 14
    undefined4 field_0x7c; // accesses: 10
    undefined4 field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 11
    undefined4 field_0x88; // accesses: 2
    undefined4 field_0x8c; // accesses: 3
    undefined4 field_0x90; // accesses: 3
    undefined4 field_0x94; // accesses: 3
    undefined4 field_0x98; // accesses: 3
    undefined4 field_0x9c; // accesses: 2
    undefined4 field_0xa0; // accesses: 2
    undefined4 field_0xa4; // accesses: 3
    undefined4 field_0xa8; // accesses: 3
    undefined4 field_0xac; // accesses: 4
    undefined4 field_0xb0; // accesses: 3
    undefined4 field_0xb4; // accesses: 3
    undefined4 field_0xb8; // accesses: 3
    undefined4 field_0xbc; // accesses: 3
    undefined4 field_0xc0; // accesses: 3
    undefined4 field_0xc4; // accesses: 3
    undefined4 field_0xc8; // accesses: 4
    undefined4 field_0xcc; // accesses: 5
    undefined4 field_0xd0; // accesses: 1
    undefined4 field_0xd4; // accesses: 22

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall MultiThreadGetScale(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall Tweak_NVidia_C51(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeAutoQuality(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeHighestResolutionFS (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall InternalApplyPreset (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,EPreset param_2);
    int __thiscall IsGraphicAdpaterMain_NVidia_C51 (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    int __thiscall WaterGeom(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    ulong __thiscall MultiThreadGetThreadCount (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    void __thiscall ApplyDynamicPresets(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    void __thiscall CSystemConfigDisplay(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    void __thiscall LowFpsReset(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    void __thiscall SetDefaultsDisplay(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1);
    void __thiscall SetPreset (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,EPreset param_2);
    void __thiscall SetSafeValues (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,int param_2,GmNat2 *param_3);
};

#endif // CSYSTEMCONFIGDISPLAY_HPP
