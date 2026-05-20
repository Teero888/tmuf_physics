// Class implementation: CScene2d

// =================================================
// Function: CScene2d::CScene2d
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CScene2d::CScene2d(CScene2d *this,CScene2d *param_1)
{
{
  undefined4 uVar1;
  CScene *unaff_ESI;
  
  CScene::CScene((CScene *)this,unaff_ESI);
  uVar1 = _DAT_00b2c060;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xa8) = uVar1;
  *(undefined4 *)(this + 0xac) = uVar1;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xb0) = 0x3f800000;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xb4) = 0x3f800000;
  return;
}
}

// =================================================
// Function: CScene2d::CreateOverlay
// =================================================
void __thiscall CScene2d::CreateOverlay(CScene2d *this,CScene2d *param_1,GmRectAligned *param_2)
{
{
  CSceneSector *pCVar1;
  CSceneSector *this_00;
  CMwNod *extraout_EAX;
  CSceneSector *extraout_EAX_00;
  CMwNod *this_01;
  CMwNod *unaff_EDI;
  CHmsZoneOverlay *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acb796;
  local_c = ExceptionList;
  pCVar1 = (CSceneSector *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  if (*(int *)(this + 0xa4) == 0) {
    this_00 = operator_new(0x3c);
    local_4 = (void *)0x0;
    if (this_00 == (CSceneSector *)0x0) {
      this_01 = (CMwNod *)0x0;
    }
    else {
      CSceneSector::CSceneSector(this_00,pCVar1);
      this_01 = extraout_EAX;
    }
    if (this_01 != *(CMwNod **)(this + 0xa4)) {
      if (this_01 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_01,unaff_EDI);
      }
      if (*(CMwNod **)(this + 0xa4) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0xa4),unaff_EDI);
      }
      *(CMwNod **)(this + 0xa4) = this_01;
    }
    *(CScene2d **)(*(int *)(this + 0xa4) + 0x14) = this;
  }
  local_c = operator_new(0x18c);
  if (local_c == (CHmsZoneOverlay *)0x0) {
    pCVar1 = (CSceneSector *)0x0;
  }
  else {
    CHmsZoneOverlay::CHmsZoneOverlay(local_c,(CHmsZoneOverlay *)unaff_EDI);
    pCVar1 = extraout_EAX_00;
  }
  *(undefined4 *)(pCVar1 + 0x13c) = *(undefined4 *)param_2;
  *(undefined4 *)(pCVar1 + 0x140) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(pCVar1 + 0x144) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(pCVar1 + 0x148) = *(undefined4 *)(param_2 + 0xc);
  SetZone(this,pCVar1,(CHmsZone *)unaff_EDI);
  *(undefined4 *)(this + 0xa8) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0xac) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + 0xb4) = *(undefined4 *)(param_2 + 0xc);
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CScene2d::SetVisible
// =================================================
void __thiscall CScene2d::SetVisible(CScene2d *this,CScene2d *param_1,int param_2)
{
{
  *(CScene2d **)(*(int *)(this + 0xa0) + 0x18) = param_1;
  return;
}
}

// =================================================
// Function: CScene2d::SetVisibleInterface
// =================================================
void __cdecl CScene2d::SetVisibleInterface(CScene2d *param_1,int param_2)
{
{
  CScene2d *this;
  CScene2d *this_00;
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  code *pcVar5;
  CFastStringInt *unaff_EDI;
  CScene2d *in_stack_0000000c;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  this_00 = param_1;
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acb7f8;
  local_c = ExceptionList;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  if (param_1 != (CScene2d *)0x0) {
    CVar1 = CMwId::CreateFromLocalName((char *)&param_1);
    this = this_00 + 0x14;
    local_4 = (void *)0x0;
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CGameCtnCampaign*>::GetNodIndexFromId
                       (this,(CFastBuffer<class_CGameCtnCampaign*> *)CONCAT31(extraout_var,CVar1),
                        pCVar2);
    OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this,pCVar3,(ulong)unaff_EDI);
      if (in_stack_0000000c == (CScene2d *)0x0) {
        pcVar5 = *(code **)(**(int **)pSVar4 + 0x104);
      }
      else {
        pcVar5 = *(code **)(**(int **)pSVar4 + 0x100);
      }
      unaff_EDI = (CFastStringInt *)0x7b247d;
      (*pcVar5)();
    }
    SetVisible(this_00,in_stack_0000000c,(int)unaff_EDI);
  }
  ExceptionList = local_4;
  return;
}
}

