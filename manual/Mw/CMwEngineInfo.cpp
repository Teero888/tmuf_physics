#include "CMwEngineInfo.hpp"
#include "CMwClassInfo.hpp"

// =================================================
// Function: CMwEngineInfo::CMwEngineInfo
// =================================================
CMwEngineInfo::CMwEngineInfo() {
    // The CFastArray constructor is automatically called for m_classes,
    // initializing its count to 0 and data pointer to nullptr.
    m_rawId = nullptr;
    m_flags = 0;
}

// Default virtual destructor 
CMwEngineInfo::~CMwEngineInfo() {
}

// =================================================
// Function: CMwEngineInfo::AddClass
// Registers a new class into this engine's array, dynamically resizing.
// =================================================
void CMwEngineInfo::AddClass(CMwClassInfo* classInfo) {
    // 1. Extract the Class Index from the Class ID
    // Ghidra: *(uint *)(param_1 + 4) >> 0xc & 0xfff
    // Top 8 bits = Engine ID, Middle 12 bits = Class Index, Bottom 12 bits = Variant
    unsigned int classIndex = (classInfo->m_classId >> 12) & 0xFFF;

    // 2. Ensure the classes array is large enough
    if (m_classes.GetCount() <= classIndex) {
        unsigned int newSize = classIndex + 1;
        
        // Allocate a minimum of 0x20 (32) slots to avoid frequent reallocations
        if (newSize < 32) {
            newSize = 32;
        }
        
        unsigned int oldSize = m_classes.GetCount();
        m_classes.SetCount(newSize);
        
        // Zero-initialize the newly allocated slots
        for (unsigned int i = oldSize; i < newSize; ++i) {
            m_classes[i] = nullptr;
        }
    }

    // 3. Insert the class info into the array
    m_classes[classIndex] = classInfo;
}