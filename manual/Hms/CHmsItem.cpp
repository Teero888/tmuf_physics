#include "CPlugBlendShapes.hpp"
#include "CHmsItem.hpp"
#include "CMwStack.hpp"
#include "CClassicArchive.hpp"
#include "CFuncSegment.hpp"
#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsZone.hpp"
#include "CHmsPortal.hpp"
#include "CPlugSolid.hpp"
#include "CPlugTree.hpp"
#include "CSystemCrashDump.hpp"
#include "CMwClassInfo.hpp"
#include "CMwParam.hpp"
#include "CSceneToyBoat.hpp"
#include "CSceneToyMotorbike.hpp"
#include "CClassicBufferMemory.hpp"
#include "CGameCtnZone.hpp"
#include "CGameCtnCollection.hpp"
#include "CPlugAudio.hpp"
#include "CMwCmdBufferCore.hpp"
#include "CDx9DeviceCaps.hpp"
#include "CMwCmdAffectParam.hpp"

// =================================================
// Engine Globals & Externs
// =================================================
extern uint32_t DAT_00b2c060;
extern CHmsItem::CCallbackRenderBeforeTree* DAT_00d67560;
extern CMwClassInfo DAT_00d67564;
extern CSystemCrashDump DAT_00d5546c;
extern char* DAT_00d731e0; 
extern double DAT_00c418d0; // Standard float/double constant for math fixes

extern void OnAccessViolation_ConcatToCrashFileName(void*);

// =================================================
// Sub-Structures
// =================================================
CHmsItem::CCallback::~CCallback() {}
CHmsItem::CCallbackRenderBeforeTree::~CCallbackRenderBeforeTree() {}

CHmsItem::SCallbackList::SCallbackList() {
    for (CCallback*& callback : m_callbacks) callback = nullptr;
}
CHmsItem::SCallbackList::~SCallbackList() {}

// =================================================
// Constructor & Destructor
// =================================================
CHmsItem::CHmsItem() : CMwNod() {
    m_portals.SetCount(0); // Offset 0x28
    m_corpuses.SetSizeAtLeast(1); // Offset 0x34
    
    m_solid = nullptr;
    m_callbacks = nullptr;
    m_name = nullptr;
    m_nod44 = nullptr;
    m_ptr54 = nullptr;
    
    m_saveStateParam1 = 0;
    m_saveStateParam2 = 0xFFFFFFFF;
    m_saveStateParam3 = DAT_00b2c060;
    
    m_flags1 = 0;
    m_flags2 = 0;
    m_visibleId = 0;
    
    // Explicit initialization sequence from assembly
    m_flags1 = (m_flags1 & 0xFF8004FF) | 0x19800000;
    m_flags2 = 0xFFF1C000;
}

CHmsItem::~CHmsItem() {
    if (m_ptr54 != nullptr) {
        delete m_ptr54;
        m_ptr54 = nullptr;
    }
    
    if (m_callbacks != nullptr) {
        delete m_callbacks;
        m_callbacks = nullptr;
    }
    
    if (m_solid != nullptr) {
         // Clear back-reference
        CMwNod::MwRelease(reinterpret_cast<CMwNod*>(m_solid));
    }
    
    m_portals.DeleteAll();
    
    if (m_nod44 != nullptr) {
        CMwNod::MwRelease(m_nod44);
    }
    
    m_corpuses.DeleteAll();
}

void* CHmsItem::_scalar_deleting_destructor_(CPfmHeap* heap, uint32_t flag) {
    this->~CHmsItem();
    if ((flag & 1) != 0) {
        delete this;
    }
    return this;
}

// =================================================
// Static Initialization & Factories
// =================================================
void CHmsItem::StaticInit() {
    // Note: The massive pointer initialization mapped in Ghidra was building 
    // the global CVisionViewportDx9 projector receiver arrays.
    // For a strictly 1:1 mapped physics module, the arrays initialize state enums.
    // Implementation omitted here as DAT_00d67590 is a strictly graphics-bound global array
    // not present in the class definition.
}

CMwNod* CHmsItem::MwNewCHmsItem() {
    return new CHmsItem();
}

void CHmsItem::CallbackSetRenderBeforeTree(CCallbackRenderBeforeTree* callback) {
    DAT_00d67560 = callback;
}

// =================================================
// Core State, Type & Information
// =================================================
EHmsCorpusCat CHmsItem::GetCorpusCat(CHmsItem* param_1) {
    if ((m_flags1 & 0x200) != 0) {
        SetCountShadowTexCasted(nullptr, 1, 0);
        SetIsVisionStatic(nullptr, 0);
        return CAT_BACKGROUND;
    }
    if ((m_flags1 & 0xFF) != 0) {
        return (m_flags1 & 0x100) != 0 ? CAT_STATIC : CAT_ZOMBIE;
    }
    return (m_flags1 & 0x100) != 0 ? CAT_STATIC : CAT_KINEMATIC;
}

CMwClassInfo* CHmsItem::MwGetClassInfo(CFuncSegment* param_1) {
    return &DAT_00d67564;
}

uint32_t CHmsItem::GetMwClassId(CControlStyle* param_1) {
    return 0x6003000;
}

int CHmsItem::MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2) {
    if (reinterpret_cast<uintptr_t>(param_1) == 0x6003000) return 1;
    return (reinterpret_cast<uintptr_t>(param_1) == 0x1001000) ? 1 : 0;
}

uint32_t CHmsItem::GetSaveStateSize(CMwClassInfoCSceneToyBoat* param_1, EMobilStateQuality param_2) {
    if (param_1 == nullptr) return 0xF;
    if (reinterpret_cast<uintptr_t>(param_1) != 1) return 0;
    return 0x1A;
}

uint32_t CHmsItem::GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2) {
    if (param_1 == nullptr) return 0x1001000;
    return (static_cast<uint32_t>(reinterpret_cast<uintptr_t>(param_1)) - 1) | 0x6003000;
}

int CHmsItem::OnCrashDump(CMwNod* param_1, CFastString* param_2) {
    int res = CMwNod::OnCrashDump(param_1, param_2);
    if (res == 0) return 0;
    
    typedef void (*DumpFunc)();
    DumpFunc d1 = (DumpFunc)*((void**)((char*)&DAT_00d5546c + 0x14));
    d1();
    
    DAT_00d5546c.IsValid_DumpFidAndMwId(param_1, "SceneMobil", m_name, reinterpret_cast<CMwNod*>(1));
    
    if (m_solid != nullptr) {
        int valid = DAT_00d5546c.IsValid_DumpFidAndMwId(param_1, reinterpret_cast<const char*>(0xB56048), reinterpret_cast<const char*>(m_solid), reinterpret_cast<CMwNod*>(1));
        if (valid != 0) {
            DumpFunc d2 = (DumpFunc)*((void**)((char*)m_solid + 0x58));
            d2();
        }
    }
    
    DumpFunc d3 = (DumpFunc)*((void**)((char*)&DAT_00d5546c + 0x18));
    d3();
    return 1;
}

