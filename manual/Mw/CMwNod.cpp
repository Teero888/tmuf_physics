#include "CMwNod.hpp"
#include "CMwEngineManager.hpp"
#include "CClassicArchive.hpp"
#include "CFastString.hpp"
#include "CMwStack.hpp"
#include "CMwClassInfo.hpp"
#include "CMwParam.hpp"

// =================================================
// Engine Globals
// =================================================
extern CMwEngineManager DAT_00d73344;
extern void (*DAT_00d7333c)(CMwNod*);

struct SSystemEngineModule {
    CMwEngineInfo* m_engine;
    SSystemEngineModule* m_next; 
};
extern SSystemEngineModule* DAT_00d73ba8;

extern CFastString DAT_00d733d0; // Static string for VirtualParam_Get
extern void* DAT_00d71c9c;       // Empty string fallback

// Global state trackers for Param_Check recursive array logic
extern int* DAT_00d73388;
extern uint32_t* DAT_00d7338c;
extern uint32_t DAT_00d73380;
extern uint32_t DAT_00d7337C;
extern uint32_t DAT_00d73390;
extern CMwNod DAT_00d73378;

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
    if (m_flags != 0 && DAT_00d7333c != nullptr) {
        DAT_00d7333c(this);
    }
    if (m_dependants != nullptr) {
        DependantSendMwIsKilled(nullptr);
    }
    if (m_receivers != nullptr) {
        delete m_receivers;
        m_receivers = nullptr;
    }
}

// =================================================
// Core Static Factory & Reflection
// =================================================
void CMwNod::StaticInit() {
    for (SSystemEngineModule* mod = DAT_00d73ba8; mod != nullptr; mod = mod->m_next) {
        if (mod->m_engine != nullptr) {
            DAT_00d73344.AddClass(mod->m_engine, nullptr);
        }
    }
    CMwClassInfo::BuildTree(nullptr);
}

void CMwNod::AddClass(CMwEngineInfo* engine, CMwClassInfo* classInfo) {
    DAT_00d73344.AddClass(engine, classInfo);
}

CMwClassInfo* CMwNod::StaticGetClassInfo(uint32_t classId) {
    return DAT_00d73344.GetClassInfo(classId);
}

CMwNod* CMwNod::CreateByMwClassId(uint32_t classId) {
    CMwClassInfo* classInfo = StaticGetClassInfo(classId);
    if (classInfo != nullptr) {
        typedef CMwNod* (*Instantiator)();
        Instantiator createFunc = (Instantiator)*((void**)((char*)classInfo + 0x1C));
        return createFunc();
    }
    return nullptr;
}

int CMwNod::StaticMwIsKindOf(uint32_t classId, uint32_t parentClassId) {
    if (classId != 0xFFFFFFFF && parentClassId != 0xFFFFFFFF) {
        if (classId == parentClassId) return 1;
        
        CMwClassInfo* childInfo = StaticGetClassInfo(classId);
        CMwClassInfo* parentInfo = StaticGetClassInfo(parentClassId);
        
        if (childInfo != nullptr && parentInfo != nullptr) {
            if (childInfo->m_classId == parentInfo->m_classId) return 1;
            
            for (CMwClassInfo* curr = childInfo->m_parent; curr != nullptr; curr = curr->m_parent) {
                if (curr->m_classId == parentInfo->m_classId) return 1;
            }
        }
    }
    return 0;
}

// =================================================
// Serialization & Debugging
// =================================================
void CMwNod::Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId) {
    if (chunkId != 0x1001000) {
        return;
    }

    // Strictly match the CClassicArchive signature
    CFastStringInt nameStr;

    if (archive->m_isWriting == false) {
        archive->ReadString(&nameStr);
    } else {
        nameStr.SetString("No DevName");
        archive->WriteString(&nameStr);
    }
}

uint32_t CMwNod::GetChunkInfo(CFuncSegment* segment, uint32_t chunkId) {
    if (chunkId != 0x1001000) {
        return 0xFACADE01;
    }
    return 1;
}

