// Class implementation: CGameCtnChallenge

// =================================================
// Function: CGameCtnChallenge::GetBlockFromPlayField
// =================================================
CGameCtnBlock * __thiscall
CGameCtnChallenge::GetBlockFromPlayField
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  int iVar1;
  CGameCtnFieldUnit *pCVar2;
  CGameCtnChallenge *this_00;
  CGameCtnBlock *pCVar3;
  
  pCVar3 = (CGameCtnBlock *)0x0;
  iVar1 = IsEditableCoord(this,param_1,param_2);
  if (iVar1 == 0) {
    return (CGameCtnBlock *)0x0;
  }
  pCVar2 = GetFieldUnit(this_00,param_1,param_2);
  if ((pCVar2 != (CGameCtnFieldUnit *)0x0) && (*(int *)(pCVar2 + 4) != 0)) {
    pCVar3 = *(CGameCtnBlock **)(*(int *)(pCVar2 + 4) + 0x14);
  }
  return pCVar3;
}
}

// =================================================
// Function: CGameCtnChallenge::GetBlockUnitFromPlayField
// =================================================
CGameCtnBlockUnit * __thiscall
CGameCtnChallenge::GetBlockUnitFromPlayField
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  CGameCtnFieldUnit *pCVar1;
  
  pCVar1 = GetFieldUnit(this,param_1,param_2);
  if (pCVar1 == (CGameCtnFieldUnit *)0x0) {
    return (CGameCtnBlockUnit *)0x0;
  }
  return *(CGameCtnBlockUnit **)(pCVar1 + 4);
}
}

// =================================================
// Function: CGameCtnChallenge::GetBlockUnitInfoFromPlayField
// =================================================
CGameCtnBlockUnitInfo * __thiscall
CGameCtnChallenge::GetBlockUnitInfoFromPlayField
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  CGameCtnBlockUnit *pCVar1;
  
  pCVar1 = GetBlockUnitFromPlayField(this,param_1,param_2);
  if (pCVar1 == (CGameCtnBlockUnit *)0x0) {
    return (CGameCtnBlockUnitInfo *)0x0;
  }
  return *(CGameCtnBlockUnitInfo **)(pCVar1 + 0x18);
}
}

// =================================================
// Function: CGameCtnChallenge::GetCoordFromPos
// =================================================
void __thiscall
CGameCtnChallenge::GetCoordFromPos
          (CGameCtnChallenge *this,GmField2Base *param_1,GmVec2 *param_2,GmNat2 *param_3)
{
{
  float fVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar2 = *(int *)(this + 0x90);
  fVar1 = *(float *)(iVar2 + 0x7c);
  local_8 = (undefined4)(longlong)ROUND(*(float *)param_2 / fVar1);
  *(undefined4 *)param_1 = local_8;
  local_8 = (undefined4)(longlong)ROUND(*(float *)(param_2 + 4) / *(float *)(iVar2 + 0x80));
  *(undefined4 *)(param_1 + 4) = local_8;
  local_8 = (undefined4)(longlong)ROUND(*(float *)(param_2 + 8) / fVar1);
  *(undefined4 *)(param_1 + 8) = local_8;
  return;
}
}

// =================================================
// Function: CGameCtnChallenge::GetFieldUnit
// =================================================
CGameCtnFieldUnit * __thiscall
CGameCtnChallenge::GetFieldUnit(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  int extraout_ECX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined3 in_stack_00000009;
  ulong in_stack_0000000c;
  ulong uVar5;
  
  uVar5 = in_stack_0000000c;
  iVar1 = IsEditableCoord(this,param_1,param_2);
  if (iVar1 != 0) {
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             (*(int *)(extraout_ECX + 0xb0) * (int)param_1 + in_stack_0000000c);
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(extraout_ECX + 0x14),pCVar4,uVar5);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(*(void **)pSVar2,unaff_EDI);
    if (_param_2 < pCVar3) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(extraout_ECX + 0x14),pCVar4,unaff_ESI);
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (*(void **)pSVar2,_param_2,unaff_EBP);
      return *(CGameCtnFieldUnit **)pSVar2;
    }
  }
  return (CGameCtnFieldUnit *)0x0;
}
}

