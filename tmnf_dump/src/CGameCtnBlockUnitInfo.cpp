// Class implementation: CGameCtnBlockUnitInfo

// =================================================
// Function: CGameCtnBlockUnitInfo::CGameCtnBlockUnitInfo
// =================================================
void __thiscall
CGameCtnBlockUnitInfo::CGameCtnBlockUnitInfo
          (CGameCtnBlockUnitInfo *this,CGameCtnBlockUnitInfo *param_1,GmNat3 param_2,ulong param_3,
          ulong param_4,CGameCtnBlockInfoClip *param_5,CGameCtnBlockInfoClip *param_6,
          CGameCtnBlockInfoClip *param_7,CGameCtnBlockInfoClip *param_8,CGameCtnBlockInfo *param_9)
{
{
  CGameCtnBlockUnitInfo *this_00;
  SCasterCat *pSVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  CMwId *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CMwId *unaff_EBP;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CMwNod *unaff_EDI;
  ulong unaff_retaddr;
  undefined3 in_stack_00000009;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000038;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000048;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000058;
  CGameCtnBlockUnitInfo *pCVar4;
  void *pvVar5;
  undefined1 *puVar6;
  ulong uVar7;
  
  uVar7 = 0xffffffff;
  puVar6 = &LAB_00abd724;
  pvVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar4 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe0),unaff_EDI);
  this_00 = this + 0x20;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this_00,unaff_ESI);
  _param_2 = (CFastBuffer<class_CCrystalFace*> *)CONCAT31(in_stack_00000009,1);
  CMwId::CMwId(this + 0x34,unaff_EBP);
  param_3 = CONCAT31(param_3._1_3_,2);
  CMwId::CMwId(this + 0x44,unaff_EBX);
  param_4 = CONCAT31(param_4._1_3_,3);
  CMwId::CMwId(this + 0x50,(CMwId *)pCVar4);
  *(CGameCtnBlockInfoClip **)(this + 0x28) = param_7;
  *(CGameCtnBlockInfoClip **)(this + 0x2c) = param_8;
  *(undefined4 *)(this + 0x18) = in_stack_0000002c;
  param_5 = (CGameCtnBlockInfoClip *)CONCAT31(param_5._1_3_,4);
  *(CGameCtnBlockInfo **)(this + 0x30) = param_9;
  *(undefined4 *)(this + 0x14) = in_stack_00000028;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)&DAT_00000004,(ulong)pvVar5);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)puVar6);
  *(undefined4 *)pSVar1 = in_stack_00000038;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,uVar7);
  *(undefined4 *)pSVar1 = in_stack_00000040;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,unaff_retaddr);
  *(undefined4 *)pSVar1 = in_stack_00000048;
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,0);
  *(undefined4 *)pSVar1 = in_stack_00000050;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,_param_2);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,param_3);
      if (*(int *)pSVar1 != 0) {
        pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,param_4);
        param_4 = 0x700542;
        CMwNod::MwAddRef(*(CMwNod **)pSVar1,(CMwNod *)param_5);
        param_3 = (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar2);
  }
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x38) = 5;
  *(undefined4 *)(this + 0x40) = in_stack_00000058;
  *(undefined4 *)(this + 0x50) = 0xffffffff;
  ExceptionList = param_9;
  return;
}
}