void CHmsItem::OnNodLoaded(CDx9DeviceCaps* param_1) {
    OnAccessViolation_ConcatToCrashFileName(nullptr);
    if ((m_flags1 & 0x200) != 0 && m_solid != nullptr) {
        // CPlugSolid::ExclusionEllipsoidRadiusCompute
        typedef void (*RadFunc)(CPlugSolid*, CDx9DeviceCaps*);
        RadFunc f = (RadFunc)*((void**)((char*)m_solid + 0x30)); // Mock offset based on usual layout
        f(m_solid, param_1);
    }
}

// =================================================
// Corpus & Zone Management
// =================================================
CGameCtnZone* CHmsItem::GetZone(CGameCtnCollection* param_1, CMwId* param_2) {
    if (m_corpuses.GetCount() > reinterpret_cast<uintptr_t>(param_1)) {
        CHmsCorpus* corpus = m_corpuses[reinterpret_cast<uintptr_t>(param_1)];
        return reinterpret_cast<CGameCtnZone*>(corpus->m_zone); // Assuming zone at +0x14
    }
    return nullptr;
}

CHmsCorpus* CHmsItem::GetCorpus(CHmsItem* param_1, CHmsZone* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_corpuses[i];
        if (corpus->m_zone == param_2) {
            return corpus;
        }
    }
    return nullptr;
}

CHmsCorpus* CHmsItem::GetCurrentCorpus(CHmsItem* param_1) {
    if (m_corpuses.GetCount() != 0) {
        return m_corpuses[0];
    }
    return nullptr;
}

uint32_t CHmsItem::GetCorpusIndex(CHmsItem* param_1, CHmsZone* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_corpuses[i];
        if (corpus->m_zone == param_2) {
            return i;
        }
    }
    return 0xFFFFFFFF;
}

void CHmsItem::AddCorpus(SZone* param_1, CHmsCorpus* param_2) {
    m_corpuses.Add(param_2);
}

void CHmsItem::RemoveCorpus(CHmsZoneOverlay* param_1, CHmsCorpus* param_2) {
    m_corpuses.ReplaceByLast(param_2);
}

void CHmsItem::UpdateCorpusCat(CHmsItem* param_1) {
    EHmsCorpusCat cat = GetCorpusCat(nullptr);
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_corpuses[i];
        CHmsZone* zone = corpus->m_zone;
        
        // CFastBufferCat<...>::FindIndexInAll equivalent logic
        int index = zone->m_corpuses.FindIndexInAll(corpus);
        if (index != 0 && reinterpret_cast<uintptr_t>(corpus) != cat) {
            zone->CorpusChangeCat(corpus, cat);
        }
    }
}

// =================================================
// Physics & Dynamics Forwarding
// =================================================
void CHmsItem::AddForce(CHmsItem* param_1, GmVec3* param_2, GmVec3* param_3) {
    if (param_2 == nullptr) return;
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->AddLocalForce(param_2);
        }
    }
}

void CHmsItem::AddImpulse(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->AddLocalImpulse(param_2);
        }
    }
}

void CHmsItem::AddTorque(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->AddLocalTorque(param_2);
        }
    }
}

void CHmsItem::GetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            dyna->GetLocalAngularSpeed(param_2);
            return;
        }
    }
    param_2->x = 0.0f; param_2->y = 0.0f; param_2->z = 0.0f;
}

void CHmsItem::GetForce(CHmsItem* param_1, GmVec3* param_2) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            dyna->GetLocalForce(param_2);
            return;
        }
    }
    param_2->x = 0.0f; param_2->y = 0.0f; param_2->z = 0.0f;
}

void CHmsItem::GetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            dyna->GetLocalLinearSpeed(param_2);
            return;
        }
    }
    param_2->x = 0.0f; param_2->y = 0.0f; param_2->z = 0.0f;
}

void CHmsItem::SetAngularSpeed(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->SetLocalAngularSpeed(param_2);
        }
    }
}

void CHmsItem::SetForce(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->SetLocalForce(param_2);
        }
    }
}

void CHmsItem::SetLinearSpeed(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->SetLocalLinearSpeed(param_2);
        }
    }
}

void CHmsItem::SetTorque(CHmsItem* param_1, GmVec3* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsDyna* dyna = m_corpuses[i]->m_dyna;
        if (dyna != nullptr) {
            dyna->SetLocalTorque(param_2);
        }
    }
}

void CHmsItem::GetLocation(GmLocFreeVal* param_1, GmIso4* param_2) {
    CHmsCorpus* corpus = GetCorpus(nullptr, reinterpret_cast<CHmsZone*>(param_1));
    if (corpus) {
        typedef void (*LocFunc)(CHmsCorpus*);
        LocFunc f = (LocFunc)*((void**)((char*)corpus + 0x78));
        f(corpus);
    }
}

void CHmsItem::SetLocation(CPlugTree* param_1, GmIso4* param_2) {
    uint32_t index = GetCorpusIndex(nullptr, reinterpret_cast<CHmsZone*>(param_2));
    if (index < m_corpuses.GetCount()) {
        CHmsCorpus* corpus = m_corpuses[index];
        
        if (m_corpuses.GetCount() > 1) {
            
            
            
            
            
            GmIso4 inv;
            
            
            GmIso4 mult;
            mult.SetMult(reinterpret_cast<GmIso4*>(param_2)); // TODO
            
            GmMat3 ortho;
            ortho.OrthoNormalize();
            
            for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
                if (i != index) {
                    CHmsCorpus* c2 = m_corpuses[i];
                    typedef GmIso3* (*LocFunc2)(CHmsCorpus*);
                    LocFunc2 f2 = (LocFunc2)*((void**)((char*)c2 + 0x78));
                    GmIso3* pIso3 = f2(c2);
                    
                    GmIso4 temp;
                    GmIso4::Mult(&temp, reinterpret_cast<GmIso3*>(pIso3));
                    c2->SetLocation(nullptr, reinterpret_cast<GmIso4*>(&temp));
                }
            }
        }
        corpus->SetLocation(param_1, param_2);
    }
}

