#include "SPlugFaceCull.hpp"

// =================================================
// Function: SPlugFaceCull::SetMult
// =================================================
void SPlugFaceCull::SetMult(const SPlugFaceCull& other, const GmIso4& mat)
{
    // The decompiled assembly loop (iVar3 = 2) perfectly translates to this
    for (int i = 0; i < 2; ++i) {
        const CullElement& src = other.elements[i];
        CullElement& dst = this->elements[i];

        // 1. Transform the center point (Rotation + Translation)
        dst.center.x = src.center.x * mat.m00 + src.center.y * mat.m01 + src.center.z * mat.m02 + mat.tX;
        dst.center.y = src.center.x * mat.m10 + src.center.y * mat.m11 + src.center.z * mat.m12 + mat.tY;
        dst.center.z = src.center.x * mat.m20 + src.center.y * mat.m21 + src.center.z * mat.m22 + mat.tZ;

        // 2. Transform the axis/normal (Rotation only)
        dst.axis.x = src.axis.x * mat.m00 + src.axis.y * mat.m01 + src.axis.z * mat.m02;
        dst.axis.y = src.axis.x * mat.m10 + src.axis.y * mat.m11 + src.axis.z * mat.m12;
        dst.axis.z = src.axis.x * mat.m20 + src.axis.y * mat.m21 + src.axis.z * mat.m22;

        // 3. Copy the scalar directly
        dst.scalar = src.scalar;
    }
}