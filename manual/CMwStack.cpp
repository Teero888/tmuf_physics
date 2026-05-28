#include "CMwStack.hpp"
#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "CFastString.hpp"
#include "CMwParam.hpp"
#include <cstring> // For memcpy

// External Globals (Engine Specific Data Tables)
extern void* PTR_DAT_00bbf7d8;
extern void* PTR_DAT_00bc6508[];
extern void* PTR_DAT_00bc651c;
extern void* PTR_DAT_00bc6598;
extern uint32_t DAT_00d357f0;

// External CMwId API mock
namespace CMwId {
    extern void CreateFromLocalIndex(uintptr_t index);
}

extern void OnAccessViolation_ConcatToCrashFileName(void* data);

// =================================================
// Constructor / Destructor
// =================================================

CMwStack::CMwStack(uint32_t initialCapacity) {
    m_values = nullptr;
    m_types = nullptr;
    m_capacity = 0;
    m_count = 0;
    m_currentIndex = 0;
    m_ownsMemory = 1;
    
    SetSize(initialCapacity);
}

CMwStack::~CMwStack() {
    if (m_ownsMemory != 0) {
        delete[] m_values;
        delete[] m_types;
    }
}

// =================================================
// Memory Management
// =================================================

void CMwStack::SetSize(uint32_t newCapacity) {
    if (newCapacity == 0) {
        if (m_values != nullptr) {
            delete[] m_values;
            delete[] m_types;
            m_count = 0;
            m_values = nullptr;
            m_capacity = 0;
            m_types = nullptr;
        }
        return;
    }

    void** newValues = new void*[newCapacity];
    uint32_t* newTypes = new uint32_t[newCapacity];

    if (m_capacity == 0) {
        m_count = 0;
    } else {
        std::memcpy(newValues, m_values, m_count * sizeof(void*));
        std::memcpy(newTypes, m_types, m_count * sizeof(uint32_t));
        
        delete[] m_values;
        delete[] m_types;
    }

    m_values = newValues;
    m_currentIndex = m_count - 1;
    m_capacity = newCapacity;
    m_types = newTypes;
}

void CMwStack::CopyFrom(const CMwStack& other) {
    if (m_values != nullptr) {
        delete[] m_values;
        delete[] m_types;
    }

    m_capacity = other.m_capacity;
    m_count = other.m_count;
    m_currentIndex = other.m_currentIndex;

    if (m_capacity == 0) {
        m_values = nullptr;
        m_types = nullptr;
    } else {
        m_values = new void*[m_capacity];
        m_types = new uint32_t[m_capacity];

        if (other.m_count != 0) {
            std::memcpy(m_values, other.m_values, other.m_count * sizeof(void*));
            std::memcpy(m_types, other.m_types, other.m_count * sizeof(uint32_t));
        }
    }
}

// =================================================
// Stack Operations
// =================================================

uint32_t CMwStack::ChangeBaseVal(void* val) {
    if (m_count != 0) {
        m_values[0] = val;
        return 0;
    }
    return 5;
}

uint32_t CMwStack::InsertBaseVal(void* val) {
    if (m_capacity <= m_count) {
        return 4; // Out of bounds / Stack Overflow
    }

    // Shift all elements right (up the stack) to make room at index 0
    uint32_t i = m_capacity;
    while (i > 0) {
        i--;
        if (i > 0) {
            m_values[i] = m_values[i - 1];
            m_types[i] = m_types[i - 1];
        }
    }

    m_count++;
    m_values[0] = val;
    return 0;
}

uint32_t CMwStack::InsertBaseIndex(uint32_t val) {
    InsertBaseVal(reinterpret_cast<void*>(val));
    m_types[0] = STACK_INDEX;
    return 0;
}

uint32_t CMwStack::InsertBaseNameIndex(uint32_t val) {
    InsertBaseVal(reinterpret_cast<void*>(val));
    m_types[0] = STACK_NAMEINDEX;
    return 0;
}

uintptr_t CMwStack::GetArgument(uint32_t argType, EStackType stackType, uint32_t* outArg) {
    int maxIndex = m_count - 1;
    int searchIndex = *outArg;

    // Advanced iteration mapped directly from the decompiled `do...while`
    if (searchIndex == -1) {
        searchIndex = 0;
        *outArg = 0;
        if (m_count != 1) {
            for (int i = searchIndex + 1; i < maxIndex; ++i) {
                if (m_types[i] > 0xFFFFFFF) break; // Break condition found in ASM
                searchIndex = i;
                *outArg = i;
            }
        }
    }
    
    // Check if the parameter matches the requested type
    if (searchIndex < maxIndex && m_types[searchIndex] == stackType) {
        return reinterpret_cast<uintptr_t>(m_values[searchIndex]);
    }
    
    return 0;
}

// =================================================
// Advanced Reflection & Parsing
// =================================================

