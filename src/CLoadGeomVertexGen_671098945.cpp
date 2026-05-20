// Class implementation: CLoadGeomVertexGen_671098945

// =================================================
// Function: CLoadGeomVertexGen<671098945>::RecordVertex3InVB
// =================================================
/* WARNING: Removing unreachable block (ram,0x0097782b) */
/* WARNING: Removing unreachable block (ram,0x00977830) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CLoadGeomVertexGen<671098945>::RecordVertex3InVB
          (void *this,CLoadGeomVertexGen<671098945> *param_1,uchar **param_2,GxVertex *param_3,
          ulong param_4)
{
{
  undefined4 *puVar1;
  undefined4 uVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBP;
  uchar **ppuVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000014;
  
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  ppuVar4 = param_2;
  if (param_3 != (GxVertex *)0x0) {
    do {
      puVar1 = *(undefined4 **)param_1;
      *puVar1 = *ppuVar4;
      puVar1[1] = ppuVar4[1];
      puVar1[2] = ppuVar4[2];
      *(int *)param_1 = *(int *)param_1 + 0xc;
      puVar1 = *(undefined4 **)param_1;
      *puVar1 = ppuVar4[3];
      puVar1[1] = ppuVar4[4];
      puVar1[2] = ppuVar4[5];
      *(int *)param_1 = *(int *)param_1 + 0xc;
      param_2 = (uchar **)0x0;
      do {
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                           ((void *)(*(int *)this + 0x5c),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                            (ulong)unaff_ESI);
        puVar1 = *(undefined4 **)param_1;
        uVar2 = *(undefined4 *)(*(int *)(pSVar3 + 4) + 4 + (int)pCVar5 * 8);
        *puVar1 = *(undefined4 *)(*(int *)(pSVar3 + 4) + (int)pCVar5 * 8);
        puVar1[1] = uVar2;
        *(int *)param_1 = *(int *)param_1 + 8;
        param_2 = (uchar **)((int)param_2 + 2);
      } while (param_2 < (uchar **)0x10);
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((void *)(*(int *)this + 0x84),pCVar5,(ulong)unaff_ESI);
      puVar1 = *(undefined4 **)param_1;
      *puVar1 = *(undefined4 *)pSVar3;
      puVar1[1] = *(undefined4 *)(pSVar3 + 4);
      puVar1[2] = *(undefined4 *)(pSVar3 + 8);
      *(int *)param_1 = *(int *)param_1 + 0xc;
      puVar1 = *(undefined4 **)param_1;
      unaff_ESI = pCVar5;
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((void *)(_DAT_00000000 + 0x8c),pCVar5,unaff_EBP);
      *puVar1 = *(undefined4 *)pSVar3;
      puVar1[1] = *(undefined4 *)(pSVar3 + 4);
      puVar1[2] = *(undefined4 *)(pSVar3 + 8);
      *(int *)param_1 = *(int *)param_1 + 0xc;
      pCVar5 = pCVar5 + 1;
      ppuVar4 = ppuVar4 + 10;
    } while (pCVar5 < in_stack_00000014);
  }
  return;
}
}

