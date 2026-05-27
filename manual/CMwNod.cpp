#include "CMwNod.hpp"
#include "CMwEngineManager.hpp"
#include "CClassicArchive.hpp"
#include "CMwStack.hpp"
#include "CMwClassInfo.hpp"
#include "CMwEngineInfo.hpp"

// External Globals specific to Nadeo Engine memory
extern CMwEngineInfo* DAT_00d73ba8;
extern CMwEngineManager DAT_00d73344;
extern void (*DAT_00d7333c)(CMwNod*);

// =================================================
// Constructor & Destructor
// =================================================

CMwNod::CMwNod() {
    m_refCount = 0;
    m_flags = 0;
    m_dependants = nullptr;
    m_receivers = nullptr;
}

CMwNod::~CMwNod() {
    // Notify a global manager if registered
    if (m_flags != 0 && DAT_00d7333c != nullptr) {
        DAT_00d7333c(this);
    }
    
    // Notify graph we are dying
    if (m_dependants != nullptr) {
        DependantSendMwIsKilled(nullptr);
    }
    
    // Free receivers list
    if (m_receivers != nullptr) {
        delete m_receivers;
        m_receivers = nullptr;
    }
}

// =================================================
// Core Static Factory & Reflection
// =================================================

void CMwNod::StaticInit() {
    // Iterate through loaded engine modules and register their classes
    for (CMwEngineInfo* engine = DAT_00d73ba8; engine != nullptr; engine = engine->m_next) {
        CMwNod tempNod;
        tempNod.AddClass(engine, nullptr);
    }
    CMwClassInfo::BuildTree(DAT_00d73ba8, nullptr);
}

void CMwNod::AddClass(CMwEngineInfo* engine, CMwClassInfo* classInfo) {
    CMwEngineManager::AddClass(&DAT_00d73344, engine, classInfo);
}

CMwClassInfo* CMwNod::StaticGetClassInfo(uint32_t classId) {
    return CMwEngineManager::GetClassInfo(&DAT_00d73344, classId);
}

CMwNod* CMwNod::CreateByMwClassId(uint32_t classId) {
    CMwClassInfo* classInfo = StaticGetClassInfo(classId);
    if (classInfo != nullptr) {
        // Offset 0x1C in CMwClassInfo is typically the instantiator function pointer
        typedef CMwNod* (*Instantiator)();
        Instantiator createFunc = (Instantiator)*((void**)((char*)classInfo + 0x1C));
        return createFunc();
    }
    return nullptr;
}

