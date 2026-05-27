// Class implementation: CGameCtnReplayRecord

// =================================================
// Function: CGameCtnReplayRecord::BuildReplayDefaultFileName
// =================================================
void __thiscall
CGameCtnReplayRecord::BuildReplayDefaultFileName
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,CFastStringInt *param_2,
          int param_3,int param_4,CFastString *param_5)
{
{
  SStringParam *pSVar1;
  int iVar2;
  CFastString *pCVar3;
  undefined *puVar4;
  CFastString *this_00;
  uint uVar5;
  SSystemTime *unaff_EBX;
  SSystemTime *unaff_ESI;
  SStringParam *unaff_EDI;
  void *in_stack_00000018;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000030;
  char *in_stack_ffffffbc;
  CFastString *pCVar6;
  SStringParam *in_stack_ffffffc4;
  SStringParam *in_stack_ffffffc8;
  SStringParam *pSVar7;
  SStringParam *pSVar8;
  SStringParam *in_stack_ffffffd4;
  CGameCtnReplayRecord *pCVar9;
  SStringParam *in_stack_ffffffe4;
  SSystemTime aSStack_18 [4];
  undefined *local_14;
  undefined1 *local_10;
  undefined1 *puStack_c;
  undefined *puStack_8;
  
  puStack_c = (undefined1 *)0xffffffff;
  local_10 = &LAB_00aa1790;
  local_14 = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_14;
  pCVar3 = *(CFastString **)(this + 0x24);
  if (pCVar3 == (CFastString *)0x0) {
    CFastStringInt::SetString(param_1,(CFastStringInt *)&stack0xffffffc4,pSVar1);
    ExceptionList = local_10;
    return;
  }
  pCVar6 = pCVar3;
  iVar2 = (**(code **)(*(int *)this + 0x88))();
  pSVar7 = (SStringParam *)0x0;
  puStack_c = (undefined1 *)0x0;
  pSVar8 = (SStringParam *)PTR_DAT_00bbf7dc;
  CFastStringBase<wchar_t>::PreAlloc(&stack0xffffffcc,(CClassicBufferMemory *)0x200,(ulong)pSVar1);
  pCVar9 = *(CGameCtnReplayRecord **)(param_4 + 4);
  CFastStringInt::Concat(&stack0xffffffd0,(CFastStringInt *)&stack0xffffffd8,unaff_EDI);
  if ((param_3 != 0) || (iVar2 == 0)) {
    pCVar3 = (CFastString *)PTR_DAT_00bbf7d8;
    SSystemTime::SSystemTime(&stack0xffffffcc,unaff_ESI);
    SSystemTime::SetFromSystemTime(&stack0xffffffd0,unaff_EBX);
    CFastString::CFastString
              ((CFastString *)&local_14,(CFastString *)&DAT_00b2ce84,in_stack_ffffffbc);
    param_2 = (CFastStringInt *)CONCAT31(param_2._1_3_,2);
    SSystemTime::GetAsString_YMD_HMS(&stack0xffffffd8,aSStack_18,(CFastString *)&local_10,pCVar6);
    param_3 = CONCAT31(param_3._1_3_,1);
    if (puStack_8 != PTR_DAT_00bbf7d8) {
      puVar4 = puStack_8 + -1;
      if ((puStack_8[-1] & 0x80) != 0) {
        puVar4 = puStack_8 + -4;
      }
      operator_delete__(puVar4);
    }
    puStack_c = local_10;
    puStack_8 = local_14;
    CFastStringInt::Concat(&stack0xffffffe4,(CFastStringInt *)&puStack_c,in_stack_ffffffc4);
    CFastStringInt::Concat(aSStack_18,(CFastStringInt *)&DAT_0000005f,in_stack_ffffffc8);
    param_5 = (CFastString *)((uint)param_5 & 0xffffff00);
    if (puStack_8 != PTR_DAT_00bbf7d8) {
      puVar4 = puStack_8 + -1;
      if ((puStack_8[-1] & 0x80) != 0) {
        puVar4 = puStack_8 + -4;
      }
      operator_delete__(puVar4);
    }
  }
  puVar4 = *(undefined **)(pCVar3 + 0x10c);
  param_1 = (CGameCtnReplayRecord *)0x0;
  CFastStringInt::Concat(&local_14,(CFastStringInt *)&stack0xfffffffc,pSVar7);
  if (param_2 != (CFastStringInt *)0x0) {
    if (iVar2 == 0) goto LAB_005dc48f;
    CFastStringInt::Concat(&local_10,(CFastStringInt *)&DAT_0000005f,pSVar8);
    param_1 = *(CGameCtnReplayRecord **)(iVar2 + 0xd4);
    param_2 = *(CFastStringInt **)(iVar2 + 0xd0);
    param_3 = 0;
    CFastStringInt::Concat(&puStack_c,(CFastStringInt *)&param_1,in_stack_ffffffd4);
  }
  if (iVar2 != 0) {
    param_1 = (CGameCtnReplayRecord *)PTR_DAT_00bbf7d8;
    in_stack_00000020 = 3;
    if (*(int *)(pCVar3 + 0xf8) == 5) {
      GetBestGhostStuntsScore(this,pCVar9);
      CFastString::Format(this_00,(CFastString *)&param_1,"(%d)");
    }
    else {
      GetBestGhostRaceTime
                (this,(CGameCtnReplayRecord *)&local_14,(ulong *)&local_10,(ulong *)pCVar9);
      uVar5 = ((uint)local_10 ^ (int)local_10 >> 0x1f) - ((int)local_10 >> 0x1f);
      CFastString::ConcatFormat
                ((CFastString *)(uVar5 + ((uVar5 % 60000) / 1000 + (uVar5 / 60000) * 0x3c) * -1000),
                 (CFastStringInt *)&param_1,"(%.2d\'%.2d\'\'%.2d)");
    }
    param_5 = (CFastString *)param_4;
    in_stack_00000018 = (void *)param_3;
    CFastStringInt::Concat(&param_1,(CFastStringInt *)&param_5,in_stack_ffffffe4);
    in_stack_00000030 = 0;
    if (param_5 != (CFastString *)PTR_DAT_00bbf7d8) {
      pCVar3 = param_5 + -1;
      if (((byte)param_5[-1] & 0x80) != 0) {
        pCVar3 = param_5 + -4;
      }
      operator_delete__(pCVar3);
    }
  }
LAB_005dc48f:
  pCVar9 = param_1;
  CPlugFont::GetPureString((CFastStringInt *)&puStack_8,(CFastStringInt *)param_1);
  CSystemFileName::FixFileName((CFastStringInt *)pCVar9,0);
  if (puVar4 != PTR_DAT_00bbf7dc) {
    if ((puVar4[-1] & 0x80) == 0) {
      puVar4 = puVar4 + -2;
    }
    else {
      puVar4 = puVar4 + -4;
    }
    operator_delete__(puVar4);
  }
  ExceptionList = in_stack_00000018;
  return;
}
}

