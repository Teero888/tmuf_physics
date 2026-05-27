// Class implementation: CSceneEngine

// =================================================
// Function: CSceneEngine::CSceneEngine
// =================================================
void __thiscall CSceneEngine::CSceneEngine(CSceneEngine *this,CSceneEngine *param_1)
{
{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  CScenePickerManager *unaff_ESI;
  CScenePickerManager *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00acd3d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwEngine::CMwEngine((CMwEngine *)this,(CMwEngine *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  local_c = operator_new(0x660);
  if (local_c == (CScenePickerManager *)0x0) {
    uVar1 = 0;
  }
  else {
    CScenePickerManager::CScenePickerManager(local_c,unaff_ESI);
    uVar1 = extraout_EAX;
  }
  *(undefined4 *)(this + 0x20) = uVar1;
  *(undefined4 *)(this + 0x24) = 0;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CSceneEngine::UpdateAsync
// =================================================
/* WARNING: Removing unreachable block (ram,0x007d1466) */
/* WARNING: Removing unreachable block (ram,0x007d1438) */
/* WARNING: Removing unreachable block (ram,0x007d1490) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneEngine::UpdateAsync(CSceneEngine *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  float fVar2;
  undefined4 unaff_retaddr;
  SSystemTime *in_stack_fffffff4;
  SSystemTime *in_stack_fffffff8;
  
  SSystemTime::SSystemTime(&stack0xfffffff8,in_stack_fffffff4);
  SSystemTime::SetFromLocalTime(&stack0xfffffffc,in_stack_fffffff8);
  fVar1 = (float)_DAT_00b9f6e0;
  fVar2 = (float)_DAT_00b313f8;
  CFastMap<class_CMwId,float>::SetElem
            ((CFastMap<class_CMwId,float> *)&PTR_vftable_00ce1360,
             (CFastMap<class_CMwId,float> *)&DAT_00d6d0b4,(CMwId *)&stack0xfffffffc,
             (float *)((((float)((uint)param_1 >> 0xb & 0x3f) / fVar1) / fVar2) / fVar2 +
                      (float)((uint)param_1 & 0x1f) / fVar1 + (float)_PTR_00b2c178 +
                      ((float)((uint)param_1 >> 5 & 0x3f) / fVar1) / fVar2));
  _DAT_00d6e784 = unaff_retaddr;
  _DAT_00d6e788 = 0;
  _DAT_00d6e78c = 0;
  _DAT_00d6e790 = 0x3f800000;
  return;
}
}

