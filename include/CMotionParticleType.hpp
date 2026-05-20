#ifndef CMOTIONPARTICLETYPE_HPP
#define CMOTIONPARTICLETYPE_HPP

#include "typedefs.h"

struct ulong;

struct CMotionParticleType {
    byte _padding_0x0[36];
    int field_0x24; // accesses: 1
    byte _padding_0x28[288];
    ulong field_0x148; // accesses: 1
    byte _padding_0x14c[4];
    float field_0x150; // accesses: 1
    float field_0x154; // accesses: 1
    byte _padding_0x158[16];
    float field_0x168; // accesses: 1
    float field_0x16c; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall GenerateSplashPart (CMotionParticleType *this,CMotionParticleType *param_1,ulong param_2,GmVec3 *param_3, GmVec3 *param_4);
    ulong __thiscall GetVertPerPartCount(CMotionParticleType *this,CMotionParticleType *param_1);
};

#endif // CMOTIONPARTICLETYPE_HPP
