#ifndef CMWNOD_HPP
#define CMWNOD_HPP

#include "CFastString.hpp"
#include "CFastBuffer.hpp"
#include <cstdint> // Required for cross-platform LP64/LLP64 safety

// Forward Declarations
class CMwClassInfo;
class CMwEngineInfo;
class CFuncSegment;
class CClassicArchive;
class CMwStack;
class CMwParam;

// =================================================
// SMwParamInfo
// Reflection metadata structure used by CMwStack.
// Size: 48 bytes (0x30 / 12 words)
// =================================================
struct SMwParamInfo {
    uint32_t m_propId;       // 0x00 - Chunk ID / Property ID
    uint32_t m_flags;        // 0x04 - Bitwise flags (e.g., 0x10 = Virtual)
    void* m_typeObj;         // 0x08 - Pointer to CMwParam metadata type
    uint32_t m_offset;       // 0x0C - Memory offset within the target class
    
    // Padding to accommodate the 12-word manual copy fallback 
    // seen in MakeInfoFromStack
    uint32_t _padding[8];    // 0x10 - 0x2C
};

// =================================================
// CMwNod
// The root object class of the Nadeo Engine.
// Size: 20 bytes (0x14)
// =================================================
class CMwNod {
public:
    // Memory Layout
    // 0x00: vftable
    uint32_t m_refCount;                  // 0x04 - Reference counter
    uint32_t m_flags;                     // 0x08 - Internal flags / status
    CFastBuffer<CMwNod*>* m_dependants;   // 0x0C - Nodes that depend on this node
    CFastBuffer<CMwNod*>* m_receivers;    // 0x10 - Nodes listening to messages from this node

    // =================================================
    // Explicit Virtual Function Table (Reconstructed from offsets)
    // =================================================
    virtual ~CMwNod();                                            // 0x00
    virtual void DeleteSelf(int param);                           // 0x04 - Scalar deleting destructor
    virtual CMwClassInfo* GetClassInfo() = 0;                     // 0x08
    virtual void Unk_0x0C() {}                                    // 0x0C
    virtual bool HasProperty(uint32_t chunkId);                   // 0x10
    virtual void* GetMwId();                                      // 0x14
    virtual void SetMwId(void* id);                               // 0x18
    virtual void Unk_0x1C() {}                                    // 0x1C
    virtual void OnDependantKilled(CMwNod* killedNode);           // 0x20
    virtual uint32_t VirtualParam_Get(CMwStack* stack, void* val);// 0x24
    virtual void Unk_0x28() {}                                    // 0x28
    virtual uint32_t VirtualParam_Add(CMwStack* stack, void* val);// 0x2C
    virtual uint32_t VirtualParam_Sub(CMwStack* stack, void* val);// 0x30
    
    // ... padding for intervening virtuals ...
    virtual void OnMessage(uint32_t* msg, CMwNod* sender);        // 0x74

    // =================================================
    // Member Functions
    // =================================================
    CMwNod();
    
    static void StaticInit();
    static CMwClassInfo* StaticGetClassInfo(uint32_t classId);
    static CMwNod* CreateByMwClassId(uint32_t classId);
    static int StaticMwIsKindOf(uint32_t classId, uint32_t parentClassId);

    void AddClass(CMwEngineInfo* engine, CMwClassInfo* classInfo);
    void Chunk(CFuncSegment* segment, CClassicArchive* archive, uint32_t chunkId);
    
    // Dependency & Message Graph
    void DependantSendMwIsKilled(CMwNod* node);
    void MwAddDependant(CMwNod* node, CMwNod* param2);
    void MwAddReceiver(CMwNod* node, CMwNod* param2);
    void MwSubDependant(CMwNod* node, CMwNod* param2);
    void MwSubDependantSafe(CMwNod* node, CMwNod* param2);
    void MwSubReceiver(CMwNod* node, CMwNod* param2);
    void MwFinalSubDependant(CMwNod* node, CMwNod* param2);
    void MwIsUnreferenced(CMwNod* node1, CMwNod* node2);
    void MwSendMessage(CMwNod* msgData, uint32_t msgId, uint32_t* outMsg);

    // Reference Counting
    uint32_t MwAddRef(CMwNod* caller);
    uint32_t MwForceRef(CMwNod* newRef, uint32_t flags);
    uint32_t MwRelease(CMwNod* caller);
    uint32_t MwGetNearestFather(CMwClassInfo* classInfo, uint32_t param2, uint32_t* param3);

    // Reflection & Scripting Params
    int OnCrashDump(CMwNod* node, CFastString* outString);
    uint32_t GetChunkInfo(CFuncSegment* segment, uint32_t chunkId);
    
    uint32_t Param_Add(CMwStack* stackInfo, CMwStack* stack, void* val);
    uint32_t Param_Check(CMwStack* stackInfo, CMwStack* stack);
    uint32_t Param_Get(CMwStack* stackInfo, CMwStack* stack, void* val);
    uint32_t Param_Set(CMwStack* stackInfo, CFastString* str, CFastString* strInt);
    uint32_t Param_Sub(CMwStack* stackInfo, CMwStack* stack, void* val);
    
    // Non-virtual wrappers for virtual param calls
    uint32_t VirtualParam_Add_Wrapper(CMwStack* stack, void* val);
    uint32_t VirtualParam_Get_Wrapper(CMwStack* stack, void* val);
    uint32_t VirtualParam_Set_Wrapper(CMwStack* stack, void* val);
    uint32_t VirtualParam_Sub_Wrapper(CMwStack* stack, void* val);

    // Explicitly added to match the .cpp implementation
    uint32_t VirtualParam_Set(CMwStack* stack, void* val);

protected:
    uint32_t Internal_VirtualParam_AddOrSub(CMwStack* stack, void* val, int isAdd);
};

#endif // CMWNOD_HPP