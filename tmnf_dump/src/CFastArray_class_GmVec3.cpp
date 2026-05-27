// Class implementation: CFastArray_class_GmVec3

// =================================================
// Function: CFastArray<class_GmVec3>::AllocateMore
// =================================================
void __thiscall
CFastArray<class_GmVec3>::AllocateMore
          (void *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,ulong param_2)
{
{
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar1;
  void *pvVar2;
  longlong lVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)this;
  pCVar1 = param_1 + iVar7;
  lVar3 = ZEXT48(pCVar1) * 0xc;
  pvVar4 = operator_new__(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
  if (iVar7 != 0) {
    iVar6 = 0;
    do {
      iVar5 = *(int *)((int)this + 4) + iVar6;
      *(undefined4 *)(iVar6 + (int)pvVar4) = *(undefined4 *)(*(int *)((int)this + 4) + iVar6);
      *(undefined4 *)(iVar6 + 4 + (int)pvVar4) = *(undefined4 *)(iVar5 + 4);
      *(undefined4 *)(iVar6 + 8 + (int)pvVar4) = *(undefined4 *)(iVar5 + 8);
      iVar6 = iVar6 + 0xc;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  pvVar2 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar4;
  *(CFastArray<struct_CDx9DeviceCaps::SFormat> **)this = pCVar1;
  operator_delete__(pvVar2);
  return;
}
}

// =================================================
// Function: CFastArray<class_GmVec3>::InsertAt
// =================================================
void __thiscall
CFastArray<class_GmVec3>::InsertAt
          (void *this,CFastArray<class_CControlBase*> *param_1,ulong param_2,CControlBase **param_3)
{
{
  SBitmapSpecular *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemAt(this,(CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> *)param_1,
                           unaff_retaddr);
  *(CControlBase **)pSVar1 = *param_3;
  *(CControlBase **)(pSVar1 + 4) = param_3[1];
  *(CControlBase **)(pSVar1 + 8) = param_3[2];
  return;
}
}

// =================================================
// Function: CFastArray<class_GmVec3>::SetArray
// =================================================
void __thiscall
CFastArray<class_GmVec3>::SetArray
          (void *this,CFastArray<struct_SPlugGpuLoadFx> *param_1,ulong param_2,
          SPlugGpuLoadFx *param_3)
{
{
  operator_delete__(*(void **)((int)this + 4));
  *(ulong *)((int)this + 4) = param_2;
  *(CFastArray<struct_SPlugGpuLoadFx> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastArray<class_GmVec3>::SetCount
// =================================================
void __thiscall
CFastArray<class_GmVec3>::SetCount
          (void *this,CFastBuffer<class_CSystemFidsFolder*> *param_1,ulong param_2)
{
{
  CFastBuffer<class_CSystemFidsFolder*> *pCVar1;
  void *pvVar2;
  ulong unaff_ESI;
  
  pCVar1 = *(CFastBuffer<class_CSystemFidsFolder*> **)this;
  if (param_1 == pCVar1) {
    return;
  }
  if (*(void **)((int)this + 4) == (void *)0x0) {
    if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      *(CFastBuffer<class_CSystemFidsFolder*> **)this = param_1;
      pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0xc >> 0x20) != 0) |
                              (uint)(ZEXT48(param_1) * 0xc));
      *(void **)((int)this + 4) = pvVar2;
      return;
    }
  }
  else if (param_1 != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
    if (pCVar1 <= param_1) {
      AllocateMore(this,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)(param_1 + -(int)pCVar1),
                   unaff_ESI);
      return;
    }
    CFastArray<struct_CPlugVisual::SSubVisual>::AllocateLess
              (this,(CFastArray<struct_CHmsWaterRegion::SCell> *)(pCVar1 + -(int)param_1),unaff_ESI)
    ;
    return;
  }
  operator_delete__(*(void **)((int)this + 4));
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}
}

