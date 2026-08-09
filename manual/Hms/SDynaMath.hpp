#ifndef SDYNAMATH_HPP
#define SDYNAMATH_HPP

#include "GmMat3.hpp"
#include "GmVec3.hpp"

struct SDynaMath {
    // TmForeverFixed.exe 0x007BD090 is a static seven-argument helper. The
    // caller removes 0x1C bytes after the call; there is no hidden `this`.
    static void ComputeImpulse(
        float mass,
        const GmMat3* inverseInertia,
        float restitution,
        const GmVec3* relativeSpeed,
        const GmVec3* normal,
        const GmVec3* lever,
        GmVec3* impulse);
};

#endif // SDYNAMATH_HPP