// =================================================
// Function: CGameCtnReplayRecord::CGameCtnReplayRecord
// =================================================
void __thiscall
CGameCtnReplayRecord::CGameCtnReplayRecord(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_EDI,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x14) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x18,unaff_retaddr);
  *(undefined4 *)(this + 0x24) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x30,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CGameCtnReplayRecord::ComputeReplayDuration
// =================================================
ulong __thiscall
CGameCtnReplayRecord::ComputeReplayDuration
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CPlugFileAvi *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint uVar5;
  
  uVar5 = 0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar4,unaff_ESI);
      unaff_ESI = 0x5db1a7;
      uVar3 = CGameGhost::GetDuration(*(CGameGhost **)pSVar2,unaff_EBP);
      if (uVar5 < uVar3) {
        uVar5 = uVar3;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return uVar5;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GetBestGhostRaceTime
// =================================================
void __thiscall
CGameCtnReplayRecord::GetBestGhostRaceTime
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,ulong *param_2,ulong *param_3)
{
{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  CGameCtnReplayRecord *unaff_EDI;
  
  iVar1 = (**(code **)(*(int *)this + 0x88))();
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = *(undefined4 *)(iVar1 + 0xe8);
  }
  *(undefined4 *)param_1 = uVar3;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(ulong *)(iVar1 + 0xec);
  }
  *param_2 = uVar2;
  if (*(int *)param_1 == -1) {
    if ((iVar1 == 0) || (uVar2 = *(ulong *)(iVar1 + 0x10c), uVar2 == 0)) {
      uVar2 = ComputeReplayDuration(this,unaff_EDI);
    }
    *(ulong *)param_1 = uVar2;
  }
  return;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GetBestGhostStunts
