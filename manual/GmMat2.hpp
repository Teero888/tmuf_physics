#ifndef GMMAT2_HPP
#define GMMAT2_HPP

#include <cmath>

// =================================================
// GmMat2 (2x2 Matrix)
// =================================================
struct GmMat2 {
    float m00; // Offset 0x0
    float m01; // Offset 0x4
    float m10; // Offset 0x8
    float m11; // Offset 0xC

    // Member Functions
    void Mult(const GmMat2& other);
    void Rotate(float angle);
    void SetIdentity();
    void SetMult(const GmMat2& a, const GmMat2& b);
    void SetRotation(float angle);
    void SetTranspose(const GmMat2& other);
};

#endif // GMMAT2_HPP