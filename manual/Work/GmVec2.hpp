#ifndef GMVEC2_HPP
#define GMVEC2_HPP

#include <cmath>
#include "CClassicArchive.hpp" // Now using the real definition

struct GmIso3; // 3x3 or Affine matrix

struct GmVec2 {
    float x; // field_0x0
    float y; // field_0x4

    // Serialization
    void ArchiveGmVec2(CClassicArchive& archive);

    // Basic Math
    float GetLength() const;
    void Normalize();
    bool IsNearlyEqual(const GmVec2& other, float epsilon = 1e-6f) const;
    
    // Interpolation
    void SetBlend(const GmVec2& v1, const GmVec2& v2, float t);
    void SetBlendTri(const GmVec2& v0, const GmVec2& v1, const GmVec2& v2, float u, float v);

    // Matrix Math
    void Mult(const GmIso3& mat);
    void SetMultInverse(const GmVec2& v, const GmIso3& mat);

    // Geometric Testing
    static bool IsInTriangle(const GmVec2& v0, const GmVec2& v1, const GmVec2& v2, 
                             const GmVec2& p, float& outU, float& outV, int* outIsInside);
};

#endif // GMVEC2_HPP