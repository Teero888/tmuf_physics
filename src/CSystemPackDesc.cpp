// Class implementation: CSystemPackDesc

// =================================================
// Function: CSystemPackDesc::CanSetURL
// =================================================
int __thiscall CSystemPackDesc::CanSetURL(CSystemPackDesc *this,CSystemPackDesc *param_1)
{
{
  int iVar1;
  int iVar2;
  SCasterCat *pSVar3;
  ulong unaff_EDI;
  
  iVar1 = *(int *)(this + 0x4c);
  if ((iVar1 != 0) && (iVar1 != *(int *)(DAT_00d54250 + 0x50))) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,unaff_EDI);
    iVar2 = *(int *)pSVar3;
    iVar1 = *(int *)(iVar1 + 0x18);
    if (iVar1 != *(int *)(iVar2 + 0x30)) {
      if (iVar1 == *(int *)(iVar2 + 0x2c)) {
        return 0;
      }
      if (iVar1 == *(int *)(iVar2 + 0x28)) {
        return (uint)(*(int *)(this + 0x50) != 0);
      }
    }
  }
  return 1;
}
}

// =================================================
// Function: CSystemPackDesc::ComputeChecksum
// =================================================
SNat128 __cdecl
CSystemPackDesc::ComputeChecksum
          (ulong param_1,ulong param_2,ulong param_3,ulong param_4,uchar *param_5)
{
{
  int extraout_EAX;
  int iVar1;
  
  CFastAlgo::ComputeMD5_Digest((uchar *)param_1,param_2,(SNat128 *)param_3);
  iVar1 = extraout_EAX;
  if ((((*(int *)param_3 == DAT_00cce628) && (iVar1 = *(int *)(param_3 + 4), iVar1 == DAT_00cce62c))
      && (*(int *)(param_3 + 8) == DAT_00cce630)) && (*(int *)(param_3 + 0xc) == DAT_00cce634)) {
    *(undefined4 *)param_3 = 2;
    *(undefined4 *)(param_3 + 4) = 0;
  }
  return SUB41(iVar1,0);
}
}

// =================================================
// Function: CSystemPackDesc::ConvertChecksumToString
// =================================================
int __cdecl
CSystemPackDesc::ConvertChecksumToString(SNat128 *param_1,CFastString *param_2,int param_3)
{
{
  CFastString *this;
  CFastString *pCVar1;
  int iVar2;
  SStringParam *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  void *in_stack_00000014;
  undefined4 uStack00000018;
  int in_stack_ffffffe4;
  int iVar3;
  SStringParam *pSVar4;
  SHeaderCommunity *pSVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  CFastString *pCStack_4;
  
  iVar2 = param_3;
  this = param_2;
  pCStack_4 = (CFastString *)0xffffffff;
  puStack_8 = &LAB_00ae0b80;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (param_3 == 0) {
    pSVar5 = (SHeaderCommunity *)0x0;
  }
  else {
    pSVar5 = (SHeaderCommunity *)0x2;
  }
  CFastString::SetString
            (param_2,(CFastStringInt *)&stack0xffffffec,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  pCVar1 = param_2;
  iVar3 = 0;
  pSVar4 = (SStringParam *)PTR_DAT_00bbf7d8;
  CFastString::SetNat64
            ((CFastString *)&stack0xffffffe8,*(CFastString **)(param_2 + 8),0x1000000000,1,1,0,
             unaff_EDI,unaff_ESI);
  puStack_8 = pvStack_c;
  pCStack_4 = (CFastString *)pSVar5;
  CFastString::Concat(this,(CFastStringInt *)&puStack_8,unaff_EBX);
  CFastString::SetNat64
            ((CFastString *)&pvStack_c,*(CFastString **)pCVar1,0x1000000000,1,1,0,in_stack_ffffffe4,
             iVar3);
  param_1 = (SNat128 *)0x1;
  param_2 = pCStack_4;
  CFastString::Concat(this,(CFastStringInt *)&param_1,pSVar4);
  iVar3 = *(int *)this;
  uStack00000018 = 0xffffffff;
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,pSVar5);
  ExceptionList = in_stack_00000014;
  return (uint)(iVar3 == (-(uint)(iVar2 != 0) & 2) + 0x20);
}
}

