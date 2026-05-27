#include "GmVec3.hpp"
#include "GmVec4.hpp" // Assumes GmVec4::SetMult exists from previous implementation

// =================================================
// Function: GmVec3::ComputeTriangleTangentUV
// =================================================
int GmVec3::ComputeTriangleTangentUV(STri_PosTexTgt* param_1) {
    for (unsigned long i = 0; i < 3; ++i) {
        if (ComputeTriangleTangentUV_Rotated(param_1, i) != 0) {
            return 1;
        }
    }
    return 0;
}

// =================================================
// Function: GmVec3::DoesRayIntersectTriangle
// =================================================
int GmVec3::DoesRayIntersectTriangle(const GmVec3& rayOrigin, const GmVec3& rayDir, 
                                     const GmVec3& v0, const GmVec3& v1, const GmVec3& v2, 
                                     float& outT, float& outU, float& outV) 
{
    // Standard Möller-Trumbore algorithm (Non-Culling)
    GmVec3 edge1 = { v1.x - v0.x, v1.y - v0.y, v1.z - v0.z };
    GmVec3 edge2 = { v2.x - v0.x, v2.y - v0.y, v2.z - v0.z };

    GmVec3 pvec = {
        (rayDir.y * edge2.z) - (rayDir.z * edge2.y),
        (rayDir.z * edge2.x) - (rayDir.x * edge2.z),
        (rayDir.x * edge2.y) - (rayDir.y * edge2.x)
    };

    float det = (edge1.x * pvec.x) + (edge1.y * pvec.y) + (edge1.z * pvec.z);
    float edge2Sq = (edge2.x * edge2.x) + (edge2.y * edge2.y) + (edge2.z * edge2.z);

    // Epsilon check (_DAT_00b36288 is roughly 1e-5f or 1e-6f squared comparison)
    if (1e-6f * (edge2Sq * edge2Sq) <= (det * det)) {
        float absDet = std::abs(det);
        
        GmVec3 tvec = { rayOrigin.x - v0.x, rayOrigin.y - v0.y, rayOrigin.z - v0.z };
        
        // Fix for Ghidra's bitwise float sign logic (^ (uint)det & 0x80000000)
        // It computes the dot product, then flips the sign if det is negative.
        float u = (tvec.x * pvec.x) + (tvec.y * pvec.y) + (tvec.z * pvec.z);
        if (det < 0.0f) u = -u;

        if (u < 0.0f || u > absDet) return 0;

        GmVec3 qvec = {
            (tvec.y * edge1.z) - (tvec.z * edge1.y),
            (tvec.z * edge1.x) - (tvec.x * edge1.z),
            (tvec.x * edge1.y) - (tvec.y * edge1.x)
        };

        float v = (rayDir.x * qvec.x) + (rayDir.y * qvec.y) + (rayDir.z * qvec.z);
        if (det < 0.0f) v = -v;

        if (v < 0.0f || u + v > absDet) return 0;

        float invDet = 1.0f / absDet;
        outT = ((edge2.x * qvec.x) + (edge2.y * qvec.y) + (edge2.z * qvec.z)) * invDet;
        if (det < 0.0f) outT = -outT;
        
        outU = u * invDet;
        outV = v * invDet;
        return 1;
    }
    return 0;
}

// =================================================
// Function: GmVec3::DoesRayIntersectTriangleCull
// =================================================
int GmVec3::DoesRayIntersectTriangleCull(const GmVec3& rayOrigin, const GmVec3& rayDir, 
                                         const GmVec3& v0, const GmVec3& v1, const GmVec3& v2, 
                                         float& outT, float& outU, float& outV) 
{
    // Culling version (Only hits front-faces where det > 0)
    GmVec3 edge1 = { v1.x - v0.x, v1.y - v0.y, v1.z - v0.z };
    GmVec3 edge2 = { v2.x - v0.x, v2.y - v0.y, v2.z - v0.z };

    GmVec3 pvec = {
        (rayDir.y * edge2.z) - (rayDir.z * edge2.y),
        (rayDir.z * edge2.x) - (rayDir.x * edge2.z),
        (rayDir.x * edge2.y) - (rayDir.y * edge2.x)
    };

    float det = (edge1.x * pvec.x) + (edge1.y * pvec.y) + (edge1.z * pvec.z);
    
    // Culling condition: det must be positive
    if (det < 0.0f) return 0;

    float edge1Sq = (edge1.x * edge1.x) + (edge1.y * edge1.y) + (edge1.z * edge1.z);
    if (1e-6f * (edge1Sq * edge1Sq) <= (det * det)) {
        GmVec3 tvec = { rayOrigin.x - v0.x, rayOrigin.y - v0.y, rayOrigin.z - v0.z };
        
        float u = (tvec.x * pvec.x) + (tvec.y * pvec.y) + (tvec.z * pvec.z);
        if (u < 0.0f || u > det) return 0;

        GmVec3 qvec = {
            (tvec.y * edge1.z) - (tvec.z * edge1.y),
            (tvec.z * edge1.x) - (tvec.x * edge1.z),
            (tvec.x * edge1.y) - (tvec.y * edge1.x)
        };

        float v = (rayDir.x * qvec.x) + (rayDir.y * qvec.y) + (rayDir.z * qvec.z);
        if (v >= 0.0f && u + v <= det) {
            float invDet = 1.0f / det;
            outT = ((edge2.x * qvec.x) + (edge2.y * qvec.y) + (edge2.z * qvec.z)) * invDet;
            outU = u * invDet;
            outV = v * invDet;
            return 1;
        }
    }
    return 0;
}

