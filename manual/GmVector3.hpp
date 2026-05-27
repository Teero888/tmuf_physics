#ifndef GMVECTOR3_HPP
#define GMVECTOR3_HPP

template <typename T>
struct GmVector3 {
    T x; // Offset 0x0
    T y; // Offset 0x4
    T z; // Offset 0x8

    // Clamps the current vector's values between a min and max vector.
    void Clamp(const GmVector3<T>& min, const GmVector3<T>& max);
};

#endif // GMVECTOR3_HPP