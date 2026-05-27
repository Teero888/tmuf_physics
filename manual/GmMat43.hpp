#ifndef GMMAT43_HPP
#define GMMAT43_HPP

#include "GmVec4.hpp"

class GmIso4;

// GmMat43 is a 4-column, 3-row matrix (48 bytes) used to pack an 
// affine transformation into three hardware-ready 4D vectors.
class GmMat43 {
public:
    GmVec4 row0; // 0x00 - 0x0F
    GmVec4 row1; // 0x10 - 0x1F
    GmVec4 row2; // 0x20 - 0x2F

    // Member Functions
    void Set(const GmIso4& iso);
    void SetIdentity();
};

#endif // GMMAT43_HPP