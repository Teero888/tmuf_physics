// Class implementation: CGameNetwork_SBill

// =================================================
// Function: CGameNetwork::SBill::SBill
// =================================================
void __thiscall
CGameNetwork::SBill::SBill
          (void *this,SBill *param_1,CFastString *param_2,CFastString *param_3,
          CFastStringInt *param_4,int param_5)
{
{
  char *pcVar1;
  char *unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 in_stack_0000001c;
  SStringParam *pSVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00aa7041;
  local_c = ExceptionList;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined **)((int)this + 0xc) = PTR_DAT_00bbf7d8;
  local_4 = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  pSVar2 = this;
  CFastString::CFastString((CFastString *)((int)this + 0x18),(CFastString *)param_1,pcVar1);
  CFastString::CFastString((CFastString *)((int)this + 0x20),param_3,unaff_ESI);
  CFastStringInt::CFastStringInt((void *)((int)this + 0x28),(CFastStringInt *)param_5,pSVar2);
  *(undefined4 *)((int)this + 0x30) = in_stack_0000001c;
  ExceptionList = (void *)CONCAT31((int3)((uint)unaff_retaddr >> 8),1);
  return;
}
}

