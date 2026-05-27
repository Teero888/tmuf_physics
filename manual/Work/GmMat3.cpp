#include "GmMat3.hpp"
#include "GmVec3.hpp" // Assumed to define GmVec3
#include "CClassicArchive.hpp" // Assumed to define CClassicArchive

// Global lookup table for QuarterY rotations (Cos/Sin of 0, 90, 180, 270)
static const float DAT_00bbd760[4] = { 1.0f, 0.0f, -1.0f, 0.0f };

// =================================================
// Function: GmMat3::ArchiveGmMat3
// =================================================
void GmMat3::ArchiveGmMat3(CClassicArchive& archive) {
    archive.DoReal(&this->m00, 1);
    archive.DoReal(&this->m01, 1);
    archive.DoReal(&this->m02, 1);
    archive.DoReal(&this->m10, 1);
    archive.DoReal(&this->m11, 1);
    archive.DoReal(&this->m12, 1);
    archive.DoReal(&this->m20, 1);
    archive.DoReal(&this->m21, 1);
    archive.DoReal(&this->m22, 1);
}

// =================================================
// Function: GmMat3::GetLine
// =================================================
void GmMat3::GetLine(unsigned long index, GmVec3& outLine) const {
    const float* m = reinterpret_cast<const float*>(this);
    outLine.x = m[index * 3 + 0];
    outLine.y = m[index * 3 + 1];
    outLine.z = m[index * 3 + 2];
}

// =================================================
// Function: GmMat3::Inverse
// =================================================
void GmMat3::Inverse() {
    float inv00 = (this->m11 * this->m22) - (this->m12 * this->m21);
    float inv10 = (this->m02 * this->m21) - (this->m01 * this->m22);
    float inv20 = (this->m01 * this->m12) - (this->m02 * this->m11);
    
    float det = (inv00 * this->m00) + (inv10 * this->m10) + (inv20 * this->m20);
    
    if (det == 0.0f) return;
    
    float invDet = 1.0f / det;
    
    float new00 = inv00 * invDet;
    float new01 = inv10 * invDet;
    float new02 = inv20 * invDet;
    
    float new10 = ((this->m20 * this->m12) - (this->m10 * this->m22)) * invDet;
    float new11 = ((this->m00 * this->m22) - (this->m02 * this->m20)) * invDet;
    float new12 = ((this->m02 * this->m10) - (this->m00 * this->m12)) * invDet;
    
    float new20 = ((this->m10 * this->m21) - (this->m11 * this->m20)) * invDet;
    float new21 = ((this->m20 * this->m01) - (this->m00 * this->m21)) * invDet;
    float new22 = ((this->m00 * this->m11) - (this->m01 * this->m10)) * invDet;

    this->m00 = new00; this->m01 = new01; this->m02 = new02;
    this->m10 = new10; this->m11 = new11; this->m12 = new12;
    this->m20 = new20; this->m21 = new21; this->m22 = new22;
}

// =================================================
// Function: GmMat3::IsIndirect
// =================================================
bool GmMat3::IsIndirect() const {
    float det = this->m00 * ((this->m11 * this->m22) - (this->m12 * this->m21)) +
                this->m01 * ((this->m12 * this->m20) - (this->m10 * this->m22)) +
                this->m02 * ((this->m10 * this->m21) - (this->m11 * this->m20));
    return det < 0.0f; // _DAT_00c418e0
}

// =================================================
// Function: GmMat3::IsNearlyEqual
// =================================================
bool GmMat3::IsNearlyEqual(const GmMat3& other) const {
    const GmVec3* v1 = reinterpret_cast<const GmVec3*>(this);
    const GmVec3* v2 = reinterpret_cast<const GmVec3*>(&other);
    
    if (v1[0].IsNearlyEqual(v2[0])) {
        if (v1[1].IsNearlyEqual(v2[1])) {
            if (v1[2].IsNearlyEqual(v2[2])) {
                return true;
            }
        }
    }
    return false;
}

