// Class implementation: GmVec4

// =================================================
// Function: GmVec4::Add
// =================================================
void __thiscall GmVec4::Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  float in_stack_0000000c;
  float in_stack_00000010;
  
  *(float *)this = *(float *)this + (float)param_1;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) + (float)param_2;
  *(float *)((int)this + 8) = *(float *)((int)this + 8) + in_stack_0000000c;
  *(float *)((int)this + 0xc) = in_stack_00000010 + *(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmVec4::GetClipFlag
// =================================================
void __thiscall GmVec4::GetClipFlag(void *this,GmReal4_64 *param_1,GmClipFlag_HalfCube *param_2)
{
{
  uint uVar1;
  
  *(undefined4 *)param_1 = 0;
  uVar1 = (uint)(*(float *)((int)this + 8) < 0.0);
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(float *)((int)this + 0xc) < *(float *)((int)this + 8)) * 2 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(float *)((int)this + 4) < -*(float *)((int)this + 0xc)) * 4 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(float *)((int)this + 0xc) < *(float *)((int)this + 4)) * 8 ^ uVar1;
  *(uint *)param_1 = uVar1;
  uVar1 = (uint)(*(float *)this < -*(float *)((int)this + 0xc)) << 4 ^ uVar1;
  *(uint *)param_1 = uVar1;
  if (*(float *)((int)this + 0xc) < *(float *)this) {
    *(uint *)param_1 = uVar1 ^ 0x20;
    return;
  }
  *(uint *)param_1 = uVar1;
  return;
}
}

// =================================================
// Function: GmVec4::GetClipFlags
// =================================================
void __cdecl GmVec4::GetClipFlags(GmVec4 *param_1,GmClipFlag_HalfCube *param_2,ulong param_3)
{
{
  GmClipFlag_HalfCube *unaff_EDI;
  
  for (; param_3 != 0; param_3 = param_3 - 1) {
    GetClipFlag(param_1,(GmReal4_64 *)param_2,unaff_EDI);
    param_2 = param_2 + 4;
    param_1 = param_1 + 0x10;
  }
  return;
}
}

// =================================================
// Function: GmVec4::Mult
// =================================================
void __thiscall GmVec4::Mult(void *this,GmIso3 *param_1,GmIso3 *param_2)
{
{
  SetMult(this,(SPlugFaceCull *)&stack0xfffffff0,(SPlugFaceCull *)param_1,*(GmIso4 **)this);
  return;
}
}

