#ifndef GMMAT4_HPP
#define GMMAT4_HPP

#include "GmFrustum.hpp"
#include "GmIso3.hpp"
#include "GmIso4.hpp"
#include "GmVec4.hpp"
#include "typedefs.h"

class GmMat4 {
  float m[16];

  void __thiscall ArchiveGmMat4(CClassicArchive *param_1);

  void __thiscall Mult(GmMat4 *param_1);

  void __thiscall Mult(GmIso4 *param_1);

  GmVec4 *__thiscall operator[](ulong param_1);

  void __thiscall Set(GmMat4 *param_1);

  void __thiscall Set(GmIso4 *param_1);

  void __thiscall SetFrustumProjection(GmFrustum *param_1, ulong param_2);

  void __thiscall SetIdentity();

  void __thiscall SetMult(GmIso4 *param_1, GmMat4 *param_2);

  void __thiscall SetMult(GmMat4 *param_1, GmMat4 *param_2);

  void __thiscall SetShadowPlaneProjection(GmVec4 *param_1, GmVec4 *param_2);

  void __thiscall SetShadowPlaneProjectionDirectional(GmVec3 *param_1,
                                                      GmVec4 *param_2);

  void __thiscall SetShadowPlaneProjectionPoint(GmVec3 *param_1,
                                                GmVec4 *param_2);

  void __thiscall SetTranspose(GmMat4 *param_1);

  void __thiscall SetTranspose(GmIso4 *param_1);

  void __thiscall SetTransposeXY(GmIso3 *param_1);

  void __thiscall SetTransposeXY_TransZ(GmIso3 *param_1);

  void __thiscall SetXY(GmIso3 *param_1);

  void __thiscall Transpose();
};

#endif // GMMAT4_HPP