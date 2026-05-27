// Class implementation: CHmsPortal

// =================================================
// Function: CHmsPortal::BindToBuild
// =================================================
void __thiscall
CHmsPortal::BindToBuild(CHmsPortal *this,CHmsPortal *param_1,CHmsItem *param_2,CPlugTree *param_3)
{
{
  int *piVar1;
  SCasterCat *pSVar2;
  undefined4 uVar3;
  SVolatileTreePointer *unaff_ESI;
  ulong unaff_retaddr;
  
  CPlugTree::GetVolatileTreePointer
            ((CPlugTree *)param_2,(CPlugTree *)0x1,(EVolatileTreeType)(this + 0x68),unaff_ESI);
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (param_2 + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  piVar1 = *(int **)pSVar2;
  *(int **)(this + 0x78) = piVar1;
  uVar3 = (**(code **)(*piVar1 + 0x78))();
  *(undefined4 *)(this + 0x7c) = uVar3;
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(*(int *)(this + 0x78) + 0x14);
  RefreshPortal(this,param_1);
  ComputeVisualLocationFromVertices(this,(CHmsPortal *)param_2);
  return;
}
}

// =================================================
// Function: CHmsPortal::CHmsPortal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsPortal::CHmsPortal(CHmsPortal *this,CHmsPortal *param_1)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  SVolatileTreePointer *unaff_ESI;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a965a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  CPlugTree::SVolatileTreePointer::SVolatileTreePointer(this + 0x68,unaff_ESI);
  uVar1 = _DAT_00b31460;
  *(undefined4 *)(this + 0x30) = _DAT_00b31460;
  uVar2 = DAT_00b3d2a0;
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x4c) = uVar2;
  *(undefined4 *)(this + 0x34) = 1;
  *(undefined4 *)(this + 0x40) = 1;
  *(undefined4 *)(this + 0x50) = uVar1;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x58) = uVar2;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x5c) = uVar1;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 200) = 0;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CHmsPortal::Chunk
// =================================================
void __thiscall
CHmsPortal::Chunk(CHmsPortal *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  ulong in_stack_00000010;
  ulong in_stack_00000014;
  int in_stack_00000018;
  ulong in_stack_0000001c;
  
  if ((CClassicArchive *)0x6006002 < param_2) {
    if (param_2 == (CClassicArchive *)0xffffffff) {
      return;
    }
LAB_0054b01a:
    CMwNod::Chunk((CMwNod *)this,param_1,param_2,unaff_EDI);
    return;
  }
  if (param_2 == (CClassicArchive *)0x6006002) {
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x24),(int *)0x1,unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x28),(int *)0x1,unaff_ESI);
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x2c),(int *)0x1,unaff_retaddr)
    ;
    unaff_retaddr = 1;
    CClassicArchive::DoReal
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x30),(float *)0x1,
               (ulong)param_1);
  }
  else {
    if (param_2 != (CClassicArchive *)0x6006000) {
      if (param_2 == (CClassicArchive *)0x6006001) {
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x40),(int *)0x1,unaff_EDI)
        ;
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x44),(int *)0x1,unaff_ESI)
        ;
        CClassicArchive::DoInteger
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x48),(int *)0x1,0,
                   unaff_retaddr);
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x4c),(float *)0x1,
                   (ulong)param_1);
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x50),(float *)0x1,
                   0x6006001);
        CClassicArchive::DoInteger
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x54),(int *)0x1,0,param_3)
        ;
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x58),(float *)0x1,
                   in_stack_00000010);
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x5c),(float *)0x1,
                   in_stack_00000014);
        CClassicArchive::DoInteger
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),(int *)0x1,0,
                   in_stack_00000018);
        CClassicArchive::DoReal
                  ((CClassicArchive *)param_1,(CClassicArchive *)(this + 100),(float *)0x1,
                   in_stack_0000001c);
        return;
      }
      goto LAB_0054b01a;
    }
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x24),(int *)0x1,unaff_EDI);
    CClassicArchive::DoBool
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x28),(int *)0x1,unaff_ESI);
  }
  CClassicArchive::DoBool
            ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x34),(int *)0x1,unaff_retaddr);
  CClassicArchive::DoBool
            ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x38),(int *)0x1,(ulong)param_1);
  CClassicArchive::DoBool
            ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x3c),(int *)0x1,(ulong)param_2);
  return;
}
}