// =================================================
// Function: GmVec4::Neg
// =================================================
void __thiscall GmVec4::Neg(void *this,GmCollision *param_1)
{
{
  *(float *)this = -*(float *)this;
  *(float *)((int)this + 4) = -*(float *)((int)this + 4);
  *(float *)((int)this + 8) = -*(float *)((int)this + 8);
  *(float *)((int)this + 0xc) = -*(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmVec4::PlaneEqInterLine
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmVec4::PlaneEqInterLine(void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3,float *param_4)
{
{
  float fVar1;
  
  fVar1 = *(float *)(param_2 + 8) * *(float *)((int)this + 8) +
          *(float *)param_2 * *(float *)this + *(float *)(param_2 + 4) * *(float *)((int)this + 4);
  if (_DAT_00b785dc < ABS(fVar1)) {
    *(float *)param_3 =
         -((*(float *)(param_1 + 8) * *(float *)((int)this + 8) +
            *(float *)param_1 * *(float *)this + *(float *)(param_1 + 4) * *(float *)((int)this + 4)
           + *(float *)((int)this + 0xc)) / fVar1);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmVec4::PlaneEqInterPlane
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmVec4::PlaneEqInterPlane(void *this,GmVec4 *param_1,GmVec4 *param_2,GmLine3 *param_3)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  *(float *)(param_2 + 0xc) =
       *(float *)(param_1 + 8) * *(float *)((int)this + 4) -
       *(float *)(param_1 + 4) * *(float *)((int)this + 8);
  *(float *)(param_2 + 0x10) =
       *(float *)((int)this + 8) * *(float *)param_1 - *(float *)(param_1 + 8) * *(float *)this;
  fVar1 = *(float *)(param_1 + 4) * *(float *)this - *(float *)param_1 * *(float *)((int)this + 4);
  *(float *)(param_2 + 0x14) = fVar1;
  if (_DAT_00d1a8ac <
      *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc) +
      *(float *)(param_2 + 0x10) * *(float *)(param_2 + 0x10) + fVar1 * fVar1) {
    fVar7 = (float10)func_0x009c1b40();
    fVar3 = 1.0 / (float)fVar7;
    fVar1 = *(float *)(param_2 + 0xc);
    *(float *)(param_2 + 0xc) = fVar3 * fVar1;
    fVar2 = *(float *)(param_2 + 0x10);
    *(float *)(param_2 + 0x10) = fVar3 * fVar2;
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) * fVar3;
    if (ABS(fVar3 * fVar1) <= _DAT_00b31460) {
      if (ABS(fVar3 * fVar2) <= _DAT_00b31460) {
        iVar6 = 2;
        iVar5 = 1;
      }
      else {
        iVar6 = 1;
        iVar5 = 2;
      }
      iVar4 = 0;
    }
    else {
      iVar6 = 0;
      iVar4 = 1;
      iVar5 = 2;
    }
    *(undefined4 *)(param_2 + iVar6 * 4) = 0;
    GmFunc::SolveLinearSystem2
              ((float *)(param_2 + iVar4 * 4),(float *)(param_2 + iVar5 * 4),
               *(float *)((int)this + iVar4 * 4),*(float *)((int)this + iVar5 * 4),
               -*(float *)((int)this + 0xc),*(float *)(param_1 + iVar4 * 4),
               *(float *)(param_1 + iVar5 * 4),-*(float *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmVec4::PlaneEqIsNearlyEqual
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmVec4::PlaneEqIsNearlyEqual(void *this,GmVec4 *param_1,GmVec4 *param_2,float param_3,float param_4)
{
{
  if ((float)_DAT_00b44a20 <=
      *(float *)(param_1 + 8) * *(float *)((int)this + 8) +
      *(float *)param_1 * *(float *)this + *(float *)(param_1 + 4) * *(float *)((int)this + 4)) {
    if (ABS(*(float *)((int)this + 0xc) - *(float *)(param_1 + 0xc)) <= (float)_DAT_00b362c0) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: GmVec4::PlaneEqMult
// =================================================
void __thiscall GmVec4::PlaneEqMult(void *this,GmVec4 *param_1,GmIso4 *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *(float *)(param_1 + 8) * *(float *)((int)this + 8) +
          *(float *)param_1 * *(float *)this + *(float *)(param_1 + 4) * *(float *)((int)this + 4);
  fVar2 = *(float *)(param_1 + 0x14) * *(float *)((int)this + 8) +
          *(float *)(param_1 + 0x10) * *(float *)((int)this + 4) +
          *(float *)(param_1 + 0xc) * *(float *)this;
  fVar3 = *(float *)(param_1 + 0x20) * *(float *)((int)this + 8) +
          *(float *)(param_1 + 0x1c) * *(float *)((int)this + 4) +
          *(float *)(param_1 + 0x18) * *(float *)this;
  *(float *)this = fVar1;
  *(float *)((int)this + 4) = fVar2;
  *(float *)((int)this + 8) = fVar3;
  *(float *)((int)this + 0xc) =
       *(float *)((int)this + 0xc) -
       (fVar3 * *(float *)(param_1 + 0x2c) +
       *(float *)(param_1 + 0x28) * fVar2 + *(float *)(param_1 + 0x24) * fVar1);
  return;
}
}

// =================================================
// Function: GmVec4::PlaneEqSetFrom3Pos
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
GmVec4::PlaneEqSetFrom3Pos
          (void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float10 fVar5;
  
  fVar2 = (*(float *)(param_2 + 4) - *(float *)(param_1 + 4)) *
          (*(float *)(param_3 + 8) - *(float *)(param_1 + 8)) -
          (*(float *)(param_2 + 8) - *(float *)(param_1 + 8)) *
          (*(float *)(param_3 + 4) - *(float *)(param_1 + 4));
  fVar1 = (*(float *)param_3 - *(float *)param_1) *
          (*(float *)(param_2 + 8) - *(float *)(param_1 + 8)) -
          (*(float *)param_2 - *(float *)param_1) *
          (*(float *)(param_3 + 8) - *(float *)(param_1 + 8));
  fVar3 = (*(float *)(param_3 + 4) - *(float *)(param_1 + 4)) *
          (*(float *)param_2 - *(float *)param_1) -
          (*(float *)(param_2 + 4) - *(float *)(param_1 + 4)) *
          (*(float *)param_3 - *(float *)param_1);
  if (_DAT_00d07588 < fVar3 * fVar3 + fVar2 * fVar2 + fVar1 * fVar1) {
    fVar5 = (float10)func_0x009c1b40();
    fVar4 = 1.0 / (float)fVar5;
    *(float *)this = fVar4 * fVar2;
    *(float *)((int)this + 4) = fVar4 * fVar1;
    *(float *)((int)this + 8) = fVar4 * fVar3;
    *(float *)((int)this + 0xc) =
         (-(fVar4 * fVar2) * *(float *)param_1 - *(float *)(param_1 + 4) * fVar4 * fVar1) -
         *(float *)(param_1 + 8) * fVar4 * fVar3;
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmVec4::PlaneEqSetMult
// =================================================
void __thiscall GmVec4::PlaneEqSetMult(void *this,GmVec4 *param_1,GmVec4 *param_2,GmIso4 *param_3)
{
{
  float fVar1;
  
  *(float *)this =
       *(float *)(param_2 + 8) * *(float *)(param_1 + 8) +
       *(float *)param_1 * *(float *)param_2 + *(float *)(param_2 + 4) * *(float *)(param_1 + 4);
  *(float *)((int)this + 4) =
       *(float *)(param_2 + 0x14) * *(float *)(param_1 + 8) +
       *(float *)(param_2 + 0x10) * *(float *)(param_1 + 4) +
       *(float *)(param_2 + 0xc) * *(float *)param_1;
  fVar1 = *(float *)(param_2 + 0x20) * *(float *)(param_1 + 8) +
          *(float *)(param_2 + 0x1c) * *(float *)(param_1 + 4) +
          *(float *)(param_2 + 0x18) * *(float *)param_1;
  *(float *)((int)this + 8) = fVar1;
  *(float *)((int)this + 0xc) =
       *(float *)(param_1 + 0xc) -
       (*(float *)(param_2 + 0x24) * *(float *)this +
        *(float *)(param_2 + 0x28) * *(float *)((int)this + 4) + *(float *)(param_2 + 0x2c) * fVar1)
  ;
  return;
}
}

// =================================================
// Function: GmVec4::PlaneEqSetNormPos
// =================================================
void __thiscall
GmVec4::PlaneEqSetNormPos(void *this,GmVec4 *param_1,GmVec3 *param_2,GmVec3 *param_3)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(float *)((int)this + 0xc) =
       (-*(float *)param_1 * *(float *)param_2 - *(float *)(param_2 + 4) * *(float *)(param_1 + 4))
       - *(float *)(param_2 + 8) * *(float *)(param_1 + 8);
  return;
}
}

// =================================================
// Function: GmVec4::PolygonClip
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
GmVec4::PolygonClip(CFastBuffer<class_GmVec4> *param_1,
                   CFastBuffer<struct_GmClipFlag_HalfCube> *param_2)
{
{
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *pCVar1;
  double dVar2;
  double dVar3;
  uint uVar4;
  CFastBuffer<class_GxVertex2> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  TiXmlAttributeSet *pTVar9;
  ulong uVar10;
  CFastBuffer<struct_GmClipFlag_HalfCube> *this;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  int iVar13;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  ushort in_FPUControlWord;
  SLoadedLight *unaff_retaddr;
  uint in_stack_00000010;
  int in_stack_0000001c;
  uint in_stack_00000020;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000024;
  double *in_stack_00000028;
  double in_stack_0000002c;
  double in_stack_00000034;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar14;
  ulong in_stack_ffffffd4;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffd8;
  TiXmlAttribute *in_stack_ffffffe0;
  SCasterCat *in_stack_ffffffe4;
  TiXmlAttribute *in_stack_ffffffe8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffec;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffff4;
  SCasterCat *in_stack_fffffff8;
  
  pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
            CONCAT22((short)((uint)in_stack_ffffffd0 >> 0x10),in_FPUControlWord);
  if ((in_FPUControlWord & 0x300) != 0x200) {
    in_stack_ffffffcc =
         (CFastBuffer<class_CCrystalFace*> *)
         (CONCAT22((short)((uint)in_stack_ffffffcc >> 0x10),in_FPUControlWord) & 0xfffffeff | 0x200)
    ;
  }
  if ((_DAT_00d706d0 & 1) == 0) {
    _DAT_00d706d0 = _DAT_00d706d0 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d706c4,unaff_EDI);
    _atexit(`public:_static_void___cdecl_GmVec4::
            PolygonClip(class_CFastBuffer<class_GmVec4>&,class_CFastBuffer<struct_GmClipFlag_HalfCube>&)'
            ::__l5::_dynamic_atexit_destructor_for__Vertexs__);
  }
  pCVar5 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_ESI);
  CFastBuffer<class_GxVertex2>::AllocSetCount(&DAT_00d706c4,pCVar5,unaff_EBX);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d706c4,in_stack_ffffffcc);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<class_GxColor>::operator[](param_1,pCVar11,(ulong)pCVar14);
      pCVar14 = pCVar11;
      pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (&DAT_00d706c4,pCVar11,in_stack_ffffffd4);
      *(double *)pSVar8 = (double)*(float *)pSVar7;
      pCVar11 = pCVar11 + 1;
      *(double *)(pSVar8 + 8) = (double)*(float *)(pSVar7 + 4);
      *(double *)(pSVar8 + 0x10) = (double)*(float *)(pSVar7 + 8);
      *(double *)(pSVar8 + 0x18) = (double)*(float *)(pSVar7 + 0xc);
    } while (pCVar11 < pCVar6);
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  do {
    pTVar9 = (TiXmlAttributeSet *)(2 - ((uint)pCVar6 >> 1));
    uVar10 = CFastBuffer<class_CCrystalFace*>::GetCount
                       (&DAT_00d706c4,(CFastBuffer<class_CCrystalFace*> *)pCVar14);
    pCVar1 = (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(uVar10 * 2 + 3);
    CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>::SetSizeAtLeast
              (&DAT_00d706c4,pCVar1,in_stack_ffffffd4);
    pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8e60b5;
    CFastBuffer<int>::SetSizeAtLeast(param_2,pCVar1,(ulong)in_stack_ffffffd8);
    in_stack_ffffffd4 = 0x8e60c1;
    pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                       (&DAT_00d706c4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pCVar6);
    in_stack_ffffffd8 = (CFastBuffer<class_CCrystalFace*> *)0x8e60cc;
    CFastBuffer<class_GmReal4_64>::Add(&DAT_00d706c4,(TiXmlAttributeSet *)pSVar7,in_stack_ffffffe0);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8e60d5;
    in_stack_ffffffe4 =
         CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                   (param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                    (ulong)in_stack_ffffffe4);
    in_stack_ffffffe0 = (TiXmlAttribute *)0x8e60dd;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (param_2,(TiXmlAttributeSet *)in_stack_ffffffe4,in_stack_ffffffe8);
    in_stack_ffffffe8 = (TiXmlAttribute *)0x8e60e7;
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d706c4,in_stack_ffffffec);
    if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      this = (CFastBuffer<struct_GmClipFlag_HalfCube> *)(1 << ((byte)unaff_EBP & 0x1f));
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        in_stack_ffffffe8 = (TiXmlAttribute *)0x8e611b;
        pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                           (&DAT_00d706c4,pCVar12,(ulong)pTVar9);
        pTVar9 = (TiXmlAttributeSet *)pCVar12;
        pSVar8 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_2,pCVar12,(ulong)in_stack_fffffff4);
        in_stack_00000024 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar8;
        uVar4 = (uint)((in_stack_00000010 & (uint)in_stack_00000024) == 0);
        if ((pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) &&
           (in_stack_00000020 != uVar4)) {
          in_stack_fffffff4 = pCVar12 + -1;
          pTVar9 = (TiXmlAttributeSet *)0x8e6158;
          pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                             (&DAT_00d706c4,in_stack_fffffff4,(ulong)in_stack_fffffff8);
          in_stack_0000002c = *(double *)(pSVar8 + in_stack_0000001c * 8);
          dVar2 = *(double *)(pSVar8 + 0x18);
          dVar3 = *(double *)(pSVar7 + in_stack_0000001c * 8);
          if (this == (CFastBuffer<struct_GmClipFlag_HalfCube> *)0x0) {
            dVar3 = in_stack_0000002c - dVar3;
LAB_008e619a:
            in_stack_0000002c = in_stack_0000002c / dVar3;
          }
          else {
            if (((uint)this & 1) != 0) {
              in_stack_0000002c = dVar2 - in_stack_0000002c;
              dVar3 = (dVar3 + in_stack_0000002c) - *(double *)(pSVar7 + 0x18);
              goto LAB_008e619a;
            }
            in_stack_0000002c =
                 (-dVar2 - in_stack_0000002c) /
                 (*(double *)(pSVar7 + 0x18) + (dVar3 - (dVar2 + in_stack_0000002c)));
          }
          in_stack_fffffff8 = (SCasterCat *)0x8e61aa;
          in_stack_00000024 =
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>::AddNewElem
                         (&DAT_00d706c4,unaff_EBP);
          unaff_retaddr =
               CFastBuffer<struct_SIfBlock>::AddNewElem
                         (this,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_retaddr
                         );
          dVar2 = 0.0;
          in_stack_0000002c = (double)CONCAT44(in_stack_0000002c._4_4_,unaff_retaddr);
          if ((0.0 <= in_stack_00000034) && (dVar2 = in_stack_00000034, 1.0 < in_stack_00000034)) {
            dVar2 = 1.0;
          }
          dVar3 = 1.0 - dVar2;
          *in_stack_00000028 = *(double *)pSVar8 * dVar3 + *(double *)pSVar7 * dVar2;
          in_stack_00000028[1] = *(double *)(pSVar7 + 8) * dVar2 + *(double *)(pSVar8 + 8) * dVar3;
          in_stack_00000028[2] =
               *(double *)(pSVar7 + 0x10) * dVar2 + *(double *)(pSVar8 + 0x10) * dVar3;
          in_stack_00000028[3] =
               dVar3 * *(double *)(pSVar8 + 0x18) + *(double *)(pSVar7 + 0x18) * dVar2;
          unaff_EBP = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x8e6227;
          GmReal4_64::GetClipFlag
                    (in_stack_00000028,(GmReal4_64 *)unaff_retaddr,(GmClipFlag_HalfCube *)pCVar11);
          *in_stack_0000002c._4_4_ = *in_stack_0000002c._4_4_ & ~in_stack_00000020;
          pCVar12 = in_stack_00000024;
        }
        if ((uVar4 != 0) && (pCVar12 < pCVar11 + -1)) {
          in_stack_ffffffe8 = (TiXmlAttribute *)0x8e6251;
          CFastBuffer<class_GmReal4_64>::Add
                    (&DAT_00d706c4,(TiXmlAttributeSet *)pSVar7,(TiXmlAttribute *)pTVar9);
          pTVar9 = (TiXmlAttributeSet *)&stack0x00000020;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (this,pTVar9,(TiXmlAttribute *)in_stack_fffffff4);
        }
        pCVar12 = pCVar12 + 1;
        param_2 = this;
      } while (pCVar12 < pCVar11);
    }
    in_stack_ffffffec = (CFastBuffer<class_CCrystalFace*> *)0x8e6284;
    uVar10 = CFastBuffer<class_CCrystalFace*>::GetCount
                       (&DAT_00d706c4,(CFastBuffer<class_CCrystalFace*> *)pTVar9);
    iVar13 = uVar10 - (int)pCVar11;
    if (iVar13 != 0) {
      pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (&DAT_00d706c4,pCVar11,iVar13 * 0x20);
      in_stack_ffffffe8 = (TiXmlAttribute *)0x8e62a8;
      pSVar7 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                         (&DAT_00d706c4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)pSVar7);
      in_stack_ffffffec = (CFastBuffer<class_CCrystalFace*> *)0x8e62ae;
      _memmove(pSVar7,in_stack_fffffff4,(uint)in_stack_fffffff8);
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_2,pCVar11,iVar13 * 4)
      ;
      in_stack_fffffff8 =
           CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pSVar7);
      in_stack_fffffff4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8e62d1;
      _memmove(in_stack_fffffff8,unaff_EBP,(uint)unaff_retaddr);
    }
    _DAT_00d706c4 = iVar13;
    *(int *)param_2 = iVar13;
    if ((iVar13 == 0) ||
       (pCVar6 = pCVar6 + 1,
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000005 < pCVar6)) {
      pCVar5 = (CFastBuffer<class_GxVertex2> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (&DAT_00d706c4,(CFastBuffer<class_CCrystalFace*> *)pCVar14);
      CFastBuffer<class_GmVec4>::AllocSetCount(pCVar11,pCVar5,in_stack_ffffffd4);
      pCVar14 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount(pCVar11,in_stack_ffffffd8);
      pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar14 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar7 = CFastBuffer<class_GxColor>::operator[](pCVar11,pCVar12,(ulong)pCVar6);
          pCVar6 = pCVar12;
          pSVar8 = CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>::operator[]
                             (&DAT_00d706c4,pCVar12,(ulong)in_stack_ffffffe0);
          *(float *)pSVar7 = (float)*(double *)pSVar8;
          pCVar12 = pCVar12 + 1;
          *(float *)(pSVar7 + 4) = (float)*(double *)(pSVar8 + 8);
          *(float *)(pSVar7 + 8) = (float)*(double *)(pSVar8 + 0x10);
          *(float *)(pSVar7 + 0xc) = (float)*(double *)(pSVar8 + 0x18);
        } while (pCVar12 < pCVar14);
      }
      return;
    }
  } while( true );
}
}

// =================================================
// Function: GmVec4::Set
// =================================================
void __thiscall GmVec4::Set(void *this,CMwCmdScriptVarBool *param_1,int param_2)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  return;
}
}

// =================================================
// Function: GmVec4::SetBlend
// =================================================
void __thiscall
GmVec4::SetBlend(void *this,SParam *param_1,SParam *param_2,SParam *param_3,float param_4)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = 1.0 - (float)param_3;
  *(float *)this = fVar1 * *(float *)param_1;
  *(float *)((int)this + 4) = *(float *)(param_1 + 4) * fVar1;
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) * fVar1;
  *(float *)((int)this + 0xc) = fVar1 * *(float *)(param_1 + 0xc);
  fVar1 = *(float *)(param_2 + 4);
  fVar2 = *(float *)(param_2 + 8);
  fVar3 = *(float *)(param_2 + 0xc);
  *(float *)this = *(float *)this + *(float *)param_2 * (float)param_3;
  *(float *)((int)this + 4) = fVar1 * (float)param_3 + *(float *)((int)this + 4);
  *(float *)((int)this + 8) = fVar2 * (float)param_3 + *(float *)((int)this + 8);
  *(float *)((int)this + 0xc) = (float)param_3 * fVar3 + *(float *)((int)this + 0xc);
  return;
}
}

// =================================================
// Function: GmVec4::SetLeftMult
// =================================================
void __thiscall GmVec4::SetLeftMult(void *this,GmVec4 *param_1,GmIso4 *param_2,GmVec4 *param_3)
{
{
  undefined1 in_AL;
  
  out(0x3e,in_AL);
  FUN_009ab8d2();
  return;
}
}

// =================================================
// Function: GmVec4::SetMult
// =================================================
void __thiscall
GmVec4::SetMult(void *this,SPlugFaceCull *param_1,SPlugFaceCull *param_2,GmIso4 *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  pSVar1 = GmMat4::operator[](param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EDI);
  *(float *)this =
       *(float *)(pSVar1 + 0xc) * *(float *)(param_2 + 0xc) +
       *(float *)(pSVar1 + 8) * *(float *)(param_2 + 8) +
       *(float *)pSVar1 * *(float *)param_2 + *(float *)(pSVar1 + 4) * *(float *)(param_2 + 4);
  pSVar1 = GmMat4::operator[](param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                              unaff_ESI);
  *(float *)((int)this + 4) =
       *(float *)(pSVar1 + 0xc) * *(float *)(param_2 + 0xc) +
       *(float *)(pSVar1 + 8) * *(float *)(param_2 + 8) +
       *(float *)pSVar1 * *(float *)param_2 + *(float *)(pSVar1 + 4) * *(float *)(param_2 + 4);
  pSVar1 = GmMat4::operator[](param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x2,
                              unaff_EBX);
  *(float *)((int)this + 8) =
       *(float *)(pSVar1 + 0xc) * *(float *)(param_2 + 0xc) +
       *(float *)(pSVar1 + 8) * *(float *)(param_2 + 8) +
       *(float *)pSVar1 * *(float *)param_2 + *(float *)(pSVar1 + 4) * *(float *)(param_2 + 4);
  pSVar1 = GmMat4::operator[](param_2,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,
                              unaff_retaddr);
  *(float *)((int)this + 0xc) =
       *(float *)(pSVar1 + 0xc) * *(float *)(param_2 + 0xc) +
       *(float *)(pSVar1 + 8) * *(float *)(param_2 + 8) +
       *(float *)param_2 * *(float *)pSVar1 + *(float *)(pSVar1 + 4) * *(float *)(param_2 + 4);
  return;
}
}

// =================================================
// Function: GmVec4::SetSub
// =================================================
void __thiscall GmVec4::SetSub(void *this,GmVec4 *param_1,GmVec4 *param_2,GmVec4 *param_3)
{
{
  *(float *)this = *(float *)param_1 - *(float *)param_2;
  *(float *)((int)this + 4) = *(float *)(param_1 + 4) - *(float *)(param_2 + 4);
  *(float *)((int)this + 8) = *(float *)(param_1 + 8) - *(float *)(param_2 + 8);
  *(float *)((int)this + 0xc) = *(float *)(param_1 + 0xc) - *(float *)(param_2 + 0xc);
  return;
}
}

// =================================================
// Function: GmVec4::Sub
// =================================================
void __thiscall GmVec4::Sub(void *this,GmVec4 *param_1,GmVec4 param_2)
{
{
  undefined3 in_stack_00000009;
  float in_stack_0000000c;
  float in_stack_00000010;
  
  *(float *)this = *(float *)this - (float)param_1;
  *(float *)((int)this + 4) = *(float *)((int)this + 4) - _param_2;
  *(float *)((int)this + 8) = *(float *)((int)this + 8) - in_stack_0000000c;
  *(float *)((int)this + 0xc) = *(float *)((int)this + 0xc) - in_stack_00000010;
  return;
}
}