// =================================================
CGameCtnGhost * __thiscall
CGameCtnReplayRecord::GetBestGhostStunts(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CGameCtnReplayRecord *this_00;
  uint uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  uint uVar4;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x18;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    uVar4 = *(uint *)(*(int *)pSVar3 + 0xf0);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < pCVar2) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_EBX)
        ;
        uVar1 = *(uint *)(*(int *)pSVar3 + 0xf0);
        if ((uVar1 != 0xffffffff) && (uVar4 < uVar1)) {
          uVar4 = uVar1;
        }
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
    }
    if (uVar4 != 0xffffffff) {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)this)
      ;
      return *(CGameCtnGhost **)pSVar3;
    }
  }
  return (CGameCtnGhost *)0x0;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GetBestGhostStuntsScore
// =================================================
ulong __thiscall
CGameCtnReplayRecord::GetBestGhostStuntsScore
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CGameCtnGhost *pCVar1;
  CGameCtnReplayRecord *unaff_retaddr;
  
  pCVar1 = GetBestGhostStunts(this,unaff_retaddr);
  if (pCVar1 == (CGameCtnGhost *)0x0) {
    return 0;
  }
  return *(ulong *)(pCVar1 + 0xf0);
}
}

// =================================================
// Function: CGameCtnReplayRecord::GetVersion
// =================================================
EReplayGhostVersion __thiscall
CGameCtnReplayRecord::GetVersion(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  EReplayGhostVersion EVar4;
  EReplayGhostVersion EVar5;
  bool bVar6;
  
  EVar4 = 0xffffffff;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  EVar5 = EVar4;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar3,unaff_ESI);
      EVar4 = *(EReplayGhostVersion *)(*(int *)pSVar2 + 0x100);
      if ((EVar5 != 0xffffffff) && (bVar6 = EVar5 != EVar4, EVar4 = EVar5, bVar6)) {
        return 0xffffffff;
      }
      pCVar3 = pCVar3 + 1;
      EVar5 = EVar4;
    } while (pCVar3 < pCVar1);
  }
  return EVar4;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GetVersionString
// =================================================
void __cdecl
CGameCtnReplayRecord::GetVersionString(EReplayGhostVersion param_1,CFastString *param_2)
{
{
  CFastString *this;
  
  this = (CFastString *)(param_1 - 1);
  if (this < (CFastString *)0x270e) {
    CFastString::Format(this,param_2,"TMr.%d");
    return;
  }
  if ((9999 < (int)param_1) && (param_1 != 0xffffffff)) {
    CFastString::Format(this,param_2,"VSKr.%d");
    return;
  }
  CFastString::SetString(param_2,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)"Unknown");
  return;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GhostGetByPlayerUid
// =================================================
CGameCtnGhost * __thiscall
CGameCtnReplayRecord::GhostGetByPlayerUid
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,uchar param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  uchar unaff_SI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           GhostGetIndexByPlayerUid(this,param_1,unaff_SI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x18,pCVar1,unaff_retaddr);
    return *(CGameCtnGhost **)pSVar2;
  }
  return (CGameCtnGhost *)0x0;
}
}

// =================================================
// Function: CGameCtnReplayRecord::GhostGetIndexByPlayerUid
// =================================================
ulong __thiscall
CGameCtnReplayRecord::GhostGetIndexByPlayerUid
          (CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1,uchar param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x18,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x18,pCVar3,unaff_ESI);
      if (*(uchar *)(*(int *)pSVar2 + 0x9c) == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGameCtnReplayRecord::IsAlmostEmpty
// =================================================
int __thiscall
CGameCtnReplayRecord::IsAlmostEmpty(CGameCtnReplayRecord *this,CGameCtnReplayRecord *param_1)
{
{
  CGameCtnReplayRecord *this_00;
  int iVar1;
  ulong uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  SShaderCustom *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CGameCtnReplayRecord *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  int in_stack_00000008;
  CGameCtnReplayRecord *pCVar6;
  
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (*(int *)(this + 0x24) == 0) {
    return 1;
  }
  this_00 = this + 0x18;
  pCVar6 = this;
  iVar1 = CFastBuffer<class_CAudioSound*>::IsEmpty(this_00,unaff_EBX);
  if ((iVar1 != 0) && (uVar2 = ComputeReplayDuration(this,unaff_EDI), uVar2 < 10000)) {
    return 1;
  }
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar5,unaff_ESI);
      unaff_ESI = 0x5db221;
      CGameGhost::GetDuration(*(CGameGhost **)pSVar4,(CPlugFileAvi *)pCVar6);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  return (uint)(in_stack_00000008 == 0);
}
}

