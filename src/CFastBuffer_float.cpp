// Class implementation: CFastBuffer_float

// =================================================
// Function: CFastBuffer<float>::Add
// =================================================
void __thiscall
CFastBuffer<float>::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  int iVar1;
  ulong unaff_EDI;
  
  iVar1 = *(int *)this;
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1),unaff_EDI);
  *(undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 4) = *(undefined4 *)param_2;
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar1 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<float>::AllocSetCount
// =================================================
void __thiscall
CFastBuffer<float>::AllocSetCount(void *this,CFastBuffer<class_GxVertex2> *param_1,ulong param_2)
{
{
  ulong unaff_EDI;
  
  SetSizeAtLeast(this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)param_1,unaff_EDI);
  *(CFastBuffer<class_GxVertex2> **)this = param_1;
  return;
}
}

// =================================================
// Function: CFastBuffer<float>::ArchiveCountAndElems
// =================================================
void __thiscall
CFastBuffer<float>::ArchiveCountAndElems
          (void *this,CFastArray<struct_SOldLetter> *param_1,CClassicArchive *param_2)
{
{
  CFastArray<struct_SOldLetter> *this_00;
  ulong unaff_ESI;
  int unaff_EDI;
  ulong unaff_retaddr;
  
  this_00 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    CClassicArchive::WriteNatural((CClassicArchive *)param_1,this,(ulong *)0x1,0,unaff_EDI);
    CClassicArchive::WriteData
              ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),
               (void *)(*(int *)this * 4),unaff_ESI);
    return;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,unaff_EDI);
  if (((CClassicArchive *)0x10000000 < param_2) && (DAT_00d72e8c != (code *)0x0)) {
    (*DAT_00d72e8c)();
  }
  AllocSetCount(this,(CFastBuffer<class_GxVertex2> *)param_2,unaff_ESI);
  CClassicArchive::ReadData
            ((CClassicArchive *)this_00,*(CClassicArchive **)((int)this + 4),
             (void *)(*(int *)this * 4),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastBuffer<float>::ReplaceByLastAt
// =================================================
void __thiscall
CFastBuffer<float>::ReplaceByLastAt
          (void *this,CFastBufferRef<class_CGameMobil> *param_1,ulong param_2,ulong param_3)
{
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = (*(int *)this - (int)param_1) - param_2;
  if (param_2 <= uVar4) {
    uVar4 = param_2;
  }
  iVar2 = *(int *)this - uVar4;
  uVar6 = 0;
  if (3 < (int)uVar4) {
    iVar7 = (uVar4 - 4 >> 2) + 1;
    uVar6 = iVar7 * 4;
    iVar3 = iVar2 * 4;
    iVar5 = (int)param_1 * 4;
    do {
      *(undefined4 *)(iVar5 + *(int *)((int)this + 4)) =
           *(undefined4 *)(iVar3 + *(int *)((int)this + 4));
      iVar7 = iVar7 + -1;
      *(undefined4 *)(iVar5 + 4 + *(int *)((int)this + 4)) =
           *(undefined4 *)(iVar3 + 4 + *(int *)((int)this + 4));
      *(undefined4 *)(iVar5 + 8 + *(int *)((int)this + 4)) =
           *(undefined4 *)(iVar3 + 8 + *(int *)((int)this + 4));
      *(undefined4 *)(iVar5 + 0xc + *(int *)((int)this + 4)) =
           *(undefined4 *)(iVar3 + 0xc + *(int *)((int)this + 4));
      iVar3 = iVar3 + 0x10;
      iVar5 = iVar5 + 0x10;
    } while (iVar7 != 0);
  }
  if (uVar4 <= uVar6) {
    *(ulong *)this = *(int *)this - param_2;
    return;
  }
  iVar3 = (int)(param_1 + uVar6) * 4;
  iVar2 = (iVar2 + uVar6) * 4;
  iVar5 = uVar4 - uVar6;
  do {
    puVar1 = (undefined4 *)(iVar2 + *(int *)((int)this + 4));
    iVar2 = iVar2 + 4;
    *(undefined4 *)(iVar3 + *(int *)((int)this + 4)) = *puVar1;
    iVar3 = iVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(ulong *)this = *(int *)this - param_2;
  return;
}
}

// =================================================
// Function: CFastBuffer<float>::SetSizeAtLeast
// =================================================
void __thiscall
CFastBuffer<float>::SetSizeAtLeast
          (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2)
{
{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((int)this + 8);
  if (0 < (int)((int)param_1 - uVar3)) {
    if ((int)((int)param_1 - uVar3) <= (int)(uVar3 >> 1)) {
      param_1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)((uVar3 >> 1) + uVar3);
    }
    pvVar2 = operator_new__(-(uint)((int)(ZEXT48(param_1) * 4 >> 0x20) != 0) |
                            (uint)(ZEXT48(param_1) * 4));
    uVar3 = 0;
    if (*(int *)this != 0) {
      do {
        iVar1 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        *(undefined4 *)((int)pvVar2 + uVar3 * 4 + -4) =
             *(undefined4 *)(*(int *)((int)this + 4) + iVar1);
      } while (uVar3 < *(uint *)this);
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8) = param_1;
    operator_delete__(*(void **)((int)this + 4));
    *(void **)((int)this + 4) = pvVar2;
  }
  return;
}
}

