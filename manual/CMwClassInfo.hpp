#ifndef CMWCLASSINFO_HPP
#define CMWCLASSINFO_HPP

#include "CFastString.hpp"
#include <cstdint>

// Forward Declarations
class CMwNod;
struct SMwParamInfo;

// =================================================
// CMwClassInfo
// Metadata descriptor for a specific engine class.
// Size: 40 bytes (0x28)
// =================================================
class CMwClassInfo {
public:
    virtual ~CMwClassInfo();                // 0x00 - vftable

    uint32_t m_classId;                // 0x04 - The 32-bit unique class identifier
    CMwClassInfo* m_parent;                 // 0x08 - Pointer to the base class info
    
    // Deduced padding based on AddChild method calls and standard tree layouts
    void* m_firstChild;                     // 0x0C - Intrusive tree child pointer
    void* m_sibling;                        // 0x10 - Intrusive tree sibling pointer
    
    const char* m_className;                // 0x14 - String literal of the class name
    CMwClassInfo* m_next;                   // 0x18 - Next class in the global registry linked list
    
    // Instantiator function pointer to create a new CMwNod of this type
    typedef CMwNod* (*InstantiatorFunc)();
    InstantiatorFunc m_pInstantiator;       // 0x1C
    
    SMwParamInfo** m_params;                // 0x20 - Array of parameter metadata
    unsigned int m_paramCount;              // 0x24 - Number of parameters

    // Member Functions
    static void BuildTree(CMwClassInfo* root);
    static CMwClassInfo* FindFromClassName(CFastString* className);
    
    bool IsMwParamIdEqualName(uint32_t paramId, const char* paramName) const;
    uint32_t MwGetNearestFather(uint32_t count, uint32_t* parentIds) const;
    
    // Helper implied by BuildTree assembly
    void AddChild(CMwClassInfo* childClass);
};

#endif // CMWCLASSINFO_HPP