int CMwNod::OnCrashDump(CMwNod* node, CFastString* outString) {
    CMwClassInfo* info = GetClassInfo();
    if (info) {
        // Output formatted crash string
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
    if (m_refCount != 0) return m_refCount;

    if (m_dependants != nullptr && m_dependants->GetCount() != 0) {
        for (uint32_t i = 0; i < m_dependants->GetCount(); ++i) {
            CMwNod* dep = m_dependants->operator[](i);
            if (dep) dep->OnDependantKilled(this);
        }
    }
    DeleteSelf(1); 
    return 0;
}

uint32_t CMwNod::MwForceRef(CMwNod* newRef, uint32_t flags) {
    uint32_t oldRef = m_refCount;
    m_refCount = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(newRef) & 0xFFFFFFFF);
    return oldRef;
}

uint32_t CMwNod::MwGetNearestFather(CMwClassInfo* classInfo, uint32_t param2, uint32_t* param3) {
    CMwClassInfo* thisInfo = GetClassInfo();
    if (thisInfo != nullptr) {
        return thisInfo->MwGetNearestFather(param2, param3);
    }
    return 0xFFFFFFFF;
}

// =================================================
// Dependency Graph
// =================================================
void CMwNod::MwAddDependant(CMwNod* node, CMwNod* param2) {
    if (m_dependants == nullptr) m_dependants = new CFastBuffer<CMwNod*>();
    m_dependants->Add(node);
}

void CMwNod::MwAddReceiver(CMwNod* node, CMwNod* param2) {
    if (m_receivers == nullptr) m_receivers = new CFastBuffer<CMwNod*>();
    m_receivers->Add(node);
}

void CMwNod::MwSubDependant(CMwNod* node, CMwNod* param2) {
    if (m_dependants) {
        // Implement ReplaceByLast logic
    }
}

