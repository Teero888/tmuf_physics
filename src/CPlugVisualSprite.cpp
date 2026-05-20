// Class implementation: CPlugVisualSprite

// =================================================
// Function: CPlugVisualSprite::AddSprite
// =================================================
void __thiscall
CPlugVisualSprite::AddSprite
          (CPlugVisualSprite *this,CPlugVisualSprite *param_1,GmVec3 *param_2,float param_3,
          GxColor *param_4,float param_5,float param_6,ulong param_7)
{
{
  CFastBuffer<class_GxVertex>::Add
            (this + 0x78,(TiXmlAttributeSet *)&stack0xffffffd8,*(TiXmlAttribute **)param_1);
  return;
}
}

// =================================================
// Function: CPlugVisualSprite::AddTexCoordSet
// =================================================
ulong __thiscall
CPlugVisualSprite::AddTexCoordSet
          (CPlugVisualSprite *this,CPlugVisualSprite *param_1,float param_2,float param_3,
          ulong param_4,float param_5,float param_6)
{
{
  return 0;
}
}

// =================================================
// Function: CPlugVisualSprite::CPlugVisualSprite
// =================================================
void __thiscall
CPlugVisualSprite::CPlugVisualSprite(CPlugVisualSprite *this,CPlugVisualSprite *param_1)
{
{
  CPlugVisual3D *unaff_ESI;
  undefined1 uStack00000008;
  CPlugVisualSprite *pCVar1;
  CPlugVisualSprite *pCVar2;
  
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CPlugVisual3D::CPlugVisual3D
            ((CPlugVisual3D *)this,(CPlugVisual3D *)(DAT_00cca150 ^ (uint)&stack0xffffffec),
             unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xb0) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0xb8,(CFastArray<class_CManoeuvre*> *)pCVar1);
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x100;
  *(uint *)(this + 0xb0) = *(uint *)(this + 0xb0) & 0x3c0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0x3f800000;
  uStack00000008 = 1;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined2 *)(this + 0xb4) = 1;
  *(undefined2 *)(this + 0xb6) = 1;
  *(undefined4 *)(this + 0xac) = 0;
  UpdateAtlasTexCoords(this,pCVar2);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CPlugVisualSprite::ComputeBoundingBox
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugVisualSprite::ComputeBoundingBox
          (CPlugVisualSprite *this,CPlugVisualStrip *param_1,ulong param_2,ulong param_3)
{
{
  CPlugVisualSprite *this_00;
  float fVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  float fVar5;
  ulong in_stack_ffffffc4;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  this_00 = this + 0x78;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    local_1c = *(float *)pSVar3;
    local_24 = *(float *)(pSVar3 + 4);
    local_20 = *(float *)(pSVar3 + 8);
    pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBP);
    fVar5 = GetMaxDiameter((GmVec3 *)(pSVar3 + 0xc));
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    local_18 = local_24;
    local_14 = local_20;
    if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < pCVar2) {
      do {
        pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (this_00,pCVar4,(ulong)unaff_EBX);
        if (*(float *)(pSVar3 + 4) < local_1c) {
          local_1c = *(float *)(pSVar3 + 4);
        }
        if (*(float *)(pSVar3 + 8) < local_18) {
          local_18 = *(float *)(pSVar3 + 8);
        }
        if (local_14 < *(float *)pSVar3) {
          local_14 = *(float *)pSVar3;
        }
        if (local_10 < *(float *)(pSVar3 + 4)) {
          local_10 = *(float *)(pSVar3 + 4);
        }
        if (local_c < *(float *)(pSVar3 + 8)) {
          local_c = *(float *)(pSVar3 + 8);
        }
        unaff_EBX = pCVar4;
        pSVar3 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                           (this_00,pCVar4,in_stack_ffffffc4);
        fVar1 = *(float *)(pSVar3 + 0xc);
        local_20 = *(float *)(pSVar3 + 0x14);
        if (local_20 < (float)_DAT_00b99c50) {
          if (_DAT_00b37b60 < local_20 != (_DAT_00b37b60 == local_20)) {
            fVar1 = fVar1 / local_20;
          }
        }
        else {
          fVar1 = local_20 * fVar1;
        }
        if (local_24 < fVar1) {
          local_24 = fVar1;
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
    fVar1 = (float)_DAT_00b313b8;
    fVar5 = fVar5 * fVar1;
    *(float *)(this + 0x34) = ((local_24 - fVar5) + local_18 + fVar5) * fVar1;
    *(float *)(this + 0x38) = (local_14 + fVar5 + (local_20 - fVar5)) * fVar1;
    *(float *)(this + 0x3c) = (fVar5 + local_10 + (local_1c - fVar5)) * fVar1;
    *(float *)(this + 0x40) = ((local_18 + fVar5) - (local_24 - fVar5)) * fVar1;
    *(float *)(this + 0x44) = ((local_14 + fVar5) - (local_20 - fVar5)) * fVar1;
    *(float *)(this + 0x48) = fVar1 * ((fVar5 + local_10) - (local_1c - fVar5));
  }
  return;
}
}

