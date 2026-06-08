#include "GmBoxAligned.hpp"
#include "CClassicArchive.hpp"
#include <cmath>

// Engine constants extracted from assembly
const float HALF = 0.5f; // _DAT_00b313b8
const float TWO = 2.0f;  // _DAT_00b33a58
const float EPSILON = 0.00001f; // _PTR_00b2c178

// =================================================
// Initialization & Setters
// =================================================

void GmBoxAligned::SetCenterHalfDiag(const GmVec3& c, const GmVec3& h) {
    center = c;
    extents = h;
}

void GmBoxAligned::SetMinMax(const GmVec3& min, const GmVec3& max) {
    center.x = (min.x + max.x) * HALF;
    center.y = (min.y + max.y) * HALF;
    center.z = (min.z + max.z) * HALF;

    extents.x = (max.x - min.x) * HALF;
    extents.y = (max.y - min.y) * HALF;
    extents.z = (max.z - min.z) * HALF;
}

void GmBoxAligned::SetFromConeAndRadius(const GmIso4& transform, float radius, float height) {
    // Note: Recreated exactly from the raw pointer arithmetic in the Ghidra output.
    // This calculates a tight AABB around a transformed cone.
    float fVar1 = transform.m20; // +0x18 in GmIso4
    
    // func_0x009c1b40 is likely a fast inverse square root or similar math utility.
    // Placeholder function to maintain the 1:1 math structure.
    extern float MathUtility_9c1b40(); 
    
    float fVar11 = MathUtility_9c1b40();
    
    float stack_18[6];
    const float* matPtr = &transform.m10; // param_1 + 0x0C
    
    for (int i = 0; i < 3; ++i) { // Loop mapped from uVar10 = 0 to 0xC (3 iterations, 4 bytes each)
        float fVar2 = *matPtr;
        float fVar12 = MathUtility_9c1b40();
        
        float posExt = radius;
        if (fVar2 <= fVar1) {
            float fVar3 = fVar2 * fVar1 + fVar12 * fVar11;
            if (fVar3 < EPSILON && fVar3 != EPSILON) fVar3 = 0.0f;
            posExt = fVar3 * radius;
        }
        stack_18[i + 3] = posExt; // +0x0C offset in the array
        
        float negExt = -radius;
        if (-fVar2 <= fVar1) {
            fVar2 = fVar12 * fVar11 - fVar2 * fVar1;
            if (fVar2 < EPSILON && fVar2 != EPSILON) fVar2 = 0.0f;
            negExt = -radius * fVar2;
        }
        stack_18[i] = negExt;
        
        matPtr++;
    }
    
    float minX = transform.m00 + stack_18[0];
    float minY = transform.m01 + stack_18[1];
    float minZ = transform.m02 + stack_18[2];
    
    float maxX = transform.m00 + stack_18[3];
    float maxY = transform.m01 + stack_18[4];
    float maxZ = transform.m02 + stack_18[5];
    
    center.x = (minX + maxX) * HALF;
    center.y = (minY + maxY) * HALF;
    center.z = (minZ + maxZ) * HALF;
    
    extents.x = (maxX - minX) * HALF;
    extents.y = (maxY - minY) * HALF;
    extents.z = (maxZ - minZ) * HALF;
}

// =================================================
// Getters
// =================================================

GmVec3 GmBoxAligned::GetMin() const {
    return {
        center.x - extents.x,
        center.y - extents.y,
        center.z - extents.z
    };
}

void GmBoxAligned::GetMinMax(GmVec3& outMin, GmVec3& outMax) const {
    outMin.x = center.x - extents.x;
    outMin.y = center.y - extents.y;
    outMin.z = center.z - extents.z;
    
    outMax.x = center.x + extents.x;
    outMax.y = center.y + extents.y;
    outMax.z = center.z + extents.z;
}

void GmBoxAligned::GetDiag(GmVec3& outDiag) const {
    outDiag.x = extents.x * TWO;
    outDiag.y = extents.y * TWO;
    outDiag.z = extents.z * TWO;
}

// =================================================
// Geometric Tests
// =================================================

bool GmBoxAligned::IsNull() const {
    return extents.x < 0.0f;
}

