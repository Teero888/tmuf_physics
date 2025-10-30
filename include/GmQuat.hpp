#ifndef GMQUAT_HPP
#define GMQUAT_HPP

#include "typedefs.h"

class GmMat3;
class GmVec3;

class GmQuat {
  float w, x, y, z;

  void __thiscall ArchiveGmQuat(CClassicArchive *param_1);
  void __thiscall ArchiveGmQuatCompact(CClassicArchive *param_1);
  void __thiscall ComputeSquad(GmQuat *param_1, GmQuat *param_2, GmQuat *param_3, GmQuat *param_4, float param_5);
  void __thiscall GetRotation(float *param_1, GmVec3 *param_2);
  void __thiscall GetYawPitchRoll(float *param_1, float *param_2, float *param_3);
  void __thiscall Mult(GmQuat *param_1);
  void __thiscall Normalize();
  void __thiscall Set(float param_1, GmVec3 *param_2);
  void __thiscall Set(GmMat3 *param_1);
  void __thiscall SetIdentity();
  void __thiscall SetInverse(GmQuat *param_1);
  void __thiscall SetMult(GmQuat *param_1, GmQuat *param_2);
  void __thiscall SetRotation(float param_1, GmVec3 *param_2);
  void __thiscall SetSlerp(float param_1, float param_2, float param_3, float param_4, float *param_5, float param_6);
  void __thiscall SetSquad(float param_1, float param_2, float param_3, float param_4, float *param_5, float *param_6, float *param_7, float param_8);
  void __thiscall SetYawPitchRoll(float param_1, float param_2, float param_3);
};

#endif // GMQUAT_HPP