// Class implementation: CLoadGeomVertexGen_2113

// =================================================
// Function: CLoadGeomVertexGen<2113>::RecordVertex3InVB
// =================================================
/* WARNING: Removing unreachable block (ram,0x0097772b) */
/* WARNING: Removing unreachable block (ram,0x00977730) */

void __thiscall
CLoadGeomVertexGen<2113>::RecordVertex3InVB
          (void *this,CLoadGeomVertexGen<671098945> *param_1,uchar **param_2,GxVertex *param_3,
          ulong param_4)
{
{
  undefined4 *puVar1;
  undefined4 uVar2;
  SCasterCat *pSVar3;
  uchar **ppuVar4;
  GxVertex *pGVar5;
  ulong unaff_EDI;
  
  pGVar5 = (GxVertex *)0x0;
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
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,unaff_EDI);
        puVar1 = *(undefined4 **)param_1;
        uVar2 = *(undefined4 *)(*(int *)(pSVar3 + 4) + 4 + (int)pGVar5 * 8);
        *puVar1 = *(undefined4 *)(*(int *)(pSVar3 + 4) + (int)pGVar5 * 8);
        puVar1[1] = uVar2;
        *(int *)param_1 = *(int *)param_1 + 8;
        param_3 = param_3 + 1;
        param_2 = (uchar **)((int)param_2 + 2);
      } while (param_2 < (uchar **)0x10);
      pGVar5 = pGVar5 + 1;
      ppuVar4 = ppuVar4 + 10;
    } while (pGVar5 < param_3);
  }
  return;
}
}

