// Class implementation: CFastBufferRef_class_CPlugShaderApply

// =================================================
// Function: CFastBufferRef<class_CPlugShaderApply>::AddPtr
// =================================================
void __thiscall
CFastBufferRef<class_CPlugShaderApply>::AddPtr
          (void *this,CFastBufferRef<class_CGameTournament> *param_1,CGameTournament *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  CMwNod *this_00;
  CMwNod *unaff_EBP;
  CMwNod *unaff_ESI;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 4);
  if (param_2 != *(CGameTournament **)(*(int *)((int)this + 4) + *(int *)this * 4)) {
    if (param_2 != (CGameTournament *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_2,unaff_ESI);
    }
    this_00 = (CMwNod *)*puVar1;
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwRelease(this_00,unaff_EBP);
    }
    *puVar1 = param_2;
  }
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1);
  return;
}
}

