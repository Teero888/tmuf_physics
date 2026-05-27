// Class implementation: CFuncEnum

// =================================================
// Function: CFuncEnum::CFuncEnum
// =================================================
void __thiscall CFuncEnum::CFuncEnum(CFuncEnum *this,CFuncEnum *param_1)
{
{
  CMwId *unaff_ESI;
  CFuncEnum *pCVar1;
  CFastArray<class_CManoeuvre*> *pCVar2;
  
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CFunc::CFunc((CFunc *)this,(CFunc *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x18,(CFastArray<class_CManoeuvre*> *)pCVar1);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x44,pCVar2);
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x24) = 1;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0x3f800000;
  *(undefined4 *)(this + 0x38) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CFuncEnum::SetValue
// =================================================
void __thiscall CFuncEnum::SetValue(CFuncEnum *this,CMwCmdAffectParamBool *param_1)
{
{
  CFuncEnum *this_00;
  CMwCmdAffectParamBool *this_01;
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  ulong unaff_retaddr;
  CMwNod *in_stack_00000008;
  
  this_01 = param_1;
  if (*(int *)(this + 0x20) == 0) {
    if (in_stack_00000008 == (CMwNod *)0xffffffff) {
      CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
                (this + 0x18,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&param_1,
                 (SFormat *)unaff_EDI);
      CMwNod::MwAddRef((CMwNod *)0xffffffff,unaff_ESI);
      return;
    }
  }
  else if (in_stack_00000008 == (CMwNod *)0xffffffff) {
    if (param_1 == (CMwCmdAffectParamBool *)0x0) {
      return;
    }
    CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    CMwNod::MwRelease((CMwNod *)this_01,unaff_ESI);
    return;
  }
  this_00 = this + 0x18;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000008,
                      unaff_EBX);
  if (*(CMwNod **)pSVar1 != in_stack_00000008) {
    if (in_stack_00000008 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(in_stack_00000008,unaff_EDI);
    }
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000008,
                        (ulong)unaff_ESI);
    if (*(int *)pSVar1 != 0) {
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                  in_stack_00000008,unaff_retaddr);
      CMwNod::MwRelease(*(CMwNod **)pSVar1,(CMwNod *)param_1);
    }
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_00000008,
                        (ulong)in_stack_00000008);
    *(CMwNod **)pSVar1 = in_stack_00000008;
  }
  return;
}
}

// =================================================
// Function: CFuncEnum::SetWantedCount
// =================================================
void __thiscall CFuncEnum::SetWantedCount(CFuncEnum *this,CFuncEnum *param_1,ulong param_2)
{
{
  CFuncEnum *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFuncEnum *pCVar3;
  ulong unaff_ESI;
  CFuncEnum *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFuncEnum *unaff_retaddr;
  CFastBuffer<class_CSystemFidsFolder*> *in_stack_0000000c;
  int in_stack_00000010;
  ulong uVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFuncEnum *pCVar7;
  
  *(CFuncEnum **)(this + 0x20) = param_1;
  if (param_1 != (CFuncEnum *)0x0) {
    this_00 = this + 0x18;
    pCVar7 = this;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar3 = this;
    if (param_1 < pCVar1) {
      pCVar4 = param_1;
      do {
        uVar5 = 0x587048;
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,
                            (ulong)unaff_EBX);
        if (*(int *)pSVar2 != 0) {
          pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x587055;
          unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,
                              unaff_ESI);
          unaff_ESI = 0x58705c;
          CMwNod::MwRelease(*(CMwNod **)pSVar2,(CMwNod *)unaff_EBP);
        }
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,uVar5);
        *(undefined4 *)pSVar2 = 0;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x44,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar4,
                            (ulong)pCVar6);
        pCVar4 = pCVar4 + 1;
        *(undefined4 *)pSVar2 = 0xffffffff;
        pCVar3 = unaff_retaddr;
        param_1 = (CFuncEnum *)param_2;
      } while (pCVar4 < pCVar1);
    }
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)param_1,(ulong)unaff_EBX);
    CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
              (pCVar3 + 0x44,in_stack_0000000c,unaff_ESI);
    if (pCVar1 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_2 + 0x20)) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar1,(ulong)unaff_EBP);
        *(undefined4 *)pSVar2 = 0;
        unaff_EBP = pCVar1;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar3 + 0x44,pCVar1,(ulong)pCVar7);
        pCVar1 = pCVar1 + 1;
        *(undefined4 *)pSVar2 = 0xffffffff;
      } while (pCVar1 < *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                         (in_stack_00000010 + 0x20));
    }
  }
  return;
}
}

