// Class implementation: CFastArray_class_GxColor

// =================================================
// Function: CFastArray<class_GxColor>::AllocateLess
// =================================================
void __thiscall
CFastArray<class_GxColor>::AllocateLess
          (void *this,CFastArray<struct_CHmsWaterRegion::SCell> *param_1,ulong param_2)
{
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  CFastArray<struct_CHmsWaterRegion::SCell> *pCVar5;
  
  pCVar5 = (CFastArray<struct_CHmsWaterRegion::SCell> *)(*(int *)this - (int)param_1);
  pvVar2 = operator_new__(-(uint)((int)(ZEXT48(pCVar5) * 0x10 >> 0x20) != 0) |
                          (uint)(ZEXT48(pCVar5) * 0x10));
  if (pCVar5 != (CFastArray<struct_CHmsWaterRegion::SCell> *)0x0) {
    iVar4 = 0;
    param_1 = pCVar5;
    do {
      iVar3 = *(int *)((int)this + 4) + iVar4;
      *(undefined4 *)(iVar4 + (int)pvVar2) = *(undefined4 *)(*(int *)((int)this + 4) + iVar4);
      *(undefined4 *)(iVar4 + 4 + (int)pvVar2) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar4 + 8 + (int)pvVar2) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar4 + 0xc + (int)pvVar2) = *(undefined4 *)(iVar3 + 0xc);
      iVar4 = iVar4 + 0x10;
      param_1 = param_1 + -1;
    } while (param_1 != (CFastArray<struct_CHmsWaterRegion::SCell> *)0x0);
  }
  pvVar1 = *(void **)((int)this + 4);
  *(void **)((int)this + 4) = pvVar2;
  *(CFastArray<struct_CHmsWaterRegion::SCell> **)this = pCVar5;
  operator_delete__(pvVar1);
  return;
}
}

