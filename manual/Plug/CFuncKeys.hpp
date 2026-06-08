#ifndef CFUNCKEYS_HPP
#define CFUNCKEYS_HPP

#include "CFunc.hpp"
#include "CFastArray.hpp"
#include "CMwId.hpp"
#include <cstdint>

class CFuncKeys : public CFunc {
public:
    CFastArray<float> m_keys; // 0x14 - Key times (X axis)
    CMwId m_id;               // 0x1C

    CFuncKeys() : CFunc() {}
    virtual ~CFuncKeys() {}

    int ComputeBlendCoef(float x, uint32_t& index1, uint32_t& index2, float& ratio);
    void GetBoundingIndices(float x, uint32_t& index1, uint32_t& index2);
};

#endif // CFUNCKEYS_HPP
