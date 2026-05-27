// Class implementation: CGameLeague

// =================================================
// Function: CGameLeague::GetFullPath
// =================================================
void __thiscall
CGameLeague::GetFullPath(CGameLeague *this,CGameLeague *param_1,CFastStringInt *param_2)
{
{
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  SStringParam *pSVar1;
  undefined4 local_4;
  
  pSVar1 = *(SStringParam **)(this + 0x18);
  local_4 = 0;
  CFastStringInt::SetString(param_1,(CFastStringInt *)&stack0xfffffff4,unaff_EDI);
  if (*(int *)param_1 != 0) {
    CFastStringInt::Concat(param_1,(CFastStringInt *)0x7c,unaff_ESI);
  }
  local_4 = *(undefined4 *)(this + 0x20);
  CFastStringInt::Concat(param_1,(CFastStringInt *)&local_4,pSVar1);
  return;
}
}

// =================================================
// Function: CGameLeague::GetNameAndPathFromFullPath
// =================================================
void __cdecl
CGameLeague::GetNameAndPathFromFullPath
          (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3)
{
{
  short sVar1;
  CFastStringInt *pCVar2;
  short *psVar3;
  SStringParam *unaff_ESI;
  ulong unaff_EDI;
  void *in_stack_00000010;
  SStringParam *in_stack_fffffff4;
  short *psVar4;
  int local_4;
  
  pCVar2 = (CFastStringInt *)
           CFastStringInt::FindLast(param_1,(CFastStringInt *)0x7c,0xffffffff,unaff_EDI);
  if (pCVar2 != (CFastStringInt *)0xffffffff) {
    psVar4 = (short *)(*(int *)(param_1 + 4) + 2 + (int)pCVar2 * 2);
    if (psVar4 == (short *)0x0) {
      local_4 = 0;
    }
    else {
      psVar3 = psVar4;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      local_4 = (int)psVar3 - (int)(psVar4 + 1) >> 1;
    }
    CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&stack0xfffffff8,unaff_ESI);
    local_4 = *(int *)(param_1 + 4);
    CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&local_4,in_stack_fffffff4);
    CFastStringInt::TruncAfterIndex(in_stack_00000010,pCVar2,(ulong)psVar4);
    return;
  }
  local_4 = *(int *)param_1;
  CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&stack0xfffffff8,unaff_ESI);
  local_4 = DAT_00d71d5c;
  CFastStringInt::SetString(in_stack_00000010,(CFastStringInt *)&local_4,in_stack_fffffff4);
  return;
}
}

