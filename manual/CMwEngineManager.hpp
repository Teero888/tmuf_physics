#ifndef CMWENGINEMANAGER_HPP
#define CMWENGINEMANAGER_HPP

#include "CFastArray.hpp"

// Forward Declarations
class CMwEngineInfo;
class CMwClassInfo;

// =================================================
// CMwEngineManager
// Global registry for all module engines and their classes.
// Size: 12 bytes (0x0C)
// =================================================
class CMwEngineManager {
public:
    virtual ~CMwEngineManager() {} // 0x00 - vftable

    // The decompiler shows "this + 4" being passed to CFastBuffer functions.
    // This is an array of pointers to CMwEngineInfo objects.
    CFastArray<CMwEngineInfo*> m_engines; // 0x04

    // Member Functions
    CMwClassInfo* GetClassInfo(unsigned long classId);
    void AddClass(CMwEngineInfo* engine, CMwClassInfo* classInfo);
};

#endif // CMWENGINEMANAGER_HPP