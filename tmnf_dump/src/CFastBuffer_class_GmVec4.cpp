// Class implementation: CFastBuffer_class_GmVec4

// =================================================
// Function: CFastBuffer<class_GmVec4>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<class_GmVec4>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  CFastBuffer<class_GmInt4>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GmVec4>::FillWith
// =================================================
void __thiscall
CFastBuffer<class_GmVec4>::FillWith
          (void *this,CFixedArray<unsigned_char,8,unsigned_long> *param_1,uchar *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)this;
  if (iVar3 != 0) {
    iVar2 = 0;
    do {
      puVar1 = (undefined4 *)(*(int *)((int)this + 4) + iVar2);
      *puVar1 = *(undefined4 *)param_1;
      puVar1[1] = *(undefined4 *)(param_1 + 4);
      puVar1[2] = *(undefined4 *)(param_1 + 8);
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
      puVar1[3] = *(undefined4 *)(param_1 + 0xc);
    } while (iVar3 != 0);
  }
  return;
}
}