// =================================================
// Function: GmMat3::IsOrthogonal
// =================================================
bool GmMat3::IsOrthogonal() const {
    float eps = 1e-4f; // _DAT_00b37b60
    
    float dot01 = (this->m00 * this->m10) + (this->m01 * this->m11) + (this->m02 * this->m12);
    float dot02 = (this->m00 * this->m20) + (this->m01 * this->m21) + (this->m02 * this->m22);
    float dot12 = (this->m10 * this->m20) + (this->m11 * this->m21) + (this->m12 * this->m22);
    
    return std::abs(dot01) < eps && std::abs(dot02) < eps && std::abs(dot12) < eps;
}

// =================================================
// Function: GmMat3::IsOrthonormal
// =================================================
bool GmMat3::IsOrthonormal() const {
    float eps = 1e-4f; // _DAT_00b37b60
    
    float len0 = GmFunc::InvSqrt((this->m00 * this->m00) + (this->m01 * this->m01) + (this->m02 * this->m02));
    if (std::abs(len0 - 1.0f) < eps) {
        float len1 = GmFunc::InvSqrt((this->m10 * this->m10) + (this->m11 * this->m11) + (this->m12 * this->m12));
        if (std::abs(len1 - 1.0f) < eps) {
            float len2 = GmFunc::InvSqrt((this->m20 * this->m20) + (this->m21 * this->m21) + (this->m22 * this->m22));
            if (std::abs(len2 - 1.0f) < eps) {
                return IsOrthogonal();
            }
        }
    }
    return false;
}

// =================================================
// Function: GmMat3::LeftMult
// =================================================
void GmMat3::LeftMult(const GmMat3& other) {
    GmMat3 temp = *this;
    this->SetMult(other, temp);
}

// =================================================
// Function: GmMat3::Mult
// =================================================
void GmMat3::Mult(const GmMat3& other) {
    GmMat3 temp = *this;
    this->SetMult(temp, other);
}

// =================================================
// Function: GmMat3::MultTranspose
// =================================================
void GmMat3::MultTranspose(const GmMat3& a, const GmMat3& b) {
    // Computes A^T * B
    this->m00 = (a.m00 * b.m00) + (a.m10 * b.m10) + (a.m20 * b.m20);
    this->m01 = (a.m00 * b.m01) + (a.m10 * b.m11) + (a.m20 * b.m21);
    this->m02 = (a.m00 * b.m02) + (a.m10 * b.m12) + (a.m20 * b.m22);
    
    this->m10 = (a.m01 * b.m00) + (a.m11 * b.m10) + (a.m21 * b.m20);
    this->m11 = (a.m01 * b.m01) + (a.m11 * b.m11) + (a.m21 * b.m21);
    this->m12 = (a.m01 * b.m02) + (a.m11 * b.m12) + (a.m21 * b.m22);
    
    this->m20 = (a.m02 * b.m00) + (a.m12 * b.m10) + (a.m22 * b.m20);
    this->m21 = (a.m02 * b.m01) + (a.m12 * b.m11) + (a.m22 * b.m21);
    this->m22 = (a.m02 * b.m02) + (a.m12 * b.m12) + (a.m22 * b.m22);
}

// =================================================
// Function: GmMat3::OrthoNormalize
// =================================================
void GmMat3::OrthoNormalize() {
    float eps = 1e-6f; // _DAT_00d1a840

    // Normalize Row 0
    float lenSq0 = (this->m00 * this->m00) + (this->m01 * this->m01) + (this->m02 * this->m02);
    if (lenSq0 > eps) {
        float invLen0 = GmFunc::InvSqrt(lenSq0);
        this->m00 *= invLen0;
        this->m01 *= invLen0;
        this->m02 *= invLen0;
    }

    // Row 2 = Row 0 x Row 1
    this->m20 = (this->m01 * this->m12) - (this->m02 * this->m11);
    this->m21 = (this->m02 * this->m10) - (this->m00 * this->m12);
    this->m22 = (this->m00 * this->m11) - (this->m01 * this->m10);

    // Normalize Row 2
    float lenSq2 = (this->m20 * this->m20) + (this->m21 * this->m21) + (this->m22 * this->m22);
    if (lenSq2 > eps) {
        float invLen2 = GmFunc::InvSqrt(lenSq2);
        this->m20 *= invLen2;
        this->m21 *= invLen2;
        this->m22 *= invLen2;
    }

    // Row 1 = Row 2 x Row 0
    this->m10 = (this->m21 * this->m02) - (this->m22 * this->m01);
    this->m11 = (this->m22 * this->m00) - (this->m20 * this->m02);
    this->m12 = (this->m20 * this->m01) - (this->m21 * this->m00);
}

