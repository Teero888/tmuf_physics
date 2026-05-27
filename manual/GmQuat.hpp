#ifndef GMQUAT_HPP
#define GMQUAT_HPP

#include <cmath>
#include <cstdint>

// Forward Declarations
class CClassicArchive;
struct GmVec3;
struct GmMat3;

// =================================================
// GmQuat (Quaternion)
// =================================================
struct GmQuat {
    float w; // field_0x0
    float x; // field_0x4
    float y; // field_0x8
    float z; // field_0xc

    // Serialization
    void ArchiveGmQuat(CClassicArchive& archive);
    void ArchiveGmQuatCompact(CClassicArchive& archive);

    // Extraction & Info
    void GetRotation(float& outAngle, GmVec3& outAxis) const;
    void GetYawPitchRoll(float& outYaw, float& outPitch, float& outRoll) const;
    void Normalize();

    // Setters
    void Set(const GmMat3& mat);
    void SetIdentity();
    void SetInverse(const GmQuat& other);
    void SetRotation(const GmVec3& axis, float angle);
    void SetYawPitchRoll(float yaw, float pitch, float roll);

    // Math
    void Mult(const GmQuat& other);
    void SetMult(const GmQuat& a, const GmQuat& b);
    
    // Interpolation
    void SetSlerp(const GmQuat& a, const GmQuat& b, float t);
    void SetSquad(const GmQuat& q0, const GmQuat& q1, const GmQuat& c0, const GmQuat& c1, float t);
    void ComputeSquad(const GmQuat& q0, const GmQuat& q1, const GmQuat& q2, const GmQuat& q3, float t);
};

#endif // GMQUAT_HPP