// =================================================
// Function: CPlugVisualSprite::SetRenderMode
// =================================================
void __thiscall
CPlugVisualSprite::SetRenderMode
          (CPlugVisualSprite *this,CPlugVisualIndexedLines *param_1,ERenderMode param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0xb0);
  if ((uVar1 & 7) != (uint)(param_1 != (CPlugVisualIndexedLines *)0x0)) {
    *(uint *)(this + 0xb0) = (param_1 != (CPlugVisualIndexedLines *)0x0 ^ uVar1) & 7 ^ uVar1;
    if ((*(uint *)(this + 0x1c) & 0x400) == 0) {
      *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x400;
      if (DAT_00d6eb04 != (undefined4 *)0x0) {
        (**(code **)*DAT_00d6eb04)(this);
      }
    }
  }
  *(uint *)(this + 0xb0) =
       *(uint *)(this + 0xb0) ^ ((uint)(param_2 != 0) * 8 ^ *(uint *)(this + 0xb0)) & 8;
  return;
}
}

// =================================================
// Function: CPlugVisualSprite::SetSpriteFlags
// =================================================
void __thiscall
CPlugVisualSprite::SetSpriteFlags
          (CPlugVisualSprite *this,CPlugVisualSprite *param_1,SSpriteF *param_2)
{
{
  *(undefined4 *)(this + 0xb0) = *(undefined4 *)param_1;
  if ((*(uint *)(this + 0x1c) & 0x400) == 0) {
    *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) | 0x400;
    if (DAT_00d6eb04 != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00882cf1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*DAT_00d6eb04)();
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CPlugVisualSprite::UpdateAtlasTexCoords
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugVisualSprite::UpdateAtlasTexCoords(CPlugVisualSprite *this,CPlugVisualSprite *param_1)
{
{
  float fVar1;
  float fVar2;
  ushort uVar3;
  CPlugVisualSprite *pCVar4;
  SCasterCat *pSVar5;
  CPlugVisualSprite *pCVar6;
  CPlugVisualSprite *pCVar7;
  uint uVar8;
  ulong unaff_ESI;
  uint uVar9;
  ulong unaff_EDI;
  float local_4;
  
  uVar3 = *(ushort *)(this + 0xb4);
  if (uVar3 < 2) {
    uVar3 = 1;
  }
  *(ushort *)(this + 0xb4) = uVar3;
  uVar3 = *(ushort *)(this + 0xb6);
  if (uVar3 < 2) {
    uVar3 = 1;
  }
  *(ushort *)(this + 0xb6) = uVar3;
  CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>::SetCount
            (this + 0xb8,
             (CFastBuffer<class_CSystemFidsFolder*> *)
             (uint)(ushort)(uVar3 * *(short *)(this + 0xb4)),unaff_ESI);
  uVar8 = (uint)*(ushort *)(this + 0xb4);
  pCVar7 = (CPlugVisualSprite *)(uint)*(ushort *)(this + 0xb6);
  pCVar4 = (CPlugVisualSprite *)0x0;
  fVar1 = (float)(int)pCVar7;
  if (pCVar7 != (CPlugVisualSprite *)0x0) {
    do {
      uVar9 = 0;
      pCVar6 = pCVar4;
      if (uVar8 != 0) {
        pCVar7 = (CPlugVisualSprite *)(float)(int)pCVar4;
        if ((int)pCVar4 < 0) {
          pCVar7 = (CPlugVisualSprite *)((float)pCVar7 + _DAT_00c418d0);
        }
        do {
          pSVar5 = CFastBuffer<class_GxColor>::operator[]
                             (this + 0xb8,
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                              (uVar8 * (int)pCVar4 + uVar9),unaff_EDI);
          fVar2 = (float)(int)uVar9;
          if ((int)uVar9 < 0) {
            fVar2 = fVar2 + _DAT_00c418d0;
          }
          uVar9 = uVar9 + 1;
          *(float *)pSVar5 = fVar2 + 0.0;
          *(float *)(pSVar5 + 4) = (float)pCVar7 + 1.0;
          *(float *)(pSVar5 + 8) = fVar2 + 1.0;
          *(float *)(pSVar5 + 0xc) = 1.0 / (float)uVar8;
          *(float *)pSVar5 = (1.0 / fVar1) * *(float *)pSVar5;
          *(float *)(pSVar5 + 4) = local_4 * *(float *)(pSVar5 + 4);
          *(float *)(pSVar5 + 8) = *(float *)(pSVar5 + 8) * (1.0 / fVar1);
          *(float *)(pSVar5 + 0xc) = local_4 * *(float *)(pSVar5 + 0xc);
          pCVar6 = param_1;
        } while (uVar9 < uVar8);
      }
      pCVar4 = pCVar6 + 1;
    } while (pCVar4 < pCVar7);
  }
  return;
}
}