uint32_t CMwStack::WatchNextNameIndex(uint32_t* outNameIndex, CMwNod** outNodeArray, uint32_t nodeCount) {
    // Pop the stack
    m_currentIndex--;

    // Create ID context
    CMwStack* localStack = this;
    CMwId::CreateFromLocalIndex(reinterpret_cast<uintptr_t>(&localStack));

    if (outNodeArray != nullptr) {
        for (uint32_t i = 0; i < nodeCount; ++i) {
            CMwNod* node = outNodeArray[i];
            
            // Calls a virtual function to verify class/stack identity
            typedef int* (*VerifyFunc)();
            VerifyFunc func = (VerifyFunc)*((void**)((char*)node + 0x14));
            int* result = func();
            
            if (result != nullptr && reinterpret_cast<CMwStack*>(*result) == localStack) {
                *outNameIndex = i;
                OnAccessViolation_ConcatToCrashFileName(nullptr); // Engine crash logging hook
                return 0;
            }
        }
    }

    OnAccessViolation_ConcatToCrashFileName(nullptr);
    return 2;
}

uint32_t CMwStack::MakeInfoFromStack(SMwParamInfo* outInfo, CMwNod* contextNod) {
    int elementCount = 0;
    
    if (m_types[0] != 0) {
        int i = 0;
        do {
            i++;
            elementCount++;
        } while (m_types[i] != 0);

        if (elementCount != 0) {
            // Traverse down the parameter metadata arrays
            uint32_t* paramData = reinterpret_cast<uint32_t*>(m_values[elementCount]);
            
            CMwParam* paramObj = reinterpret_cast<CMwParam*>(paramData[2]);
            int isIndexed = paramObj->IsIndexed();
            bool runFallbackLabel = false; // Replaces the illegal goto

            if (isIndexed == 0) {
                // Call virtual function 0x10 on current node
                typedef int (*CheckFunc)(int);
                CheckFunc func = (CheckFunc)*((void**)((char*)this + 0x10));
                
                if (func(0x1008000) != 0) {
                    runFallbackLabel = true; // Was: goto LAB_00937781;
                } else {
                    if (elementCount == 1) {
                        int valIndex = static_cast<int>(reinterpret_cast<uintptr_t>(m_values[0]) & 0xFFFFFFFF);
                        unsigned int id = reinterpret_cast<unsigned int*>(paramData[9])[valIndex];
                        
                        if (id < 0x1001000) {
                            outInfo->m_offset = id;
                            outInfo->m_typeObj = PTR_DAT_00bc6508[id];
                        } else {
                            outInfo->m_offset = 5;
                            outInfo->m_typeObj = PTR_DAT_00bc651c;
                        }
                        
                        outInfo->m_flags = 0xFFFFFFFF;
                        return 0;
                    }
                    
                    outInfo->m_offset = 0x24;
                    outInfo->m_typeObj = PTR_DAT_00bc6598;
                    return 0;
                }
            } else {
                outInfo->m_offset = paramData[9];
                outInfo->m_typeObj = PTR_DAT_00bc6508[paramData[9]];
                
                uint32_t tempVar = paramData[10];
                outInfo->m_flags &= 0xFFFFFFFB; 
                
                if (elementCount == 2) {
                    // Manual copy of 12 words (48 bytes) observed in ASM
                    uint32_t* dest = &DAT_00d357f0;
                    uint32_t* src = reinterpret_cast<uint32_t*>(outInfo);
                    for (int j = 0; j < 12; ++j) {
                        dest[j] = src[j];
                    }
                    runFallbackLabel = true; // Reaches LAB_00937781 naturally
                }
            }

            // Replaces LAB_00937781:
            if (runFallbackLabel) {
                outInfo->m_offset = 0x24;
                outInfo->m_typeObj = PTR_DAT_00bc6598;
                
                // Specific property type checks
                switch (DAT_00d357f0) { // DAT_00d357f0 is what dest[0] was assigned to
                    case 9: case 0x13: case 0x17: case 0x31: case 0x35: case 0x39: case 0x3D:
                        break;
                    default:
                        return 1;
                }
            }
            return 0;
        }
    }

    // Direct 12-word copy fallback
    uint32_t* srcData = reinterpret_cast<uint32_t*>(m_values[0]);
    uint32_t* destData = reinterpret_cast<uint32_t*>(outInfo);
    for (int i = 0; i < 12; ++i) {
        destData[i] = srcData[i];
    }
    
    return 0;
}

uint32_t CMwStack::FillIndexFromText(uint32_t param2, CMwNod* contextNod, CFastString* textStr) {
    CFastBuffer<void*> gpuBuffer; 
    
    // CFastStringInt struct required for tokenizing
    
    SFastTokenInt tokenData;
    
    int hasToken = textStr->GetNextToken(&tokenData);
    
    while (hasToken != 0) {
        if (PTR_DAT_00bbf7d8 != nullptr) {
            CFastString* newStr = new CFastString();
           newStr->SetString("default"); 
            gpuBuffer.Add(newStr); 
        }
        hasToken = textStr->GetNextToken(&tokenData);
    }
    
    uint32_t recursiveResult = FillIndexFromText(param2, contextNod, textStr);
    
    // Cleanup generated strings
    for (unsigned int i = 0; i < gpuBuffer.GetCount(); ++i) {
        delete reinterpret_cast<CFastString*>(gpuBuffer[i]);
    }
    
    if (recursiveResult != 0) {
        SetSize(0); // Reset stack on failure
    }
    
    return recursiveResult;
}