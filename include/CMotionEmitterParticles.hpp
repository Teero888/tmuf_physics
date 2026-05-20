#ifndef CMOTIONEMITTERPARTICLES_HPP
#define CMOTIONEMITTERPARTICLES_HPP

#include "typedefs.h"

struct CMwNod;
struct CSceneObjectLink;

struct CMotionEmitterParticles {
    byte _padding_0x0[124];
    undefined4 field_0x7c; // accesses: 1
    CMotionEmitterParticles * field_0x80; // accesses: 2
    undefined4 field_0x84; // accesses: 1
    undefined4 field_0x88; // accesses: 5
    CSceneObjectLink * field_0x8c; // accesses: 2

    // Member Functions
    void __thiscall CMotionEmitterParticles (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1);
    void __thiscall SetEmitterModel (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1, CMotionParticleEmitterModel *param_2);
    void __thiscall SetIsActive (CMotionEmitterParticles *this,CSceneObjectLink *param_1,int param_2);
    void __thiscall SetIsEventMode (CMotionEmitterParticles *this,CMotionEmitterParticles *param_1,int param_2);
};

#endif // CMOTIONEMITTERPARTICLES_HPP
