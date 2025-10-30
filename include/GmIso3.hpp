#ifndef GMISO3_HPP
#define GMISO3_HPP

#include "typedefs.h"

class CClassicArchive;

class GmIso3 {
  float AxeXx, AxeXy, AxeYx, AxeYy;
  float tx, ty;

  void __thiscall ArchiveGmIso3(CClassicArchive *param_1);
  void __thiscall Mult(GmIso3 *param_1);
  void __thiscall MultInverse(GmIso3 *param_1);
  void __thiscall Set(GmIso3 *param_1);
  void __thiscall SetIdentity();
  void __thiscall SetInverse(GmIso3 *param_1);
  void __thiscall SetMult(GmIso3 *param_1, GmIso3 *param_2);
};

#endif // GMISO3_HPP