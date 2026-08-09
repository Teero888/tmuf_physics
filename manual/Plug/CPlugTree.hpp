#ifndef CPLUGTREE_HPP
#define CPLUGTREE_HPP

#include "CMwNod.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmMat3.hpp"
#include "GmBoxAligned.hpp"
#include "CFastBuffer.hpp"
#include <cstdint>

class CPlugSolid;
class CPlugVisual;
class CPlugSurface;
class CPlugMaterial;
class CPlugShader;
class CClassicArchive;
class CFuncSegment;
class CMwId;
class CControlStyle;
class CMwCmdExpIso4Ident;
class CPlugBlendShapes;
class CSystemData;
class CMwStack;
class CMwValueStd;
class CRpcCallInternal;
struct CPfmHeap;
struct GmBoxAligned;

class CPlugTree : public CMwNod {
public:
    struct CIteratorTree {
        virtual ~CIteratorTree();
        uint8_t m_padding[8];
        CPlugTree* m_current; // 0x0C
        CPlugTree* m_root;    // 0x10
    };

    // Native 32-bit layout evidence:
    //   +0x14 solid, +0x24 parent, +0x28 child CFastBuffer,
    //   +0x34 subtree bounds, +0x5c local GmIso4, +0x8c surface,
    //   +0x9c flags. These members preserve those semantics without
    //   claiming native byte offsets in the standalone 64-bit build.
    CPlugSolid* m_solid;
    uint32_t m_plugId;
    CMwNod* m_nod1c;
    uint32_t m_nameId;
    CPlugTree* m_parent;
    CFastBuffer<CPlugTree*> m_children;
    GmBoxAligned m_boundingBox;
    uint32_t m_field_0x4c;
    uint32_t m_field_0x50;
    uint32_t m_field_0x54;
    uint32_t m_field_0x58;
    GmIso4 m_location;
    CPlugSurface* m_surface;
    int* m_ptr90;
    CMwNod* m_nod94;
    CMwNod* m_nod98;
    uint32_t m_field_0x9c;
    int* m_ptrA0;
    void* m_ptrA4;
    CMwNod* m_nodA8;

    CPlugTree();
    virtual ~CPlugTree();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCPlugTree();
    
    enum : uint32_t {
        kUseLocation = 0x00000004u,
        kVisible = 0x00000008u,
        kCollisionEnabled = 0x00000080u,
        kLocationDirty = 0x00010000u,
    };

    // Core spatial/scenegraph functions.
    void AddChild(CPlugTree* child);
    uint32_t GetChildCount() const;
    CPlugTree* GetChild(uint32_t index) const;
    void GetThisToRootTransfo(
        GmIso4& result,
        bool includeThis = true,
        const CPlugTree* stopBefore = nullptr) const;
    GmIso4* GetLocation();
    const GmIso4* GetLocation() const;
    void SetLocation(const GmIso4& location);
    void SetTranslation(const GmVec3& translation);
    void SetRotation(const GmMat3& rotation);
    void SetIsVisible(bool visible);
    void SetIsCollidable(bool collidable);
    void SetUseLocation(bool useLocation);
    void SetSurface(CPlugSurface* surface);
    bool UsesLocation() const;
    bool IsCollisionEnabled() const;
    
    uint32_t GetMwClassId();
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    
    // Legacy immediate-child iteration helpers. Tree algorithms use the
    // typed GetChildCount/GetChild API and are fully re-entrant.
    uint32_t GetAllChildStart();
    CPlugTree* GetAllChildNext(CPlugTree* current);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
};

#endif // CPLUGTREE_HPP
