// Class implementation: CFastAlgo

// =================================================
// Function: CFastAlgo::ComputeCrc32
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulong __cdecl CFastAlgo::ComputeCrc32(CClassicBuffer *param_1,ulong param_2)
{
{
  void *pvVar1;
  GmVector3<unsigned_long> *extraout_EAX;
  void *extraout_EAX_00;
  int iVar2;
  ulong extraout_EAX_01;
  void *extraout_EAX_02;
  GmVector3<unsigned_long> *unaff_EBX;
  GmVector3<unsigned_long> *unaff_EBP;
  ulong uVar3;
  GmVector3<unsigned_long> *unaff_ESI;
  GmVector3<unsigned_long> *unaff_EDI;
  ulong in_stack_ffffeff8;
  GmVector3<unsigned_long> *in_stack_ffffeffc;
  GmVector3<unsigned_long> *pGVar4;
  CClassicBuffer aCStack_ff4 [4080];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)&stack0xffffeff8;
  pvVar1 = (void *)(**(code **)(*(int *)param_1 + 0x18))();
  Min(pvVar1,unaff_EDI,unaff_ESI);
  pGVar4 = extraout_EAX;
  (**(code **)(*(int *)param_1 + 0x14))();
  uVar3 = 0;
  Min((void *)0x1000,unaff_EBP,unaff_EBX);
  pvVar1 = extraout_EAX_00;
  while( true ) {
    if (pvVar1 == (void *)0x0) {
      return uVar3;
    }
    iVar2 = CClassicBuffer::ReadAll(param_1,aCStack_ff4,pvVar1,in_stack_ffffeff8);
    if (iVar2 == 0) break;
    crc32();
    in_stack_ffffeff8 = 0x90aa35;
    Min((void *)0x1000,in_stack_ffffeffc,pGVar4);
    uVar3 = extraout_EAX_01;
    pvVar1 = extraout_EAX_02;
  }
  return 0;
}
}

// =================================================
// Function: CFastAlgo::ComputeHMAC_MD5_Digest
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeHMAC_MD5_Digest(SHMAC_MD5_Data *param_1)
{
{
  uint uVar1;
  undefined1 local_e4 [88];
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
  _memset(&local_48,0,0x41);
  _memset(&local_8c,0,0x41);
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
}

// =================================================
// Function: CFastAlgo::ComputeHashSize
// =================================================
ulong __cdecl CFastAlgo::ComputeHashSize(ulong param_1)
{
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
}

// =================================================
// Function: CFastAlgo::ComputeHashVal
// =================================================
ulong __cdecl CFastAlgo::ComputeHashVal(char *param_1,ulong *param_2)
{
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
}

// =================================================
// Function: CFastAlgo::ComputeMD5_Digest
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl CFastAlgo::ComputeMD5_Digest(uchar *param_1,ulong param_2,SNat128 *param_3)
{
{
  undefined1 local_5c [88];
  uint local_4;
  
  local_4 = DAT_00cca150 ^ (uint)local_5c;
  classic_md5_init();
  classic_md5_append();
  classic_md5_finish();
  return;
}
}

// =================================================
// Function: CFastAlgo::GetRandomNat32
// =================================================
ulong __cdecl CFastAlgo::GetRandomNat32(void)
{
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
}

