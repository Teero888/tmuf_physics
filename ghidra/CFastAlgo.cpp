
int __cdecl CFastAlgo::CheckHashedPassword(CFastString *param_1, SNat128 *param_2)

{
  SNat128 *unaff_EBX;
  ulong unaff_ESI;
  CFastString *unaff_EDI;
  int local_10;
  int local_c;
  int local_8;
  int local_4;

  InternalHashPassword(unaff_EDI, unaff_ESI, unaff_EBX);
  if ((((local_10 == *(int *)param_2) && (local_c == *(int *)(param_2 + 4))) &&
       (local_8 == *(int *)(param_2 + 8))) &&
      (local_4 == *(int *)(param_2 + 0xc))) {
    return 1;
  }
  return 0;
}

ulong __cdecl CFastAlgo::ComputeCrc32(CClassicBuffer *param_1, ulong param_2)

{
  ulong extraout_EAX;

  crc32();
  return extraout_EAX;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulong __cdecl CFastAlgo::ComputeCrc32(CClassicBuffer *param_1, ulong param_2)

{
  void *pvVar1;
  GmVector3<> *extraout_EAX;
  void *extraout_EAX_00;
  int iVar2;
  ulong extraout_EAX_01;
  void *extraout_EAX_02;
  GmVector3<> *unaff_EBX;
  GmVector3<> *unaff_EBP;
  ulong uVar3;
  GmVector3<> *unaff_ESI;
  GmVector3<> *unaff_EDI;
  ulong in_stack_ffffeff8;
  GmVector3<> *in_stack_ffffeffc;
  GmVector3<> *pGVar4;
  CClassicBuffer aCStack_ff4[4080];
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)&stack0xffffeff8;
  pvVar1 = (void *)(**(code **)(*(int *)param_1 + 0x18))();
  Min(pvVar1, unaff_EDI, unaff_ESI);
  pGVar4 = extraout_EAX;
  (**(code **)(*(int *)param_1 + 0x14))();
  uVar3 = 0;
  Min((void *)0x1000, unaff_EBP, unaff_EBX);
  pvVar1 = extraout_EAX_00;
  while (true) {
    if (pvVar1 == (void *)0x0) {
      return uVar3;
    }
    iVar2 = CClassicBuffer::ReadAll(param_1, aCStack_ff4, pvVar1, in_stack_ffffeff8);
    if (iVar2 == 0)
      break;
    crc32();
    in_stack_ffffeff8 = 0x90aa35;
    Min((void *)0x1000, in_stack_ffffeffc, pGVar4);
    uVar3 = extraout_EAX_01;
    pvVar1 = extraout_EAX_02;
  }
  return 0;
}

ulong __cdecl CFastAlgo::ComputeHashSize(ulong param_1)

{
  int iVar1;
  ulong unaff_EDI;
  uint uVar2;
  ulong uVar3;

  uVar2 = (param_1 * 4) / 3;
  if (10 < uVar2) {
    uVar3 = uVar2 | 1;
    iVar1 = IsPrime(unaff_EDI);
    while (iVar1 == 0) {
      uVar3 = uVar3 + 2;
      iVar1 = IsPrime(unaff_EDI);
    }
    return uVar3;
  }
  return 0xb;
}

ulong __cdecl CFastAlgo::ComputeHashVal(char *param_1, ulong *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;

  uVar4 = 0;
  uVar2 = 0;
  uVar1 = *(ushort *)param_1;
  while (uVar1 != 0) {
    uVar2 = uVar2 * 0x10 + (uint)uVar1;
    uVar4 = uVar4 + 1;
    param_1 = (char *)((int)param_1 + 2);
    uVar3 = uVar2 & 0xf0000000;
    if (uVar3 != 0) {
      uVar2 = uVar2 ^ uVar3 >> 0x18 ^ uVar3;
    }
    uVar1 = *(ushort *)param_1;
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = uVar4;
  }
  return uVar2;
}