// =================================================
// Function: GmMat3::RotateX
// =================================================
void GmMat3::RotateX(const GmMat3& other, float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);
    float ns = -s;

    this->m00 = other.m00;
    this->m01 = other.m01;
    this->m02 = other.m02;
    
    this->m10 = (other.m10 * c) + (other.m20 * ns);
    this->m11 = (other.m11 * c) + (other.m21 * ns);
    this->m12 = (other.m12 * c) + (other.m22 * ns);
    
    this->m20 = (other.m10 * s) + (other.m20 * c);
    this->m21 = (other.m11 * s) + (other.m21 * c);
    this->m22 = (other.m12 * s) + (other.m22 * c);
}

// =================================================
// Function: GmMat3::RotateY
// =================================================
void GmMat3::RotateY(const GmMat3& other, float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);
    float ns = -s;

    this->m00 = (other.m00 * c) + (other.m20 * s);
    this->m01 = (other.m01 * c) + (other.m21 * s);
    this->m02 = (other.m02 * c) + (other.m22 * s);
    
    this->m10 = other.m10;
    this->m11 = other.m11;
    this->m12 = other.m12;
    
    this->m20 = (other.m00 * ns) + (other.m20 * c);
    this->m21 = (other.m01 * ns) + (other.m21 * c);
    this->m22 = (other.m02 * ns) + (other.m22 * c);
}

// =================================================
// Function: GmMat3::RotateZ
// =================================================
void GmMat3::RotateZ(const GmMat3& other, float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);
    float ns = -s;

    this->m00 = (other.m00 * c) + (other.m10 * ns);
    this->m01 = (other.m01 * c) + (other.m11 * ns);
    this->m02 = (other.m02 * c) + (other.m12 * ns);
    
    this->m10 = (other.m00 * s) + (other.m10 * c);
    this->m11 = (other.m01 * s) + (other.m11 * c);
    this->m12 = (other.m02 * s) + (other.m12 * c);
    
    this->m20 = other.m20;
    this->m21 = other.m21;
    this->m22 = other.m22;
}

// =================================================
// Function: GmMat3::Set (From Quaternion)
// =================================================
void GmMat3::Set(const GmQuat& quat) {
    float x2 = quat.x * 2.0f;
    float y2 = quat.y * 2.0f;
    float z2 = quat.z * 2.0f;
    
    float wx2 = quat.w * x2;
    float wy2 = quat.w * y2;
    float wz2 = quat.w * z2;
    
    float xx2 = quat.x * x2;
    float xy2 = quat.x * y2;
    float xz2 = quat.x * z2;
    
    float yy2 = quat.y * y2;
    float yz2 = quat.y * z2;
    float zz2 = quat.z * z2;
    
    this->m00 = 1.0f - yy2 - zz2;
    this->m01 = xy2 - wz2;
    this->m02 = xz2 + wy2;
    
    this->m10 = xy2 + wz2;
    this->m11 = 1.0f - xx2 - zz2;
    this->m12 = yz2 - wx2;
    
    this->m20 = xz2 - wy2;
    this->m21 = yz2 + wx2;
    this->m22 = 1.0f - xx2 - yy2;
}

// =================================================
// Function: GmMat3::SetBlend
// =================================================
void GmMat3::SetBlend(const GmMat3& a, const GmMat3& b, float t) {
    GmQuat qA, qB, qOut;
    qA.Set(a);
    qB.Set(b);
    
    GmQuat::SetSlerp(qOut, qA, qB, t);
    
    // Fallback equality check logic
    if (std::abs(qOut.w - qA.w) < 1e-4f && std::abs(qOut.x - qA.x) < 1e-4f && 
        std::abs(qOut.y - qA.y) < 1e-4f && GmFunc::AreNearlyEqual(qOut.z, qA.z, 1e-4f)) {
        this->Set(qA);
        return;
    }
    
    this->Set(qOut);
}

