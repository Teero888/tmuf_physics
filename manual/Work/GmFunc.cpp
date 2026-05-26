#include "GmFunc.hpp"
#include <ctime>

namespace GmFunc {

// =================================================
// Math Utilities
// =================================================

float AsinSafe(float val) {
    if (val < -1.0f) return -1.57079632679f; // -PI/2
    if (val > 1.0f)  return 1.57079632679f;  // PI/2
    return std::asin(val);
}

float ClampReal(float val, float min, float max) {
    return std::clamp(val, min, max);
}

float Mod(float val, float min, float max) {
    if (val >= min && val < max) {
        return val;
    }
    float range = max - min;
    float f = std::fmod(val - min, range);
    if (f < 0.0f) {
        f += range;
    }
    return f + min;
}

float Sign(float val, float sig) {
    return (val <= 0.0f) ? -sig : sig;
}

float Saturate(float val) {
    return std::clamp(val, 0.0f, 1.0f);
}

float Min(float a, float b) {
    return std::min(a, b);
}

float Max(float a, float b) {
    return std::max(a, b);
}

float RandReal(float min, float max) {
    return min + (max - min) * (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX));
}

void SetRandSeed(ulong seed) {
    if (seed == 0xFFFFFFFF) {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    } else {
        std::srand(seed);
    }
}

// =================================================
// Tests & Checks
// =================================================

bool IsANumber(float val) {
    return !std::isnan(val);
}

bool IsZero(float val, float epsilon) {
    return std::abs(val) < epsilon;
}

bool AreNearlyEqual(float a, float b, float epsilon) {
    return std::abs(a - b) < epsilon;
}

// =================================================
// Solvers & Safe Math
// =================================================

bool Div(float* out, float num, float den) {
    // The epsilon checks that the result won't exceed a massive boundary
    // e.g., if eps is 1e-5, max result magnitude is clamped to 100,000
    if (std::abs(num) * 1e-5f < std::abs(den)) { 
        *out = num / den;
        return true;
    }
    return false;
}

bool SolveLinearSystem2(float* out1, float* out2, float a11, float a12, float b1, float a21, float a22, float b2) {
    float det = (a11 * a22) - (a21 * a12);
    float limit = std::abs(det) * 1e-5f; // Boundary check to prevent extreme overflow results
    
    float det1 = (b1 * a22) - (b2 * a12);
    float det2 = (a11 * b2) - (b1 * a21);
    
    if (std::abs(det1) < limit && std::abs(det2) < limit) {
        float invDet = 1.0f / det;
        *out1 = det1 * invDet;
        *out2 = det2 * invDet;
        return true;
    }
    return false;
}

// =================================================
// Serialization Mapping
// =================================================

uchar RealToNat7(float val, float min, float max) {
    float mapped = ((val - min) / (max - min)) * 127.0f;
    mapped = std::clamp(mapped, 0.0f, 127.0f);
    return static_cast<uchar>(std::round(mapped));
}

uchar RealToNat8(float val, float min, float max) {
    float mapped = ((val - min) / (max - min)) * 255.0f;
    mapped = std::clamp(mapped, 0.0f, 255.0f);
    return static_cast<uchar>(std::round(mapped));
}

ushort RealToNat16(float val, float min, float max) {
    float mapped = ((val - min) / (max - min)) * 65535.0f;
    mapped = std::clamp(mapped, 0.0f, 65535.0f);
    return static_cast<ushort>(std::round(mapped));
}

// =================================================
// Spherical Normal Compression
// =================================================

void ReadUnitVec3(CClassicBuffer* buf, GmVec3* out) {
    uchar pitchByte, yawByte;
    buf->Read(&pitchByte, 1);
    buf->Read(&yawByte, 1);

    // Map bytes back to Pitch [-PI/2, PI/2] and Yaw [-PI, PI]
    float pitch = (static_cast<float>(pitchByte) / 255.0f) * 3.14159265f - 1.57079632f;
    float yaw = (static_cast<float>(yawByte) / 255.0f) * 6.28318530f - 3.14159265f;

    float cosPitch = std::cos(pitch);
    out->x = cosPitch * std::cos(yaw);
    out->y = cosPitch * std::sin(yaw);
    out->z = std::sin(pitch);
}

void WriteUnitVec3(CClassicBuffer* buf, GmVec3* vec) {
    float pitch = AsinSafe(vec->z);
    float cosPitch = std::cos(pitch);
    float yaw = 0.0f;

    if (std::abs(cosPitch) >= 1e-6f) { // EPSILON
        float val = ClampReal(vec->x / cosPitch, -1.0f, 1.0f);
        yaw = std::acos(val);
        if (vec->y * cosPitch < 0.0f) {
            yaw = -yaw;
        }
    }

    // Map Pitch [-PI/2, PI/2] and Yaw [-PI, PI] to bytes [0, 255]
    uchar pitchByte = RealToNat8(pitch, -1.57079632f, 1.57079632f);
    uchar yawByte = RealToNat8(yaw, -3.14159265f, 3.14159265f);

    buf->Write(&pitchByte, 1);
    buf->Write(&yawByte, 1);
}

} // namespace GmFunc