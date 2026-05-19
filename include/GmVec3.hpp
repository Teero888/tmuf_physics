// PDB Verified Layout & Functions derived from ghidra/GmVec3.cpp

#ifndef GMVEC3_HPP
#define GMVEC3_HPP

#include "typedefs.h"

class GmIso4;
class GmMat4;
class GmMat3;

#pragma pack(push, 4)
struct GmVec3 {
public:
  float x, y, z;

  GmVec3() : x(0), y(0), z(0) {}
  GmVec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

  static int __cdecl ComputeTriangleTangentUV(struct STri_PosTexTgt *param_1);
  static int __cdecl DoesRayIntersectTriangle(GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3, GmVec3 *param_4, GmVec3 *param_5, float *param_6, float *param_7, float *param_8);
  static int __cdecl DoesRayIntersectTriangleCull(GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3, GmVec3 *param_4, GmVec3 *param_5, float *param_6, float *param_7, float *param_8);
  static float __cdecl GetAngle(GmVec3 *param_1, GmVec3 *param_2);
  static float __cdecl GetInnerAngle(GmVec3 *param_1, GmVec3 *param_2);

  ulong __thiscall IsNearlyEqual(GmVec3 *param_1);
  void __thiscall Mult(GmIso4 *param_1);
  void __thiscall Mult(GmMat3 *param_1);
  void __thiscall Mult(GmMat4 *param_1);
  void __thiscall MultInverse(GmIso4 *param_1);
  void __thiscall MultTranspose(GmMat3 *param_1);
  void __thiscall SetFromBGRA(uchar *param_1, ulong param_2);
  void __thiscall SetInverseTranslation(GmIso4 *param_1);
  void __thiscall SetMult(GmVec3 *param_1, GmMat3 *param_2);
  void __thiscall SetMult(GmVec3 *param_1, GmIso4 *param_2);
  void __thiscall SetMult(GmVec3 *param_1, GmMat4 *param_2);
  void __thiscall SetMultTranspose(GmVec3 *param_1, GmMat3 *param_2);
};
#pragma pack(pop)

#endif // GMVEC3_HPP
