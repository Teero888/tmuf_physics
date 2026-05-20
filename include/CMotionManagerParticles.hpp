#ifndef CMOTIONMANAGERPARTICLES_HPP
#define CMOTIONMANAGERPARTICLES_HPP

#include "typedefs.h"

struct CSceneMobil;

struct CMotionManagerParticles {
    struct SEmitParams {
        void** vftable;
        byte _padding_0x4[44];
        undefined4 field_0x30; // accesses: 1
        undefined4 field_0x34; // accesses: 1
        undefined4 field_0x38; // accesses: 1
        undefined4 field_0x3c; // accesses: 1
        undefined4 field_0x40; // accesses: 1
        undefined4 field_0x44; // accesses: 1
        undefined4 field_0x48; // accesses: 1
        undefined4 field_0x4c; // accesses: 1
        undefined4 field_0x50; // accesses: 1
        undefined4 field_0x54; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    void** vftable;
    byte _padding_0x4[24];
    CSceneMobil * field_0x1c; // accesses: 2
    byte _padding_0x20[4];
    int field_0x24; // accesses: 1
    byte _final_padding[0x1c]; // Total size: 0x44

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
