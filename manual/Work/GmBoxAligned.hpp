#ifndef GMBOXALIGNED_HPP
#define GMBOXALIGNED_HPP

#include "typedefs.h"
#include "GmVec3.hpp"
#include "GmIso4.hpp"

class CClassicArchive;

// =================================================
// GmBoxAligned
// Axis-Aligned Bounding Box defined by a Center and Extents (Half-Size).
// Size: 24 bytes (6 floats)
// =================================================
class GmBoxAligned {
public:
    GmVec3 center;  // 0x00, 0x04, 0x08
    GmVec3 extents; // 0x0C, 0x10, 0x14

    // Initialization & Setters
    void SetCenterHalfDiag(const GmVec3& c, const GmVec3& h);
    void SetMinMax(const GmVec3& min, const GmVec3& max);
    void SetFromConeAndRadius(const GmIso4& transform, float radius, float height);
    
    // Getters
    GmVec3 GetMin() const;
    void GetMinMax(GmVec3& outMin, GmVec3& outMax) const;
    void GetDiag(GmVec3& outDiag) const;

    // Geometric Tests
    bool IsNull() const;
    bool IsIncluded(const GmBoxAligned& outerBox) const;
    bool TestInter(const GmVec3& point) const;
    
    // Line Segment Intersections (Separating Axis Theorem)
    bool TestInterSegment(const GmVec3& pointA, const GmVec3& pointB) const;
    bool TestInterSegment_MiddleVectAB(const GmVec3& midPoint, const GmVec3& diff) const;

    // Transformations & Boolean Operations
    void SetMult(const GmBoxAligned& other, const GmIso4& mat);
    void Mult(const GmIso4& mat);
    void Union(const GmBoxAligned& other);

    // Serialization
    void ArchiveABox(CClassicArchive* archive);
    void ArchiveABoxOld1(CClassicArchive* archive);
};

#endif // GMBOXALIGNED_HPP