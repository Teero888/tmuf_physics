#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CPlugTree.hpp"
#include "CPlugShader.hpp"
#include "CPlugBitmapRender.hpp"
#include "CMwClassInfo.hpp"
#include "CSystemCrashDump.hpp"
#include "CFastString.hpp"
#include "CClassicBufferMemory.hpp"
#include "CRpcCallInternal.hpp"

// Engine Globals
extern CMwClassInfo DAT_00d6764c;
extern CSystemCrashDump DAT_00d5546c;
extern float DAT_00b56ec0;

// Sub-Structures Mocks
CHmsZoneElem::CHmsZoneElem() : CMwNod() { m_zone = nullptr; }
CHmsZoneElem::~CHmsZoneElem() {}

// =================================================
// Constructor & Destructor
// =================================================
CHmsCorpus::CHmsCorpus() : CHmsZoneElem() {
    m_item = nullptr;
    m_ptr50 = 0;
    m_dyna = nullptr;
    m_ptr4C = nullptr;
    m_flags54 = 0xFFFFFFFF;
}

CHmsCorpus::~CHmsCorpus() {
    if (m_ptr4C != nullptr) {
        // Internal rendering buffers cleanup mocked from offset 0x0C
        typedef void (*BufDel)(void*);
        BufDel d1 = (BufDel)*((void**)(*reinterpret_cast<char**>(m_ptr4C) + 0x0C));
        if (d1) d1(reinterpret_cast<char*>(m_ptr4C) + 0x0C);
        
        BufDel d2 = (BufDel)*((void**)(*reinterpret_cast<char**>(m_ptr4C) + 0x00));
        if (d2) d2(m_ptr4C);
        
        delete[] reinterpret_cast<char*>(m_ptr4C);
        m_ptr4C = nullptr;
    }
    
    if (m_dyna != nullptr) {
        delete m_dyna;
        m_dyna = nullptr;
    }
}

void CHmsCorpus::AddCollisionSurface(
    GmSurf* surface, const GmIso4& location) {
    if (surface == nullptr) return;
    LocatedGmSurf located{};
    located.m_surf = surface;
    located.m_location = location;
    m_collisionSurfaces.Add(located);
}

void CHmsCorpus::ClearCollisionSurfaces() {
    m_collisionSurfaces.m_count = 0;
}

void* CHmsCorpus::_vector_deleting_destructor_(CRpcCallInternal* param_1, uint32_t param_2) {
    this->~CHmsCorpus();
    if ((param_2 & 1) != 0) {
        delete this;
    }
    return this;
}

// =================================================
// Static Initialization & Factories
// =================================================
CMwNod* CHmsCorpus::MwNewCHmsCorpus() {
    return new CHmsCorpus();
}

CMwClassInfo* CHmsCorpus::MwGetClassInfo(CFuncSegment* param_1) {
    return &DAT_00d6764c;
}

uint32_t CHmsCorpus::GetMwClassId(CControlStyle* param_1) {
    return 0x6002000;
}

int CHmsCorpus::MwIsKindOf(CMwCmdAffectParam* param_1, uint32_t param_2) {
    uintptr_t id = reinterpret_cast<uintptr_t>(param_1);
    if (id != 0x6002000 && id != 0x6008000) {
        return (id == 0x1001000) ? 1 : 0;
    }
    return 1;
}

