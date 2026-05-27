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
    // First Control Point (c1)
    GmQuat invQ1;
    invQ1.SetInverse(q1);

    GmQuat m0;
    m0.SetMult(q0, invQ1);

    GmQuat m2;
    m2.SetMult(q2, invQ1);

    // Log(m2)
    float len2Sq = (m2.x * m2.x) + (m2.y * m2.y) + (m2.z * m2.z);
    float len2 = std::sqrt(len2Sq);
    float angle2 = std::acos(m2.w);
    float log2_x = 0.0f, log2_y = 0.0f, log2_z = 0.0f;
    
    if (len2 > 1e-6f) { // _DAT_00bbd8e4
        float coef2 = angle2 / len2;
        log2_x = m2.x * coef2;
        log2_y = m2.y * coef2;
        log2_z = m2.z * coef2;
    }

    // Log(m0)
    float len0Sq = (m0.x * m0.x) + (m0.y * m0.y) + (m0.z * m0.z);
    float len0 = std::sqrt(len0Sq);
    float angle0 = std::acos(m0.w);
    float log0_x = 0.0f, log0_y = 0.0f, log0_z = 0.0f;
    
    if (len0 > 1e-6f) {
        float coef0 = angle0 / len0;
        log0_x = m0.x * coef0;
        log0_y = m0.y * coef0;
        log0_z = m0.z * coef0;
    }

    // Average * -0.25f (_DAT_00bbd900)
    float fFactor = -0.25f; 
    float avg1_x = (log0_x + log2_x) * fFactor;
    float avg1_y = (log0_y + log2_y) * fFactor;
    float avg1_z = (log0_z + log2_z) * fFactor;

    // Exp(avg)
    float avgLen1Sq = (avg1_x * avg1_x) + (avg1_y * avg1_y) + (avg1_z * avg1_z);
    float avgLen1 = std::sqrt(avgLen1Sq);

    GmQuat exp1;
    if (avgLen1 <= 1e-6f) {
        exp1.SetIdentity();
    } else {
        float sinAvg1 = std::sin(avgLen1);
        float coefAvg1 = sinAvg1 / avgLen1;
        exp1.x = avg1_x * coefAvg1;
        exp1.y = avg1_y * coefAvg1;
        exp1.z = avg1_z * coefAvg1;
        exp1.w = std::cos(avgLen1);
    }

    GmQuat c1;
    c1.SetMult(q1, exp1);


    // Second Control Point (c2) 
    GmQuat invQ2;
    invQ2.SetInverse(q2);

    GmQuat m1;
    m1.SetMult(q1, invQ2);

    GmQuat m3;
    m3.SetMult(q3, invQ2);

    // Log(m3)
    float len3Sq = (m3.x * m3.x) + (m3.y * m3.y) + (m3.z * m3.z);
    float len3 = std::sqrt(len3Sq);
    float angle3 = std::acos(m3.w);
    float log3_x = 0.0f, log3_y = 0.0f, log3_z = 0.0f;
    
    if (len3 > 1e-6f) {
        float coef3 = angle3 / len3;
        log3_x = m3.x * coef3;
        log3_y = m3.y * coef3;
        log3_z = m3.z * coef3;
    }

    // Log(m1)
    float len1Sq = (m1.x * m1.x) + (m1.y * m1.y) + (m1.z * m1.z);
    float len1 = std::sqrt(len1Sq);
    float angle1 = std::acos(m1.w);
    float log1_x = 0.0f, log1_y = 0.0f, log1_z = 0.0f;
    
    if (len1 > 1e-6f) {
        float coef1 = angle1 / len1;
        log1_x = m1.x * coef1;
        log1_y = m1.y * coef1;
        log1_z = m1.z * coef1;
    }

    // Average * -0.25f
    float avg2_x = (log1_x + log3_x) * fFactor;
    float avg2_y = (log1_y + log3_y) * fFactor;
    float avg2_z = (log1_z + log3_z) * fFactor;

    // Exp(avg)
    float avgLen2Sq = (avg2_x * avg2_x) + (avg2_y * avg2_y) + (avg2_z * avg2_z);
    float avgLen2 = std::sqrt(avgLen2Sq);

    GmQuat exp2;
    if (avgLen2 <= 1e-6f) {
        exp2.SetIdentity();
    } else {
        float sinAvg2 = std::sin(avgLen2);
        float coefAvg2 = sinAvg2 / avgLen2;
        exp2.x = avg2_x * coefAvg2;
        exp2.y = avg2_y * coefAvg2;
        exp2.z = avg2_z * coefAvg2;
        exp2.w = std::cos(avgLen2);
    }

    GmQuat c2;
    c2.SetMult(q2, exp2);

    // Perform the Squad Interpolation using the exact control points
    this->SetSquad(q1, q2, c1, c2, t);
}