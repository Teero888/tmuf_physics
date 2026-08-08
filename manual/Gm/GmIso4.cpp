#include "GmIso4.hpp"
#include "GmVec3.hpp"
#include "GmVec4.hpp"
#include "GmIso3.hpp"
#include "CClassicArchive.hpp"
#include <cmath>

void GmIso4::SetIdentity() {
    rot.SetIdentity();
    tX = tY = tZ = 0.0f;
}

void GmIso4::SetTranslation(const GmVec3& trans) {
    tX = trans.x;
    tY = trans.y;
    tZ = trans.z;
}

void GmIso4::Set(const GmIso4& other) {
    rot.m00 = other.rot.m00; rot.m01 = other.rot.m01; rot.m02 = other.rot.m02;
    rot.m10 = other.rot.m10; rot.m11 = other.rot.m11; rot.m12 = other.rot.m12;
    rot.m20 = other.rot.m20; rot.m21 = other.rot.m21; rot.m22 = other.rot.m22;
    tX = other.tX;
    tY = other.tY;
    tZ = other.tZ;
}

GmVec3 GmIso4::UnTransform(const GmVec3& v) const {
    GmVec3 res(v.x - tX, v.y - tY, v.z - tZ);
    return GmVec3(
        rot.m00 * res.x + rot.m10 * res.y + rot.m20 * res.z,
        rot.m01 * res.x + rot.m11 * res.y + rot.m21 * res.z,
        rot.m02 * res.x + rot.m12 * res.y + rot.m22 * res.z
    );
}

GmVec3 GmIso4::UnTransformVector(const GmVec3& v) const {
    return GmVec3(
        rot.m00 * v.x + rot.m10 * v.y + rot.m20 * v.z,
        rot.m01 * v.x + rot.m11 * v.y + rot.m21 * v.z,
        rot.m02 * v.x + rot.m12 * v.y + rot.m22 * v.z
    );
}

void GmIso4::SetInverse(const GmIso4& other) {
    rot.SetTranspose(other.rot);
    tX = -(rot.m00 * other.tX + rot.m01 * other.tY + rot.m02 * other.tZ);
    tY = -(rot.m10 * other.tX + rot.m11 * other.tY + rot.m12 * other.tZ);
    tZ = -(rot.m20 * other.tX + rot.m21 * other.tY + rot.m22 * other.tZ);
}

void GmIso4::Inverse() {
    const GmIso4 original = *this;
    SetInverse(original);
}

void GmIso4::SetMult(const GmIso4& a, const GmIso4& b) {
    rot.SetMult(a.rot, b.rot);
    tX = b.m00 * a.tX + b.m01 * a.tY + b.m02 * a.tZ + b.tX;
    tY = b.m10 * a.tX + b.m11 * a.tY + b.m12 * a.tZ + b.tY;
    tZ = b.m20 * a.tX + b.m21 * a.tY + b.m22 * a.tZ + b.tZ;
}

void GmIso4::Mult(const GmIso4& other) {
    const GmIso4 original = *this;
    SetMult(original, other);
}

void GmIso4::LeftMult(const GmIso4& other) {
    const GmIso4 original = *this;
    SetMult(other, original);
}

void GmIso4::MultInverse(const GmIso4& other) {
    GmIso4 inverse;
    inverse.SetInverse(other);
    Mult(inverse);
}

void GmIso4::SetBlend(const GmIso4& a, const GmIso4& b, float t) {
    tX = a.tX + (b.tX - a.tX) * t;
    tY = a.tY + (b.tY - a.tY) * t;
    tZ = a.tZ + (b.tZ - a.tZ) * t;
    rot.SetBlend(a.rot, b.rot, t);
}

void GmIso4::SetMult(GmIso4* other) {
    if (other != nullptr) Mult(*other);
}

void GmIso4::Mult(GmIso4* res, void* a) {
    if (res == nullptr || a == nullptr) return;
    res->Mult(*static_cast<GmIso4*>(a));
}
void GmIso4::SetBlend(GmIso4* res, void* p1, void* p2, void* p3, float t) {}
