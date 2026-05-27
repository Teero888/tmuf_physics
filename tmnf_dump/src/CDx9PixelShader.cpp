// Class implementation: CDx9PixelShader

// =================================================
// Function: CDx9PixelShader::UndirtyAndSetPixelShader
// =================================================
void __thiscall CDx9PixelShader::UndirtyAndSetPixelShader(void *this,CDx9PixelShader *param_1)
{
{
  int iVar1;
  CDx9VStreamKeeper *unaff_EDI;
  int iVar2;
  
  iVar2 = 0x9045000;
  iVar1 = (**(code **)(**(int **)((int)this + 4) + 0x10))();
  if ((iVar1 != 0) && (iVar1 = *(int *)((int)this + 4), *(int *)(iVar1 + 200) != 0)) {
    Release(this,unaff_EDI);
    *(undefined4 *)(iVar1 + 200) = 0;
  }
  if ((*(int *)this == 0) && (*(int *)((int)this + 8) != 0)) {
    Compile(this,(CDx9PixelShader *)0x1,iVar2);
  }
  (**(code **)(*DAT_00d75680 + 0x1ac))(DAT_00d75680,*(undefined4 *)this);
  return;
}
}

