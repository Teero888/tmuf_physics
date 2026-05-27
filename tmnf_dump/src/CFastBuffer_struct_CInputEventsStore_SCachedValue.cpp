// Class implementation: CFastBuffer_struct_CInputEventsStore_SCachedValue

// =================================================
// Function: CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
// =================================================
void __thiscall
CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  CFastBuffer<class_GmVec3>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 0xc);
  *puVar1 = *(undefined4 *)param_2;
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  puVar1[2] = *(undefined4 *)(param_2 + 8);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1);
  return;
}
}

