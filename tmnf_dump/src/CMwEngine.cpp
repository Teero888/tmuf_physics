// Class implementation: CMwEngine

// =================================================
// Function: CMwEngine::AllocateGroups
// =================================================
void __thiscall CMwEngine::AllocateGroups(CMwEngine *this,CMwEngine *param_1)
{
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae308b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = (**(code **)(*(int *)this + 0x7c))(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  puVar4 = (uint *)0x0;
  *(uint *)(this + 0x1c) = uVar1;
  if (uVar1 != 0) {
    uVar3 = -(uint)((int)((ulonglong)uVar1 * 0xc >> 0x20) != 0) | (uint)((ulonglong)uVar1 * 0xc);
    puVar2 = operator_new__(-(uint)(0xfffffffb < uVar3) | uVar3 + 4);
    uStack_4 = 0;
    if (puVar2 != (uint *)0x0) {
      puVar4 = puVar2 + 1;
      *puVar2 = uVar1;
      _eh_vector_constructor_iterator_
                (puVar4,0xc,uVar1,
                 CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>,
                 CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>);
    }
    *(uint **)(this + 0x18) = puVar4;
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CMwEngine::CMwEngine
// =================================================
void __thiscall CMwEngine::CMwEngine(CMwEngine *this,CMwEngine *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined ***)this = vftable;
  return;
}
}