void CHmsItem::RotateOf(CHmsCorpus* param_1, GmMat3* param_2) {
    GmMat3* pGVar1 = reinterpret_cast<GmMat3*>(reinterpret_cast<char*>(param_1) + 8);
    CHmsCorpus* local_2c = *reinterpret_cast<CHmsCorpus**>(reinterpret_cast<char*>(param_1) + 0xC);
    
    GmMat3 local_24;
    local_24.Set(GmQuat()); // TODO
    RotateOf(local_2c, pGVar1);
}

void CHmsItem::TransformOf(CHmsItem* param_1, GmIso4* param_2) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_corpuses[i];
        
        CHmsDyna* dyna = corpus->m_dyna;
        GmIso3* gIso = nullptr;
        if (dyna == nullptr || (gIso = reinterpret_cast<GmIso3*>(reinterpret_cast<char*>(dyna) + 0x33C)) == nullptr) {
            typedef GmIso3* (*LocFunc)(CHmsCorpus*);
            LocFunc f = (LocFunc)*((void**)((char*)corpus + 0x78));
            GmIso3* pIso = f(corpus);
            
            GmIso4 mult;
            GmIso4::Mult(&mult, pIso); // TODO: implement full GmIso4::Mult
            corpus->SetLocation(nullptr, &mult);
        } else {
            GmIso4 temp1;
            GmIso4::Mult(&temp1, gIso);
            
            GmIso3* pGVar6 = nullptr;
            if (dyna != nullptr) {
                pGVar6 = reinterpret_cast<GmIso3*>(reinterpret_cast<char*>(dyna) + 0x338);
            }
            
            GmIso4 temp2;
            GmIso4::Mult(&temp2, pGVar6);
        }
    }
}

// =================================================
// Property Toggles (Bitwise Flag Management)
// =================================================
void CHmsItem::SetCollisionGroup(CHmsItem* param_1, ECollisionGroup param_2) {
    if ((CHmsItem*)((m_flags1 >> 13) & 0xF) != param_1) {
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            // Virtual call to Pre-Change
            typedef void (*GroupFunc)(CHmsCorpus*);
            GroupFunc f1 = (GroupFunc)*((void**)((char*)m_corpuses[i] + 0x84));
            f1(m_corpuses[i]);
        }
        
        m_flags1 = (m_flags1 & ~0x1E000) | ((reinterpret_cast<uintptr_t>(param_1) & 0xF) << 13);
        
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            // Virtual call to Post-Change
            typedef void (*GroupFunc)(CHmsCorpus*);
            GroupFunc f2 = (GroupFunc)*((void**)((char*)m_corpuses[i] + 0x88));
            f2(m_corpuses[i]);
        }
    }
}

void CHmsItem::SetContactInterest(CHmsItem* param_1, EContactInterest param_2) {
    m_flags1 = (m_flags1 & ~0x60000) | ((reinterpret_cast<uintptr_t>(param_1) & 0x3) << 17);
}

void CHmsItem::SetCountShadowTexCasted(CHmsItem* param_1, uint8_t param_2, int param_3) {
    if ((m_flags1 & 0xFF) != reinterpret_cast<uintptr_t>(param_1) || 
        ((m_flags1 >> 23) & 1) != (param_2 != 0)) {
        
        m_flags1 = (m_flags1 & ~0xFF) | (reinterpret_cast<uintptr_t>(param_1) & 0xFF);
        m_flags1 = (m_flags1 & ~0x800000) | ((param_2 != 0 ? 1 : 0) << 23);
        
        if ((m_flags1 & 0xFF) != 0 && (m_flags2 & 0xFFF) == 0) {
            m_flags2 = (m_flags2 & 0xFFFFF001) | 1;
        }
        UpdateCorpusCat(nullptr);
    }
}

void CHmsItem::SetDynamicType(CHmsItem* param_1, EDynamicType param_2) {
    if (param_1 != reinterpret_cast<CHmsItem*>((m_flags1 >> 11) & 3)) {
        // Detailed transformation pipeline for changing body types dynamically
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            // Execute virtual teardown for old type
            typedef void (*TypeFunc)(CHmsCorpus*);
            TypeFunc f1 = (TypeFunc)*((void**)((char*)m_corpuses[i] + 0x7C));
            f1(m_corpuses[i]);
        }
        
        m_flags1 = (m_flags1 & ~0x1800) | ((reinterpret_cast<uintptr_t>(param_1) & 3) << 11);
        
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            // Execute virtual setup for new type
            typedef void (*TypeFunc)(CHmsCorpus*);
            TypeFunc f2 = (TypeFunc)*((void**)((char*)m_corpuses[i] + 0x78));
            f2(m_corpuses[i]);
        }
    }
}

void CHmsItem::SetIsBackground(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x200) | ((param_1 != nullptr ? 1 : 0) << 9);
    UpdateCorpusCat(nullptr);
}

void CHmsItem::SetIsCollisionStatic(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x80000) | ((param_1 != nullptr ? 1 : 0) << 19);
}

void CHmsItem::SetIsForcePointDynamicCollisionResponse(CHmsItem* param_1, int param_2) {
    m_flags2 = (m_flags2 & ~0x1000) | ((param_1 != nullptr ? 1 : 0) << 12);
}

void CHmsItem::SetIsKinematicOnly(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x100000) | ((param_1 != nullptr ? 1 : 0) << 20);
}

void CHmsItem::SetIsVisionStatic(CHmsItem* param_1, int param_2) {
    if (((m_flags1 >> 8) & 1) != (param_1 != nullptr)) {
        m_flags1 = (m_flags1 & ~0x100) | ((param_1 != nullptr ? 1 : 0) << 8);
        UpdateCorpusCat(nullptr);
    }
}

void CHmsItem::SetIsZombie(CHmsItem* param_1, int param_2) {
    uint32_t isZombie = (m_flags1 >> 21) & 1;
    if ((isZombie == 0 || param_1 == nullptr) && (isZombie != 0 || param_1 != nullptr) && (m_flags1 & 0x1800) != 0) {
        
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            typedef void (*ZombFunc)(CHmsCorpus*);
            ZombFunc f1 = (ZombFunc)*((void**)((char*)m_corpuses[i] + 0x8C));
            f1(m_corpuses[i]);
        }
        
        m_flags1 = (m_flags1 & ~0x200000) | ((param_2 != 0 ? 1 : 0) << 21);
        
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            typedef void (*ZombFunc)(CHmsCorpus*);
            ZombFunc f2 = (ZombFunc)*((void**)((char*)m_corpuses[i] + 0x90));
            f2(m_corpuses[i]);
        }
    }
}

