#ifndef CHMSCORPUS_HPP
#define CHMSCORPUS_HPP

#include "CMwNod.hpp"
#include "GmVec3.hpp"
#include "GmVec4.hpp"
#include "GmIso3.hpp"
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include <cstdint>

// Forward Declarations
class CHmsZone;
class CHmsItem;
class CHmsDyna;
class CFuncSegment;
class CMwCmdAffectParam;
class CControlStyle;
class CClassicBufferMemory;
class CSceneToyBoat;
class CPlugTree;
class GmLocFreeVal;
class GmFrustumIso4;
class CRpcCallInternal;

// =================================================
// CHmsZoneElem (Mock Base Class for size and alignment)
// Size: 56 bytes (0x38)
// =================================================
class CHmsZoneElem : public CMwNod {
public:
    CHmsZone* m_zone; // Offset 0x14 across all Corpus structs
    // 0x18 to 0x37 omitted fields handled by padding in corpus
    virtual ~CHmsZoneElem();
    CHmsZoneElem();
};

// =================================================
// CHmsCorpus
// The bridge entity that maps a static/dynamic mesh 
// into a collision grid/zone.
// Size: 92 bytes (0x5C)
// =================================================
class CHmsCorpus : public CHmsZoneElem {
public:
    CMwClassInfo* GetClassInfo() override { return nullptr; }
public:
    // 0x00 to 0x37 inherited from CHmsZoneElem (including CMwNod)
    
    GmVec3 m_translation;                  // 0x3C to 0x47 (X, Y, Z)
    CHmsItem* m_item;                      // 0x48 (Pointer back to the base Item definition)
    void* m_ptr4C;                         // 0x4C (Internal rendering/material buffer)
    uint32_t m_ptr50;                      // 0x50 
    uint32_t m_flags54;                    // 0x54 (Initialized to 0xFFFFFFFF)
    CHmsDyna* m_dyna;                      // 0x58 (Only exists if Corpus is dynamic)

    // =================================================
    // Member Functions
    // =================================================
    CHmsCorpus();
    virtual ~CHmsCorpus();
    virtual void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);

    static CMwNod* MwNewCHmsCorpus();

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    uint32_t GetMwClassId(CControlStyle* param_1);
    int MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2);
    int OnCrashDump(CMwNod* param_1, CFastString* param_2);
    
    int WaterGetPlaneEqInZone(CHmsCorpus* param_1, GmVec4* param_2);
    
    void ComputeCurrentState(CHmsCorpus* param_1, float param_2);
    void GetLocation(GmLocFreeVal* param_1, GmIso4* param_2);
    void OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5);
    void RefreshFromSolid(CHmsCorpus* param_1);
    void Reset(GmFrustumIso4* param_1);
    void RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6);
    void RotateOf(CHmsCorpus* param_1, GmMat3* param_2);
    void SetItem(CHmsCorpus* param_1, CHmsItem* param_2);
    void SetLocation(CPlugTree* param_1, GmIso4* param_2);
    void SetTranslation(GmIso4* param_1, GmVec3* param_2);
};

#endif // CHMSCORPUS_HPP