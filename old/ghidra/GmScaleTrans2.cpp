
/* public: void __thiscall GmScaleTrans2::LeftMult(class GmScaleTrans2 const &)
 */

void __thiscall GmScaleTrans2::LeftMult(GmScaleTrans2 *this,
                                        GmScaleTrans2 *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;

  fVar1 = *(float *)(param_1 + 8);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0xc);
  fVar4 = *(float *)(this + 4);
  *(float *)this = *(float *)param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(this + 8) + fVar1 * fVar2;
  *(float *)(this + 0xc) = *(float *)(this + 0xc) + fVar3 * fVar4;
  return;
}

/* public: void __thiscall GmScaleTrans2::Mult(class GmScaleTrans2 const &) */

void __thiscall GmScaleTrans2::Mult(GmScaleTrans2 *this, GmScaleTrans2 *param_1)

{
  *(float *)this = *(float *)param_1 * *(float *)this;
  *(float *)(this + 4) = *(float *)(param_1 + 4) * *(float *)(this + 4);
  *(float *)(this + 8) = *(float *)(this + 8) * *(float *)param_1;
  *(float *)(this + 0xc) = *(float *)(this + 0xc) * *(float *)(param_1 + 4);
  *(float *)(this + 8) = *(float *)(param_1 + 8) + *(float *)(this + 8);
  *(float *)(this + 0xc) = *(float *)(param_1 + 0xc) + *(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmScaleTrans2::SetInverse(class GmScaleTrans2 const
 * &) */

void __thiscall GmScaleTrans2::SetInverse(GmScaleTrans2 *this,
                                          GmScaleTrans2 *param_1)

{
  float fVar1;

  fVar1 = *(float *)(param_1 + 4);
  *(float *)this = 1.0 / *(float *)param_1;
  *(float *)(this + 4) = fVar1 / 1.0;
  *(float *)(this + 8) = *(float *)(param_1 + 8) * *(float *)this;
  *(float *)(this + 0xc) = *(float *)(param_1 + 0xc) * *(float *)(this + 4);
  *(float *)(this + 8) = -*(float *)(this + 8);
  *(float *)(this + 0xc) = -*(float *)(this + 0xc);
  return;
}

/* public: void __thiscall GmScaleTrans2::SetRect_ConvTo_Rectm1p1(class
 * GmRectAligned const &) */

void __thiscall GmScaleTrans2::SetRect_ConvTo_Rectm1p1(GmScaleTrans2 *this,
                                                       GmRectAligned *param_1)

{
  float fVar1;
  float fVar2;

  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  *(float *)this = *(float *)(param_1 + 8) - *(float *)param_1;
  *(float *)this = *(float *)this * 0.5;
  *(float *)(this + 4) = (fVar1 - fVar2) * 0.5;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  *(float *)(this + 8) = (*(float *)(param_1 + 8) + *(float *)param_1) * 0.5;
  *(float *)(this + 0xc) = (fVar1 + fVar2) * 0.5;
  return;
}

/* public: void __thiscall GmScaleTrans2::SetRect_MoveTo_Rect(class
   GmRectAligned const &,class GmRectAligned const &) */

void __thiscall GmScaleTrans2::SetRect_MoveTo_Rect(GmScaleTrans2 *this,
                                                   GmRectAligned *param_1,
                                                   GmRectAligned *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;

  fVar5 = (*(float *)(param_2 + 0xc) - *(float *)(param_2 + 4)) /
          (*(float *)(param_1 + 0xc) - *(float *)(param_1 + 4));
  *(float *)this = (*(float *)(param_2 + 8) - *(float *)param_2) /
                   (*(float *)(param_1 + 8) - *(float *)param_1);
  *(float *)(this + 4) = fVar5;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_2 + 0xc);
  fVar4 = *(float *)(param_2 + 4);
  *(float *)(this + 8) =
      (*(float *)param_2 + *(float *)(param_2 + 8)) * 0.5 -
      *(float *)this * (*(float *)(param_1 + 8) + *(float *)param_1) * 0.5;
  *(float *)(this + 0xc) =
      (fVar3 + fVar4) * 0.5 - fVar5 * (fVar1 + fVar2) * 0.5;
  return;
}
