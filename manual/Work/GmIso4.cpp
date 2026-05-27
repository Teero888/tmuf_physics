#include "GmIso4.hpp"

// Assuming standard definitions from your earlier files
#include "GmVec3.hpp"
#include "GmVec4.hpp"
#include "GmIso3.hpp"
#include "CClassicArchive.hpp"

// =================================================
// Function: GmIso4::ArchiveGmIso4
// =================================================
void GmIso4::ArchiveGmIso4(CClassicArchive& archive) {
    this->rot.ArchiveGmMat3(archive);
    archive.DoReal(&this->tX, 1);
    archive.DoReal(&this->tY, 1);
    archive.DoReal(&this->tZ, 1);
}

// =================================================
// Function: GmIso4::GetDir
// =================================================
void GmIso4::GetDir(GmVec3& outDir) const {
    outDir.x = this->m02;
    outDir.y = this->m12;
    outDir.z = this->m22;
}

// =================================================
// Function: GmIso4::GetUp
// =================================================
void GmIso4::GetUp(GmVec3& outUp) const {
    outUp.x = this->m01;
    outUp.y = this->m11;
    outUp.z = this->m21;
}

// =================================================
// Function: GmIso4::GetPlaneEq
// =================================================
void GmIso4::GetPlaneEq(unsigned long axis, GmVec4& outPlane) const {
    GmVec3 line;
    this->rot.GetLine(axis, line);
    outPlane.x = line.x;
    outPlane.y = line.y;
    outPlane.z = line.z;
    // Compute distance (D = -Dot(Normal, Position))
    outPlane.w = -(line.x * this->tX) - (line.y * this->tY) - (line.z * this->tZ);
}

// =================================================
// Function: GmIso4::IsNearlyEqual
// =================================================
bool GmIso4::IsNearlyEqual(const GmIso4& other) const {
    float eps = 1e-5f; // Standard engine epsilon
    if (std::abs(this->tX - other.tX) > eps) return false;
    if (std::abs(this->tY - other.tY) > eps) return false;
    if (std::abs(this->tZ - other.tZ) > eps) return false;
    return this->rot.IsNearlyEqual(other.rot);
}

// =================================================
// Function: GmIso4::NUGetIso4AndScale
// =================================================
void GmIso4::NUGetIso4AndScale(GmIso4& outMat, GmVec3& outScale) const {
    outMat = *this;
    
    // Decompiler mapped this to Transpose, but it's extracting column lengths
    float lenSqX = (outMat.m00 * outMat.m00) + (outMat.m10 * outMat.m10) + (outMat.m20 * outMat.m20);
    float lenSqY = (outMat.m01 * outMat.m01) + (outMat.m11 * outMat.m11) + (outMat.m21 * outMat.m21);
    float lenSqZ = (outMat.m02 * outMat.m02) + (outMat.m12 * outMat.m12) + (outMat.m22 * outMat.m22);
    
    outScale.x = 1.0f / GmFunc::InvSqrt(lenSqX);
    outScale.y = 1.0f / GmFunc::InvSqrt(lenSqY);
    outScale.z = 1.0f / GmFunc::InvSqrt(lenSqZ);
    
    float invX = 1.0f / outScale.x;
    outMat.m00 *= invX;
    outMat.m10 *= invX;
    outMat.m20 *= invX;
    
    float invY = 1.0f / outScale.y;
    outMat.m01 *= invY;
    outMat.m11 *= invY;
    outMat.m21 *= invY;
    
    float invZ = 1.0f / outScale.z;
    outMat.m02 *= invZ;
    outMat.m12 *= invZ;
    outMat.m22 *= invZ;
    
    if (outMat.rot.IsIndirect()) {
        outMat.m00 = -outMat.m00;
        outMat.m10 = -outMat.m10;
        outMat.m20 = -outMat.m20;
        outScale.x = -outScale.x;
    }
}

// =================================================
// Function: GmIso4::Set
// =================================================
void GmIso4::Set(const GmIso4& other) {
    this->rot.Set(other.rot);
    this->tX = other.tX;
    this->tY = other.tY;
    this->tZ = other.tZ;
}

// =================================================
// Function: GmIso4::SetRow (Decompiler labeled SetColumn)
// =================================================
void GmIso4::SetRow(unsigned long index, const GmVec4& row) {
    float* m = reinterpret_cast<float*>(this);
    m[index * 3 + 0] = row.x;
    m[index * 3 + 1] = row.y;
    m[index * 3 + 2] = row.z;
    m[9 + index]     = row.w; // 9 = tX offset
}

// =================================================
// Function: GmIso4::SetXY
// =================================================
void GmIso4::SetXY(const GmIso3& iso2d) {
    this->m00 = iso2d.m00;
    this->m01 = iso2d.m01;
    this->m02 = 0.0f;
    
    this->m10 = iso2d.m10;
    this->m11 = iso2d.m11;
    this->m12 = 0.0f;
    
    this->m20 = 0.0f;
    this->m21 = 0.0f;
    this->m22 = 1.0f;
    
    this->tX = iso2d.tX;
    this->tY = iso2d.tY;
    this->tZ = 0.0f;
}