// =================================================
// Function: CGameCtnChallenge::GetGroundBlock
// =================================================
CGameCtnBlock * __thiscall
CGameCtnChallenge::GetGroundBlock(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  uchar uVar1;
  CGameCtnBlock *pCVar2;
  
  uVar1 = GetZoneHeight(this,param_1,param_2);
  pCVar2 = GetBlockFromPlayField(this,param_1,(GmNat3)(uVar1 + '\x01'));
  if (pCVar2 == (CGameCtnBlock *)0x0) {
    pCVar2 = GetBlockFromPlayField(this,param_1,(GmNat3)0x0);
  }
  return pCVar2;
}
}

// =================================================
// Function: CGameCtnChallenge::GetRealZone
// =================================================
CGameCtnZone * __thiscall
CGameCtnChallenge::GetRealZone(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  CGameCtnBlock *pCVar1;
  CGameCtnZone *pCVar2;
  CGameCtnBlockInfo *in_stack_0000000c;
  
  pCVar1 = GetBlockFromPlayField(this,param_1,(GmNat3)0x0);
  pCVar2 = CGameCtnCollection::GetZoneFromLandBlockInfo
                     (*(CGameCtnCollection **)(this + 0x90),*(CGameCtnCollection **)(pCVar1 + 0x24),
                      in_stack_0000000c);
  return pCVar2;
}
}

// =================================================
// Function: CGameCtnChallenge::GetRealZoneId
// =================================================
CMwId * __thiscall
CGameCtnChallenge::GetRealZoneId(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  CGameCtnZone *pCVar1;
  
  pCVar1 = GetRealZone(this,param_1,param_2);
  return (CMwId *)(pCVar1 + 0x14);
}
}

// =================================================
// Function: CGameCtnChallenge::GetStartLine
// =================================================
CGameCtnBlock * __thiscall
CGameCtnChallenge::GetStartLine(CGameCtnChallenge *this,CGameCtnChallenge *param_1,ulong param_2)
{
{
  CGameCtnChallenge *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CGameCtnChallenge *extraout_EDX;
  CGameCtnBlock *unaff_EBX;
  CGameCtnChallenge *unaff_EBP;
  CGameCtnChallenge *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  int in_stack_00000014;
  
  this_00 = this + 0x54;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = *(CGameCtnChallenge **)pSVar2;
      iVar3 = IsStartBlock(this,unaff_ESI,(CGameCtnBlock *)unaff_EBP);
      if (iVar3 == 0) {
        unaff_ESI = (CGameCtnChallenge *)0x5ac516;
        unaff_EBP = extraout_EDX;
        iVar3 = IsStartFinishBlock(this,extraout_EDX,unaff_EBX);
        if (iVar3 != 0) goto LAB_005ac51a;
      }
      else {
LAB_005ac51a:
        if (in_stack_00000014 == 0) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar4,unaff_retaddr);
          return *(CGameCtnBlock **)pSVar2;
        }
        in_stack_00000014 = in_stack_00000014 + -1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return (CGameCtnBlock *)0x0;
}
}

