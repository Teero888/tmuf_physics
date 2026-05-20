#ifndef SDYNAMATH_HPP
#define SDYNAMATH_HPP

#include "typedefs.h"

struct SDynaMath {
    byte _padding_0x0[4];
    float field_0x4; // accesses: 12
    float field_0x8; // accesses: 12

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeImpulse (void *this,CSceneVehicleSpeedBoat *param_1,float param_2,GmMat3 *param_3,float param_4, GmVec3 *param_5,GmVec3 *param_6,GmVec3 *param_7,GmVec3 *param_8);
};

#endif // SDYNAMATH_HPP