// =================================================
// Function: GmMat3::SetDOV
// =================================================
void GmMat3::SetDOV(const GmVec3& dov, const GmVec3* up) {
    GmVec3 crossUp;
    if (!up) {
        crossUp = { dov.y * 0.0f - dov.z * 1.0f, dov.z * 0.0f - dov.x * 0.0f, dov.x * 1.0f - dov.y * 0.0f }; // Rough Cross with UP (0,1,0)
        float lenSq = (crossUp.x * crossUp.x) + (crossUp.y * crossUp.y) + (crossUp.z * crossUp.z);
        
        if (lenSq < 1e-6f) {
            GmVec3 defaultUp = {1.0f, 0.0f, 0.0f};
            SetDOVandUpV(dov, defaultUp);
            return;
        }
        GmVec3 defaultUp = {0.0f, 1.0f, 0.0f};
        SetDOVandUpV(dov, defaultUp);
        return;
    }
    
    SetDOVandUpV(dov, *up);
}

// =================================================
// Function: GmMat3::SetDOVInverse
// =================================================
bool GmMat3::SetDOVInverse(const GmVec3& dov) {
    this->m20 = dov.x;
    this->m21 = dov.y;
    this->m22 = dov.z;
    
    float lenSq2 = (this->m20 * this->m20) + (this->m21 * this->m21) + (this->m22 * this->m22);
    if (lenSq2 <= 1e-6f) return false;
    
    float invLen2 = GmFunc::InvSqrt(lenSq2);
    this->m20 *= invLen2;
    this->m21 *= invLen2;
    this->m22 *= invLen2;
    
    // Cross product with UP (0, 1, 0)
    this->m00 = this->m22;
    this->m01 = 0.0f;
    this->m02 = -this->m20;
    
    float lenSq0 = (this->m00 * this->m00) + (this->m01 * this->m01) + (this->m02 * this->m02);
    if (lenSq0 < 1e-4f) { // Collinear fallback
        this->m00 = 0.0f;
        this->m01 = this->m22;
        this->m02 = -this->m21;
        
        // Cross product with RIGHT (1, 0, 0)
        this->m00 = (this->m11 * this->m22) - (this->m12 * this->m21);
        this->m01 = (this->m12 * this->m20) - (this->m10 * this->m22);
        this->m02 = (this->m10 * this->m21) - (this->m11 * this->m20);
        
        float newLenSq0 = (this->m00 * this->m00) + (this->m01 * this->m01) + (this->m02 * this->m02);
        if (newLenSq0 > 1e-6f) {
            float invLen0 = GmFunc::InvSqrt(newLenSq0);
            this->m00 *= invLen0;
            this->m01 *= invLen0;
            this->m02 *= invLen0;
        }
        
        this->m10 = (this->m02 * this->m21) - (this->m01 * this->m22);
        this->m11 = (this->m00 * this->m22) - (this->m02 * this->m20);
        this->m12 = (this->m01 * this->m20) - (this->m00 * this->m21);
        return true;
    }
    
    // Standard normalizations
    this->m10 = - (this->m22 * this->m01);
    this->m11 = (this->m22 * this->m00) - (this->m20 * this->m02);
    this->m12 = (this->m20 * this->m01);
    
    float lenSq1 = (this->m10 * this->m10) + (this->m11 * this->m11) + (this->m12 * this->m12);
    if (lenSq1 > 1e-6f) {
        float invLen1 = GmFunc::InvSqrt(lenSq1);
        this->m10 *= invLen1;
        this->m11 *= invLen1;
        this->m12 *= invLen1;
    }
    
    this->m00 = (this->m11 * this->m22) - (this->m12 * this->m21);
    this->m01 = (this->m12 * this->m20) - (this->m10 * this->m22);
    this->m02 = (this->m10 * this->m21) - (this->m11 * this->m20);
    return true;
}

