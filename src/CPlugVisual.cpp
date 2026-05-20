// Class implementation: CPlugVisual

// =================================================
// Function: CPlugVisual::AddTexCoordSet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CPlugVisual::AddTexCoordSet
          (CPlugVisual *this,CPlugVisualSprite *param_1,float param_2,float param_3,ulong param_4,
          float param_5,float param_6)
{
{
  CPlugVisual *this_00;
  int iVar1;
  ulong uVar2;
  uint uVar3;
  SNewTriangleVert *pSVar4;
  float *pfVar5;
  uint uVar6;
  int iVar7;
  uint unaff_EBX;
  SFormat *pSVar8;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar9;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ad6218;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 0x5c;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this_00,(CFastBuffer<class_CCrystalFace*> *)
                             (DAT_00cca150 ^ (uint)&stack0xffffffdc));
  if (uVar2 < 8) {
    uVar3 = (**(code **)(*(int *)this + 0xbc))();
    uStack_10 = 0x100;
    local_c = (void *)0x0;
    pCVar10 = (CFastBuffer<class_CCrystalFace*> *)0x0;
    pCVar9 = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)&uStack_10;
    pSVar8 = (SFormat *)0x86050a;
    (**(code **)(*(int *)this + 0x128))();
    CFastArray<class_GxTexCoordSet>::AddTail
              (this_00,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0xffffffe4,pSVar8);
    local_8 = (undefined1 *)0xffffffff;
    if ((unaff_EBX & 0x100) != 0) {
      operator_delete__((void *)0x0);
    }
    pSVar4 = CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::GetLastElem
                       (this_00,pCVar9);
    if (((_DAT_00bae7c0 <= ABS((float)param_1 - 1.0)) || (_DAT_00bae7c0 <= ABS(param_2 - 1.0))) &&
       (*pSVar4 == (SNewTriangleVert)0x0)) {
      iVar1 = *(int *)(pSVar4 + 4);
      uVar6 = 0;
      if (3 < (int)uVar3) {
        iVar7 = (uVar3 - 4 >> 2) + 1;
        uVar6 = iVar7 * 4;
        pfVar5 = (float *)(iVar1 + 8);
        do {
          iVar7 = iVar7 + -1;
          pfVar5[-2] = pfVar5[-2] * (float)param_1 + (float)param_4;
          pfVar5[-1] = pfVar5[-1] * param_2 + param_5;
          *pfVar5 = *pfVar5 * (float)param_1 + (float)param_4;
          pfVar5[1] = param_2 * pfVar5[1] + param_5;
          pfVar5[2] = pfVar5[2] * (float)param_1 + (float)param_4;
          pfVar5[3] = pfVar5[3] * param_2 + param_5;
          pfVar5[4] = pfVar5[4] * (float)param_1 + (float)param_4;
          pfVar5[5] = param_2 * pfVar5[5] + param_5;
          pfVar5 = pfVar5 + 8;
        } while (iVar7 != 0);
      }
      while (uVar6 < uVar3) {
        iVar7 = uVar6 * 8;
        uVar6 = uVar6 + 1;
        *(float *)(iVar1 + -8 + uVar6 * 8) =
             *(float *)(iVar1 + iVar7) * (float)param_1 + (float)param_4;
        *(float *)(iVar1 + -4 + uVar6 * 8) = *(float *)(iVar1 + -4 + uVar6 * 8) * param_2 + param_5;
      }
    }
    if (((*(uint *)(this + 0x1c) & 0x400) == 0) &&
       (*(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x400, DAT_00d6eb04 != (undefined4 *)0x0))
    {
      (**(code **)*DAT_00d6eb04)(this);
    }
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar10);
    uVar2 = uVar2 - 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  ExceptionList = local_8;
  return uVar2;
}
}

