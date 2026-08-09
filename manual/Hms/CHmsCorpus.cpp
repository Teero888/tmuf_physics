#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsItem.hpp"
#include "CPlugTree.hpp"
#include "CPlugSolid.hpp"
#include "CPlugSurface.hpp"
#include "CPlugSurfaceGeom.hpp"
#include "CPlugShader.hpp"
#include "CPlugBitmapRender.hpp"
#include "CMwClassInfo.hpp"
#include "CSystemCrashDump.hpp"
#include "CFastString.hpp"
#include "CClassicBufferMemory.hpp"
#include "CRpcCallInternal.hpp"
#include <algorithm>
#include <cmath>
#include <mutex>
#include <unordered_map>
#include <vector>

// Engine Globals
extern CMwClassInfo DAT_00d6764c;
extern CSystemCrashDump DAT_00d5546c;
extern float DAT_00b56ec0;

namespace {

struct SCorpusTokenRegistry {
    std::mutex mutex;
    std::unordered_map<uint32_t, std::vector<CHmsCorpus*>> corpuses;
};

SCorpusTokenRegistry& CorpusTokenRegistry() {
    // Deliberately retain the registry until process exit so corpus teardown
    // during static destruction never observes a destroyed registry.
    static SCorpusTokenRegistry* registry = new SCorpusTokenRegistry();
    return *registry;
}

void RegisterCorpus(CHmsCorpus* corpus) {
    SCorpusTokenRegistry& registry = CorpusTokenRegistry();
    std::lock_guard<std::mutex> lock(registry.mutex);
    std::vector<CHmsCorpus*>& matches =
        registry.corpuses[CHmsCorpus::PointerToken(corpus)];
    if (std::find(matches.begin(), matches.end(), corpus) == matches.end()) {
        matches.push_back(corpus);
    }
}

void UnregisterCorpus(CHmsCorpus* corpus) {
    SCorpusTokenRegistry& registry = CorpusTokenRegistry();
    std::lock_guard<std::mutex> lock(registry.mutex);
    const uint32_t token = CHmsCorpus::PointerToken(corpus);
    auto bucket = registry.corpuses.find(token);
    if (bucket == registry.corpuses.end()) return;

    std::vector<CHmsCorpus*>& matches = bucket->second;
    matches.erase(std::remove(matches.begin(), matches.end(), corpus),
                  matches.end());
    if (matches.empty()) registry.corpuses.erase(bucket);
}

void CollectCollisionSurfaces(
    CHmsCorpus& corpus,
    CPlugTree* tree,
    const GmIso4& parentToWorld) {
    if (tree == nullptr || !tree->IsCollisionEnabled()) return;

    GmIso4 nodeToWorld = parentToWorld;
    if (tree->UsesLocation()) {
        nodeToWorld.SetMult(tree->m_location, parentToWorld);
    }

    if (tree->m_surface != nullptr &&
        tree->m_surface->m_geometry != nullptr &&
        tree->m_surface->m_geometry->GetGmSurf() != nullptr) {
        corpus.AddCollisionSurface(tree->m_surface, nodeToWorld);
    }

    for (uint32_t index = 0; index < tree->GetChildCount(); ++index) {
        CollectCollisionSurfaces(
            corpus, tree->GetChild(index), nodeToWorld);
    }
}

} // namespace

// Sub-Structures Mocks
CHmsZoneElem::CHmsZoneElem() : CMwNod() { m_zone = nullptr; }
CHmsZoneElem::~CHmsZoneElem() {}

// =================================================
// Constructor & Destructor
// =================================================
CHmsCorpus::CHmsCorpus() : CHmsZoneElem() {
    m_location.SetIdentity();
    m_item = nullptr;
    m_ptr50 = 0;
    m_dyna = nullptr;
    m_ptr4C = nullptr;
    m_flags54 = 0xFFFFFFFF;
    RegisterCorpus(this);
}

CHmsCorpus::~CHmsCorpus() {
    UnregisterCorpus(this);

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

uint32_t CHmsCorpus::PointerToken(const CHmsCorpus* corpus) {
    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(corpus));
}

CHmsCorpus* CHmsCorpus::ResolvePointerToken(uint32_t token) {
    if (token == 0u) return nullptr;

    SCorpusTokenRegistry& registry = CorpusTokenRegistry();
    std::lock_guard<std::mutex> lock(registry.mutex);
    const auto bucket = registry.corpuses.find(token);
    if (bucket == registry.corpuses.end() || bucket->second.size() != 1u) {
        return nullptr;
    }
    return bucket->second.front();
}

const GmMat3& CHmsCorpus::CurrentRotation() const {
    return m_dyna != nullptr
        ? m_dyna->CurrentState().m_rotationMatrix
        : m_location.rot;
}