// =================================================
// Error Handling
// =================================================
int CHmsCorpus::OnCrashDump(CMwNod* param_1, CFastString* param_2) {
    int res = CMwNod::OnCrashDump(param_1, param_2);
    if (res == 0) return 0;
    
    typedef void (*DumpFunc)();
    DumpFunc d1 = (DumpFunc)*((void**)((char*)&DAT_00d5546c + 0x14));
    d1();
    
    // Abstracted virtual string retrieval (offset +0x78 mapped to Location/Iso getter)
    typedef void* (*GetTrans)();
    GetTrans f = (GetTrans)*((void**)((char*)this + 0x78));
    uintptr_t locObj = reinterpret_cast<uintptr_t>(f());
    
    CFastString* str = reinterpret_cast<CFastString*>(reinterpret_cast<GetTrans>(*reinterpret_cast<void**>(reinterpret_cast<char*>(&DAT_00d5546c) + 0x1C))());
    str->SetString("Translation=");
    
    // Append vec3
    DAT_00d5546c.StringCatVec3(param_1, reinterpret_cast<CFastString*>(locObj + 0x24));
    
    if (m_item != nullptr) {
        int valid = DAT_00d5546c.IsValid_DumpFidAndMwId(param_1, "HmsItem", reinterpret_cast<const char*>(m_item), reinterpret_cast<CMwNod*>(1));
        if (valid != 0) {
            DumpFunc d2 = (DumpFunc)*((void**)((char*)m_item + 0x58));
            d2();
        }
    }
    
    DumpFunc d3 = (DumpFunc)*((void**)((char*)&DAT_00d5546c + 0x18));
    d3();
    return 1;
}

// =================================================
// Physics & Dynamics Forwarding
// =================================================
void CHmsCorpus::GetLocation(GmLocFreeVal* param_1, GmIso4* param_2) {
    if (m_dyna == nullptr) {
        return;
    }
    // Abstract virtual forwarding
}

void CHmsCorpus::SetLocation(CPlugTree* param_1, GmIso4* param_2) {
    // Array copy of the 12 words (48 bytes / GmIso4)
    uint32_t* dest = reinterpret_cast<uint32_t*>(&m_zone); // Start at 0x14
    uint32_t* src = reinterpret_cast<uint32_t*>(param_1);
    
    for (int i = 0; i < 12; ++i) {
        *dest = *src;
        dest++;
        src++;
    }
    
    if (m_dyna != nullptr) {
        m_dyna->SetLocation(param_1, param_2);
    }
}

void CHmsCorpus::SetTranslation(GmIso4* param_1, GmVec3* param_2) {
    uint32_t* src = reinterpret_cast<uint32_t*>(param_1);
    uint32_t* dest = reinterpret_cast<uint32_t*>(&m_translation);
    
    dest[0] = src[0];
    dest[1] = src[1];
    dest[2] = src[2];
    
    if (m_dyna != nullptr) {
        m_dyna->SetTranslation(param_1, param_2);
    }
}

void CHmsCorpus::SetItem(CHmsCorpus* param_1, CHmsItem* param_2) {
    if (m_dyna != nullptr) {
        delete m_dyna;
    }
    
    m_item = reinterpret_cast<CHmsItem*>(param_1);
    m_dyna = nullptr;
    
    // Check if the item is dynamic (flags1 >> 11 & 3)
    uint32_t dynamicType = (m_item->m_flags1 >> 11) & 3;
    if (dynamicType != 0) {
        m_dyna = new CHmsDyna();
        m_dyna->SetDynamicType(reinterpret_cast<CHmsItem*>(dynamicType - 1), static_cast<EDynamicType>(0));
    }
    RefreshFromSolid(nullptr);
}

void CHmsCorpus::RotateOf(CHmsCorpus* param_1, GmMat3* param_2) {
    if (m_dyna != nullptr) {
        m_dyna->RotateOf(param_1, param_2);
        return;
    }
    
    GmMat3 localMat;
    localMat.Set(GmQuat());
    
    // Virtual getter for Iso3
    typedef GmIso3* (*LocFunc)(CHmsCorpus*);
    LocFunc f = (LocFunc)*((void**)((char*)this + 0x78));
    GmIso3* pIso1 = f(this);
    
    // Abstracting matrix and iso math
    GmMat3 matTemp;
    GmMat3::Mult(&matTemp, pIso1);
    
    GmIso4 ortho;
    matTemp.OrthoNormalize(); // TODO
    
    SetLocation(nullptr, &ortho);
}

void CHmsCorpus::ComputeCurrentState(CHmsCorpus* param_1, float param_2) {
    if (m_dyna != nullptr) {
        GmIso4 blendOut;
        GmIso4::SetBlend(&blendOut, nullptr, nullptr, nullptr, 0.0f);
            
        // Copy blended state back
        uint32_t* dest = reinterpret_cast<uint32_t*>(&m_zone); // Start at 0x14
        uint32_t* src = reinterpret_cast<uint32_t*>(&blendOut);
        for (int i = 0; i < 12; ++i) {
            *dest = *src;
            dest++;
            src++;
        }
    }
}

