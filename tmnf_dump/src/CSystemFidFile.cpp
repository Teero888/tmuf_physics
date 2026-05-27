// Class implementation: CSystemFidFile

// =================================================
// Function: CSystemFidFile::CSystemFidFile
// =================================================
void __thiscall CSystemFidFile::CSystemFidFile(CSystemFidFile *this,CSystemFidFile *param_1)
{
{
  CSystemFid *unaff_ESI;
  
  CSystemFid::CSystemFid((CSystemFid *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined **)(this + 0x78) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x18) = 1;
  this[0x1c] = DAT_00d543c0;
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x800;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  return;
}
}

// =================================================
// Function: CSystemFidFile::ForceUpdateFidProps
// =================================================
void __thiscall CSystemFidFile::ForceUpdateFidProps(CSystemFidFile *this,CSystemFidFile *param_1)
{
{
  CSystemFid *unaff_ESI;
  CLoaderFidContainer *in_stack_00000008;
  CSystemFid *in_stack_0000000c;
  
  CSystemFid::ResetHeaderUserDatas((CSystemFid *)this,unaff_ESI);
  this[0x1c] = (CSystemFidFile)((byte)this[0x1c] | DAT_00d543c0);
  CSystemFid::UpdateFidProps((CSystemFid *)this,in_stack_00000008,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CSystemFidFile::GetFullName
// =================================================
void __thiscall
CSystemFidFile::GetFullName(CSystemFidFile *this,CPlugFile *param_1,CFastStringInt *param_2)
{
{
  SStringParam *pSVar1;
  CSystemFid *pCVar2;
  undefined4 *extraout_EAX;
  SStringParam *unaff_ESI;
  CSystemFid *unaff_EDI;
  SStringParamInt *in_stack_ffffffd4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined *puStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a82708;
  local_c = ExceptionList;
  pSVar1 = (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffcc);
  ExceptionList = &local_c;
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(**(int **)(this + 0x14) + 0x98))(param_1,param_2);
  }
  local_24 = *(undefined4 *)(this + 0x78);
  local_20 = *(undefined4 *)(this + 0x74);
  local_1c = 0;
  CFastStringInt::Concat(param_1,(CFastStringInt *)&local_24,pSVar1);
  pCVar2 = CSystemFid::ParametrizedGetLoadableFid((CSystemFid *)this,unaff_EDI);
  if (*(undefined ***)(pCVar2 + 0x6c) != &PTR_vftable_00ccbf90) {
    CFastStringInt::CFastStringInt(&local_24,(CFastStringInt *)L"<virtual>",unaff_ESI);
    local_c = (void *)extraout_EAX[1];
    puStack_8 = (undefined1 *)*extraout_EAX;
    uStack_4 = 0;
    CFastStringInt::ConcatBefore(param_1,(CFastStringInt *)&local_c,in_stack_ffffffd4);
    if (puStack_18 != PTR_DAT_00bbf7dc) {
      if ((puStack_18[-1] & 0x80) == 0) {
        puStack_18 = puStack_18 + -2;
      }
      else {
        puStack_18 = puStack_18 + -4;
      }
      operator_delete__(puStack_18);
    }
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSystemFidFile::GetFullNameUpTo
// =================================================
int __thiscall
CSystemFidFile::GetFullNameUpTo
          (CSystemFidFile *this,CSystemFidsDrive *param_1,CFastStringInt *param_2,
          CSystemFids *param_3)
{
{
  int iVar1;
  CSystemFidsDrive *pCVar2;
  
  if (*(int *)(this + 0x14) != 0) {
    pCVar2 = param_1;
    iVar1 = (**(code **)(**(int **)(this + 0x14) + 0x9c))(param_1,param_2);
    if (iVar1 != 0) {
      CFastStringInt::Concat(param_1,(CFastStringInt *)&stack0xffffffec,(SStringParam *)pCVar2);
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemFidFile::OSCheckIfExists
// =================================================
int __thiscall CSystemFidFile::OSCheckIfExists(CSystemFidFile *this,CSystemFidFile *param_1)
{
{
  CSystemFid *pCVar1;
  int iVar2;
  undefined *puVar3;
  CPlugFile *pCVar4;
  CFastStringInt *pCVar5;
  undefined4 local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a827c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = CSystemFid::ParametrizedGetLoadableFid
                     ((CSystemFid *)this,(CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  if (*(undefined ***)(pCVar1 + 0x6c) != &PTR_vftable_00ccbf90) {
    ExceptionList = local_8;
    return 0;
  }
  local_10 = 0;
  local_c = PTR_DAT_00bbf7dc;
  pCVar5 = (CFastStringInt *)0x0;
  pCVar4 = (CPlugFile *)0x0;
  pCVar1 = CSystemFid::ParametrizedGetLoadableFid((CSystemFid *)this,(CSystemFid *)&local_10);
  GetFullName((CSystemFidFile *)pCVar1,pCVar4,pCVar5);
  iVar2 = CSystemManagerFile::IsFileExists((CFastStringInt *)&local_10);
  if (local_c != PTR_DAT_00bbf7dc) {
    if ((local_c[-1] & 0x80) == 0) {
      puVar3 = local_c + -2;
    }
    else {
      puVar3 = local_c + -4;
    }
    operator_delete__(puVar3);
  }
  ExceptionList = local_8;
  return iVar2;
}
}

// =================================================
// Function: CSystemFidFile::SetFileName
// =================================================
void __thiscall
CSystemFidFile::SetFileName(CSystemFidFile *this,CSystemFidFile *param_1,CFastStringInt *param_2)
{
{
  void *this_00;
  SStringParam *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 4);
  local_4 = 0;
  CFastStringInt::SetString((GmQuat *)(this + 0x74),(CFastStringInt *)&local_c,unaff_EDI);
  CSystemFileName::Normalize(this_00,(GmQuat *)(this + 0x74));
  (**(code **)(*(int *)this + 0x8c))();
  return;
}
}

// =================================================
// Function: CSystemFidFile::~CSystemFidFile
// =================================================
void __thiscall CSystemFidFile::~CSystemFidFile(CSystemFidFile *this,CSystemFidFile *param_1)
{
{
  undefined *puVar1;
  
  *(undefined ***)this = vftable;
  puVar1 = *(undefined **)(this + 0x78);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined **)(this + 0x78) = PTR_DAT_00bbf7dc;
  }
  CSystemFid::~CSystemFid((CSystemFid *)this,(CSystemFid *)param_1);
  return;
}
}

