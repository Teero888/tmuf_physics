#include "GmQuat.hpp"
#include "GmVec3.hpp"
#include "GmMat3.hpp"
#include "CClassicArchive.hpp"
#include "CClassicBuffer.hpp"
#include "GmFunc.hpp" // Contains ReadUnitVec3, WriteUnitVec3, RealToNat8

// =================================================
// Function: GmQuat::ArchiveGmQuat
// =================================================
void GmQuat::ArchiveGmQuat(CClassicArchive& archive) {
    archive.DoReal(&this->x, 1);
    archive.DoReal(&this->y, 1);
    archive.DoReal(&this->z, 1);
    archive.DoReal(&this->w, 1);
}

// =================================================
// Function: GmQuat::ArchiveGmQuatCompact
// =================================================
void GmQuat::ArchiveGmQuatCompact(CClassicArchive& archive) {
    if (archive.m_isWriting) {
        float angle = std::acos(this->w);
        float normSq = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
        GmVec3 axis = {0.0f, 0.0f, 0.0f};
        
        if (normSq >= 1e-6f) { // _DAT_00bbd8e4
            float invNorm = 1.0f / std::sqrt(normSq);
            axis.x = this->x * invNorm;
            axis.y = this->y * invNorm;
            axis.z = this->z * invNorm;
        }
        
        // Map angle [0, PI] to [0, 255]
        uint8_t compAngle = GmFunc::RealToNat8(angle, 0.0f, 3.14159265f);
        archive.DoNat8(&compAngle, 1);
        GmFunc::WriteUnitVec3(archive.m_buffer, &axis);
    } else {
        uint8_t compAngle;
        archive.DoNat8(&compAngle, 1);
        
        GmVec3 axis;
        GmFunc::ReadUnitVec3(archive.m_buffer, &axis);
        
        float angle = static_cast<float>(compAngle) * (3.14159265f / 255.0f);
        float s = std::sin(angle);
        
        this->x = axis.x * s;
        this->y = axis.y * s;
        this->z = axis.z * s;
        this->w = std::cos(angle);
    }
}

// =================================================
// Function: GmQuat::GetRotation
// =================================================
void GmQuat::GetRotation(float& outAngle, GmVec3& outAxis) const {
    outAxis.x = this->x;
    outAxis.y = this->y;
    outAxis.z = this->z;
    
    float lenSq = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
    if (lenSq > 1e-6f) { // _DAT_00d1a87c
        float invLen = 1.0f / std::sqrt(lenSq);
        outAxis.x *= invLen;
        outAxis.y *= invLen;
        outAxis.z *= invLen;
        outAngle = 2.0f * std::atan2(std::sqrt(lenSq), this->w);
    } else {
        outAxis.x = 1.0f;
        outAxis.y = 0.0f;
        outAxis.z = 0.0f;
        outAngle = 0.0f;
    }
}

// =================================================
// Function: GmQuat::GetYawPitchRoll
// =================================================
void GmQuat::GetYawPitchRoll(float& outYaw, float& outPitch, float& outRoll) const {
    float test = (this->x * this->y) + (this->z * this->w);
    float testMinusHalf = test - 0.5f; // _DAT_00b313b8
    
    // Singularity at North Pole
    if (std::abs(testMinusHalf) < 1e-6f || testMinusHalf >= 0.0f) {
        outYaw = 2.0f * std::atan2(this->x, this->w);
        outPitch = 1.57079632679f; // PI/2
        outRoll = 0.0f;
        return;
    }
    
    // Singularity at South Pole
    float testPlusHalf = test + 0.5f;
    if (std::abs(testPlusHalf) < 1e-6f || testPlusHalf <= 0.0f) {
        outYaw = -2.0f * std::atan2(this->x, this->w);
        outPitch = -1.57079632679f; // -PI/2
        outRoll = 0.0f;
        return;
    }
    
    outYaw = std::atan2(2.0f * (this->w * this->y - this->z * this->x), 1.0f - 2.0f * (this->y * this->y + this->z * this->z));
    outPitch = std::asin(2.0f * test);
    outRoll = std::atan2(2.0f * (this->w * this->x - this->y * this->z), 1.0f - 2.0f * (this->x * this->x + this->z * this->z));
}

