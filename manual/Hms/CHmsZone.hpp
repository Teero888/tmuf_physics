#ifndef CHMSZONE_HPP
#define CHMSZONE_HPP

#include "CHmsItem.hpp"
#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "CFastArray.hpp"
#include "CFastString.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include <cstdint>

// Forward Declarations
class CHmsCorpus;
class CHmsItem;
class CHmsLight;
class CHmsCorpusLight;
class CHmsForceField;
class CHmsZoneVPacker;
class CHmsZoneOverlay;
class CHmsViewport;
class CHmsCamera;
class CAudioPort;
class CAudioSound;
class CPlugSound;
class CGamePopUp;
class CPlugFontBitmap;
class CSystemFidParameters;
class CClassicArchive;
class CFuncSegment;
class CControlStyle;
class CMwCmdExpIso4Ident;
class CMwCmdScriptVarClass;
class CPlugBlendShapes;
class CSystemData;
class CGameCtnDecorationMood;
class CMwCmdAffectParam;
class CMwStack;
class CMwValueStd;
class CRpcCallInternal;
class GxFog;

struct SZone;
struct SHmsVPackerCreate {};
enum EBalanceGroup { BG_DEFAULT = 0 };

// =================================================
// CHmsZone
// A spatial partitioning node in the physics engine.
// Size: 284 bytes (0x11C)
// =================================================
class CHmsZone : public CMwNod {
public:
    CMwClassInfo* GetClassInfo() override { return nullptr; }
public:
    struct CVisionData {
        virtual ~CVisionData();
        virtual void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);
    };

    // 0x00 to 0x13 inherited from CMwNod (vftable, m_refCount, m_flags, dependants, receivers)
    CHmsZone* m_parentZone;                                // 0x14
    
    // Trackers
    CFastBufferCat<CHmsCorpus*, EHmsCorpusCat> m_corpuses; // 0x1C (Size 0x24)
    CFastBuffer<CHmsCorpus*> m_staticCorpuses;             // 0x40 (Size 0x0C)
    CFastBuffer<CHmsCorpus*> m_dynamicCorpuses;            // 0x4C (Size 0x0C)
    CFastBufferCat<CHmsCorpusLight*, uint32_t> m_lights;   // 0x58 (Size 0x24)
    CFastBuffer<CHmsForceField*> m_forceFields;            // 0x7C (Size 0x0C)
    CFastBuffer<void*> m_materials;                        // 0x88 (Size 0x0C)
    
    // Vectors & Fog 
    GmVec3 m_colorGradient1;                               // 0x94
    GmVec3 m_colorGradient2;                               // 0xA0
    uint32_t m_zoneFlags;                                  // 0xAC
    GxFog* m_fog;                                          // 0xB0 (Stored as CMwNod*)
    uint32_t m_fogFlags1;                                  // 0xB4
    uint32_t m_fogFlags2;                                  // 0xB8
    uint32_t m_fogFlags3;                                  // 0xBC
    float m_fogParams[4];                                  // 0xC0 to 0xCF
    float m_waterHeight1;                                  // 0xD0
    float m_waterHeight2;                                  // 0xD4
    float m_waterHeight3;                                  // 0xD8
    
    CFastBuffer<void*> m_bufferDC;                         // 0xDC (Size 0x0C)
    CMwNod* m_nodE8;                                       // 0xE8
    
    // Visibility Filters (SPlugVisibleFilter masks)
    uint16_t m_visFilter1;                                 // 0xEC
    uint16_t m_visFilter2;                                 // 0xEE
    uint16_t m_visFilter3;                                 // 0xF0
    uint16_t m_visFilter4;                                 // 0xF2
    
    CFastBuffer<void*> m_bufferF4;                         // 0xF4 (Size 0x0C)
    
    uint32_t m_lightCount;                                 // 0x100
    CHmsZoneVPacker* m_vPacker;                            // 0x104
    float m_waterRenderTileHeight;                         // 0x108
    
    CFastBuffer<CAudioSound*> m_sounds;                    // 0x10C (Size 0x0C)
    void (*m_callback)();                                  // 0x118

    // =================================================
    // Member Functions
    // =================================================
    CHmsZone();
    virtual ~CHmsZone();
    virtual void* _vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2);

    static void StaticInit();
    static CMwNod* MwNewCHmsZone();

    CAudioSound* AddSound(CAudioPort* param_1, CPlugSound* param_2, EBalanceGroup param_3, int param_4);
    CHmsCorpus* CreateZoneCorpus(CHmsZoneOverlay* param_1);
    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    
    int CheckPreloadVisionData(CHmsZone* param_1, CHmsViewport* param_2, CHmsCamera* param_3);
    int MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2);
    
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetMwClassId(CControlStyle* param_1);
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    
    uint32_t VirtualParam_Add(CMwCmdScriptVarClass* param_1, CMwStack* param_2, void* param_3);
    uint32_t VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3);
    uint32_t VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3);
    uint32_t VirtualParam_Sub(CGameCtnDecorationMood* param_1, CMwStack* param_2, void* param_3);
    
    void AddCorpus(SZone* param_1, CHmsCorpus* param_2);
    void AddField(CHmsZone* param_1, CHmsForceField* param_2);
    void AddItem(CGamePopUp* param_1, CFastStringInt* param_2, uint32_t param_3, int param_4);
    void AddLight(CHmsZone* param_1, CHmsLight* param_2, GmIso4* param_3);
    void ApplyFidParameters(CPlugFontBitmap* param_1, CSystemFidParameters* param_2, CSystemFidParameters* param_3, CFastBuffer<void*>* param_4);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    
    void CorpusChangeBuild(CHmsZone* param_1, CHmsCorpus* param_2, int param_3);
    void CorpusChangeCat(CHmsCorpus* param_2, int param_3);
    void CorpusChangeCat(CHmsZone* param_1, uint32_t param_2, EHmsCorpusCat param_3, EHmsCorpusCat param_4);
    void CorpusChangeLightEmitter(CHmsZone* param_1, CHmsCorpus* param_2, int param_3);
    
    void RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2);
    void RemoveField(CHmsZone* param_1, CHmsForceField* param_2);
    void RemoveItem(CHmsZone* param_1, CHmsItem* param_2);
    void RemoveLight(CHmsZoneVPacker* param_1, CHmsCorpusLight* param_2);
    void RemoveSound(CAudioPort* param_1, CAudioSound* param_2);
    
    void VPackerCreate(CHmsZone* param_1, SHmsVPackerCreate* param_2);
    void VPackerRemove(CHmsZone* param_1);
    void WaterRenderTileHeightSet(CHmsZone* param_1, float param_2);
};

#endif // CHMSZONE_HPP