// =================================================
// Function: CSystemPackDesc::GetContents
// =================================================
void __thiscall
CSystemPackDesc::GetContents
          (CSystemPackDesc *this,CSystemPackDesc *param_1,CSystemFids **param_2,CSystemFid **param_3
          )
{
{
  int *piVar1;
  ulong uVar2;
  int iVar3;
  CSystemFid *unaff_ESI;
  ulong unaff_EDI;
  undefined4 *in_stack_00000010;
  
  if (*(CSystemFid **)(this + 0x48) == (CSystemFid *)0x0) {
    *(undefined4 *)param_1 = 0;
    *param_2 = (CSystemFids *)0x0;
    return;
  }
  if (*(int *)(this + 0x78) == 0) {
    uVar2 = CSystemFid::GetClassId(*(CSystemFid **)(this + 0x48),unaff_ESI);
    if (uVar2 != 0xffffffff) {
      uVar2 = CSystemFid::GetClassId(*(CSystemFid **)(this + 0x48),(CSystemFid *)0x9084000);
      iVar3 = CMwNod::StaticMwIsKindOf(uVar2,unaff_EDI);
      if (iVar3 != 0) {
        iVar3 = CSystemArchiveNod::LoadFromFid<class_CMwNod>
                          ((CMwNodRef<class_CMwNod> *)(this + 0x78),*(CSystemFid **)(this + 0x48),7)
        ;
        if ((iVar3 != 0) && (piVar1 = *(int **)(this + 0x78), piVar1 != (int *)0x0)) {
          if (piVar1[0xb] == 0) {
            (**(code **)(*piVar1 + 0x98))(*(undefined4 *)(*(int *)(this + 0x48) + 0x14),1);
          }
          *param_3 = (CSystemFid *)piVar1[0xb];
          *in_stack_00000010 = 0;
          return;
        }
        *param_3 = (CSystemFid *)0x0;
        *in_stack_00000010 = 0;
        return;
      }
    }
    *param_3 = (CSystemFid *)0x0;
    *in_stack_00000010 = *(undefined4 *)(this + 0x48);
    return;
  }
  *(undefined4 *)param_1 = *(undefined4 *)(*(int *)(this + 0x78) + 0x2c);
  *param_2 = (CSystemFids *)0x0;
  return;
}
}

// =================================================
// Function: CSystemPackDesc::SetChecksumNull
// =================================================
void __cdecl CSystemPackDesc::SetChecksumNull(SNat128 *param_1)
{
{
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}
}

// =================================================
// Function: CSystemPackDesc::SetURL
// =================================================
void __thiscall
CSystemPackDesc::SetURL(CSystemPackDesc *this,CSystemPackDesc *param_1,CFastString *param_2)
{
{
  int iVar1;
  CSystemPackDesc *unaff_ESI;
  SStringParam *in_stack_fffffff8;
  undefined4 local_4;
  
  iVar1 = CanSetURL(this,unaff_ESI);
  if (iVar1 != 0) {
    local_4 = *(undefined4 *)(param_2 + 4);
    CFastString::SetString
              ((CFastString *)(this + 0x24),(CFastStringInt *)&local_4,in_stack_fffffff8);
    CSystemPackManager::NormalizeUrl((CFastString *)(this + 0x24));
  }
  return;
}
}

// =================================================
// Function: CSystemPackDesc::TouchLastTimeOfUse
// =================================================
void __thiscall CSystemPackDesc::TouchLastTimeOfUse(CSystemPackDesc *this,CSystemPackDesc *param_1)
{
{
  SSystemTime *unaff_retaddr;
  
  SSystemTime::SetFromSystemTime(this + 0x14,unaff_retaddr);
  if (DAT_00d54250 != 0) {
    *(undefined4 *)(DAT_00d54250 + 0x68) = 1;
  }
  return;
}
}

