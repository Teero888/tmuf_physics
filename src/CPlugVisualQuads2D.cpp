// Class implementation: CPlugVisualQuads2D

// =================================================
// Function: CPlugVisualQuads2D::CPlugVisualQuads2D
// =================================================
void __thiscall
CPlugVisualQuads2D::CPlugVisualQuads2D(CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1)
{
{
  CPlugVisual2D *unaff_ESI;
  
  CPlugVisual2D::CPlugVisual2D((CPlugVisual2D *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CPlugVisualQuads2D::CreateQuad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugVisualQuads2D::CreateQuad
          (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,GmVec2 param_2,float param_3,
          float param_4,GxColor *param_5,ulong param_6,float param_7)
{
{
  float fVar1;
  float fVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  uint uVar4;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CPlugVisualQuads2D *this_00;
  ulong unaff_EDI;
  float10 fVar5;
  undefined3 in_stack_00000009;
  float in_stack_00000020;
  float fStack00000024;
  undefined4 in_stack_0000002c;
  undefined4 *in_stack_00000034;
  float fVar6;
  float in_stack_ffffffe0;
  float fVar7;
  float in_stack_ffffffe8;
  double dVar8;
  ulong uVar9;
  float fStack_8;
  undefined4 uStack_4;
  
  _param_1 = (double)CONCAT35(in_stack_00000009,CONCAT14(param_2,param_1));
  fVar6 = param_3 * (float)_DAT_00b313b8;
  fVar7 = (float)_DAT_00b313b8 * param_4;
  if ((_DAT_00d6eb48 & 1) == 0) {
    _DAT_00d6eb48 = _DAT_00d6eb48 | 1;
    fVar5 = (float10)func_0x009c1b40();
    param_3 = (float)fVar5;
    _DAT_00d6eb44 = 1.0 / param_3;
  }
  this_00 = this + 0x78;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_6,unaff_EDI);
  uStack_4 = SUB84((double)(_param_2 + in_stack_ffffffe0),0);
  fVar1 = in_stack_00000020 + in_stack_00000020;
  fStack_8 = (float)((ulonglong)(double)fVar1 >> 0x20);
  *(float *)pSVar3 = (_param_2 + in_stack_ffffffe0) - (0.0 - in_stack_ffffffe8) * fVar1;
  *(float *)(pSVar3 + 4) = param_3 - in_stack_ffffffe8;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_6,unaff_ESI);
  fVar2 = _DAT_00d6eb44;
  *(float *)(pSVar3 + 8) = _DAT_00d6eb44;
  *(float *)(pSVar3 + 0xc) = -fVar2;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 1),
                      unaff_EBP);
  dVar8 = (double)(param_4 - in_stack_ffffffe8);
  *(float *)pSVar3 = (param_4 - in_stack_ffffffe8) - fVar1;
  *(float *)(pSVar3 + 4) = param_7;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 1),
                      unaff_EBX);
  *(float *)(pSVar3 + 8) = param_7;
  *(float *)(pSVar3 + 0xc) = param_7;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 2),
                      (ulong)fVar6);
  *(float *)pSVar3 =
       (float)(double)CONCAT44(param_4,param_3) -
       ((float)_PTR_00b2c178 + fStack_8) * (float)_param_1;
  fStack00000024 = fStack_8 + param_7;
  *(float *)(pSVar3 + 4) = fStack00000024;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 2),
                      (ulong)in_stack_ffffffe0);
  fVar6 = _DAT_00d6eb44;
  *(float *)(pSVar3 + 8) = _DAT_00d6eb44;
  *(float *)(pSVar3 + 0xc) = fVar6;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 3),
                      (ulong)fVar7);
  uVar9 = (ulong)((ulonglong)dVar8 >> 0x20);
  *(float *)pSVar3 =
       (float)((float10)(double)CONCAT44(uStack_4,fStack_8) -
              (float10)(double)CONCAT44(param_4,param_3));
  *(undefined4 *)(pSVar3 + 4) = in_stack_0000002c;
  pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(param_6 + 3),
                      SUB84(dVar8,0));
  *(undefined4 *)(pSVar3 + 8) = in_stack_0000002c;
  *(float *)(pSVar3 + 0xc) = _DAT_00d6eb44;
  uVar4 = 0;
  do {
    pSVar3 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar4 + param_6),
                        uVar9);
    *(undefined4 *)(pSVar3 + 0x10) = *in_stack_00000034;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(pSVar3 + 0x14) = in_stack_00000034[1];
    *(undefined4 *)(pSVar3 + 0x18) = in_stack_00000034[2];
    *(undefined4 *)(pSVar3 + 0x1c) = in_stack_00000034[3];
  } while (uVar4 < 4);
  return;
}
}

