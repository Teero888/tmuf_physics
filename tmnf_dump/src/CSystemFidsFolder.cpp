// Class implementation: CSystemFidsFolder

// =================================================
// Function: CSystemFidsFolder::CSystemFidsFolder
// =================================================
void __thiscall
CSystemFidsFolder::CSystemFidsFolder(CSystemFidsFolder *this,CSystemFidsFolder *param_1)
{
{
  CSystemFids *unaff_ESI;
  
  CSystemFids::CSystemFids((CSystemFids *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined **)(this + 0x44) = PTR_DAT_00bbf7dc;
  *(uint *)(this + 0x34) = *(uint *)(this + 0x34) & 0xfffffffe;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  return;
}
}

// =================================================
// Function: CSystemFidsFolder::GetFullName
// =================================================
void __thiscall
CSystemFidsFolder::GetFullName(CSystemFidsFolder *this,CPlugFile *param_1,CFastStringInt *param_2)
{
{
  (**(code **)(**(int **)(this + 0x14) + 0x98))(param_1,param_2);
  CSystemFileName::ConcatDirectory((CFastStringInt *)param_1,(CFastStringInt *)(this + 0x40));
  return;
}
}

// =================================================
// Function: CSystemFidsFolder::MakeDir
// =================================================
/* WARNING: Removing unreachable block (ram,0x0042a80f) */

EMakeDir __cdecl CSystemFidsFolder::MakeDir(CFastStringInt *param_1)
{
{
  EMakeDir EVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x98))(&DAT_00d555b8);
  EVar1 = CSystemManagerFile::MakeDir((CFastStringInt *)&DAT_00d555b8);
  if (EVar1 != 2) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSystemFidsFolder::SetDirName
// =================================================
void __thiscall
CSystemFidsFolder::SetDirName
          (CSystemFidsFolder *this,CSystemFidsFolder *param_1,CFastStringInt *param_2)
{
{
  SStringParam *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 4);
  local_4 = 0;
  CFastStringInt::SetString((CFastStringInt *)(this + 0x40),(CFastStringInt *)&local_c,unaff_EDI);
  CSystemFileName::StripTrailingSlash((CFastStringInt *)(this + 0x40));
  (**(code **)(*(int *)this + 0xbc))();
  return;
}
}

// =================================================
// Function: CSystemFidsFolder::~CSystemFidsFolder
// =================================================
void __thiscall
CSystemFidsFolder::~CSystemFidsFolder(CSystemFidsFolder *this,CSystemFidsFolder *param_1)
{
{
  undefined *puVar1;
  
  *(undefined ***)this = vftable;
  puVar1 = *(undefined **)(this + 0x44);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined **)(this + 0x44) = PTR_DAT_00bbf7dc;
  }
  CSystemFids::~CSystemFids((CSystemFids *)this,(CSystemFids *)param_1);
  return;
}
}

