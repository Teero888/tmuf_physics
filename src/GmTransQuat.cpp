

/* public: void __thiscall GmTransQuat::SetBlend(class GmTransQuat const &,class
   GmTransQuat const
   &,float) */

void __thiscall GmTransQuat::SetBlend(GmTransQuat *this, GmTransQuat *param_1,
                                      GmTransQuat *param_2, float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;

  *(float *)(this + 0x10) =
      *(float *)(param_2 + 0x10) - *(float *)(param_1 + 0x10);
  *(float *)(this + 0x14) =
      *(float *)(param_2 + 0x14) - *(float *)(param_1 + 0x14);
  *(float *)(this + 0x18) =
      *(float *)(param_2 + 0x18) - *(float *)(param_1 + 0x18);
  fVar1 = *(float *)(this + 0x10);
  *(float *)(this + 0x10) = param_3 * fVar1;
  fVar2 = *(float *)(this + 0x14);
  *(float *)(this + 0x14) = fVar2 * param_3;
  fVar3 = *(float *)(this + 0x18);
  *(float *)(this + 0x18) = fVar3 * param_3;
  *(float *)(this + 0x10) = *(float *)(param_1 + 0x10) + param_3 * fVar1;
  *(float *)(this + 0x14) = fVar2 * param_3 + *(float *)(param_1 + 0x14);
  *(float *)(this + 0x18) = fVar3 * param_3 + *(float *)(param_1 + 0x18);
  GmQuat::SetSlerp((GmQuat *)this, *(float *)param_1, *(float *)(param_1 + 4),
                   *(float *)(param_1 + 8), *(float *)(param_1 + 0xc),
                   (float *)param_2, param_3);
  return;
}
