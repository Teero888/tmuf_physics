#ifndef GMISO4_HPP
#define GMISO4_HPP

#include <cmath>
#include "GmMat3.hpp"
#include <cstdint>

// Forward declarations
class CClassicArchive;
struct GmVec2;
struct GmVec3;
struct GmVec4;
struct GmIso3; // 2D Affine Transform from previous implementations

// =================================================
// GmIso4 (3D Affine Transformation Matrix)
// =================================================
struct GmIso4 {
    union {
        GmMat3 rot; // 0x0 - 0x20
        struct {
            float m00, m01, m02; // 0x0, 0x4, 0x8
            float m10, m11, m12; // 0xC, 0x10, 0x14
            float m20, m21, m22; // 0x18, 0x1C, 0x20
        };
    };
    
    float tX; // 0x24
    float tY; // 0x28
    float tZ; // 0x2C

    // Member Functions
    void ArchiveGmIso4(CClassicArchive& archive);
    
    // Getters
    void GetDir(GmVec3& outDir) const;
    void GetUp(GmVec3& outUp) const;
    void GetPlaneEq(uint32_t axis, GmVec4& outPlane) const;
    bool IsNearlyEqual(const GmIso4& other) const;
    void NUGetIso4AndScale(GmIso4& outMat, GmVec3& outScale) const;

    // Setters
    void Set(const GmIso4& other);
    void SetRow(uint32_t index, const GmVec4& row); // Decompiler labeled as SetColumn
    void SetXY(const GmIso3& iso2d);
    void SetIdentity();
    void SetBlend(const GmIso4& a, const GmIso4& b, float t);
    void SetLookAt(const GmVec3& pos, const GmVec3& target, const GmVec3& up);
    void SetTranslation(const GmVec3& trans);
    void SetUScaleTrans(float scale, const GmVec3& trans);
    void SetNUScaleTrans(const GmVec3& scale, const GmVec3& trans);

    // Matrix Math
    void Inverse();
    void SetInverse(const GmIso4& other);
    void UScaleSetInverse(const GmIso4& other);
    void NUScaleSetInverse(const GmIso4& other);
    
    void Mult(const GmIso4& other);
    void SetMult(const GmIso4& a, const GmIso4& b);
    void LeftMult(const GmIso4& other);
    void MultInverse(const GmIso4& other);
    
    // Rotations & Symmetry
    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void SymmetryPlane(const GmIso4& mat, const GmVec4& plane);
};

#endif // GMISO4_HPP