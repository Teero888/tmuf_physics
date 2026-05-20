// Class implementation: CFastBuffer_class_GxVertex

// =================================================
// Function: CFastBuffer<class_GxVertex>::Add
// =================================================
void __thiscall
CFastBuffer<class_GxVertex>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  int iVar2;
  ulong unaff_EDI;
  undefined4 *puVar3;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  puVar3 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 0x28);
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    puVar3 = puVar3 + 1;
  }
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GxVertex>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<class_GxVertex>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar1 = (*(int *)this - (int)param_1) - param_2;
  uVar5 = param_2;
  if (uVar1 < param_2) {
    uVar5 = uVar1;
  }
  if (uVar5 != 0) {
    iVar4 = (int)param_1 * 0x28;
    iVar2 = (*(int *)this - uVar5) * 0x28;
    do {
      puVar6 = (undefined4 *)(iVar2 + *(int *)((int)this + 4));
      puVar7 = (undefined4 *)(iVar4 + *(int *)((int)this + 4));
      iVar2 = iVar2 + 0x28;
      iVar4 = iVar4 + 0x28;
      uVar5 = uVar5 - 1;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    } while (uVar5 != 0);
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GxVertex>::SetBuffer
// =================================================
void __thiscall
CFastBuffer<class_GxVertex>::SetBuffer
          (void *this,CFastBuffer<class_GxVertex> *param_1,ulong param_2,GxVertex *param_3)
{
{
  operator_delete__(*(void **)((int)this + 4));
  *(ulong *)((int)this + 4) = param_2;
  *(CFastBuffer<class_GxVertex> **)this = param_1;
  *(CFastBuffer<class_GxVertex> **)((int)this + 8) = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<class_GxVertex>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<class_GxVertex>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar4)) {
    if ((int)((int)param_1 - uVar4) <= (int)(uVar4 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar4 >> 1) + uVar4);
    }
    pvVar1 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 0x28 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 0x28));
    uVar4 = 0;
    if (*(int *)this != 0) {
      iVar2 = 0;
      do {
        uVar4 = uVar4 + 1;
        puVar5 = (undefined4 *)(*(int *)((int)this + 4) + iVar2);
        puVar6 = (undefined4 *)(iVar2 + (int)pvVar1);
        for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        iVar2 = iVar2 + 0x28;
      } while (uVar4 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar1;
  }
  return;
}
}

