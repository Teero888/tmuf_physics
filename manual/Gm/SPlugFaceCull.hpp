#ifndef SPLUGFACECULL_HPP
#define SPLUGFACECULL_HPP

#include "GmVec3.hpp"
#include "GmIso4.hpp"

// SPlugFaceCull contains an array of exactly 2 culling primitives
struct SPlugFaceCull {
    struct CullElement {
        GmVec3 center; // 0x00 - 0x0B (Point: Transformed by rotation + translation)
        GmVec3 axis;   // 0x0C - 0x17 (Vector: Transformed by rotation only)
        float scalar;  // 0x18 - 0x1B (Float: Copied directly, likely an extent/radius)
    };

    CullElement elements[2]; // 0x00 - 0x37 (56 bytes total)

    // Member Functions
    void SetMult(const SPlugFaceCull& other, const GmIso4& mat);
};

#endif // SPLUGFACECULL_HPP