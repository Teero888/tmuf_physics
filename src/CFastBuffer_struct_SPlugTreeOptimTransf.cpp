// Class implementation: CFastBuffer_struct_SPlugTreeOptimTransf

// =================================================
// Function: CFastBuffer<struct_SPlugTreeOptimTransf>::Add
// =================================================
void __thiscall
CFastBuffer<struct_SPlugTreeOptimTransf>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  int iVar2;
  TiXmlAttribute *pTVar3;
  ulong unaff_EDI;
  undefined4 *puVar4;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  puVar4 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 0x38);
  *puVar4 = *(undefined4 *)param_2;
  puVar4[1] = *(undefined4 *)(param_2 + 4);
  pTVar3 = param_2 + 8;
  puVar4 = puVar4 + 2;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *(undefined4 *)pTVar3;
    pTVar3 = pTVar3 + 4;
    puVar4 = puVar4 + 1;
  }
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

