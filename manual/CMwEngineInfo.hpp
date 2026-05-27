#ifndef CMWENGINEINFO_HPP
#define CMWENGINEINFO_HPP

#include "CFastArray.hpp"

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
    
    void* m_rawId;                       // 0x04 - Raw Engine ID / Name Pointer
    uint32_t m_flags;               // 0x08 - Engine specific flags
    CFastArray<CMwClassInfo*> m_classes; // 0x0C - Array of registered classes

    // Member Functions
    CMwEngineInfo();
    void AddClass(CMwClassInfo* classInfo);
};

#endif // CMWENGINEINFO_HPP