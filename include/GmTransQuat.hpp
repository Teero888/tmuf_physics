#ifndef GMTRANSQUAT_HPP
#define GMTRANSQUAT_HPP

#include "typedefs.h"

class GmTransQuat {
  float w, x, y, z;
  void __thiscall SetBlend(GmTransQuat *param_1, GmTransQuat *param_2, float param_3);
};

#endif // GMTRANSQUAT_HPP