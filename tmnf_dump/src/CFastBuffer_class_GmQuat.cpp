// Class implementation: CFastBuffer_class_GmQuat

// =================================================
// Function: CFastBuffer<class_GmQuat>::Add
// =================================================
void __thiscall
CFastBuffer<class_GmQuat>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  undefined4 *puVar2;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  CFastBuffer<class_GmInt4>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  puVar2 = (undefined4 *)(*(int *)this * 0x10 + *(int *)((int)this + 4));
  *puVar2 = *(undefined4 *)param_2;
  puVar2[1] = *(undefined4 *)(param_2 + 4);
  puVar2[2] = *(undefined4 *)(param_2 + 8);
  puVar2[3] = *(undefined4 *)(param_2 + 0xc);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GmQuat>::RemoveAt
// =================================================
void __thiscall
CFastBuffer<class_GmQuat>::RemoveAt
          (void *this,CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *param_1,
          ulong param_2,ulong param_3)
{
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = (*(int *)this - (int)param_1) - param_2;
  if (iVar4 != 0) {
    iVar6 = (int)param_1 << 4;
    iVar5 = (int)(param_1 + param_2) * 0x10;
    do {
      iVar2 = *(int *)((int)this + 4);
      iVar1 = iVar5 + iVar2;
      puVar3 = (undefined4 *)(iVar2 + iVar6);
      *puVar3 = *(undefined4 *)(iVar5 + iVar2);
      puVar3[1] = *(undefined4 *)(iVar1 + 4);
      puVar3[2] = *(undefined4 *)(iVar1 + 8);
      iVar5 = iVar5 + 0x10;
      iVar6 = iVar6 + 0x10;
      iVar4 = iVar4 + -1;
      puVar3[3] = *(undefined4 *)(iVar1 + 0xc);
    } while (iVar4 != 0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

