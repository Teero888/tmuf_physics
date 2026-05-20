// Class implementation: CFastBuffer_struct_CSceneVehicleStruct_SSimulationWheel

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AddNewElem
// =================================================
SLoadedLight * __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(int *)this = *(int *)this + 1;
  return (SLoadedLight *)(*(int *)((int)this + 4) + iVar1 * 0xc);
}
}

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::AllocSetCount
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
// Function: CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::ArchiveCount
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::ArchiveCount
          (void *this,CFastArray<class_CPlugFileSnd*> *param_1,CClassicArchive *param_2)
{
{
  void *pvVar1;
  CFastBuffer<struct_SMeshOctreeCell> *pCVar2;
  ulong unaff_ESI;
  int unaff_EDI;
  
  CClassicArchive::DoNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
  if (*(uint *)this != 0) {
    if ((0x10000000 < *(uint *)this) && (DAT_00d72e8c != (code *)0x0)) {
      (*DAT_00d72e8c)();
    }
    if (*(int *)(param_1 + 8) == 0) {
      pvVar1 = *(void **)((int)this + 4);
      pCVar2 = *(CFastBuffer<struct_SMeshOctreeCell> **)this;
      if (pvVar1 != (void *)0x0) {
        _eh_vector_destructor_iterator_
                  (pvVar1,0xc,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
        operator_delete__((void *)((int)pvVar1 + -4));
      }
      *(undefined4 *)((int)this + 4) = 0;
      *(undefined4 *)((int)this + 8) = 0;
      *(undefined4 *)this = 0;
      InitSize(this,pCVar2,unaff_ESI);
      *(CFastBuffer<struct_SMeshOctreeCell> **)this = pCVar2;
    }
  }
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::InitSize
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::InitSize
          (void *this,CFastBuffer<struct_SMeshOctreeCell> *param_1,ulong param_2)
{
{
  undefined4 *puVar1;
  uint uVar2;
  code *pcVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acc83b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 8) = param_1;
  uVar2 = -(uint)((int)(ZEXT48(param_1) * 0xc >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0xc);
  puVar1 = operator_new__(-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pcVar3 = SPlugGpuLoadFx::~SPlugGpuLoadFx;
    *puVar1 = param_1;
    _eh_vector_constructor_iterator_
              (puVar1 + 1,0xc,(int)param_1,CSceneVehicleStruct::SSimulationWheel::SSimulationWheel,
               SPlugGpuLoadFx::~SPlugGpuLoadFx);
    *(undefined4 **)((int)this + 4) = puVar1 + 1;
    *(undefined4 *)this = 0;
    ExceptionList = pcVar3;
    return;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *unaff_EBX;
  uint *puVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00accaab;
  local_c = ExceptionList;
  pvVar2 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  uVar5 = *(uint *)((int)this + 8);
  puVar7 = (uint *)0x0;
  if (0 < (int)((int)param_1 - uVar5)) {
    if ((int)((int)param_1 - uVar5) <= (int)(uVar5 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar5 >> 1) + uVar5);
    }
    uVar5 = -(uint)((int)(ZEXT48(param_1) * 0xc >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 0xc);
    puVar3 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
    local_4 = 0;
    if (puVar3 != (uint *)0x0) {
      puVar7 = puVar3 + 1;
      *puVar3 = (uint)param_1;
      _eh_vector_constructor_iterator_
                (puVar7,0xc,(int)param_1,CSceneVehicleStruct::SSimulationWheel::SSimulationWheel,
                 SPlugGpuLoadFx::~SPlugGpuLoadFx);
      unaff_EBX = puVar7;
    }
    uVar5 = 0;
    puVar3 = puVar7;
    if (*(int *)this != 0) {
      puVar6 = puVar7 + 2;
      do {
        iVar4 = *(int *)((int)this + 4) + (-8 - (int)puVar7);
        puVar6[-2] = *(uint *)(iVar4 + (int)puVar6);
        puVar6[-1] = *(uint *)((int)puVar6 + iVar4 + 4);
        *puVar6 = *(uint *)((int)puVar6 + iVar4 + 8);
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + 3;
        puVar3 = unaff_EBX;
      } while (uVar5 < *(uint *)this);
    }
    pvVar1 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar1 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar1,0xc,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
      operator_delete__((void *)((int)pvVar1 + -4));
    }
    *(uint **)((int)this + 4) = puVar3;
  }
  ExceptionList = pvVar2;
  return;
}
}

