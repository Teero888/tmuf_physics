#ifndef CMWENGINEINFO_HPP
#define CMWENGINEINFO_HPP

#include "CFastArray.hpp"
#include <cstdint>

// Forward Declarations
class CMwClassInfo;

// =================================================
// CMwEngineInfo
// Internal registry holding all classes for a specific engine module.
// Size: 20 bytes (0x14)
// =================================================
class CMwEngineInfo {
public:
    virtual ~CMwEngineInfo(); // 0x00 - vftable
    
    // The field at 0x04 is used for both the engine ID (for bitwise lookups)
    // and the name pointer (for debugging/identification).
    // Use an anonymous union to allow both interpretations safely.
    union {
        uint32_t m_engineId;  // 0x04 - Used for bit-shifting lookups
        void* m_rawId;        // 0x04 - Used as the engine name identifier
    };
    uint32_t m_flags;               // 0x08 - Engine specific flags
    CFastArray<CMwClassInfo*> m_classes; // 0x0C - Array of registered classes

    // Member Functions
    CMwEngineInfo();
    void AddClass(CMwClassInfo* classInfo);
};

#endif // CMWENGINEINFO_HPP