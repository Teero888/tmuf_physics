#ifndef CPLUGTREE_HPP
#define CPLUGTREE_HPP

#include "CMwNod.hpp"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmMat2.hpp"
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

    // 0x00: vftable (MwNod)
    // 0x04: m_refCount
    // 0x08: m_flags
    // 0x0C: m_dependants
    // 0x10: m_receivers
    
    CPlugSolid* m_solid;             // 0x14
    uint32_t m_field_0x18;
    CMwNod* m_nod1c;
    int m_field_0x20;
    CPlugTree* m_parent;             // 0x24
    uint8_t m_padding_0x28[12];
    GmIso4 m_location;               // 0x34 (0x34 to 0x63, 48 bytes)
    uint32_t m_field_0x64;
    uint32_t m_field_0x68;
    float m_field_0x6c;
    uint32_t m_field_0x70;
    uint8_t m_padding_0x74[12];      // Gap seen in dump 0x5c to 0x80
    uint32_t m_field_0x80;
    uint32_t m_field_0x84;
    uint32_t m_field_0x88;
    CMwNod* m_nod8c;
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
    
    // Core spatial/scenegraph functions
    static void GetThisToRootTransfo(GmIso4* res, void* p, GmIso4* a, int i, CPlugTree* t);
    GmIso4* GetLocation();
    void SetLocation(CPlugTree* param_1, GmIso4* param_2);
    void SetTranslation(GmIso4* param_1, GmVec3* param_2);
    void SetRotation(GmMat2* param_1, float param_2);
    void SetIsVisible(CPlugTree* param_1, int param_2);
    
    uint32_t GetMwClassId();
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    
    // Iteration helpers (simplified from dump)
    uint32_t GetAllChildStart();
    CPlugTree* GetAllChildNext(CPlugTree* current);
    
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
};

#endif // CPLUGTREE_HPP
