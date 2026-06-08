#ifndef CFUNCKEYSREAL_HPP
#define CFUNCKEYSREAL_HPP

#include "CFuncKeys.hpp"
#include <cstdint>

class CFuncKeysReal : public CFuncKeys {
public:
    CFastArray<float> m_values; // 0x20 - Key values (Y axis)
    float* m_ptr28;             // 0x28

    CFuncKeysReal() : CFuncKeys(), m_ptr28(nullptr) {}
    virtual ~CFuncKeysReal() {}

    float GetRealAt(float x);
};

#endif // CFUNCKEYSREAL_HPP
