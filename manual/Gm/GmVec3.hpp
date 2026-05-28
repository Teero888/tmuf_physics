#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include <cmath>
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include <cstdint>

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
    void SetFromBGRA(const uint8_t* bgraColor);
    
    // Matrix Multiplication
    void Mult(const GmIso4& mat);
    void SetMult(const GmVec3& v, const GmIso4& mat);
    void MultInverse(const GmIso4& mat);
    void MultTranspose(const GmMat3& mat);
    void SetMultTranspose(const GmVec3& v, const GmMat3& mat);
    void SetInverseTranslation(const GmIso4& mat);

    // =================================================
    // Operator Overloads
    // =================================================

    // Unary minus (Negation)
    inline GmVec3 operator-() const {
        return { -x, -y, -z };
    }

    // Vector + Vector
    inline GmVec3 operator+(const GmVec3& v) const {
        return { x + v.x, y + v.y, z + v.z };
    }

    // Vector - Vector
    inline GmVec3 operator-(const GmVec3& v) const {
        return { x - v.x, y - v.y, z - v.z };
    }

    // Vector * Vector (Component-wise multiplication)
    inline GmVec3 operator*(const GmVec3& v) const {
        return { x * v.x, y * v.y, z * v.z };
    }

    // Vector / Vector (Component-wise division)
    inline GmVec3 operator/(const GmVec3& v) const {
        return { x / v.x, y / v.y, z / v.z };
    }

    // Vector * Scalar
    inline GmVec3 operator*(float scalar) const {
        return { x * scalar, y * scalar, z * scalar };
    }

    // Vector / Scalar
    inline GmVec3 operator/(float scalar) const {
        float inv = 1.0f / scalar; // Faster to multiply by inverse
        return { x * inv, y * inv, z * inv };
    }

    // Compound Assignment Operators
    inline GmVec3& operator+=(const GmVec3& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    inline GmVec3& operator-=(const GmVec3& v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    inline GmVec3& operator*=(float scalar) {
        x *= scalar; y *= scalar; z *= scalar;
        return *this;
    }

    inline GmVec3& operator/=(float scalar) {
        float inv = 1.0f / scalar;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
};

// External helper definition required by ComputeTriangleTangentUV
extern int ComputeTriangleTangentUV_Rotated(STri_PosTexTgt* param_1, uint32_t rotationIndex);

#endif // GMVEC3_HPP