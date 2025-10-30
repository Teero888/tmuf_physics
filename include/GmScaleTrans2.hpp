#ifndef GMSCALETRANS2_HPP
#define GMSCALETRANS2_HPP

#include "typedefs.h"

class GmRectAligned;

class GmScaleTrans2 {
  // TODO: figure out fields and types

  void __thiscall LeftMult(GmScaleTrans2 *param_1);
  void __thiscall Mult(GmScaleTrans2 *param_1);
  void __thiscall SetInverse(GmScaleTrans2 *param_1);
  void __thiscall SetRect_ConvTo_Rectm1p1(GmRectAligned *param_1);
  void __thiscall SetRect_MoveTo_Rect(GmRectAligned *param_1, GmRectAligned *param_2);
};

#endif // GMSCALETRANS2_HPP
