// Class implementation: CFastArray_struct_SPlugGpuLoadFx

// =================================================
// Function: CFastArray<struct_SPlugGpuLoadFx>::AreEqual
// =================================================
int __thiscall
CFastArray<struct_SPlugGpuLoadFx>::AreEqual
          (void *this,CDx9StateBlock *param_1,CDx9StateBlock *param_2)
{
{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  int *piVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint *puVar8;
  void *in_stack_0000000c;
  
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_0000000c,unaff_ESI);
  if (uVar3 != uVar4) {
    return 0;
  }
  uVar6 = 0;
  if (uVar3 != 0) {
    piVar7 = *(int **)(param_1 + 4);
    puVar8 = (uint *)(*(int *)((int)in_stack_0000000c + 4) + 4);
    iVar5 = *(int *)((int)in_stack_0000000c + 4) - (int)piVar7;
    do {
      if (*piVar7 != *(int *)(iVar5 + (int)piVar7)) {
        return 0;
      }
      uVar1 = *puVar8;
      uVar2 = piVar7[1];
      if (((uVar1 ^ uVar2) & 7) != 0) {
        return 0;
      }
      if (((uVar1 ^ uVar2) & 0x38) != 0) {
        return 0;
      }
      if (((uVar1 ^ uVar2) & 0x7fe00) != 0) {
        return 0;
      }
      if (((uVar1 ^ uVar2) & 0xfff80000) != 0) {
        return 0;
      }
      uVar6 = uVar6 + 1;
      puVar8 = puVar8 + 2;
      piVar7 = piVar7 + 2;
    } while (uVar6 < uVar3);
  }
  return 1;
}
}

// =================================================
// Function: CFastArray<struct_SPlugGpuLoadFx>::CopyFromFastArray
// =================================================
void __thiscall
CFastArray<struct_SPlugGpuLoadFx>::CopyFromFastArray
          (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar5;
  int in_stack_0000000c;
  
  pCVar1 = (CFastBuffer<class_CSystemFidsFolder*> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  SetCount(this,pCVar1,unaff_EBP);
  pCVar5 = (CFastBuffer<class_CSystemFidsFolder*> *)0x0;
  if (pCVar1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    do {
      puVar2 = (undefined4 *)(*(int *)((int)this + 4) + (int)pCVar5 * 8);
      puVar3 = (undefined4 *)(*(int *)(in_stack_0000000c + 4) + (int)pCVar5 * 8);
      *puVar2 = *puVar3;
      pCVar5 = pCVar5 + 1;
      puVar2[1] = puVar2[1] ^ (puVar2[1] ^ puVar3[1]) & 7;
      uVar4 = (puVar3[1] ^ puVar2[1]) & 0x38 ^ puVar2[1];
      puVar2[1] = uVar4;
      uVar4 = (puVar3[1] ^ uVar4) & 0x1c0 ^ uVar4;
      puVar2[1] = uVar4;
      uVar4 = (puVar3[1] ^ uVar4) & 0x7fe00 ^ uVar4;
      puVar2[1] = uVar4;
      puVar2[1] = (puVar3[1] ^ uVar4) & 0x7ffff ^ puVar3[1];
    } while (pCVar5 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CFastArray<struct_SPlugGpuLoadFx>::GetIndexFromAdr
// =================================================
ulong __thiscall
CFastArray<struct_SPlugGpuLoadFx>::GetIndexFromAdr
          (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,SPlugGpuLoadFx *param_2)
{
{
  return (int)param_1 - *(int *)((int)this + 4) >> 3;
}
}

// =================================================
// Function: CFastArray<struct_SPlugGpuLoadFx>::SetArray
// =================================================
void __thiscall
CFastArray<struct_SPlugGpuLoadFx>::SetArray
          (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,ulong param_2,
          SPlugGpuLoadFx *param_3)
{
{
  void *pvVar1;
  undefined4 unaff_EDI;
  code *pcVar2;
  
  pvVar1 = *(void **)((int)this + 4);
  if (pvVar1 != (void *)0x0) {
    pcVar2 = SPlugGpuLoadFx::~SPlugGpuLoadFx;
    _eh_vector_destructor_iterator_
              (pvVar1,8,*(int *)((int)pvVar1 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
    operator_delete__((void *)((int)pvVar1 + -4));
    *(undefined4 *)((int)this + 4) = unaff_EDI;
    *(code **)this = pcVar2;
    return;
  }
  *(ulong *)((int)this + 4) = param_2;
  *(CFastArray<struct_SPlugGpuLoadFx> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastArray<struct_SPlugGpuLoadFx>::SetCount
// =================================================
void __thiscall
CFastArray<struct_SPlugGpuLoadFx>::SetCount
          (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 *puVar4;
  uint uVar5;
  code *pcVar6;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ad98eb;
  local_c = ExceptionList;
  pvVar3 = (void *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    ExceptionList = &LAB_00ad98eb;
    return;
  }
  pvVar2 = *(void **)((int)this + 4);
  if (pvVar2 == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      uVar5 = -(uint)((int)(ZEXT48(param_1) * 8 >> 0x20) != 0) | (uint)(ZEXT48(param_1) * 8);
      puVar4 = operator_new__(-(uint)(0xfffffffb < uVar5) | uVar5 + 4);
      local_4 = 0;
      if (puVar4 == (undefined4 *)0x0) {
        *(undefined4 *)((int)this + 4) = 0;
        ExceptionList = local_c;
        return;
      }
      pcVar6 = SPlugGpuLoadFx::~SPlugGpuLoadFx;
      *puVar4 = param_1;
      _eh_vector_constructor_iterator_
                (puVar4 + 1,8,(int)param_1,CGameCtnMasterServer::SMedalsInfo::SMedalsInfo,
                 SPlugGpuLoadFx::~SPlugGpuLoadFx);
      *(undefined4 **)((int)this + 4) = puVar4 + 1;
      ExceptionList = pcVar6;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                   (ulong)pvVar3);
      ExceptionList = local_8;
      return;
    }
    AllocateLess(this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),
                 (ulong)pvVar3);
    ExceptionList = local_8;
    return;
  }
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_
              (pvVar2,8,*(int *)((int)pvVar2 + -4),SPlugGpuLoadFx::~SPlugGpuLoadFx);
    operator_delete__((void *)((int)pvVar2 + -4));
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  ExceptionList = pvVar3;
  return;
}
}

