#ifndef GMRECTALIGNED_H
#define GMRECTALIGNED_H

#include "typedefs.h"

class GmScaleTrans2;
class GmBoxAligned;
class GmVec2;
class GmFrustum;

class GmRectAligned {
  // TODO: figure out fields and types

  void __thiscall Archive(CClassicArchive *param_1);
  void __thiscall GetLocalCoordinates(GmVec2 *param_1, GmVec2 *param_2);
  void __thiscall Inter(GmRectAligned *param_1);
  ulong __thiscall IsInside(GmVec2 *param_1);
  ulong __thiscall IsNull();
  void __thiscall Mult(GmScaleTrans2 *param_1);
  void __thiscall ScaleByEpsilon();
  void __thiscall SetBoxProjection(GmBoxAligned *param_1, GmFrustum *param_2);
  void __thiscall SetMult(GmRectAligned *param_1, GmScaleTrans2 *param_2);
  void __thiscall SetSubRectFrom_m1p1(GmRectAligned *param_1, GmRectAligned *param_2);
  ulong __thiscall TestInter(GmRectAligned *param_1);
  ulong __thiscall TestInterSegment(GmVec2 *param_1, GmVec2 *param_2);
  ulong __thiscall TestInterTriangle(GmVec2 *param_1, GmVec2 *param_2,
                                     GmVec2 *param_3, int *param_4,
                                     float *param_5, float *param_6,
                                     int *param_7, int param_8);
  void __thiscall Union(GmVec2 *param_1);
};

#endif // GMRECTALIGNED_H
