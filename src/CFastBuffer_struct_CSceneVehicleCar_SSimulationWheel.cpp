// Class implementation: CFastBuffer_struct_CSceneVehicleCar_SSimulationWheel

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::AllocSetCount
          (void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar6;
  undefined4 *puVar7;
  void *unaff_EDI;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acc86b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar4 = *(uint *)((int)this + 8);
  pCVar6 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0;
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    uVar4 = -(uint)((int)(ZEXT48(param_1) * 0x2fc >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0x2fc);
    pCVar2 = operator_new__(-(uint)(0xfffffffb < uVar4) | uVar4 + 4);
    local_4 = 0;
    if (pCVar2 != (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0) {
      pCVar6 = pCVar2 + 4;
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)pCVar2 = param_1;
      _eh_vector_constructor_iterator_
                (pCVar6,0x2fc,(int)param_1,CSceneVehicleCar::SSimulationWheel::SSimulationWheel,
                 OnAccessViolation_ConcatToCrashFileName);
    }
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar3 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar7 = (undefined4 *)(*(int *)((int)this + 4) + iVar3);
        pCVar8 = pCVar6 + iVar3;
        for (iVar5 = 0xbf; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pCVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          pCVar8 = pCVar8 + 4;
        }
        iVar3 = iVar3 + 0x2fc;
        param_1 = pCVar2;
      } while (uVar4 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0x2fc,*(int *)((int)pvVar1 + -4),OnAccessViolation_ConcatToCrashFileName);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 4) = pCVar6;
  }
  ExceptionList = unaff_EDI;
  return;
}
}

