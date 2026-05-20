// Class implementation: CFastBuffer_class_GmInt4

// =================================================
// Function: CFastBuffer<class_GmInt4>::AddNewElem
// =================================================
/* WARNING: Control flow encountered bad instruction data */

SLoadedLight * __thiscall
CFastBuffer<class_GmInt4>::AddNewElem
          (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1)
{
{
  *(char *)this = *(char *)this << 1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}
}

// =================================================
// Function: CFastBuffer<class_GmInt4>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<class_GmInt4>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x10 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x10));
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar3 = 0;
      do {
        iVar2 = *(int *)((int)this + 4) + iVar3;
        *(undefined4 *)(iVar3 + (int)pvVar1) = *(undefined4 *)(*(int *)((int)this + 4) + iVar3);
        *(undefined4 *)(iVar3 + 4 + (int)pvVar1) = *(undefined4 *)(iVar2 + 4);
        *(undefined4 *)(iVar3 + 8 + (int)pvVar1) = *(undefined4 *)(iVar2 + 8);
        *(undefined4 *)(iVar3 + 0xc + (int)pvVar1) = *(undefined4 *)(iVar2 + 0xc);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x10;
      } while (uVar4 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

