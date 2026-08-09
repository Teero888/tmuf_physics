#ifndef CPLUGSOLID_HPP
#define CPLUGSOLID_HPP

#include "CMwNod.hpp"
#include "CPlugPhysicalObject.hpp"
#include <cstdint>

class CPlugTree;
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
class CDx9DeviceCaps;
struct CPfmHeap;

class CPlugSolid : public CMwNod {
public:
    uint32_t m_field_0x14;
    CPlugPhysicalObject m_physicalObject; // native +0x18..+0x5F
    uint32_t m_field_0x60;
    CPlugTree* m_tree;       // native root tree at +0x64
    CPlugSolid* m_solid68;
    float m_field_0x6c;
    uint32_t m_field_0x70;

    float& Mass() { return m_physicalObject.m_mass; }
    const float& Mass() const { return m_physicalObject.m_mass; }

    CPlugSolid();
    virtual ~CPlugSolid();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCPlugSolid();
    
    CPlugTree* GetPlugFromId(CPlugSolid* param_1, CMwId* param_2);
    uint32_t GetMwClassId();
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    void OnNodLoaded(CDx9DeviceCaps* param_1);
    void SetTree(CPlugTree* tree, bool connectTree = true);
    void SetTree(CPlugSolid* param_1, CPlugTree* param_2, int param_3);
};

#endif // CPLUGSOLID_HPP
