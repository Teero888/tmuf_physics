// Class implementation: CFastRectTable_int

// =================================================
// Function: CFastRectTable<int>::AddColumn
// =================================================
ulong __thiscall CFastRectTable<int>::AddColumn(void *this,CFastRectTable<int> *param_1)
{
{
  CFastRectTable<int> *pCVar1;
  ulong unaff_EDI;
  
  pCVar1 = (CFastRectTable<int> *)(*(int *)((int)this + 8) + 1);
  SetAllocColumnCountAtLeast(this,pCVar1,unaff_EDI);
  *(CFastRectTable<int> **)((int)this + 8) = pCVar1;
  return (ulong)pCVar1;
}
}

// =================================================
// Function: CFastRectTable<int>::AddLine
// =================================================
void __thiscall
CFastRectTable<int>::AddLine
          (void *this,CPlugVisualLines2D *param_1,GmVec2 *param_2,GmVec2 *param_3,GxColor *param_4)
{
{
  CFastRectTable<int> *pCVar1;
  ulong unaff_EDI;
  
  pCVar1 = (CFastRectTable<int> *)(*(int *)((int)this + 4) + 1);
  SetAllocLineCountAtLeast(this,pCVar1,unaff_EDI);
  *(CFastRectTable<int> **)((int)this + 4) = pCVar1;
  return;
}
}

// =================================================
// Function: CFastRectTable<int>::CFastRectTable<int>
// =================================================
void __thiscall CFastRectTable<int>::CFastRectTable<int>(void *this,CFastRectTable<int> *param_1)
{
{
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  return;
}
}

// =================================================
// Function: CFastRectTable<int>::Get
// =================================================
CMwNod * __thiscall
CFastRectTable<int>::Get
          (void *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,ulong *param_4)
{
{
  return (CMwNod *)(*(int *)this + (int)(param_2 + *(int *)((int)this + 0x10) * (int)param_1) * 4);
}
}

// =================================================
// Function: CFastRectTable<int>::ReplaceColumnByLastAt
// =================================================
void __thiscall
CFastRectTable<int>::ReplaceColumnByLastAt(void *this,CFastRectTable<int> *param_1,ulong param_2)
{
{
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + -1;
  return;
}
}

// =================================================
// Function: CFastRectTable<int>::ReplaceLineByLastAt
// =================================================
void __thiscall
CFastRectTable<int>::ReplaceLineByLastAt(void *this,CFastRectTable<int> *param_1,ulong param_2)
{
{
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + -1;
  return;
}
}

// =================================================
// Function: CFastRectTable<int>::SetAllocColumnCountAtLeast
// =================================================
void __thiscall
CFastRectTable<int>::SetAllocColumnCountAtLeast
          (void *this,CFastRectTable<int> *param_1,ulong param_2)
{
{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar5 = *(uint *)((int)this + 0x10);
  if (0 < (int)((int)param_1 - uVar5)) {
    if ((int)((int)param_1 - uVar5) <= (int)(uVar5 >> 1)) {
      param_1 = (CFastRectTable<int> *)((uVar5 >> 1) + uVar5);
    }
    lVar1 = (ulonglong)(uint)(*(int *)((int)this + 0xc) * (int)param_1) * 4;
    puVar2 = operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar5 = 0;
    puVar6 = puVar2;
    if (*(int *)((int)this + 4) != 0) {
      do {
        uVar3 = 0;
        puVar4 = puVar6;
        if (*(int *)((int)this + 8) != 0) {
          do {
            *puVar4 = *(undefined4 *)
                       (*(int *)this + (*(int *)((int)this + 0x10) * uVar5 + uVar3) * 4);
            uVar3 = uVar3 + 1;
            puVar4 = puVar4 + 1;
          } while (uVar3 < *(uint *)((int)this + 8));
        }
        uVar5 = uVar5 + 1;
        puVar6 = puVar6 + (int)param_1;
      } while (uVar5 < *(uint *)((int)this + 4));
    }
    *(CFastRectTable<int> **)((int)this + 0x10) = param_1;
    operator_delete__(*(void **)this);
    *(undefined4 **)this = puVar2;
  }
  return;
}
}

// =================================================
// Function: CFastRectTable<int>::SetAllocLineCountAtLeast
// =================================================
void __thiscall
CFastRectTable<int>::SetAllocLineCountAtLeast(void *this,CFastRectTable<int> *param_1,ulong param_2)
{
{
  longlong lVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)((int)this + 0xc);
  if (0 < (int)((int)param_1 - uVar5)) {
    if ((int)((int)param_1 - uVar5) <= (int)(uVar5 >> 1)) {
      param_1 = (CFastRectTable<int> *)((uVar5 >> 1) + uVar5);
    }
    lVar1 = (ulonglong)(uint)(*(int *)((int)this + 0x10) * (int)param_1) * 4;
    pvVar3 = operator_new__(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    uVar5 = 0;
    if (*(int *)((int)this + 4) != 0) {
      do {
        uVar4 = 0;
        if (*(int *)((int)this + 8) != 0) {
          do {
            iVar2 = (*(int *)((int)this + 0x10) * uVar5 + uVar4) * 4;
            uVar4 = uVar4 + 1;
            *(undefined4 *)(iVar2 + (int)pvVar3) = *(undefined4 *)(iVar2 + *(int *)this);
          } while (uVar4 < *(uint *)((int)this + 8));
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)((int)this + 4));
    }
    *(CFastRectTable<int> **)((int)this + 0xc) = param_1;
    operator_delete__(*(void **)this);
    *(void **)this = pvVar3;
  }
  return;
}
}

