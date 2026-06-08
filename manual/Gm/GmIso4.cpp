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

void GmIso4::SetMult(GmIso4* other) {}
void GmIso4::Mult(GmIso4* res, void* a) {}
void GmIso4::SetBlend(GmIso4* res, void* p1, void* p2, void* p3, float t) {}