// =================================================
// Function: CHmsPortal::ComputeVisualLocationFromVertices
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsPortal::ComputeVisualLocationFromVertices(CHmsPortal *this,CHmsPortal *param_1)
{
{
  float fVar1;
  float fVar2;
  CHmsPortal *pCVar3;
  CHmsPortal *pCVar4;
  float *pfVar5;
  float fVar6;
  GmVec3 *unaff_EBX;
  uint uVar7;
  CHmsPortal *unaff_EBP;
  uint uVar8;
  GmVec3 *unaff_ESI;
  CHmsPortal *pCVar9;
  CHmsPortal *unaff_EDI;
  float10 fVar10;
  CHmsPortal *pCStack00000008;
  CHmsPortal *pCStack0000000c;
  CHmsPortal *in_stack_00000010;
  GmVec3 *in_stack_ffffffa4;
  CHmsPortal *in_stack_ffffffac;
  uint uStack_4c;
  int iStack_48;
  CHmsPortal *pCStack_44;
  CHmsPortal *pCStack_40;
  float fStack_3c;
  float fStack_38;
  float local_34;
  float local_30;
  float local_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  local_1c = _DAT_00b2c060;
  local_18 = _DAT_00b2c060;
  local_14 = _DAT_00b2c060;
  local_34 = _DAT_00b2c060;
  uVar7 = 0;
  local_30 = _DAT_00b2c060;
  local_2c = _DAT_00b2c060;
  if (*(int *)(this + 0x88) == 0) {
    RefreshPortal(this,unaff_EDI);
  }
  pCVar4 = (CHmsPortal *)(**(code **)(**(int **)(this + 0x88) + 0x8c))();
  do {
    do {
      if ((pCVar4 == (CHmsPortal *)0xffffffff) || (2 < uVar7)) {
        pCVar9 = this + 0x8c;
        GmMat3::SetLine(pCVar9,(GmMat3 *)0x0,(ulong)&local_30,unaff_ESI);
        GmMat3::SetLine(pCVar9,(GmMat3 *)0x1,(ulong)&fStack_38,unaff_EBX);
        GmMat3::SetLine(pCVar9,(GmMat3 *)0x2,(ulong)&local_1c,in_stack_ffffffa4);
        pCVar3 = _DAT_00b57474;
        pCStack00000008 = _DAT_00b57478;
        pCStack0000000c = _DAT_00b57478;
        if (*(int *)(this + 0x88) == 0) {
          RefreshPortal(this,pCVar4);
        }
        iStack_48 = (**(code **)(**(int **)(this + 0x88) + 0x8c))();
        param_1 = pCVar3;
        while (iStack_48 != -1) {
          if (*(int *)(this + 0x88) == 0) {
            RefreshPortal(this,in_stack_ffffffac);
          }
          (**(code **)(**(int **)(this + 0x88) + 0x90))(&iStack_48,&local_34);
          if (local_34 != 0.0) {
            pfVar5 = (float *)((int)fStack_3c + 8);
            fVar6 = local_34;
            do {
              pCStack_44 = (CHmsPortal *)
                           (local_18 * *pfVar5 + pfVar5[-2] * fStack_20 + local_1c * pfVar5[-1]);
              pCStack_40 = (CHmsPortal *)
                           (fStack_24 * *pfVar5 + pfVar5[-2] * local_2c + fStack_28 * pfVar5[-1]);
              if ((float)pCStack_44 < (float)param_1) {
                param_1 = pCStack_44;
              }
              if ((float)pCStack_40 < (float)pCStack00000008) {
                pCStack00000008 = pCStack_40;
              }
              if ((float)pCStack0000000c < (float)pCStack_44) {
                pCStack0000000c = pCStack_44;
              }
              if ((float)in_stack_00000010 < (float)pCStack_40) {
                in_stack_00000010 = pCStack_40;
              }
              pfVar5 = pfVar5 + 10;
              fVar6 = (float)((int)fVar6 + -1);
            } while (fVar6 != 0.0);
          }
        }
        fVar2 = (float)_DAT_00b313b8;
        *(float *)(this + 0xb0) = fStack_8;
        *(float *)(this + 0xb4) = fStack_4;
        *(CHmsPortal **)(this + 0xb8) = pCVar3;
        fVar6 = ((float)pCStack0000000c + (float)param_1) * fVar2 -
                (fStack_8 * fStack_20 + fStack_4 * local_1c + (float)pCVar3 * local_18);
        fVar1 = ((float)in_stack_00000010 + (float)pCStack00000008) * fVar2 -
                (fStack_28 * fStack_4 + local_2c * fStack_8 + (float)pCVar3 * fStack_24);
        *(float *)(this + 0xb0) =
             fVar1 * *(float *)(this + 0x90) + fVar6 * *(float *)pCVar9 +
             *(float *)(this + 0x94) * 0.0 + *(float *)(this + 0xb0);
        *(float *)(this + 0xb4) =
             *(float *)(this + 0xa0) * 0.0 +
             *(float *)(this + 0x98) * fVar6 + *(float *)(this + 0x9c) * fVar1 +
             *(float *)(this + 0xb4);
        *(float *)(this + 0xb8) =
             *(float *)(this + 0xac) * 0.0 +
             *(float *)(this + 0xa8) * fVar1 + *(float *)(this + 0xa4) * fVar6 +
             *(float *)(this + 0xb8);
        *(float *)(this + 0x100) = (float)pCStack0000000c - (float)param_1;
        *(float *)(this + 0x104) = (float)in_stack_00000010 - (float)pCStack00000008;
        *(float *)(this + 0x100) = *(float *)(this + 0x100) * fVar2;
        *(float *)(this + 0x104) = fVar2 * *(float *)(this + 0x104);
        *(float *)(this + 0xbc) = local_14;
        *(float *)(this + 0xc0) = fStack_10;
        *(float *)(this + 0xc4) = fStack_c;
        *(float *)(this + 200) =
             (-local_14 * *(float *)(this + 0xb0) - *(float *)(this + 0xb4) * fStack_10) -
             *(float *)(this + 0xb8) * fStack_c;
        return;
      }
      if (*(int *)(this + 0x88) == 0) {
        RefreshPortal(this,unaff_EBP);
      }
      (**(code **)(**(int **)(this + 0x88) + 0x90))(&stack0xffffffa8,&uStack_4c,&pCStack_44);
      uVar8 = 0;
    } while (uStack_4c == 0);
    pCVar9 = pCStack_44 + 8;
    do {
      if (2 < uVar7) break;
      if (uVar7 == 0) {
        local_18 = *(float *)(pCVar9 + -8);
        uVar7 = 1;
        local_14 = *(float *)(pCVar9 + -4);
        fStack_10 = *(float *)pCVar9;
      }
      else if (uVar7 == 1) {
        local_30 = *(float *)(pCVar9 + -8) - local_18;
        local_2c = *(float *)(pCVar9 + -4) - local_14;
        fStack_28 = *(float *)pCVar9 - fStack_10;
        fVar10 = (float10)func_0x009c1b40();
        in_stack_ffffffac = (CHmsPortal *)(float)fVar10;
        if (_DAT_00b57470 < (float)in_stack_ffffffac) {
          uVar7 = 2;
          in_stack_ffffffac = (CHmsPortal *)(1.0 / (float)in_stack_ffffffac);
          local_30 = (float)in_stack_ffffffac * local_30;
          local_2c = local_2c * (float)in_stack_ffffffac;
          fStack_28 = (float)in_stack_ffffffac * fStack_28;
        }
      }
      else if (uVar7 == 2) {
        fStack_3c = *(float *)(pCVar9 + -8) - local_18;
        fStack_38 = *(float *)(pCVar9 + -4) - local_14;
        local_34 = *(float *)pCVar9 - fStack_10;
        fStack_24 = local_2c * local_34 - fStack_28 * fStack_38;
        fStack_20 = fStack_3c * fStack_28 - local_30 * local_34;
        local_1c = fStack_38 * local_30 - local_2c * fStack_3c;
        fVar10 = (float10)func_0x009c1b40();
        in_stack_ffffffac = (CHmsPortal *)(float)fVar10;
        if (_DAT_00b57470 < (float)in_stack_ffffffac) {
          fVar6 = 1.0 / (float)in_stack_ffffffac;
          fStack_24 = fVar6 * fStack_24;
          fStack_20 = fVar6 * fStack_20;
          local_1c = fVar6 * local_1c;
          in_stack_ffffffac = (CHmsPortal *)ABS(fStack_20);
          if (1.0 - (float)in_stack_ffffffac <= (float)_DAT_00b36288) {
            uVar7 = 3;
            fStack_3c = fStack_28 * fStack_20 - local_2c * local_1c;
            fStack_38 = local_30 * local_1c - fStack_24 * fStack_28;
            local_34 = fStack_24 * local_2c - local_30 * fStack_20;
          }
          else {
            fVar6 = -fStack_20;
            fStack_3c = fVar6 * fStack_24 + 0.0;
            fStack_38 = fVar6 * fStack_20 + 1.0;
            local_34 = fVar6 * local_1c + 0.0;
            in_stack_ffffffac =
                 (CHmsPortal *)(fStack_3c * fStack_3c + fStack_38 * fStack_38 + local_34 * local_34)
            ;
            if (_DAT_00cdcb00 < (float)in_stack_ffffffac) {
              fVar10 = (float10)func_0x009c1b40();
              in_stack_ffffffac = (CHmsPortal *)(1.0 / (float)fVar10);
              fStack_3c = (float)in_stack_ffffffac * fStack_3c;
              fStack_38 = fStack_38 * (float)in_stack_ffffffac;
              local_34 = (float)in_stack_ffffffac * local_34;
            }
            uVar7 = 3;
            local_30 = local_1c * fStack_38 - local_34 * fStack_20;
            local_2c = fStack_24 * local_34 - fStack_3c * local_1c;
            fStack_28 = fStack_3c * fStack_20 - fStack_24 * fStack_38;
          }
        }
      }
      uVar8 = uVar8 + 1;
      pCVar9 = pCVar9 + 0x28;
    } while (uVar8 < uStack_4c);
  } while( true );
}
}