// =================================================
// Function: GmMat3::SetDOVandLeftV
// =================================================
void GmMat3::SetDOVandLeftV(const GmVec3& dov, const GmVec3& leftV) {
    GmVec3 crossZ = {
        (dov.y * leftV.z) - (dov.z * leftV.y),
        (dov.z * leftV.x) - (dov.x * leftV.z),
        (dov.x * leftV.y) - (dov.y * leftV.x)
    };
    
    float lenSqZ = (crossZ.x * crossZ.x) + (crossZ.y * crossZ.y) + (crossZ.z * crossZ.z);
    if (lenSqZ > 1e-6f) {
        float invZ = GmFunc::InvSqrt(lenSqZ);
        crossZ.x *= invZ; crossZ.y *= invZ; crossZ.z *= invZ;
    }
    
    GmVec3 normDov = dov;
    float lenSqD = (normDov.x * normDov.x) + (normDov.y * normDov.y) + (normDov.z * normDov.z);
    if (lenSqD > 1e-6f) {
        float invD = GmFunc::InvSqrt(lenSqD);
        normDov.x *= invD; normDov.y *= invD; normDov.z *= invD;
    }
    
    GmVec3 crossX = {
        (crossZ.y * normDov.z) - (crossZ.z * normDov.y),
        (normDov.x * crossZ.z) - (crossZ.x * normDov.z),
        (crossZ.x * normDov.y) - (crossZ.y * normDov.x)
    };
    
    this->SetLine(0, crossX);
    this->SetLine(1, crossZ);
    this->SetLine(2, normDov);
}

// =================================================
// Function: GmMat3::SetDOVandUpV
// =================================================
void GmMat3::SetDOVandUpV(const GmVec3& dov, const GmVec3& upV) {
    GmVec3 crossX = {
        (dov.z * upV.y) - (dov.y * upV.z),
        (dov.x * upV.z) - (upV.x * dov.z),
        (dov.y * upV.x) - (dov.x * upV.y)
    };
    
    float lenSqX = (crossX.x * crossX.x) + (crossX.y * crossX.y) + (crossX.z * crossX.z);
    if (lenSqX > 1e-6f) {
        float invX = GmFunc::InvSqrt(lenSqX);
        crossX.x *= invX; crossX.y *= invX; crossX.z *= invX;
    }
    
    GmVec3 normDov = dov;
    float lenSqD = (normDov.x * normDov.x) + (normDov.y * normDov.y) + (normDov.z * normDov.z);
    if (lenSqD > 1e-6f) {
        float invD = GmFunc::InvSqrt(lenSqD);
        normDov.x *= invD; normDov.y *= invD; normDov.z *= invD;
    }
    
    GmVec3 crossY = {
        (crossX.z * normDov.y) - (crossX.y * normDov.z),
        (crossX.x * normDov.z) - (normDov.x * crossX.z),
        (crossX.y * normDov.x) - (crossX.x * normDov.y)
    };
    
    this->SetLine(0, crossX);
    this->SetLine(1, crossY);
    this->SetLine(2, normDov);
}

// =================================================
// Function: GmMat3::SetIdentity
// =================================================
void GmMat3::SetIdentity() {
    this->m00 = 1.0f; this->m01 = 0.0f; this->m02 = 0.0f;
    this->m10 = 0.0f; this->m11 = 1.0f; this->m12 = 0.0f;
    this->m20 = 0.0f; this->m21 = 0.0f; this->m22 = 1.0f;
}

// =================================================
// Function: GmMat3::SetLine
// =================================================
void GmMat3::SetLine(unsigned long index, const GmVec3& line) {
    float* m = reinterpret_cast<float*>(this);
    m[index * 3 + 0] = line.x;
    m[index * 3 + 1] = line.y;
    m[index * 3 + 2] = line.z;
}

