// Class implementation: GxBGRAColor

// =================================================
// Function: GxBGRAColor::Set
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GxBGRAColor::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  float fVar1;
  undefined1 local_4;
  
  fVar1 = (float)_DAT_00b55d50;
  local_4 = (undefined1)(int)ROUND(*(float *)param_1 * fVar1);
  *(undefined1 *)((int)this + 2) = local_4;
  local_4 = (undefined1)(int)ROUND(*(float *)(param_1 + 4) * fVar1);
  *(undefined1 *)((int)this + 1) = local_4;
  local_4 = (undefined1)(int)ROUND(*(float *)(param_1 + 8) * fVar1);
  *(undefined1 *)this = local_4;
  param_2._0_1_ = (undefined1)(int)ROUND(fVar1 * (float)param_2);
  *(undefined1 *)((int)this + 3) = (undefined1)param_2;
  return;
}
}

// =================================================
// Function: GxBGRAColor::SetRealRGBA
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
GxBGRAColor::SetRealRGBA
          (void *this,GxBGRAColor *param_1,float param_2,float param_3,float param_4,float param_5)
{
{
  float fVar1;
  undefined1 local_4;
  
  fVar1 = (float)_DAT_00b55d50;
  local_4 = (undefined1)(int)ROUND((float)param_1 * fVar1);
  *(undefined1 *)((int)this + 2) = local_4;
  param_2._0_1_ = (undefined1)(int)ROUND(param_2 * fVar1);
  *(undefined1 *)((int)this + 1) = param_2._0_1_;
  param_2._0_1_ = (undefined1)(int)ROUND(param_3 * fVar1);
  *(undefined1 *)this = param_2._0_1_;
  param_2._0_1_ = (undefined1)(int)ROUND(fVar1 * param_4);
  *(undefined1 *)((int)this + 3) = param_2._0_1_;
  return;
}
}