// =================================================
// Function: GmIso4::SetIdentity
// =================================================
void GmIso4::SetIdentity() {
    this->rot.SetIdentity();
    this->tX = 0.0f;
    this->tY = 0.0f;
    this->tZ = 0.0f;
}

// =================================================
// Function: GmIso4::SetBlend
// =================================================
void GmIso4::SetBlend(const GmIso4& a, const GmIso4& b, float t) {
    this->tX = a.tX + (b.tX - a.tX) * t;
    this->tY = a.tY + (b.tY - a.tY) * t;
    this->tZ = a.tZ + (b.tZ - a.tZ) * t;
    this->rot.SetBlend(a.rot, b.rot, t);
}

// =================================================
// Function: GmIso4::SetLookAt
// =================================================
void GmIso4::SetLookAt(const GmVec3& pos, const GmVec3& target, const GmVec3& up) {
    GmVec3 dir = { target.x - pos.x, target.y - pos.y, target.z - pos.z };
    this->rot.SetDOV(dir, up);
    this->tX = pos.x;
    this->tY = pos.y;
    this->tZ = pos.z;
}

// =================================================
// Function: GmIso4::SetTranslation
// =================================================
void GmIso4::SetTranslation(const GmVec3& trans) {
    this->tX = trans.x;
    this->tY = trans.y;
    this->tZ = trans.z;
}

// =================================================
// Function: GmIso4::SetUScaleTrans
// =================================================
void GmIso4::SetUScaleTrans(float scale, const GmVec3& trans) {
    this->m00 = scale; this->m01 = 0.0f;  this->m02 = 0.0f;
    this->m10 = 0.0f;  this->m11 = scale; this->m12 = 0.0f;
    this->m20 = 0.0f;  this->m21 = 0.0f;  this->m22 = scale;
    
    this->tX = trans.x;
    this->tY = trans.y;
    this->tZ = trans.z;
}

// =================================================
// Function: GmIso4::SetNUScaleTrans
// =================================================
void GmIso4::SetNUScaleTrans(const GmVec3& scale, const GmVec3& trans) {
    this->m00 = scale.x; this->m01 = 0.0f;    this->m02 = 0.0f;
    this->m10 = 0.0f;    this->m11 = scale.y; this->m12 = 0.0f;
    this->m20 = 0.0f;    this->m21 = 0.0f;    this->m22 = scale.z;
    
    this->tX = trans.x;
    this->tY = trans.y;
    this->tZ = trans.z;
}

// =================================================
// Function: GmIso4::Inverse
// =================================================
void GmIso4::Inverse() {
    this->rot.Transpose();
    
    float invTx = -this->tX;
    float invTy = -this->tY;
    float invTz = -this->tZ;
    
    this->tX = (invTx * this->m00) + (invTy * this->m10) + (invTz * this->m20);
    this->tY = (invTx * this->m01) + (invTy * this->m11) + (invTz * this->m21);
    this->tZ = (invTx * this->m02) + (invTy * this->m12) + (invTz * this->m22);
}

// =================================================
// Function: GmIso4::SetInverse
// =================================================
void GmIso4::SetInverse(const GmIso4& other) {
    this->rot.SetTranspose(other.rot);
    
    float invTx = -other.tX;
    float invTy = -other.tY;
    float invTz = -other.tZ;
    
    this->tX = (invTx * this->m00) + (invTy * this->m10) + (invTz * this->m20);
    this->tY = (invTx * this->m01) + (invTy * this->m11) + (invTz * this->m21);
    this->tZ = (invTx * this->m02) + (invTy * this->m12) + (invTz * this->m22);
}

// =================================================
// Function: GmIso4::UScaleSetInverse
// =================================================
void GmIso4::UScaleSetInverse(const GmIso4& other) {
    // For uniform scale, Transpose doesn't strictly invert the scale, 
    // it requires multiplication. Decompiler calls GmMat3::Mult here.
    GmIso4 tempInv = other;
    tempInv.rot.Transpose();
    this->rot.Mult(tempInv.rot);
    
    float invTx = -other.tX;
    float invTy = -other.tY;
    float invTz = -other.tZ;
    
    this->tX = (invTx * this->m00) + (invTy * this->m10) + (invTz * this->m20);
    this->tY = (invTx * this->m01) + (invTy * this->m11) + (invTz * this->m21);
    this->tZ = (invTx * this->m02) + (invTy * this->m12) + (invTz * this->m22);
}

