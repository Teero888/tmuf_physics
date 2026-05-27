// Class implementation: SSceneToyBoat_NetState

// =================================================
// Function: SSceneToyBoat_NetState::ApplyExtrapolatedStateToBoat
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SSceneToyBoat_NetState::ApplyExtrapolatedStateToBoat
          (void *this,SSceneToyBoat_NetState *param_1,CSceneToyBoat *param_2,ulong param_3)
{
{
  SSailManoeuvre SVar1;
  CPlugAudio *this_00;
  CMwId *pCVar2;
  int iVar3;
  SCasterCat *pSVar4;
  int iVar5;
  undefined3 extraout_var;
  CSceneToyBoat *pCVar7;
  CSceneToyBoat *unaff_EBX;
  ulong unaff_ESI;
  undefined4 *puVar8;
  CPlugAudio *unaff_EDI;
  CSceneToyBoat *pCVar9;
  CSceneToyBoat *pCVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  ESailType in_stack_ffffff84;
  float fVar11;
  GmVec3 *pGVar12;
  GmVec3 *pGVar13;
  float in_stack_ffffff90;
  float in_stack_ffffff94;
  GmVec3 *local_58;
  float *local_54;
  undefined4 local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  CSceneToyBoat *local_2c;
  GmMat3 local_28 [8];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  undefined4 local_18 [6];
  int *piVar6;
  
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = CPlugAudio::MwGetId(this_00,unaff_EDI);
  iVar3 = *(int *)pCVar2 - param_3;
  fVar11 = (float)iVar3 * (float)_DAT_00b30a18;
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(param_2 + 0x28) + 0x34),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
  if (*(int *)(*(int *)pSVar4 + 0x58) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x32c) + 0x10;
  }
  local_34 = *(float *)(iVar5 + 4);
  local_30 = *(float *)(iVar5 + 0x10);
  pCVar10 = *(CSceneToyBoat **)(iVar5 + 0x1c);
  local_2c = pCVar10;
  SVar1 = CSceneToyBoat::SailManoeuvreGet(param_2,(CSceneToyBoat *)&local_58);
  piVar6 = (int *)CONCAT31(extraout_var,SVar1);
  if (((*piVar6 == DAT_00d07bcc) && (piVar6[1] == DAT_00d07bd0)) && (piVar6[2] == DAT_00d07bd4)) {
    pCVar9 = *(CSceneToyBoat **)this;
    pCVar7 = (CSceneToyBoat *)CSceneToyBoat::SailTypeCurGet(param_2,unaff_EBX);
  }
  else {
    pCVar9 = *(CSceneToyBoat **)this;
    pCVar7 = (CSceneToyBoat *)CSceneToyBoat::SailTypeAfterManoeuvresGet(param_2,unaff_EBX);
  }
  if (pCVar7 != pCVar9) {
    CSceneToyBoat::SailSwitchTo(param_2,pCVar9,in_stack_ffffff84);
  }
  *(undefined4 *)(param_2 + 0xdc) = *(undefined4 *)((int)this + 0x34);
  *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)((int)this + 0x38);
  *(undefined4 *)(param_2 + 0x11c) = *(undefined4 *)((int)this + 0x38);
  *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)((int)this + 0x3c);
  CSceneToyBoat::GlobalIsAutomaticSheetSet
            (param_2,*(CSceneToyBoat **)((int)this + 0x44),(int)fVar11);
  CSceneToyBoat::GlobalIsFullEaseOutSet(param_2,*(CSceneToyBoat **)((int)this + 0x48),iVar3);
  if ((*(int *)((int)this + 0x44) == 0) && (*(int *)((int)this + 0x48) == 0)) {
    CSceneToyBoat::GlobalSheetTargetNormedAngleSet
              (param_2,*(CSceneToyBoat **)((int)this + 0x40),in_stack_ffffff90);
  }
  local_44 = *(float *)((int)this + 0xc);
  local_48 = *(undefined4 *)((int)this + 0x30);
  local_50 = *(undefined4 *)((int)this + 0x28);
  local_3c = *(float *)((int)this + 0x24);
  local_4c = *(float *)((int)this + 0x2c);
  local_54 = (float *)CSceneToyBoat::RotationRadiusGet
                                (param_2,*(CSceneToyBoat **)((int)this + 0x38),in_stack_ffffff94);
  __CIatan2();
  local_58 = (GmVec3 *)(float)extraout_ST0;
  pGVar13 = *(GmVec3 **)(param_2 + 0xb8);
  pGVar12 = *(GmVec3 **)(param_2 + 0xbc);
  CSceneToyBoat::DeltaMoveGet(param_2,pCVar10,*(float *)((int)this + 0x34),local_54,local_58);
  local_38 = (float)pCVar10 + local_44;
  local_34 = local_40 + (float)_PTR_00b2c178;
  local_30 = (float)local_54 + local_3c;
  GmIso4::SetTranslation(local_20,(GmIso4 *)&local_38,pGVar12);
  __CIsin();
  local_4c = (float)extraout_ST0_00;
  local_48 = 0;
  __CIcos();
  local_44 = (float)extraout_ST0_01;
  GmMat3::SetUpVandDOV(local_1c,local_28,(GmVec3 *)&local_4c,pGVar13);
  puVar8 = local_18;
  pCVar10 = param_2 + 0x204;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pCVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    pCVar10 = pCVar10 + 4;
  }
  *(undefined4 *)(param_2 + 0x200) = 1;
  return;
}
}

