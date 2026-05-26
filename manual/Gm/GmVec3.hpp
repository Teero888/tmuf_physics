#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include <cmath>

// Forward declarations & dependencies
struct STri_PosTexTgt;

// Minimal GmMat3 (3x3 Matrix - 36 bytes) required for GmVec3 operations
struct GmMat3 {
    float m00, m01, m02; // 0x0, 0x4, 0x8
    float m10, m11, m12; // 0xC, 0x10, 0x14
    float m20, m21, m22; // 0x18, 0x1C, 0x20
};

// Minimal GmIso4 (4x4 Affine Matrix - 48+ bytes) required for GmVec3 operations
struct GmIso4 {
    GmMat3 rot; // 0x0 - 0x20
    float tX;   // 0x24
    float tY;   // 0x28
    float tZ;   // 0x2C
};

// =================================================
// GmVec3
// =================================================
struct GmVec3 {
    float x; // Offset 0x0
    float y; // Offset 0x4
    float z; // Offset 0x8

    // Static Geometric Tests
    static float GetAngle(const GmVec3& v1, const GmVec3& v2);
    static float GetInnerAngle(const GmVec3& v1, const GmVec3& v2);
    static int ComputeTriangleTangentUV(STri_PosTexTgt* param_1);
    
    // Raycasting
    static int DoesRayIntersectTriangle(const GmVec3& rayOrigin, const GmVec3& rayDir, 
                                        const GmVec3& v0, const GmVec3& v1, const GmVec3& v2, 
                                        float& outT, float& outU, float& outV);
                                        
    static int DoesRayIntersectTriangleCull(const GmVec3& rayOrigin, const GmVec3& rayDir, 
                                            const GmVec3& v0, const GmVec3& v1, const GmVec3& v2, 
                                            float& outT, float& outU, float& outV);

    // Member Functions
    bool IsNearlyEqual(const GmVec3& other) const;
    void SetFromBGRA(const unsigned char* bgraColor);
    
    // Matrix Multiplication
    void Mult(const GmIso4& mat);
    void SetMult(const GmVec3& v, const GmIso4& mat);
    void MultInverse(const GmIso4& mat);
    void MultTranspose(const GmMat3& mat);
    void SetMultTranspose(const GmVec3& v, const GmMat3& mat);
    void SetInverseTranslation(const GmIso4& mat);
};

// External helper definition required by ComputeTriangleTangentUV
extern int ComputeTriangleTangentUV_Rotated(STri_PosTexTgt* param_1, unsigned long rotationIndex);

#endif // GMVEC3_HPP