#ifndef CPLUGSOLID_HPP
#define CPLUGSOLID_HPP

#include "CMwNod.hpp"
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
    float m_mass;          // 0x18
    uint8_t m_padding[36];
    uint32_t m_field_0x40;
    uint32_t m_field_0x44;
    uint32_t m_field_0x48;
    uint8_t m_padding2[8];
    CClassicArchive* m_archive54;
    CClassicArchive* m_archive58;
    CPlugSolid* m_model5c;
    uint32_t m_field_0x60;
    int* m_ptr64;
    CPlugSolid* m_solid68;
    float m_field_0x6c;
    uint32_t m_field_0x70;

    CPlugSolid();
    virtual ~CPlugSolid();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    static CMwNod* MwNewCPlugSolid();
    
    CPlugTree* GetPlugFromId(CPlugSolid* param_1, CMwId* param_2);
    uint32_t GetMwClassId();
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
    void OnNodLoaded(CDx9DeviceCaps* param_1);
    void SetTree(CPlugSolid* param_1, CPlugTree* param_2, int param_3);
};

#endif // CPLUGSOLID_HPP