int CMwNod::StaticMwIsKindOf(uint32_t classId, uint32_t parentClassId) {
    if (classId != 0xFFFFFFFF && parentClassId != 0xFFFFFFFF) {
        if (classId == parentClassId) {
            return 1;
        }
        CMwClassInfo* childInfo = StaticGetClassInfo(classId);
        CMwClassInfo* parentInfo = StaticGetClassInfo(parentClassId);
        
        if (childInfo != nullptr && parentInfo != nullptr) {
            if (childInfo->m_classId == parentInfo->m_classId) {
                return 1;
            }
            // Traverse inheritance chain (offset +0x08 is parent pointer)
            for (CMwClassInfo* curr = childInfo->m_parent; curr != nullptr; curr = curr->m_parent) {
                if (curr->m_classId == parentInfo->m_classId) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// =================================================
// Serialization
// =================================================

void CMwNod::Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId) {
    // 0x1001000 is the base node chunk used for string identification
    if (chunkId != 0x1001000) {
        // Forward to a deprecated handler if not the standard chunk
        // CMwDeprecated::Chunk(this, segment, archive);
        return;
    }

    CFastString nameStr;
    const char* defaultName = "No DevName";

    // Read vs Write
    if (archive->m_isWriting == false) {
        archive->ReadString(&nameStr);
    } else {
        nameStr.SetString(defaultName);
        archive->WriteString(&nameStr);
    }
}

uint32_t CMwNod::GetChunkInfo(CFuncSegment* segment, uint32_t chunkId) {
    if (chunkId != 0x1001000) {
        CFastString err;
        // CFastString::Format(&err, "Unknown ChunkId: %08X", chunkId);
        return 0xFACADE01; // Facade error code
    }
    return 1;
}

int CMwNod::OnCrashDump(CMwNod* node, CFastString* outString) {
    // Boilerplate stripped. Calls GetClassInfo() and dumps ID formatting
    CMwClassInfo* info = GetClassInfo();
    if (info) {
        // CFastString::ConcatFormat(outString, "(0x%08X)", info->m_classId);
        return 1;
    }
    return 0;
}

// =================================================
// Reference Counting
// =================================================

uint32_t CMwNod::MwAddRef(CMwNod* caller) {
    m_refCount++;
    return m_refCount;
}

uint32_t CMwNod::MwRelease(CMwNod* caller) {
    m_refCount--;
    if (m_refCount != 0) {
        return m_refCount;
    }

    // If dependents exist, notify them before dying
    if (m_dependants != nullptr && m_dependants->GetCount() != 0) {
        for (unsigned int i = 0; i < m_dependants->GetCount(); ++i) {
            CMwNod* dep = m_dependants->operator[](i);
            dep->OnDependantKilled(this);
        }
    }
    
    // Call scalar deleting destructor
    DeleteSelf(1); 
    return 0;
}

uint32_t CMwNod::MwForceRef(CMwNod* newRef, uint32_t flags) {
    uint32_t oldRef = m_refCount;
    m_refCount = (uint32_t)newRef; // Used forcefully as a swap pointer in some contexts
    return oldRef;
}

uint32_t CMwNod::MwGetNearestFather(CMwClassInfo* classInfo, uint32_t param2, uint32_t* param3) {
    CMwClassInfo* thisInfo = GetClassInfo();
    if (thisInfo != nullptr) {
        // return CMwClassInfo::MwGetNearestFather(thisInfo, classInfo, param2, param3);
    }
    return 0xFFFFFFFF;
}

// =================================================
// Dependency Graph
// =================================================

void CMwNod::MwAddDependant(CMwNod* node, CMwNod* param2) {
    if (m_dependants == nullptr) {
        m_dependants = new CFastBuffer<CMwNod*>();
    }
    m_dependants->AddTail(node);
}

void CMwNod::MwAddReceiver(CMwNod* node, CMwNod* param2) {
    if (m_receivers == nullptr) {
        m_receivers = new CFastBuffer<CMwNod*>();
    }
    m_receivers->AddTail(node);
}

void CMwNod::MwSubDependant(CMwNod* node, CMwNod* param2) {
    if (m_dependants != nullptr) {
        // CFastBuffer<CMwNod*>::ReplaceByLast(m_dependants, node);
    }
}

void CMwNod::MwSubDependantSafe(CMwNod* node, CMwNod* param2) {
    if (m_dependants != nullptr) {
        // int index = m_dependants->Find(node);
        // if (index != -1) m_dependants->ReplaceByLastAt(index);
    }
}

void CMwNod::MwFinalSubDependant(CMwNod* node, CMwNod* param2) {
    MwSubDependant(node, param2);
    if (m_refCount == 0) {
        if (m_dependants == nullptr || m_dependants->GetCount() == 0) {
            DeleteSelf(1);
        }
    }
}

void CMwNod::MwIsUnreferenced(CMwNod* node1, CMwNod* node2) {
    MwFinalSubDependant(node1, node2);
}

void CMwNod::MwSubReceiver(CMwNod* node, CMwNod* param2) {
    if (m_receivers != nullptr) {
        // int index = m_receivers->Find(node);
        // if (index != -1) m_receivers->ReplaceByLastAt(index);
        
        if (m_receivers->GetCount() == 0) {
            delete m_receivers;
            m_receivers = nullptr;
        }
    }
}

void CMwNod::DependantSendMwIsKilled(CMwNod* param_1) {
    if (m_dependants != nullptr) {
        bool killedAny = false;
        do {
            killedAny = false;
            for (unsigned int i = 0; i < m_dependants->GetCount(); ++i) {
                CMwNod* dep = m_dependants->operator[](i);
                if (dep != nullptr) {
                    dep->OnDependantKilled(this);
                    killedAny = true;
                    // Reset iteration because buffer modified
                    break;
                }
            }
        } while (killedAny);

        delete m_dependants;
        m_dependants = nullptr;
    }
}

void CMwNod::MwSendMessage(CMwNod* msgData, uint32_t msgId, uint32_t* outMsg) {
    if (m_receivers != nullptr) {
        for (unsigned int i = 0; i < m_receivers->GetCount(); ++i) {
            CMwNod* receiver = m_receivers->operator[](i);
            receiver->OnMessage(outMsg, this);
        }
    }
}

// =================================================
// Reflection Parameters (CMwStack logic)
// =================================================

// Note: Recreated from pointer math. paramInfo structure extracted.
uint32_t CMwNod::Param_Get(CMwNod* stackInfo, CMwStack* stack, CMwValueStd* val) {
    // stackInfo structure maps to an internal struct tracking recursion
    uint32_t stackIndex = *((uint32_t*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x10 checks if it's a virtual parameter
    if ((paramInfo->m_flags & 0x10) != 0) {
        *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Get(stack, val);
    }

    if (HasProperty(paramInfo->m_offset & 0xFFFFF000)) {
        // Calls the specific param type's Get handler (offset 0x94)
        typedef uint32_t (*ParamGetFunc)(void*, CMwNod*, CMwStack*);
        ParamGetFunc func = (ParamGetFunc)*((void**)((char*)paramInfo->m_typeObj + 0x94));
        
        void* targetMemory = (char*)this + paramInfo->m_offset;
        return func(targetMemory, stackInfo, stack);
    }
    return 1;
}

uint32_t CMwNod::Param_Add(CMwNod* stackInfo, CMwStack* stack, void* val) {
    uint32_t stackIndex = *((uint32_t*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x40 checks if virtual add
    if ((paramInfo->m_flags & 0x40) != 0) {
        *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Add(stack, val);
    }

    typedef uint32_t (*ParamAddFunc)(void*, CMwNod*, CMwStack*);
    ParamAddFunc func = (ParamAddFunc)*((void**)((char*)paramInfo->m_typeObj + 0x9C));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

uint32_t CMwNod::Param_Sub(CMwNod* stackInfo, CMwStack* stack, void* val) {
    uint32_t stackIndex = *((uint32_t*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x80 checks if virtual sub
    if ((paramInfo->m_flags & 0x80) != 0) {
        *((uint32_t*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Sub(stack, val);
    }

    typedef uint32_t (*ParamSubFunc)(void*, CMwNod*, CMwStack*);
    ParamSubFunc func = (ParamSubFunc)*((void**)((char*)paramInfo->m_typeObj + 0xA0));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

uint32_t CMwNod::Param_Check(CMwNod* stackInfo, CMwStack* stack) {
    int stackIndex = *((int*)((char*)stackInfo + 0x18));
    if (stackIndex < 0) return 0;
    
    // Check property offsets and bounds logic...
    // (Omitted the raw recursive unpacking of CMwStack for brevity, 
    // it simply calls HasProperty() and checks array indices.)
    return 0;
}

uint32_t CMwNod::Param_Set(CMwNod* stackInfo, CFastString* str, CFastStringInt* strInt) {
    // Sets string values to engine objects via reflection. Heavily ties into CMwStack state tracking.
    return 0;
}

// =================================================
// Virtual Parameter Wrappers
// =================================================

uint32_t CMwNod::VirtualParam_Get_Wrapper(CMwStack* stack, CMwValueStd* val) {
    // Offset 0x24 in vftable
    return VirtualParam_Get(stack, val); 
}

uint32_t CMwNod::VirtualParam_Add_Wrapper(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 1);
}

uint32_t CMwNod::VirtualParam_Sub_Wrapper(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 0);
}

uint32_t CMwNod::VirtualParam_Set_Wrapper(CMwStack* stack, void* val) {
    // Checks chunk ID 0x1001000 and calls SetMwId
    uint32_t stackIndex = *((uint32_t*)((char*)stack + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stack + 0x10));
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    
    if (paramInfo->m_offset == 0x1001000) {
        SetMwId(*((void**)((char*)val + 4)));
    }
    return 0;
}

uint32_t CMwNod::Internal_VirtualParam_AddOrSub(CMwStack* stack, void* val, int isAdd) {
    // Abstracted internal handler
    return 0;
}

// Default Virtual Implementations
CMwNod::~CMwNod() {}
void CMwNod::DeleteSelf(int param) { if (param & 1) delete this; }
bool CMwNod::HasProperty(uint32_t chunkId) { return false; }
void* CMwNod::GetMwId() { return nullptr; }
void CMwNod::SetMwId(void* id) {}
void CMwNod::OnDependantKilled(CMwNod* killedNode) {}
uint32_t CMwNod::VirtualParam_Get(CMwStack* stack, CMwValueStd* val) { return 1; }
uint32_t CMwNod::VirtualParam_Add(CMwStack* stack, void* val) { return 0; }
uint32_t CMwNod::VirtualParam_Sub(CMwStack* stack, void* val) { return 0; }
void CMwNod::OnMessage(uint32_t* msg, CMwNod* sender) {}