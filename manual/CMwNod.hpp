#ifndef CMWNOD_HPP
#define CMWNOD_HPP

#include "CFastString.hpp"
#include "CFastBuffer.hpp"

// Forward Declarations
class CMwClassInfo;
class CMwEngineInfo;
class CFuncSegment;
class CClassicArchive;
class CMwStack;
class CMwValueStd;
struct SMwParamInfo;

// =================================================
// CMwNod
// The root object class of the Nadeo Engine.
// Size: 20 bytes (0x14)
// =================================================
class CMwNod {
public:
    // Memory Layout
    // 0x00: vftable
    unsigned long m_refCount;             // 0x04 - Reference counter
    unsigned long m_flags;                // 0x08 - Internal flags / status
    CFastBuffer<CMwNod*>* m_dependants;   // 0x0C - Nodes that depend on this node
    CFastBuffer<CMwNod*>* m_receivers;    // 0x10 - Nodes listening to messages from this node

    // =================================================
    // Explicit Virtual Function Table (Reconstructed from offsets)
    // =================================================
    virtual ~CMwNod();                                                  // 0x00
    virtual void DeleteSelf(int param);                                 // 0x04 - Scalar deleting destructor
    virtual CMwClassInfo* GetClassInfo() = 0;                           // 0x08
    virtual void Unk_0x0C() {}                                          // 0x0C
    virtual bool HasProperty(unsigned long chunkId);                    // 0x10
    virtual void* GetMwId();                                            // 0x14
    virtual void SetMwId(void* id);                                     // 0x18
    virtual void Unk_0x1C() {}                                          // 0x1C
    virtual void OnDependantKilled(CMwNod* killedNode);                 // 0x20
    virtual unsigned long VirtualParam_Get(CMwStack* stack, CMwValueStd* val); // 0x24
    virtual void Unk_0x28() {}                                          // 0x28
    virtual unsigned long VirtualParam_Add(CMwStack* stack, void* val); // 0x2C
    virtual unsigned long VirtualParam_Sub(CMwStack* stack, void* val); // 0x30
    
    // ... padding for intervening virtuals ...
    virtual void OnMessage(unsigned long* msg, CMwNod* sender);         // 0x74

    // =================================================
    // Member Functions
    // =================================================
    CMwNod();
    
    static void StaticInit();
    static CMwClassInfo* StaticGetClassInfo(unsigned long classId);
    static CMwNod* CreateByMwClassId(unsigned long classId);
    static int StaticMwIsKindOf(unsigned long classId, unsigned long parentClassId);

    void AddClass(CMwEngineInfo* engine, CMwClassInfo* classInfo);
    void Chunk(CFuncSegment* segment, CClassicArchive* archive, unsigned long chunkId);
    
    // Dependency & Message Graph
    void DependantSendMwIsKilled(CMwNod* node);
    void MwAddDependant(CMwNod* node, CMwNod* param2);
    void MwAddReceiver(CMwNod* node, CMwNod* param2);
    void MwSubDependant(CMwNod* node, CMwNod* param2);
    void MwSubDependantSafe(CMwNod* node, CMwNod* param2);
    void MwSubReceiver(CMwNod* node, CMwNod* param2);
    void MwFinalSubDependant(CMwNod* node, CMwNod* param2);
    void MwIsUnreferenced(CMwNod* node1, CMwNod* node2);
    void MwSendMessage(CMwNod* msgData, unsigned long msgId, unsigned long* outMsg);

    // Reference Counting
    unsigned long MwAddRef(CMwNod* caller);
    unsigned long MwForceRef(CMwNod* newRef, unsigned long flags);
    unsigned long MwRelease(CMwNod* caller);
    unsigned long MwGetNearestFather(CMwClassInfo* classInfo, unsigned long param2, unsigned long* param3);

    // Reflection & Scripting Params
    int OnCrashDump(CMwNod* node, CFastString* outString);
    unsigned long GetChunkInfo(CFuncSegment* segment, unsigned long chunkId);
    unsigned long Param_Add(CMwNod* stackInfo, CMwStack* stack, void* val);
    unsigned long Param_Check(CMwNod* stackInfo, CMwStack* stack);
    unsigned long Param_Get(CMwNod* stackInfo, CMwStack* stack, CMwValueStd* val);
    unsigned long Param_Set(CMwNod* stackInfo, CFastString* str, CFastStringInt* strInt);
    unsigned long Param_Sub(CMwNod* stackInfo, CMwStack* stack, void* val);
    
    // Non-virtual wrappers for virtual param calls
    unsigned long VirtualParam_Add_Wrapper(CMwStack* stack, void* val);
    unsigned long VirtualParam_Get_Wrapper(CMwStack* stack, CMwValueStd* val);
    unsigned long VirtualParam_Set_Wrapper(CMwStack* stack, void* val);
    unsigned long VirtualParam_Sub_Wrapper(CMwStack* stack, void* val);

protected:
    unsigned long Internal_VirtualParam_AddOrSub(CMwStack* stack, void* val, int isAdd);
};

// Extracted parameter reflection layout
struct SMwParamInfo {
    void* m_typeObj;         // 0x08
    unsigned long m_offset;  // 0x0C
    unsigned long m_flags;   // 0x14
};

#endif // CMWNOD_HPP