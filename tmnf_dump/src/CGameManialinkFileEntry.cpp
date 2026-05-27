// Class implementation: CGameManialinkFileEntry

// =================================================
// Function: CGameManialinkFileEntry::CGameManialinkFileEntry
// =================================================
void __thiscall
CGameManialinkFileEntry::CGameManialinkFileEntry
          (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1)
{
{
  CGameManialinkEntry *unaff_ESI;
  
  CGameManialinkEntry::CGameManialinkEntry((CGameManialinkEntry *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined **)(this + 0x38) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x24) = 1;
  return;
}
}

// =================================================
// Function: CGameManialinkFileEntry::SetFileType
// =================================================
void __thiscall
CGameManialinkFileEntry::SetFileType
          (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1,CFastString *param_2)
{
{
  CGameManialinkFileEntry *this_00;
  int iVar1;
  char *unaff_ESI;
  ulong unaff_EDI;
  ulong uVar2;
  char *in_stack_0000000c;
  ulong in_stack_00000010;
  int in_stack_00000014;
  int in_stack_0000001c;
  undefined *puVar3;
  char *pcVar4;
  
  this_00 = param_1;
  puVar3 = &DAT_00b914d8;
  if (*(int *)param_1 == 4) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)param_1,(CFastStringInt *)&stack0xfffffff8,(SStringParam *)0x0
                       ,unaff_EDI);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9025000;
      *(undefined4 *)(this + 0x2c) = 0x9084000;
      return;
    }
  }
  if (*(int *)this_00 == 9) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&stack0xfffffffc,(SStringParam *)0x0
                       ,(ulong)unaff_ESI);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x3043000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  if (*(int *)this_00 == 6) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&stack0xfffffffc,(SStringParam *)0x0
                       ,(ulong)unaff_ESI);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x3093000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  pcVar4 = "image";
  uVar2 = 5;
  if (*(int *)this_00 == 5) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&stack0xfffffffc,(SStringParam *)0x0
                       ,(ulong)unaff_ESI);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9025000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  SStringParam::SStringParam(&stack0xfffffffc,(SStringParam *)&DAT_00b4fdb8,unaff_ESI);
  if (param_1 == *(CGameManialinkFileEntry **)this_00) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&stack0x00000000,(SStringParam *)0x0
                       ,(ulong)puVar3);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9030000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  SStringParam::SStringParam(&param_1,(SStringParam *)&DAT_00b87330,pcVar4);
  if (in_stack_0000000c == *(char **)this_00) {
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&param_2,(SStringParam *)0x0,uVar2);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9060000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  SStringParam::SStringParam(&stack0x0000000c,(SStringParam *)&DAT_00b68648,(char *)param_1);
  if (in_stack_00000014 == *(int *)this_00) {
    param_1 = (CGameManialinkFileEntry *)0x0;
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)&stack0x00000010,(SStringParam *)0x0
                       ,(ulong)param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9041000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  param_2 = (CFastString *)&DAT_00b914cc;
  param_1 = (CGameManialinkFileEntry *)0x75b83c;
  SStringParam::SStringParam(&stack0x00000014,(SStringParam *)&DAT_00b914cc,in_stack_0000000c);
  if (in_stack_0000001c == *(int *)this_00) {
    in_stack_0000000c = (char *)0x0;
    param_2 = (CFastString *)&stack0x00000018;
    param_1 = (CGameManialinkFileEntry *)0x75b852;
    iVar1 = CFastString::CompareNoCase
                      ((CFastString *)this_00,(CFastStringInt *)param_2,(SStringParam *)0x0,
                       in_stack_00000010);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x28) = 0x9084000;
      *(undefined4 *)(this + 0x2c) = 0xffffffff;
      return;
    }
  }
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x2c) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CGameManialinkFileEntry::SetFolder
// =================================================
void __thiscall
CGameManialinkFileEntry::SetFolder
          (CGameManialinkFileEntry *this,CGameManialinkFileEntry *param_1,CFastStringInt *param_2)
{
{
  ulong uVar1;
  CFastStringInt *unaff_ESI;
  
  if (*(int *)param_1 != 0) {
    uVar1 = CSystemDataFolders::FindDirIndexFromRelPath
                      ((void *)(DAT_00d68c44 + 0x148),(CSystemDataFolders *)0x1,(ulong)param_1,
                       unaff_ESI);
    if (uVar1 != 0xffffffff) {
      *(ulong *)(this + 0x30) = uVar1;
      return;
    }
  }
  *(undefined4 *)(this + 0x30) = 0xfffffffe;
  return;
}
}

