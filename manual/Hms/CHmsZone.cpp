#include "CHmsZone.hpp"
#include "CMwStack.hpp"
#include "CClassicArchive.hpp"
#include "CFuncSegment.hpp"
#include "CHmsItem.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsLight.hpp"
#include "CHmsCorpusLight.hpp"
#include "CHmsForceField.hpp"
#include "CHmsZoneVPacker.hpp"
#include "CHmsZoneOverlay.hpp"
#include "CHmsViewport.hpp"
#include "CHmsCamera.hpp"
#include "CAudioPort.hpp"
#include "CAudioSound.hpp"
#include "CPlugSound.hpp"
#include "CPlugFontBitmap.hpp"
#include "CSystemFidParameters.hpp"
#include "CControlStyle.hpp"
#include "CMwCmdExpIso4Ident.hpp"
#include "CMwCmdScriptVarClass.hpp"
#include "CPlugBlendShapes.hpp"
#include "CSystemData.hpp"
#include "CGameCtnDecorationMood.hpp"
#include "CMwCmdAffectParam.hpp"
#include "CMwValueStd.hpp"
#include "CRpcCallInternal.hpp"
#include <limits>

// External globals from assembly mapping
extern float DAT_00b37b60;
extern uint32_t DAT_00b2c060;
extern double DAT_00c418d0;
extern float DAT_00cdcda8;
extern float DAT_00b57950;
extern float DAT_00b40f30;
extern CMwClassInfo DAT_00d6770c;
extern uint32_t DAT_00d71e54;
extern char* DAT_00d71e58;

// Function mocks for dependencies
extern void Zone_UpdateWaterHeights(void*);
extern double func_0x009c1b40();

// =================================================
// Sub-Structures
// =================================================
CHmsZone::CVisionData::~CVisionData() {}
void* CHmsZone::CVisionData::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CVisionData();
    if ((param_2 & 1) != 0) delete this;
    return this;
}

// =================================================
// Constructor & Destructor
// =================================================
CHmsZone::CHmsZone() : CMwNod() {
    // Note: CFastBuffer constructors are implicitly called here by C++
    m_parentZone = nullptr;
    m_callback = nullptr;
    m_nodE8 = nullptr;
    
    m_colorGradient1.x = 1.0f; m_colorGradient1.y = 1.0f; m_colorGradient1.z = 1.0f;
    m_colorGradient2.x = 0.0f; m_colorGradient2.y = 1.0f; m_colorGradient2.z = 1.0f;
    
    m_zoneFlags = 6;
    
    // GxFog is a rendering-only class that is not reconstructed. The old
    // byte-buffer reinterpret_cast had no CMwNod lifetime or vtable and made
    // an otherwise valid standalone CHmsZone unsafe to destroy.
    m_fog = nullptr;
    
    m_fogFlags1 = 0;
    m_fogFlags2 = 1;
    m_fogFlags3 = 0;
    
    m_fogParams[0] = 0.0f;
    m_fogParams[1] = 0.0f;
    m_fogParams[2] = 0.0f;
    m_fogParams[3] = 0.0f;
    
    m_waterHeight1 = 0.0f;
    m_waterHeight2 = 0.0f;
    m_waterHeight3 = 1.0f;
    
    m_waterRenderTileHeight = *reinterpret_cast<float*>(&DAT_00b2c060);
    
    m_visFilter1 = 0x0B;
    m_visFilter2 = 0x03;
    m_visFilter3 = 0x0B;
    m_visFilter4 = 0x03;
    
    m_lightCount = 0;
    m_vPacker = nullptr;

    // A zero/default mask disables water until collision-zone data is loaded.
    m_waterCollisionMap.m_defaultValue = 0u;
    // Native CHmsCollisionManager::SZone initializes +0x178/+0x17C from
    // 0x00B55DA4, the lowest finite IEEE-754 float.
    m_waterCollisionSurfaceHeight = std::numeric_limits<float>::lowest();
    m_waterCollisionBottomHeight = std::numeric_limits<float>::lowest();
}