// =================================================
// Function: SSceneToyBoat_NetState::RestoreFromBuffer
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SSceneToyBoat_NetState::RestoreFromBuffer
          (void *this,SSceneToyBoat_NetState *param_1,CClassicBufferMemory *param_2,ulong param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  ulong unaff_ESI;
  ulong unaff_EDI;
  void *in_stack_0000001c;
  uint uStack00000020;
  ulong uVar4;
  uint uVar5;
  CClassicArchive *in_stack_ffffffc4;
  int in_stack_ffffffc8;
  int in_stack_ffffffcc;
  uint in_stack_ffffffd0;
  CPlugFileOggVorbis *in_stack_ffffffd4;
  SStreamContext **in_stack_ffffffd8;
  CClassicArchive *in_stack_ffffffdc;
  undefined **local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  CClassicArchive local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ad36b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)&stack0xffffffdc,
             (CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffbc));
  local_20 = CNetArchive::vftable;
  local_14 = 0;
  uVar4 = 0;
  CNetArchive::StartReading((CNetArchive *)&local_20,(CPlugFileOggVorbis *)param_2);
  CClassicArchive::DoReal
            ((CClassicArchive *)&stack0xffffffdc,(CClassicArchive *)((int)this + 0x28),(float *)0x1,
             uVar4);
  CClassicArchive::DoReal
            ((CClassicArchive *)&local_20,(CClassicArchive *)((int)this + 0x2c),(float *)0x1,
             unaff_EDI);
  CClassicArchive::DoReal
            ((CClassicArchive *)&local_1c,(CClassicArchive *)((int)this + 0x30),(float *)0x1,
             unaff_ESI);
  GmQuat::ArchiveGmQuatCompact(&stack0xffffffd8,(GmQuat *)&local_18,in_stack_ffffffc4);
  uVar5 = local_1c;
  GmMat3::Set((void *)((int)this + 4),(CMwCmdScriptVarBool *)in_stack_ffffffdc,(int)local_20);
  CClassicArchive::DoNat8
            ((CClassicArchive *)&local_1c,(CClassicArchive *)&stack0xffffffcc,(uchar *)0x1,0,uVar5);
  *(uint *)((int)this + 0x44) = (byte)((byte)in_stack_ffffffd0 >> 6) & 1;
  *(uint *)this = in_stack_ffffffd0 & 0x3f;
  *(uint *)((int)this + 0x48) = (uint)(byte)((byte)in_stack_ffffffd0 >> 7);
  CClassicArchive::DoNat16
            ((CClassicArchive *)&local_18,(CClassicArchive *)&stack0xffffffd4,(ushort *)0x1,0,
             local_18);
  CClassicArchive::DoNat8
            ((CClassicArchive *)&local_14,(CClassicArchive *)&stack0xffffffd5,(uchar *)0x1,0,
             in_stack_ffffffc8);
  CClassicArchive::DoNat8
            (local_10,(CClassicArchive *)&stack0xffffffda,(uchar *)0x1,0,in_stack_ffffffcc);
  CClassicArchive::DoNat8
            ((CClassicArchive *)&local_c,(CClassicArchive *)&stack0xffffffdf,(uchar *)0x1,0,
             in_stack_ffffffd0);
  uStack00000020 = (uint)local_20 >> 0x18;
  *(float *)((int)this + 0x34) =
       ((float)(local_1c & 0xffff) / (float)_DAT_00b52a58) * (float)_DAT_00b40f30 -
       (float)_DAT_00b40f28;
  fVar3 = (float)_DAT_00b55d50;
  fVar2 = (float)_DAT_00b59bb8;
  fVar1 = (float)_DAT_00b36110;
  *(float *)((int)this + 0x38) = ((float)((uint)local_20 >> 8 & 0xff) / fVar3) * fVar2 - fVar1;
  *(float *)((int)this + 0x3c) = ((float)((uint)local_20 >> 0x10 & 0xff) / fVar3) * fVar2 - fVar1;
  *(float *)((int)this + 0x40) = ((float)uStack00000020 / fVar3) * 1.0 + 0.0;
  CNetArchive::EndReading((CNetArchive *)&local_8,in_stack_ffffffd4,in_stack_ffffffd8);
  uStack00000020 = 0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)&stack0x00000000,in_stack_ffffffdc);
  ExceptionList = in_stack_0000001c;
  return;
}
}

