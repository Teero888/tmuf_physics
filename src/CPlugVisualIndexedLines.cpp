// Class implementation: CPlugVisualIndexedLines

// =================================================
// Function: CPlugVisualIndexedLines::AddNewBox
// =================================================
void __thiscall
CPlugVisualIndexedLines::AddNewBox
          (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1,GmBoxOriented *param_2,
          GxColor *param_3)
{
{
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  GmBoxOriented *pGVar2;
  GxColor *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBuffer<class_CCrystalFace*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)(*(int *)(this + 0x98) + 0x1c),unaff_EDI);
  pGVar2 = (GmBoxOriented *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x78,pCVar1);
  SetBoxAt(this,pGVar2,unaff_ESI,unaff_retaddr,(ulong)param_1);
  return;
}
}

// =================================================
// Function: CPlugVisualIndexedLines::AddNewLine
// =================================================
void __thiscall
CPlugVisualIndexedLines::AddNewLine
          (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1,ushort param_2,
          GmVec3 *param_3,GxColor *param_4,float param_5,float param_6)
{
{
  CPlugVisualIndexedLines *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined2 in_stack_0000000a;
  undefined4 *in_stack_0000001c;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  
  this_00 = this + 0x78;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  CFastBuffer<struct_CPlugVisual::SSplit>::AllocSetCount
            (this_00,(CFastBuffer<class_GxVertex2> *)(pCVar2 + 1),unaff_ESI);
  pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this_00,pCVar2,unaff_EBX);
  *(undefined4 *)pSVar3 = *(undefined4 *)param_5;
  *(undefined4 *)(pSVar3 + 4) = *(undefined4 *)((int)param_5 + 4);
  *(undefined4 *)(pSVar3 + 8) = *(undefined4 *)((int)param_5 + 8);
  pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this_00,pCVar2,unaff_retaddr);
  *(undefined4 *)(pSVar3 + 0x18) = *in_stack_0000001c;
  *(undefined4 *)(pSVar3 + 0x1c) = in_stack_0000001c[1];
  *(undefined4 *)(pSVar3 + 0x20) = in_stack_0000001c[2];
  *(undefined4 *)(pSVar3 + 0x24) = in_stack_0000001c[3];
  pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[](this_00,pCVar2,(ulong)param_1);
  *(undefined4 *)(pSVar3 + 0xc) = in_stack_00000024;
  *(undefined4 *)(pSVar3 + 0x10) = in_stack_00000028;
  *(undefined4 *)(pSVar3 + 0x14) = 0;
  iVar1 = *(int *)(this + 0x98);
  CFastBuffer<unsigned_short>::Add((void *)(iVar1 + 0x1c),(TiXmlAttributeSet *)&param_6,_param_2);
  in_stack_0000001c = (undefined4 *)((uint)pCVar2 & 0xffff);
  CFastBuffer<unsigned_short>::Add
            ((void *)(iVar1 + 0x1c),(TiXmlAttributeSet *)&stack0x0000001c,(TiXmlAttribute *)param_3)
  ;
  return;
}
}

// =================================================
// Function: CPlugVisualIndexedLines::CPlugVisualIndexedLines
// =================================================
void __thiscall
CPlugVisualIndexedLines::CPlugVisualIndexedLines
          (CPlugVisualIndexedLines *this,CPlugVisualIndexedLines *param_1)
{
{
  CPlugVisualIndexed *unaff_ESI;
  CPlugVisualIndexed *unaff_retaddr;
  
  CPlugVisualIndexed::CPlugVisualIndexed((CPlugVisualIndexed *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x9c) = 0;
  return;
}
}

