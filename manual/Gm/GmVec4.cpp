#include "GmFunc.hpp"
#include "GmVec4.hpp"
#include "GmVec3.hpp"
#include "GmLine3.hpp" // Assuming this has a GmVec3 pos and GmVec3 dir
#include "GmIso4.hpp"
#include "CFastBuffer.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include <cmath>

namespace {

struct GmReal4_64 {
    double values[4];
};

uint32_t GetClipFlag64(const GmReal4_64& value) {
    const double x = value.values[0];
    const double y = value.values[1];
    const double z = value.values[2];
    const double w = value.values[3];

    uint32_t flag = static_cast<uint32_t>(z < 0.0);
    flag ^= static_cast<uint32_t>(w < z) * 2u;
    flag ^= static_cast<uint32_t>(y < -w) * 4u;
    flag ^= static_cast<uint32_t>(w < y) * 8u;
    flag ^= static_cast<uint32_t>(x < -w) << 4u;
    flag ^= static_cast<uint32_t>(w < x) << 5u;
    return flag;
}

double ClipEdgeParameter(const GmReal4_64& previous,
                         const GmReal4_64& current,
                         uint32_t plane) {
    const uint32_t coordinate = 2u - plane / 2u;
    const long double previousCoordinate = previous.values[coordinate];
    const long double currentCoordinate = current.values[coordinate];
    const long double previousW = previous.values[3];
    const long double currentW = current.values[3];

    long double parameter;
    if (plane == 0u) {
        parameter = previousCoordinate /
                    (previousCoordinate - currentCoordinate);
    } else if ((plane & 1u) != 0u) {
        const long double numerator = previousW - previousCoordinate;
        parameter = numerator /
                    (currentCoordinate + numerator - currentW);
    } else {
        parameter = (-previousW - previousCoordinate) /
                    (currentW + currentCoordinate - previousW - previousCoordinate);
    }

    // The native routine stores the x87 result to a double before clamping.
    double roundedParameter = static_cast<double>(parameter);
    if (roundedParameter < 0.0) roundedParameter = 0.0;
    if (roundedParameter > 1.0) roundedParameter = 1.0;
    return roundedParameter;
}

GmReal4_64 BlendClipVertex(const GmReal4_64& previous,
                           const GmReal4_64& current,
                           double parameter) {
    const long double currentWeight = parameter;
    const long double previousWeight = 1.0L - currentWeight;
    GmReal4_64 result{};
    for (uint32_t component = 0; component < 4; ++component) {
        result.values[component] = static_cast<double>(
            static_cast<long double>(previous.values[component]) * previousWeight +
            static_cast<long double>(current.values[component]) * currentWeight);
    }
    return result;
}

} // namespace

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
    
    if (std::abs(dotDir) > TmForeverPhysicsConstants::kLineIntersectionEpsilon) {
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
    
    if (sqrLen > TmForeverPhysicsConstants::kPlaneNormalSquaredEpsilon) {
        // func_0x009c1b40 is an inverse square root routine (1 / sqrt)
        float invLen = 1.0f / std::sqrt(sqrLen); 
        
        outLine.dir.x *= invLen;
        outLine.dir.y *= invLen;
        outLine.dir.z *= invLen;
        
        int i0, i1, i2;
        if (std::abs(outLine.dir.x) <= TmForeverPhysicsConstants::kPlaneSolveAxisThreshold) {
            if (std::abs(outLine.dir.y) <= TmForeverPhysicsConstants::kPlaneSolveAxisThreshold) {
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
    (void)dotEpsilon;
    (void)distEpsilon;
    float dotProduct = other.z * z + other.x * x + other.y * y;
    if (dotProduct >= TmForeverPhysicsConstants::kPlaneNormalDotThreshold) {
        if (std::abs(w - other.w) <= TmForeverPhysicsConstants::kPlaneDistanceThreshold) {
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
    
    if (sqrLen > TmForeverPhysicsConstants::kPlaneNormalSquaredEpsilon) {
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

void GmVec4::GetClipFlag(uint32_t& outFlag) const {
    outFlag = 0;
    uint32_t flag = (z < 0.0f);                  // Bit 0: Near
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

void GmVec4::GetClipFlags(const GmVec4* vecs, uint32_t* outFlags, uint32_t count) {
    for (uint32_t i = 0; i < count; ++i) {
        vecs[i].GetClipFlag(outFlags[i]);
    }
}

void GmVec4::PolygonClip(CFastBuffer<GmVec4>& vertices,
                         CFastBuffer<uint32_t>& clipFlags) {
    const uint32_t inputCount = vertices.GetCount();
    if (inputCount == 0u || clipFlags.GetCount() != inputCount) {
        if (inputCount == 0u) clipFlags.AllocSetCount(0u);
        return;
    }

    CFastBuffer<GmReal4_64> workingVertices;
    workingVertices.AllocSetCount(inputCount);
    for (uint32_t index = 0; index < inputCount; ++index) {
        workingVertices[index].values[0] = vertices[index].x;
        workingVertices[index].values[1] = vertices[index].y;
        workingVertices[index].values[2] = vertices[index].z;
        workingVertices[index].values[3] = vertices[index].w;
    }

    for (uint32_t plane = 0; plane < 6u && workingVertices.GetCount() != 0u; ++plane) {
        const uint32_t planeBit = 1u << plane;
        const uint32_t oldCount = workingVertices.GetCount();
        CFastBuffer<GmReal4_64> outputVertices;
        CFastBuffer<uint32_t> outputFlags;
        outputVertices.SetSizeAtLeast(oldCount * 2u + 3u);
        outputFlags.SetSizeAtLeast(oldCount * 2u + 3u);

        for (uint32_t currentIndex = 0; currentIndex <= oldCount; ++currentIndex) {
            const uint32_t wrappedIndex = currentIndex == oldCount ? 0u : currentIndex;
            const GmReal4_64& current = workingVertices[wrappedIndex];
            const uint32_t currentFlag = clipFlags[wrappedIndex];
            const bool currentInside = (currentFlag & planeBit) == 0u;

            if (currentIndex != 0u) {
                const uint32_t previousIndex = currentIndex - 1u;
                const bool previousInside = (clipFlags[previousIndex] & planeBit) == 0u;
                if (previousInside != currentInside) {
                    const double parameter = ClipEdgeParameter(
                        workingVertices[previousIndex], current, plane);
                    const GmReal4_64 intersection = BlendClipVertex(
                        workingVertices[previousIndex], current, parameter);
                    outputVertices.Add(intersection);
                    outputFlags.Add(GetClipFlag64(intersection) & ~planeBit);
                }
            }

            if (currentInside && currentIndex < oldCount) {
                outputVertices.Add(current);
                outputFlags.Add(currentFlag);
            }
        }

        workingVertices.AllocSetCount(outputVertices.GetCount());
        clipFlags.AllocSetCount(outputFlags.GetCount());
        for (uint32_t index = 0; index < outputVertices.GetCount(); ++index) {
            workingVertices[index] = outputVertices[index];
            clipFlags[index] = outputFlags[index];
        }
    }

    vertices.AllocSetCount(workingVertices.GetCount());
    for (uint32_t index = 0; index < workingVertices.GetCount(); ++index) {
        vertices[index].x = static_cast<float>(workingVertices[index].values[0]);
        vertices[index].y = static_cast<float>(workingVertices[index].values[1]);
        vertices[index].z = static_cast<float>(workingVertices[index].values[2]);
        vertices[index].w = static_cast<float>(workingVertices[index].values[3]);
    }
}
