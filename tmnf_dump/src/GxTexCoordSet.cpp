// Class implementation: GxTexCoordSet

// =================================================
// Function: GxTexCoordSet::Alloc
// =================================================
void __thiscall GxTexCoordSet::Alloc(void *this,GxTexCoordSet *param_1,ulong param_2)
{
{
  void *pvVar1;
  
  pvVar1 = operator_new__(*(int *)(&DAT_00c40e80 + (*(uint *)this & 0xff) * 4) * (int)param_1);
  *(void **)((int)this + 4) = pvVar1;
  return;
}
}

