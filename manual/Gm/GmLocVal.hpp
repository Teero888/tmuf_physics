#ifndef GMLOCVAL_HPP
#define GMLOCVAL_HPP

#include "GmIso4.hpp"
#include <cstdint>

struct GmLensVal;
struct GmFrustumIso4;

struct GmLocVal {
    GmIso4 m_iso; // 0x00 (Matches padding 36)
    // field_0x24, 0x28, 0x2c might be something else or part of larger iso?
    // Wait, GmIso4 is 0x30 bytes?
    // rot: 0x24, trans: 0x24 to 0x30.
    // field_0x24 in GmLocVal would be tX in GmIso4.
    
    void Reset(GmFrustumIso4* param_1);
    void SetLinearInterp(GmLensVal* p1, GmLensVal* p2, GmLensVal* p3, float t);
};

#endif // GMLOCVAL_HPP