bool GmBoxAligned::IsIncluded(const GmBoxAligned& outerBox) const {
    GmVec3 innerMin = GetMin();
    GmVec3 innerMax = { center.x + extents.x, center.y + extents.y, center.z + extents.z };
    
    GmVec3 outerMin = outerBox.GetMin();
    GmVec3 outerMax = { outerBox.center.x + outerBox.extents.x, outerBox.center.y + outerBox.extents.y, outerBox.center.z + outerBox.extents.z };

    if (innerMax.z <= outerMax.z && innerMin.z >= outerMin.z &&
        innerMax.x <= outerMax.x && innerMin.x >= outerMin.x &&
        innerMax.y <= outerMax.y && innerMin.y >= outerMin.y) {
        return true;
    }
    return false;
}

bool GmBoxAligned::TestInter(const GmVec3& point) const {
    if (std::abs(point.x - center.x) <= extents.x) {
        if (std::abs(point.y - center.y) <= extents.y) {
            if (std::abs(point.z - center.z) <= extents.z) {
                return true;
            }
        }
    }
    return false;
}

bool GmBoxAligned::TestInterSegment(const GmVec3& pointA, const GmVec3& pointB) const {
    GmVec3 diff = {
        pointB.x - pointA.x,
        pointB.y - pointA.y,
        pointB.z - pointA.z
    };
    
    GmVec3 midPoint = {
        (pointA.x + pointB.x) * HALF,
        (pointA.y + pointB.y) * HALF,
        (pointA.z + pointB.z) * HALF
    };
    
    return TestInterSegment_MiddleVectAB(midPoint, diff);
}

bool GmBoxAligned::TestInterSegment_MiddleVectAB(const GmVec3& midPoint, const GmVec3& diff) const {
    // Standard Separating Axis Theorem (SAT) for AABB vs Line Segment
    float fVar1 = center.x - midPoint.x;
    float fVar2 = center.y - midPoint.y;
    float fVar3 = center.z - midPoint.z;
    
    float absDiffX = std::abs(diff.x);
    float absDiffY = std::abs(diff.y);
    float absDiffZ = std::abs(diff.z);

    // Test axes: X, Y, Z
    if (std::abs(fVar1) <= extents.x + absDiffX * HALF &&
        std::abs(fVar2) <= extents.y + absDiffY * HALF &&
        std::abs(fVar3) <= extents.z + absDiffZ * HALF) 
    {
        // Test Cross-Product axes
        if (std::abs(diff.z * fVar2 - diff.y * fVar3) <= extents.y * absDiffZ + extents.z * absDiffY &&
            std::abs(fVar3 * diff.x - fVar1 * diff.z) <= extents.x * absDiffZ + extents.z * absDiffX &&
            std::abs(fVar1 * diff.y - diff.x * fVar2) <= extents.x * absDiffY + extents.y * absDiffX) 
        {
            return true;
        }
    }
    return false;
}

// =================================================
// Transformations & Boolean Operations
// =================================================

void GmBoxAligned::SetMult(const GmBoxAligned& other, const GmIso4& mat) {
    // 1. Transform Center
    center.x = mat.m00 * other.center.x + mat.m01 * other.center.y + mat.m02 * other.center.z + mat.tX;
    center.y = mat.m10 * other.center.x + mat.m11 * other.center.y + mat.m12 * other.center.z + mat.tY;
    center.z = mat.m20 * other.center.x + mat.m21 * other.center.y + mat.m22 * other.center.z + mat.tZ;

    // 2. Transform Extents (Uses absolute values of rotation matrix to maximize bounding box)
    extents.x = std::abs(mat.m00) * other.extents.x + std::abs(mat.m01) * other.extents.y + std::abs(mat.m02) * other.extents.z;
    extents.y = std::abs(mat.m10) * other.extents.x + std::abs(mat.m11) * other.extents.y + std::abs(mat.m12) * other.extents.z;
    extents.z = std::abs(mat.m20) * other.extents.x + std::abs(mat.m21) * other.extents.y + std::abs(mat.m22) * other.extents.z;
}

void GmBoxAligned::Mult(const GmIso4& mat) {
    SetMult(*this, mat);
}

