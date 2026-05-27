#ifndef GMMAT3_HPP
#define GMMAT3_HPP

#include <cmath>
#include "GmQuat.hpp"

// Forward declarations
class CClassicArchive;
struct GmVec2;
struct GmVec3;

// =================================================
// GmMat3 (3x3 Matrix)
// =================================================
struct GmMat3 {
    float m00, m01, m02; // 0x0, 0x4, 0x8
    float m10, m11, m12; // 0xC, 0x10, 0x14
    float m20, m21, m22; // 0x18, 0x1C, 0x20

    // Serialization
    void ArchiveGmMat3(CClassicArchive& archive);

    // Getters & Checks
    void GetLine(unsigned long index, GmVec3& outLine) const;
    bool IsIndirect() const;
    bool IsNearlyEqual(const GmMat3& other) const;
    bool IsOrthogonal() const;
    bool IsOrthonormal() const;

    // Setters
    void Set(const GmQuat& quat);
    void SetBlend(const GmMat3& a, const GmMat3& b, float t);
    void SetIdentity();
    void SetLine(unsigned long index, const GmVec3& line);
    void SetRotateQuarterY(unsigned long quarterTurns);
    void SetTranspose(const GmMat3& other);
    
    // LookAt / DOV (Direction of View) Setters
    void SetDOV(const GmVec3& dov, const GmVec3* up = nullptr);
    void SetDOVandLeftV(const GmVec3& dov, const GmVec3& leftV);
    void SetDOVandUpV(const GmVec3& dov, const GmVec3& upV);
    void SetUpVandDOV(const GmVec3& upV, const GmVec3& dov);
    bool SetDOVInverse(const GmVec3& dov);

    // Math & Transformations
    void Inverse();
    void Transpose();
    void OrthoNormalize();
    void Mult(const GmMat3& other);
    void SetMult(const GmMat3& a, const GmMat3& b);
    void LeftMult(const GmMat3& other);
    void MultTranspose(const GmMat3& a, const GmMat3& b);
    
    void RotateX(const GmMat3& other, float angle);
    void RotateY(const GmMat3& other, float angle);
    void RotateZ(const GmMat3& other, float angle);
};

#endif // GMMAT3_HPP