// =================================================
// Dynamic State Saving & Rendering Integration
// =================================================
void CHmsCorpus::RefreshFromSolid(CHmsCorpus* param_1) {
    if (m_dyna != nullptr) {
        // Re-align internal physical buffer if solid bounds changed
        uintptr_t itemPtr = reinterpret_cast<uintptr_t>(m_item);
        uintptr_t solidPtr = *reinterpret_cast<uintptr_t*>(itemPtr + 0x14);
        *reinterpret_cast<uintptr_t*>(reinterpret_cast<char*>(m_dyna) + 0x108) = solidPtr + 0x18;
    }
}

void CHmsCorpus::Reset(GmFrustumIso4* param_1) {
    if (m_dyna != nullptr) {
        m_dyna->Reset(param_1);
    }
}

void CHmsCorpus::OldRestoreStaticState(CHmsCorpus* param_1, CClassicBufferMemory* param_2, int param_3, uint8_t param_4, int param_5) {
    if (m_dyna != nullptr) {
        m_dyna->OldRestoreStaticState(param_1, param_2, param_3, param_4, param_5);
    }
}

void CHmsCorpus::RestoreStaticState(CSceneToyBoat* param_1, CClassicBufferMemory* param_2, int param_3, uint32_t param_4, uint32_t param_5, int param_6) {
    if (m_dyna != nullptr) {
        m_dyna->RestoreStaticState(param_1, param_2, param_3, param_4, param_5, param_6);
    }
}

// =================================================
// Advanced Interaction (Water Planes)
// =================================================
int CHmsCorpus::WaterGetPlaneEqInZone(CHmsCorpus* param_1, GmVec4* param_2) {
    if (m_item != nullptr && *reinterpret_cast<uintptr_t*>(reinterpret_cast<char*>(m_item) + 0x14) != 0) {
        // CIteratorShader parsing block
        uintptr_t treePtr = *reinterpret_cast<uintptr_t*>(*reinterpret_cast<uintptr_t*>(reinterpret_cast<char*>(m_item) + 0x14) + 100);
        
        // Abstract Iterator
        int hasNext = 1; 
        while (hasNext != 0) {
            // Virtual mock for GetNextShader
            CPlugShader* shader = nullptr; 
            
            if (shader != nullptr && (reinterpret_cast<uint32_t*>(shader)[8] & 0xC00000) == 0x800000) {
                CPlugBitmapRender* render = CPlugShader::FindBitmapRenderByClassId(shader, reinterpret_cast<CPlugShader*>(0x9087000), 0, nullptr, nullptr);
                
                if (render != nullptr) {
                    GmIso4 transfo;
                    CPlugTree::GetThisToRootTransfo(&transfo, nullptr, reinterpret_cast<GmIso4*>(1), 0, reinterpret_cast<CPlugTree*>(treePtr));
                    
                    typedef GmIso3* (*LocFunc)(CHmsCorpus*);
                    LocFunc f = (LocFunc)*((void**)((char*)this + 0x78));
                    GmIso3* pIso = f(this);
                    
                    GmIso4 multIso;
                    GmIso4::Mult(&multIso, pIso);
                    
                    // Specific float mapped from assembly
                    float local_44 = *reinterpret_cast<float*>(*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(shader) + 0x90) + 0x38);
                    
                    GmVec4 planeVec;
                    planeVec.x = 0.0f;
                    planeVec.y = 1.0f;
                    planeVec.z = 0.0f;
                    planeVec.w = (DAT_00b56ec0 * 0.0f - local_44) - 0.0f;
                    
                    // GmVec4::PlaneEqMult(reinterpret_cast<GmVec4*>(&planeVec), param_2, &transfo);
                    return 1;
                }
            }
            hasNext = 0; // Break loop
        }
    }
    return 0;
}
