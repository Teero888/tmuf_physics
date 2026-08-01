#pragma once
#include <cstdint>

template <typename T>
struct CFastCrypt {
    uint32_t key;
    uint32_t encrypted_value;

    T Get() const {
        // Assume T is small enough to fit in uint32_t or is a float
        union { uint32_t u; T t; } val;
        val.u = encrypted_value ^ key;
        return val.t;
    }
    
    void Set(T val) {
        union { uint32_t u; T t; } v;
        v.t = val;
        key = 0x1337BEEF; // Default key
        encrypted_value = v.u ^ key;
    }
};
