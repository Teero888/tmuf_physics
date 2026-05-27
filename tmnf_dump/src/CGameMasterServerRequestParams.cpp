// Class implementation: CGameMasterServerRequestParams

// =================================================
// Function: CGameMasterServerRequestParams::GetParam
// =================================================
int __thiscall
CGameMasterServerRequestParams::GetParam
          (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1,
          CFastString *param_2,CFastString *param_3)
{
{
  SParam *pSVar1;
  CFastString *in_stack_fffffff8;
  
  pSVar1 = InternalGetParam(this,param_1,in_stack_fffffff8);
  if (pSVar1 == (SParam *)0x0) {
    return 0;
  }
  CFastString::SetString
            (param_3,(CFastStringInt *)&stack0xfffffffc,*(SStringParam **)(pSVar1 + 0xc));
  return 1;
}
}

// =================================================
// Function: CGameMasterServerRequestParams::GetParamAsNatural
// =================================================
int __thiscall
CGameMasterServerRequestParams::GetParamAsNatural
          (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1,
          CFastString *param_2,ulong *param_3)
{
{
  int iVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  ulong uVar4;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_8 = &LAB_00aac6d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar4 = 0;
  local_10 = PTR_DAT_00bbf7d8;
  local_4 = (void *)0x0;
  iVar1 = GetParam(this,param_1,(CFastString *)&stack0xffffffec,
                   (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  if (iVar1 == 0) {
    if (local_c != PTR_DAT_00bbf7d8) {
      puVar2 = local_c + -1;
      if ((local_c[-1] & 0x80) != 0) {
        puVar2 = local_c + -4;
      }
      operator_delete__(puVar2);
    }
    ExceptionList = local_8;
    return 0;
  }
  CFastString::GetNatural((CFastString *)&local_10,(CFastString *)param_3,(ulong *)0x0,0,uVar4);
  if (local_8 != PTR_DAT_00bbf7d8) {
    puVar3 = local_8 + -1;
    if ((local_8[-1] & 0x80) != 0) {
      puVar3 = local_8 + -4;
    }
    operator_delete__(puVar3);
  }
  ExceptionList = local_4;
  return 1;
}
}

// =================================================
// Function: CGameMasterServerRequestParams::GetParamAsStringInt
// =================================================
int __thiscall
CGameMasterServerRequestParams::GetParamAsStringInt
          (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1,
          CFastString *param_2,CFastStringInt *param_3)
{
{
  int iVar1;
  undefined *puVar2;
  SStringParam *pSVar3;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  void *local_4;
  
  puVar2 = PTR_DAT_00bbf7d8;
  local_8 = &LAB_00aac708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar3 = (SStringParam *)0x0;
  local_4 = (void *)0x0;
  iVar1 = GetParam(this,param_1,(CFastString *)&stack0xffffffe4,
                   (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  if (iVar1 == 0) {
    if (local_14 != PTR_DAT_00bbf7d8) {
      puVar2 = local_14 + -1;
      if ((local_14[-1] & 0x80) != 0) {
        puVar2 = local_14 + -4;
      }
      operator_delete__(puVar2);
    }
    ExceptionList = local_8;
    return 0;
  }
  local_c = puVar2;
  local_10 = local_14;
  CFastStringInt::SetUtf8(param_3,(CFastStringInt *)&local_10,pSVar3);
  if (local_10 != PTR_DAT_00bbf7d8) {
    puVar2 = local_10 + -1;
    if ((local_10[-1] & 0x80) != 0) {
      puVar2 = local_10 + -4;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_4;
  return 1;
}
}

// =================================================
// Function: CGameMasterServerRequestParams::InternalGetParam
// =================================================
SParam * __thiscall
CGameMasterServerRequestParams::InternalGetParam
          (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1,
          CFastString *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *this_00;
  int extraout_EAX;
  int *unaff_EBX;
  int *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 4,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      this_00 = CFastBuffer<class_GxColor>::operator[](this + 4,pCVar2,unaff_ESI);
      if (*(int *)param_2 == *(int *)this_00) {
        unaff_ESI = 0;
        CFastString::Compare
                  ((CFastString *)this_00,(SParam_Fids *)&stack0x00000000,(SParam *)0x0,unaff_EBP,
                   unaff_EBX);
        if (extraout_EAX == 0) {
          return (SParam *)this_00;
        }
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCVar1);
  }
  return (SParam *)0x0;
}
}

