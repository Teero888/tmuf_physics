#ifndef CHMSITEM_HPP
#define CHMSITEM_HPP

#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "CFastArray.hpp"
#include "CFastString.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmIso3.hpp"
#include "GmMat3.hpp"
#include <cstdint>

// Forward Declarations
class CClassicArchive;
class CPlugSolid;
class CSceneToyMotorbike;
class CSceneToyBoat;
class CGameCtnZone;
class CGameCtnCollection;
class CMwId;
class CHmsCorpus;
class CHmsZone;
class CHmsPortal;
class CHmsDyna;
class CHmsZoneOverlay;
class CFuncSegment;
class CMwCmdAffectParam;
class CControlStyle;
class CMwClassInfoCSceneToyBoat;
class CMwCmdExpIso4Ident;
class CPlugBlendShapes;
class CMwStack;
class CMwValueStd;
class CSystemData;
class CPfmHeap;
class CClassicBufferMemory;
class CCrystal;
class CPlugTree;
class GmLocFreeVal;
class CDx9DeviceCaps;
struct SZone;
struct SPlugVisibleId;

// Enums reconstructed from usage
enum EHmsCorpusCat { CAT_DYNAMIC = 0, CAT_STATIC = 1, CAT_ZOMBIE = 2, CAT_KINEMATIC = 3, CAT_BACKGROUND = 4 };
enum ECollisionGroup { CG_DEFAULT = 0, CG_GROUP1 = 1, CG_GROUP2 = 2, CG_GROUP3 = 4 };
enum EContactInterest { CI_NONE = 0, CI_ALL = 2 };
enum EDynamicType { DT_STATIC = 0, DT_DYNAMIC = 1 };
enum EMobilStateQuality { MSQ_LOW = 0, MSQ_HIGH = 1 };
enum ECallback { CB_NONE = 0, CB_RENDER = 1, CB_PHYSICS = 2 };

// =================================================
// CHmsItem
// A core physical/spatial object in the Nadeo Hms system.
// Size: 88 bytes (0x58)
// =================================================
class CHmsItem : public CMwNod {
public:
    CMwClassInfo* GetClassInfo() override { return nullptr; }

public:
    struct CCallback {
        virtual ~CCallback();
    };

    struct CCallbackRenderBeforeTree {
        virtual ~CCallbackRenderBeforeTree();
    };

    struct SCallbackList {
        virtual ~SCallbackList();
        CCallback* m_callbacks[5]; // 0x04 to 0x14
        
        SCallbackList();
    };

    // 0x00 to 0x13 inherited from CMwNod (vftable, m_refCount, m_flags, dependants, receivers)
    CPlugSolid* m_solid;                   // 0x14
    uint32_t m_flags1;                     // 0x18 - Dense bitfield
    uint32_t m_flags2;                     // 0x1C - Dense bitfield
    uint16_t m_visibleId;                  // 0x20
    uint16_t m_pad22;                      // 0x22
    SCallbackList* m_callbacks;            // 0x24
    CFastArray<CHmsPortal*> m_portals;     // 0x28
    CFastBuffer<CHmsCorpus*> m_corpuses;   // 0x34
    char* m_name;                          // 0x40
    CMwNod* m_nod44;                       // 0x44
    int m_saveStateParam1;                 // 0x48
    int m_saveStateParam2;                 // 0x4C
    uint32_t m_saveStateParam3;            // 0x50
    void* m_ptr54;                         // 0x54
    CHmsDyna* m_dyna;                      // 0x58 (Convenience)

    // =================================================
    // Member Functions
    // =================================================
    CHmsItem();
    virtual ~CHmsItem();
    void* _scalar_deleting_destructor_(CPfmHeap* heap, uint32_t flag);

    static void StaticInit();
    static CMwNod* MwNewCHmsItem();
    static void CallbackSetRenderBeforeTree(CCallbackRenderBeforeTree* param_1);

    CGameCtnZone* GetZone(CGameCtnCollection* param_1, CMwId* param_2);
    CHmsCorpus* GetCorpus(CHmsItem* param_1, CHmsZone* param_2);
    CHmsCorpus* GetCurrentCorpus(CHmsItem* param_1);
    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    EHmsCorpusCat GetCorpusCat(CHmsItem* param_1);
    float GetAsyncBlendBetweenPreviousAndNextStates(CHmsItem* param_1);
    
