// Class implementation: CFastBuffer_class_GmReal4_64

// =================================================
// Function: CFastBuffer<class_GmReal4_64>::Add
// =================================================
void __thiscall
CFastBuffer<class_GmReal4_64>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  int iVar2;
  ulong unaff_EDI;
  undefined4 *puVar3;
  
  iVar1 = *(int *)this;
  CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  puVar3 = (undefined4 *)(*(int *)this * 0x20 + *(int *)((int)this + 4));
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

