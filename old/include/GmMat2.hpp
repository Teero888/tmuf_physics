#ifndef GMMAT2_HPP
#define GMMAT2_HPP

#include "typedefs.h"

class GmMat2 {
  float m[4];

  void __thiscall Mult(GmMat2 *param_1);
  void __thiscall Rotate(float param_1);
  void __thiscall SetIdentity();
  void __thiscall SetMult(GmMat2 *param_1, GmMat2 *param_2);
  void __thiscall SetRotation(float param_1);
  void __thiscall SetTranspose(GmMat2 *param_1);
};

#endif //  GMMAT2_HPP
