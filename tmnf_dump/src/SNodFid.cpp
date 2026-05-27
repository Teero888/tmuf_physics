// Class implementation: SNodFid

// =================================================
// Function: SNodFid::SetNoDuplicate
// =================================================
void __thiscall SNodFid::SetNoDuplicate(void *this,SNodFid *param_1,CMwNod *param_2)
{
{
  int iVar1;
  CMwNod *pCVar2;
  CSystemEngine *extraout_EAX;
  CSystemFids *pCVar3;
  CSystemFidFile *pCVar4;
  void *pvVar5;
  undefined *puVar6;
  SStringParam *unaff_EBX;
  undefined1 uStack0000000c;
  void *in_stack_00000010;
  undefined1 uStack00000014;
  CSystemFids *pCVar7;
  CFastStringInt *in_stack_ffffffdc;
  int *piVar8;
  CSystemFid *pCVar9;
  undefined *local_18;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_4 = (undefined *)0xffffffff;
  local_8 = &LAB_00acba20;
  local_c = ExceptionList;
  pCVar2 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_c;
  *(SNodFid **)this = param_1;
  CMwNod::MwAddRef((CMwNod *)param_1,pCVar2);
  iVar1 = *(int *)(param_1 + 8);
  *(int *)((int)this + 4) = iVar1;
  if (iVar1 == 0) {
    piVar8 = (int *)0x0;
    DAT_00d6ced0 = DAT_00d6ced0 + 1;
    pCVar9 = (CSystemFid *)PTR_DAT_00bbf7d8;
    CFastString::Format((CFastString *)&stack0xffffffe0,(CFastString *)&stack0xffffffe0,
                        "__FakeMobilDuplicate\\Nod%d");
    local_4 = local_18;
    CFastStringInt::CFastStringInt(local_10,(CFastStringInt *)&local_8,unaff_EBX);
    pCVar7 = (CSystemFids *)0x0;
    uStack0000000c = 1;
    pCVar3 = CSystemEngine::GetLocationBuffer(DAT_00d6ce94,extraout_EAX);
    pCVar4 = CSystemEngine::FindOrAddFidAt
                       (DAT_00d6ce94,(CSystemEngine *)pCVar3,pCVar7,in_stack_ffffffdc,piVar8);
    uStack00000014 = 0;
    if (PTR_DAT_00bbf7dc != (undefined *)0x0) {
      if ((bRamffffffff & 0x80) == 0) {
        pvVar5 = (void *)0xfffffffe;
      }
      else {
        pvVar5 = (void *)0xfffffffc;
      }
      operator_delete__(pvVar5);
      local_4 = (undefined *)0x0;
    }
    CSystemEngine::BindFidNod(DAT_00d6ce94,*(CSystemEngine **)this,(CMwNod *)pCVar4,pCVar9);
    if (local_4 != PTR_DAT_00bbf7d8) {
      puVar6 = local_4 + -1;
      if ((local_4[-1] & 0x80) != 0) {
        puVar6 = local_4 + -4;
      }
      operator_delete__(puVar6);
    }
  }
  ExceptionList = in_stack_00000010;
  return;
}
}