void CHmsItem::SetLightEmitter(CHmsItem* param_1, int param_2) {
    if ((m_visibleId & 1) != (param_1 != nullptr)) {
        m_visibleId = (m_visibleId & ~1) | (param_1 != nullptr ? 1 : 0);
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            // m_corpuses[i]->CorpusChangeLightEmitter(param_1);
        }
    }
}

void CHmsItem::SetLightLensFlareEnable(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x10000000) | ((param_1 != nullptr ? 1 : 0) << 28);
}

void CHmsItem::SetOccluderForLightMap(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x400000) | ((param_1 != nullptr ? 1 : 0) << 22);
}

void CHmsItem::SetShadowCasterGroupMask(CHmsItem* param_1, uint32_t param_2) {
    m_flags2 = (m_flags2 & ~0xFFF) | (reinterpret_cast<uintptr_t>(param_1) & 0xFFF);
    if ((m_flags1 & 0xFF) != 0 && (m_flags2 & 0xFFF) == 0) {
        m_flags2 = (m_flags2 & 0xFFFFF001) | 1;
    }
}

void CHmsItem::SetShadowFakeEnable(CHmsItem* param_1, int param_2) {
    m_flags1 = (m_flags1 & ~0x8000000) | ((param_1 != nullptr ? 1 : 0) << 27);
}

void CHmsItem::SetShadowReceiverGroupMask(CHmsItem* param_1, uint32_t param_2) {
    m_flags2 = (m_flags2 & 0xFFFFF) | (reinterpret_cast<uintptr_t>(param_1) << 20);
}

// =================================================
// Game State & Prediction
// =================================================
void CHmsItem::AddStateForPrediction(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t param_3, uint32_t param_4) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            dyna->AddStateForPrediction(param_1, param_2, param_3, param_4);
        }
    }
}

int CHmsItem::IsStateDifferentFrom(CHmsItem* param_1, GmIso4* param_2) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            return dyna->IsStateDifferentFrom(param_1, param_2);
        }
    }
    return 0;
}

void CHmsItem::OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5) {
    if (param_2 == nullptr) {
        m_saveStateParam2 = param_3;
    } else {
        m_saveStateParam1 = param_3;
    }
    if (m_corpuses.GetCount() != 0) {
        m_corpuses[0]->OldRestoreStaticState(m_corpuses[0], param_2, param_3, param_4, param_5);
    }
}

void CHmsItem::ResetDynamicState(CHmsItem* param_1) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        m_corpuses[i]->Reset(nullptr);
    }
}

void CHmsItem::RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6) {
    if (param_2 == nullptr) {
        m_saveStateParam2 = param_3;
    } else {
        m_saveStateParam1 = param_3;
    }
    if (m_corpuses.GetCount() != 0) {
        m_corpuses[0]->RestoreStaticState(param_1, param_2, param_3, param_4, param_5, param_6);
    }
}

void CHmsItem::SaveState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, uint32_t* param_3, uint32_t param_4) {
    if (m_corpuses.GetCount() != 0) {
        CHmsDyna* dyna = m_corpuses[0]->m_dyna;
        if (dyna != nullptr) {
            dyna->SaveState(param_1, param_2, param_3, param_4);
        }
    }
}

// =================================================
// Advanced Mesh / Tree Interaction
// =================================================
void CHmsItem::CreateDefaultData(CCrystal* param_1) {
    CPlugSolid* solid = nullptr; // new CPlugSolid(); abstract
    
    // Abstract virtual initialization
    typedef void (*InitFunc)();
    InitFunc f = (InitFunc)*((void**)((char*)solid + 0x4C));
    f();
    
    SetSolid(nullptr, solid);
}

void CHmsItem::CreatePortal(CHmsItem* param_1, CHmsPortal** param_2, CPlugTree* param_3) {
    CHmsPortal* portal = *param_2;
    if (portal == nullptr) {
        portal = nullptr; // new CHmsPortal(); abstract
        *param_2 = portal;
    }
    
    // portal->BindToBuild(...)
    m_portals.Add(portal);
    CMwNod::MwAddRef(reinterpret_cast<CMwNod*>(portal));
    UpdateIsBuild(nullptr);
}

void CHmsItem::RemovePortal(CHmsItem* param_1, CHmsPortal* param_2) {
    int index = -1; // Fallback find
    for (uint32_t i = 0; i < m_portals.GetCount(); ++i) {
        if (m_portals[i] == param_2) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        // m_portals.RemoveAt(index);
    }
    
    // param_2->UnbindFromBuild(...)
    CMwNod::MwRelease(reinterpret_cast<CMwNod*>(param_2));
    UpdateIsBuild(nullptr);
}

void CHmsItem::IsVisibleSet(CHmsItem* param_1, int param_2) {
    if (((m_flags2 >> 15) & 1) != (param_1 != nullptr)) {
        m_flags2 = (m_flags2 & ~0x8000) | ((param_1 != nullptr ? 1 : 0) << 15);
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            typedef void (*VisFunc)();
            VisFunc f = (VisFunc)*((void**)((char*)m_corpuses[i] + 0x80));
            f();
        }
    }
}

void CHmsItem::OnVisible_WakeOrKeepAwake(CHmsItem* param_1) {
    if (m_callbacks != nullptr && m_callbacks->m_callbacks[0] != nullptr) {
        if ((m_flags2 & 0x2000) != 0) {
            m_flags2 = (m_flags2 & ~0x2000) | 0x4000;
            // Virtual callback execution
            typedef void (*CbFunc)(CHmsItem*);
            CbFunc f = (CbFunc)*((void**)((char*)m_callbacks->m_callbacks[0] + 0xC));
            f(this);
        } else {
            m_flags2 |= 0x4000;
        }
    }
}

void CHmsItem::PickDisable(CHmsItem* param_1) {
    if (m_solid != nullptr) {
        CPlugTree* tree = *reinterpret_cast<CPlugTree**>(reinterpret_cast<char*>(m_solid) + 100);
        if (tree != nullptr) {
            tree->m_flags = tree->m_flags & ~0x40; // 0xFFFFFFBF
            
            CPlugTree* child = nullptr;
            while (reinterpret_cast<uintptr_t>(child) != 0xFFFFFFFF) {
                child->m_flags = child->m_flags & ~0x40;
                child = nullptr;
            }
        }
    }
}

