#ifndef GMTRANSQUAT_HPP
#define GMTRANSQUAT_HPP

#include "GmQuat.hpp"
#include "GmVec3.hpp"
#include "typedefs.h"

class GmTransQuat {
  // TODO: this is an assumption, check if correct
  GmQuat Rotation;
  GmVec3 Translation;
  void __thiscall SetBlend(GmTransQuat *param_1, GmTransQuat *param_2, float param_3);
};

#endif // GMTRANSQUAT_HPP