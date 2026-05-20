// Class implementation: SStringParam

// =================================================
// Function: SStringParam::SStringParam
// =================================================
void __thiscall SStringParam::SStringParam(void *this,SStringParam *param_1,char *param_2)
{
{
  SStringParam *pSVar1;
  SStringParam SVar2;
  
  *(SStringParam **)this = param_1;
  if (param_1 != (SStringParam *)0x0) {
    pSVar1 = param_1 + 1;
    do {
      SVar2 = *param_1;
      param_1 = param_1 + 1;
    } while (SVar2 != (SStringParam)0x0);
    *(int *)((int)this + 4) = (int)param_1 - (int)pSVar1;
    return;
  }
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
}