// =================================================
// Function: CPlugVisual::CPlugVisual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugVisual::CPlugVisual(CPlugVisual *this,CPlugVisual *param_1,CPlugVisual *param_2)
{
{
  uint uVar1;
  undefined4 uVar2;
  CFastArray<class_CManoeuvre*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwId *unaff_EDI;
  void *in_stack_00000010;
  CPlugVisual *pCVar3;
  CFastArray<class_CManoeuvre*> *pCVar4;
  CFastArray<class_CManoeuvre*> *pCVar5;
  
  pCVar5 = (CFastArray<class_CManoeuvre*> *)&LAB_00ad6158;
  pCVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)param_1,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4))
  ;
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x18,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x20,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x2c,unaff_EBX);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x54,(CFastArray<class_CManoeuvre*> *)pCVar3);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x5c,pCVar4);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 100,pCVar5);
  uVar1 = *(uint *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x14) = 0;
  *(uint *)(this + 0x1c) = uVar1 & 0xfff9fff8 | 0x80450;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  uVar2 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x40) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x44) = uVar2;
  *(undefined4 *)(this + 0x48) = uVar2;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  ExceptionList = in_stack_00000010;
  return;
}
}

// =================================================
// Function: CPlugVisual::EnableVertexColor
// =================================================
void __thiscall CPlugVisual::EnableVertexColor(CPlugVisual *this,CPlugVisual *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x1c);
  if ((uVar1 >> 8 & 1) != (uint)(param_1 != (CPlugVisual *)0x0)) {
    uVar1 = ((uint)(param_1 != (CPlugVisual *)0x0) << 8 ^ uVar1) & 0x100 ^ uVar1;
    *(uint *)(this + 0x1c) = uVar1;
    if ((uVar1 & 0x10) == 0) {
      *(uint *)(this + 0x1c) = uVar1 | 0x10;
      if (DAT_00d6eb04 != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0085da16. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)*DAT_00d6eb04)();
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CPlugVisual::EnableVertexNormal
// =================================================
void __thiscall CPlugVisual::EnableVertexNormal(CPlugVisual *this,CPlugVisual *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x1c);
  if ((uVar1 >> 7 & 1) != (uint)(param_1 != (CPlugVisual *)0x0)) {
    uVar1 = ((uint)(param_1 != (CPlugVisual *)0x0) << 7 ^ uVar1) & 0x80 ^ uVar1;
    *(uint *)(this + 0x1c) = uVar1;
    if ((uVar1 & 0x10) == 0) {
      *(uint *)(this + 0x1c) = uVar1 | 0x10;
      if (DAT_00d6eb04 != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0085da66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)*DAT_00d6eb04)();
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CPlugVisual::IsVisible
// =================================================
int __thiscall
CPlugVisual::IsVisible(CPlugVisual *this,CPlugVisual *param_1,GmFrustum *param_2,GmIso4 *param_3)
{
{
  int iVar1;
  GmIso4 *in_stack_ffffffe8;
  GmIso4 *in_stack_ffffffec;
  
  GmBoxAligned::SetMult
            (&stack0xffffffe8,(SPlugFaceCull *)(this + 0x34),(SPlugFaceCull *)param_2,
             in_stack_ffffffe8);
  iVar1 = GmFrustum::TestInter
                    (param_2,(CPlugVolumeProjector *)&stack0xffffffec,(GmBoxAligned *)0x0,
                     in_stack_ffffffec);
  return iVar1;
}
}

// =================================================
// Function: CPlugVisual::RemoveTexCoordSetAll
// =================================================
void __thiscall CPlugVisual::RemoveTexCoordSetAll(CPlugVisual *this,CPlugVisual *param_1)
{
{
  ulong unaff_ESI;
  
  CFastArray<class_GxTexCoordSet>::SetCount
            (this + 0x5c,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_ESI);
  if ((*(uint *)(this + 0x1c) & 0x400) == 0) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x400;
    if (DAT_00d6eb04 != (undefined4 *)0x0) {
      (**(code **)*DAT_00d6eb04)(this);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugVisual::SetBoundingBox
// =================================================
void __thiscall
CPlugVisual::SetBoundingBox(CPlugVisual *this,CPlugVisual *param_1,GmBoxAligned *param_2)
{
{
  *(undefined4 *)(this + 0x34) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x14);
  return;
}
}

// =================================================
// Function: CPlugVisual::SetBoundingMinMax
// =================================================
void __thiscall
CPlugVisual::SetBoundingMinMax
          (CPlugVisual *this,CPlugVisual *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  GmBoxAligned::SetMinMax(this + 0x34,(GmBoxAligned *)param_1,param_2,param_3);
  return;
}
}

// =================================================
// Function: CPlugVisual::UpdateVisualFromShaderRequirement
// =================================================
int __thiscall
CPlugVisual::UpdateVisualFromShaderRequirement
          (CPlugVisual *this,CPlugVisual *param_1,CPlugShader **param_2,CPlugShader *param_3)
{
{
  bool bVar1;
  bool bVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  int iVar4;
  ulong uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  uint uVar11;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float fVar12;
  CFastBuffer<class_CCrystalFace*> *pCVar13;
  undefined4 *puStack_c;
  undefined4 local_8;
  uint local_4;
  
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x54,unaff_EDI);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x54,pCVar10,unaff_ESI);
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < pCVar3);
  }
  uVar9 = *(uint *)(*param_2 + 0x24);
  pCVar13 = (CFastBuffer<class_CCrystalFace*> *)0x9010000;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)this + 0x10))();
  if (iVar4 == 0) {
    uVar11 = *(uint *)(*param_2 + 0x20);
    fVar12 = 1.2308693e-38;
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x5c,pCVar13);
    uVar7 = 8;
    uVar8 = local_4;
    do {
      if ((uVar8 & 0x6000000) != 0) break;
      uVar7 = uVar7 - 1;
      uVar8 = uVar8 * 4;
    } while (uVar7 != 0);
    if (uVar5 < uVar7) {
      uVar5 = uVar7;
    }
    if (uVar5 < (uVar11 & 0xf)) {
      local_8 = 1;
      iVar4 = (uVar11 & 0xf) - uVar5;
      do {
        AddTexCoordSet(this,(CPlugVisualSprite *)0x3f800000,1.0,0.0,0,0.0,fVar12);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  if (((uVar9 & 0x40) != 0) && (((byte)this[0x1c] & 0x80) == 0)) {
    EnableVertexNormal(this,(CPlugVisual *)0x1,(int)pCVar13);
    local_8 = 1;
  }
  if (((uVar9 & 0x200) != 0) && ((*(uint *)(this + 0x1c) & 0x100) == 0)) {
    EnableVertexColor(this,(CPlugVisual *)0x1,(int)pCVar13);
    local_8 = 1;
  }
  uVar11 = uVar9 >> 0x1b & 1;
  puVar6 = puStack_c;
  if ((uVar11 != 0) || ((uVar9 & 0x20000000) != 0)) {
    iVar4 = (**(code **)(*(int *)this + 0x10))(0x902c000);
    if (iVar4 == 0) {
      *param_2 = (CPlugShader *)param_2;
    }
    else {
      if (((uVar11 == 0) ||
          (uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x84,pCVar13), uVar5 != 0)) ||
         ((local_4 & 0x8000000) != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      uVar9 = local_4 >> 0x1d & 1;
      if (((uVar9 == 0) ||
          (uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x8c,pCVar13), uVar5 != 0)) ||
         ((local_4 & 0x20000000) != 0)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((bVar2) || (bVar1)) {
        iVar4 = (**(code **)(*(int *)this + 0x138))(0,0,uVar11,uVar9);
        puVar6 = (undefined4 *)0x1;
        if (iVar4 == 0) {
          *puStack_c = local_8;
          return (int)(undefined4 *)0x1;
        }
      }
    }
  }
  return (int)puVar6;
}
}