// =================================================
// Function: CGameCtnChallenge::GetVehicleIdent
// =================================================
SGameCtnIdentifier * __thiscall
CGameCtnChallenge::GetVehicleIdent(CGameCtnChallenge *this,CGameCtnChallenge *param_1)
{
{
  SGameCtnIdentifier *this_00;
  CFastString CVar1;
  int *piVar2;
  undefined3 extraout_var;
  int extraout_EAX;
  undefined1 *puVar3;
  CGameCtnChapter *pCVar4;
  bool bVar5;
  CGameCtnChallenge *unaff_ESI;
  int *unaff_EDI;
  CTrackManiaEditorIconPage local_1c [3];
  char local_19;
  char *local_14;
  undefined1 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9cd99;
  local_c = ExceptionList;
  piVar2 = (int *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  bVar5 = false;
  this_00 = (SGameCtnIdentifier *)(this + 0xe8);
  if (*(int *)this_00 != -1) {
    local_14 = "Unassigned";
    local_10 = &DAT_0000000a;
    CVar1 = CMwId::GetName(this_00,local_1c);
    local_4 = (void *)0x0;
    bVar5 = true;
    CFastString::Compare
              ((CFastString *)CONCAT31(extraout_var,CVar1),(SParam_Fids *)&local_14,(SParam *)0x0,
               piVar2,unaff_EDI);
    local_19 = '\0';
    if (extraout_EAX != 0) goto LAB_005a659e;
  }
  local_19 = '\x01';
LAB_005a659e:
  if ((bVar5) && (local_10 != PTR_DAT_00bbf7d8)) {
    puVar3 = local_10 + -1;
    if ((local_10[-1] & 0x80) != 0) {
      puVar3 = local_10 + -4;
    }
    operator_delete__(puVar3);
    local_14 = (char *)0x0;
    local_10 = PTR_DAT_00bbf7d8;
  }
  if (local_19 == '\0') {
    ExceptionList = local_4;
    return this_00;
  }
  pCVar4 = *(CGameCtnChapter **)(this + 0x90);
  if ((pCVar4 == (CGameCtnChapter *)0x0) &&
     (pCVar4 = GetChapter(this,unaff_ESI), pCVar4 == (CGameCtnChapter *)0x0)) {
    ExceptionList = local_4;
    return this_00;
  }
  ExceptionList = local_4;
  return (SGameCtnIdentifier *)(pCVar4 + 0x60);
}
}

// =================================================
// Function: CGameCtnChallenge::GetZone
// =================================================
CGameCtnZone * __thiscall
CGameCtnChallenge::GetZone(CGameCtnChallenge *this,CGameCtnCollection *param_1,CMwId *param_2)
{
{
  CGameCtnCollection *this_00;
  CMwId *pCVar1;
  CGameCtnZone *pCVar2;
  CMwId *in_stack_0000000c;
  
  this_00 = *(CGameCtnCollection **)(this + 0x90);
  pCVar1 = GetZoneId(this,(CGameCtnChallenge *)param_1,SUB41(param_2,0));
  pCVar2 = CGameCtnCollection::GetZone(this_00,(CGameCtnCollection *)pCVar1,in_stack_0000000c);
  return pCVar2;
}
}

// =================================================
// Function: CGameCtnChallenge::GetZoneHeight
// =================================================
uchar __thiscall
CGameCtnChallenge::GetZoneHeight(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  int in_stack_0000000c;
  
  pSVar1 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                     (this + 0x44,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (*(int *)(this + 0xb0) * (int)param_1 + in_stack_0000000c),unaff_retaddr);
  return (uchar)*pSVar1;
}
}

// =================================================
// Function: CGameCtnChallenge::GetZoneId
// =================================================
CMwId * __thiscall
CGameCtnChallenge::GetZoneId(CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  int in_stack_0000000c;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x3c,
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (*(int *)(this + 0xb0) * (int)param_1 + in_stack_0000000c),unaff_retaddr);
  return (CMwId *)pSVar1;
}
}