void GmBoxAligned::Union(const GmBoxAligned& other) {
    // If this box is empty, just copy the other one
    if (extents.x < 0.0f) {
        *this = other;
        return;
    }
    
    // If the other box is not empty, compute the union
    if (other.extents.x >= 0.0f) {
        GmVec3 min1 = GetMin();
        GmVec3 max1 = { center.x + extents.x, center.y + extents.y, center.z + extents.z };
        
        GmVec3 min2 = other.GetMin();
        GmVec3 max2 = { other.center.x + other.extents.x, other.center.y + other.extents.y, other.center.z + other.extents.z };

        GmVec3 finalMin, finalMax;

        finalMin.x = std::min(min1.x, min2.x);
        finalMin.y = std::min(min1.y, min2.y);
        finalMin.z = std::min(min1.z, min2.z);

        finalMax.x = std::max(max1.x, max2.x);
        finalMax.y = std::max(max1.y, max2.y);
        finalMax.z = std::max(max1.z, max2.z);

        SetMinMax(finalMin, finalMax);
    }
}

// =================================================
// Serialization
// =================================================

void GmBoxAligned::ArchiveABox(CClassicArchive* archive) {
    archive->DoReal(&center.x, 1);
    archive->DoReal(&center.y, 1);
    archive->DoReal(&center.z, 1);
    archive->DoReal(&extents.x, 1);
    archive->DoReal(&extents.y, 1);
    archive->DoReal(&extents.z, 1);
}

void GmBoxAligned::ArchiveABoxOld1(CClassicArchive* archive) {
    GmVec3 min = GetMin();
    GmVec3 max = { center.x + extents.x, center.y + extents.y, center.z + extents.z };

    archive->DoReal(&min.x, 1);
    archive->DoReal(&min.y, 1);
    archive->DoReal(&min.z, 1);
    archive->DoReal(&max.x, 1);
    archive->DoReal(&max.y, 1);
    archive->DoReal(&max.z, 1);
    
    if (!archive->m_isWriting) {
        SetMinMax(min, max);
    }
}

void GmBoxAligned::InitEmpty() {
    this->center = GmVec3{0, 0, 0};
    this->extents = GmVec3{-1e30f, -1e30f, -1e30f}; // Indicates empty
}

void GmBoxAligned::Union(GmBoxAligned* out, const GmBoxAligned* a, const GmBoxAligned* b) {
    GmVec3 minA = {a->center.x - a->extents.x, a->center.y - a->extents.y, a->center.z - a->extents.z};
    GmVec3 maxA = {a->center.x + a->extents.x, a->center.y + a->extents.y, a->center.z + a->extents.z};
    GmVec3 minB = {b->center.x - b->extents.x, b->center.y - b->extents.y, b->center.z - b->extents.z};
    GmVec3 maxB = {b->center.x + b->extents.x, b->center.y + b->extents.y, b->center.z + b->extents.z};
    
    GmVec3 minOut = {
        minA.x < minB.x ? minA.x : minB.x,
        minA.y < minB.y ? minA.y : minB.y,
        minA.z < minB.z ? minA.z : minB.z
    };
    GmVec3 maxOut = {
        maxA.x > maxB.x ? maxA.x : maxB.x,
        maxA.y > maxB.y ? maxA.y : maxB.y,
        maxA.z > maxB.z ? maxA.z : maxB.z
    };
    out->SetMinMax(minOut, maxOut);
}


void GmBoxAligned::Subdivide8(GmBoxAligned octants[8]) const {
    // Dummy stub
}

void GmBoxAligned::Subdivide2(GmBoxAligned childBoxes[2]) const {
    // Dummy stub
}

bool GmBoxAligned::TestInter(class NvFaceInfo* face, void* arg2, const GmBoxAligned* box, const GmIso4* transform) {
    // Dummy stub
    return true;
}

void GmBoxAligned::Union(const GmVec3& point) {
    if (IsNull()) {
        center = point;
        extents = GmVec3(0,0,0);
        return;
    }
    GmVec3 minV = center - extents;
    GmVec3 maxV = center + extents;
    if (point.x < minV.x) minV.x = point.x;
    if (point.y < minV.y) minV.y = point.y;
    if (point.z < minV.z) minV.z = point.z;
    if (point.x > maxV.x) maxV.x = point.x;
    if (point.y > maxV.y) maxV.y = point.y;
    if (point.z > maxV.z) maxV.z = point.z;
    center = (minV + maxV) * 0.5f;
    extents = (maxV - minV) * 0.5f;
}
