#ifndef CPLUGSURFACEGEOM_HPP
#define CPLUGSURFACEGEOM_HPP

#include "typedefs.h"

struct GmSurf;
struct GmSurfMesh;

struct CPlugSurfaceGeom {
    byte _padding_0x0[4];
    CPlugBlendShapes * field_0x4; // accesses: 9
    char field_0x6; // accesses: 5
    byte _padding_0x7[1];
    int field_0x8; // accesses: 31
    float field_0xc; // accesses: 3
    int field_0x10; // accesses: 5
    float field_0x14; // accesses: 2
    int field_0x18; // accesses: 10
    float field_0x1c; // accesses: 4
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1
    float field_0x28; // accesses: 2
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 1
    undefined4 * field_0x34; // accesses: 50
    undefined4 field_0x38; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall GetVolume(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CPlugSurfaceGeom(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1);
    CMwClassInfo * __thiscall MwGetClassInfo(CPlugSurfaceGeom *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCPlugSurfaceGeom(void);
    int __thiscall MwIsKindOf(CPlugSurfaceGeom *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetChunkInfo(CPlugSurfaceGeom *this,CFuncSegment *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CPlugSurfaceGeom *this,CControlStyle *param_1);
    ulong __thiscall GetUidChunkFromIndex (CPlugSurfaceGeom *this,CMwCmdExpIso4Ident *param_1,ulong param_2);
    ulong __thiscall GetWeightDistribCount(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1);
    ulong __thiscall VirtualParam_Get (CPlugSurfaceGeom *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    ulong __thiscall VirtualParam_Set (CPlugSurfaceGeom *this,CSystemData *param_1,CMwStack *param_2,void *param_3);
    void * __thiscall _scalar_deleting_destructor_ (CPlugSurfaceGeom *this,CPfmHeap *param_1,uint param_2);
    void __thiscall Chunk (CPlugSurfaceGeom *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
    void __thiscall ComputeBoundingBox (CPlugSurfaceGeom *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3);
    void __thiscall CreateDefaultData(CPlugSurfaceGeom *this,CCrystal *param_1);
    void __thiscall GetWeightDistrib (CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1,ulong param_2,GmVec3 *param_3);
    void __thiscall SetGmSurfType (CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1,EGmSurfType *param_2);
    void __thiscall TransformByNOMat(CPlugSurfaceGeom *this,GmSurfMesh *param_1,GmIso4 *param_2);
    void __thiscall ~CPlugSurfaceGeom(CPlugSurfaceGeom *this,CPlugSurfaceGeom *param_1);
};

#endif // CPLUGSURFACEGEOM_HPP