// =================================================
// Function: CGameCtnChallenge::IsCheckpointBlock
// =================================================
int __thiscall
CGameCtnChallenge::IsCheckpointBlock
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2)
{
{
  SHeaderCommunity *pSVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined4 local_1c;
  undefined *local_18;
  char *local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00a9d3e8;
  local_c = ExceptionList;
  pSVar1 = (SHeaderCommunity *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  if (*(int *)(param_1 + 0x24) != 0) {
    return (uint)(*(int *)(*(int *)(param_1 + 0x24) + 0x11c) == 2);
  }
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7d8;
  local_4 = 0;
  ExceptionList = &local_c;
  CMwId::GetName(param_1 + 0x14,(CTrackManiaEditorIconPage *)&local_1c);
  if ((*(uint *)(param_1 + 0x60) & 0x4000) == 0) {
    local_14 = "Checkpoint";
    local_10 = 10;
    uVar2 = CFastString::FindFirst((CFastString *)&local_1c,(CFastStringInt *)&local_14,0,1);
    if (uVar2 == 0xffffffff) {
      local_14 = "CheckPoint";
      local_10 = 10;
      uVar2 = CFastString::FindFirst((CFastString *)&local_1c,(CFastStringInt *)&local_14,0,1);
      if (uVar2 == 0xffffffff) goto LAB_005ac6ec;
    }
    SHeaderCommunity::~SHeaderCommunity(&local_1c,pSVar1);
    ExceptionList = local_8;
    return 1;
  }
LAB_005ac6ec:
  if (local_18 != PTR_DAT_00bbf7d8) {
    puVar3 = local_18 + -1;
    if ((local_18[-1] & 0x80) != 0) {
      puVar3 = local_18 + -4;
    }
    operator_delete__(puVar3);
  }
  ExceptionList = local_c;
  return 0;
}
}

// =================================================
// Function: CGameCtnChallenge::IsEditableCoord
// =================================================
int __thiscall
CGameCtnChallenge::IsEditableCoord
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,GmNat3 param_2)
{
{
  undefined3 in_stack_00000009;
  uint in_stack_0000000c;
  
  if (((param_1 < *(CGameCtnChallenge **)(this + 0xa8)) &&
      (in_stack_0000000c < *(uint *)(this + 0xb0))) && (_param_2 < *(uint *)(this + 0xac))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CGameCtnChallenge::IsStartBlock
// =================================================
int __thiscall
CGameCtnChallenge::IsStartBlock
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2)
{
{
  return (uint)(*(int *)(*(int *)(param_1 + 0x24) + 0x11c) == 0);
}
}

// =================================================
// Function: CGameCtnChallenge::IsStartFinishBlock
// =================================================
int __thiscall
CGameCtnChallenge::IsStartFinishBlock
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,CGameCtnBlock *param_2)
{
{
  return (uint)(*(int *)(*(int *)(param_1 + 0x24) + 0x11c) == 4);
}
}

// =================================================
// Function: CGameCtnChallenge::SetIsBlockHelpers
// =================================================
void __thiscall
CGameCtnChallenge::SetIsBlockHelpers
          (CGameCtnChallenge *this,CGameCtnChallenge *param_1,int param_2,int param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CPlugTree *pCVar3;
  int iVar4;
  uint uVar5;
  SVolatileTreePointer *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if ((*(CGameCtnChallenge **)(this + 0xd4) != param_1) || (*(int *)(this + 0xd8) != param_2)) {
    *(int *)(this + 0xd8) = param_2;
    *(CGameCtnChallenge **)(this + 0xd4) = param_1;
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x54,unaff_EDI);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x54,pCVar6,unaff_EBP);
        if (*(CSceneMobil **)(*(int *)pSVar2 + 0x44) != (CSceneMobil *)0x0) {
          pCVar3 = CSceneMobil::GetTree(*(CSceneMobil **)(*(int *)pSVar2 + 0x44),unaff_EBX);
          unaff_EBX = DAT_00d69aec;
          iVar4 = (**(code **)(*(int *)pCVar3 + 0xb4))();
          if (iVar4 != 0) {
            uVar5 = ((uint)(*(int *)(this + 0xd4) != 0) << 0xe ^ *(uint *)(iVar4 + 0x9c)) & 0x4000 ^
                    *(uint *)(iVar4 + 0x9c);
            *(uint *)(iVar4 + 0x9c) = (uVar5 >> 0xb ^ uVar5) & 8 ^ uVar5;
          }
          unaff_EBP = DAT_00d69af0;
          iVar4 = (**(code **)(*(int *)pCVar3 + 0xb4))();
          if (iVar4 != 0) {
            uVar5 = ((uint)(*(int *)(this + 0xd8) != 0) << 0xe ^ *(uint *)(iVar4 + 0x9c)) & 0x4000 ^
                    *(uint *)(iVar4 + 0x9c);
            *(uint *)(iVar4 + 0x9c) = (uVar5 >> 0xb ^ uVar5) & 8 ^ uVar5;
          }
          (**(code **)(*(int *)pCVar3 + 0xbc))(0);
        }
        pCVar6 = pCVar6 + 1;
      } while (pCVar6 < pCVar1);
    }
  }
  return;
}
}

// =================================================
// Function: CGameCtnChallenge::SetStartLight
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnChallenge::SetStartLight(CGameCtnChallenge *this,CGameCtnChallenge *param_1,ulong param_2)
{
{
  CFuncPlug *pCVar1;
  float unaff_retaddr;
  
  if (*(int *)(this + 0x1a8) != 0) {
    if (param_1 < (CGameCtnChallenge *)0x2) {
      pCVar1 = (CFuncPlug *)0x0;
    }
    else {
      pCVar1 = _DAT_00b31460;
      if (param_1 != (CGameCtnChallenge *)0x2) {
        pCVar1 = (CFuncPlug *)0x3f800000;
      }
    }
    CMotionCmdBase::SetPhase
              (*(CMotionCmdBase **)(*(int *)(this + 0x1a8) + 0x30),pCVar1,unaff_retaddr);
  }
  return;
}
}

