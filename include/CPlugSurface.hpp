#ifndef CPLUGSURFACE_HPP
#define CPLUGSURFACE_HPP

#include "typedefs.h"

struct CClassicArchive;
struct CMwNod;

struct CPlugSurface {
    void** vftable; // accesses: 2
    byte _padding_0x4[16];
    CMwNod * field_0x14; // accesses: 8
    byte _final_padding[0xc]; // Total size: 0x24

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl StaticInit(void);
    CMwClassInfo * __thiscall MwGetClassInfo(CPlugSurface *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCPlugSurface(void);
    int __cdecl ComputeCollision (LocatedGmSurf *param_1,LocatedGmSurf *param_2,CGmCollisionBuffer *param_3);
    int __thiscall MwIsKindOf(CPlugSurface *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CPlugSurface *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CPlugSurface *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex(CPlugSurface *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    void * __thiscall _scalar_deleting_destructor_(CPlugSurface *this,CPfmHeap *param_1,uint param_2);
    void __cdecl StaticRelease(void);
    void __thiscall CPlugSurface(CPlugSurface *this,CPlugSurface *param_1);
    void __thiscall Chunk(CPlugSurface *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ~CPlugSurface(CPlugSurface *this,CPlugSurface *param_1);
};

#endif // CPLUGSURFACE_HPP
