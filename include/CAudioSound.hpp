#ifndef CAUDIOSOUND_HPP
#define CAUDIOSOUND_HPP

#include "typedefs.h"

struct CAudioPort;
struct CMwNod;
struct ulong;

struct CAudioSound {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    undefined4 field_0x14; // accesses: 2
    undefined4 field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 1
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    undefined4 field_0x28; // accesses: 1
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 1
    undefined4 field_0x38; // accesses: 1
    undefined4 field_0x3c; // accesses: 1
    undefined4 field_0x40; // accesses: 1
    CAudioPort * field_0x44; // accesses: 4
    uint field_0x48; // accesses: 1
    undefined4 field_0x4c; // accesses: 1
    ulong field_0x50; // accesses: 6
    undefined4 field_0x54; // accesses: 3
    undefined4 field_0x58; // accesses: 1
    undefined4 field_0x5c; // accesses: 1
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    undefined4 field_0x6c; // accesses: 1
    undefined4 field_0x70; // accesses: 1
    int * field_0x74; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CAudioSound (CAudioSound *this,CAudioSound *param_1,CPlugSound *param_2,CAudioPort *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall Stop(CAudioSound *this,STmRaceLowFps *param_1);
    void __thiscall Play(CAudioSound *this,CPlugFileVideo *param_1,EPlugVideoTimer param_2,int param_3, ulong param_4);
};

#endif // CAUDIOSOUND_HPP
