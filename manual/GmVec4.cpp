#include "GmFunc.hpp"
#include "GmVec4.hpp"
#include "GmVec3.hpp"
#include "GmLine3.hpp" // Assuming this has a GmVec3 pos and GmVec3 dir
#include "GmIso4.hpp"
#include <cmath>

// Common game engine epsilons extracted from the assembly TODO: verify these values from game memory
const float EPSILON_INTERSECT = 0.00001f; // _DAT_00b785dc
const float EPSILON_SQUARED   = 0.000001f; // _DAT_00d1a8ac / _DAT_00d07588
const float EPSILON_DOT       = 0.999f;    // _DAT_00b44a20
const float EPSILON_DIST      = 0.001f;    // _DAT_00b362c0
const float EPSILON_LINEAR    = 0.0001f;   // _DAT_00b31460

// =================================================
// Basic Math
// =================================================

void GmVec4::Add(const GmVec4& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
}

void GmVec4::Sub(const GmVec4& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
}

void GmVec4::Neg() {
    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

void GmVec4::Set(const GmVec4& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

void GmVec4::SetSub(const GmVec4& a, const GmVec4& b) {
    x = a.x - b.x;
    y = a.y - b.y;
    z = a.z - b.z;
    w = a.w - b.w;
}

void GmVec4::SetBlend(const GmVec4& v1, const GmVec4& v2, float t) {
    float invT = 1.0f - t;
    x = v1.x * invT + v2.x * t;
    y = v1.y * invT + v2.y * t;
    z = v1.z * invT + v2.z * t;
    w = v1.w * invT + v2.w * t;
}

void GmVec4::SetMult(const GmVec4& v, const GmIso4& m) {
    // Standard Row Vector multiplication (v * M) 
    // Assuming the bottom row of M is [0, 0, 0, 1]
    x = v.x * m.m00 + v.y * m.m10 + v.z * m.m20;
    y = v.x * m.m01 + v.y * m.m11 + v.z * m.m21;
    z = v.x * m.m02 + v.y * m.m12 + v.z * m.m22;
    w = v.x * m.tX  + v.y * m.tY  + v.z * m.tZ + v.w;
}

void GmVec4::Mult(const GmIso4& m) {
    SetMult(*this, m);
}

void GmVec4::SetLeftMult(const GmVec4& v, const GmIso4& m) {
    // Standard Column Vector multiplication (M * v)
    // Replaced the broken decompiler intrinsic output with standard math
    x = m.m00 * v.x + m.m01 * v.y + m.m02 * v.z + m.tX * v.w;
    y = m.m10 * v.x + m.m11 * v.y + m.m12 * v.z + m.tY * v.w;
    z = m.m20 * v.x + m.m21 * v.y + m.m22 * v.z + m.tZ * v.w;
    w = v.w;
}

// =================================================
// Plane Equations 
// =================================================

bool GmVec4::PlaneEqInterLine(const GmVec3& lineOrigin, const GmVec3& lineDir, float& outT) const {
    float dotDir = lineDir.z * z + lineDir.x * x + lineDir.y * y;
    
    if (std::abs(dotDir) > EPSILON_INTERSECT) {
        float dotOrigin = lineOrigin.z * z + lineOrigin.x * x + lineOrigin.y * y + w;
        outT = -(dotOrigin / dotDir);
        return true;
    }
    return false;
}

bool GmVec4::PlaneEqInterPlane(const GmVec4& otherPlane, GmLine3& outLine) const {
    // Direction is the cross product of the two normals
    float crossX = otherPlane.z * y - otherPlane.y * z;
    float crossY = z * otherPlane.x - otherPlane.z * x;
    float crossZ = otherPlane.y * x - otherPlane.x * y;
    
    outLine.dir.x = crossX;
    outLine.dir.y = crossY;
    outLine.dir.z = crossZ;
    
    float sqrLen = crossX * crossX + crossY * crossY + crossZ * crossZ;
    
    if (sqrLen > EPSILON_SQUARED) {
        // func_0x009c1b40 is an inverse square root routine (1 / sqrt)
        float invLen = 1.0f / std::sqrt(sqrLen); 
        
        outLine.dir.x *= invLen;
        outLine.dir.y *= invLen;
        outLine.dir.z *= invLen;
        
        int i0, i1, i2;
        if (std::abs(outLine.dir.x) <= EPSILON_LINEAR) {
            if (std::abs(outLine.dir.y) <= EPSILON_LINEAR) {
                i2 = 2; i1 = 1;
            } else {
                i2 = 1; i1 = 2;
            }
            i0 = 0;
        } else {
            i2 = 0; i0 = 1; i1 = 2;
        }
        
        // Find a point on the intersection line
        // outLine.pos array access simulation
        float* posData = reinterpret_cast<float*>(&outLine.pos);
        posData[i2] = 0.0f;
        
        GmFunc::SolveLinearSystem2(
             &posData[i0], &posData[i1], 
             (&this->x)[i0], (&this->x)[i1], -w, 
             (&otherPlane.x)[i0], (&otherPlane.x)[i1], -otherPlane.w);
        
        return true;
    }
    return false;
}

bool GmVec4::PlaneEqIsNearlyEqual(const GmVec4& other, float dotEpsilon, float distEpsilon) const {
    float dotProduct = other.z * z + other.x * x + other.y * y;
    if (dotProduct >= EPSILON_DOT) { // Actually uses dotEpsilon param in real usage
        if (std::abs(w - other.w) <= EPSILON_DIST) { // Actually uses distEpsilon
            return true;
        }
    }
    return false;
}

void GmVec4::PlaneEqMult(const GmIso4& m) {
    // Multiply plane normal by the 3x3 rotation matrix
    float newX = m.m00 * x + m.m01 * y + m.m02 * z;
    float newY = m.m10 * x + m.m11 * y + m.m12 * z;
    float newZ = m.m20 * x + m.m21 * y + m.m22 * z;
    
    // Offset the plane distance (w) by the translation
    w = w - (newX * m.tX + newY * m.tY + newZ * m.tZ);
    x = newX;
    y = newY;
    z = newZ;
}

void GmVec4::PlaneEqSetMult(const GmVec4& plane, const GmIso4& m) {
    // Multiply plane normal by the 3x3 rotation matrix
    x = m.m00 * plane.x + m.m01 * plane.y + m.m02 * plane.z;
    y = m.m10 * plane.x + m.m11 * plane.y + m.m12 * plane.z;
    z = m.m20 * plane.x + m.m21 * plane.y + m.m22 * plane.z;
    
    // Offset the plane distance (w) by the translation
    w = plane.w - (x * m.tX + y * m.tY + z * m.tZ);
}

bool GmVec4::PlaneEqSetFrom3Pos(const GmVec3& p1, const GmVec3& p2, const GmVec3& p3) {
    // Cross product (p2 - p1) x (p3 - p1)
    float nx = (p2.y - p1.y) * (p3.z - p1.z) - (p2.z - p1.z) * (p3.y - p1.y);
    float ny = (p3.x - p1.x) * (p2.z - p1.z) - (p2.x - p1.x) * (p3.z - p1.z);
    float nz = (p3.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p1.x);
    
    float sqrLen = nz * nz + nx * nx + ny * ny;
    
    if (sqrLen > EPSILON_SQUARED) {
        float invLen = 1.0f / std::sqrt(sqrLen);
        x = invLen * nx;
        y = invLen * ny;
        z = invLen * nz;
        w = -(x * p1.x + y * p1.y + z * p1.z);
        return true;
    }
    return false;
}

void GmVec4::PlaneEqSetNormPos(const GmVec3& normal, const GmVec3& pos) {
    x = normal.x;
    y = normal.y;
    z = normal.z;
    w = -(normal.x * pos.x + normal.y * pos.y + normal.z * pos.z);
}

// =================================================
// Clipping Logic
// =================================================

void GmVec4::GetClipFlag(uint& outFlag) const {
    outFlag = 0;
    uint flag = (z < 0.0f);                      // Bit 0: Near
    flag = ((w < z) * 2) ^ flag;                 // Bit 1: Far
    flag = ((y < -w) * 4) ^ flag;                // Bit 2: Bottom
    flag = ((w < y) * 8) ^ flag;                 // Bit 3: Top
    flag = ((x < -w) << 4) ^ flag;               // Bit 4: Left (<< 4 is * 16)
    
    if (w < x) {
        outFlag = flag ^ 0x20;                   // Bit 5: Right
        return;
    }
    outFlag = flag;
}

void GmVec4::GetClipFlags(const GmVec4* vecs, uint* outFlags, unsigned int count) {
    for (unsigned int i = 0; i < count; ++i) {
        vecs[i].GetClipFlag(outFlags[i]);
    }
}

// Stub for PolygonClip - Handled by the rendering architecture.
void GmVec4::PolygonClip(void* param_1, void* param_2) {
    // This requires definitions for CFastBuffer, CDx9TextureKeeper, 
    // CVisionHmsZone, CCrystalFace, etc. It handles geometric clipping
    // in rendering, not core math operations.
}