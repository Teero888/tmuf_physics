#include "CMwEngineManager.hpp"
#include "CMwEngineInfo.hpp" // Needs to define CMwEngineInfo class
#include "CMwClassInfo.hpp"  // Needs to define CMwClassInfo class
#include "CFastString.hpp"
#include "CMwDeprecated.hpp" // Mocks for deprecated wrap functions
#include "CClassicLog.hpp"   // Logger mock

// External table mapping Engine IDs to global pointers (Observed at 0xd35d04)
struct SEngineMapping {
    CMwEngineInfo* enginePtr;
    uint32_t engineFlags;
};
extern SEngineMapping DAT_00d35d04[46]; // 0x2e elements

// =================================================
// Function: CMwEngineManager::AddClass
// =================================================
void CMwEngineManager::AddClass(CMwEngineInfo* enginePtr, CMwClassInfo* classInfo) {
    // 1. Extract Engine ID from the CMwEngineInfo 
    // Ghidra: *(uint *)(param_1 + 4) >> 0x18
    unsigned int engineIdFull = enginePtr->m_engineId;
    unsigned int engineIndex = engineIdFull >> 24; 
    
    // Mask off the top 8 bits for the raw ID
    void* rawEngineId = reinterpret_cast<void*>(engineIdFull & 0xFF000000);

    // 2. Ensure the engines array is large enough
    if (m_engines.GetCount() <= engineIndex) {
        unsigned int newSize = engineIndex + 1;
        // Allocate minimum of 0x30 (48) engines to avoid constant resizing
        if (newSize < 48) {
            newSize = 48;
        }
        
        unsigned int oldSize = m_engines.GetCount();
        m_engines.SetCount(newSize);
        
        // Zero-initialize the newly allocated slots
        for (unsigned int i = oldSize; i < newSize; ++i) {
            m_engines[i] = nullptr;
        }
    }

    // 3. Get or Create the Engine Info slot
    CMwEngineInfo* registeredEngine = m_engines[engineIndex];
    
    if (registeredEngine == nullptr) {
        // Allocate a new CMwEngineInfo (Size 0x14 / 20 bytes)
        registeredEngine = new CMwEngineInfo();
        m_engines[engineIndex] = registeredEngine;
        
        // Set the raw ID string/pointer
        registeredEngine->m_rawId = rawEngineId;
        
        // Scan the global mapping table to set specific engine flags
        for (unsigned int i = 0; i < 46; ++i) {
            if (DAT_00d35d04[i].enginePtr == enginePtr) {
                registeredEngine->m_flags = DAT_00d35d04[i].engineFlags;
                break;
            }
        }
    }

    // 4. Add the class to the specific engine
    registeredEngine->AddClass(classInfo);
}

// =================================================
// Function: CMwEngineManager::GetClassInfo
// =================================================
CMwClassInfo* CMwEngineManager::GetClassInfo(uint32_t classId) {
    // Legacy support wrapper
    uint32_t wrappedId = CMwDeprecated::WrapClassId(classId);

    // Extract the indices based on bitwise structure
    unsigned int engineIndex = wrappedId >> 24;
    unsigned int classIndex = (wrappedId >> 12) & 0xFFF;

    // 1. Lookup Engine
    if (engineIndex < m_engines.GetCount()) {
        CMwEngineInfo* engine = m_engines[engineIndex];
        
        if (engine != nullptr) {
            // 2. Lookup Class within Engine (m_classes is offset 0x0C in CMwEngineInfo)
            if (classIndex < engine->m_classes.GetCount()) {
                CMwClassInfo* info = engine->m_classes[classIndex];
                if (info != nullptr) {
                    return info;
                }
            }
        }
    }

    // --- Failure Path (Logging) ---
    // Emulate the error logging seen in Ghidra output
    CFastString errorStr;
    // CFastString::Format(&errorStr, 
    //     "Trying to use a class (0x%08x) from engine \"%s\", which is not available in this exe.", 
    //     classId, "UnknownEngine");

    // CClassicLog::AddLogStringInFile(errorStr.GetCStr());

    return nullptr;
}