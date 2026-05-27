#ifndef GMLINE3_HPP
#define GMLINE3_HPP

#include "GmVec3.hpp"

class GmLine3 {
public:
    GmVec3 pos; // 0x00 - 0x0B (Position/Origin of the line)
    GmVec3 dir; // 0x0C - 0x17 (Normalized Direction vector)

    // Standard C++ constructors for ease of use
    GmLine3() = default;
    GmLine3(const GmVec3& position, const GmVec3& direction) 
        : pos(position), dir(direction) {}
};

#endif // GMLINE3_HPP