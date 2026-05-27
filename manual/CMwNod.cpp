#include "CMwNod.hpp"
#include "CMwEngineManager.hpp"
#include "CClassicArchive.hpp"
#include "CMwStack.hpp"
#include "CMwClassInfo.hpp"

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

CMwClassInfo* CMwNod::StaticGetClassInfo(unsigned long classId) {
    return CMwEngineManager::GetClassInfo(&DAT_00d73344, classId);
}

CMwNod* CMwNod::CreateByMwClassId(unsigned long classId) {
    CMwClassInfo* classInfo = StaticGetClassInfo(classId);
    if (classInfo != nullptr) {
        // Offset 0x1C in CMwClassInfo is typically the instantiator function pointer
        typedef CMwNod* (*Instantiator)();
        Instantiator createFunc = (Instantiator)*((void**)((char*)classInfo + 0x1C));
        return createFunc();
    }
    return nullptr;
}

int CMwNod::StaticMwIsKindOf(unsigned long classId, unsigned long parentClassId) {
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

void CMwNod::Chunk(CFuncSegment* segment, CClassicArchive* archive, unsigned long chunkId) {
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

unsigned long CMwNod::GetChunkInfo(CFuncSegment* segment, unsigned long chunkId) {
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

unsigned long CMwNod::MwAddRef(CMwNod* caller) {
    m_refCount++;
    return m_refCount;
}

unsigned long CMwNod::MwRelease(CMwNod* caller) {
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

unsigned long CMwNod::MwForceRef(CMwNod* newRef, unsigned long flags) {
    unsigned long oldRef = m_refCount;
    m_refCount = (unsigned long)newRef; // Used forcefully as a swap pointer in some contexts
    return oldRef;
}

unsigned long CMwNod::MwGetNearestFather(CMwClassInfo* classInfo, unsigned long param2, unsigned long* param3) {
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

void CMwNod::MwSendMessage(CMwNod* msgData, unsigned long msgId, unsigned long* outMsg) {
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
unsigned long CMwNod::Param_Get(CMwNod* stackInfo, CMwStack* stack, CMwValueStd* val) {
    // stackInfo structure maps to an internal struct tracking recursion
    unsigned long stackIndex = *((unsigned long*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x10 checks if it's a virtual parameter
    if ((paramInfo->m_flags & 0x10) != 0) {
        *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Get(stack, val);
    }

    if (HasProperty(paramInfo->m_offset & 0xFFFFF000)) {
        // Calls the specific param type's Get handler (offset 0x94)
        typedef unsigned long (*ParamGetFunc)(void*, CMwNod*, CMwStack*);
        ParamGetFunc func = (ParamGetFunc)*((void**)((char*)paramInfo->m_typeObj + 0x94));
        
        void* targetMemory = (char*)this + paramInfo->m_offset;
        return func(targetMemory, stackInfo, stack);
    }
    return 1;
}

unsigned long CMwNod::Param_Add(CMwNod* stackInfo, CMwStack* stack, void* val) {
    unsigned long stackIndex = *((unsigned long*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x40 checks if virtual add
    if ((paramInfo->m_flags & 0x40) != 0) {
        *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Add(stack, val);
    }

    typedef unsigned long (*ParamAddFunc)(void*, CMwNod*, CMwStack*);
    ParamAddFunc func = (ParamAddFunc)*((void**)((char*)paramInfo->m_typeObj + 0x9C));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

unsigned long CMwNod::Param_Sub(CMwNod* stackInfo, CMwStack* stack, void* val) {
    unsigned long stackIndex = *((unsigned long*)((char*)stackInfo + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stackInfo + 0x10));
    
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex - 1;

    // Bit 0x80 checks if virtual sub
    if ((paramInfo->m_flags & 0x80) != 0) {
        *((unsigned long*)((char*)stackInfo + 0x18)) = stackIndex;
        return VirtualParam_Sub(stack, val);
    }

    typedef unsigned long (*ParamSubFunc)(void*, CMwNod*, CMwStack*);
    ParamSubFunc func = (ParamSubFunc)*((void**)((char*)paramInfo->m_typeObj + 0xA0));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

unsigned long CMwNod::Param_Check(CMwNod* stackInfo, CMwStack* stack) {
    int stackIndex = *((int*)((char*)stackInfo + 0x18));
    if (stackIndex < 0) return 0;
    
    // Check property offsets and bounds logic...
    // (Omitted the raw recursive unpacking of CMwStack for brevity, 
    // it simply calls HasProperty() and checks array indices.)
    return 0;
}

unsigned long CMwNod::Param_Set(CMwNod* stackInfo, CFastString* str, CFastStringInt* strInt) {
    // Sets string values to engine objects via reflection. Heavily ties into CMwStack state tracking.
    return 0;
}

// =================================================
// Virtual Parameter Wrappers
// =================================================

unsigned long CMwNod::VirtualParam_Get_Wrapper(CMwStack* stack, CMwValueStd* val) {
    // Offset 0x24 in vftable
    return VirtualParam_Get(stack, val); 
}

unsigned long CMwNod::VirtualParam_Add_Wrapper(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 1);
}

unsigned long CMwNod::VirtualParam_Sub_Wrapper(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 0);
}

unsigned long CMwNod::VirtualParam_Set_Wrapper(CMwStack* stack, void* val) {
    // Checks chunk ID 0x1001000 and calls SetMwId
    unsigned long stackIndex = *((unsigned long*)((char*)stack + 0x18));
    SMwParamInfo** stackArray = *((SMwParamInfo***)((char*)stack + 0x10));
    SMwParamInfo* paramInfo = stackArray[stackIndex];
    
    if (paramInfo->m_offset == 0x1001000) {
        SetMwId(*((void**)((char*)val + 4)));
    }
    return 0;
}

unsigned long CMwNod::Internal_VirtualParam_AddOrSub(CMwStack* stack, void* val, int isAdd) {
    // Abstracted internal handler
    return 0;
}

// Default Virtual Implementations
CMwNod::~CMwNod() {}
void CMwNod::DeleteSelf(int param) { if (param & 1) delete this; }
bool CMwNod::HasProperty(unsigned long chunkId) { return false; }
void* CMwNod::GetMwId() { return nullptr; }
void CMwNod::SetMwId(void* id) {}
void CMwNod::OnDependantKilled(CMwNod* killedNode) {}
unsigned long CMwNod::VirtualParam_Get(CMwStack* stack, CMwValueStd* val) { return 1; }
unsigned long CMwNod::VirtualParam_Add(CMwStack* stack, void* val) { return 0; }
unsigned long CMwNod::VirtualParam_Sub(CMwStack* stack, void* val) { return 0; }
void CMwNod::OnMessage(unsigned long* msg, CMwNod* sender) {}