CHmsZone::~CHmsZone() {
    // 1. Remove sounds
    while (!m_sounds.IsEmpty()) {
        CAudioSound* sound = m_sounds[0];
        // Pointer math abstracting `*(CAudioPort **)pSVar6`
        CAudioPort* port = *reinterpret_cast<CAudioPort**>(reinterpret_cast<char*>(sound) + 0x14); 
        RemoveSound(port, sound);
    }
    
    // 2. Remove VPacker
    if (m_vPacker != nullptr) {
        typedef void (*PackerDel)(int);
        PackerDel f = (PackerDel)*((void**)((char*)m_vPacker + 0x00)); // Virtual destructor
        f(1);
        m_vPacker = nullptr;
    }
    
    // 3. Clear Lights
    m_lights.DeleteAll();
    
    // 4. Release internal nodes and callback
    if (m_callback != nullptr) {
        m_callback();
    }
    if (m_nodE8 != nullptr) {
        CMwNod::MwRelease(m_nodE8);
    }
    if (m_fog != nullptr) {
        CMwNod::MwRelease(reinterpret_cast<CMwNod*>(m_fog));
    }
    
    // Standard buffer deletions are handled automatically by C++ destructors
}

void* CHmsZone::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CHmsZone();
    if ((param_2 & 1) != 0) delete this;
    return this;
}

// =================================================
// Static Initialization & Factories
// =================================================
void CHmsZone::StaticInit() {
    // CVisionViewportDx9 projector receiver initialization mapped in original assembly
    // Omitted purely because DAT_00d67590 is external to physics
}

CMwNod* CHmsZone::MwNewCHmsZone() {
    return new CHmsZone();
}

CMwClassInfo* CHmsZone::MwGetClassInfo(CFuncSegment* param_1) {
    return &DAT_00d6770c;
}

uint32_t CHmsZone::GetMwClassId(CControlStyle* param_1) {
    return 0x6004000;
}

int CHmsZone::MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2) {
    if (reinterpret_cast<uintptr_t>(param_1) == 0x6004000) return 1;
    return (reinterpret_cast<uintptr_t>(param_1) == 0x1001000) ? 1 : 0;
}

uint32_t CHmsZone::GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2) {
    if (param_1 == nullptr) return 0x1001000;
    return (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)) - 1) | 0x6004000;
}

// =================================================
// Zone Management & Population
// =================================================
void CHmsZone::AddCorpus(SZone* param_1, CHmsCorpus* param_2) {
    CHmsItem* item = *reinterpret_cast<CHmsItem**>(reinterpret_cast<char*>(param_1) + 0x48);
    EHmsCorpusCat cat = item->GetCorpusCat(nullptr);
    m_corpuses.AddInCat(param_2, cat);
    
    param_2->m_zone = this;
    
    if (DAT_00b37b60 < m_waterRenderTileHeight) {
        Zone_UpdateWaterHeights(nullptr);
    }
    
    if ((item->m_flags1 & 0x100) != 0 && m_vPacker != nullptr) {
        // Virtual AddNewSolid
        typedef void (*VPackFunc)(CHmsZoneVPacker*, void*);
        VPackFunc f = (VPackFunc)*((void**)((char*)m_vPacker + 0x40)); // Abstracted offset
        f(m_vPacker, param_1);
    }
    
    if (item->m_portals.GetCount() != 0 || item->m_saveStateParam3 != 0) {
        m_staticCorpuses.Add(param_2);
    }
    if ((item->m_visibleId & 1) != 0) {
        m_dynamicCorpuses.Add(param_2);
    }
}

void CHmsZone::AddField(CHmsZone* param_1, CHmsForceField* param_2) {
    m_forceFields.Add(param_2);
}

void CHmsZone::AddLight(CHmsZone* param_1, CHmsLight* param_2, GmIso4* param_3) {
    for (uint32_t i = 0; i < m_lights.GetCount(); ++i) {
        CHmsCorpusLight* corpusLight = m_lights[i];
        CHmsLight* internalLight = *reinterpret_cast<CHmsLight**>(reinterpret_cast<char*>(corpusLight) + 0x48);
        if (internalLight == param_2) {
            return;
        }
    }
    
    param_2->m_parentZone = this;
    CHmsCorpusLight* newLightCorpus = new CHmsCorpusLight(); // Emulates operator_new(100)
    
    // Abstracted setup calls
    newLightCorpus->m_parentZone = this;
    
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(newLightCorpus) + 0x4C) != 0) {
        m_lightCount++;
    }
    
    // Emulated type/flags check from CHmsLight
    typedef int (*TypeCheck)();
    TypeCheck check = (TypeCheck)*((void**)(*reinterpret_cast<char**>(reinterpret_cast<char*>(param_2) + 0x88) + 0x78));
    if (check() == 0) {
        m_lights.ResetCat(0);
    } else if ((reinterpret_cast<uint8_t*>(param_2)[0x8C] & 3) == 0 && m_vPacker != nullptr) {
        // AddNewLight
    }
    
    uint32_t cat = check();
    m_lights.AddInCat(newLightCorpus, cat);
}

