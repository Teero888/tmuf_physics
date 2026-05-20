// Class implementation: CTrackManiaPlayerInfo

// =================================================
// Function: CTrackManiaPlayerInfo::CTrackManiaPlayerInfo
// =================================================
void __thiscall
CTrackManiaPlayerInfo::CTrackManiaPlayerInfo
          (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  CTrackManiaPlayerInfo *this_00;
  CMwId CVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  int unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CMwId *pCVar2;
  CFastStringInt *in_stack_00000008;
  CFastStringInt *in_stack_0000000c;
  CFastStringInt *in_stack_00000010;
  char *in_stack_00000014;
  SInputActionDesc *in_stack_00000018;
  char *in_stack_0000001c;
  char *in_stack_00000020;
  CFastStringInt *in_stack_00000024;
  char cStack00000028;
  undefined3 uStack00000029;
  char cStack0000002c;
  char cStack00000030;
  char cStack00000034;
  char cStack00000038;
  undefined1 uStack0000003c;
  undefined1 uStack00000040;
  undefined1 uStack00000044;
  undefined3 uStack00000045;
  undefined1 uStack00000048;
  undefined1 uStack0000004c;
  CTrackManiaPlayerInfo *in_stack_ffffffec;
  CTrackManiaPlayerInfo *pCVar3;
  GmMat43 *pGVar4;
  CTrackManiaPlayerInfo *pCVar5;
  GmFrustumIso4 *pGVar6;
  
  pGVar6 = (GmFrustumIso4 *)0xffffffff;
  pCVar5 = (CTrackManiaPlayerInfo *)&LAB_00a8bbbc;
  pGVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CGamePlayerInfo::CGamePlayerInfo
            ((CGamePlayerInfo *)this,(CGamePlayerInfo *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  pCVar2 = (CMwId *)0x0;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x2f8,unaff_EDI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x300,unaff_ESI);
  *(undefined4 *)(this + 0x30c) = 0;
  *(undefined **)(this + 0x310) = PTR_DAT_00bbf7dc;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x324,unaff_EBP);
  this_00 = this + 0x350;
  in_stack_0000000c = (CFastStringInt *)CONCAT31(in_stack_0000000c._1_3_,4);
  CInputEventsStore::CInputEventsStore(this_00,(CInputEventsStore *)0x0,1,unaff_EBX);
  *(undefined4 *)(this + 0x3a0) = 0;
  *(undefined **)(this + 0x3a4) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x3a8) = 0;
  *(undefined **)(this + 0x3ac) = PTR_DAT_00bbf7dc;
  in_stack_00000010 = (CFastStringInt *)CONCAT31(in_stack_00000010._1_3_,6);
  *(undefined4 *)(this + 0x240) = 0;
  *(undefined4 *)(this + 0x318) = 0;
  *(undefined4 *)(this + 0x348) = 0;
  *(undefined4 *)(this + 0x34c) = 0;
  *(undefined4 *)(this + 0x2ac) = 0xffffffff;
  *(undefined4 *)(this + 0x2b8) = 0xffffffff;
  *(undefined4 *)(this + 0x2a4) = 0xffffffff;
  *(undefined4 *)(this + 0x2e4) = 0;
  *(undefined4 *)(this + 0x330) = 0;
  *(undefined4 *)(this + 0x334) = 0;
  *(undefined4 *)(this + 0x2cc) = 0;
  ResetPerformance(this,in_stack_ffffffec);
  *(undefined4 *)(this + 0x314) = 2;
  GmIso4::SetIdentity(this + 0x274,(GmMat43 *)pCVar3);
  GmIso4::SetIdentity(this + 0x244,pGVar4);
  *(undefined4 *)(this + 800) = 0;
  *(undefined4 *)(this + 0x238) = 0;
  *(undefined4 *)(this + 0x308) = 0;
  *(undefined4 *)(this + 0x31c) = 0;
  *(undefined4 *)(this + 0x2c4) = 0;
  *(undefined4 *)(this + 0x2d4) = 0;
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  *(undefined4 *)(this + 0x344) = 0;
  *(undefined4 *)(this + 0x2f0) = 0xffffffff;
  *(undefined4 *)(this + 0x2f4) = 0xffffffff;
  *(undefined4 *)(this + 0x2e8) = 0;
  ResetAverageRank(this,pCVar5);
  SRpcPlayerQuickInfo::Reset(this + 0x39c,pGVar6);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000014);
  in_stack_00000024 = (CFastStringInt *)CONCAT31(in_stack_00000024._1_3_,7);
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f70,
             (SInputActionDesc *)CONCAT31(extraout_var,CVar1),pCVar2);
  cStack00000028 = '\x06';
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_1);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000018);
  _cStack00000028 = (CFastStringInt *)CONCAT31(uStack00000029,8);
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f74,
             (SInputActionDesc *)CONCAT31(extraout_var_00,CVar1),(CMwId *)param_1);
  cStack0000002c = '\x06';
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000008);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x0000001c);
  cStack0000002c = '\t';
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f78,
             (SInputActionDesc *)CONCAT31(extraout_var_01,CVar1),(CMwId *)in_stack_00000008);
  cStack00000030 = '\x06';
  OnAccessViolation_ConcatToCrashFileName(in_stack_0000000c);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000020);
  cStack00000030 = '\n';
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f68,
             (SInputActionDesc *)CONCAT31(extraout_var_02,CVar1),(CMwId *)in_stack_0000000c);
  cStack00000034 = '\x06';
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000010);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000024);
  cStack00000034 = '\v';
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f64,
             (SInputActionDesc *)CONCAT31(extraout_var_03,CVar1),(CMwId *)in_stack_00000010);
  cStack00000038 = '\x06';
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_00000014);
  CVar1 = CMwId::CreateFromLocalName(&stack0x00000028);
  cStack00000038 = '\f';
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f6c,
             (SInputActionDesc *)CONCAT31(extraout_var_04,CVar1),(CMwId *)in_stack_00000014);
  uStack0000003c = 6;
  in_stack_00000014 = (char *)0x4afd1b;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_00000018);
  in_stack_00000014 = "Respawn";
  CVar1 = CMwId::CreateFromLocalName(&stack0x0000002c);
  in_stack_00000014 = (char *)CONCAT31(extraout_var_05,CVar1);
  uStack0000003c = 0xd;
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f60,(SInputActionDesc *)in_stack_00000014,
             (CMwId *)in_stack_00000018);
  uStack00000040 = 6;
  in_stack_00000018 = (SInputActionDesc *)0x4afd4f;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_0000001c);
  in_stack_00000014 = &stack0x00000030;
  in_stack_00000018 = (SInputActionDesc *)&DAT_00b3d550;
  CVar1 = CMwId::CreateFromLocalName(in_stack_00000014);
  in_stack_00000018 = (SInputActionDesc *)CONCAT31(extraout_var_06,CVar1);
  in_stack_00000014 = PTR_DAT_00cd3f7c;
  uStack00000040 = 0xe;
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd3f7c,in_stack_00000018,
             (CMwId *)in_stack_0000001c);
  uStack00000044 = 6;
  in_stack_0000001c = (char *)0x4afd82;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_00000020);
  in_stack_00000018 = (SInputActionDesc *)&stack0x00000034;
  in_stack_0000001c = "_FakeFinishLine";
  in_stack_00000014 = (char *)0x4afd91;
  CVar1 = CMwId::CreateFromLocalName((char *)in_stack_00000018);
  in_stack_0000001c = (char *)CONCAT31(extraout_var_07,CVar1);
  in_stack_00000018 = (SInputActionDesc *)PTR_DAT_00cd400c;
  _uStack00000044 = (void *)CONCAT31(uStack00000045,0xf);
  in_stack_00000014 = (char *)0x4afda8;
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd400c,(SInputActionDesc *)in_stack_0000001c,
             (CMwId *)in_stack_00000020);
  uStack00000048 = 6;
  in_stack_00000020 = (char *)0x4afdb6;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000024);
  in_stack_0000001c = &stack0x00000038;
  in_stack_00000020 = "_FakeIsRaceRunning";
  in_stack_00000018 = (SInputActionDesc *)0x4afdc5;
  CVar1 = CMwId::CreateFromLocalName(in_stack_0000001c);
  in_stack_00000020 = (char *)CONCAT31(extraout_var_08,CVar1);
  in_stack_0000001c = PTR_DAT_00cd4010;
  uStack00000048 = 0x10;
  in_stack_00000018 = (SInputActionDesc *)0x4afddc;
  CInputEventsStore::RegisterInput
            (this_00,(CInputEventsStore *)PTR_DAT_00cd4010,(SInputActionDesc *)in_stack_00000020,
             (CMwId *)in_stack_00000024);
  uStack0000004c = 6;
  in_stack_00000024 = (CFastStringInt *)0x4afdea;
  OnAccessViolation_ConcatToCrashFileName(_cStack00000028);
  ExceptionList = _uStack00000044;
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::ChangeRaceState
// =================================================
void __thiscall
CTrackManiaPlayerInfo::ChangeRaceState
          (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,ulong param_2,
          ERaceState param_3)
{
{
  CPlugVertexStream *unaff_retaddr;
  
  *(ulong *)(this + 0x314) = param_2;
  CGameNetPlayerInfo::SetDirty((CGameNetPlayerInfo *)this,unaff_retaddr,(int)param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::InitBestCheckpoints
// =================================================
void __thiscall
CTrackManiaPlayerInfo::InitBestCheckpoints
          (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  CTrackManiaPlayerInfo *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x300;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar3,(ulong)unaff_ESI);
      *(undefined4 *)pSVar2 = 0xffffffff;
      unaff_ESI = pCVar3;
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar3,unaff_EBX);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(pSVar2 + 4) = 0;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::InitCheckpoints
// =================================================
void __thiscall
CTrackManiaPlayerInfo::InitCheckpoints(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  CTrackManiaPlayerInfo *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x2f8;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar3,(ulong)unaff_ESI);
      *(undefined4 *)pSVar2 = 0xffffffff;
      unaff_ESI = pCVar3;
      pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar3,unaff_EBX);
      pCVar3 = pCVar3 + 1;
      *(undefined4 *)(pSVar2 + 4) = 0;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::IsPureSpectator
// =================================================
int __thiscall
CTrackManiaPlayerInfo::IsPureSpectator(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  if ((((*(int *)(this + 0x88) == 0) && (*(int *)(this + 0x90) != 0)) &&
      (*(int *)(this + 0x6c) == 0)) &&
     (((*(int *)(this + 0x70) == 0 || (*(int *)(this + 0x2b4) != -1)) ||
      (*(int *)(this + 0x2e0) != 0)))) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::ResetAverageRank
// =================================================
void __thiscall
CTrackManiaPlayerInfo::ResetAverageRank(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  *(undefined4 *)(this + 0x2ec) = 0;
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::ResetPerformance
// =================================================
void __thiscall
CTrackManiaPlayerInfo::ResetPerformance(CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1)
{
{
  *(undefined4 *)(this + 0x2a8) = 0xffffffff;
  *(undefined4 *)(this + 0x2b4) = 0xffffffff;
  *(undefined4 *)(this + 0x2c0) = 0xffffffff;
  *(undefined4 *)(this + 0x2c8) = 999;
  *(undefined4 *)(this + 0x2d0) = 0;
  *(undefined4 *)(this + 0x2e0) = 0;
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::SetNbCheckpoints
// =================================================
void __thiscall
CTrackManiaPlayerInfo::SetNbCheckpoints
          (CTrackManiaPlayerInfo *this,CGameCtnGhost *param_1,ulong param_2)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  CTrackManiaPlayerInfo *unaff_retaddr;
  
  CFastArray<struct_CDx9StateBlock::SRenderState>::SetCount
            (this + 0x2f8,(CFastBuffer<class_CSystemFidsFolder*> *)param_1,unaff_EDI);
  CFastArray<struct_CDx9StateBlock::SRenderState>::SetCount
            (this + 0x300,(CFastBuffer<class_CSystemFidsFolder*> *)param_1,unaff_ESI);
  InitCheckpoints(this,unaff_retaddr);
  InitBestCheckpoints(this,(CTrackManiaPlayerInfo *)param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaPlayerInfo::SetSpawnLoc
// =================================================
void __thiscall
CTrackManiaPlayerInfo::SetSpawnLoc
          (CTrackManiaPlayerInfo *this,CTrackManiaPlayerInfo *param_1,GmIso4 *param_2,int param_3)
{
{
  int iVar1;
  CTrackManiaPlayerInfo *pCVar2;
  CTrackManiaPlayerInfo *pCVar3;
  
  pCVar2 = param_1;
  pCVar3 = this + 0x274;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    pCVar3 = pCVar3 + 4;
  }
  if (param_2 != (GmIso4 *)0x0) {
    pCVar2 = this + 0x244;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pCVar2 = *(undefined4 *)param_1;
      param_1 = param_1 + 4;
      pCVar2 = pCVar2 + 4;
    }
  }
  return;
}
}