    int IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2);
    int MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2);
    int OnCrashDump(CMwNod* param_1, CFastString* param_2);
    
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetCorpusIndex(CHmsItem* param_1, CHmsZone* param_2);
    uint32_t GetMwClassId(CControlStyle* param_1);
    uint32_t GetSaveStateSize(CMwClassInfoCSceneToyBoat* param_1, EMobilStateQuality param_2);
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    
    uint32_t VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3);
    uint32_t VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3);
    
    void AddCorpus(SZone* param_1, CHmsCorpus* param_2);
    void AddForce(CHmsItem* param_1, GmVec3* param_2, GmVec3* param_3);
    void AddImpulse(CHmsItem* param_1, GmVec3* param_2);
    void AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4);
    void AddTorque(CHmsItem* param_1, GmVec3* param_2);
    void CallbackSet(CHmsItem* param_1, ECallback param_2, CCallback* param_3);
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    void CreateDefaultData(CCrystal* param_1);
    void CreatePortal(CHmsItem* param_1, CHmsPortal** param_2, CPlugTree* param_3);
    void GetAngularSpeed(CHmsItem* param_1, GmVec3* param_2);
    void GetForce(CHmsItem* param_1, GmVec3* param_2);
    void GetLinearSpeed(CHmsItem* param_1, GmVec3* param_2);
    void GetLocation(GmLocFreeVal* param_1, GmIso4* param_2);
    void IsVisibleSet(CHmsItem* param_1, int param_2);
    void OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5);
    void OnNodLoaded(CDx9DeviceCaps* param_1);
    void OnVisible_WakeOrKeepAwake(CHmsItem* param_1);
    void PickDisable(CHmsItem* param_1);
    void PickEnableAtLevel(CHmsItem* param_1, uint32_t param_2);
    void RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2);
    void RemovePortal(CHmsItem* param_1, CHmsPortal* param_2);
    void ResetDynamicState(CHmsItem* param_1);
    void RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6);
    void RotateOf(CHmsCorpus* param_1, GmMat3* param_2);
    void SaveState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t* param_3, uint32_t param_4);
    void SetAngularSpeed(CHmsItem* param_1, GmVec3* param_2);
    void SetCollisionGroup(CHmsItem* param_1, ECollisionGroup param_2);
    void SetContactInterest(CHmsItem* param_1, EContactInterest param_2);
    void SetCountShadowTexCasted(CHmsItem* param_1, uint8_t param_2, int param_3);
    void SetDynamicType(CHmsItem* param_1, EDynamicType param_2);
    void SetForce(CHmsItem* param_1, GmVec3* param_2);
    void SetIsBackground(CHmsItem* param_1, int param_2);
    void SetIsCollisionStatic(CHmsItem* param_1, int param_2);
    void SetIsForcePointDynamicCollisionResponse(CHmsItem* param_1, int param_2);
    void SetIsKinematicOnly(CHmsItem* param_1, int param_2);
    void SetIsVisionStatic(CHmsItem* param_1, int param_2);
    void SetIsZombie(CHmsItem* param_1, int param_2);
    void SetLightEmitter(CHmsItem* param_1, int param_2);
    void SetLightLensFlareEnable(CHmsItem* param_1, int param_2);
    void SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2);
    void SetLocation(CPlugTree* param_1, GmIso4* param_2);
    void SetOccluderForLightMap(CHmsItem* param_1, int param_2);
    void SetShadowCasterGroupMask(CHmsItem* param_1, uint32_t param_2);
    void SetShadowFakeEnable(CHmsItem* param_1, int param_2);
    void SetShadowReceiverGroupMask(CHmsItem* param_1, uint32_t param_2);
    void SetSolid(CSceneToyMotorbike* param_1, CPlugSolid* param_2);
    void SetTorque(CHmsItem* param_1, GmVec3* param_2);
    void TransformOf(CHmsItem* param_1, GmIso4* param_2);
    void UpdateCorpusCat(CHmsItem* param_1);
    void UpdateIsBuild(CHmsItem* param_1);
    void VisibleIdSet(CHmsItem* param_1, SPlugVisibleId* param_2);
};

#endif // CHMSITEM_HPP
