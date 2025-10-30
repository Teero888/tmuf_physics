#ifndef GMISO4_HPP
#define GMISO4_HPP

#include "typedefs.h"

class GmVec3;
class GmVec4;
class GmMat3;
class GmTransQuat;
class GmIso3;

class GmIso4 {
  // 3x3 matrix
  float AxeXx, AxeXy, AxeXz;
  float AxeYx, AxeYy, AxeYz;
  float AxeZx, AxeZy, AxeZz;

  float tx, ty, tz;

  void __thiscall ArchiveGmIso4(CClassicArchive *param_1);
  void __thiscall GetDir(GmVec3 *param_1);
  void __thiscall GetPlaneEq(ulong param_1, GmVec4 *param_2);
  void __thiscall Inverse();
  ulong __thiscall IsNearlyEqual(GmIso4 *param_1);
  void __thiscall LeftMult(GmIso4 *param_1);
  void __thiscall Mult(GmIso4 *param_1);
  void __thiscall MultInverse(GmIso4 *param_1);
  void __thiscall NUGetIso4AndScale(GmIso4 *param_1, GmVec3 *param_2);
  void __thiscall NUScaleSetInverse(GmIso4 *param_1);
  void __thiscall RotateX(float param_1);
  void __thiscall RotateY(float param_1);
  void __thiscall RotateZ(float param_1);
  void __thiscall Set(GmMat3 *param_1, GmVec3 *param_2);
  void __thiscall Set(GmTransQuat *param_1);
  void __thiscall SetBlend(GmIso4 *param_1, GmIso4 *param_2, float param_3);
  void __thiscall SetColumn(ulong param_1, GmVec4 *param_2);
  void __thiscall SetIdentity();
  void __thiscall SetInverse(GmIso4 *param_1);
  void __thiscall SetLookAt(GmVec3 *param_1, GmVec3 *param_2, GmVec3 *param_3);
  void __thiscall SetLookAt(GmVec3 *param_1, GmVec3 *param_2, ulong param_3);
  void __thiscall SetMult(GmIso4 *param_1, GmIso4 *param_2);
  void __thiscall SetNUScaleTrans(GmVec3 *param_1, GmVec3 *param_2);
  void __thiscall SetRotation(GmMat3 *param_1);
  void __thiscall SetTranslation(GmVec3 *param_1);
  void __thiscall SetUScaleTrans(float param_1, GmVec3 *param_2);
  void __thiscall SetXY(GmIso3 *param_1);
  void __thiscall SymmetryPlane(GmVec4 *param_1);
  void __thiscall UScaleSetInverse(GmIso4 *param_1);
};

#endif // GMISO4_HPP