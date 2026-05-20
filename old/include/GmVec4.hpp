#ifndef GMVEC4_HPP
#define GMVEC4_HPP

#include "typedefs.h"

class GmIso4;
class GmMat4;
class GmLine3;
class GmVec3;

class GmVec4 {
  float x, y, z, w;

  static void __cdecl PolygonClip(CFastBuffer<> *param_1, CFastBuffer<> *param_2);
  static void __cdecl GetClipFlags(GmVec4 *param_1, GmClipFlag_HalfCube *param_2, ulong param_3);
  void __thiscall Add(float param_1, float param_2, float param_3, float param_4);
  void __thiscall GetClipFlag(GmClipFlag_HalfCube *param_1);
  void __thiscall Mult(float *param_1);
  void __thiscall Mult(GmMat4 *param_1);
  void __thiscall Neg();
  ulong __thiscall PlaneEqInterLine(GmVec3 *param_1, GmVec3 *param_2, float *param_3);
  ulong __thiscall PlaneEqInterPlane(GmVec4 *param_1, GmLine3 *param_2);
  ulong __thiscall PlaneEqIsNearlyEqual(GmVec4 *param_1, float param_2, float param_3);
  void __thiscall PlaneEqMult(GmIso4 *param_1);
  ulong __thiscall PlaneEqSetFrom3Pos(GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3);
  void __thiscall PlaneEqSetMult(GmVec4 *param_1, GmIso4 *param_2);
  void __thiscall PlaneEqSetNormPos(GmVec3 *param_1, GmVec3 *param_2);
  void __thiscall Set(float param_1, float param_2, float param_3, float param_4);
  void __thiscall Set(GmVec3 *param_1, float param_2);
  void __thiscall Set(GmVec4 *param_1);
  void __thiscall SetBlend(GmVec4 *param_1, GmVec4 *param_2, float param_3);
  void __thiscall SetLeftMult(GmIso4 *param_1, GmVec4 *param_2);
  void __thiscall SetMult(float param_1, GmVec4 *param_2);
  void __thiscall SetMult(GmVec4 *param_1, GmMat4 *param_2);
  void __thiscall SetSub(GmVec4 *param_1, GmVec4 *param_2);
  void __thiscall Sub(float param_1, float param_2, float param_3, float param_4);
};

#endif // GMVEC4_HPP