// =================================================
// Function: CHmsPortal::GetChunkInfo
// =================================================
ulong __thiscall CHmsPortal::GetChunkInfo(CHmsPortal *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0x6006003) {
    if (param_1 != (CFuncSegment *)0x6006002) {
      if (param_1 == (CFuncSegment *)0x6006000) {
        return 1;
      }
      if (param_1 != (CFuncSegment *)0x6006001) goto LAB_0054aec1;
    }
    return 3;
  }
  if (param_1 == (CFuncSegment *)0xffffffff) {
    return 0xffffffff;
  }
LAB_0054aec1:
  uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
  return uVar1;
}
}

// =================================================
// Function: CHmsPortal::GetMwClassId
// =================================================
ulong __thiscall CHmsPortal::GetMwClassId(CHmsPortal *this,CControlStyle *param_1)
{
{
  return 0x6006000;
}
}

// =================================================
// Function: CHmsPortal::GetPlaneEqInWorld
// =================================================
void __thiscall CHmsPortal::GetPlaneEqInWorld(CHmsPortal *this,CHmsPortal *param_1,GmVec4 *param_2)
{
{
  GmIso4 *unaff_retaddr;
  
  GmVec4::PlaneEqSetMult(param_1,(GmVec4 *)(this + 0xbc),*(GmVec4 **)(this + 0x7c),unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsPortal::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CHmsPortal::GetUidChunkFromIndex(CHmsPortal *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
    return 0x1001000;
  }
  return (uint)(param_1 + -1) | 0x6006000;
}
}

// =================================================
// Function: CHmsPortal::IsVisible
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsPortal::IsVisible(CHmsPortal *this,CPlugVisual *param_1,GmFrustum *param_2,GmIso4 *param_3)
{
{
  int iVar1;
  GmIso4 *unaff_EBX;
  GmIso4 *unaff_ESI;
  GmIso4 *unaff_EDI;
  GmIso4 *in_stack_ffffff8c;
  GmIso4 *in_stack_ffffff90;
  float local_6c [2];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined1 local_54 [36];
  undefined1 local_30 [4];
  float local_2c;
  float local_28 [2];
  GmFrustum aGStack_20 [32];
  
  *(undefined4 *)param_3 = 0;
  GmIso4::SetMult(local_30,*(SPlugFaceCull **)(this + 0x7c),(SPlugFaceCull *)param_2,unaff_ESI);
  GmVec4::PlaneEqSetMult(local_6c,(GmVec4 *)(this + 0xbc),(GmVec4 *)&local_2c,unaff_EBX);
  if (local_5c < _DAT_00b574fc) {
    return 0;
  }
  if (*(int *)param_3 == 0) {
    local_6c[0] = *(float *)(param_3 + 0xc);
  }
  else {
    local_6c[0] = *(float *)(param_3 + 0xc) - *(float *)(param_3 + 0x18);
  }
  if ((local_5c < local_6c[0] + (float)_DAT_00b36288) && (local_60 < 0.0)) {
    GmIso4::SetMult(&local_58,(SPlugFaceCull *)(this + 0x8c),(SPlugFaceCull *)local_28,unaff_EDI);
    GmIso4::Inverse(local_54,in_stack_ffffff8c);
    local_64 = ABS(local_2c);
    if ((local_64 < *(float *)(this + 0x100)) &&
       (local_64 = ABS(local_28[0]), local_64 < *(float *)(this + 0x104))) {
      if ((float)_DAT_00b541b8 < ABS(local_58)) {
        *(undefined4 *)param_3 = 1;
        return 1;
      }
      *(undefined4 *)param_3 = 0;
      return 1;
    }
  }
  if (*(int *)(this + 0x88) == 0) {
    RefreshPortal(this,(CHmsPortal *)in_stack_ffffff90);
  }
  iVar1 = CPlugVisual::IsVisible
                    (*(CPlugVisual **)(this + 0x88),(CPlugVisual *)param_3,aGStack_20,
                     in_stack_ffffff90);
  return iVar1;
}
}

// =================================================
// Function: CHmsPortal::LinkOneWay
// =================================================
void __cdecl CHmsPortal::LinkOneWay(CHmsPortal *param_1,CHmsPortal *param_2)
{
{
  *(CHmsPortal **)(param_1 + 0x1c) = param_2;
  UpdateZoneTransfoOneWay(param_1,param_2);
  return;
}
}

// =================================================
// Function: CHmsPortal::LinkTwoWays
// =================================================
void __cdecl CHmsPortal::LinkTwoWays(CHmsPortal *param_1,CHmsPortal *param_2)
{
{
  GmScaleTrans2 *unaff_EDI;
  
  LinkOneWay(param_1,param_2);
  *(CHmsPortal **)(param_2 + 0x1c) = param_1;
  *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  GmIso4::SetInverse(param_2 + 0xcc,(GmScaleTrans2 *)(param_1 + 0xcc),unaff_EDI);
  return;
}
}

// =================================================
// Function: CHmsPortal::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsPortal::MwGetClassInfo(CHmsPortal *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d676b4;
}
}

