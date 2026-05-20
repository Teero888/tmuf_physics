#ifndef CSCENETOYROCK_HPP
#define CSCENETOYROCK_HPP

#include "typedefs.h"

struct CMotionEmitterParticles;
struct CPlugAudio;
struct CSceneToySea;
struct CSceneToySeaHouleTable;

struct CSceneToyRock {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 3
    byte _padding_0x18[12];
    CSceneToySeaHouleTable * field_0x24; // accesses: 2
    float field_0x28; // accesses: 3
    float field_0x2c; // accesses: 2
    byte _padding_0x30[8];
    float field_0x38; // accesses: 2
    byte _padding_0x3c[8];
    float field_0x44; // accesses: 2
    byte _padding_0x48[24];
    undefined4 field_0x60; // accesses: 1
    undefined4 field_0x64; // accesses: 1
    undefined4 field_0x68; // accesses: 1
    int field_0x6c; // accesses: 1
    int field_0x70; // accesses: 5
    byte _padding_0x74[4];
    CSceneToySea * field_0x78; // accesses: 4
    float field_0x7c; // accesses: 2
    float field_0x80; // accesses: 5
    float field_0x84; // accesses: 2
    float field_0x88; // accesses: 3
    float field_0x8c; // accesses: 2
    float field_0x90; // accesses: 1
    float field_0x94; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall UpdateAsync(CSceneToyRock *this,CInputPortDx8 *param_1);
};

#endif // CSCENETOYROCK_HPP
