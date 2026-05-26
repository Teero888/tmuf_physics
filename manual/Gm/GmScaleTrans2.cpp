// Class implementation: GmScaleTrans2

// =================================================
// Function: GmScaleTrans2::LeftMult
// =================================================
void __thiscall GmScaleTrans2::LeftMult(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_1 + 8);
  fVar2 = *(float *)this;
  fVar3 = *(float *)(param_1 + 0xc);
  fVar4 = *(float *)((int)this + 4);
  *(float *)this = *(float *)param_1 * *(float *)this;
  *(float *)((int)this + 4) = *(float *)(param_1 + 4) * *(float *)((int)this + 4);
  *(float *)((int)this + 8) = *(float *)((int)this + 8) + fVar1 * fVar2;
  *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) + fVar3 * fVar4;
  return;
}
}

// =================================================
// Function: GmScaleTrans2::SetInverse
// =================================================
void __thiscall GmScaleTrans2::SetInverse(void *this,GmScaleTrans2 *param_1,GmScaleTrans2 *param_2)
{
{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 4);
  *(float *)this = 1.0 / *(float *)param_1;
  *(float *)((int)this + 4) = 1.0 / fVar1;
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) * *(float *)this;
  *(float *)((int)this + 0xc) = *(float *)(param_1 + 0xc) * *(float *)((int)this + 4);
  *(float *)((int)this + 8) = -*(float *)((int)this + 8);
  *(float *)((int)this + 0xc) = -*(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmScaleTrans2::SetRect_ConvTo_Rectm1p1
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmScaleTrans2::SetRect_ConvTo_Rectm1p1(void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  *(float *)this = *(float *)(param_1 + 8) - *(float *)param_1;
  fVar3 = (float)_DAT_00b313b8;
  *(float *)this = *(float *)this * fVar3;
  *(float *)((int)this + 4) = (fVar1 - fVar2) * fVar3;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  *(float *)((int)this + 8) = (*(float *)(param_1 + 8) + *(float *)param_1) * fVar3;
  *(float *)((int)this + 0xc) = (fVar1 + fVar2) * fVar3;
  return;
}
}

// =================================================
// Function: GmScaleTrans2::SetRect_MoveTo_Rect
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmScaleTrans2::SetRect_MoveTo_Rect
          (void *this,GmScaleTrans2 *param_1,GmRectAligned *param_2,GmRectAligned *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = (*(float *)(param_2 + 0xc) - *(float *)(param_2 + 4)) /
          (*(float *)(param_1 + 0xc) - *(float *)(param_1 + 4));
  *(float *)this =
       (*(float *)(param_2 + 8) - *(float *)param_2) / (*(float *)(param_1 + 8) - *(float *)param_1)
  ;
  *(float *)((int)this + 4) = fVar5;
  fVar6 = (float)_DAT_00b313b8;
  fVar1 = *(float *)(param_1 + 0xc);
  fVar2 = *(float *)(param_1 + 4);
  fVar3 = *(float *)(param_2 + 0xc);
  fVar4 = *(float *)(param_2 + 4);
  *(float *)((int)this + 8) =
       (*(float *)param_2 + *(float *)(param_2 + 8)) * fVar6 -
       *(float *)this * (*(float *)(param_1 + 8) + *(float *)param_1) * fVar6;
  *(float *)((int)this + 0xc) = (fVar3 + fVar4) * fVar6 - fVar5 * (fVar1 + fVar2) * fVar6;
  return;
}
}

