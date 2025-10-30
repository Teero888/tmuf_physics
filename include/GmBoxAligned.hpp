#include "GmBoxOriented.hpp"
#include "GmCone3.hpp"
#include "GmFrustum.hpp"
#include "GmVec3.hpp"
#include "typedefs.h"

class GmBoxAligned {
  // TODO: figure out fields and types

  void __thiscall ArchiveABox(CClassicArchive *param_1);

  void __thiscall ArchiveABoxOld1(CClassicArchive *param_1);

  void __thiscall GetDiag(GmVec3 *param_1);

  void __thiscall GetMax(float *param_1);

  void __thiscall GetMin(float *param_1);

  void __thiscall GetMinMax(GmVec3 *param_1, GmVec3 *param_2);

  int __thiscall Inter(GmBoxAligned *param_1);

  int __thiscall IsIncluded(GmFrustum *param_1);

  int __thiscall IsIncluded(GmBoxAligned *param_1);

  int __thiscall IsNull();

  void __thiscall Mult(GmIso4 *param_1);

  void __thiscall Set(GmBoxAligned *param_1);

  void __thiscall Set(GmBoxOriented *param_1);

  void __thiscall SetCenter0HalfDiag(GmVec3 *param_1);

  void __thiscall SetCenterHalfDiag(GmVec3 *param_1, GmVec3 *param_2);

  void __thiscall SetFromConeAndRadius(GmCone3 *param_1, float param_2);

  void __thiscall SetMinMax(GmVec3 *param_1, GmVec3 *param_2);

  void __thiscall SetMult(GmBoxAligned *param_1, GmIso4 *param_2);

  int __thiscall TestInter(GmBoxAligned *param_1);

  int __thiscall TestInter(GmVec3 *param_1);

  int __thiscall TestInterSegment(GmVec3 *param_1, GmVec3 *param_2);

  int __thiscall TestInterSegment_MiddleVectAB(GmVec3 *param_1,
                                               GmVec3 *param_2);

  void __thiscall Union(GmBoxAligned *param_1);
};
