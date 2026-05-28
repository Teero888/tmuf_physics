#ifndef SMWIDINTERNAL_HPP
#define SMWIDINTERNAL_HPP

#include "CFastBuffer.hpp"
#include "CFastArray.hpp"
#include <cstdint>

// =================================================
// SMwIdInternal
// The global engine string dictionary memory arena.
// Size: 272 bytes (0x110)
// =================================================
struct SMwIdInternal {
    // 0x00 to 0x0B (12 bytes)
    // Memory arena pre-allocated to hold raw character strings
    CFastBuffer<char> m_stringArena; 

    // 0x0C to 0x10B (256 bytes)
    // 32 individual CFastArrays (8 bytes each). 
    // The top bits of the CMwId determine which bucket to look in.
    CFastArray<const char*> m_buckets[32]; 

    // 0x10C to 0x10F (4 bytes)
    // Boolean flag set to 1 at the end of CMwId::StaticInit
    uint32_t m_isInitialized; 

    // Member Functions
    SMwIdInternal();
};

#endif // SMWIDINTERNAL_HPP