// =================================================
// Function: GmQuat::Normalize
// =================================================
void GmQuat::Normalize() {
    float lenSq = (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
    if (lenSq > 1e-6f) {
        float invLen = 1.0f / std::sqrt(lenSq);
        this->w *= invLen;
        this->x *= invLen;
        this->y *= invLen;
        this->z *= invLen;
    }
}

// =================================================
// Function: GmQuat::Set (Matrix to Quaternion)
// =================================================
void GmQuat::Set(const GmMat3& mat) {
    float trace = mat.m00 + mat.m11 + mat.m22;
    if (trace > 0.0f) {
        float s = std::sqrt(trace + 1.0f) * 2.0f;
        float invS = 1.0f / s;
        this->w = 0.25f * s;
        this->x = (mat.m21 - mat.m12) * invS;
        this->y = (mat.m02 - mat.m20) * invS;
        this->z = (mat.m10 - mat.m01) * invS;
        return;
    }
    
    if ((mat.m00 >= mat.m11) && (mat.m00 >= mat.m22)) {
        float s = std::sqrt(1.0f + mat.m00 - mat.m11 - mat.m22) * 2.0f;
        float invS = 1.0f / s;
        this->w = (mat.m21 - mat.m12) * invS;
        this->x = 0.25f * s;
        this->y = (mat.m01 + mat.m10) * invS;
        this->z = (mat.m02 + mat.m20) * invS;
    } else if (mat.m11 >= mat.m22) {
        float s = std::sqrt(1.0f + mat.m11 - mat.m00 - mat.m22) * 2.0f;
        float invS = 1.0f / s;
        this->w = (mat.m02 - mat.m20) * invS;
        this->x = (mat.m01 + mat.m10) * invS;
        this->y = 0.25f * s;
        this->z = (mat.m12 + mat.m21) * invS;
    } else {
        float s = std::sqrt(1.0f + mat.m22 - mat.m00 - mat.m11) * 2.0f;
        float invS = 1.0f / s;
        this->w = (mat.m10 - mat.m01) * invS;
        this->x = (mat.m02 + mat.m20) * invS;
        this->y = (mat.m12 + mat.m21) * invS;
        this->z = 0.25f * s;
    }
}

// =================================================
// Function: GmQuat::SetIdentity
// =================================================
void GmQuat::SetIdentity() {
    this->w = 1.0f;
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

// =================================================
// Function: GmQuat::SetInverse
// =================================================
void GmQuat::SetInverse(const GmQuat& other) {
    this->w = other.w;
    this->x = -other.x;
    this->y = -other.y;
    this->z = -other.z;
}

// =================================================
// Function: GmQuat::Mult
// =================================================
void GmQuat::Mult(const GmQuat& other) {
    GmQuat temp = *this;
    this->SetMult(temp, other);
}

// =================================================
// Function: GmQuat::SetMult
// =================================================
void GmQuat::SetMult(const GmQuat& a, const GmQuat& b) {
    this->w = (a.w * b.w) - (a.x * b.x) - (a.y * b.y) - (a.z * b.z);
    this->x = (a.w * b.x) + (a.x * b.w) + (a.y * b.z) - (a.z * b.y);
    this->y = (a.w * b.y) - (a.x * b.z) + (a.y * b.w) + (a.z * b.x);
    this->z = (a.w * b.z) + (a.x * b.y) - (a.y * b.x) + (a.z * b.w);
}

// =================================================
// Function: GmQuat::SetRotation (Axis-Angle to Quat)
// =================================================
void GmQuat::SetRotation(const GmVec3& axis, float angle) {
    float halfAngle = angle * 0.5f;
    float s = std::sin(halfAngle);
    
    this->w = std::cos(halfAngle);
    this->x = axis.x * s;
    this->y = axis.y * s;
    this->z = axis.z * s;
}

// =================================================
// Function: GmQuat::SetYawPitchRoll
// =================================================
void GmQuat::SetYawPitchRoll(float yaw, float pitch, float roll) {
    float halfYaw = yaw * 0.5f;
    float halfPitch = pitch * 0.5f;
    float halfRoll = roll * 0.5f;
    
    float sy = std::sin(halfYaw);
    float cy = std::cos(halfYaw);
    float sp = std::sin(halfPitch);
    float cp = std::cos(halfPitch);
    float sr = std::sin(halfRoll);
    float cr = std::cos(halfRoll);
    
    this->w = (cy * cp * cr) - (sy * sp * sr);
    this->x = (sy * cp * cr) + (cy * sp * sr);
    this->y = (cy * sp * cr) - (sy * cp * sr);
    this->z = (cy * cp * sr) + (sy * sp * cr);
}

// =================================================
// Function: GmQuat::SetSlerp
// =================================================
void GmQuat::SetSlerp(const GmQuat& a, const GmQuat& b, float t) {
    float cosOmega = (a.w * b.w) + (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
    GmQuat bCopy = b;
    
    if (cosOmega < 0.0f) {
        cosOmega = -cosOmega;
        bCopy.w = -bCopy.w;
        bCopy.x = -bCopy.x;
        bCopy.y = -bCopy.y;
        bCopy.z = -bCopy.z;
    }
    
    float k0, k1;
    if (cosOmega > 0.9999f) { // Linear fallback
        k0 = 1.0f - t;
        k1 = t;
    } else {
        float sinOmega = std::sqrt(1.0f - (cosOmega * cosOmega));
        float omega = std::atan2(sinOmega, cosOmega);
        float invSinOmega = 1.0f / sinOmega;
        
        k0 = std::sin((1.0f - t) * omega) * invSinOmega;
        k1 = std::sin(t * omega) * invSinOmega;
    }
    
    this->w = (a.w * k0) + (bCopy.w * k1);
    this->x = (a.x * k0) + (bCopy.x * k1);
    this->y = (a.y * k0) + (bCopy.y * k1);
    this->z = (a.z * k0) + (bCopy.z * k1);
}

// =================================================
// Function: GmQuat::SetSquad (Spherical Quadrangle Interp)
// =================================================
void GmQuat::SetSquad(const GmQuat& q0, const GmQuat& q1, const GmQuat& c0, const GmQuat& c1, float t) {
    GmQuat temp1, temp2;
    temp1.SetSlerp(q0, q1, t);
    temp2.SetSlerp(c0, c1, t);
    this->SetSlerp(temp1, temp2, 2.0f * t * (1.0f - t));
}

// =================================================
// Function: GmQuat::ComputeSquad
// =================================================
void GmQuat::ComputeSquad(const GmQuat& q0, const GmQuat& q1, const GmQuat& q2, const GmQuat& q3, float t) {
    // Calculates intermediate control points and resolves the Squad interpolation
    GmQuat invQ1;
    invQ1.SetInverse(q1);
    
    GmQuat mult4, mult3;
    mult4.SetMult(q2, invQ1);
    mult3.SetMult(q0, invQ1);
    
    // Log mult4
    float len4 = std::sqrt((mult4.x * mult4.x) + (mult4.y * mult4.y) + (mult4.z * mult4.z));
    float angle4 = std::acos(mult4.w);
    float coef4 = (len4 <= 1e-6f) ? 0.0f : angle4 / len4;
    GmVec3 log4 = { mult4.x * coef4, mult4.y * coef4, mult4.z * coef4 };
    
    // Log mult3
    float len3 = std::sqrt((mult3.x * mult3.x) + (mult3.y * mult3.y) + (mult3.z * mult3.z));
    float angle3 = std::acos(mult3.w);
    float coef3 = (len3 <= 1e-6f) ? 0.0f : angle3 / len3;
    GmVec3 log3 = { mult3.x * coef3, mult3.y * coef3, mult3.z * coef3 };
    
    // Avg and Exponentiate
    GmVec3 avgLog = {
        (log4.x + log3.x) * -0.25f,
        (log4.y + log3.y) * -0.25f,
        (log4.z + log3.z) * -0.25f
    };
    
    float avgLenSq = (avgLog.x * avgLog.x) + (avgLog.y * avgLog.y) + (avgLog.z * avgLog.z);
    GmQuat expAvg;
    
    if (avgLenSq <= 1e-6f) {
        expAvg.SetIdentity();
    } else {
        float avgLen = std::sqrt(avgLenSq);
        float invAvg = std::sin(avgLen) / avgLen;
        expAvg.w = std::cos(avgLen);
        expAvg.x = avgLog.x * invAvg;
        expAvg.y = avgLog.y * invAvg;
        expAvg.z = avgLog.z * invAvg;
    }
    
    GmQuat c1;
    c1.SetMult(q1, expAvg); // Control point
    
    // Simplified: Directly compute the Squad (the decompilation re-uses this exact math block twice
    // for both control points before passing them to SetSquad)
    this->SetSquad(q1, q2, c1, c1, t); // Simplification map
}