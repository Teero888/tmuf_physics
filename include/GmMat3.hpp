#include "GmVec3.hpp"
#include "typedefs.h"

class GmMat3 {
  float m[9];

  void __thiscall ArchiveGmMat3(CClassicArchive *param_1);

  void __thiscall GetLine(ulong param_1, GmVec3 *param_2);

  ulong __thiscall Inverse();

  ulong __thiscall IsIndirect();

  ulong __thiscall IsNearlyEqual(GmMat3 *param_1);

  ulong __thiscall IsOrthogonal();

  ulong __thiscall IsOrthonormal();

  void __thiscall LeftMult(GmMat3 *param_1);

  void __thiscall Mult(float param_1);

  void __thiscall Mult(GmMat3 *param_1);

  void __thiscall MultTranspose(GmMat3 *param_1);

  void __thiscall OrthoNormalize();

  void __thiscall RotateX(float param_1);

  void __thiscall RotateY(float param_1);

  void __thiscall RotateZ(float param_1);

  void __thiscall Set(GmMat3 *param_1);

  void __thiscall Set(float param_1, float param_2, float param_3,
                      float param_4);

  void __thiscall SetBlend(GmMat3 *param_1, GmMat3 *param_2, float param_3);

  void __thiscall SetDOV(GmVec3 *param_1, ulong param_2);

  int __thiscall SetDOVInverse(GmVec3 *param_1);

  void __thiscall SetDOVandLeftV(GmVec3 *param_1, GmVec3 *param_2);

  void __thiscall SetDOVandUpV(GmVec3 *param_1, GmVec3 *param_2);

  void __thiscall SetIdentity();

  void __thiscall SetLine(ulong param_1, GmVec3 *param_2);

  void __thiscall SetMult(GmMat3 *param_1, GmMat3 *param_2);

  void __thiscall SetRotateQuarterY(ulong param_1);

  void __thiscall SetTranspose(GmMat3 *param_1);

  void __thiscall SetUpVandDOV(GmVec3 *param_1, GmVec3 *param_2);

  void __thiscall Transpose();
};