// =================================================
// Function: CHmsPortal::MwIsKilled
// =================================================
void __thiscall CHmsPortal::MwIsKilled(CHmsPortal *this,CVisionViewportDx9 *param_1,CMwNod *param_2)
{
{
  CMwNod *unaff_ESI;
  
  if (param_1 == *(CVisionViewportDx9 **)(this + 0x84)) {
    *(undefined4 *)(this + 0x84) = 0;
    if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
      CMwNod::MwSubDependant(*(CMwNod **)(this + 0x88),(CMwNod *)this,unaff_ESI);
    }
    *(undefined4 *)(this + 0x88) = 0;
    return;
  }
  CSceneMobil::VehicleBlockSpeed2Set((CSceneMobil *)this,(CSceneMobil *)param_1,(int)unaff_ESI);
  return;
}
}

// =================================================
// Function: CHmsPortal::MwIsKindOf
// =================================================
int __thiscall CHmsPortal::MwIsKindOf(CHmsPortal *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x6006000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CHmsPortal::MwIsUnreferenced
// =================================================
void __thiscall
CHmsPortal::MwIsUnreferenced(CHmsPortal *this,CVisionViewportDx9 *param_1,CMwNod *param_2)
{
{
  if (param_1 == *(CVisionViewportDx9 **)(this + 0x88)) {
    *(undefined4 *)(this + 0x88) = 0;
    CMwNod::MwFinalSubDependant((CMwNod *)param_1,(CMwNod *)this,param_2);
    return;
  }
  CMwNod::MwIsUnreferenced((CMwNod *)this,param_1,param_2);
  return;
}
}

// =================================================
// Function: CHmsPortal::MwNewCHmsPortal
// =================================================
CMwNod * __cdecl CHmsPortal::MwNewCHmsPortal(void)
{
{
  CHmsPortal *pCVar1;
  CMwNod *extraout_EAX;
  CHmsPortal *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a965db;
  local_c = ExceptionList;
  pCVar1 = (CHmsPortal *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x108);
  local_4 = 0;
  if (local_10 != (CHmsPortal *)0x0) {
    CHmsPortal(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsPortal::RefreshPortal
// =================================================
void __thiscall CHmsPortal::RefreshPortal(CHmsPortal *this,CHmsPortal *param_1)
{
{
  CMwNod *this_00;
  CPlugTree *this_01;
  CMwNod *unaff_ESI;
  SVolatileTreePointer *unaff_retaddr;
  CMwNod *in_stack_00000008;
  CHmsPortal *in_stack_00000014;
  
  if (*(CMwNod **)(this + 0x84) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x84),(CMwNod *)this,unaff_ESI);
  }
  if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x88),(CMwNod *)this,(CMwNod *)unaff_retaddr);
  }
  this_01 = CPlugTree::SVolatileTreePointer::GetTree(this + 0x68,unaff_retaddr);
  *(CPlugTree **)(this + 0x84) = this_01;
  CMwNod::MwAddDependant((CMwNod *)this_01,(CMwNod *)this,(CMwNod *)param_1);
  this_00 = *(CMwNod **)(*(int *)(this + 0x84) + 0x90);
  *(CMwNod **)(this + 0x88) = this_00;
  CMwNod::MwAddDependant(this_00,(CMwNod *)this,in_stack_00000008);
  ComputeVisualLocationFromVertices(this,in_stack_00000014);
  return;
}
}

