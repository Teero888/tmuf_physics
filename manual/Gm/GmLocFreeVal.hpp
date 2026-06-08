#ifndef GMLOCFREEVAL_HPP
#define GMLOCFREEVAL_HPP

#include <cstdint>

struct GmIso4;
struct GmLocVal;
struct GmFrustumIso4;

struct GmLocFreeVal {
    float m_data[6]; // 0x00 to 0x14

    void GetLocVal(GmLocVal* out);
    void Reset(GmFrustumIso4* param_1);
};

#endif // GMLOCFREEVAL_HPP
