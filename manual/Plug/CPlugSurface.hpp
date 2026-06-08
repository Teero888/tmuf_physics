#ifndef CPLUGSURFACE_HPP
#define CPLUGSURFACE_HPP

#include "CMwNod.hpp"
#include <cstdint>

class CFuncSegment;
class CClassicArchive;
struct LocatedGmSurf;
class CGmCollisionBuffer;
class CMwCmdAffectParam;
class CControlStyle;
class CMwCmdExpIso4Ident;
struct CPfmHeap;

class CPlugSurface : public CMwNod {
public:
    CMwNod* m_nod14; // 0x14
    uint8_t m_padding[12];

    CPlugSurface();
    virtual ~CPlugSurface();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCPlugSurface();
    static int ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3);
    int MwIsKindOf(uint32_t classId);
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetMwClassId();
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    static void StaticInit();
    static void StaticRelease();
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
};

#endif // CPLUGSURFACE_HPP