// =================================================
// Function: CHmsPortal::TransformLocation
// =================================================
void __thiscall
CHmsPortal::TransformLocation
          (CHmsPortal *this,CHmsPortal *param_1,SHmsCameraLocation *param_2,
          SHmsCameraLocation *param_3)
{
{
  GmIso4 *unaff_EDI;
  
  GmIso4::SetMult(param_1 + 0x30,(SPlugFaceCull *)(param_2 + 0x30),(SPlugFaceCull *)(this + 0xcc),
                  unaff_EDI);
  *(uint *)(param_1 + 0xa0) =
       *(uint *)(param_1 + 0xa0) ^
       (*(uint *)(this + 0xfc) ^ *(uint *)(param_2 + 0xa0) ^ *(uint *)(param_1 + 0xa0)) & 1;
  return;
}
}

// =================================================
// Function: CHmsPortal::TransformView
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsPortal::TransformView(CHmsPortal *this,CHmsPortal *param_1,GmIso4 *param_2,GmFrustum *param_3)
{
{
  float *this_00;
  float fVar1;
  CMwCmdScriptVarBool *pCVar2;
  GmVec3 *unaff_EBX;
  int iVar3;
  GmIso3 *unaff_EBP;
  GmIso4 *unaff_ESI;
  GmIso4 *unaff_EDI;
  uint uVar4;
  int *in_stack_00000010;
  CMwCmdScriptVarBool *local_c0;
  CMwCmdScriptVarBool *local_bc;
  CMwCmdScriptVarBool *local_b8;
  CMwCmdScriptVarBool *local_b4;
  CMwCmdScriptVarBool *local_b0;
  CMwCmdScriptVarBool *local_ac;
  CMwCmdScriptVarBool *local_a8;
  CMwCmdScriptVarBool *local_a4;
  SPlugFaceCull *local_a0;
  CMwCmdScriptVarBool *local_9c;
  void *local_98;
  float local_94;
  float local_90;
  CMwCmdScriptVarBool *local_8c;
  float local_88 [3];
  CMwCmdScriptVarBool *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  CMwCmdScriptVarBool *local_6c;
  undefined4 local_68;
  CMwCmdScriptVarBool *local_64;
  CMwCmdScriptVarBool *local_60;
  undefined4 local_5c [3];
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 local_2c [4];
  GmIso3 local_28 [40];
  
  GmIso4::SetMult(&local_60,(SPlugFaceCull *)(*(int *)(this + 0x78) + 0x18),(SPlugFaceCull *)param_1
                  ,unaff_EDI);
  local_a0 = (SPlugFaceCull *)(this + 0x8c);
  GmIso4::SetMult(local_2c,local_a0,(SPlugFaceCull *)local_5c,unaff_ESI);
  if (*in_stack_00000010 == 0) {
    local_94 = (float)in_stack_00000010[3];
  }
  else {
    local_94 = (float)in_stack_00000010[3] - (float)in_stack_00000010[6];
  }
  local_94 = 1.0 / local_94;
  local_bc = (CMwCmdScriptVarBool *)0x0;
  local_b4 = (CMwCmdScriptVarBool *)0x0;
  local_b8 = (CMwCmdScriptVarBool *)0x0;
  if (*in_stack_00000010 == 0) {
    local_a0 = (SPlugFaceCull *)in_stack_00000010[6];
    local_8c = (CMwCmdScriptVarBool *)in_stack_00000010[3];
  }
  else {
    local_a0 = (SPlugFaceCull *)((float)in_stack_00000010[6] + (float)in_stack_00000010[3]);
    local_8c = (CMwCmdScriptVarBool *)((float)in_stack_00000010[3] - (float)in_stack_00000010[6]);
  }
  iVar3 = 0;
  local_88[0] = *(float *)(this + 0x100);
  local_88[1] = *(float *)(this + 0x104);
  local_88[2] = 0.0;
  local_b0 = (CMwCmdScriptVarBool *)-*(float *)(this + 0x100);
  local_78 = *(undefined4 *)(this + 0x104);
  local_74 = 0;
  local_70 = *(undefined4 *)(this + 0x100);
  local_ac = (CMwCmdScriptVarBool *)-*(float *)(this + 0x104);
  local_68 = 0;
  local_5c[0] = 0;
  uVar4 = 0;
  local_98 = local_a0;
  local_7c = local_b0;
  local_6c = local_ac;
  local_64 = local_b0;
  local_60 = local_ac;
  do {
    this_00 = local_88 + uVar4 * 3;
    GmVec3::Mult(this_00,local_28,unaff_EBP);
    if (local_88[0] < local_88[uVar4 * 3 + 2] == (local_88[0] == local_88[uVar4 * 3 + 2])) {
      iVar3 = iVar3 + 1;
      local_8c = (CMwCmdScriptVarBool *)(local_90 * *this_00);
      local_c0 = (CMwCmdScriptVarBool *)(local_90 * local_88[uVar4 * 3 + 1]);
      local_94 = local_88[0];
    }
    else {
      local_8c = (CMwCmdScriptVarBool *)((1.0 / local_88[uVar4 * 3 + 2]) * *this_00);
      local_c0 = (CMwCmdScriptVarBool *)((1.0 / local_88[uVar4 * 3 + 2]) * local_88[uVar4 * 3 + 1]);
      if (local_88[uVar4 * 3 + 2] < local_94) {
        local_94 = local_88[uVar4 * 3 + 2];
      }
    }
    if (uVar4 == 0) {
      local_bc = local_8c;
      local_b8 = local_c0;
      local_b0 = local_c0;
      local_b4 = local_8c;
    }
    else {
      if ((float)local_bc <= (float)local_8c) {
        if ((float)local_b4 < (float)local_8c) {
          local_b4 = local_8c;
        }
      }
      else {
        local_bc = local_8c;
      }
      if ((float)local_b8 <= (float)local_c0) {
        if ((float)local_b0 < (float)local_c0) {
          local_b0 = local_c0;
        }
      }
      else {
        local_b8 = local_c0;
      }
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  if (iVar3 != 0) {
    if (iVar3 == 4) {
      return 1;
    }
    GmMat3::GetLine(local_98,(GmMat3 *)0x2,(ulong)&local_ac,unaff_EBX);
    local_8c = (CMwCmdScriptVarBool *)
               ((float)local_a4 * local_40 + (float)local_a8 * local_44 + (float)local_a0 * local_3c
               );
    fVar1 = (float)local_a0 * local_48 + local_4c * (float)local_a4 + local_50 * (float)local_a8;
    local_94 = ABS((float)local_8c);
    if (_DAT_00b57470 < ABS(fVar1)) {
      if (0.0 <= fVar1) {
        local_b8 = _DAT_00b2c060;
      }
      if (local_94 <= _DAT_00b57470) goto LAB_0054b86f;
    }
    else if (local_94 <= _DAT_00b57470) {
      return 1;
    }
    if (0.0 <= (float)local_8c) {
      local_b4 = _DAT_00b2c060;
    }
    else {
      local_ac = (CMwCmdScriptVarBool *)0x3f800000;
    }
  }
LAB_0054b86f:
  local_a8 = (CMwCmdScriptVarBool *)in_stack_00000010[1];
  local_a4 = (CMwCmdScriptVarBool *)in_stack_00000010[2];
  local_a0 = (SPlugFaceCull *)in_stack_00000010[4];
  local_9c = (CMwCmdScriptVarBool *)in_stack_00000010[5];
  pCVar2 = local_a8;
  if (((float)local_a8 <= (float)local_b8) && (pCVar2 = local_b8, (float)local_a0 < (float)local_b8)
     ) {
    pCVar2 = (CMwCmdScriptVarBool *)local_a0;
  }
  local_b8 = pCVar2;
  pCVar2 = local_a4;
  if (((float)local_a4 <= (float)local_b4) && (pCVar2 = local_b4, (float)local_9c < (float)local_b4)
     ) {
    pCVar2 = local_9c;
  }
  local_b4 = pCVar2;
  pCVar2 = local_a4;
  if (((float)local_ac < (float)local_a4) || (pCVar2 = local_9c, (float)local_9c < (float)local_ac))
  {
    local_ac = pCVar2;
  }
  GmFrustum::Set(in_stack_00000010,local_b8,(int)local_b4);
  return 1;
}
}

// =================================================
// Function: CHmsPortal::UnbindFromBuild
// =================================================
void __thiscall CHmsPortal::UnbindFromBuild(CHmsPortal *this,CHmsPortal *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x88),(CMwNod *)this,unaff_EDI);
  }
  if (*(CMwNod **)(this + 0x84) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x84),(CMwNod *)this,unaff_ESI);
  }
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  return;
}
}

