// PDB Verified Layout & Functions derived from ghidra/GmMat3.cpp

#ifndef GMMAT3_HPP
#define GMMAT3_HPP

#include "typedefs.h"

class CClassicArchive;
class GmQuat;
class GmVec3;
class GmIso3;

#pragma pack(push, 4)
struct GmMat3 {
public:
  float XX, XY, XZ;
  float YX, YY, YZ;
  float ZX, ZY, ZZ;

  GmMat3() : XX(1), XY(0), XZ(0), YX(0), YY(1), YZ(0), ZX(0), ZY(0), ZZ(1) {}

  void __thiscall ArchiveGmMat3(CClassicArchive *param_1);
  void __thiscall GetLine(ulong param_1, GmVec3 *param_2) const;
  ulong __thiscall Inverse(void);
  ulong __thiscall IsIndirect(void) const;
  ulong __thiscall IsNearlyEqual(GmMat3 *param_1) const;
  ulong __thiscall IsOrthogonal(void) const;
  ulong __thiscall IsOrthonormal(void) const;
  void __thiscall LeftMult(GmMat3 *param_1);
  void __thiscall Mult(float param_1);
  void __thiscall Mult(GmMat3 *param_1);
  void __thiscall MultTranspose(GmMat3 *param_1);
  void __thiscall OrthoNormalize(void);
  void __thiscall RotateX(float param_1);
  void __thiscall RotateY(float param_1);
  void __thiscall RotateZ(float param_1);
  void __thiscall Set(GmMat3 *param_1);
  void __thiscall Set(float param_1, float param_2, float param_3, float param_4);
  void __thiscall SetBlend(GmMat3 *param_1, GmMat3 *param_2, float param_3);
  void __thiscall SetDOV(GmVec3 *param_1, ulong param_2);
  int __thiscall SetDOVInverse(GmVec3 *param_1);
  void __thiscall SetDOVandLeftV(GmVec3 *param_1, GmVec3 *param_2);
  void __thiscall SetDOVandUpV(GmVec3 *param_1, GmVec3 *param_2);
  void __thiscall SetIdentity(void);
  void __thiscall SetLine(ulong param_1, GmVec3 *param_2);
  void __thiscall SetMult(GmMat3 *param_1, GmMat3 *param_2);
  void __thiscall SetRotateQuarterY(ulong param_1);
  void __thiscall SetTranspose(GmMat3 *param_1);
  void __thiscall SetUpVandDOV(GmVec3 *param_1, GmVec3 *param_2);
  void __thiscall Transpose(void);
};
#pragma pack(pop)

#endif // GMMAT3_HPP