ulong __cdecl CFastAlgo::ComputeHashVal(char *param_1, ulong *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;

  uVar4 = 0;
  uVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    uVar2 = uVar2 * 0x10 + (int)cVar1;
    uVar4 = uVar4 + 1;
    param_1 = param_1 + 1;
    uVar3 = uVar2 & 0xf0000000;
    if (uVar3 != 0) {
      uVar2 = uVar2 ^ uVar3 >> 0x18 ^ uVar3;
    }
    cVar1 = *param_1;
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = uVar4;
  }
  return uVar2;
}

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeHMAC_MD5_Digest(SHMAC_MD5_Data *param_1)

{
  uint uVar1;
  undefined1 local_e4[88];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)local_e4;
  _memset(&local_48, 0, 0x41);
  _memset(&local_8c, 0, 0x41);
  local_44 = *(undefined4 *)(param_1 + 0x1c);
  local_48 = *(undefined4 *)(param_1 + 0x18);
  local_8c = *(undefined4 *)(param_1 + 0x18);
  local_40 = *(undefined4 *)(param_1 + 0x20);
  local_3c = *(undefined4 *)(param_1 + 0x24);
  local_80 = *(undefined4 *)(param_1 + 0x24);
  local_88 = *(undefined4 *)(param_1 + 0x1c);
  local_84 = *(undefined4 *)(param_1 + 0x20);
  uVar1 = 0;
  do {
    *(byte *)((int)&local_48 + uVar1) = *(byte *)((int)&local_48 + uVar1) ^ 0x36;
    *(byte *)((int)&local_8c + uVar1) = *(byte *)((int)&local_8c + uVar1) ^ 0x5c;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  classic_md5_init();
  classic_md5_append();
  classic_md5_append();
  classic_md5_finish();
  classic_md5_init();
  classic_md5_append();
  classic_md5_append();
  classic_md5_finish();
  return;
}

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeHMAC_SHA1_Digest(SHMAC_SHA1_Data *param_1)

{
  uint uVar1;
  undefined1 local_e8[92];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)local_e8;
  _memset(&local_48, 0, 0x41);
  _memset(&local_8c, 0, 0x41);
  local_44 = *(undefined4 *)(param_1 + 0x24);
  local_48 = *(undefined4 *)(param_1 + 0x20);
  local_8c = *(undefined4 *)(param_1 + 0x20);
  local_40 = *(undefined4 *)(param_1 + 0x28);
  local_3c = *(undefined4 *)(param_1 + 0x2c);
  local_80 = *(undefined4 *)(param_1 + 0x2c);
  local_88 = *(undefined4 *)(param_1 + 0x24);
  local_84 = *(undefined4 *)(param_1 + 0x28);
  uVar1 = 0;
  do {
    *(byte *)((int)&local_48 + uVar1) = *(byte *)((int)&local_48 + uVar1) ^ 0x36;
    *(byte *)((int)&local_8c + uVar1) = *(byte *)((int)&local_8c + uVar1) ^ 0x5c;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x40);
  _SHA1Init();
  _SHA1Update();
  _SHA1Update();
  _SHA1Final();
  _SHA1Init();
  _SHA1Update();
  _SHA1Update();
  _SHA1Final();
  return;
}

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeMD5_Digest(uchar *param_1, ulong param_2, SNat128 *param_3)

{
  void *pvVar1;
  void *extraout_EAX;
  int iVar2;
  void *extraout_EAX_00;
  GmVector3<> *unaff_EBX;
  GmVector3<> *unaff_EBP;
  GmVector3<> *unaff_ESI;
  GmVector3<> *unaff_EDI;
  GmVector3<> *in_stack_ffffefa4;
  GmVector3<> *in_stack_ffffefa8;
  CClassicBuffer aCStack_ff4[4080];
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)&stack0xffffefa0;
  pvVar1 = (void *)(**(code **)(*(int *)param_1 + 0x18))();
  Min(pvVar1, unaff_EDI, unaff_ESI);
  (**(code **)(*(int *)param_1 + 0x14))();
  classic_md5_init();
  Min((void *)0x1000, unaff_EBP, unaff_EBX);
  pvVar1 = extraout_EAX;
  while (true) {
    if (pvVar1 == (void *)0x0) {
      classic_md5_finish();
      return;
    }
    iVar2 = CClassicBuffer::ReadAll((CClassicBuffer *)param_1, aCStack_ff4, pvVar1, param_2);
    if (iVar2 == 0)
      break;
    classic_md5_append();
    param_2 = 0x90ab07;
    Min((void *)0x1000, in_stack_ffffefa4, in_stack_ffffefa8);
    pvVar1 = extraout_EAX_00;
  }
  return;
}

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeMD5_Digest(uchar *param_1, ulong param_2, SNat128 *param_3)