void CHmsItem::PickEnableAtLevel(CHmsItem* param_1, uint32_t param_2) {
    if (m_solid != nullptr) {
        CPlugTree* tree = *reinterpret_cast<CPlugTree**>(reinterpret_cast<char*>(m_solid) + 100);
        if (tree != nullptr) {
            tree->m_flags = (tree->m_flags & ~0x40) | ((param_1 == nullptr ? 1 : 0) << 6);
            
            CPlugTree* child = nullptr;
            while (reinterpret_cast<uintptr_t>(child) != 0xFFFFFFFF) {
                uint8_t enable = 0;
                // Tree level comparison logic mapped from assembly
                if (param_1 == reinterpret_cast<CHmsItem*>(child)) enable = 1;
                
                child->m_flags = (child->m_flags & ~0x40) | (enable << 6);
                child = nullptr;
            }
        }
    }
}

void CHmsItem::SetSolid(CSceneToyMotorbike* param_1, CPlugSolid* param_2) {
    if (param_1 != nullptr && reinterpret_cast<uintptr_t>(param_1) != 0x14) { // Null check emulation
        CMwNod::MwAddRef(reinterpret_cast<CMwNod*>(param_1));
        if (m_solid != nullptr) {
            
            CMwNod::MwRelease(reinterpret_cast<CMwNod*>(m_solid));
        }
        m_solid = reinterpret_cast<CPlugSolid*>(param_1);
        
        
        for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
            m_corpuses[i]->RefreshFromSolid(reinterpret_cast<CHmsCorpus*>(param_1));
        }
    }
}

void CHmsItem::UpdateIsBuild(CHmsItem* param_1) {
    for (uint32_t i = 0; i < m_corpuses.GetCount(); ++i) {
        CHmsCorpus* corpus = m_corpuses[i];
        CHmsZone* zone = corpus->m_zone;
        
        // Emulating the nested lookup and change
        int zoneListPtr = *reinterpret_cast<int*>(reinterpret_cast<char*>(zone) + 0x2C);
        uint32_t zoneCount = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(zone) + 0x28);
        
        for (uint32_t j = 0; j < zoneCount; ++j) {
            if (*reinterpret_cast<CHmsZone**>(zoneListPtr + j * 4) == zone) {
                zone->CorpusChangeBuild(zone, corpus, 0);
                break;
            }
        }
    }
}

void CHmsItem::VisibleIdSet(CHmsItem* param_1, SPlugVisibleId* param_2) {
    if (((m_visibleId ^ static_cast<uint16_t>(reinterpret_cast<uintptr_t>(param_1))) & 1) != 0) {
        SetLightEmitter(reinterpret_cast<CHmsItem*>(static_cast<uint16_t>(reinterpret_cast<uintptr_t>(param_1)) & 1), 0);
    }
    m_visibleId = static_cast<uint16_t>(reinterpret_cast<uintptr_t>(param_1));
}

void CHmsItem::CallbackSet(ECallback type, CCallback* callback) {
    const uint32_t index = static_cast<uint32_t>(type);
    if (index >= 6u) return;
    if (callback != nullptr && callback->GetType() != type) return;
    if (m_callbacks == nullptr) {
        if (callback == nullptr) return;
        m_callbacks = new SCallbackList();
    }
    m_callbacks->m_callbacks[index] = callback;
}

float CHmsItem::GetAsyncBlendBetweenPreviousAndNextStates(CHmsItem* param_1) {
    CMwCmdBufferCore* core = *reinterpret_cast<CMwCmdBufferCore**>(DAT_00d731e0 + 0x14);
    if ((m_flags1 & 0x200000) == 0) {
        if (core == nullptr) core = reinterpret_cast<CMwCmdBufferCore*>(DAT_00d731e0 + 0xA0);
        // CMwId id = 0;
        uint32_t u1 = 0; // id.m_id;
        
        uint32_t props = 0;
        uint32_t u2 = 0;
        
        int diff = u1 - (u1 / u2) * u2;
        float f1 = static_cast<float>(diff);
        if (diff < 0) f1 += DAT_00c418d0;
        
        float f2 = static_cast<float>(static_cast<int>(u2));
        if (static_cast<int>(u2) < 0) f2 += DAT_00c418d0;
        
        return f1 / f2;
    }
    
    if (core == nullptr) core = reinterpret_cast<CMwCmdBufferCore*>(DAT_00d731e0 + 0xA0);
    // CMwId id = 0;
    uint32_t u1 = 0; // id.m_id;
    uint32_t u2 = m_saveStateParam2;
    
    if (u2 != 0xFFFFFFFF && u2 != m_saveStateParam1 && m_saveStateParam1 <= u1) {
        float f1 = 1.0f;
        if (u1 <= u2) {
            f1 = static_cast<float>(static_cast<int>(u1 - m_saveStateParam1));
            if (static_cast<int>(u1 - m_saveStateParam1) < 0) f1 += DAT_00c418d0;
            
            float f2 = static_cast<float>(static_cast<int>(u2 - m_saveStateParam1));
            if (static_cast<int>(u2 - m_saveStateParam1) < 0) f2 += DAT_00c418d0;
            
            f1 = 0.0f; // clamp (f1 / f2, 0.0f, 1.0f);
        }
        return f1;
    }
    return 0.0f;
}

// =================================================
// Serialization / Archive "Chunk" Parsing
// =================================================

uint32_t CHmsItem::GetChunkInfo(CFuncSegment* param_1, uint32_t param_2) {
    uint32_t chunkId = reinterpret_cast<uintptr_t>(param_1);
    
    if (chunkId < 0x600300A) {
        if (chunkId != 0x6003009) {
            switch (chunkId) {
                case 0x6003000: case 0x6003002: case 0x6003003: case 0x6003004:
                case 0x6003005: case 0x6003006: case 0x6003007: case 0x6003008:
                    break;
                case 0x6003001: return 3;
                default: return CMwNod::GetChunkInfo(param_1, param_2);
            }
        }
    } else {
        if (chunkId > 0x600300E) {
            if (chunkId < 0x6003012) {
                if (chunkId == 0x6003011) return 3;
                if (chunkId == 0x600300F || chunkId == 0x6003010) return 1;
            } else if (chunkId == 0xFFFFFFFF) {
                return 0xFFFFFFFF;
            }
            return CMwNod::GetChunkInfo(param_1, param_2);
        }
        if (chunkId != 0x600300E) {
            switch (chunkId) {
                case 0x600300A: case 0x600300B: case 0x600300C: case 0x600300D: break;
                default: return CMwNod::GetChunkInfo(param_1, param_2);
            }
        }
    }
    return 1;
}

