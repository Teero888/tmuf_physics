#ifndef CMOTIONMANAGERPARTICLES_HPP
#define CMOTIONMANAGERPARTICLES_HPP

#include "typedefs.h"

struct CMotionEmitterParticles;
struct CMotionParticleType;
struct CPlugAudio;
struct CPlugVisual;
struct CPlugVisualIndexedLines;
struct CPlugVisualSprite;
struct CSceneMobil;
struct GmIso3;
struct GmVec3;
struct TiXmlAttribute;

struct CMotionManagerParticles {
    struct SEmitParams {

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 53
    undefined4 field_0x8; // accesses: 42
    undefined4 field_0xc; // accesses: 24
    int field_0x10; // accesses: 2
    CPlugVisualSprite * field_0x14; // accesses: 17
    undefined4 field_0x18; // accesses: 16
    undefined4 field_0x1c; // accesses: 15
    undefined4 field_0x20; // accesses: 15
    GmIso3 * field_0x24; // accesses: 18
    float field_0x28; // accesses: 6
    SCasterCat * field_0x2c; // accesses: 7
    float field_0x30; // accesses: 5
    undefined4 field_0x34; // accesses: 10
    undefined4 field_0x38; // accesses: 13
    undefined4 field_0x3c; // accesses: 17
    undefined4 field_0x40; // accesses: 10
    undefined4 field_0x44; // accesses: 2
    undefined4 field_0x48; // accesses: 2
    byte _padding_0x4c[4];
    void * field_0x50; // accesses: 3
    byte _padding_0x54[4];
    float field_0x58; // accesses: 2
    undefined4 field_0x5c; // accesses: 3
    undefined4 field_0x60; // accesses: 3
    float field_0x64; // accesses: 1
    byte _padding_0x68[4];
    float field_0x6c; // accesses: 1
    float field_0x70; // accesses: 2
    float field_0x74; // accesses: 1
    byte _padding_0x78[4];
    SPartState * field_0x7c; // accesses: 5
    undefined4 field_0x80; // accesses: 10
    undefined4 field_0x84; // accesses: 5
    undefined4 field_0x88; // accesses: 5
    undefined4 field_0x8c; // accesses: 4
    TiXmlAttribute * field_0x90; // accesses: 4
    byte _padding_0x94[4];
    int field_0x98; // accesses: 5
    uint field_0x9c; // accesses: 7
    byte _padding_0xa0[4];
    undefined4 field_0xa4; // accesses: 2
    undefined4 field_0xa8; // accesses: 2
    byte _padding_0xac[16];
    float field_0xbc; // accesses: 1
    float field_0xc0; // accesses: 1
    byte _padding_0xc4[136];
    int field_0x14c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ int __thiscall GroupUpdateParticles (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupEmitParticles (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateMultiState (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateMultistateLightTrail (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateMultistateWaterSplash (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateStandardLinesSpeedCamera (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateStandardQuadCamera (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateStandardQuadSpeed (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GroupUpdateStandardWaterSplash (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3,GmVec3 *param_4,GmVec3 *param_5,ulong *param_6);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall PartInit (CMotionManagerParticles *this,CMotionManagerParticles *param_1,SPart *param_2, CMotionParticleType *param_3,ulong param_4,SEmitParams *param_5);
    void __thiscall EmitterGetEmitParamsAsync (CMotionManagerParticles *this,CMotionManagerParticles *param_1, CMotionEmitterParticles *param_2,SEmitParams *param_3);
    void __thiscall GroupKillParticle (CMotionManagerParticles *this,CMotionManagerParticles *param_1,ulong param_2, ulong param_3);
    void __thiscall UpdateAsync(CMotionManagerParticles *this,CInputPortDx8 *param_1);
};

#endif // CMOTIONMANAGERPARTICLES_HPP
