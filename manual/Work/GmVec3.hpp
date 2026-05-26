#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include <cmath>
#include "GmIso4.hpp"
#include "GmMat3.hpp"

// Forward declarations & dependencies
struct STri_PosTexTgt;

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