void CHmsItem::Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3) {
    uint32_t chunkId = reinterpret_cast<uintptr_t>(param_2) & 0xFFFFFFFF;

    if (chunkId > 0x6003009) {
        if (chunkId < 0x600300F) {
            if (chunkId == 0x600300E) {
                m_flags1 &= 0x1FFFFFFF;
                param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                param_2->DoNat16(&m_visibleId, 1);
                m_flags2 |= 0xFFF00000;
                m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x11000000;
                return;
            }
            switch (chunkId) {
                case 0x600300A: {
                    uint32_t dataVal = 0;
                    param_2->DoData(reinterpret_cast<uint8_t*>(&dataVal), 8);
                    m_flags1 = dataVal;
                    uint32_t dt = 0; // Fetched from stack emulation
                    if (dt > 0xB) dt = 0;
                    m_flags2 = (1 << (dt & 0x1F)) & 0xFFF | (m_flags2 & 0x7000) | 0xFFF18000;
                    m_visibleId = static_cast<uint16_t>(dataVal >> 24);
                    m_flags1 = (dataVal & 0xEFFFBEF) | 0x11000000;
                    SetLightEmitter(reinterpret_cast<CHmsItem*>((dataVal >> 10) & 1), 0);
                    return;
                }
                case 0x600300B: {
                    m_flags1 &= 0x1FFFFFFF;
                    param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                    m_flags2 = (m_flags2 & 0x7FFF) | 0xFFF18000;
                    m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x11000000;
                    param_2->DoNat16(&m_visibleId, 1);
                    if ((m_flags2 & 0xFFF) > 0xB) m_flags2 &= 0xFFFFF000;
                    m_flags2 = ((1 << (m_flags2 & 0x1F)) ^ m_flags2) & 0xFFF ^ m_flags2;
                    return;
                }
                case 0x600300C: {
                    m_flags1 &= 0x1FFFFFFF;
                    param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                    m_flags2 = (m_flags2 & 0x7FFF) | 0xFFF18000;
                    m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x11000000;
                    param_2->DoNat16(&m_visibleId, 1);
                    return;
                }
                case 0x600300D: {
                    m_flags1 &= 0x1FFFFFFF;
                    param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                    param_2->DoNat16(&m_visibleId, 1);
                    m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x11000000;
                    m_flags2 = m_flags2 | 0xFFF10000;
                    return;
                }
            }
        } else if (chunkId < 0x6003012) {
            if (chunkId == 0x6003011) {
                m_flags1 &= 0x1FFFFFFF;
                param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                param_2->DoNat16(&m_visibleId, 1);
                return;
            }
            if (chunkId == 0x600300F) {
                m_flags1 &= 0x1FFFFFFF;
                param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                param_2->DoNat16(&m_visibleId, 1);
                m_flags2 |= 0xFFF00000;
                m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x10000000;
                return;
            }
            if (chunkId == 0x6003010) {
                m_flags1 &= 0x1FFFFFFF;
                param_2->DoData(reinterpret_cast<uint8_t*>(&m_flags1), 8);
                param_2->DoNat16(&m_visibleId, 1);
                m_flags1 |= 0x10000000;
                return;
            }
        } else if (chunkId == 0xFFFFFFFF) {
            return;
        }
        CMwNod::Chunk(param_1, param_2, param_3);
        return;
    }

    if (chunkId == 0x6003009) {
        uint32_t dataVal = 0;
        param_2->DoData(reinterpret_cast<uint8_t*>(&dataVal), 4);
        m_flags2 = (param_3 != 0 ? 1 : 0) | (m_flags2 & 0x7000) | 0xFFF18000;
        m_flags1 = (dataVal & 0xFFFFFBEF) | 0x11000000;
        SetLightEmitter(reinterpret_cast<CHmsItem*>((dataVal >> 10) & 1), 0);
        return;
    }

    switch (chunkId) {
        case 0x6003000: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
            param_2->DoBool(&b1, 1);
            SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b2, 1);
            SetContactInterest(reinterpret_cast<CHmsItem*>(b2 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b3, 1);
            SetDynamicType(reinterpret_cast<CHmsItem*>(b4 ? 1 : 0), DT_STATIC);
            m_flags2 |= 0xFFF00000;
            m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x10000000;
            return;
        }
        case 0x6003001: {
            if (m_solid == nullptr) {
                CPlugSolid* solid = nullptr; // new CPlugSolid(); abstract
                SetSolid(nullptr, solid);
            }
            return;
        }
        case 0x6003002: {
            // Sound cleanup
            return;
        }
        case 0x6003003: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
            param_2->DoBool(&b1, 1); SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b2, 1); SetContactInterest(reinterpret_cast<CHmsItem*>(b2 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b3, 1); SetDynamicType(reinterpret_cast<CHmsItem*>(b3 ? 1 : 0), DT_STATIC);
            param_2->DoBool(&b4, 1);
            break;
        }
        case 0x6003004: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0; uint8_t n1 = 0;
            param_2->DoBool(&b1, 1); SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b2, 1); SetContactInterest(reinterpret_cast<CHmsItem*>(b2 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b3, 1); SetDynamicType(reinterpret_cast<CHmsItem*>(b3 ? 1 : 0), DT_STATIC);
            param_2->DoNat8(&n1, 1);
            SetCountShadowTexCasted(reinterpret_cast<CHmsItem*>(static_cast<uintptr_t>(n1)), 1, 0);
            m_flags2 |= 0xFFF00000;
            m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x10000000;
            return;
        }
        case 0x6003005: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0, b4 = 0; uint8_t n1 = 0;
            param_2->DoBool(&b1, 1); param_2->DoBool(&b2, 1);
            m_flags1 ^= ((b2 != 0 ? 1 : 0) << 9 ^ m_flags1) & 0x200;
            SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b3, 1); SetContactInterest(reinterpret_cast<CHmsItem*>(b3 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b4, 1); SetDynamicType(reinterpret_cast<CHmsItem*>(b4 ? 1 : 0), DT_STATIC);
            param_2->DoNat8(&n1, 1);
            SetCountShadowTexCasted(reinterpret_cast<CHmsItem*>(static_cast<uintptr_t>(n1)), 1, 0);
            m_flags2 |= 0xFFF00000;
            m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x10000000;
            return;
        }
        case 0x6003006: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0; uint8_t n1 = 0;
            param_2->DoBool(&b1, 1); param_2->DoBool(&b2, 1); param_2->DoBool(&b3, 1);
            m_flags1 ^= ((b3 != 0 ? 1 : 0) << 9 ^ m_flags1) & 0x200;
            SetLightEmitter(reinterpret_cast<CHmsItem*>(b2 ? 1 : 0), 0);
            SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b4, 1); SetContactInterest(reinterpret_cast<CHmsItem*>(b4 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b5, 1); SetDynamicType(reinterpret_cast<CHmsItem*>(b5 ? 1 : 0), DT_STATIC);
            param_2->DoNat8(&n1, 1);
            break;
        }
        case 0x6003007: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            int b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0; uint8_t n1 = 0;
            param_2->DoBool(&b1, 1); param_2->DoBool(&b2, 1); param_2->DoBool(&b3, 1);
            m_flags2 |= 0xFFF00000;
            m_flags1 = ((b3 != 0 ? 1 : 0 | 0x80000) << 9) | (m_flags1 & 0xFFFFFDFF);
            SetLightEmitter(reinterpret_cast<CHmsItem*>(b2 ? 1 : 0), 0);
            SetCollisionGroup(reinterpret_cast<CHmsItem*>(b1 ? 4 : 0), CG_DEFAULT);
            param_2->DoBool(&b4, 1); SetContactInterest(reinterpret_cast<CHmsItem*>(b4 ? 2 : 0), CI_NONE);
            param_2->DoBool(&b5, 1); SetDynamicType(reinterpret_cast<CHmsItem*>(b5 ? 1 : 0), DT_STATIC);
            param_2->DoNat8(&n1, 1);
            SetCountShadowTexCasted(reinterpret_cast<CHmsItem*>(static_cast<uintptr_t>(n1)), 1, 0);
            return;
        }
        case 0x6003008: {
            uint32_t nat1 = 0; param_2->DoNatural(&nat1, 1);
            uint32_t data = 0; param_2->DoData(reinterpret_cast<uint8_t*>(&data), 4);
            m_flags2 |= 0xFFF00000;
            m_flags1 = (m_flags1 & 0xFFF600FF) | (data & 0x100) | ((data & 0x100) << 11) | (data & 0x200) | ((data & 0x800 | 0x1100000) << 4);
            int b1 = 0; param_2->DoBool(&b1, 1);
            SetLightEmitter(reinterpret_cast<CHmsItem*>((b1 >> 10) & 1), 0);
            SetContactInterest(reinterpret_cast<CHmsItem*>(b1 ? 2 : 0), CI_NONE);
            m_visibleId = 0;
            return;
        }
    }
    
    SetCountShadowTexCasted(reinterpret_cast<CHmsItem*>(1), 1, 0);
    m_flags2 |= 0xFFF00000;
    m_flags1 = (m_flags1 & 0xFFFFFBEF) | 0x10000000;
}