// =================================================
// Function: GmIso4::NUScaleSetInverse
// =================================================
void GmIso4::NUScaleSetInverse(const GmIso4& other) {
    this->rot.SetTranspose(other.rot);
    
    float lenX2 = (this->m00 * this->m00) + (this->m01 * this->m01) + (this->m02 * this->m02);
    float lenY2 = (this->m10 * this->m10) + (this->m11 * this->m11) + (this->m12 * this->m12);
    float lenZ2 = (this->m20 * this->m20) + (this->m21 * this->m21) + (this->m22 * this->m22);
    
    float invSqX = 1.0f / lenX2;
    float invSqY = 1.0f / lenY2;
    float invSqZ = 1.0f / lenZ2;
    
    this->m00 *= invSqX; this->m01 *= invSqX; this->m02 *= invSqX;
    this->m10 *= invSqY; this->m11 *= invSqY; this->m12 *= invSqY;
    this->m20 *= invSqZ; this->m21 *= invSqZ; this->m22 *= invSqZ;
    
    float invTx = -other.tX;
    float invTy = -other.tY;
    float invTz = -other.tZ;
    
    this->tX = (invTx * this->m00) + (invTy * this->m10) + (invTz * this->m20);
    this->tY = (invTx * this->m01) + (invTy * this->m11) + (invTz * this->m21);
    this->tZ = (invTx * this->m02) + (invTy * this->m12) + (invTz * this->m22);
}

// =================================================
// Function: GmIso4::Mult
// =================================================
void GmIso4::Mult(const GmIso4& other) {
    GmIso4 temp = *this;
    this->SetMult(temp, other);
}

// =================================================
// Function: GmIso4::SetMult
// =================================================
void GmIso4::SetMult(const GmIso4& a, const GmIso4& b) {
    this->m00 = (a.m00 * b.m00) + (a.m01 * b.m10) + (a.m02 * b.m20);
    this->m01 = (a.m00 * b.m01) + (a.m01 * b.m11) + (a.m02 * b.m21);
    this->m02 = (a.m00 * b.m02) + (a.m01 * b.m12) + (a.m02 * b.m22);
    
    this->m10 = (a.m10 * b.m00) + (a.m11 * b.m10) + (a.m12 * b.m20);
    this->m11 = (a.m10 * b.m01) + (a.m11 * b.m11) + (a.m12 * b.m21);
    this->m12 = (a.m10 * b.m02) + (a.m11 * b.m12) + (a.m12 * b.m22);
    
    this->m20 = (a.m20 * b.m00) + (a.m21 * b.m10) + (a.m22 * b.m20);
    this->m21 = (a.m20 * b.m01) + (a.m21 * b.m11) + (a.m22 * b.m21);
    this->m22 = (a.m20 * b.m02) + (a.m21 * b.m12) + (a.m22 * b.m22);
    
    this->tX = (a.tX * b.m00) + (a.tY * b.m10) + (a.tZ * b.m20) + b.tX;
    this->tY = (a.tX * b.m01) + (a.tY * b.m11) + (a.tZ * b.m21) + b.tY;
    this->tZ = (a.tX * b.m02) + (a.tY * b.m12) + (a.tZ * b.m22) + b.tZ;
}

// =================================================
// Function: GmIso4::LeftMult
// =================================================
void GmIso4::LeftMult(const GmIso4& other) {
    GmIso4 temp = *this;
    this->SetMult(other, temp);
}

// =================================================
// Function: GmIso4::MultInverse
// =================================================
void GmIso4::MultInverse(const GmIso4& other) {
    GmIso4 invOther;
    invOther.SetInverse(other);
    this->Mult(invOther);
}

// =================================================
// Function: GmIso4::RotateX
// =================================================
void GmIso4::RotateX(float angle) {
    GmIso4 temp = *this;
    this->rot.RotateX(temp.rot, angle);
}

// =================================================
// Function: GmIso4::RotateY
// =================================================
void GmIso4::RotateY(float angle) {
    GmIso4 temp = *this;
    this->rot.RotateY(temp.rot, angle);
}

// =================================================
// Function: GmIso4::RotateZ
// =================================================
void GmIso4::RotateZ(float angle) {
    GmIso4 temp = *this;
    this->rot.RotateZ(temp.rot, angle);
}

// =================================================
// Function: GmIso4::SymmetryPlane
// =================================================
void GmIso4::SymmetryPlane(const GmIso4& mat, const GmVec4& plane) {
    // Projects/Reflects the matrix across the given plane
    GmVec3 line;
    for (unsigned long i = 0; i < 3; ++i) {
        mat.rot.GetLine(i, line);
        
        float dot2 = (line.x * plane.x) + (line.y * plane.y) + (line.z * plane.z);
        dot2 *= 2.0f;
        
        line.x -= dot2 * plane.x;
        line.y -= dot2 * plane.y;
        line.z -= dot2 * plane.z;
        
        this->rot.SetLine(i, line);
    }
    
    float dotTrans = (mat.tX * plane.x) + (mat.tY * plane.y) + (mat.tZ * plane.z) + plane.w;
    dotTrans *= 2.0f;
    
    this->tX = mat.tX - (dotTrans * plane.x);
    this->tY = mat.tY - (dotTrans * plane.y);
    this->tZ = mat.tZ - (dotTrans * plane.z);
}