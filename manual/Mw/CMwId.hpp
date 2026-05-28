#ifndef CMWID_HPP
#define CMWID_HPP

#include "CFastString.hpp"
#include <cstdint> // For cross-platform 32-bit safety

// =================================================
// CMwId
// A highly optimized 32-bit identifier used to replace 
// strings for fast comparisons and memory saving.
// Size: 4 bytes (0x04)
// =================================================
class CMwId {
public:
    uint32_t m_id; // 0x00 - No VTable! Just the raw 32-bit ID

    // Constructors
    CMwId() : m_id(0xFFFFFFFF) {} // Default uninitialized state is typically -1
    CMwId(uint32_t id) : m_id(id) {}

    // Member Functions
    static void StaticInit();
    static CMwId CreateFromLocalIndex(uint32_t index);
    static CMwId CreateFromLocalName(const char* name);
    
    void SetLocalName(const char* name);
    const char* GetString() const;
    CFastString GetName() const;

    // Operator overloads to make it behave like an integer
    inline bool operator==(const CMwId& other) const { return m_id == other.m_id; }
    inline bool operator!=(const CMwId& other) const { return m_id != other.m_id; }
};

#endif // CMWID_HPP