// =================================================
// Function: CHmsPortal::UpdateZoneTransfoOneWay
// =================================================
/* WARNING: Removing unreachable block (ram,0x0054b25e) */
/* WARNING: Removing unreachable block (ram,0x0054b2a9) */

void __cdecl CHmsPortal::UpdateZoneTransfoOneWay(CHmsPortal *param_1,CHmsPortal *param_2)
{
{
  int iVar1;
  GmScaleTrans2 *unaff_EBX;
  GmIso4 *unaff_EBP;
  undefined4 *puVar2;
  GmScaleTrans2 *pGVar3;
  GmIso4 *in_stack_ffffff70;
  undefined4 local_8c;
  SPlugFaceCull local_88 [4];
  float local_84;
  float fStack_78;
  float fStack_6c;
  GmScaleTrans2 local_5c [48];
  undefined1 auStack_2c [4];
  SPlugFaceCull local_28 [40];
  
  GmIso4::SetMult(&stack0xffffff70,(SPlugFaceCull *)(param_2 + 0x8c),
                  *(SPlugFaceCull **)(param_2 + 0x7c),unaff_EBP);
  puVar2 = &local_8c;
  pGVar3 = local_5c;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pGVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    pGVar3 = pGVar3 + 4;
  }
  local_84 = -local_84;
  fStack_78 = -fStack_78;
  fStack_6c = -fStack_6c;
  *(undefined4 *)(param_2 + 0xfc) = 1;
  GmIso4::SetInverse(auStack_2c,local_5c,unaff_EBX);
  GmIso4::SetMult(param_2 + 0xcc,local_28,local_88,in_stack_ffffff70);
  return;
}
}

