// Class implementation: CFastArray_class_CCrystalVertex

// =================================================
// Function: >::DeleteOneAt
// =================================================
void __thiscall
CFastArray<class_CCrystalVertex*>::DeleteOneAt
          (void *this,CFastArray<class_CPlugShaderPass*> *param_1,CPlugShaderPass **param_2)
{
{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint uVar4;
  void *pvVar5;
  uint uVar6;
  GxTexCoordSet *unaff_EDI;
  
  uVar4 = CFastArray<class_CGameMenuFrame*>::Find
                    (this,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_EDI);
  puVar2 = *(undefined4 **)(*(int *)((int)this + 4) + uVar4 * 4);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  uVar1 = *(int *)this - 1;
  *(uint *)this = uVar1;
  if (uVar1 != 0) {
    pvVar5 = operator_new__(-(uint)((int)((ulonglong)uVar1 * 4 >> 0x20) != 0) |
                            (uint)((ulonglong)uVar1 * 4));
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        *(undefined4 *)((int)pvVar5 + uVar6 * 4) =
             *(undefined4 *)(*(int *)((int)this + 4) + uVar6 * 4);
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    for (; uVar6 < uVar1; uVar6 = uVar6 + 1) {
      *(undefined4 *)((int)pvVar5 + uVar6 * 4) =
           *(undefined4 *)(*(int *)((int)this + 4) + 4 + uVar6 * 4);
    }
    pvVar3 = *(void **)((int)this + 4);
    *(void **)((int)this + 4) = pvVar5;
    operator_delete__(pvVar3);
    return;
  }
  operator_delete__(*(void **)((int)this + 4));
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
}