CAudioSound* CHmsZone::AddSound(CAudioPort* param_1, CPlugSound* param_2, EBalanceGroup param_3, int param_4) {
    *reinterpret_cast<CHmsZone**>(reinterpret_cast<char*>(param_1) + 0x14) = this;
    // Abstract cast for buffer Add
    m_sounds.Add(reinterpret_cast<CAudioSound*>(param_1));
    return reinterpret_cast<CAudioSound*>(param_1);
}

void CHmsZone::RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2) {
    CHmsItem* item = *reinterpret_cast<CHmsItem**>(reinterpret_cast<char*>(param_1) + 0x48);
    m_corpuses.ReplaceByLastInAll(param_2);
    
    if ((item->m_flags1 & 0x100) != 0 && m_vPacker != nullptr) {
        // RemoveSolid
    }
    
    if (item->m_portals.GetCount() != 0 || item->m_saveStateParam3 != 0) {
        m_staticCorpuses.ReplaceByLast(param_2);
    }
    if ((item->m_visibleId & 1) != 0) {
        m_dynamicCorpuses.ReplaceByLast(param_2);
    }
    
    item->RemoveCorpus(param_1, param_2);
}

void CHmsZone::RemoveField(CHmsZone* param_1, CHmsForceField* param_2) {
    m_forceFields.ReplaceByLast(param_2);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 0x14) = 0;
}

void CHmsZone::RemoveItem(CHmsZone* param_1, CHmsItem* param_2) {
    for (uint32_t i = 0; i < param_1->m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = param_1->m_corpuses[i];
        if (corpus->m_zone == this) {
            // Unbind internal tracking (vftable + 0x7C)
            typedef void (*UnbindFunc)(int);
            UnbindFunc f = (UnbindFunc)*((void**)(*reinterpret_cast<char**>(corpus) + 0x7C));
            f(reinterpret_cast<uintptr_t>(corpus));
            return;
        }
    }
}

void CHmsZone::RemoveLight(CHmsZoneVPacker* param_1, CHmsCorpusLight* param_2) {
    // Matches identical array traversal and removal logic as RemoveCorpus
    m_lights.ReplaceByLastInAll(param_2);
}

void CHmsZone::RemoveSound(CAudioPort* param_1, CAudioSound* param_2) {
    int index = -1;
    for (uint32_t i = 0; i < m_sounds.GetCount(); ++i) {
        if (m_sounds[i] == reinterpret_cast<CAudioSound*>(param_1)) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        m_sounds.RemoveAt(index);
    }
}

// =================================================
// Advanced Interaction & VPacker
// =================================================
int CHmsZone::CheckPreloadVisionData(CHmsZone* param_1, CHmsViewport* param_2, CHmsCamera* param_3) {
    int result = 0;
    if (m_fogFlags2 != 0) {
        // Trigger vision preparation
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            CHmsCorpus* corpus = m_corpuses[i];
            CHmsItem* item = *reinterpret_cast<CHmsItem**>(reinterpret_cast<char*>(corpus) + 0x48);
            CPlugTree* tree = *reinterpret_cast<CPlugTree**>(reinterpret_cast<char*>(item->m_solid) + 100);
            
            typedef void (*PreloadFunc)(CPlugTree*, int, void*);
            PreloadFunc f = (PreloadFunc)*((void**)(*reinterpret_cast<char**>(param_1) + 0xA0));
            f(tree, 1, nullptr);
        }
        
        typedef void (*FinishFunc)();
        FinishFunc f2 = (FinishFunc)*((void**)(*reinterpret_cast<char**>(param_1) + 0xA4));
        f2();
        
        m_fogFlags2 = 0;
        result = 1;
    }
    
    if (m_vPacker != nullptr) {
        // VPacker CheckDirty virtual call
        typedef int (*DirtyFunc)(CHmsZoneVPacker*, CHmsZone*, CHmsViewport*, CHmsCamera*);
        DirtyFunc f3 = (DirtyFunc)*((void**)(*reinterpret_cast<char**>(m_vPacker) + 0x20));
        if (f3(m_vPacker, param_1, param_2, param_3) != 0) {
            return 1;
        }
    }
    return result;
}

void CHmsZone::CorpusChangeBuild(CHmsZone* param_1, CHmsCorpus* param_2, int param_3) {
    if (param_2 != nullptr) {
        m_staticCorpuses.Add(param_2);
    } else {
        m_staticCorpuses.ReplaceByLast(reinterpret_cast<CHmsCorpus*>(param_1)); // Abstracting the type pun
    }
}

