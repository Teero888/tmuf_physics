// Class implementation: CControlGrid

// =================================================
// Function: CControlGrid::CControlGrid
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlGrid::CControlGrid(CControlGrid *this,CControlGrid *param_1)
{
{
  undefined4 uVar1;
  CControlContainer *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastArray<class_CManoeuvre*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000010;
  
  CControlContainer::CControlContainer((CControlContainer *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x158,unaff_retaddr);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x160,(CFastArray<class_CManoeuvre*> *)param_1);
  *(undefined4 *)(this + 0x180) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1a0,in_stack_00000008);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x1ac,in_stack_0000000c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1b4,in_stack_00000010);
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 400) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x184) = 1;
  *(undefined4 *)(this + 0x194) = uVar1;
  *(undefined4 *)(this + 0x188) = 0;
  *(undefined4 *)(this + 0x18c) = 0;
  *(undefined4 *)(this + 0x198) = 0;
  *(undefined4 *)(this + 0x19c) = 0;
  return;
}
}

// =================================================
// Function: CControlGrid::SetChildSquare
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CControlGrid::SetChildSquare
          (CControlGrid *this,CControlGrid *param_1,ulong param_2,ulong param_3,ulong param_4)
{
{
  float fVar1;
  SCasterCat *pSVar2;
  CControlGrid *unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this + 0x158,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_EDI);
  fVar1 = (float)(int)param_3;
  if ((int)param_3 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  *(float *)pSVar2 = fVar1;
  pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this + 0x158,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      unaff_ESI);
  *(ulong *)(pSVar2 + 4) = param_3;
  UpdateForceColumnsWidths(this,unaff_EBX);
  return;
}
}

// =================================================
// Function: CControlGrid::UpdateForceColumnsWidths
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlGrid::UpdateForceColumnsWidths(CControlGrid *this,CControlGrid *param_1)
{
{
  CControlGrid *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong *unaff_EDI;
  CFastBuffer<class_GxVertex2> *unaff_retaddr;
  ulong in_stack_fffffff8;
  ulong local_4;
  
  GetSize(this,(CControlGrid *)&stack0xfffffff8,&local_4,unaff_EDI);
  this_00 = this + 0x1a0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  CFastBuffer<float>::AllocSetCount(this_00,unaff_retaddr,unaff_EBX);
  for (; pCVar1 < unaff_retaddr; pCVar1 = pCVar1 + 1) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,pCVar1,in_stack_fffffff8);
    *(undefined4 *)pSVar2 = _DAT_00b2c060;
  }
  return;
}
}