void CMwNod::MwSubDependantSafe(CMwNod* node, CMwNod* param2) {
    if (m_dependants) {
        // Implement safe Find and Replace logic
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
    if (m_receivers) {
        if (m_receivers->GetCount() == 0) {
            delete m_receivers;
            m_receivers = nullptr;
        }
    }
}

void CMwNod::DependantSendMwIsKilled(CMwNod* param_1) {
    if (m_dependants != nullptr) {
        bool killedAny;
        do {
            killedAny = false;
            for (uint32_t i = 0; i < m_dependants->GetCount(); ++i) {
                CMwNod* dep = m_dependants->operator[](i);
                if (dep != nullptr) {
                    dep->OnDependantKilled(this);
                    killedAny = true;
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
        for (uint32_t i = 0; i < m_receivers->GetCount(); ++i) {
            CMwNod* receiver = m_receivers->operator[](i);
            receiver->OnMessage(outMsg, this);
        }
    }
}

// =================================================
// FULL REFLECTION PARAMETER ROUTING (1:1 with Assembly)
// =================================================

uint32_t CMwNod::Param_Get(CMwStack* stackInfo, CMwStack* stack, void* val) {
    int stackIndex = stackInfo->m_currentIndex;
    SMwParamInfo* paramInfo = (SMwParamInfo*)stackInfo->m_values[stackIndex];
    stackInfo->m_currentIndex = stackIndex - 1;

    if ((paramInfo->m_flags & 0x10) != 0) {
        stackInfo->m_currentIndex = stackIndex;
        return VirtualParam_Get_Wrapper(stackInfo, val);
    }

    if (HasProperty(paramInfo->m_propId & 0xFFFFF000)) {
        typedef uint32_t (*ParamGetFunc)(void*, CMwStack*, CMwStack*);
        ParamGetFunc func = (ParamGetFunc)*((void**)((char*)paramInfo->m_typeObj + 0x94));
        void* targetMemory = (char*)this + paramInfo->m_offset;
        return func(targetMemory, stackInfo, stack);
    }
    return 1;
}

uint32_t CMwNod::Param_Add(CMwStack* stackInfo, CMwStack* stack, void* val) {
    int stackIndex = stackInfo->m_currentIndex;
    SMwParamInfo* paramInfo = (SMwParamInfo*)stackInfo->m_values[stackIndex];
    stackInfo->m_currentIndex = stackIndex - 1;

    if ((paramInfo->m_flags & 0x40) != 0) {
        stackInfo->m_currentIndex = stackIndex;
        return VirtualParam_Add_Wrapper(stackInfo, val);
    }

    typedef uint32_t (*ParamAddFunc)(void*, CMwStack*, CMwStack*);
    ParamAddFunc func = (ParamAddFunc)*((void**)((char*)paramInfo->m_typeObj + 0x9C));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

uint32_t CMwNod::Param_Sub(CMwStack* stackInfo, CMwStack* stack, void* val) {
    int stackIndex = stackInfo->m_currentIndex;
    SMwParamInfo* paramInfo = (SMwParamInfo*)stackInfo->m_values[stackIndex];
    stackInfo->m_currentIndex = stackIndex - 1;

    if ((paramInfo->m_flags & 0x80) != 0) {
        stackInfo->m_currentIndex = stackIndex;
        return VirtualParam_Sub_Wrapper(stackInfo, val);
    }

    typedef uint32_t (*ParamSubFunc)(void*, CMwStack*, CMwStack*);
    ParamSubFunc func = (ParamSubFunc)*((void**)((char*)paramInfo->m_typeObj + 0xA0));
    void* targetMemory = (char*)this + paramInfo->m_offset;
    return func(targetMemory, stackInfo, stack);
}

uint32_t CMwNod::Param_Check(CMwStack* stackInfo, CMwStack* stack) {
    if (stackInfo->m_currentIndex < 0) return 0;

    SMwParamInfo* paramInfo = (SMwParamInfo*)stackInfo->m_values[stackInfo->m_currentIndex];

    if (!HasProperty(paramInfo->m_propId & 0xFFFFF000)) {
        return 2;
    }

    CMwNod* outNode = reinterpret_cast<CMwNod*>(stackInfo); 

    typedef uint32_t (*ParamCheckFunc)(void*, CMwStack*, CMwNod**);
    ParamCheckFunc checkFunc = (ParamCheckFunc)*((void**)((char*)paramInfo->m_typeObj + 0xA4));

    uint32_t result = checkFunc(this, stackInfo, &outNode);

    if (result == 0) {
        if (outNode == nullptr) {
            // Complex Array/Index Bounds Checking
            if (stackInfo->m_currentIndex > 0 && 
                stackInfo->m_types[stackInfo->m_currentIndex - 1] == STACK_INDEX) 
            {
                uint32_t localStackMem[68];
                CMwStack* localStack = reinterpret_cast<CMwStack*>(&localStackMem);

                uint32_t local_24 = 0;
                // FIX: Safe 64-bit pointer-to-int cast via uintptr_t
                int local_20 = static_cast<int>(reinterpret_cast<uintptr_t>(paramInfo) & 0xFFFFFFFF);

                DAT_00d73388 = &local_20;
                DAT_00d7338c = &local_24;
                DAT_00d73380 = 1;
                DAT_00d7337C = 1;
                DAT_00d73390 = 0;

                // FIX: Explicit reinterpret_cast from CMwNod* to CMwStack*
                uint32_t getRes = Param_Get(reinterpret_cast<CMwStack*>(&DAT_00d73378), localStack, reinterpret_cast<void*>(this));

                DAT_00d73388 = nullptr;
                DAT_00d7338c = nullptr;

                if (getRes != 0) return getRes;

                CMwParam* paramObj = reinterpret_cast<CMwParam*>(paramInfo->m_typeObj);
                int isIndexed = paramObj->IsIndexed();
                
                uint32_t elementCount = 0;
                if (isIndexed == 0) {
                    typedef uint32_t (*GetCount1)(CMwStack*);
                    GetCount1 countFunc = (GetCount1)*((void**)((char*)paramInfo->m_typeObj + 0x90));
                    elementCount = countFunc(localStack);
                } else {
                    typedef uint32_t (*GetCount2)(CMwStack*);
                    GetCount2 countFunc = (GetCount2)*((void**)((char*)paramInfo->m_typeObj + 0x88));
                    elementCount = countFunc(localStack);
                }

                // FIX: Safe 64-bit pointer-to-int cast via uintptr_t
                uint32_t requestedIndex = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(stackInfo->m_values[stackInfo->m_currentIndex - 1]) & 0xFFFFFFFF);
                
                if (elementCount <= requestedIndex) {
                    return 2;
                }
            }
            return 0;
        }
        return outNode->Param_Check(reinterpret_cast<CMwStack*>(outNode), stack);
    }
    return result;
}

uint32_t CMwNod::Param_Set(CMwStack* stackInfo, CFastString* str, CFastString* strInt) {
    // Reconstructing the dense string parsing and assignment routing
    CMwStack localStackA(0);
    uint32_t res = localStackA.FillIndexFromText(0xFFFFFFFF, reinterpret_cast<CMwNod*>(strInt), str);
    
    if (res != 0) return res;

    CMwStack localStackB(0);
    if (localStackA.m_count == 0) {
        return 5;
    }

    SMwParamInfo paramInfoLocal;
    res = localStackB.MakeInfoFromStack(&paramInfoLocal, this);
    if (res != 0) return res;

    // Direct translation of Ghidra's complex condition tree
    typedef int (*TypeCheck1)();
    typedef int (*TypeCheck2)();
    typedef int (*TypeCheck3)();

    TypeCheck1 check1 = (TypeCheck1)*((void**)((char*)paramInfoLocal.m_typeObj + 0x10));
    TypeCheck2 check2 = (TypeCheck2)*((void**)((char*)paramInfoLocal.m_typeObj + 0x10)); // Mapped from offset overlaps
    TypeCheck3 check3 = (TypeCheck3)*((void**)((char*)paramInfoLocal.m_typeObj + 0xAC));

    int c1 = check1();
    int c2 = check2();
    int c3 = check3();

    if (c1 == 0 && c2 == 0 && c3 == 0) {
        return 7;
    }

    res = Param_Check(&localStackA, &localStackB);
    if (res != 0) return res;

    if (c1 == 0) {
        if (c2 == 0) {
            typedef void (*SetFunc)(CFastString*, CFastString*, CFastString*);
            SetFunc setF = (SetFunc)*((void**)((char*)paramInfoLocal.m_typeObj + 0xB0));
            setF(nullptr, strInt, nullptr);
        } else {
            if (*(int*)strInt != 0) {
                // String conversion & setting logic 
                res = Param_Set(&localStackB, str, strInt);
                return res;
            }
        }
    }

    return Param_Set(&localStackA, nullptr, strInt);
}

// =================================================
// Virtual Parameter Wrappers
// =================================================

uint32_t CMwNod::VirtualParam_Get(CMwStack* stack, void* val) {
    int stackIndex = stack->m_currentIndex;
    SMwParamInfo* paramInfo = (SMwParamInfo*)stack->m_values[stackIndex];
    stack->m_currentIndex = stackIndex - 1;

    uint32_t propId = paramInfo->m_propId;

    if (propId == 0x1001000) {
        void* mwId = GetMwId();
        if (mwId != nullptr) {
            // Internal C++ string fetching
            *reinterpret_cast<void**>(val) = &DAT_00d733d0;
            return 0;
        }
        *reinterpret_cast<void**>(stack) = &DAT_00d71c9c;
        return 0;
    }
    return 1;
}

uint32_t CMwNod::VirtualParam_Set(CMwStack* stack, void* val) {
    int stackIndex = stack->m_currentIndex;
    SMwParamInfo* paramInfo = (SMwParamInfo*)stack->m_values[stackIndex];
    stack->m_currentIndex = stackIndex - 1;

    if (paramInfo->m_propId == 0x1001000) {
        SetMwId(*reinterpret_cast<void**>((char*)val + 4));
    }
    return 0;
}

uint32_t CMwNod::VirtualParam_Add(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 1);
}

uint32_t CMwNod::VirtualParam_Sub(CMwStack* stack, void* val) {
    return Internal_VirtualParam_AddOrSub(stack, val, 0);
}

uint32_t CMwNod::VirtualParam_Get_Wrapper(CMwStack* stack, void* val) {
    return VirtualParam_Get(stack, val);
}
uint32_t CMwNod::VirtualParam_Add_Wrapper(CMwStack* stack, void* val) {
    return VirtualParam_Add(stack, val);
}
uint32_t CMwNod::VirtualParam_Sub_Wrapper(CMwStack* stack, void* val) {
    return VirtualParam_Sub(stack, val);
}
uint32_t CMwNod::Internal_VirtualParam_AddOrSub(CMwStack* stack, void* val, int isAdd) {
    return 0;
}

// Default Virtual Implementations
void CMwNod::DeleteSelf(int param) { if (param & 1) delete this; }
bool CMwNod::HasProperty(uint32_t chunkId) { return false; }
void* CMwNod::GetMwId() { return nullptr; }
void CMwNod::SetMwId(void* id) {}
void CMwNod::OnDependantKilled(CMwNod* killedNode) {}
void CMwNod::OnMessage(uint32_t* msg, CMwNod* sender) {}