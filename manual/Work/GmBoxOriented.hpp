#ifndef GMBOXORIENTED_HPP
#define GMBOXORIENTED_HPP

#include "typedefs.h"
#include "GmMat3.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"

// =================================================
// GmBoxOriented
// Represents an Oriented Bounding Box (OBB).
// Size: 64 bytes (0x40)
// =================================================
class GmBoxOriented {
public:
    GmMat3 axes;    // 0x00 - 0x23 (Orthogonal axis vectors)
    GmVec3 center;  // 0x24 - 0x2F (Center point in world/local space)
    GmVec3 extents; // 0x30 - 0x3B (Half-sizes along each axis)
    float _padding; // 0x3C - 0x3F (Alignment padding)

    // Member Functions
    void Mult(const GmIso4& mat);
};

#endif // GMBOXORIENTED_HPP