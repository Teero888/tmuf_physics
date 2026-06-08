#include "CFuncKeys.hpp"

void CFuncKeys::GetBoundingIndices(float x, uint32_t& index1, uint32_t& index2) {
    uint32_t count = m_keys.m_count;
    if (count == 0) {
        index1 = 0xFFFFFFFF;
        index2 = 0xFFFFFFFF;
        return;
    }
    if (count == 1) {
        index1 = 0;
        index2 = 0;
        return;
    }

    if (x <= m_keys[0]) {
        index1 = 0;
        index2 = 0;
        return;
    }
    if (x >= m_keys[count - 1]) {
        index1 = count - 1;
        index2 = count - 1;
        return;
    }

    // Binary search or linear scan for the bounding interval
    for (uint32_t i = 0; i < count - 1; ++i) {
        if (x >= m_keys[i] && x <= m_keys[i+1]) {
            index1 = i;
            index2 = i + 1;
            return;
        }
    }
}

int CFuncKeys::ComputeBlendCoef(float x, uint32_t& index1, uint32_t& index2, float& ratio) {
    GetBoundingIndices(x, index1, index2);
    if (index1 == 0xFFFFFFFF) return 0;
    if (index1 == index2) {
        ratio = 0.0f;
        return 1;
    }

    float x1 = m_keys[index1];
    float x2 = m_keys[index2];
    if (std::abs(x2 - x1) < 1e-6f) {
        ratio = 0.0f;
    } else {
        ratio = (x - x1) / (x2 - x1);
    }
    return 1;
}
