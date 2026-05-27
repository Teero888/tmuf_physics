// Class implementation: CPlugVisual3D

// =================================================
// Function: CPlugVisual3D::CPlugVisual3D
// =================================================
void __thiscall
CPlugVisual3D::CPlugVisual3D(CPlugVisual3D *this,CPlugVisual3D *param_1,CPlugVisual3D *param_2)
{
{
  CFastArray<class_CManoeuvre*> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  undefined1 uStack0000000c;
  CPlugVisual3D *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ad891f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CPlugVisual::CPlugVisual
            ((CPlugVisual *)this,(CPlugVisual *)param_1,
             (CPlugVisual *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x78,unaff_EDI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x84,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x8c,unaff_EBX);
  uStack0000000c = 3;
  CFastBuffer<struct_CPlugVisual::SSplit>::CopyFromFastBuffer
            (this + 0x78,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(param_1 + 0x78),
             (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)pCVar1);
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CPlugVisual3D::SetVertices
// =================================================
void __thiscall
CPlugVisual3D::SetVertices
          (CPlugVisual3D *this,CPlugVisual3D *param_1,ulong param_2,GxVertex *param_3)
{
{
  CFastBuffer<class_GxVertex>::SetBuffer
            (this + 0x78,(CFastBuffer<class_GxVertex> *)param_1,param_2,param_3);
  return;
}
}

