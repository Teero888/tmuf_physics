// Class implementation: CHmsCorpusLight

// =================================================
// Function: CHmsCorpusLight::CHmsCorpusLight
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsCorpusLight::CHmsCorpusLight(CHmsCorpusLight *this,CHmsCorpusLight *param_1)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  CHmsZoneElem *unaff_ESI;
  
  CHmsZoneElem::CHmsZoneElem((CHmsZoneElem *)this,unaff_ESI);
  uVar1 = _DAT_00b31460;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x5c) = DAT_00d378cc;
  uVar2 = DAT_00d67970;
  *(undefined4 *)(this + 0x54) = uVar1;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x60) = uVar2;
  return;
}
}

// =================================================
// Function: CHmsCorpusLight::ComputeBBoxInWorld
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsCorpusLight::ComputeBBoxInWorld
          (CHmsCorpusLight *this,CHmsCorpusLight *param_1,GmBoxAligned *param_2,ERadius param_3)
{
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  GmBoxAligned *unaff_EBX;
  ulong unaff_ESI;
  GmIso3 *unaff_EDI;
  float fVar4;
  GmCone3 *pGStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  piVar1 = *(int **)(*(int *)(this + 0x48) + 0x88);
  iVar3 = (**(code **)(*piVar1 + 0x78))();
  switch(iVar3) {
  default:
    return 0;
  case 3:
  case 5:
    break;
  case 4:
    GmFrustum::GetBBox(piVar1 + 0x26,(GmFrustum *)param_1,unaff_EBX);
    GmBoxAligned::Mult(param_1,(GmIso3 *)(this + 0x18),unaff_EDI);
    return 1;
  }
  fVar4 = 0.0;
  if ((int)param_2 < 4) {
    fVar4 = (float)piVar1[(int)(param_2 + 0x1a)];
  }
  else {
    uVar2 = piVar1[5];
    if (((uVar2 & 1) != 0) && ((float)_PTR_00b2c178 < (float)piVar1[0x1a])) {
      fVar4 = (float)piVar1[0x1a];
    }
    if (((uVar2 & 8) != 0) && (fVar4 < (float)piVar1[0x1b])) {
      fVar4 = (float)piVar1[0x1b];
    }
    if (((uVar2 & 4) != 0) && (fVar4 < (float)piVar1[0x1c])) {
      fVar4 = (float)piVar1[0x1c];
    }
  }
  if (iVar3 == 3) {
    *(undefined4 *)param_1 = *(undefined4 *)(this + 0x3c);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0x40);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x44);
    *(float *)(param_1 + 0xc) = fVar4;
    *(float *)(param_1 + 0x10) = fVar4;
    *(float *)(param_1 + 0x14) = fVar4;
    return 1;
  }
  GmIso4::GetDir(this + 0x18,(CSystemDataFolders *)&uStack_10,(ulong)unaff_EDI,unaff_ESI);
  uStack_c = *(undefined4 *)(this + 0x44);
  uStack_14 = *(undefined4 *)(this + 0x3c);
  uStack_10 = *(undefined4 *)(this + 0x40);
  GmBoxAligned::SetFromConeAndRadius((void *)param_3,(GmBoxAligned *)&uStack_14,pGStack_18,fVar4);
  return 1;
}
}

// =================================================
// Function: CHmsCorpusLight::ComputeReflectGroundLocation
// =================================================
void __thiscall
CHmsCorpusLight::ComputeReflectGroundLocation
          (CHmsCorpusLight *this,CHmsCorpusLight *param_1,GmIso4 *param_2)
{
{
  GmMat43 *unaff_ESI;
  SPlugFaceCull *in_stack_0000000c;
  GmVec4 *in_stack_ffffffd0;
  GmIso4 *in_stack_ffffffd4;
  SPlugFaceCull local_28 [40];
  
  GmIso4::SetIdentity(&stack0xffffffd0,unaff_ESI);
  GmIso4::SymmetryPlane(&stack0xffffffd4,(GmIso4 *)(*(int *)(this + 0x48) + 0x74),in_stack_ffffffd0)
  ;
  GmIso4::SetMult((void *)(*(int *)(this + 0x4c) + 0x18),local_28,in_stack_0000000c,
                  in_stack_ffffffd4);
  return;
}
}

// =================================================
// Function: CHmsCorpusLight::GetPosition
// =================================================
GmVec3 __thiscall
CHmsCorpusLight::GetPosition(CHmsCorpusLight *this,CGameControlCameraTarget *param_1)
{
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(*(int *)(this + 0x48) + 0x88) + 0x78))();
  if (((iVar1 != 3) && (iVar1 != 2)) && (iVar1 != 5)) {
    return (GmVec3)0x0;
  }
  *(undefined4 *)param_1 = *(undefined4 *)(this + 0x3c);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(this + 0x40);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(this + 0x44);
  return (GmVec3)0x1;
}
}

// =================================================
// Function: CHmsCorpusLight::LightReflectGroundClean
// =================================================
void __thiscall
CHmsCorpusLight::LightReflectGroundClean(CHmsCorpusLight *this,CHmsCorpusLight *param_1)
{
{
  if (*(int **)(this + 0x4c) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x4c) + 4))(1);
    *(undefined4 *)(this + 0x4c) = 0;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpusLight::SetLight
// =================================================
void __thiscall
CHmsCorpusLight::SetLight(CHmsCorpusLight *this,CMotionLight *param_1,GxLight *param_2)
{
{
  CHmsCorpusLight *pCVar1;
  int extraout_EAX;
  int iVar2;
  CHmsCorpusLight *unaff_EDI;
  GmIso4 *pGVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a975eb;
  local_c = ExceptionList;
  pCVar1 = (CHmsCorpusLight *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(CMotionLight **)(this + 0x48) = param_1;
  if (((byte)param_1[0x8c] & 4) != 0) {
    LightReflectGroundClean(this,pCVar1);
    pGVar3 = (GmIso4 *)0x55c150;
    pCVar1 = operator_new(100);
    if (pCVar1 == (CHmsCorpusLight *)0x0) {
      iVar2 = 0;
    }
    else {
      CHmsCorpusLight(pCVar1,unaff_EDI);
      iVar2 = extraout_EAX;
    }
    *(int *)(this + 0x4c) = iVar2;
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(this + 0x14);
    *(CMotionLight **)(*(int *)(this + 0x4c) + 0x48) = param_1;
    pCVar1 = (CHmsCorpusLight *)(**(code **)(*(int *)this + 0x78))();
    ComputeReflectGroundLocation(this,pCVar1,pGVar3);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CHmsCorpusLight::SetLocation
// =================================================
void __thiscall
CHmsCorpusLight::SetLocation(CHmsCorpusLight *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  int iVar1;
  int iVar2;
  CPlugTree *pCVar3;
  CHmsCorpusLight *pCVar4;
  
  iVar1 = *(int *)(this + 0x48);
  pCVar3 = param_1;
  pCVar4 = this + 0x18;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pCVar4 = *(undefined4 *)pCVar3;
    pCVar3 = pCVar3 + 4;
    pCVar4 = pCVar4 + 4;
  }
  if ((iVar1 != 0) && (*(int *)(this + 0x4c) != 0)) {
    ComputeReflectGroundLocation(this,(CHmsCorpusLight *)param_1,param_2);
    return;
  }
  return;
}
}