{
  undefined1 local_5c[88];
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)local_5c;
  classic_md5_init();
  classic_md5_append();
  classic_md5_finish();
  return;
}

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeSHA1_Digest(uchar *param_1, ulong param_2, CFastString *param_3)

{
  SStringParam *unaff_EDI;
  undefined1 *local_7c;
  undefined4 local_78;
  undefined1 local_18[20];
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)&local_7c;
  _SHA1Init();
  _SHA1Update();
  _SHA1Final();
  local_7c = local_18;
  local_78 = 0x14;
  CFastString::SetString(param_3, (CFastStringInt *)&local_7c, unaff_EDI);
  return;
}

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::GetRandomData(void *param_1, ulong param_2)

{
  uint uVar1;
  int iVar2;
  SNat128 *pSVar3;
  __time64_t _Var4;
  SNat128 aSStack_3c[20];
  undefined4 local_28;
  uchar auStack_24[32];
  uint local_4;

  local_4 = DAT_00cca150 ^ (uint)aSStack_3c;
  _Var4 = __time64((__time64_t *)0x0);
  local_28 = (undefined4)((ulonglong)_Var4 >> 0x20);
  uVar1 = _rand();
  FUN_009c2270(uVar1 ^ (uint)_Var4 ^ 0xbb40e64e);
  do {
    uVar1 = 0;
    do {
      iVar2 = _rand();
      *(short *)(auStack_24 + uVar1 * 2) = (short)iVar2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x10);
    ComputeMD5_Digest(auStack_24, 0x20, aSStack_3c);
    iVar2 = 0x10;
    pSVar3 = aSStack_3c;
    do {
      if ((int)param_2 < 1) {
        return;
      }
      *(SNat128 *)param_1 = *pSVar3;
      iVar2 = iVar2 + -1;
      param_1 = (void *)((int)param_1 + 1);
      pSVar3 = pSVar3 + 1;
      param_2 = param_2 - 1;
    } while (0 < iVar2);
  } while (0 < (int)param_2);
  return;
}