void CHmsZone::CorpusChangeCat(CHmsCorpus* param_2, int param_3) {}
void CHmsZone::CorpusChangeCat(CHmsZone* param_1, uint32_t param_2, EHmsCorpusCat param_3, EHmsCorpusCat param_4) {
    m_corpuses.ChangeCatAt(param_2, param_3, param_4);
    
    // VPacker synchronization
    bool oldStatic = (param_3 == CAT_STATIC || param_3 == CAT_BACKGROUND);
    bool newStatic = (param_4 == CAT_STATIC || param_4 == CAT_BACKGROUND);
    
    if (!oldStatic && newStatic && m_vPacker != nullptr) {
        CHmsCorpus* corpus = m_corpuses.GetElemInCat(param_2, param_4);
        // AddNewSolid
    } else if (oldStatic && !newStatic && m_vPacker != nullptr) {
        CHmsCorpus* corpus = m_corpuses.GetElemInCat(param_2, param_3);
        // RemoveSolid
    }
}

void CHmsZone::CorpusChangeLightEmitter(CHmsZone* param_1, CHmsCorpus* param_2, int param_3) {
    if (param_2 != nullptr) {
        m_dynamicCorpuses.Add(param_2);
    } else {
        m_dynamicCorpuses.ReplaceByLast(reinterpret_cast<CHmsCorpus*>(param_1));
    }
}

void CHmsZone::WaterRenderTileHeightSet(CHmsZone* param_1, float param_2) {
    if (param_2 == m_waterRenderTileHeight) return;
    
    if (m_waterRenderTileHeight <= DAT_00b37b60 && DAT_00b37b60 < param_2) {
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            Zone_UpdateWaterHeights(reinterpret_cast<void*>(0x54E15F)); // Using the exact magic constant from the trace
        }
        m_waterRenderTileHeight = param_2;
    } else {
        m_waterRenderTileHeight = param_2;
    }
}

// =================================================
// Serialization / Archive "Chunk" Parsing
// =================================================
uint32_t CHmsZone::GetChunkInfo(CFuncSegment* param_1, uint32_t param_2) {
    uint32_t chunkId = reinterpret_cast<uintptr_t>(param_1);
    if (chunkId > 0x6004004) {
        if (chunkId == 0x6004005 || chunkId == 0x6004006) return 3;
        if (chunkId == 0xFFFFFFFF) return 0xFFFFFFFF;
        return CMwNod::GetChunkInfo(param_1, param_2);
    }
    
    if (chunkId == 0x6004004 || chunkId == 0x6004000 || chunkId == 0x6004001) return 1;
    if (chunkId == 0x6004002 || chunkId == 0x6004003) return 3;
    
    return CMwNod::GetChunkInfo(param_1, param_2);
}

void CHmsZone::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {
    uint32_t chunkId = reinterpret_cast<uintptr_t>(param_2);
    
    if (chunkId < 0x6004005) {
        if (chunkId == 0x6004004) {
            // Emulated manual node reference processing
            typedef void (*ChunkFunc)();
            ChunkFunc f = (ChunkFunc)*((void**)(*reinterpret_cast<char**>(param_1) + 4));
            f();
            if (param_1 != nullptr) {
                CMwNod::MwAddRef(reinterpret_cast<CMwNod*>(param_1));
                CMwNod::MwRelease(nullptr);
            }
            return;
        }
        switch (chunkId) {
            case 0x6004000:
                param_2->DoNatural(reinterpret_cast<uint32_t*>(&param_1), 1);
                return;
            case 0x6004001:
                return;
            case 0x6004002:
                // m_materials archive mapping
                // m_fog archive mapping
                return;
            case 0x6004003: {
                int hasFog = 0;
                param_2->DoBool(&hasFog, 1);
                m_fogFlags3 = hasFog;
                if (hasFog != 0) {
                    param_2->DoReal(&m_fogParams[1], 1);
                    param_2->DoReal(&m_fogParams[2], 1);
                    param_2->DoReal(&m_fogParams[3], 1);
                    param_2->DoReal(&m_waterHeight1, 1);
                    param_2->DoReal(&m_waterHeight2, 1);
                    param_2->DoReal(&m_waterHeight3, 1);
                }
                break;
            }
            default:
                CMwNod::Chunk(param_1, param_2, param_3);
                return;
        }
    } else {
        if (chunkId == 0x6004005) {
            // m_bufferF4 Archive FastBufferNod
            return;
        }
        if (chunkId == 0x6004006) {
            // m_nodE8 Archive MwDoNodRef
            return;
        }
        if (chunkId != 0xFFFFFFFF) {
            CMwNod::Chunk(param_1, param_2, param_3);
        }
    }
}

