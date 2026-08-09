#ifndef CPLUGSURFACE_HPP
#define CPLUGSURFACE_HPP

#include "CMwNod.hpp"
#include "CFastBuffer.hpp"
#include "GmIso4.hpp"
#include <cstdint>

class CFuncSegment;
class CClassicArchive;
struct LocatedGmSurf;
struct LocatedPlugSurface;
class CGmCollisionBuffer;
class CPlugSurfaceGeom;
class CMwCmdAffectParam;
class CControlStyle;
class CMwCmdExpIso4Ident;
struct CPfmHeap;

class CPlugSurface : public CMwNod {
public:
    CPlugSurfaceGeom* m_geometry; // native +0x14
    // Native stores CPlugMaterial references at +0x18 and maps each GmSurf
    // local material index through the material's byte at +0x18. Standalone
    // code stores those resolved 16-bit physical material IDs directly.
    CFastBuffer<uint16_t> m_materialIds;

    CPlugSurface();
    virtual ~CPlugSurface();

    virtual CMwClassInfo* GetClassInfo() override { return nullptr; }

    CMwClassInfo* MwGetClassInfo(CFuncSegment* param_1);
    static CMwNod* MwNewCPlugSurface();
    static int ComputeCollision(LocatedGmSurf* param_1, LocatedGmSurf* param_2, CGmCollisionBuffer* param_3);
    static int ComputeCollision(LocatedPlugSurface* first, LocatedPlugSurface* second, CGmCollisionBuffer* buffer);
    int MwIsKindOf(uint32_t classId);
    uint32_t GetChunkInfo(CFuncSegment* param_1, uint32_t param_2);
    uint32_t GetMwClassId();
    uint32_t GetUidChunkFromIndex(CMwCmdExpIso4Ident* param_1, uint32_t param_2);
    
    void* _scalar_deleting_destructor_(CPfmHeap* param_1, uint32_t param_2);
    static void StaticInit();
    static void StaticRelease();
    void Chunk(CFuncSegment* param_1, CClassicArchive* param_2, uint32_t param_3);
};

struct LocatedPlugSurface {
    CPlugSurface* m_surface;
    GmIso4 m_location;
};

#endif // CPLUGSURFACE_HPP
