// Class implementation: GmUnit

// =================================================
// Function: GmUnit::ConvertMethodGet
// =================================================
int __cdecl
GmUnit::ConvertMethodGet(CFastString *param_1,EConvertMethod *param_2,CFastStringInt *param_3)
{
{
  int iVar1;
  ulong unaff_ESI;
  char *pcVar2;
  ulong unaff_EDI;
  char *pcVar3;
  bool bVar4;
  undefined4 *in_stack_00000010;
  char *local_8;
  char *local_4;
  
  local_8 = "DegToRad";
  local_4 = (char *)0x8;
  iVar1 = CFastString::CompareNoCase
                    (param_1,(CFastStringInt *)&local_8,(SStringParam *)0x0,unaff_EDI);
  if (iVar1 == 0) {
    *(undefined4 *)param_3 = 1;
    return 1;
  }
  local_4 = "KnotToMs";
  iVar1 = CFastString::CompareNoCase
                    (param_1,(CFastStringInt *)&local_4,(SStringParam *)0x0,unaff_ESI);
  if (iVar1 == 0) {
    *in_stack_00000010 = 3;
    return 1;
  }
  iVar1 = 9;
  bVar4 = true;
  pcVar2 = *(char **)(param_1 + 4);
  pcVar3 = "RadToDeg";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    *in_stack_00000010 = 2;
    return 1;
  }
  iVar1 = 9;
  bVar4 = true;
  pcVar2 = *(char **)(param_1 + 4);
  pcVar3 = "MsToKnot";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    *in_stack_00000010 = 4;
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmUnit::ConvertReal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GmUnit::ConvertReal(EConvertMethod param_1,float param_2)
{
{
  switch(param_1) {
  case 1:
    return (param_2 * (float)_DAT_00b36110) / (float)_DAT_00b36ab8;
  case 2:
    return (param_2 * (float)_DAT_00b36ab8) / (float)_DAT_00b36110;
  case 3:
    return param_2 * (float)_DAT_00b5b9d0;
  case 4:
    return param_2 * (float)_DAT_00b5b9c0;
  default:
    return param_2;
  }
}
}

// =================================================
// Function: GmUnit::ConvertRealString
// =================================================
void __cdecl GmUnit::ConvertRealString(EConvertMethod param_1,CFastStringInt *param_2)
{
{
  CFastStringInt *this;
  undefined *puVar1;
  ulong unaff_ESI;
  float *unaff_EDI;
  CFastString *in_stack_0000000c;
  SStringParam *pSVar2;
  undefined *local_18;
  CFastString local_14 [4];
  undefined4 local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  this = param_2;
  local_8 = &LAB_00ade478;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 != 0) {
    pSVar2 = (SStringParam *)0x0;
    local_18 = PTR_DAT_00bbf7d8;
    local_4 = 0;
    CFastStringInt::GetAscii
              (param_2,(CFastStringInt *)&stack0xffffffe4,
               (CFastString *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
    CFastString::GetReal((CFastString *)&local_18,(CFastString *)&param_2,unaff_EDI);
    in_stack_0000000c = (CFastString *)ConvertReal(param_1,(float)in_stack_0000000c);
    CFastString::SetReal(local_14,in_stack_0000000c,4.2039e-45,unaff_ESI);
    local_8 = local_c;
    local_4 = local_10;
    CFastStringInt::SetString(this,(CFastStringInt *)&local_8,pSVar2);
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar1 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar1 = local_8 + -4;
      }
      operator_delete__(puVar1);
    }
  }
  ExceptionList = (void *)param_1;
  return;
}
}