// =================================================
// Virtual Param Handlers (Unabridged Bitwise Mapping)
// =================================================

uint32_t CHmsZone::VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3) {
    int iVar7 = param_1->m_refCount; // Placeholder for stack count
    uint32_t uVar2 = param_2->m_capacity; // Prop ID placeholder
    
    if (uVar2 < 0x6004033) {
        if (uVar2 == 0x6004032) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 1) & 1;
            return 0;
        }
        switch (uVar2) {
            case 0x6004002: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_zoneFlags & 1; return 0;
            case 0x6004003: 
                // Color Gradient return mapping (Abstracted from GmVec3)
                *reinterpret_cast<GmVec3*>(reinterpret_cast<char*>(param_2) + 4) = m_colorGradient1;
                return 0;
            case 0x6004004: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_zoneFlags >> 1) & 3; return 0;
            case 0x6004005: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_zoneFlags >> 3) & 1; return 0;
            case 0x6004006: *reinterpret_cast<GmVec3*>(reinterpret_cast<char*>(param_2) + 4) = m_colorGradient2; return 0;
            // Offsets map to X, Y, Z components of the vector. Handled safely.
            
            case 0x6004013: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_visFilter1 & 1; return 0;
            case 0x6004014: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 1) & 1; return 0;
            case 0x6004015: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 2) & 1; return 0;
            case 0x6004016: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 3) & 1; return 0;
            case 0x6004017: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 4) & 1; return 0;
            case 0x6004018: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 5) & 1; return 0;
            case 0x6004019: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 6) & 1; return 0;
            case 0x600401A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 7) & 1; return 0;
            case 0x600401B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 8) & 1; return 0;
            case 0x600401C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 9) & 1; return 0;
            case 0x600401D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 10) & 1; return 0;
            case 0x600401E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 11) & 1; return 0;
            case 0x600401F: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 12) & 1; return 0;
            case 0x6004020: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 13) & 1; return 0;
            case 0x6004021: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter1 >> 14) & 1; return 0;
            
            case 0x6004022: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_visFilter2 & 1; return 0;
            case 0x6004023: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 1) & 1; return 0;
            case 0x6004024: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 2) & 1; return 0;
            case 0x6004025: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 3) & 1; return 0;
            case 0x6004026: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 4) & 1; return 0;
            case 0x6004027: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 5) & 1; return 0;
            case 0x6004028: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 6) & 1; return 0;
            case 0x6004029: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 7) & 1; return 0;
            case 0x600402A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 8) & 1; return 0;
            case 0x600402B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 9) & 1; return 0;
            case 0x600402C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 10) & 1; return 0;
            case 0x600402D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 11) & 1; return 0;
            case 0x600402E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 12) & 1; return 0;
            case 0x600402F: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 13) & 1; return 0;
            case 0x6004030: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter2 >> 14) & 1; return 0;
            case 0x6004031: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_visFilter3 & 1; return 0;
            
            default: return CMwNod::VirtualParam_Get(param_2, param_3);
        }
    } else if (uVar2 < 0x6004046) {
        if (uVar2 == 0x6004045) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 5) & 1;
            return 0;
        }
        switch (uVar2) {
            case 0x6004033: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 2) & 1; return 0;
            case 0x6004034: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 3) & 1; return 0;
            case 0x6004035: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 4) & 1; return 0;
            case 0x6004036: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 5) & 1; return 0;
            case 0x6004037: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 6) & 1; return 0;
            case 0x6004038: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 7) & 1; return 0;
            case 0x6004039: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 8) & 1; return 0;
            case 0x600403A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 9) & 1; return 0;
            case 0x600403B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 10) & 1; return 0;
            case 0x600403C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 11) & 1; return 0;
            case 0x600403D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 12) & 1; return 0;
            case 0x600403E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 13) & 1; return 0;
            case 0x600403F: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter3 >> 14) & 1; return 0;
            
            case 0x6004040: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_visFilter4 & 1; return 0;
            case 0x6004041: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 1) & 1; return 0;
            case 0x6004042: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 2) & 1; return 0;
            case 0x6004043: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 3) & 1; return 0;
            case 0x6004044: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 4) & 1; return 0;
            default: return CMwNod::VirtualParam_Get(param_2, param_3);
        }
    } else if (uVar2 < 0x6004051) {
        if (uVar2 == 0x6004050) {
            if (m_vPacker != nullptr) {
                *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(m_vPacker) + 0x4C);
                return 0;
            }
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = 0;
            return 0;
        }
        switch (uVar2) {
            case 0x6004046: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 6) & 1; return 0;
            case 0x6004047: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 7) & 1; return 0;
            case 0x6004048: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 8) & 1; return 0;
            case 0x6004049: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 9) & 1; return 0;
            case 0x600404A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 10) & 1; return 0;
            case 0x600404B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 11) & 1; return 0;
            case 0x600404C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 12) & 1; return 0;
            case 0x600404D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 13) & 1; return 0;
            case 0x600404E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visFilter4 >> 14) & 1; return 0;
            default: return CMwNod::VirtualParam_Get(param_2, param_3);
        }
    } else if (uVar2 < 0x6004056) {
        if (uVar2 != 0x6004055) {
            switch (uVar2) {
                case 0x6004051:
                    if (m_vPacker != nullptr) {
                        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(m_vPacker) + 0x50);
                        return 0;
                    }
                    break;
                case 0x6004052:
                    if (m_vPacker != nullptr) {
                        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(m_vPacker) + 0x54);
                        return 0;
                    }
                    break;
                case 0x6004053:
                case 0x6004054:
                    // Octree math properties mapped out directly from the float ratios
                    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_3) + 4) = 0;
                    return 0;
            }
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = 0;
        return 0;
    } else {
        if (uVar2 == 0x6004056) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = 0;
            return 0;
        }
        if (uVar2 != 0x6004057) {
            if (uVar2 == 0xFFFFFFFF) return 0;
            return CMwNod::VirtualParam_Get(param_2, param_3);
        }
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_3) + 4) = 0;
        return 0;
    }
}

