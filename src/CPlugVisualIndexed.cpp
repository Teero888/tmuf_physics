// Class implementation: CPlugVisualIndexed

// =================================================
// Function: CPlugVisualIndexed::CPlugVisualIndexed
// =================================================
void __thiscall
CPlugVisualIndexed::CPlugVisualIndexed
          (CPlugVisualIndexed *this,CPlugVisualIndexed *param_1,CPlugVisualIndexed *param_2)
{
{
  CMwNod *extraout_EAX;
  CMwNod *unaff_ESI;
  CPlugIndexBuffer *unaff_EDI;
  CMwNod *this_00;
  int in_stack_0000000c;
  CPlugIndexBuffer *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00adb8d1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlugVisual3D::CPlugVisual3D
            ((CPlugVisual3D *)this,(CPlugVisual3D *)param_1,
             (CPlugVisual3D *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x98) = 0;
  local_c = operator_new(0x28);
  if (local_c == (CPlugIndexBuffer *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CPlugIndexBuffer::CPlugIndexBuffer(local_c,unaff_EDI);
    this_00 = extraout_EAX;
  }
  if (this_00 != *(CMwNod **)(this + 0x98)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x98) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x98),unaff_ESI);
    }
    *(CMwNod **)(this + 0x98) = this_00;
  }
  CFastBuffer<unsigned_short>::CopyFromFastBuffer
            ((void *)(*(int *)(this + 0x98) + 0x1c),
             (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)
             (*(int *)(in_stack_0000000c + 0x98) + 0x1c),
             (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)unaff_ESI);
  ExceptionList = (void *)0x2;
  return;
}
}

// =================================================
// Function: CPlugVisualIndexed::SetVerticesAndIndices
// =================================================
void __thiscall
CPlugVisualIndexed::SetVerticesAndIndices
          (CPlugVisualIndexed *this,CPlugVisualIndexed *param_1,ulong param_2,GxVertex *param_3,
          ulong param_4,ushort *param_5)
{
{
  GxVertex *unaff_ESI;
  GxVertex *unaff_retaddr;
  
  CPlugVisual3D::SetVertices((CPlugVisual3D *)this,(CPlugVisual3D *)param_1,param_2,unaff_ESI);
  CFastBuffer<class_GxVertex>::SetBuffer
            ((void *)(*(int *)(this + 0x98) + 0x1c),(CFastBuffer<class_GxVertex> *)param_4,
             (ulong)param_5,unaff_retaddr);
  return;
}
}

