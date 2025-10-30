#ifndef GMVEC2_HPP
#define GMVEC2_HPP
#include "typedefs.h"

class GmIso3;
class GmMat2;

class GmVec2 {
  float x, y;

  void __thiscall ArchiveGmVec2(CClassicArchive *param_1);
  float __thiscall GetLength();
  ulong __cdecl IsInTriangle(GmVec2 *param_1, GmVec2 *param_2, GmVec2 *param_3,
                             GmVec2 *param_4, float *param_5, float *param_6,
                             int *param_7);
  ulong __thiscall IsNearlyEqual(GmVec2 *param_1);
  void __thiscall Mult(GmMat2 *param_1);
  ulong __thiscall Normalize();
  float *__thiscall operator[](ulong param_1);
  void __thiscall SetBlend(GmVec2 *param_1, GmVec2 *param_2, float param_3);
  void __thiscall SetBlendTri(GmVec2 *param_1, GmVec2 *param_2, GmVec2 *param_3, float param_4, float param_5);
  void __thiscall SetMultInverse(GmVec2 *param_1, GmIso3 *param_2);
};
#endif // GMVEC2_HPP
