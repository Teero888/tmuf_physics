#include "GmMat43.hpp"
#include "GmIso4.hpp"

// =================================================
// Function: GmMat43::Set
// =================================================
void GmMat43::Set(const GmIso4& iso)
{
    // Row 0: X-axis rotation + X translation
    row0.x = iso.m00;
    row0.y = iso.m01;
    row0.z = iso.m02;
    row0.w = iso.tX;

    // Row 1: Y-axis rotation + Y translation
    row1.x = iso.m10;
    row1.y = iso.m11;
    row1.z = iso.m12;
    row1.w = iso.tY;

    // Row 2: Z-axis rotation + Z translation
    row2.x = iso.m20;
    row2.y = iso.m21;
    row2.z = iso.m22;
    row2.w = iso.tZ;
}

// =================================================
// Function: GmMat43::SetIdentity
// =================================================
void GmMat43::SetIdentity()
{
    // The hex value 0x3f800000 directly translates to 1.0f
    
    row0.x = 1.0f;
    row0.y = 0.0f;
    row0.z = 0.0f;
    row0.w = 0.0f;

    row1.x = 0.0f;
    row1.y = 1.0f;
    row1.z = 0.0f;
    row1.w = 0.0f;

    row2.x = 0.0f;
    row2.y = 0.0f;
    row2.z = 1.0f;
    row2.w = 0.0f;
}