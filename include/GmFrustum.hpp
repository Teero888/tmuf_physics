#ifndef GMFRUSTUM_HPP
#define GMFRUSTUM_HPP

#include "GmIso4.hpp"
#include "typedefs.h"

class GmFrustum {
  // TODO: figure out fields and types

  void __thiscall ArchiveFrustum(CClassicArchive *param_1);

  void __thiscall ArchiveFrustumOld1(CClassicArchive *param_1);

  void __thiscall ChangeHeightByAspect(float param_1);

  void __thiscall ChangeWidthByAspect(float param_1);

  void __thiscall ExtrudeFromZ(float param_1, float param_2, float param_3,
                               GmVec3 *param_4);

  void __thiscall GetAspect(GmRectAligned *param_1);

  void __thiscall GetBBox(GmBoxAligned *param_1);

  float __thiscall GetFarZ();

  float __thiscall GetFovY();

  float __thiscall GetNearZ();

  void __thiscall GetPlaneEqs6(GmVec4 *param_1, GmIso4 *param_2);

  float __thiscall GetRatioXY();

  void __thiscall GetRectZ(float param_1, GmRectAligned *param_2);

  void __thiscall GetVertices4AtZ(GmVec3 *param_1, float param_2);

  ulong __thiscall IsValid();

  void __thiscall Scale(float param_1, float param_2);

  void __thiscall Set(float param_1, float param_2, float param_3,
                      float param_4);

  void __thiscall Set(GmBoxOriented *param_1);

  void __thiscall Set(undefined4 param_1, undefined4 param_2,
                      undefined4 param_3, undefined4 param_4,
                      undefined4 param_5, undefined4 param_6);

  void __thiscall Set(GmFrustum *param_1);

  void __thiscall Set(GmBoxAligned *param_1);

  void __thiscall SetComplementX(GmFrustum *param_1);

  void __thiscall SetComplementY(GmFrustum *param_1);

  void __thiscall SetFarZ(float param_1);

  void __thiscall SetFovX(float param_1, float param_2, float param_3,
                          float param_4);

  void __thiscall SetFovY(float param_1, float param_2, float param_3,
                          float param_4);

  void __thiscall SetNearZ(float param_1);

  void __thiscall SetOrtho(GmBoxAligned *param_1);

  void __thiscall SetRangeZ(float param_1, float param_2);

  int __thiscall TestInter(float param_1, float param_2, float param_3);

  ulong __thiscall TestInter(GmBoxAligned *param_1, ulong param_2);
};

#endif // GMFRUSTUM_HPP