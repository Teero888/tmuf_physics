// Class implementation: CSceneToyFxDynaBump

// =================================================
// Function: CSceneToyFxDynaBump::AbsorbContact
// =================================================
void __thiscall
CSceneToyFxDynaBump::AbsorbContact
          (CSceneToyFxDynaBump *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  int iVar1;
  CHmsPhysicalContact *unaff_ESI;
  CHmsItem *unaff_EDI;
  float unaff_retaddr;
  GmVec3 *in_stack_fffffff4;
  undefined1 local_4 [4];
  
  CSceneMobil::AbsorbContact((CSceneMobil *)this,param_1,unaff_EDI,unaff_ESI);
  *(int *)(this + 0x6c) = *(int *)(this + 0x6c) + 1;
  iVar1 = *(int *)(param_1 + 0x40);
  *(float *)(this + 0x70) = *(float *)(iVar1 + 0x3c) + *(float *)(this + 0x70);
  *(float *)(this + 0x74) = *(float *)(iVar1 + 0x44) + *(float *)(this + 0x74);
  GmMat3::GetLine((void *)(*(int *)(param_1 + 0x40) + 0x18),(GmMat3 *)0x2,(ulong)local_4,
                  in_stack_fffffff4);
  *(float *)(this + 0x78) = *(float *)(this + 0x78) + unaff_retaddr;
  *(float *)(this + 0x7c) = *(float *)(this + 0x7c) + (float)param_1;
  *(float *)(this + 0x80) = *(float *)(this + 0x80) + (float)param_2;
  *(float *)(this + 0x84) = *(float *)(this + 0x84) + *(float *)(param_1 + 0x24);
  *(float *)(this + 0x88) = *(float *)(param_1 + 0x28) + *(float *)(this + 0x88);
  *(float *)(this + 0x8c) = *(float *)(param_1 + 0x2c) + *(float *)(this + 0x8c);
  return;
}
}

