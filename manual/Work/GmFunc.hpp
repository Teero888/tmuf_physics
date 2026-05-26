#ifndef GMFUNC_HPP
#define GMFUNC_HPP

#include "typedefs.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>

// Forward declarations
class CClassicBuffer;
struct GmVec3;

namespace GmFunc {
    // Math Utilities
    float AsinSafe(float val);
    float ClampReal(float val, float min, float max);
    float Mod(float val, float min, float max); // Wraps a value between min and max
    float Sign(float val, float sig);
    float Saturate(float val);
    float Min(float a, float b);
    float Max(float a, float b);
    float RandReal(float min, float max);
    void SetRandSeed(ulong seed);

    // Tests & Checks
    bool IsANumber(float val);
    bool IsZero(float val, float epsilon = 1e-6f);
    bool AreNearlyEqual(float a, float b, float epsilon = 1e-6f);

    // Solvers & Safe Math
    bool Div(float* out, float num, float den);
    bool SolveLinearSystem2(float* out1, float* out2, float a11, float a12, float b1, float a21, float a22, float b2);

    // Serialization & Mapping
    uchar RealToNat7(float val, float min, float max);
    uchar RealToNat8(float val, float min, float max);
    ushort RealToNat16(float val, float min, float max);
    
    void ReadUnitVec3(CClassicBuffer* buf, GmVec3* out);
    void WriteUnitVec3(CClassicBuffer* buf, GmVec3* vec);
};

#endif // GMFUNC_HPP