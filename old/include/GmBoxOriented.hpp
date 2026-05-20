#ifndef GMBOXORIENTED_HPP
#define GMBOXORIENTED_HPP

#include "GmMat3.hpp"
#include "GmVec3.hpp"
#include "typedefs.h"

class GmIso4;
class GmBoxAligned;

class GmBoxOriented {
  // TODO: this is an assumption, check if correct
  GmMat3 m_OrthonormalBasis;
  GmVec3 m_Center;
  GmVec3 m_HalfDiag;

  void __thiscall Mult(GmIso4 *param_1);
  void __thiscall Set(GmBoxAligned *param_1);
  void __thiscall SetNull();
};

#endif // GMBOXORIENTED_HPP