// =================================================
// Function: CSceneToyFxDynaBump::CSceneToyFxDynaBump
// =================================================
void __thiscall
CSceneToyFxDynaBump::CSceneToyFxDynaBump(CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1)
{
{
  CMwId *unaff_EBX;
  CMwId *unaff_EBP;
  CMwId *unaff_ESI;
  CMwId *unaff_EDI;
  CFastStringInt *pCVar1;
  CFastStringInt *in_stack_00000008;
  undefined1 uStack0000000c;
  undefined1 uStack00000010;
  undefined1 uStack00000014;
  void *in_stack_00000024;
  CSceneToyFxDynaBump *pCVar2;
  void *pvVar3;
  CFastStringInt *pCVar4;
  CFastStringInt *pCVar5;
  
  pCVar5 = (CFastStringInt *)0xffffffff;
  pCVar4 = (CFastStringInt *)&LAB_00acf65e;
  pvVar3 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CSceneToy::CSceneToy((CSceneToy *)this,(CSceneToy *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar1 = (CFastStringInt *)0x0;
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x98,unaff_EDI);
  param_1 = (CSceneToyFxDynaBump *)CONCAT31(param_1._1_3_,1);
  CMwId::CMwId(this + 0xa0,unaff_ESI);
  in_stack_00000008 = (CFastStringInt *)CONCAT31(in_stack_00000008._1_3_,2);
  CMwId::CMwId(this + 0xa8,unaff_EBP);
  uStack0000000c = 3;
  CMwId::CMwId(this + 0xb0,unaff_EBX);
  uStack00000010 = 4;
  CMwId::CMwId(this + 0xb8,(CMwId *)pCVar2);
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  uStack00000014 = 5;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  CMwCmdContainer::AddFastCall
            ((CMwCmdContainer *)(this + 0x48),(CMwCmdContainer *)this,(CMwNod *)UpdateAsync,
             (_func___cdecl_void *)&DAT_0000001a,(ulong)pvVar3);
  CMwId::SetLocalName(this + 0x98,(CMwId *)"BumpScaleUV",pCVar4);
  CMwId::SetLocalName(this + 0xa0,(CMwId *)"Interact1PosInTexBias",pCVar5);
  CMwId::SetLocalName(this + 0xa8,(CMwId *)"Interact1Iso3ColX",pCVar1);
  CMwId::SetLocalName(this + 0xb0,(CMwId *)"Interact1Iso3ColY",(CFastStringInt *)param_1);
  CMwId::SetLocalName(this + 0xb8,(CMwId *)"Interact1Intens",in_stack_00000008);
  ExceptionList = in_stack_00000024;
  return;
}
}

// =================================================
// Function: CSceneToyFxDynaBump::InitFromMaterialFx
// =================================================
void __thiscall
CSceneToyFxDynaBump::InitFromMaterialFx
          (CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1,CPlugTree *param_2)
{
{
  CHmsItem *this_00;
  CPlugTree *pCVar1;
  CPlugTree *this_01;
  CPlugTree *extraout_EAX;
  CPlugMaterialFx *pCVar2;
  int iVar3;
  CPlugTree *unaff_EBX;
  CPlugMaterial *unaff_ESI;
  CPlugTree *unaff_EDI;
  void *in_stack_0000001c;
  CPlugTree *pCVar4;
  GmIso4 *pGVar5;
  CPlugMaterialFxs *in_stack_ffffffc4;
  int in_stack_ffffffc8;
  ECollisionGroup in_stack_ffffffcc;
  EContactInterest in_stack_ffffffd0;
  CSceneToyFxDynaBump *in_stack_ffffffd4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00acf68b;
  local_c = ExceptionList;
  pCVar1 = (CPlugTree *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  this_01 = operator_new(0xac);
  local_4 = 0;
  if (this_01 == (CPlugTree *)0x0) {
    pCVar1 = (CPlugTree *)0x0;
  }
  else {
    CPlugTree::CPlugTree(this_01,pCVar1);
    pCVar1 = extraout_EAX;
  }
  CPlugTree::GetThisToRootTransfo(param_2,(CPlugTree *)&stack0xffffffc8,(GmIso4 *)0x1,0,unaff_EDI);
  pGVar5 = (GmIso4 *)0x1;
  pCVar4 = param_2;
  (**(code **)(*(int *)pCVar1 + 0xb0))();
  CPlugTree::SetUseLocation(pCVar1,(CPlugTree *)0x1,(int)pCVar4);
  CPlugTree::SetLocation(pCVar1,(CPlugTree *)&stack0xffffffc8,pGVar5);
  *(uint *)(pCVar1 + 0x9c) = *(uint *)(pCVar1 + 0x9c) | 0x88;
  CPlugTree::SetMaterial(pCVar1,(CPlugMaterialCustom *)0x0,unaff_ESI);
  CSceneMobil::SetTree((CSceneMobil *)this,(CPlugSolid *)pCVar1,unaff_EBX,(int)this_01);
  pCVar2 = CPlugMaterial::AddMobil_GetMatFx(*(CPlugMaterial **)(param_2 + 0x98),in_stack_ffffffc4);
  this_00 = *(CHmsItem **)(this + 0x28);
  *(CPlugMaterialFx **)(this + 0x94) = pCVar2;
  CHmsItem::SetIsVisionStatic(this_00,(CHmsItem *)0x0,in_stack_ffffffc8);
  CHmsItem::SetCollisionGroup
            (this_00,(CHmsItem *)((-(uint)(*(int *)(*(int *)(this + 0x94) + 0x14) != 0) & 3) + 1),
             in_stack_ffffffcc);
  CHmsItem::SetContactInterest(this_00,(CHmsItem *)0x2,in_stack_ffffffd0);
  iVar3 = UpdateShaderLoadFxPtrs(this,in_stack_ffffffd4);
  *(int *)(this + 0x90) = iVar3;
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CSceneToyFxDynaBump::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneToyFxDynaBump::UpdateAsync(CSceneToyFxDynaBump *this,CInputPortDx8 *param_1)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  undefined4 *puVar13;
  float fVar14;
  float fVar15;
  float10 fVar16;
  
  if (*(int *)(this + 0x90) != 0) {
    fVar1 = *(float *)(*(int *)(this + 0x94) + 0x1c);
    iVar10 = *(int *)(this + 0x6c);
    if (iVar10 == 0) {
      puVar13 = *(undefined4 **)(this + 0xbc);
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0x3f800000;
    }
    else {
      fVar2 = (float)iVar10;
      if (iVar10 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar2 = 1.0 / fVar2;
      *(float *)(this + 0x70) = fVar2 * *(float *)(this + 0x70);
      *(float *)(this + 0x74) = fVar2 * *(float *)(this + 0x74);
      *(undefined4 *)(this + 0x7c) = 0;
      if (_DAT_00d090d0 <
          *(float *)(this + 0x80) * *(float *)(this + 0x80) +
          *(float *)(this + 0x78) * *(float *)(this + 0x78) +
          *(float *)(this + 0x7c) * *(float *)(this + 0x7c)) {
        fVar16 = (float10)func_0x009c1b40();
        fVar3 = 1.0 / (float)fVar16;
        *(float *)(this + 0x78) = fVar3 * *(float *)(this + 0x78);
        *(float *)(this + 0x7c) = *(float *)(this + 0x7c) * fVar3;
        *(float *)(this + 0x80) = fVar3 * *(float *)(this + 0x80);
      }
      fVar16 = (float10)func_0x009c1b40();
      fVar2 = (float)fVar16 * fVar2;
      fVar3 = *(float *)(*(int *)(this + 0x94) + 0x18) / (float)_DAT_00b3d2a8;
      if (fVar3 < fVar2 == (fVar3 == fVar2)) {
        fVar1 = (fVar2 / fVar3) * fVar1;
      }
      pfVar11 = *(float **)(this + 0xbc);
      *pfVar11 = fVar1;
      pfVar11[1] = 0.0;
      pfVar11[2] = 0.0;
      pfVar11[3] = 1.0;
      fVar1 = *(float *)(*(int *)(this + 0x94) + 0x20);
      pfVar11 = *(float **)(this + 0x9c);
      fVar14 = (float)_DAT_00b313b8;
      fVar2 = *pfVar11;
      fVar3 = *(float *)(*(int *)(this + 0x94) + 0x24);
      pfVar12 = *(float **)(this + 0xa4);
      fVar4 = *pfVar11;
      fVar5 = *(float *)(this + 0x7c);
      fVar15 = (float)_PTR_00b2c178;
      fVar6 = *(float *)(this + 0x80);
      fVar7 = *(float *)(this + 0x78);
      fVar8 = *(float *)(this + 0x74);
      fVar9 = *pfVar11;
      *pfVar12 = *pfVar11 * *(float *)(this + 0x70) - fVar14;
      pfVar12[1] = fVar8 * fVar9 - fVar14;
      pfVar12[2] = 0.0;
      pfVar12[3] = 1.0;
      pfVar11 = *(float **)(this + 0xac);
      fVar1 = (1.0 / (fVar2 * fVar1 * fVar14)) * fVar14;
      *pfVar11 = (fVar6 - fVar5 * fVar15) * fVar1;
      pfVar11[1] = fVar1 * (fVar5 * fVar15 - fVar7);
      fVar5 = _DAT_00b31460;
      pfVar11[2] = _DAT_00b31460;
      pfVar11[3] = 1.0;
      pfVar11 = *(float **)(this + 0xb4);
      fVar2 = (1.0 / (fVar3 * fVar14 * fVar4)) * fVar14;
      fVar1 = *(float *)(this + 0x80);
      *pfVar11 = fVar2 * *(float *)(this + 0x78);
      pfVar11[1] = fVar1 * fVar2;
      pfVar11[2] = fVar5;
      pfVar11[3] = 1.0;
      pfVar11 = *(float **)(this + 0xac);
      pfVar11[2] = pfVar11[2] - (*pfVar11 * fVar14 + pfVar11[1] * fVar14);
      pfVar11 = *(float **)(this + 0xb4);
      pfVar11[2] = pfVar11[2] - (pfVar11[1] * fVar14 + *pfVar11 * fVar14);
    }
    *(undefined4 *)(this + 0x6c) = 0;
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined4 *)(this + 0x70) = 0;
    *(undefined4 *)(this + 0x80) = 0;
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0x78) = 0;
    *(undefined4 *)(this + 0x8c) = 0;
    *(undefined4 *)(this + 0x88) = 0;
    *(undefined4 *)(this + 0x84) = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneToyFxDynaBump::UpdateShaderLoadFxPtrs
// =================================================
int __thiscall
CSceneToyFxDynaBump::UpdateShaderLoadFxPtrs(CSceneToyFxDynaBump *this,CSceneToyFxDynaBump *param_1)
{
{
  CPlugShader *this_00;
  CPlugTree *pCVar1;
  int iVar2;
  GmVec4 *pGVar3;
  CPlugMaterial *this_01;
  CSysFidNodRef<class_CPlugMaterial> *unaff_EBX;
  ulong *unaff_ESI;
  SVolatileTreePointer *unaff_EDI;
  ulong *unaff_retaddr;
  ulong *in_stack_00000008;
  ulong *puVar4;
  
  pCVar1 = CSceneMobil::GetTree((CSceneMobil *)this,unaff_EDI);
  this_00 = *(CPlugShader **)(pCVar1 + 0x94);
  iVar2 = (**(code **)(*(int *)this_00 + 0x98))();
  if (iVar2 == 0) {
    return 0;
  }
  puVar4 = (ulong *)0x0;
  iVar2 = (**(code **)(*(int *)this_00 + 0x9c))();
  iVar2 = *(int *)(iVar2 + 0x1c);
  if (*(char *)(iVar2 + 0x4d) == '\x05') {
    pGVar3 = CPlugShader::GetLoadFxValue
                       (this_00,(CPlugShader *)(this + 0x98),(CMwId *)0x0,(SPlugGpuLoadFx **)0x0,
                        (CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,puVar4);
    *(GmVec4 **)(this + 0x9c) = pGVar3;
    if (pGVar3 != (GmVec4 *)0x0) {
      this_01 = CSysFidNodRef<class_CPlugMaterial>::GetNod
                          ((void *)(*(int *)(iVar2 + 0x74) + 0x18),unaff_EBX);
      pGVar3 = CPlugShader::GetLoadFxValue
                         ((CPlugShader *)this_01,(CPlugShader *)(this + 0xa0),(CMwId *)0x0,
                          (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                          unaff_ESI);
      *(GmVec4 **)(this + 0xa4) = pGVar3;
      if (pGVar3 != (GmVec4 *)0x0) {
        pGVar3 = CPlugShader::GetLoadFxValue
                           ((CPlugShader *)this_01,(CPlugShader *)(this + 0xa8),(CMwId *)0x0,
                            (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                            unaff_retaddr);
        *(GmVec4 **)(this + 0xac) = pGVar3;
        if (pGVar3 != (GmVec4 *)0x0) {
          pGVar3 = CPlugShader::GetLoadFxValue
                             ((CPlugShader *)this_01,(CPlugShader *)(this + 0xb0),(CMwId *)0x0,
                              (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0
                              ,(ulong *)param_1);
          *(GmVec4 **)(this + 0xb4) = pGVar3;
          if (pGVar3 != (GmVec4 *)0x0) {
            pGVar3 = CPlugShader::GetLoadFxValue
                               ((CPlugShader *)this_01,(CPlugShader *)(this + 0xb8),(CMwId *)0x0,
                                (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,
                                (EPlugGpuPipeline *)0x0,in_stack_00000008);
            *(GmVec4 **)(this + 0xbc) = pGVar3;
            return (uint)(pGVar3 != (GmVec4 *)0x0);
          }
        }
      }
    }
  }
  return 0;
}
}

