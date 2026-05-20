#ifndef GMBOXALIGNED_HPP
#define GMBOXALIGNED_HPP

#include "typedefs.h"

struct GmIso4;

struct GmBoxAligned {
    float field_0x0; // accesses: 19
    float field_0x4; // accesses: 17
    float field_0x8; // accesses: 18
    float field_0xc; // accesses: 25
    float field_0x10; // accesses: 22
    float field_0x14; // accesses: 23

    // Member Functions
    GmVec3 __thiscall GetMin(void *this,GmBoxAligned *param_1);
    int __thiscall IsIncluded(void *this,GmBoxAligned *param_1,GmBoxAligned *param_2);
    int __thiscall IsNull(void *this,CSysFidNodRef<class_CPlugBitmap> *param_1);
    int __thiscall TestInter (void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3);
    int __thiscall TestInterSegment_MiddleVectAB (void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3);
    ulong __thiscall TestInterSegment(void *this,GmRectAligned *param_1,GmVec2 *param_2,GmVec2 *param_3);
    void __thiscall ArchiveABox(void *this,GmBoxAligned *param_1,CClassicArchive *param_2);
    void __thiscall ArchiveABoxOld1(void *this,GmBoxAligned *param_1,CClassicArchive *param_2);
    void __thiscall GetDiag(void *this,GmBoxAligned *param_1,GmVec3 *param_2);
    void __thiscall GetMinMax(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall Mult(void *this,GmIso3 *param_1,GmIso3 *param_2);
    void __thiscall SetCenterHalfDiag(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall SetFromConeAndRadius(void *this,GmBoxAligned *param_1,GmCone3 *param_2,float param_3);
    void __thiscall SetMinMax(void *this,GmBoxAligned *param_1,GmVec3 *param_2,GmVec3 *param_3);
    void __thiscall SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3);
    void __thiscall Union(void *this,GmRectAligned *param_1,GmVec2 *param_2);
};

#endif // GMBOXALIGNED_HPP