// =================================================
// Function: GmVec3::GetAngle
// =================================================
float GmVec3::GetAngle(const GmVec3& v1, const GmVec3& v2) {
    GmVec3 n1 = v1;
    GmVec3 n2 = v2;
    
    float lenSq1 = (n1.x * n1.x) + (n1.y * n1.y) + (n1.z * n1.z);
    if (lenSq1 > 1e-6f) { // _DAT_00d1a8f0
        float invLen = GmFunc::InvSqrt(lenSq1);
        n1.x *= invLen; n1.y *= invLen; n1.z *= invLen;
    }
    
    float lenSq2 = (n2.x * n2.x) + (n2.y * n2.y) + (n2.z * n2.z);
    if (lenSq2 > 1e-6f) {
        float invLen = GmFunc::InvSqrt(lenSq2);
        n2.x *= invLen; n2.y *= invLen; n2.z *= invLen;
    }

    float dot = (n1.x * n2.x) + (n1.y * n2.y) + (n1.z * n2.z);
    float angle = std::acos(dot);

    if (angle > 1e-5f) { // _DAT_00bbdb0c
        // Cross product: cross(n1, n2)
        // Ghidra output checked the Y component of the cross product to determine sign
        // using UP vector = (0, 1, 0). (cross.y = n1.z * n2.x - n1.x * n2.z)
        float crossY = (n1.z * n2.x) - (n1.x * n2.z);
        
        if (crossY < 0.0f) { // _DAT_00c418e0
            angle = -angle;
        }
    }
    return angle;
}

// =================================================
// Function: GmVec3::GetInnerAngle
// =================================================
float GmVec3::GetInnerAngle(const GmVec3& v1, const GmVec3& v2) {
    float dot = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    return std::acos(dot);
}

// =================================================
// Function: GmVec3::IsNearlyEqual
// =================================================
bool GmVec3::IsNearlyEqual(const GmVec3& other) const {
    float eps = 1e-5f; // _DAT_00b36288 (Relative Epsilon)
    
    if (this->x < other.x - (std::abs(other.x) * eps) || this->x > other.x + (std::abs(other.x) * eps)) return false;
    if (this->y < other.y - (std::abs(other.y) * eps) || this->y > other.y + (std::abs(other.y) * eps)) return false;
    if (this->z < other.z - (std::abs(other.z) * eps) || this->z > other.z + (std::abs(other.z) * eps)) return false;
    
    return true;
}

// =================================================
// Function: GmVec3::Mult
// =================================================
void GmVec3::Mult(const GmIso4& mat) {
    SetMult(*this, mat);
}

// =================================================
// Function: GmVec3::SetMult
// =================================================
void GmVec3::SetMult(const GmVec3& v, const GmIso4& mat) {
    // 3D vector multiplied by 4x4 matrix with perspective divide
    GmVec4 v4 = { v.x, v.y, v.z, 1.0f };
    GmVec4 result;
    result.SetMult(v4, mat); // From GmVec4 class

    float invW = 1.0f / std::abs(result.w);
    this->x = result.x * invW;
    this->y = result.y * invW;
    this->z = result.z * invW;
}

// =================================================
// Function: GmVec3::MultInverse
// =================================================
void GmVec3::MultInverse(const GmIso4& mat) {
    // 1. Subtract translation
    GmVec3 temp = {
        this->x - mat.tX,
        this->y - mat.tY,
        this->z - mat.tZ
    };
    
    // 2. Multiply by transpose of the rotation matrix
    this->SetMultTranspose(temp, mat.rot);
}

// =================================================
// Function: GmVec3::MultTranspose
// =================================================
void GmVec3::MultTranspose(const GmMat3& mat) {
    GmVec3 temp = *this;
    this->SetMultTranspose(temp, mat);
}

// =================================================
// Function: GmVec3::SetMultTranspose
// =================================================
void GmVec3::SetMultTranspose(const GmVec3& v, const GmMat3& mat) {
    this->x = (v.x * mat.m00) + (v.y * mat.m10) + (v.z * mat.m20);
    this->y = (v.x * mat.m01) + (v.y * mat.m11) + (v.z * mat.m21);
    this->z = (v.x * mat.m02) + (v.y * mat.m12) + (v.z * mat.m22);
}

// =================================================
// Function: GmVec3::SetFromBGRA
// =================================================
void GmVec3::SetFromBGRA(const unsigned char* bgraColor) {
    float scale = 0.00392156862f; // 1.0f / 255.0f (_DAT_00b3d080)
    
    this->x = static_cast<float>(bgraColor[2]) * scale; // R
    this->y = static_cast<float>(bgraColor[1]) * scale; // G
    this->z = static_cast<float>(bgraColor[0]) * scale; // B
}

// =================================================
// Function: GmVec3::SetInverseTranslation
// =================================================
void GmVec3::SetInverseTranslation(const GmIso4& mat) {
    // Calculates - (M^T * T)
    this->x = - (mat.tX * mat.rot.m00 + mat.tY * mat.rot.m10 + mat.tZ * mat.rot.m20);
    this->y = - (mat.tX * mat.rot.m01 + mat.tY * mat.rot.m11 + mat.tZ * mat.rot.m21);
    this->z = - (mat.tX * mat.rot.m02 + mat.tY * mat.rot.m12 + mat.tZ * mat.rot.m22);
}