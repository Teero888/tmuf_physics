// Class implementation: CFastRadixSort

// =================================================
// Function: CFastRadixSort::CFastRadixSort
// =================================================
void __thiscall CFastRadixSort::CFastRadixSort(void *this,CFastRadixSort *param_1)
{
{
  CFastRadixSort *unaff_retaddr;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  ResetIndices(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastRadixSort::ResetIndices
// =================================================
void __thiscall CFastRadixSort::ResetIndices(void *this,CFastRadixSort *param_1)
{
{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)this != 0) {
    do {
      *(uint *)(*(int *)((int)this + 8) + uVar1 * 4) = uVar1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)this);
  }
  return;
}
}

// =================================================
// Function: CFastRadixSort::Sort
// =================================================
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

CFastRadixSort * __thiscall
CFastRadixSort::Sort(void *this,CFastRadixSort *param_1,float *param_2,ulong param_3)
{
{
  float fVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  CFastRadixSort *pCVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float *pfVar15;
  CFastRadixSort *unaff_ESI;
  float *pfVar16;
  int local_1400 [129];
  uint auStack_11fc [384];
  int aiStack_bfc [256];
  int aiStack_7fc [255];
  uint auStack_400 [129];
  int local_1fc [126];
  undefined4 local_4;
  
  local_4 = 0x90f3aa;
  if ((param_1 != (CFastRadixSort *)0x0) && (param_2 != (float *)0x0)) {
    *(int *)((int)this + 0x10) = *(int *)((int)this + 0x10) + 1;
    if (param_2 != *(float **)((int)this + 4)) {
      if (*(float **)this < param_2) {
        Resize(this,(CVisionViewportDx9 *)param_2);
      }
      else {
        ResetIndices(this,unaff_ESI);
      }
      *(float **)((int)this + 4) = param_2;
    }
    _memset(auStack_11fc + 0x80,0,0x1000);
    piVar3 = *(int **)((int)this + 8);
    fVar2 = *(float *)(param_1 + *piVar3 * 4);
    pCVar8 = param_1;
    while( true ) {
      if (pCVar8 == param_1 + (int)param_2 * 4) {
        *(int *)((int)this + 0x14) = *(int *)((int)this + 0x14) + 1;
        return this;
      }
      fVar1 = *(float *)(param_1 + *piVar3 * 4);
      piVar3 = piVar3 + 1;
      if (fVar1 < fVar2) break;
      auStack_11fc[(byte)*pCVar8 + 0x80] = auStack_11fc[(byte)*pCVar8 + 0x80] + 1;
      aiStack_bfc[(byte)pCVar8[1]] = aiStack_bfc[(byte)pCVar8[1]] + 1;
      aiStack_7fc[(byte)pCVar8[2]] = aiStack_7fc[(byte)pCVar8[2]] + 1;
      auStack_400[(byte)pCVar8[3] + 1] = auStack_400[(byte)pCVar8[3] + 1] + 1;
      pCVar8 = pCVar8 + 4;
      fVar2 = fVar1;
    }
    for (; pCVar8 != param_1 + (int)param_2 * 4; pCVar8 = pCVar8 + 4) {
      auStack_11fc[(byte)*pCVar8 + 0x80] = auStack_11fc[(byte)*pCVar8 + 0x80] + 1;
      aiStack_bfc[(byte)pCVar8[1]] = aiStack_bfc[(byte)pCVar8[1]] + 1;
      aiStack_7fc[(byte)pCVar8[2]] = aiStack_7fc[(byte)pCVar8[2]] + 1;
      auStack_400[(byte)pCVar8[3] + 1] = auStack_400[(byte)pCVar8[3] + 1] + 1;
    }
    iVar12 = 0;
    iVar9 = 0x20;
    piVar3 = local_1fc + 2;
    do {
      iVar12 = iVar12 + piVar3[-2] + piVar3[-1] + piVar3[1] + *piVar3;
      iVar9 = iVar9 + -1;
      piVar3 = piVar3 + 4;
    } while (iVar9 != 0);
    uVar11 = 0;
    pfVar15 = param_2;
    do {
      if (uVar11 == 3) {
        if ((float *)auStack_400[(byte)param_1[3] + 1] == pfVar15) {
          if ((byte)param_1[3] < 0x80) goto LAB_0090f757;
          pfVar16 = (float *)0x0;
          if (pfVar15 != (float *)0x0) {
            iVar9 = (int)pfVar15 * 4;
            do {
              *(undefined4 *)(*(int *)((int)this + 0xc) + (int)pfVar16 * 4) =
                   *(undefined4 *)(iVar9 + -4 + *(int *)((int)this + 8));
              pfVar16 = (float *)((int)pfVar16 + 1);
              iVar9 = iVar9 + -4;
            } while (pfVar16 < pfVar15);
          }
          uVar7 = *(undefined4 *)((int)this + 8);
          *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0xc);
        }
        else {
          local_1400[1] = iVar12;
          uVar6 = 4;
          do {
            uVar4 = uVar6 + 4;
            *(int *)((int)local_1400 + uVar6 + 4) =
                 *(int *)((int)local_1400 + uVar6) + *(int *)((int)auStack_400 + uVar6);
            uVar6 = uVar4;
          } while (uVar4 < 0x200);
          auStack_11fc[0x7f] = 0;
          puVar5 = auStack_11fc + 0x7e;
          iVar9 = 0x7f;
          piVar3 = (int *)register0x00000010;
          do {
            iVar14 = *piVar3;
            piVar3 = piVar3 + -1;
            *puVar5 = puVar5[1] + iVar14;
            puVar5 = puVar5 + -1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          uVar6 = 0x200;
          do {
            iVar9 = *(int *)((int)auStack_400 + uVar6 + 8);
            piVar3 = (int *)((int)local_1400 + uVar6 + 4);
            *piVar3 = *piVar3 + *(int *)((int)auStack_400 + uVar6 + 4);
            piVar3 = (int *)((int)local_1400 + uVar6 + 8);
            *piVar3 = *piVar3 + iVar9;
            iVar9 = *(int *)((int)auStack_400 + uVar6 + 0x10);
            piVar3 = (int *)((int)local_1400 + uVar6 + 0xc);
            *piVar3 = *piVar3 + *(int *)((int)auStack_400 + uVar6 + 0xc);
            piVar3 = (int *)((int)local_1400 + uVar6 + 0x10);
            *piVar3 = *piVar3 + iVar9;
            uVar6 = uVar6 + 0x10;
          } while (uVar6 < 0x400);
          pfVar16 = (float *)0x0;
          if (pfVar15 != (float *)0x0) {
            do {
              iVar9 = *(int *)(*(int *)((int)this + 8) + (int)pfVar16 * 4);
              piVar3 = local_1400 + (byte)param_1[iVar9 * 4 + 3] + 1;
              if ((byte)param_1[iVar9 * 4 + 3] < 0x80) {
                iVar14 = *piVar3;
                *(int *)(*(int *)((int)this + 0xc) + iVar14 * 4) = iVar9;
                *piVar3 = iVar14 + 1;
                param_1 = (CFastRadixSort *)param_2;
              }
              else {
                *piVar3 = *piVar3 + -1;
                *(int *)(*(int *)((int)this + 0xc) + *piVar3 * 4) = iVar9;
              }
              pfVar16 = (float *)((int)pfVar16 + 1);
            } while (pfVar16 < pfVar15);
          }
          uVar7 = *(undefined4 *)((int)this + 8);
          *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0xc);
        }
LAB_0090f754:
        *(undefined4 *)((int)this + 0xc) = uVar7;
      }
      else {
        pCVar8 = param_1 + uVar11;
        if ((float *)auStack_11fc[uVar11 * 0x100 + (uint)(byte)*pCVar8 + 0x80] != pfVar15) {
          piVar3 = local_1400 + 1;
          puVar5 = auStack_11fc + uVar11 * 0x100 + 0x83;
          local_1400[1] = 0;
          iVar9 = uVar11 * 0x400 - (int)piVar3;
          iVar14 = 0x33;
          do {
            iVar13 = *(int *)((int)auStack_11fc + iVar9 + 0x200 + (int)piVar3) + *piVar3;
            uVar6 = puVar5[-2];
            piVar3[1] = iVar13;
            iVar13 = iVar13 + uVar6;
            uVar6 = puVar5[-1];
            piVar3[2] = iVar13;
            iVar13 = iVar13 + uVar6;
            uVar6 = *puVar5;
            piVar3[3] = iVar13;
            iVar13 = iVar13 + uVar6;
            uVar6 = puVar5[1];
            piVar3[4] = iVar13;
            piVar3[5] = uVar6 + iVar13;
            piVar3 = piVar3 + 5;
            puVar5 = puVar5 + 5;
            iVar14 = iVar14 + -1;
          } while (iVar14 != 0);
          piVar10 = *(int **)((int)this + 8);
          piVar3 = piVar10 + param_3;
          for (; piVar10 != piVar3; piVar10 = piVar10 + 1) {
            iVar9 = *piVar10;
            *(int *)(*(int *)((int)this + 0xc) + local_1400[(byte)pCVar8[iVar9 * 4] + 1] * 4) =
                 iVar9;
            local_1400[(byte)pCVar8[iVar9 * 4] + 1] = local_1400[(byte)pCVar8[iVar9 * 4] + 1] + 1;
          }
          uVar7 = *(undefined4 *)((int)this + 8);
          *(undefined4 *)((int)this + 8) = *(undefined4 *)((int)this + 0xc);
          pfVar15 = (float *)param_3;
          param_1 = (CFastRadixSort *)param_2;
          goto LAB_0090f754;
        }
      }
LAB_0090f757:
      uVar11 = uVar11 + 1;
    } while (uVar11 < 4);
  }
  return this;
}
}

// =================================================
// Function: CFastRadixSort::~CFastRadixSort
// =================================================
void __thiscall CFastRadixSort::~CFastRadixSort(void *this,CFastRadixSort *param_1)
{
{
  operator_delete__(*(void **)((int)this + 0xc));
  operator_delete__(*(void **)((int)this + 8));
  return;
}
}

