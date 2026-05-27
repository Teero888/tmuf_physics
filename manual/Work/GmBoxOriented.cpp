#include "GmBoxOriented.hpp"

// =================================================
// Function: GmBoxOriented::Mult
// Transforms the Oriented Bounding Box by a 4x4 affine matrix.
// =================================================
void GmBoxOriented::Mult(const GmIso4& mat)
{
    // 1. Copy the current axes (This maps exactly to Ghidra's 9-float loop)
    GmMat3 oldAxes = axes;
    
    // 2. Multiply the axes by the rotation matrix
    // These specific dot products perfectly match the unrolled assembly math
    axes.m00 = oldAxes.m20 * mat.m02 + oldAxes.m10 * mat.m01 + oldAxes.m00 * mat.m00;
    axes.m01 = oldAxes.m21 * mat.m02 + oldAxes.m11 * mat.m01 + oldAxes.m01 * mat.m00;
    axes.m02 = oldAxes.m22 * mat.m02 + oldAxes.m12 * mat.m01 + oldAxes.m02 * mat.m00;
    
    axes.m10 = oldAxes.m20 * mat.m12 + oldAxes.m10 * mat.m11 + oldAxes.m00 * mat.m10;
    axes.m11 = oldAxes.m21 * mat.m12 + oldAxes.m11 * mat.m11 + oldAxes.m01 * mat.m10;
    axes.m12 = oldAxes.m22 * mat.m12 + oldAxes.m12 * mat.m11 + oldAxes.m02 * mat.m10;
    
    axes.m20 = oldAxes.m20 * mat.m22 + oldAxes.m10 * mat.m21 + oldAxes.m00 * mat.m20;
    axes.m21 = oldAxes.m21 * mat.m22 + oldAxes.m11 * mat.m21 + oldAxes.m01 * mat.m20;
    axes.m22 = oldAxes.m22 * mat.m22 + oldAxes.m12 * mat.m21 + oldAxes.m02 * mat.m20;

    // 3. Transform the center point (Rotation + Translation)
    // Offset 0x24 corresponds directly to this->center
    center.Mult(mat);
}