#ifndef CMWSTACK_HPP
#define CMWSTACK_HPP

#include "CFastString.hpp"
#include "CMwNod.hpp"
#include <cstdint>

// Forward Declarations
struct SMwParamInfo;
class CMwParam;

enum EStackType {
    STACK_VAL = 0,
    STACK_INDEX = 1,
    STACK_NAMEINDEX = 2
};

// =================================================
// CMwStack
// The runtime reflection/scripting stack.
// Size: 28 bytes (0x1C)
// =================================================
class CMwStack {
public:
    virtual ~CMwStack();                    // 0x00 - vftable

    uint32_t m_count;                  // 0x04 - Number of elements currently in the stack
    uint32_t m_capacity;               // 0x08 - Max allocated capacity
    int m_ownsMemory;                       // 0x0C - Boolean flag (1 = manages its own memory)
    void** m_values;                        // 0x10 - Array of raw pointers/values
    uint32_t* m_types;                 // 0x14 - Array of EStackType tags
    int m_currentIndex;                     // 0x18 - The current active frame/top index

    // Member Functions
    CMwStack(uint32_t initialCapacity);
    
    void SetSize(uint32_t newCapacity);
    void CopyFrom(const CMwStack& other);
    
    uint32_t ChangeBaseVal(void* val);
    uint32_t InsertBaseVal(void* val);
    uint32_t InsertBaseIndex(uint32_t val);
    uint32_t InsertBaseNameIndex(uint32_t val);
    
    uintptr_t GetArgument(uint32_t argType, EStackType stackType, uint32_t* outArg);
    
    uint32_t MakeInfoFromStack(SMwParamInfo* outInfo, CMwNod* contextNod);
    uint32_t FillIndexFromText(uint32_t param2, CMwNod* contextNod, CFastString* textStr);
    uint32_t WatchNextNameIndex(uint32_t* outNameIndex, CMwNod** outNodeArray, uint32_t nodeCount);
};

#endif // CMWSTACK_HPP