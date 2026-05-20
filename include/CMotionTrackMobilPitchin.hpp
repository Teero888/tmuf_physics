#ifndef CMOTIONTRACKMOBILPITCHIN_HPP
#define CMOTIONTRACKMOBILPITCHIN_HPP

#include "typedefs.h"

struct CPlugAudio;
struct GmMat2;

struct CMotionTrackMobilPitchin {
    byte _padding_0x0[8];
    float field_0x8; // accesses: 1
    float field_0xc; // accesses: 1
    byte _padding_0x10[4];
    CPlugAudio * field_0x14; // accesses: 1
    byte _padding_0x18[12];
    undefined4 field_0x24; // accesses: 1
    float field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 1
    byte _padding_0x30[36];
    float field_0x54; // accesses: 2
    byte _padding_0x58[12];
    float field_0x64; // accesses: 4
    float field_0x68; // accesses: 4
    float field_0x6c; // accesses: 3
    undefined4 field_0x70; // accesses: 2
    float field_0x74; // accesses: 2
    undefined4 field_0x78; // accesses: 2
    undefined4 field_0x7c; // accesses: 2
    float field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 2
    GmMat2 * field_0x88; // accesses: 1
    float field_0x8c; // accesses: 2
    byte _padding_0x90[20];
    float field_0xa4; // accesses: 4
    float field_0xa8; // accesses: 1
    float field_0xac; // accesses: 3
    float field_0xb0; // accesses: 3
    uint field_0xb4; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeAngleAndMoyenne (CMotionTrackMobilPitchin *this,CMotionTrackMobilPitchin *param_1,float *param_2, float *param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputePitchinLocation (CMotionTrackMobilPitchin *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3);
};

#endif // CMOTIONTRACKMOBILPITCHIN_HPP
