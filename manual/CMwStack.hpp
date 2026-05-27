#ifndef CMWSTACK_HPP
#define CMWSTACK_HPP

#include "CFastString.hpp"
#include "CMwNod.hpp"

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

    unsigned long m_count;                  // 0x04 - Number of elements currently in the stack
    unsigned long m_capacity;               // 0x08 - Max allocated capacity
    int m_ownsMemory;                       // 0x0C - Boolean flag (1 = manages its own memory)
    void** m_values;                        // 0x10 - Array of raw pointers/values
    unsigned long* m_types;                 // 0x14 - Array of EStackType tags
    int m_currentIndex;                     // 0x18 - The current active frame/top index

    // Member Functions
    CMwStack(unsigned long initialCapacity);
    
    void SetSize(unsigned long newCapacity);
    void CopyFrom(const CMwStack& other);
    
    unsigned long ChangeBaseVal(void* val);
    unsigned long InsertBaseVal(void* val);
    unsigned long InsertBaseIndex(unsigned long val);
    unsigned long InsertBaseNameIndex(unsigned long val);
    
    unsigned long GetArgument(unsigned long argType, EStackType stackType, unsigned long* outArg);
    
    unsigned long MakeInfoFromStack(SMwParamInfo* outInfo, CMwNod* contextNod);
    unsigned long FillIndexFromText(unsigned long param2, CMwNod* contextNod, CFastString* textStr);
    unsigned long WatchNextNameIndex(unsigned long* outNameIndex, CMwNod** outNodeArray, unsigned long nodeCount);
};

#endif // CMWSTACK_HPP