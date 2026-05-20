// Class implementation: CFastArray_struct_SGameCtnIdentifier

// =================================================
// Function: CFastArray<struct_SGameCtnIdentifier>::AddTail
// =================================================
void __thiscall
CFastArray<struct_SGameCtnIdentifier>::AddTail
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2)
{
{
  undefined4 *puVar1;
  ulong unaff_ESI;
  
  if (*(int *)this == 0) {
    SetCount(this,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
    puVar1 = *(undefined4 **)((int)this + 4);
    *puVar1 = *(undefined4 *)param_2;
    puVar1[1] = *(undefined4 *)(param_2 + 4);
    puVar1[2] = *(undefined4 *)(param_2 + 8);
    return;
  }
  AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x1,unaff_ESI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + -0xc + *(int *)this * 0xc);
  *puVar1 = *(undefined4 *)param_2;
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  puVar1[2] = *(undefined4 *)(param_2 + 8);
  return;
}
}

// =================================================
// Function: CFastArray<struct_SGameCtnIdentifier>::IsEmpty
// =================================================
int __thiscall CFastArray<struct_SGameCtnIdentifier>::IsEmpty(void *this,SShaderCustom *param_1)
{
{
  return (uint)(*(int *)((int)this + 4) == 0);
}
}

