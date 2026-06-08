#include "CFuncKeysReal.hpp"

float CFuncKeysReal::GetRealAt(float x) {
    uint32_t i1, i2;
    float ratio;
    if (ComputeBlendCoef(x, i1, i2, ratio)) {
        float y1 = m_values[i1];
        float y2 = m_values[i2];
        return y1 + ratio * (y2 - y1);
    }
    return 0.0f;
}