// =================================================
// Virtual Param Set / Get (Bitwise Unpacking)
// =================================================
uint32_t CHmsItem::VirtualParam_Get(CPlugBlendShapes* param_1, CMwStack* param_2, CMwValueStd* param_3) {
    int iVar2 = param_1->m_refCount; // Placeholder for stack count extraction
    uint32_t uVar4 = param_2->m_capacity; // Prop ID placeholder
    
    if (uVar4 < 0x600301D) {
        if (uVar4 == 0x600301C) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 28) & 1;
            return 0;
        }
        switch (uVar4) {
            case 0x6003003: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 13) & 0xF; return 0;
            case 0x6003004: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 11) & 0x3; return 0;
            case 0x6003005: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 17) & 0x3; return 0;
            case 0x6003006: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 20) & 0x1; return 0;
            case 0x6003007: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 8) & 0x1; return 0;
            case 0x6003008: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 19) & 0x1; return 0;
            case 0x6003009: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 9) & 0x1; return 0;
            case 0x600300A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 25) & 0x1; return 0;
            case 0x600300B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 26) & 0x1; return 0;
            case 0x600300C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 10) & 0x1; return 0;
            case 0x600300D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 22) & 0x1; return 0;
            case 0x600300E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 12) & 0x1; return 0;
            case 0x600300F: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = static_cast<uint8_t>(m_flags1); return 0;
            case 0x6003010: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 23) & 0x1; return 0;
            case 0x6003011: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 27) & 0x1; return 0;
            case 0x6003012: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_flags2 & 0x1; return 0;
            case 0x6003013: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_flags2 & 0x2; return 0;
            case 0x6003014: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_flags2 & 0x4; return 0;
            case 0x6003015: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_flags2 & 0x8; return 0;
            case 0x6003016: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 20) & 0x1; return 0;
            case 0x6003017: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 20) & 0x2; return 0;
            case 0x6003018: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 20) & 0x4; return 0;
            case 0x6003019: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 20) & 0x8; return 0;
            case 0x600301B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags1 >> 24) & 0x1; return 0;
        }
    } else if (uVar4 < 0x6003029) {
        if (uVar4 == 0x6003028) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 7) & 0x1;
            return 0;
        }
        switch (uVar4) {
            case 0x600301D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 16) & 0x1; return 0;
            case 0x600301E: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 17) & 0x1; return 0;
            case 0x600301F: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 18) & 0x1; return 0;
            case 0x6003020: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 19) & 0x1; return 0;
            case 0x6003021: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = m_visibleId & 0x1; return 0;
            case 0x6003022: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 1) & 0x1; return 0;
            case 0x6003023: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 2) & 0x1; return 0;
            case 0x6003024: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 3) & 0x1; return 0;
            case 0x6003025: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 4) & 0x1; return 0;
            case 0x6003026: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 5) & 0x1; return 0;
            case 0x6003027: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 6) & 0x1; return 0;
        }
    } else if (uVar4 < 0x600302F) {
        if (uVar4 == 0x600302E) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 13) & 0x1;
            return 0;
        }
        switch (uVar4) {
            case 0x6003029: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 8) & 0x1; return 0;
            case 0x600302A: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 9) & 0x1; return 0;
            case 0x600302B: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 10) & 0x1; return 0;
            case 0x600302C: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 11) & 0x1; return 0;
            case 0x600302D: *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 12) & 0x1; return 0;
        }
    } else {
        if (uVar4 > 0x6003032) {
            if (uVar4 == 0x6003033) {
                // Vector fetching logic for speed
                return 0;
            }
            if (uVar4 != 0xFFFFFFFF) {
                return CMwNod::VirtualParam_Get(param_2, param_3);
            }
            return 0;
        }
        if (uVar4 == 0x6003032) {
            return 0;
        }
        if (uVar4 == 0x600302F) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_visibleId >> 14) & 0x1;
            return 0;
        }
        if (uVar4 == 0x6003030) {
            *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(param_2) + 4) = (m_flags2 >> 15) & 0x1;
            return 0;
        }
    }
    return CMwNod::VirtualParam_Get(param_2, param_3);
}

