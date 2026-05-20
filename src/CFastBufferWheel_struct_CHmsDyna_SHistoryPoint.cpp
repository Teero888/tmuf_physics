// Class implementation: CFastBufferWheel_struct_CHmsDyna_SHistoryPoint

// =================================================
// Function: CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>::InsertNewElemFromStart
// =================================================
SHistoryPoint * __thiscall
CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>::InsertNewElemFromStart
          (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  uint uVar2;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar7;
  uint uVar8;
  undefined4 *puVar9;
  ulong unaff_EDI;
  uint uVar10;
  undefined4 *puVar11;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *unaff_retaddr;
  
  if ((*(int *)((int)this + 0x10) == 0) || (*(int *)this != *(int *)((int)this + 0x10))) {
    pCVar1 = *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 8);
    pCVar7 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(*(int *)this + 1);
    if (pCVar1 < pCVar7) {
      CFastBuffer<struct_CHmsDyna::SHistoryPoint>::SetSizeAtLeast(this,pCVar7,unaff_EDI);
      pCVar3 = pCVar1 + -1;
      if (*(int *)((int)this + 0xc) <= (int)pCVar3) {
        iVar5 = (int)pCVar3 * 0xe0;
        do {
          pCVar7 = pCVar3 + (*(int *)((int)this + 8) - (int)pCVar1);
          pCVar3 = pCVar3 + -1;
          puVar9 = (undefined4 *)(iVar5 + *(int *)((int)this + 4));
          puVar11 = (undefined4 *)((int)pCVar7 * 0xe0 + *(int *)((int)this + 4));
          for (iVar4 = 0x38; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar11 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar11 = puVar11 + 1;
          }
          iVar5 = iVar5 + -0xe0;
          pCVar7 = unaff_retaddr;
        } while (*(int *)((int)this + 0xc) <= (int)pCVar3);
      }
      *(int *)((int)this + 0xc) =
           *(int *)((int)this + 0xc) + (*(int *)((int)this + 8) - (int)pCVar1);
    }
    else if (*(int *)((int)this + 0xc) == 0) {
      *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)((int)this + 0xc) = pCVar1;
    }
    *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this = pCVar7;
  }
  else if (*(int *)((int)this + 0xc) == 0) {
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)((int)this + 8);
  }
  *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
  uVar6 = 0;
  if (param_2 != 0) {
    do {
      uVar10 = *(int *)((int)this + 0xc) + uVar6;
      uVar2 = *(uint *)((int)this + 8);
      uVar8 = uVar10 + 1;
      if (uVar2 <= uVar8) {
        uVar8 = uVar8 - uVar2;
      }
      if (uVar2 <= uVar10) {
        uVar10 = uVar10 - uVar2;
      }
      uVar6 = uVar6 + 1;
      puVar9 = (undefined4 *)(uVar8 * 0xe0 + *(int *)((int)this + 4));
      puVar11 = (undefined4 *)(uVar10 * 0xe0 + *(int *)((int)this + 4));
      for (iVar5 = 0x38; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar11 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar11 = puVar11 + 1;
      }
    } while (uVar6 < param_2);
  }
  uVar6 = *(int *)((int)this + 0xc) + param_2;
  if (*(uint *)((int)this + 8) <= uVar6) {
    uVar6 = uVar6 - *(uint *)((int)this + 8);
  }
  return (SHistoryPoint *)(uVar6 * 0xe0 + *(int *)((int)this + 4));
}
}

// =================================================
// Function: CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>::PushNewElem
// =================================================
SBlockState * __thiscall
CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>::PushNewElem
          (void *this,
          CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1)
{
{
  SHistoryPoint *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = InsertNewElemFromStart
                     (this,(CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *)0x0,unaff_retaddr);
  return (SBlockState *)pSVar1;
}
}

