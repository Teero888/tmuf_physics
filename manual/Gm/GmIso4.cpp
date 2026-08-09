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

void GmIso4::SetUScaleTrans(float scale, const GmVec3& trans) {
    SetNUScaleTrans({scale, scale, scale}, trans);
}

void GmIso4::SetNUScaleTrans(const GmVec3& scale, const GmVec3& trans) {
    m00 = scale.x; m01 = 0.0f;    m02 = 0.0f;
    m10 = 0.0f;    m11 = scale.y; m12 = 0.0f;
    m20 = 0.0f;    m21 = 0.0f;    m22 = scale.z;
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

void GmIso4::UScaleSetInverse(const GmIso4& other) {
    rot.SetTranspose(other.rot);
    const float inverseSquaredScale =
        1.0f / (m00 * m00 + m01 * m01 + m02 * m02);
    m00 *= inverseSquaredScale; m01 *= inverseSquaredScale; m02 *= inverseSquaredScale;
    m10 *= inverseSquaredScale; m11 *= inverseSquaredScale; m12 *= inverseSquaredScale;
    m20 *= inverseSquaredScale; m21 *= inverseSquaredScale; m22 *= inverseSquaredScale;
    tX = -other.tX;
    tY = -other.tY;
    tZ = -other.tZ;
    const float inverseTranslationX =
        m00 * tX + m01 * tY + m02 * tZ;
    const float inverseTranslationY =
        m10 * tX + m11 * tY + m12 * tZ;
    const float inverseTranslationZ =
        m20 * tX + m21 * tY + m22 * tZ;
    tX = inverseTranslationX;
    tY = inverseTranslationY;
    tZ = inverseTranslationZ;
}

void GmIso4::NUScaleSetInverse(const GmIso4& other) {
    rot.SetTranspose(other.rot);
    const float inverseSquaredScaleX =
        1.0f / (m00 * m00 + m01 * m01 + m02 * m02);
    const float inverseSquaredScaleY =
        1.0f / (m10 * m10 + m11 * m11 + m12 * m12);
    const float inverseSquaredScaleZ =
        1.0f / (m20 * m20 + m21 * m21 + m22 * m22);
    m00 *= inverseSquaredScaleX; m01 *= inverseSquaredScaleX; m02 *= inverseSquaredScaleX;
    m10 *= inverseSquaredScaleY; m11 *= inverseSquaredScaleY; m12 *= inverseSquaredScaleY;
    m20 *= inverseSquaredScaleZ; m21 *= inverseSquaredScaleZ; m22 *= inverseSquaredScaleZ;
    tX = -other.tX;
    tY = -other.tY;
    tZ = -other.tZ;
    const float inverseTranslationX =
        m00 * tX + m01 * tY + m02 * tZ;
    const float inverseTranslationY =
        m10 * tX + m11 * tY + m12 * tZ;
    const float inverseTranslationZ =
        m20 * tX + m21 * tY + m22 * tZ;
    tX = inverseTranslationX;
    tY = inverseTranslationY;
    tZ = inverseTranslationZ;
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
