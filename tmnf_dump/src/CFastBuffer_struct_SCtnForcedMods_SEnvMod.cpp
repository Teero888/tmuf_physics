// Class implementation: CFastBuffer_struct_SCtnForcedMods_SEnvMod

// =================================================
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::Add
// =================================================
void __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 8);
  *puVar1 = *(undefined4 *)param_2;
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::ArchiveCount
// =================================================
void __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::ArchiveCount
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
                  (pvVar1,8,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
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
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::CopyFromFastBuffer
// =================================================
void __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::CopyFromFastBuffer
          (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1,
          CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2)
{
{
  undefined4 *puVar1;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_SCtnForcedMods::SEnvMod> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  GmFrustumIso4 *unaff_EDI;
  ulong unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this,unaff_EDI);
  pCVar2 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)GetAllocatedSize(param_2,unaff_ESI);
  SetSizeAtLeast(this,pCVar2,unaff_EBP);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EBX);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_SFastCat>::operator[](param_2,pCVar5,unaff_retaddr);
      puVar1 = (undefined4 *)(*(int *)((int)this + 4) + (int)pCVar5 * 8);
      *puVar1 = *(undefined4 *)pSVar4;
      pCVar5 = pCVar5 + 1;
      puVar1[1] = *(undefined4 *)(pSVar4 + 4);
    } while (pCVar5 < pCVar3);
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)this = pCVar3;
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
// =================================================
ulong __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
          (void *this,CFastBuffer<struct_SCtnForcedMods::SEnvMod> *param_1)
{
{
  return *(ulong *)((int)this + 8);
}
}

// =================================================
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::InitSize
// =================================================
void __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::InitSize
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
  puStack_8 = &LAB_00aafbfb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(CFastBuffer<struct_SMeshOctreeCell> **)((int)this + 8) = param_1;
  uVar2 = -(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 8);
  puVar1 = operator_new__(-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
  local_4 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    pcVar3 = SPlugGpuLoadFx::~SPlugGpuLoadFx;
    *puVar1 = param_1;
    _eh_vector_constructor_iterator_
              (puVar1 + 1,8,(int)param_1,CGameCtnMasterServer::SMedalsInfo::SMedalsInfo,
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
// Function: CFastBuffer<struct_SCtnForcedMods::SEnvMod>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<struct_SCtnForcedMods::SEnvMod>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aad08b;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  uVar5 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar5)) {
    if ((int)((int)param_1 - uVar5) <= (int)(uVar5 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar5 >> 1) + uVar5);
    }
    uVar5 = -(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 8);
    puVar4 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
    local_4 = 0;
    if (puVar4 == (uint *)0x0) {
      puVar7 = (uint *)0x0;
    }
    else {
      puVar7 = puVar4 + 1;
      *puVar4 = (uint)param_1;
      _eh_vector_constructor_iterator_
                (puVar7,8,(int)param_1,CGameCtnMasterServer::SMedalsInfo::SMedalsInfo,
                 SPlugGpuLoadFx::~SPlugGpuLoadFx);
    }
    uVar5 = 0;
    if (*(int *)this != 0) {
      do {
        iVar1 = *(int *)((int)this + 4);
        puVar7[uVar5 * 2] = *(uint *)(iVar1 + uVar5 * 8);
        uVar6 = uVar5 + 1;
        puVar7[uVar5 * 2 + 1] = *(uint *)(iVar1 + uVar5 * 8 + 4);
        uVar5 = uVar6;
      } while (uVar6 < *(uint *)this);
    }
    pvVar2 = *(void **)((int)this + 4);
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    if (pvVar2 != (void *)0x0) {
      _eh_vector_destructor_iterator_
                (pvVar2,8,*(int *)((int)pvVar2 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
      operator_delete__((void *)((int)pvVar2 + -4));
    }
    *(uint **)((int)this + 4) = puVar7;
  }
  ExceptionList = pvVar3;
  return;
}
}

