// Class implementation: GmLensVal

// =================================================
// Function: GmLensVal::Reset
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GmLensVal::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  undefined4 uVar1;
  
  *(undefined4 *)this = _DAT_00b36190;
  *(undefined4 *)((int)this + 4) = _DAT_00b36154;
  *(undefined4 *)((int)this + 8) = DAT_00b36188;
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0xc) = _DAT_00b2c060;
  *(undefined4 *)((int)this + 0x10) = uVar1;
  return;
}
}

// =================================================
// Function: GmLensVal::SetLinearInterp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GmLensVal::SetLinearInterp
          (void *this,GmLensVal *param_1,GmLensVal *param_2,GmLensVal *param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = 1.0 - (float)param_3;
  *(float *)this = *(float *)param_1 * fVar2 + *(float *)param_2 * (float)param_3;
  *(float *)((int)this + 4) =
       *(float *)(param_1 + 4) * fVar2 + *(float *)(param_2 + 4) * (float)param_3;
  *(float *)((int)this + 8) =
       *(float *)(param_1 + 8) * fVar2 + *(float *)(param_2 + 8) * (float)param_3;
  fVar3 = _DAT_00b2c060;
  if ((_DAT_00b2c060 == *(float *)(param_1 + 0xc)) && (_DAT_00b2c060 == *(float *)(param_2 + 0xc)))
  {
    *(float *)((int)this + 0xc) = _DAT_00b2c060;
  }
  else {
    if ((_DAT_00b2c060 == *(float *)(param_1 + 0xc)) && (_DAT_00b2c060 != *(float *)(param_2 + 0xc))
       ) {
      fVar1 = *(float *)(param_2 + 0xc);
    }
    else if ((_DAT_00b2c060 == *(float *)(param_1 + 0xc)) ||
            (_DAT_00b2c060 != *(float *)(param_2 + 0xc))) {
      fVar1 = *(float *)(param_1 + 0xc) * fVar2 + *(float *)(param_2 + 0xc) * (float)param_3;
    }
    else {
      fVar1 = *(float *)(param_1 + 0xc);
    }
    *(float *)((int)this + 0xc) = fVar1;
  }
  if ((fVar3 == *(float *)(param_1 + 0x10)) && (fVar3 == *(float *)(param_2 + 0x10))) {
    *(float *)((int)this + 0x10) = fVar3;
    return;
  }
  if ((fVar3 == *(float *)(param_1 + 0x10)) && (fVar3 != *(float *)(param_2 + 0x10))) {
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
    return;
  }
  if ((fVar3 != *(float *)(param_1 + 0x10)) && (fVar3 == *(float *)(param_2 + 0x10))) {
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    return;
  }
  *(float *)((int)this + 0x10) =
       fVar2 * *(float *)(param_1 + 0x10) + *(float *)(param_2 + 0x10) * (float)param_3;
  return;
}
}

