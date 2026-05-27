// Class implementation: CTrackManiaControlScores

// =================================================
// Function: CTrackManiaControlScores::CanTakeScore
// =================================================
int __thiscall
CTrackManiaControlScores::CanTakeScore
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CTrackManiaRaceScore *param_2)
{
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x54);
  bVar3 = iVar1 == 0;
  if ((bVar3) || (*(int *)(iVar1 + 0x6c) == 0)) {
    if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x18) == -1)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((((*(int *)(this + 0x164) == 0) || (bVar3)) || (*(int *)(iVar1 + 0x314) == 2)) &&
       ((*(int *)(this + 0x160) != 0 || ((bVar2 && ((bVar3 || (*(int *)(iVar1 + 0x70) == 0)))))))) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaControlScores::CanTakeScore_Teams
// =================================================
int __thiscall
CTrackManiaControlScores::CanTakeScore_Teams
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CTrackManiaRaceScore *param_2,uchar param_3)
{
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0x54);
  bVar3 = iVar1 == 0;
  if (!bVar3) {
    if (*(int *)(iVar1 + 0x6c) != 0) {
      return 0;
    }
    if (*(uint *)(iVar1 + 0x240) != ((uint)param_2 & 0xff)) {
      return 0;
    }
    if ((*(int *)(iVar1 + 0x2a8) != 0) && (*(int *)(iVar1 + 0x2a8) != -1)) {
      bVar2 = true;
      goto LAB_004ae7e6;
    }
  }
  bVar2 = false;
