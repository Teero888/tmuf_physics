#include "GmVec2.hpp"

// =================================================
// Serialization
// =================================================
void GmVec2::ArchiveGmVec2(CClassicArchive& archive) {
    // We now pass '1' for the count parameter, perfectly matching 
    // the (float *)0x1 we saw in the original decompilation.
    archive.DoReal(&this->x, 1);
    archive.DoReal(&this->y, 1);
}

// =================================================
// Basic Math
// =================================================
float GmVec2::GetLength() const {
    // func_0x009c1b40 is likely a fast sqrt implementation
    return std::sqrt((this->x * this->x) + (this->y * this->y));
}

void GmVec2::Normalize() {
    float lenSq = (this->x * this->x) + (this->y * this->y);
    
    // Check against epsilon (_DAT_00ccfe00) to prevent divide by zero
    if (lenSq > 1e-6f) {
        float invLen = 1.0f / std::sqrt(lenSq);
        this->x *= invLen;
        this->y *= invLen;
    }
}

bool GmVec2::IsNearlyEqual(const GmVec2& other, float epsilon) const {
    float dx = this->x - other.x;
    float dy = this->y - other.y;
    
    // _DAT_00d1a968 represents the squared epsilon threshold
    return ((dx * dx) + (dy * dy)) < epsilon; 
}

// =================================================
// Interpolation
// =================================================
void GmVec2::SetBlend(const GmVec2& v1, const GmVec2& v2, float t) {
    // Standard Linear Interpolation (Lerp)
    this->x = v1.x + ((v2.x - v1.x) * t);
    this->y = v1.y + ((v2.y - v1.y) * t);
}

void GmVec2::SetBlendTri(const GmVec2& v0, const GmVec2& v1, const GmVec2& v2, float u, float v) {
    // Barycentric interpolation
    float w = (1.0f - u) - v;
    
    this->x = (w * v0.x) + (u * v1.x) + (v * v2.x);
    this->y = (w * v0.y) + (u * v1.y) + (v * v2.y);
}

// =================================================
// Matrix Math
// =================================================
void GmVec2::Mult(const GmIso3& mat) {
    const float* m = reinterpret_cast<const float*>(&mat);
    
    // Assuming a 2x2 matrix embedded in the struct
    // m[0] = m00, m[1] = m01, m[2] = m10, m[3] = m11
    float oldX = this->x;
    
    this->x = (m[0] * oldX) + (m[1] * this->y);
    this->y = (m[3] * this->y) + (m[2] * oldX);
}

void GmVec2::SetMultInverse(const GmVec2& v, const GmIso3& mat) {
    const float* m = reinterpret_cast<const float*>(&mat);
    
    // In an affine 2D transform, m[4] and m[5] are typically the Translation X and Y
    float tx = m[4]; // 0x10
    float ty = m[5]; // 0x14
    
    float dx = v.x - tx;
    float dy = v.y - ty;
    
    this->x = (m[0] * dx) + (m[2] * dy);
    this->y = (m[3] * dy) + (m[1] * dx);
}

// =================================================
// Geometric Testing
// =================================================
bool GmVec2::IsInTriangle(const GmVec2& v0, const GmVec2& v1, const GmVec2& v2, 
                          const GmVec2& p, float& outU, float& outV, int* outIsInside) 
{
    // Solve for Barycentric coordinates (U and V)
    bool hasSolution = GmFunc::SolveLinearSystem2(
        &outU, &outV,
        v1.x - v0.x, v2.x - v0.x, p.x - v0.x,
        v1.y - v0.y, v2.y - v0.y, p.y - v0.y
    );

    if (!hasSolution) {
        if (outIsInside) *outIsInside = 0;
        return false;
    }

    if (outIsInside) *outIsInside = 1;

    // Check if the point lies inside the triangle boundaries
    // U > 0 && V > 0 && (U + V) < 1.0 (with slight tolerance)
    if (!std::isnan(outU) && outU >= 0.0f && 
        !std::isnan(outV) && outV >= 0.0f && 
        (outU + outV) <= 1.0f) // _DAT_00b2c188 is likely 1.0f + epsilon
    {
        return true;
    }

    return false;
}