// =================================================
// Function: CHmsPortal::UpdateZoneTransfoTwoWays
// =================================================
void __cdecl CHmsPortal::UpdateZoneTransfoTwoWays(CHmsPortal *param_1,CHmsPortal *param_2)
{
{
  GmScaleTrans2 *unaff_EDI;
  
  UpdateZoneTransfoOneWay(param_1,param_2);
  *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(param_1 + 0xfc);
  GmIso4::SetInverse(param_2 + 0xcc,(GmScaleTrans2 *)(param_1 + 0xcc),unaff_EDI);
  return;
}
}

// =================================================
// Function: CHmsPortal::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CHmsPortal::_scalar_deleting_destructor_(CHmsPortal *this,CPfmHeap *param_1,uint param_2)
{
{
  CHmsPortal *unaff_ESI;
  
  ~CHmsPortal(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsPortal::~CHmsPortal
// =================================================
void __thiscall CHmsPortal::~CHmsPortal(CHmsPortal *this,CHmsPortal *param_1)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  uint unaff_retaddr;
  CHmsPortal *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a96583;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  pCVar2 = this;
  if (*(CMwNod **)(this + 0x84) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x84),(CMwNod *)this,pCVar1);
  }
  if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x88),(CMwNod *)this,unaff_ESI);
  }
  CPlugTree::SVolatileTreePointer::~SVolatileTreePointer
            (this + 0x68,(SVolatileTreePointer *)unaff_ESI);
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)pCVar2);
  ExceptionList = (void *)(unaff_retaddr & 0xffffff00);
  return;
}
}