// =================================================
// Function: CGameLeague::GetPathSteps
// =================================================
void __thiscall
CGameLeague::GetPathSteps
          (CGameLeague *this,CGameLeague *param_1,CFastBuffer<class_CFastStringInt> *param_2)
{
{
  undefined *puVar1;
  undefined4 local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_8 = &LAB_00aac218;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = 0;
  local_10 = PTR_DAT_00bbf7dc;
  local_4 = 0;
  GetFullPath(this,(CGameLeague *)&local_14,(CFastStringInt *)(DAT_00cca150 ^ (uint)&local_14));
  GetPathStepsFromFullPath((CFastStringInt *)&local_10,param_2);
  if (local_c != PTR_DAT_00bbf7dc) {
    if ((local_c[-1] & 0x80) == 0) {
      puVar1 = local_c + -2;
    }
    else {
      puVar1 = local_c + -4;
    }
    operator_delete__(puVar1);
  }
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CGameLeague::GetPathStepsFromFullPath
// =================================================
void __cdecl
CGameLeague::GetPathStepsFromFullPath
          (CFastStringInt *param_1,CFastBuffer<class_CFastStringInt> *param_2)
{
{
  SBitmapSpecular *this;
  undefined *puVar1;
  CFastStringInt *unaff_ESI;
  SStringParam *unaff_EDI;
  CFastStringInt *in_stack_ffffffb8;
  SStringParam *pSVar2;
  undefined *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined1 *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_14;
  undefined1 *local_10;
  void *local_c;
  undefined4 local_8;
  
  local_c = (void *)0xffffffff;
  local_10 = &LAB_00aac1a8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (param_2,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffb0));
  puVar1 = PTR_DAT_00bbf7dc;
  local_28 = *(undefined **)param_1;
  if (local_28 != (undefined *)0x0) {
    local_34 = (undefined *)0x0;
    local_30 = PTR_DAT_00bbf7dc;
    pSVar2 = (SStringParam *)0x0;
    local_3c = (undefined *)0x0;
    local_38 = PTR_DAT_00bbf7dc;
    local_2c = *(undefined **)(param_1 + 4);
    local_8 = 2;
    local_24 = (undefined *)0x0;
    CFastStringInt::SetString(&stack0xffffffbc,(CFastStringInt *)&local_2c,unaff_EDI);
    do {
      local_28 = local_3c;
      local_20 = 0;
      local_24 = puVar1;
      CFastStringInt::SetString(&local_30,(CFastStringInt *)&local_28,(SStringParam *)unaff_ESI);
      unaff_ESI = (CFastStringInt *)&local_34;
      GetNameAndPathFromFullPath((CFastStringInt *)&local_2c,(CFastStringInt *)&local_3c,unaff_ESI);
      if (local_34 != (undefined *)0x0) {
        this = CFastBuffer<class_CFastStringInt>::InsertNewElemAt
                         (param_2,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)0x0,
                          (ulong)in_stack_ffffffb8);
        local_14 = local_2c;
        in_stack_ffffffb8 = (CFastStringInt *)&local_14;
        local_10 = local_30;
        local_c = (void *)0x0;
        unaff_ESI = (CFastStringInt *)0x6483c3;
        CFastStringInt::SetString(this,in_stack_ffffffb8,pSVar2);
      }
    } while (puVar1 != (undefined *)0x0);
    if (local_34 != PTR_DAT_00bbf7dc) {
      puVar1 = local_34 + -4;
      if ((local_34[-1] & 0x80) == 0) {
        puVar1 = local_34 + -2;
      }
      operator_delete__(puVar1);
      local_38 = (undefined *)0x0;
      local_34 = PTR_DAT_00bbf7dc;
    }
    if (local_3c != PTR_DAT_00bbf7dc) {
      puVar1 = local_3c + -4;
      if ((local_3c[-1] & 0x80) == 0) {
        puVar1 = local_3c + -2;
      }
      operator_delete__(puVar1);
      local_3c = PTR_DAT_00bbf7dc;
    }
    if (local_2c != PTR_DAT_00bbf7dc) {
      puVar1 = local_2c + -4;
      if ((local_2c[-1] & 0x80) == 0) {
        puVar1 = local_2c + -2;
      }
      operator_delete__(puVar1);
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CGameLeague::GetRecursivesPathsFromFullPath
// =================================================
/* WARNING: Removing unreachable block (ram,0x006484e5) */

void __cdecl
CGameLeague::GetRecursivesPathsFromFullPath
          (CFastStringInt *param_1,CFastBuffer<class_CFastStringInt> *param_2)
{
{
  undefined *puVar1;
  undefined *puVar2;
  SStringParam *unaff_EDI;
  undefined *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  void *local_14;
  undefined1 *local_10;
  void *local_c;
  
  puVar2 = PTR_DAT_00bbf7dc;
  local_10 = &LAB_00aac1e8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_c = (void *)0x2;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
            (param_2,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffb0));
  local_2c = *(undefined **)(param_1 + 4);
  local_28 = *(undefined4 *)param_1;
  local_24 = 0;
  CFastStringInt::SetString(&stack0xffffffbc,(CFastStringInt *)&local_2c,unaff_EDI);
  if (puVar2 != PTR_DAT_00bbf7dc) {
    puVar1 = puVar2 + -4;
    if ((puVar2[-1] & 0x80) == 0) {
      puVar1 = puVar2 + -2;
    }
    operator_delete__(puVar1);
  }
  if (puVar2 != PTR_DAT_00bbf7dc) {
    puVar1 = puVar2 + -4;
    if ((puVar2[-1] & 0x80) == 0) {
      puVar1 = puVar2 + -2;
    }
    operator_delete__(puVar1);
  }
  if (local_2c != PTR_DAT_00bbf7dc) {
    puVar2 = local_2c + -4;
    if ((local_2c[-1] & 0x80) == 0) {
      puVar2 = local_2c + -2;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = local_c;
  return;
}
}

