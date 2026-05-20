// Class implementation: CMwParam

// =================================================
// Function: CMwParam::IsIndexed
// =================================================
int __thiscall CMwParam::IsIndexed(CMwParam *this,CMwParam *param_1)
{
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)this + 0x78))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)this + 0x7c))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)this + 0x80))();
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)this + 0x84))();
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  return 1;
}
}

