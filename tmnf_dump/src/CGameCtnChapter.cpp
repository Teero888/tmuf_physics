// Class implementation: CGameCtnChapter

// =================================================
// Function: CGameCtnChapter::LoadNextMusic
// =================================================
CPlugMusic * __thiscall
CGameCtnChapter::LoadNextMusic
          (CGameCtnChapter *this,CGameCtnChapter *param_1,EDecorationMusic param_2)
{
{
  CGameCtnChapter *this_00;
  int iVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  int iVar4;
  CPlugMusic *extraout_EAX;
  CPlugMusic *pCVar5;
  CPlugMusic *unaff_EDI;
  CMwNod *in_stack_0000000c;
  CPlugMusic *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aad27b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + (int)param_1 * 0x10 + 0xd8;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this_00,(CFastBuffer<class_CCrystalFace*> *)
                             (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  if (uVar2 != 0) {
    iVar1 = *(int *)(this_00 + 0xc);
    iVar4 = iVar1;
    do {
      *(uint *)(this_00 + 0xc) = iVar4 + 1U;
      if (uVar2 <= iVar4 + 1U) {
        *(undefined4 *)(this_00 + 0xc) = 0;
      }
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                   (this_00 + 0xc),(ulong)unaff_EDI);
      in_stack_0000000c = (CMwNod *)0x0;
      if (*(CSystemFid **)pSVar3 != (CSystemFid *)0x0) {
        unaff_EDI = (CPlugMusic *)&DAT_00000007;
        iVar4 = CSystemArchiveNod::LoadFromFid(&stack0x0000000c,*(CSystemFid **)pSVar3,7);
        if ((iVar4 != 0) && (in_stack_0000000c != (CMwNod *)0x0)) {
          unaff_EDI = (CPlugMusic *)0x9030000;
          iVar4 = (**(code **)(*(int *)in_stack_0000000c + 0x10))();
          if (iVar4 != 0) {
            local_c = operator_new(0x78);
            if (local_c == (CPlugMusic *)0x0) {
              pCVar5 = (CPlugMusic *)0x0;
            }
            else {
              CPlugMusic::CPlugMusic(local_c,unaff_EDI);
              pCVar5 = extraout_EAX;
            }
            (**(code **)(*(int *)pCVar5 + 0x4c))();
            if (param_2 != *(EDecorationMusic *)(pCVar5 + 0x18)) {
              if (param_2 != 0) {
                CMwNod::MwAddRef((CMwNod *)param_2,(CMwNod *)unaff_EDI);
              }
              if (*(CMwNod **)(pCVar5 + 0x18) != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)(pCVar5 + 0x18),(CMwNod *)unaff_EDI);
              }
              *(EDecorationMusic *)(pCVar5 + 0x18) = param_2;
            }
            *(int *)(pCVar5 + 0x24) = 0;
            ExceptionList = puStack_8;
            return pCVar5;
          }
        }
      }
      iVar4 = *(int *)(this_00 + 0xc);
    } while (iVar4 != iVar1);
  }
  ExceptionList = puStack_8;
  return (CPlugMusic *)0x0;
}
}