// =================================================
// Function: GmMat3::SetMult
// =================================================
void GmMat3::SetMult(const GmMat3& a, const GmMat3& b) {
    this->m00 = (a.m00 * b.m00) + (a.m01 * b.m10) + (a.m02 * b.m20);
    this->m01 = (a.m00 * b.m01) + (a.m01 * b.m11) + (a.m02 * b.m21);
    this->m02 = (a.m00 * b.m02) + (a.m01 * b.m12) + (a.m02 * b.m22);
    
    this->m10 = (a.m10 * b.m00) + (a.m11 * b.m10) + (a.m12 * b.m20);
    this->m11 = (a.m10 * b.m01) + (a.m11 * b.m11) + (a.m12 * b.m21);
    this->m12 = (a.m10 * b.m02) + (a.m11 * b.m12) + (a.m12 * b.m22);
    
    this->m20 = (a.m20 * b.m00) + (a.m21 * b.m10) + (a.m22 * b.m20);
    this->m21 = (a.m20 * b.m01) + (a.m21 * b.m11) + (a.m22 * b.m21);
    this->m22 = (a.m20 * b.m02) + (a.m21 * b.m12) + (a.m22 * b.m22);
}

// =================================================
// Function: GmMat3::SetRotateQuarterY
// =================================================
void GmMat3::SetRotateQuarterY(unsigned long quarterTurns) {
    float cosT = DAT_00bbd760[quarterTurns & 3];
    float sinT = DAT_00bbd760[(quarterTurns - 1) & 3];
    
    this->m00 = cosT;  this->m01 = 0.0f; this->m02 = sinT;
    this->m10 = 0.0f;  this->m11 = 1.0f; this->m12 = 0.0f;
    this->m20 = -sinT; this->m21 = 0.0f; this->m22 = cosT;
}

// =================================================
// Function: GmMat3::SetTranspose
// =================================================
void GmMat3::SetTranspose(const GmMat3& other) {
    this->m00 = other.m00; this->m01 = other.m10; this->m02 = other.m20;
    this->m10 = other.m01; this->m11 = other.m11; this->m12 = other.m21;
    this->m20 = other.m02; this->m21 = other.m12; this->m22 = other.m22;
}

// =================================================
// Function: GmMat3::SetUpVandDOV
// =================================================
void GmMat3::SetUpVandDOV(const GmVec3& upV, const GmVec3& dov) {
    GmVec3 crossZ = {
        (upV.y * dov.z) - (upV.z * dov.y),
        (upV.z * dov.x) - (upV.x * dov.z),
        (upV.x * dov.y) - (upV.y * dov.x)
    };
    
    float lenSqZ = (crossZ.x * crossZ.x) + (crossZ.y * crossZ.y) + (crossZ.z * crossZ.z);
    if (lenSqZ > 1e-6f) {
        float invZ = GmFunc::InvSqrt(lenSqZ);
        crossZ.x *= invZ; crossZ.y *= invZ; crossZ.z *= invZ;
    }
    
    GmVec3 normUp = upV;
    float lenSqU = (normUp.x * normUp.x) + (normUp.y * normUp.y) + (normUp.z * normUp.z);
    if (lenSqU > 1e-6f) {
        float invU = GmFunc::InvSqrt(lenSqU);
        normUp.x *= invU; normUp.y *= invU; normUp.z *= invU;
    }
    
    GmVec3 crossY = {
        (crossZ.y * normUp.z) - (crossZ.z * normUp.y),
        (normUp.x * crossZ.z) - (crossZ.x * normUp.z),
        (crossZ.x * normUp.y) - (crossZ.y * normUp.x)
    };
    
    this->SetLine(0, crossZ); // X axis
    this->SetLine(1, normUp); // Y axis
    this->SetLine(2, crossY); // Z axis
}

// =================================================
// Function: GmMat3::Transpose
// =================================================
void GmMat3::Transpose() {
    float temp;
    
    temp = this->m01;
    this->m01 = this->m10;
    this->m10 = temp;
    
    temp = this->m02;
    this->m02 = this->m20;
    this->m20 = temp;
    
    temp = this->m12;
    this->m12 = this->m21;
    this->m21 = temp;
}