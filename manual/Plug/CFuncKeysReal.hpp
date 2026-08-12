#ifndef CFUNCKEYSREAL_HPP
#define CFUNCKEYSREAL_HPP

#include "CFuncKeys.hpp"
#include <cstdint>

class CFuncKeysReal : public CFuncKeys {
public:
    CFastArray<float> m_values; // 0x20 - Key values (Y axis)

    // 0x28, the RealInterp mode archived by chunk 0x0501A001 right after the
    // value array (CFuncKeysReal::Chunk, 0x5861D7). It selects between two
    // evaluators in 0x585E70: mode 1 returns the value of the greatest key at
    // or below x with no blending at all, and every other mode interpolates
    // linearly between the bounding keys.
    //
    // Beware the name. GBX.NET calls value 1 "Linear", but the executable is
    // unambiguous that 1 is the *stepped* branch: 0x585E78 subtracts one and
    // jumps to 0x585EE8, which loads values[i0] and stores it directly, while
    // the fall-through at 0x585E81 is the one that forms
    // (1 - t) * values[i0] + t * values[i1].
    enum ERealInterp : uint32_t {
        kInterpolated = 0,
        kStepped = 1,
    };
    uint32_t m_realInterp = kInterpolated;

    CFuncKeysReal() : CFuncKeys() {}
    virtual ~CFuncKeysReal() {}

    float GetRealAt(float x);
};

#endif // CFUNCKEYSREAL_HPP
