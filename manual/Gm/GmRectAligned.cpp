// Class implementation: GmRectAligned

// =================================================
// Function: GmRectAligned::Mult
// =================================================
void __thiscall GmRectAligned::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  *(float *)this = *(float *)param_1 * *(float *)this + *(float *)(param_1 + 8);
  *(float *)((int)this + 4) =
       *(float *)(param_1 + 4) * *(float *)((int)this + 4) + *(float *)(param_1 + 0xc);
  *(float *)((int)this + 8) =
       *(float *)((int)this + 8) * *(float *)param_1 + *(float *)(param_1 + 8);
  *(float *)((int)this + 0xc) =
       *(float *)((int)this + 0xc) * *(float *)(param_1 + 4) + *(float *)(param_1 + 0xc);
  return;
}
}

// =================================================
// Function: GmRectAligned::SetMult
// =================================================
void __thiscall
GmRectAligned::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  *(float *)this = *(float *)param_1 * *(float *)param_2 + *(float *)(param_2 + 8);
  *(float *)((int)this + 4) =
       *(float *)(param_1 + 4) * *(float *)(param_2 + 4) + *(float *)(param_2 + 0xc);
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) * *(float *)param_2 + *(float *)(param_2 + 8);
  *(float *)((int)this + 0xc) =
       *(float *)(param_1 + 0xc) * *(float *)(param_2 + 4) + *(float *)(param_2 + 0xc);
  return;
}
}

// =================================================
// Function: GmRectAligned::TestInter
// =================================================
int __thiscall
GmRectAligned::TestInter
          (void *this,CPlugVolumeProjector *param_1,GmBoxAligned *param_2,GmIso4 *param_3)
{
{
  if ((((*(float *)param_1 < *(float *)((int)this + 8) !=
         (*(float *)param_1 == *(float *)((int)this + 8))) &&
       (*(float *)this <= *(float *)(param_1 + 8))) &&
      (*(float *)(param_1 + 4) < *(float *)((int)this + 0xc) !=
       (*(float *)(param_1 + 4) == *(float *)((int)this + 0xc)))) &&
     (*(float *)((int)this + 4) <= *(float *)(param_1 + 0xc))) {
    return 1;
  }
  return 0;
}
}