uint32_t CHmsItem::VirtualParam_Set(CSystemData* param_1, CMwStack* param_2, void* param_3) {
    uint32_t uVar6 = param_2->m_capacity; // Prop ID placeholder
    int val = 0; // Stack fetch emulation
    
    if (uVar6 < 0x6003021) {
        if (uVar6 > 0x600301C) {
            m_flags2 = (m_flags2 & ~(1 << ((uVar6 - 0x1D) & 0x1F))) | ((val ? 1 : 0) << ((uVar6 - 0x1D) & 0x1F));
            return 0;
        }
        switch (uVar6) {
            case 0x6003000: SetSolid(reinterpret_cast<CSceneToyMotorbike*>(val), nullptr); return 0;
            case 0x6003003: SetCollisionGroup(reinterpret_cast<CHmsItem*>(val), CG_DEFAULT); return 0;
            case 0x6003004: SetDynamicType(reinterpret_cast<CHmsItem*>(val), DT_STATIC); return 0;
            case 0x6003005: SetContactInterest(reinterpret_cast<CHmsItem*>(val), CI_NONE); return 0;
            case 0x6003006: SetIsKinematicOnly(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x6003007: SetIsVisionStatic(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x6003008: SetIsCollisionStatic(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x6003009: SetIsBackground(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x600300A: m_flags1 = (m_flags1 & ~(1 << 25)) | ((val ? 1 : 0) << 25); return 0;
            case 0x600300B: m_flags1 = (m_flags1 & ~(1 << 26)) | ((val ? 1 : 0) << 26); return 0;
            case 0x600300C: m_flags1 = (m_flags1 & ~(1 << 10)) | ((val ? 1 : 0) << 10); return 0;
            case 0x600300D: SetOccluderForLightMap(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x600300E: SetIsForcePointDynamicCollisionResponse(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x600300F: SetCountShadowTexCasted(reinterpret_cast<CHmsItem*>(val), (m_flags1 >> 23) & 1, 0); return 0;
            case 0x6003010: m_flags1 = (m_flags1 & ~(1 << 23)) | ((val ? 1 : 0) << 23); return 0;
            case 0x6003011: SetShadowFakeEnable(reinterpret_cast<CHmsItem*>(val), 0); return 0;
            case 0x6003012: case 0x6003013: case 0x6003014: case 0x6003015:
                m_flags2 = (m_flags2 & ~(1 << ((uVar6 - 0x12) & 0x1F))) | ((val ? 1 : 0) << ((uVar6 - 0x12) & 0x1F));
                if (m_flags1 == 0) return 0;
                if ((m_flags2 & 0xFFF) != 0) return 0;
                m_flags2 = (m_flags2 & 0xFFFFF001) | 1;
                return 0;
            case 0x6003016: case 0x6003017: case 0x6003018: case 0x6003019:
                m_flags2 = (m_flags2 & ~(1 << ((uVar6 - 0x16) & 0x1F)) << 20) | (((val ? 1 : 0) << ((uVar6 - 0x16) & 0x1F)) << 20);
                return 0;
            case 0x600301B: m_flags1 = (m_flags1 & ~(1 << 24)) | ((val ? 1 : 0) << 24); return 0;
            case 0x600301C: SetLightLensFlareEnable(reinterpret_cast<CHmsItem*>(val), 0); return 0;
        }
    } else if (uVar6 < 0x600302C) {
        if (uVar6 == 0x600302B) {
            uint16_t uVar10 = ((val ? 1 : 0) << 10) ^ m_visibleId;
            VisibleIdSet(reinterpret_cast<CHmsItem*>(uVar10), nullptr);
            return 0;
        }
        uint16_t uVar10 = 0;
        switch (uVar6) {
            case 0x6003021: uVar10 = (val ? 1 : 0) ^ m_visibleId; break;
            case 0x6003022: uVar10 = ((val ? 1 : 0) << 1) ^ m_visibleId; break;
            case 0x6003023: uVar10 = ((val ? 1 : 0) << 2) ^ m_visibleId; break;
            case 0x6003024: uVar10 = ((val ? 1 : 0) << 3) ^ m_visibleId; break;
            case 0x6003025: uVar10 = ((val ? 1 : 0) << 4) ^ m_visibleId; break;
            case 0x6003026: uVar10 = ((val ? 1 : 0) << 5) ^ m_visibleId; break;
            case 0x6003027: uVar10 = ((val ? 1 : 0) << 6) ^ m_visibleId; break;
            case 0x6003028: uVar10 = ((val ? 1 : 0) << 7) ^ m_visibleId; break;
            case 0x6003029: 
                uVar10 = ((val ? 1 : 0) << 8) ^ m_visibleId; 
                VisibleIdSet(reinterpret_cast<CHmsItem*>(uVar10), nullptr); 
                return 0;
            case 0x600302A: 
                uVar10 = ((val ? 1 : 0) << 9) ^ m_visibleId; 
                VisibleIdSet(reinterpret_cast<CHmsItem*>(uVar10), nullptr); 
                return 0;
            default: return CMwNod::VirtualParam_Set(param_2, param_3);
        }
        VisibleIdSet(reinterpret_cast<CHmsItem*>(uVar10), nullptr);
        return 0;
    } else if (uVar6 < 0x6003031) {
        if (uVar6 == 0x6003030) {
            IsVisibleSet(reinterpret_cast<CHmsItem*>(val), 0);
            return 0;
        }
        uint16_t uVar10 = 0;
        switch (uVar6) {
            case 0x600302C: uVar10 = ((val ? 1 : 0) << 11) ^ m_visibleId; break;
            case 0x600302D: uVar10 = ((val ? 1 : 0) << 12) ^ m_visibleId; break;
            case 0x600302E: uVar10 = ((val ? 1 : 0) << 13) ^ m_visibleId; break;
            case 0x600302F: uVar10 = ((val ? 1 : 0) << 14) ^ m_visibleId; break;
        }
        VisibleIdSet(reinterpret_cast<CHmsItem*>(uVar10), nullptr);
        return 0;
    } else if (uVar6 < 0x6003034) {
        if (uVar6 == 0x6003033) {
            SetLinearSpeed(reinterpret_cast<CHmsItem*>(val), nullptr);
            return 0;
        }
        if (uVar6 == 0x6003031) {
            AddImpulse(reinterpret_cast<CHmsItem*>(val), nullptr);
            return 0;
        }
        if (uVar6 == 0x6003032) {
            SetAngularSpeed(reinterpret_cast<CHmsItem*>(val), nullptr);
            return 0;
        }
    } else if (uVar6 == 0xFFFFFFFF) {
        return 0;
    }
    
    return CMwNod::VirtualParam_Set(param_2, param_3);
}
