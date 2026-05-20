// Class implementation: CPlugFile

// =================================================
// Function: CPlugFile::CPlugFile
// =================================================
void __thiscall CPlugFile::CPlugFile(CPlugFile *this,CPlugFile *param_1)
{
{
  CPlug *unaff_ESI;
  
  CPlug::CPlug((CPlug *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CPlugFile::CreateFromFid
// =================================================
CPlugFile * __cdecl CPlugFile::CreateFromFid(CSystemFidFile *param_1)
{
{
  ulong uVar1;
  CMwNod *pCVar2;
  undefined *puVar3;
  undefined *local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ad40d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = GetClassIdFromFid(param_1);
  if (uVar1 != 0xffffffff) {
    pCVar2 = CMwNod::CreateByMwClassId(uVar1);
    ExceptionList = local_c;
    return (CPlugFile *)pCVar2;
  }
  local_14 = (undefined *)0x0;
  local_10 = PTR_DAT_00bbf7dc;
  local_4 = 0;
  CSystemFidFile::GetFullName(param_1,(CPlugFile *)&local_14,(CFastStringInt *)0x0);
  if (local_14 != PTR_DAT_00bbf7dc) {
    if ((local_14[-1] & 0x80) == 0) {
      puVar3 = local_14 + -2;
    }
    else {
      puVar3 = local_14 + -4;
    }
    operator_delete__(puVar3);
  }
  ExceptionList = local_10;
  return (CPlugFile *)0x0;
}
}

// =================================================
// Function: CPlugFile::GetClassIdFromFid
// =================================================
ulong __cdecl CPlugFile::GetClassIdFromFid(CSystemFidFile *param_1)
{
{
  CSystemFid *pCVar1;
  ulong uVar2;
  CSystemFid *unaff_retaddr;
  
  if (param_1 != (CSystemFidFile *)0x0) {
    pCVar1 = CSystemFid::ParametrizedGetLoadableFid((CSystemFid *)param_1,unaff_retaddr);
    uVar2 = GetClassIdFromFileName((CFastStringInt *)(pCVar1 + 0x74));
    return uVar2;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugFile::GetClassIdFromFileName
// =================================================
ulong __cdecl CPlugFile::GetClassIdFromFileName(CFastStringInt *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  char *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastStringInt *in_stack_00000008;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d6e510,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (&DAT_00d6e510,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = *(char **)(pSVar2 + 8);
      iVar3 = CSystemFileName::IsExtension(in_stack_00000008,unaff_ESI);
      if (iVar3 != 0) {
        return *(ulong *)pSVar2;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugFile::GetFullName
// =================================================
void __thiscall CPlugFile::GetFullName(CPlugFile *this,CPlugFile *param_1,CFastStringInt *param_2)
{
{
  CSystemFidFile *this_00;
  int iVar1;
  CPlugFile *unaff_retaddr;
  
  this_00 = *(CSystemFidFile **)(this + 8);
  if (this_00 != (CSystemFidFile *)0x0) {
    iVar1 = (**(code **)(*(int *)this_00 + 0x10))(0xb00a000);
    if (iVar1 != 0) {
      CSystemFidFile::GetFullName(this_00,unaff_retaddr,(CFastStringInt *)0x0);
    }
  }
  return;
}
}

