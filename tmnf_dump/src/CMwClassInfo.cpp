// Class implementation: CMwClassInfo

// =================================================
// Function: CMwClassInfo::BuildTree
// =================================================
void __thiscall CMwClassInfo::BuildTree(CMwClassInfo *this,CMwClassInfo *param_1)
{
{
  char *unaff_ESI;
  CMwNod *unaff_retaddr;
  ulong in_stack_00000008;
  
  do {
    if (*(CMwClassInfo **)(this + 8) != (CMwClassInfo *)0x0) {
      AddChild(*(CMwClassInfo **)(this + 8),(SGridAddChildContext *)this,unaff_ESI,unaff_retaddr,
               (char *)param_1,in_stack_00000008);
    }
    this = *(CMwClassInfo **)(this + 0x18);
  } while (this != (CMwClassInfo *)0x0);
  return;
}
}

// =================================================
// Function: CMwClassInfo::FindFromClassName
// =================================================
CMwClassInfo * __cdecl CMwClassInfo::FindFromClassName(CFastString *param_1)
{
{
  char cVar1;
  char *pcVar2;
  int extraout_EAX;
  int *unaff_ESI;
  CMwClassInfo *pCVar3;
  int *unaff_EDI;
  char *local_8;
  int local_4;
  
  pCVar3 = DAT_00d73ba8;
  if (DAT_00d73ba8 == (CMwClassInfo *)0x0) {
    return (CMwClassInfo *)0x0;
  }
  do {
    local_8 = *(char **)(pCVar3 + 0x14);
    if (local_8 == (char *)0x0) {
      local_4 = 0;
    }
    else {
      pcVar2 = local_8;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      local_4 = (int)pcVar2 - (int)(local_8 + 1);
    }
    CFastString::Compare(param_1,(SParam_Fids *)&local_8,(SParam *)0x0,unaff_EDI,unaff_ESI);
  } while ((extraout_EAX != 0) &&
          (pCVar3 = *(CMwClassInfo **)(pCVar3 + 0x18), pCVar3 != (CMwClassInfo *)0x0));
  return pCVar3;
}
}

// =================================================
// Function: CMwClassInfo::IsMwParamIdEqualName
// =================================================
int __thiscall
CMwClassInfo::IsMwParamIdEqualName
          (CMwClassInfo *this,CMwClassInfo *param_1,ulong param_2,char *param_3,int param_4)
{
{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  
  if (((this == (CMwClassInfo *)0x0) || (((uint)param_1 & 0xfffff000) != *(uint *)(this + 4))) ||
     (*(uint *)(this + 0x24) <= ((uint)param_1 & 0xfff))) {
    return 0;
  }
  pbVar2 = *(byte **)(*(int *)(*(int *)(this + 0x20) + ((uint)param_1 & 0xfff) * 4) + 0x10);
  while( true ) {
    bVar1 = *(byte *)param_2;
    bVar3 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = *(byte *)(param_2 + 1);
    bVar3 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) break;
    param_2 = param_2 + 2;
    pbVar2 = pbVar2 + 2;
    if (bVar1 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar3 == (uint)(bVar3 != 0));
}
}

// =================================================
// Function: CMwClassInfo::MwGetNearestFather
// =================================================
ulong __thiscall
CMwClassInfo::MwGetNearestFather
          (CMwClassInfo *this,CMwClassInfo *param_1,ulong param_2,ulong *param_3)
{
{
  CMwClassInfo *pCVar1;
  
  do {
    pCVar1 = (CMwClassInfo *)0x0;
    if (param_1 != (CMwClassInfo *)0x0) {
      do {
        if (*(int *)(this + 4) == *(int *)(param_2 + (int)pCVar1 * 4)) break;
        pCVar1 = pCVar1 + 1;
      } while (pCVar1 < param_1);
    }
    if (pCVar1 != param_1) {
      return (ulong)pCVar1;
    }
    this = *(CMwClassInfo **)(this + 8);
    if (this == (CMwClassInfo *)0x0) {
      return 0xffffffff;
    }
  } while( true );
}
}