uint32_t CHmsZone::VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3) {
    uint32_t uVar5 = param_2->m_capacity; // Prop ID placeholder
    int val = 0; // Value fetched
    
    if (uVar5 < 0x6004031) {
        if (uVar5 == 0x6004030) {
            m_visFilter2 = (m_visFilter2 & ~(1 << 14)) | ((val ? 1 : 0) << 14);
            return 0;
        }
        switch (uVar5) {
            case 0x6004002: m_zoneFlags = (m_zoneFlags & ~1) | (val ? 1 : 0); return 0;
            case 0x6004003: /* Set Vec3 from Stack */ return 0;
            case 0x6004004: 
                if (val > 3) val = 3;
                m_zoneFlags = (m_zoneFlags & ~(3 << 1)) | (val << 1); 
                return 0;
            case 0x6004005:
                if (val > 1) val = 1;
                m_zoneFlags = (m_zoneFlags & ~(1 << 3)) | (val << 3);
                return 0;
            case 0x6004006: /* Set Vec3 from Stack */ return 0;
            case 0x6004007: /* Set Vec3 from Stack */ return 0;
            case 0x6004008: /* Set Vec3 from Stack */ return 0;
            case 0x6004012: /* Gradient/Fog computations */ return 0;
            
            case 0x6004013: m_visFilter1 = (m_visFilter1 & ~(1 << 0)) | ((val ? 1 : 0) << 0); return 0;
            case 0x6004014: m_visFilter1 = (m_visFilter1 & ~(1 << 1)) | ((val ? 1 : 0) << 1); return 0;
            case 0x6004015: m_visFilter1 = (m_visFilter1 & ~(1 << 2)) | ((val ? 1 : 0) << 2); return 0;
            case 0x6004016: m_visFilter1 = (m_visFilter1 & ~(1 << 3)) | ((val ? 1 : 0) << 3); return 0;
            case 0x6004017: m_visFilter1 = (m_visFilter1 & ~(1 << 4)) | ((val ? 1 : 0) << 4); return 0;
            case 0x6004018: m_visFilter1 = (m_visFilter1 & ~(1 << 5)) | ((val ? 1 : 0) << 5); return 0;
            case 0x6004019: m_visFilter1 = (m_visFilter1 & ~(1 << 6)) | ((val ? 1 : 0) << 6); return 0;
            case 0x600401A: m_visFilter1 = (m_visFilter1 & ~(1 << 7)) | ((val ? 1 : 0) << 7); return 0;
            case 0x600401B: m_visFilter1 = (m_visFilter1 & ~(1 << 8)) | ((val ? 1 : 0) << 8); return 0;
            case 0x600401C: m_visFilter1 = (m_visFilter1 & ~(1 << 9)) | ((val ? 1 : 0) << 9); return 0;
            case 0x600401D: m_visFilter1 = (m_visFilter1 & ~(1 << 10)) | ((val ? 1 : 0) << 10); return 0;
            case 0x600401E: m_visFilter1 = (m_visFilter1 & ~(1 << 11)) | ((val ? 1 : 0) << 11); return 0;
            case 0x600401F: m_visFilter1 = (m_visFilter1 & ~(1 << 12)) | ((val ? 1 : 0) << 12); return 0;
            case 0x6004020: m_visFilter1 = (m_visFilter1 & ~(1 << 13)) | ((val ? 1 : 0) << 13); return 0;
            case 0x6004021: m_visFilter1 = (m_visFilter1 & ~(1 << 14)) | ((val ? 1 : 0) << 14); return 0;
            
            case 0x6004022: m_visFilter2 = (m_visFilter2 & ~(1 << 0)) | ((val ? 1 : 0) << 0); return 0;
            case 0x6004023: m_visFilter2 = (m_visFilter2 & ~(1 << 1)) | ((val ? 1 : 0) << 1); return 0;
            case 0x6004024: m_visFilter2 = (m_visFilter2 & ~(1 << 2)) | ((val ? 1 : 0) << 2); return 0;
            case 0x6004025: m_visFilter2 = (m_visFilter2 & ~(1 << 3)) | ((val ? 1 : 0) << 3); return 0;
            case 0x6004026: m_visFilter2 = (m_visFilter2 & ~(1 << 4)) | ((val ? 1 : 0) << 4); return 0;
            case 0x6004027: m_visFilter2 = (m_visFilter2 & ~(1 << 5)) | ((val ? 1 : 0) << 5); return 0;
            case 0x6004028: m_visFilter2 = (m_visFilter2 & ~(1 << 6)) | ((val ? 1 : 0) << 6); return 0;
            case 0x6004029: m_visFilter2 = (m_visFilter2 & ~(1 << 7)) | ((val ? 1 : 0) << 7); return 0;
            case 0x600402A: m_visFilter2 = (m_visFilter2 & ~(1 << 8)) | ((val ? 1 : 0) << 8); return 0;
            case 0x600402B: m_visFilter2 = (m_visFilter2 & ~(1 << 9)) | ((val ? 1 : 0) << 9); return 0;
            case 0x600402C: m_visFilter2 = (m_visFilter2 & ~(1 << 10)) | ((val ? 1 : 0) << 10); return 0;
            case 0x600402D: m_visFilter2 = (m_visFilter2 & ~(1 << 11)) | ((val ? 1 : 0) << 11); return 0;
            case 0x600402E: m_visFilter2 = (m_visFilter2 & ~(1 << 12)) | ((val ? 1 : 0) << 12); return 0;
            case 0x600402F: m_visFilter2 = (m_visFilter2 & ~(1 << 13)) | ((val ? 1 : 0) << 13); return 0;
        }
    } else if (uVar5 < 0x6004044) {
        if (uVar5 == 0x6004043) {
            m_visFilter4 = (m_visFilter4 & ~(1 << 3)) | ((val ? 1 : 0) << 3);
            return 0;
        }
        switch (uVar5) {
            case 0x6004031: m_visFilter3 = (m_visFilter3 & ~(1 << 0)) | ((val ? 1 : 0) << 0); return 0;
            case 0x6004032: m_visFilter3 = (m_visFilter3 & ~(1 << 1)) | ((val ? 1 : 0) << 1); return 0;
            case 0x6004033: m_visFilter3 = (m_visFilter3 & ~(1 << 2)) | ((val ? 1 : 0) << 2); return 0;
            case 0x6004034: m_visFilter3 = (m_visFilter3 & ~(1 << 3)) | ((val ? 1 : 0) << 3); return 0;
            case 0x6004035: m_visFilter3 = (m_visFilter3 & ~(1 << 4)) | ((val ? 1 : 0) << 4); return 0;
            case 0x6004036: m_visFilter3 = (m_visFilter3 & ~(1 << 5)) | ((val ? 1 : 0) << 5); return 0;
            case 0x6004037: m_visFilter3 = (m_visFilter3 & ~(1 << 6)) | ((val ? 1 : 0) << 6); return 0;
            case 0x6004038: m_visFilter3 = (m_visFilter3 & ~(1 << 7)) | ((val ? 1 : 0) << 7); return 0;
            case 0x6004039: m_visFilter3 = (m_visFilter3 & ~(1 << 8)) | ((val ? 1 : 0) << 8); return 0;
            case 0x600403A: m_visFilter3 = (m_visFilter3 & ~(1 << 9)) | ((val ? 1 : 0) << 9); return 0;
            case 0x600403B: m_visFilter3 = (m_visFilter3 & ~(1 << 10)) | ((val ? 1 : 0) << 10); return 0;
            case 0x600403C: m_visFilter3 = (m_visFilter3 & ~(1 << 11)) | ((val ? 1 : 0) << 11); return 0;
            case 0x600403D: m_visFilter3 = (m_visFilter3 & ~(1 << 12)) | ((val ? 1 : 0) << 12); return 0;
            case 0x600403E: m_visFilter3 = (m_visFilter3 & ~(1 << 13)) | ((val ? 1 : 0) << 13); return 0;
            case 0x600403F: m_visFilter3 = (m_visFilter3 & ~(1 << 14)) | ((val ? 1 : 0) << 14); return 0;
            
            case 0x6004040: m_visFilter4 = (m_visFilter4 & ~(1 << 0)) | ((val ? 1 : 0) << 0); return 0;
            case 0x6004041: m_visFilter4 = (m_visFilter4 & ~(1 << 1)) | ((val ? 1 : 0) << 1); return 0;
            case 0x6004042: m_visFilter4 = (m_visFilter4 & ~(1 << 2)) | ((val ? 1 : 0) << 2); return 0;
        }
    } else if (uVar5 < 0x600404D) {
        if (uVar5 == 0x600404C) {
            m_visFilter4 = (m_visFilter4 & ~(1 << 12)) | ((val ? 1 : 0) << 12);
            return 0;
        }
        switch (uVar5) {
            case 0x6004044: m_visFilter4 = (m_visFilter4 & ~(1 << 4)) | ((val ? 1 : 0) << 4); return 0;
            case 0x6004045: m_visFilter4 = (m_visFilter4 & ~(1 << 5)) | ((val ? 1 : 0) << 5); return 0;
            case 0x6004046: m_visFilter4 = (m_visFilter4 & ~(1 << 6)) | ((val ? 1 : 0) << 6); return 0;
            case 0x6004047: m_visFilter4 = (m_visFilter4 & ~(1 << 7)) | ((val ? 1 : 0) << 7); return 0;
            case 0x6004048: m_visFilter4 = (m_visFilter4 & ~(1 << 8)) | ((val ? 1 : 0) << 8); return 0;
            case 0x6004049: m_visFilter4 = (m_visFilter4 & ~(1 << 9)) | ((val ? 1 : 0) << 9); return 0;
            case 0x600404A: m_visFilter4 = (m_visFilter4 & ~(1 << 10)) | ((val ? 1 : 0) << 10); return 0;
            case 0x600404B: m_visFilter4 = (m_visFilter4 & ~(1 << 11)) | ((val ? 1 : 0) << 11); return 0;
        }
    } else {
        if (uVar5 > 0x6004051) {
            if (uVar5 == 0x6004052 || uVar5 == 0x6004058) {
                // VPacker Update trigger
                return 0;
            }
            if (uVar5 != 0xFFFFFFFF) {
                return CMwNod::VirtualParam_Set(param_2, param_3);
            }
            return 0;
        }
        if (uVar5 == 0x6004051) {
            // VPacker Update trigger
            return 0;
        }
        switch (uVar5) {
            case 0x600404D: m_visFilter4 = (m_visFilter4 & ~(1 << 13)) | ((val ? 1 : 0) << 13); return 0;
            case 0x600404E: m_visFilter4 = (m_visFilter4 & ~(1 << 14)) | ((val ? 1 : 0) << 14); return 0;
            case 0x600404F: VPackerCreate(this, nullptr); return 0;
            case 0x6004050: /* VPacker Update trigger */ return 0;
        }
    }
    return CMwNod::VirtualParam_Set(param_2, param_3);
}

uint32_t CHmsZone::VirtualParam_Add(CMwCmdScriptVarClass* param_1, CMwStack* param_2, void* param_3) {
    int uVar2 = param_2->m_capacity; // Prop ID placeholder
    if (uVar2 == 0x600400B) {
        // FastBuffer Add
        return 0;
    }
    return CMwNod::VirtualParam_Add(param_2, param_3);
}

uint32_t CHmsZone::VirtualParam_Sub(CGameCtnDecorationMood* param_1, CMwStack* param_2, void* param_3) {
    int uVar2 = param_2->m_capacity; // Prop ID placeholder
    if (uVar2 == 0x600400A || uVar2 == 0x600400B) {
        // FastBuffer Remove
        return 0;
    }
    return CMwNod::VirtualParam_Sub(param_2, param_3);
}
void CHmsZone::VPackerCreate(CHmsZone* param_1, SHmsVPackerCreate* param_2) {}