ulong __cdecl CFastAlgo::GetRandomNat32(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;

  uVar2 = 0;
  iVar3 = 4;
  do {
    iVar1 = _rand();
    uVar2 = uVar2 << 8 | (int)(iVar1 + (iVar1 >> 0x1f & 0x7fU)) >> 7 & 0xffU;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar2;
}

void __cdecl CFastAlgo::HashPassword(CFastString *param_1, SNat128 *param_2)

{
  ulong unaff_ESI;
  CFastString *unaff_EDI;
  SNat128 *unaff_retaddr;

  GetRandomNat32();
  InternalHashPassword(unaff_EDI, unaff_ESI, unaff_retaddr);
  return;
}

void __cdecl CFastAlgo::SortQuickArrayReal(void *param_1, ulong param_2, ulong param_3, ulong param_4, SSortRemapInfo *param_5)

{
  undefined4 uVar1;
  SSortKeyReal *pSVar2;
  uint uVar3;
  void *pvVar4;
  SSortKeyReal *pSVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void *pvVar9;
  uint uVar10;
  void *pvVar11;
  uint local_14;
  int local_8;
  uint local_4;

  pSVar2 = operator_new[](-(uint)((int)((ulonglong)param_2 * 8 >> 0x20) != 0) |
                          (uint)((ulonglong)param_2 * 8));
  uVar3 = 0;
  if (3 < (int)param_2) {
    pSVar5 = pSVar2 + 8;
    puVar6 = (undefined4 *)((int)param_1 + param_4);
    puVar7 = (undefined4 *)((int)param_1 + param_4 + param_3 * 3);
    puVar8 = (undefined4 *)((int)param_1 + param_4 + param_3 * 2);
    do {
      uVar1 = *puVar6;
      *(uint *)(pSVar5 + -4) = uVar3;
      *(undefined4 *)(pSVar5 + -8) = uVar1;
      uVar1 = *(undefined4 *)(param_3 + (int)puVar6);
      *(uint *)(pSVar5 + 4) = uVar3 + 1;
      *(undefined4 *)pSVar5 = uVar1;
      uVar1 = *puVar8;
      *(uint *)(pSVar5 + 0xc) = uVar3 + 2;
      *(undefined4 *)(pSVar5 + 8) = uVar1;
      uVar1 = *puVar7;
      *(uint *)(pSVar5 + 0x14) = uVar3 + 3;
      *(undefined4 *)(pSVar5 + 0x10) = uVar1;
      puVar6 = puVar6 + param_3;
      puVar8 = puVar8 + param_3;
      puVar7 = puVar7 + param_3;
      uVar3 = uVar3 + 4;
      pSVar5 = pSVar5 + 0x20;
    } while (uVar3 < param_2 - 3);
  }
  if (uVar3 < param_2) {
    puVar6 = (undefined4 *)((int)param_1 + param_4 + uVar3 * param_3);
    do {
      uVar1 = *puVar6;
      *(uint *)(pSVar2 + uVar3 * 8 + 4) = uVar3;
      *(undefined4 *)(pSVar2 + uVar3 * 8) = uVar1;
      uVar3 = uVar3 + 1;
      puVar6 = (undefined4 *)((int)puVar6 + param_3);
    } while (uVar3 < param_2);
  }
  SortQuickKeyReal(pSVar2, param_2);
  uVar3 = 0;
  if (param_2 != 0) {
    pSVar5 = pSVar2 + 4;
    do {
      *(undefined4 *)(param_5 + uVar3 * 8) = *(undefined4 *)pSVar5;
      uVar3 = uVar3 + 1;
      pSVar5 = pSVar5 + 8;
    } while (uVar3 < param_2);
  }
  pvVar4 = operator_new[](param_3);
  local_4 = 0;
  if (param_2 != 0) {
    do {
      uVar3 = *(uint *)(param_5 + local_4 * 8);
      local_8 = uVar3 * 8;
      *(uint *)(param_5 + local_8 + 4) = local_4;
      uVar10 = local_4;
      local_14 = local_4;
      if (*(uint *)(pSVar2 + local_8 + 4) != uVar3) {
        do {
          uVar10 = uVar3;
          pvVar9 = (void *)(local_14 * param_3 + (int)param_1);
          pvVar11 = (void *)(uVar10 * param_3 + (int)param_1);
          _memcpy(pvVar4, pvVar9, param_3);
          _memcpy(pvVar9, pvVar11, param_3);
          _memcpy(pvVar11, pvVar4, param_3);
          *(uint *)(param_5 + local_8 + 4) = local_14;
          *(uint *)(pSVar2 + local_14 * 8 + 4) = local_14;
          uVar3 = *(uint *)(pSVar2 + local_8 + 4);
          local_8 = uVar3 * 8;
          local_14 = uVar10;
        } while (*(uint *)(pSVar2 + local_8 + 4) != uVar3);
      }
      local_4 = local_4 + 1;
      *(uint *)(pSVar2 + uVar10 * 8 + 4) = uVar10;
    } while (local_4 < param_2);
  }
  operator_delete[](pvVar4);
  operator_delete[](pSVar2);
  return;
}

void __cdecl CFastAlgo::SortQuickKeyReal(SSortKeyReal *param_1, ulong param_2)

{
  func_0x009c1270(param_1, param_2, 8, CompareSortKeyReal);
  return;
}
