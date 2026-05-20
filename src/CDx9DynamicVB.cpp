// Class implementation: CDx9DynamicVB

// =================================================
// Function: CDx9DynamicVB::Lock
// =================================================
void __thiscall
CDx9DynamicVB::Lock(void *this,CDx9DynamicVB *param_1,ulong param_2,ulong param_3,uchar **param_4,
                   ulong *param_5)
{
{
  uint uVar1;
  undefined4 uVar2;
  uint *unaff_EBX;
  int iVar3;
  int iVar4;
  
  uVar1 = (*(int *)((int)this + 4) + -1 + param_2) / param_2;
  iVar3 = (int)param_1 * param_2;
  iVar4 = uVar1 * param_2;
  if ((*(int *)((int)this + 0x10) == 0) && ((uint)(iVar4 + iVar3) <= *(uint *)((int)this + 8))) {
    uVar2 = 0x1800;
  }
  else {
    iVar4 = 0;
    uVar1 = 0;
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
    uVar2 = 0x2800;
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  (**(code **)(**(int **)((int)this + 0x14) + 0x2c))
            (*(int **)((int)this + 0x14),iVar4,iVar3,param_3,uVar2);
  *unaff_EBX = uVar1;
  *(int *)((int)this + 4) = iVar4 + iVar3;
  return;
}
}