void CHmsCorpus::AddCollisionSurface(
    GmSurf* surface, const GmIso4& location) {
    if (surface == nullptr) return;
    SCollisionSurface located{};
    located.m_gmSurface.m_surf = surface;
    located.m_gmSurface.m_location = location;
    located.m_plugSurface = nullptr;
    m_collisionSurfaces.Add(located);
}

void CHmsCorpus::AddCollisionSurface(
    CPlugSurface* surface, const GmIso4& location) {
    if (surface == nullptr || surface->m_geometry == nullptr) return;
    GmSurf* gmSurface = surface->m_geometry->GetGmSurf();
    if (gmSurface == nullptr) return;
    SCollisionSurface located{};
    located.m_gmSurface.m_surf = gmSurface;
    located.m_gmSurface.m_location = location;
    located.m_plugSurface = surface;
    m_collisionSurfaces.Add(located);
}

void CHmsCorpus::ClearCollisionSurfaces() {
    m_collisionSurfaces.m_count = 0;
}

bool CHmsCorpus::RefreshCollisionSurfacesFromTree(CPlugTree* root) {
    if (root == nullptr) return false;
    ClearCollisionSurfaces();
    GmIso4 corpusToWorld = m_location;
    if (m_dyna != nullptr) {
        corpusToWorld.rot = m_dyna->CurrentState().m_rotationMatrix;
        corpusToWorld.SetTranslation(
            m_dyna->CurrentState().m_position);
    }
    CollectCollisionSurfaces(*this, root, corpusToWorld);
    return true;
}

bool CHmsCorpus::RefreshCollisionSurfacesFromSolid() {
    if (m_item == nullptr || m_item->m_solid == nullptr ||
        m_item->m_solid->m_tree == nullptr) {
        return false;
    }
    return RefreshCollisionSurfacesFromTree(m_item->m_solid->m_tree);
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
    if (param_2 != nullptr) *param_2 = m_location;
}

void CHmsCorpus::SetLocation(const GmIso4& location) {
    m_location = location;
    if (m_dyna != nullptr) {
        m_dyna->SetLocation(nullptr, &m_location);
    }
}

void CHmsCorpus::SetLocation(CPlugTree* param_1, GmIso4* param_2) {
    const GmIso4* location = param_2 != nullptr
        ? param_2
        : reinterpret_cast<const GmIso4*>(param_1);
    if (location != nullptr) SetLocation(*location);
}

void CHmsCorpus::SetTranslation(const GmVec3& translation) {
    m_location.SetTranslation(translation);
    if (m_dyna != nullptr) {
        GmVec3 value = translation;
        m_dyna->SetTranslation(nullptr, &value);
    }
}

void CHmsCorpus::SetTranslation(GmIso4* param_1, GmVec3* param_2) {
    const GmVec3* translation = param_2 != nullptr
        ? param_2
        : reinterpret_cast<const GmVec3*>(param_1);
    if (translation != nullptr) SetTranslation(*translation);
}

void CHmsCorpus::SetItem(CHmsCorpus* param_1, CHmsItem* param_2) {
    if (m_dyna != nullptr) {
        delete m_dyna;
    }
    
    m_item = param_2 != nullptr
        ? param_2
        : reinterpret_cast<CHmsItem*>(param_1);
    m_dyna = nullptr;
    if (m_item == nullptr) return;
    
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
    
    const GmMat3* rotation = param_2 != nullptr
        ? param_2
        : reinterpret_cast<const GmMat3*>(param_1);
    if (rotation == nullptr) return;
    GmIso4 rotated = m_location;
    rotated.rot.SetMult(*rotation, m_location.rot);
    rotated.rot.OrthoNormalize();
    SetLocation(rotated);
}

void CHmsCorpus::ComputeCurrentState(CHmsCorpus* param_1, float param_2) {
    if (m_dyna == nullptr) return;
    GmIso4 validatedLocation;
    validatedLocation.rot = m_dyna->ValidatedState().m_rotationMatrix;
    validatedLocation.SetTranslation(
        m_dyna->ValidatedState().m_position);
    GmIso4 currentLocation;
    currentLocation.rot = m_dyna->CurrentState().m_rotationMatrix;
    currentLocation.SetTranslation(m_dyna->CurrentState().m_position);
    m_location.SetBlend(validatedLocation, currentLocation, param_2);
}

// =================================================
// Dynamic State Saving & Rendering Integration
// =================================================
void CHmsCorpus::RefreshFromSolid(CHmsCorpus* param_1) {
    if (m_dyna != nullptr && m_item != nullptr &&
        m_item->m_solid != nullptr) {
        // Native points at CPlugSolid's embedded CPlugPhysicalObject (+0x18).
        m_dyna->m_field_0x108 = &m_item->m_solid->m_physicalObject;
        m_dyna->UpdateWorldInverseInertia();
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
                    reinterpret_cast<CPlugTree*>(treePtr)
                        ->GetThisToRootTransfo(transfo);
                    
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
