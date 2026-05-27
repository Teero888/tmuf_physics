// Class implementation: CPlugVisualQuads

// =================================================
// Function: CPlugVisualQuads::BoxQuadAdd
// =================================================
void __thiscall
CPlugVisualQuads::BoxQuadAdd
          (CPlugVisualQuads *this,CPlugVisualQuads *param_1,float param_2,ulong param_3,
          GxColor *param_4)
{
{
  BoxQuadAdd(this,(CPlugVisualQuads *)&stack0xffffffe8,param_2,param_3,(GxColor *)0x0);
  return;
}
}

// =================================================
// Function: CPlugVisualQuads::CPlugVisualQuads
// =================================================
void __thiscall CPlugVisualQuads::CPlugVisualQuads(CPlugVisualQuads *this,CPlugVisualQuads *param_1)
{
{
  CPlugVisual3D *unaff_ESI;
  CPlugVisual3D *unaff_retaddr;
  
  CPlugVisual3D::CPlugVisual3D((CPlugVisual3D *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CPlugVisualQuads::CreateQuadZ
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugVisualQuads::CreateQuadZ
          (CPlugVisualQuads *this,CPlugVisualQuads *param_1,GmVec3 param_2,float param_3,
          float param_4,GxColor *param_5,ulong param_6,GmVec3 *param_7)
{
{
  CPlugVisualQuads *this_00;
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  float unaff_retaddr;
  undefined3 in_stack_00000009;
  float fStack00000020;
  undefined4 in_stack_00000024;
  undefined4 *in_stack_00000028;
  undefined4 *in_stack_00000030;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  
  puVar3 = in_stack_00000028;
  fVar2 = (float)_DAT_00b313b8;
  this_00 = this + 0x78;
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fVar2 * (float)param_5);
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_7,unaff_EDI);
  fStack00000020 = _param_2 + (float)param_5;
  *(float *)pSVar4 = fStack00000020;
  fVar1 = param_3 - unaff_retaddr;
  *(float *)(pSVar4 + 4) = fVar1;
  *(float *)(pSVar4 + 8) = param_4 * fVar2;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_7 + 1),
                      unaff_ESI);
  fVar1 = param_3 - fVar1;
  *(float *)pSVar4 = fVar1;
  *(GmVec3 **)(pSVar4 + 4) = param_7;
  *(GxColor **)(pSVar4 + 8) = param_5;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_7 + 2),
                      unaff_EBP);
  *(undefined4 **)pSVar4 = in_stack_00000028;
  fStack00000020 = (float)param_5 + _param_2;
  *(float *)(pSVar4 + 4) = fStack00000020;
  *(float *)(pSVar4 + 8) = fVar1;
  pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_7 + 3),
                      unaff_EBX);
  *(float *)pSVar4 = fStack00000020;
  fStack00000020 = 5.60519e-45;
  *(undefined4 *)(pSVar4 + 4) = in_stack_00000024;
  *(GmVec3 **)(pSVar4 + 8) = param_7;
  do {
    pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_7,
                        (ulong)pCVar5);
    *(undefined4 *)(pSVar4 + 0x18) = *puVar3;
    *(undefined4 *)(pSVar4 + 0x1c) = puVar3[1];
    *(undefined4 *)(pSVar4 + 0x20) = puVar3[2];
    *(undefined4 *)(pSVar4 + 0x24) = puVar3[3];
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_7;
    pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_7,
                        (ulong)unaff_retaddr);
    *(undefined4 *)(pSVar4 + 0xc) = *in_stack_00000030;
    param_7 = param_7 + 1;
    in_stack_00000028 = (undefined4 *)((int)in_stack_00000028 + -1);
    *(undefined4 *)(pSVar4 + 0x10) = in_stack_00000030[1];
    *(undefined4 *)(pSVar4 + 0x14) = in_stack_00000030[2];
  } while (in_stack_00000028 != (undefined4 *)0x0);
  return;
}
}