LAB_004ae7e6:
  if ((((*(int *)(this + 0x164) == 0) || (bVar3)) || (*(int *)(iVar1 + 0x314) == 2)) &&
     ((*(int *)(this + 0x160) != 0 || ((bVar2 && ((bVar3 || (*(int *)(iVar1 + 0x70) == 0)))))))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaControlScores::LoadGridPage
// =================================================
void __thiscall
CTrackManiaControlScores::LoadGridPage
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CGameControlGridCard *param_2,ulong param_3)
{
{
  if ((param_1 != (CTrackManiaControlScores *)0x0) &&
     (param_2 != (CGameControlGridCard *)0xffffffff)) {
                    /* WARNING: Could not recover jumptable at 0x00449c05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1 + 0x240))();
    return;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::SaveGridPage
// =================================================
void __thiscall
CTrackManiaControlScores::SaveGridPage
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CGameControlGridCard *param_2,ulong *param_3)
{
{
  undefined4 uVar1;
  
  *(undefined4 *)param_2 = 0xffffffff;
  if (param_1 != (CTrackManiaControlScores *)0x0) {
    uVar1 = (**(code **)(*(int *)param_1 + 0x228))();
    *(undefined4 *)param_2 = uVar1;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::SetFilteredScores
// =================================================
void __thiscall
CTrackManiaControlScores::SetFilteredScores
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CFastBuffer<class_CTrackManiaRaceScore*> *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  TiXmlAttributeSet *unaff_EBX;
  CTrackManiaControlScores *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  TiXmlAttributeSet *unaff_retaddr;
  void *in_stack_0000000c;
  CTrackManiaControlScores *in_stack_00000014;
  CTrackManiaControlScores *in_stack_00000018;
  
  if ((*(int *)(this + 0x174) == 3) && (*(int *)(this + 0x168) == 0)) {
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x19c,unaff_EDI);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x1a8,unaff_ESI);
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (in_stack_0000000c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (in_stack_0000000c,pCVar4,(ulong)unaff_EBX);
        in_stack_00000014 = *(CTrackManiaControlScores **)pSVar2;
        unaff_EBX = (TiXmlAttributeSet *)0x0;
        iVar3 = CanTakeScore_Teams(this,in_stack_00000014,(CTrackManiaRaceScore *)0x0,
                                   (uchar)unaff_retaddr);
        if (iVar3 != 0) {
          unaff_retaddr = (TiXmlAttributeSet *)&stack0x00000018;
          unaff_EBX = (TiXmlAttributeSet *)0x44ab6c;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this + 0x1a8,unaff_retaddr,(TiXmlAttribute *)param_1);
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (in_stack_0000000c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (in_stack_0000000c,pCVar4,(ulong)unaff_retaddr);
        in_stack_00000018 = *(CTrackManiaControlScores **)pSVar2;
        unaff_retaddr = (TiXmlAttributeSet *)0x1;
        iVar3 = CanTakeScore_Teams(this,in_stack_00000018,(CTrackManiaRaceScore *)0x1,(uchar)param_1
                                  );
        if (iVar3 != 0) {
          param_1 = (CTrackManiaControlScores *)&stack0x0000001c;
          unaff_retaddr = (TiXmlAttributeSet *)0x44abb2;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this + 0x19c,(TiXmlAttributeSet *)param_1,(TiXmlAttribute *)param_2);
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
      return;
    }
  }
  else {
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x17c,unaff_EDI);
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (param_2,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_2,pCVar4,(ulong)unaff_EBP);
        unaff_EBP = *(CTrackManiaControlScores **)pSVar2;
        iVar3 = CanTakeScore(this,unaff_EBP,(CTrackManiaRaceScore *)unaff_EBX);
        if (iVar3 != 0) {
          unaff_EBX = (TiXmlAttributeSet *)&stack0x00000014;
          unaff_EBP = (CTrackManiaControlScores *)0x44ac0a;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this + 0x17c,unaff_EBX,(TiXmlAttribute *)unaff_retaddr);
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::SetScores
// =================================================
void __thiscall
CTrackManiaControlScores::SetScores
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CFastBuffer<class_CTrackManiaRaceScore*> *param_2)
{
{
  CFastBuffer<class_CTrackManiaRaceScore*> *unaff_EBX;
  ulong *unaff_EBP;
  ulong *unaff_ESI;
  ulong *unaff_EDI;
  CTrackManiaControlScores *in_stack_00000010;
  CTrackManiaControlScores *pCVar1;
  ulong uVar2;
  CTrackManiaControlScores *pCVar3;
  
  SaveGridPage(this,*(CTrackManiaControlScores **)(this + 0x18c),
               (CGameControlGridCard *)(this + 0x1d0),unaff_EDI);
  SaveGridPage(this,*(CTrackManiaControlScores **)(this + 0x1bc),
               (CGameControlGridCard *)(this + 0x1d4),unaff_ESI);
  SaveGridPage(this,*(CTrackManiaControlScores **)(this + 0x1c0),
               (CGameControlGridCard *)(this + 0x1d8),unaff_EBP);
  SetFilteredScores(this,in_stack_00000010,unaff_EBX);
  UpdateGrid(this,*(CGameCtnEditor **)(this + 0x18c));
  pCVar3 = this + 0x19c;
  UpdateGrid(this,*(CGameCtnEditor **)(this + 0x1bc));
  uVar2 = 1;
  pCVar1 = this + 0x1a8;
  UpdateGrid(this,*(CGameCtnEditor **)(this + 0x1c0));
  LoadGridPage(this,*(CTrackManiaControlScores **)(this + 0x18c),
               *(CGameControlGridCard **)(this + 0x1d0),(ulong)pCVar1);
  LoadGridPage(this,*(CTrackManiaControlScores **)(this + 0x1bc),
               *(CGameControlGridCard **)(this + 0x1d4),uVar2);
  LoadGridPage(this,*(CTrackManiaControlScores **)(this + 0x1c0),
               *(CGameControlGridCard **)(this + 0x1d8),(ulong)pCVar3);
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::SetTeamScores
// =================================================
void __thiscall
CTrackManiaControlScores::SetTeamScores
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1,
          CTrackManiaRaceScore *param_2,CTrackManiaRaceScore *param_3)
{
{
  ulong *unaff_ESI;
  ulong *unaff_EDI;
  undefined4 in_stack_00000010;
  ulong uVar1;
  ulong uVar2;
  
  SaveGridPage(this,*(CTrackManiaControlScores **)(this + 0x1bc),
               (CGameControlGridCard *)(this + 0x1d4),unaff_EDI);
  SaveGridPage(this,*(CTrackManiaControlScores **)(this + 0x1c0),
               (CGameControlGridCard *)(this + 0x1d8),unaff_ESI);
  *(CTrackManiaRaceScore **)(this + 0x194) = param_3;
  *(undefined4 *)(this + 0x198) = in_stack_00000010;
  UpdateGrid(this,*(CGameCtnEditor **)(this + 0x1b4));
  uVar1 = *(ulong *)(this + 0x198);
  uVar2 = 1;
  UpdateGrid(this,*(CGameCtnEditor **)(this + 0x1b8));
  LoadGridPage(this,*(CTrackManiaControlScores **)(this + 0x1bc),
               *(CGameControlGridCard **)(this + 0x1d4),uVar1);
  LoadGridPage(this,*(CTrackManiaControlScores **)(this + 0x1c0),
               *(CGameControlGridCard **)(this + 0x1d8),uVar2);
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::UpdateAsync
// =================================================
void __thiscall
CTrackManiaControlScores::UpdateAsync(CTrackManiaControlScores *this,CInputPortDx8 *param_1)
{
{
  void *this_00;
  int iVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  CFastBuffer<class_CTrackManiaRaceScore*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CTrackManiaRaceScore *unaff_retaddr;
  
  iVar1 = (**(code **)(*(int *)this + 0x108))();
  if ((iVar1 != 0) && (*(int *)(this + 0x178) != 0)) {
    if (*(CTrackManiaControlScores **)(this + 0x16c) != (CTrackManiaControlScores *)0x0) {
      SetScores(this,*(CTrackManiaControlScores **)(this + 0x16c),unaff_ESI);
    }
    if (((*(int *)(this + 0x174) == 3) &&
        (this_00 = *(void **)(this + 0x170), this_00 != (void *)0x0)) &&
       (uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI), 1 < uVar2)) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX);
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)unaff_ESI);
      SetTeamScores(this,*(CTrackManiaControlScores **)pSVar4,*(CTrackManiaRaceScore **)pSVar3,
                    unaff_retaddr);
    }
    *(undefined4 *)(this + 0x178) = 0;
  }
  UpdateGridFocusedScore(this,(CTrackManiaControlScores *)param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::UpdateGrid
// =================================================
void __thiscall
CTrackManiaControlScores::UpdateGrid(CTrackManiaControlScores *this,CGameCtnEditor *param_1)
{
{
  bool bVar1;
  undefined4 unaff_retaddr;
  uint in_stack_0000000c;
  
  if (param_1 != (CGameCtnEditor *)0x0) {
    bVar1 = in_stack_0000000c != (*(int *)(this + 0x174) == 3);
    (**(code **)(*(int *)param_1 + 0x2b0))(0xffffffff,bVar1);
    if (!bVar1) {
      (**(code **)(*(int *)param_1 + 0x2a4))(unaff_retaddr,1);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores::UpdateGridFocusedScore
// =================================================
void __thiscall
CTrackManiaControlScores::UpdateGridFocusedScore
          (CTrackManiaControlScores *this,CTrackManiaControlScores *param_1)
{
{
  int *piVar1;
  int iVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  TiXmlAttribute *pTVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a84bc8;
  local_c = ExceptionList;
  if (*(int *)(this + 400) == 0) {
    return;
  }
  ExceptionList = &local_c;
  if (((*(int *)(this + 0x18c) == 0) ||
      (piVar1 = (int *)(**(code **)(**(int **)(this + 0x18c) + 0x298))
                                 (DAT_00cca150 ^ (uint)&stack0xffffffdc), piVar1 == (int *)0x0)) &&
     ((*(int *)(this + 0x1c0) == 0 ||
      (piVar1 = (int *)(**(code **)(**(int **)(this + 0x1c0) + 0x298))(), piVar1 == (int *)0x0)))) {
    if (*(int *)(this + 0x1bc) == 0) {
      ExceptionList = local_c;
      return;
    }
    piVar1 = (int *)(**(code **)(**(int **)(this + 0x1bc) + 0x298))();
    if (piVar1 == (int *)0x0) {
      ExceptionList = local_c;
      return;
    }
  }
  iVar2 = (**(code **)(*piVar1 + 0x10))(0x240be000);
  if ((iVar2 != 0) && (iVar2 = (**(code **)(*piVar1 + 0x288))(), iVar2 != 0)) {
    pTVar4 = (TiXmlAttribute *)0x0;
    pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)0xffffffff;
    (**(code **)(**(int **)(this + 400) + 0x2b0))();
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&stack0xffffffe0,pCVar3);
    puStack_8 = (undefined1 *)0x0;
    (**(code **)(*piVar1 + 0x288))();
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (auStack_1c,(TiXmlAttributeSet *)&stack0xffffffe0,pTVar4);
    pCVar5 = (CFastBuffer<class_CPlugFileGPUV*> *)0x1;
    (**(code **)(**(int **)(this + 400) + 0x2a4))(auStack_18);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(auStack_1c,pCVar5);
  }
  ExceptionList = local_c;
  return;
}
}

