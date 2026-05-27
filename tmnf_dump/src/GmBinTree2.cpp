// Class implementation: GmBinTree2

// =================================================
// Function: GmBinTree2::GetCellAt
// =================================================
ulong __thiscall GmBinTree2::GetCellAt(void *this,GmBinTree2 *param_1,GmNat2 *param_2)
{
{
  uint *puVar1;
  byte bVar2;
  char cVar3;
  void *pvVar4;
  SCasterCat *pSVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  void *pvVar9;
  ulong unaff_ESI;
  void *this_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  int in_stack_0000000c;
  
  uVar8 = 0;
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pvVar4 = (void *)CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 4),unaff_EDI);
  bVar2 = *(byte *)this;
  pvVar9 = (void *)(uint)bVar2;
  this_00 = (void *)((int)this + 4);
  if (pvVar4 != (void *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar10,unaff_ESI);
      if ((int)*(uint *)pSVar5 < 0) {
        return (ulong)pCVar10;
      }
      cVar3 = (char)(uVar8 >> 1);
      if ((int)((int)pvVar9 - 2U) < (int)cVar3) {
        iVar7 = 0;
      }
      else {
        iVar7 = 1 << (((char)pvVar9 - cVar3) - 2U & 0x1f);
      }
      uVar6 = uVar8 & 1;
      puVar1 = (uint *)(&stack0x00000000 + uVar6 * 4);
      uVar8 = uVar8 + 1;
      if (*(uint *)(in_stack_0000000c + uVar6 * 4) < *puVar1) {
        pCVar10 = pCVar10 + 1;
        *puVar1 = *puVar1 - iVar7;
      }
      else {
        pCVar10 = pCVar10 + (*(uint *)pSVar5 & 0x7fffffff);
        *puVar1 = *puVar1 + iVar7;
      }
      pvVar9 = pvVar4;
      this_00 = (void *)(uint)bVar2;
    } while (pCVar10 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(1 << (bVar2 - 1 & 0x1f)));
  }
  return (ulong)pCVar10;
}
}