// =================================================
// Function: CPlugVisualQuads2D::SetQuadColors
// =================================================
void __thiscall
CPlugVisualQuads2D::SetQuadColors
          (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2,GxColor *param_3,
          GxColor *param_4,GxColor *param_5,GxColor *param_6)
{
{
  CPlugVisualQuads2D *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  undefined4 *in_stack_0000001c;
  
  this_00 = this + 0x78;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)((int)param_1 * 4);
  pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,pCVar1,unaff_EDI);
  *(undefined4 *)(pSVar2 + 0x10) = *(undefined4 *)param_6;
  *(undefined4 *)(pSVar2 + 0x14) = *(undefined4 *)(param_6 + 4);
  *(undefined4 *)(pSVar2 + 0x18) = *(undefined4 *)(param_6 + 8);
  *(undefined4 *)(pSVar2 + 0x1c) = *(undefined4 *)(param_6 + 0xc);
  pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,pCVar1 + 1,unaff_ESI);
  *(undefined4 *)(pSVar2 + 0x10) = *(undefined4 *)param_6;
  *(undefined4 *)(pSVar2 + 0x14) = *(undefined4 *)(param_6 + 4);
  *(undefined4 *)(pSVar2 + 0x18) = *(undefined4 *)(param_6 + 8);
  *(undefined4 *)(pSVar2 + 0x1c) = *(undefined4 *)(param_6 + 0xc);
  pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,pCVar1 + 2,unaff_retaddr);
  *(undefined4 *)(pSVar2 + 0x10) = *(undefined4 *)param_5;
  *(undefined4 *)(pSVar2 + 0x14) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(pSVar2 + 0x18) = *(undefined4 *)(param_5 + 8);
  *(undefined4 *)(pSVar2 + 0x1c) = *(undefined4 *)(param_5 + 0xc);
  pSVar2 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                     (this_00,pCVar1 + 3,(ulong)param_1);
  *(undefined4 *)(pSVar2 + 0x10) = *in_stack_0000001c;
  *(undefined4 *)(pSVar2 + 0x14) = in_stack_0000001c[1];
  *(undefined4 *)(pSVar2 + 0x18) = in_stack_0000001c[2];
  *(undefined4 *)(pSVar2 + 0x1c) = in_stack_0000001c[3];
  return;
}
}

// =================================================
// Function: CPlugVisualQuads2D::SetQuadCount
// =================================================
void __thiscall
CPlugVisualQuads2D::SetQuadCount(CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2)
{
{
                    /* WARNING: Could not recover jumptable at 0x00862374. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x114))();
  return;
}
}

// =================================================
// Function: CPlugVisualQuads2D::SetQuadUVs
// =================================================
void __thiscall
CPlugVisualQuads2D::SetQuadUVs
          (CPlugVisualQuads2D *this,CPlugVisualQuads2D *param_1,ulong param_2,GmVec2 *param_3,
          GmVec2 *param_4)
{
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong unaff_EDI;
  
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,unaff_EBP);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uVar4 != 0) {
    iVar1 = (int)param_1 * 0x20;
    do {
      pSVar5 = CFastBuffer<struct_SFastCat>::operator[]((void *)param_2,pCVar6,unaff_EDI);
      uVar2 = *(undefined4 *)(param_4 + 4);
      iVar3 = *(int *)(pSVar5 + 4);
      *(undefined4 *)(iVar1 + iVar3) = *(undefined4 *)param_3;
      pCVar6 = pCVar6 + 1;
      *(undefined4 *)(iVar1 + 4 + iVar3) = uVar2;
      uVar2 = *(undefined4 *)(param_4 + 4);
      *(undefined4 *)(iVar1 + 8 + iVar3) = *(undefined4 *)param_4;
      *(undefined4 *)(iVar1 + 0xc + iVar3) = uVar2;
      uVar2 = *(undefined4 *)(param_3 + 4);
      *(undefined4 *)((int)param_1 * 0x20 + 0x18 + iVar3) = *(undefined4 *)param_3;
      *(undefined4 *)((int)param_1 * 0x20 + 0x1c + iVar3) = uVar2;
      uVar2 = *(undefined4 *)(param_3 + 4);
      *(undefined4 *)(uVar4 + iVar3) = *(undefined4 *)param_4;
      *(undefined4 *)(uVar4 + 4 + iVar3) = uVar2;
    } while (pCVar6 < this + 0x5c);
  }
  return;
}
}

