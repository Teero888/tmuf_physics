// Class implementation: CSceneToySea

// =================================================
// Function: CSceneToySea::GetPointElevation
// =================================================
void __thiscall
CSceneToySea::GetPointElevation
          (CSceneToySea *this,CSceneToySeaHouleFixe *param_1,float param_2,float param_3,
          float *param_4)
{
{
  float *unaff_retaddr;
  
  CSceneToySeaHouleTable::GetPointElevation
            (*(CSceneToySeaHouleTable **)(this + 0xc0),param_1,param_2,param_3,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneToySea::GetPointElevationAssiette
// =================================================
void __thiscall
CSceneToySea::GetPointElevationAssiette
          (CSceneToySea *this,CSceneToySeaHouleTable *param_1,float param_2,float param_3,
          float *param_4)
{
{
  float *unaff_retaddr;
  
  CSceneToySeaHouleTable::GetPointElevationAssiette
            (*(CSceneToySeaHouleTable **)(this + 0xc0),param_1,param_2,param_3,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneToySea::SetSamplingTime_Async
// =================================================
ulong __thiscall
CSceneToySea::SetSamplingTime_Async(CSceneToySea *this,CSceneToySea *param_1,int param_2)
{
{
  CSceneToySeaHouleTable *pCVar1;
  CPlugAudio *this_00;
  CMwId *pCVar2;
  int unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  
  if (*(CSystemFileMemMapped **)(this + 300) == (CSystemFileMemMapped *)0x0) {
    this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
    }
    pCVar2 = CPlugAudio::MwGetId(this_00,(CPlugAudio *)unaff_EDI);
    pCVar1 = *(CSceneToySeaHouleTable **)pCVar2;
  }
  else {
    pCVar1 = (CSceneToySeaHouleTable *)
             CSystemFileMemMapped::GetActualSize(*(CSystemFileMemMapped **)(this + 300),unaff_EDI);
  }
  if (*(CSceneToySeaHouleTable **)(this + 0xc0) != (CSceneToySeaHouleTable *)0x0) {
    CSceneToySeaHouleTable::SetSamplingTime
              (*(CSceneToySeaHouleTable **)(this + 0xc0),pCVar1,param_2,unaff_ESI);
  }
  return (ulong)pCVar1;
}
}

// =================================================
// Function: CSceneToySea::UpdateShaderFromHoule
// =================================================
void __thiscall
CSceneToySea::UpdateShaderFromHoule(CSceneToySea *this,CSceneToySea *param_1,CPlugShader *param_2)
{
{
  ulong *puVar1;
  int iVar2;
  CPlugVolumeProjector *pCVar3;
  CSceneToySea *this_00;
  CMwId CVar4;
  GmVec4 *pGVar5;
  CPlugShaderPass **ppCVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  SCasterCat *pSVar7;
  CPlugBitmapAddress *pCVar8;
  undefined *puVar9;
  CFastString *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CPlugShaderPass **unaff_EBP;
  char *unaff_ESI;
  ulong *unaff_EDI;
  void *this_01;
  EPlugGpuPipeline *unaff_retaddr;
  CPlugShaderPass **in_stack_0000000c;
  CPlugShader *in_stack_00000010;
  char *in_stack_00000014;
  CFastStringInt *in_stack_00000018;
  CPlugShaderPass **in_stack_0000001c;
  CPlugShader *in_stack_00000020;
  char *in_stack_00000024;
  CFastStringInt *in_stack_00000028;
  CPlugShaderPass **in_stack_0000002c;
  CPlugShader *in_stack_00000030;
  char *in_stack_00000034;
  CFastStringInt *pCVar11;
  CPlugShaderPass **in_stack_0000003c;
  EPlugGpuPipeline *in_stack_00000040;
  ulong *in_stack_00000044;
  CFastBuffer<class_CCrystalFace*> *pCVar12;
  char *in_stack_0000004c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000050;
  CPlugShader *in_stack_00000054;
  CFastString *pCVar13;
  CPlugVolumeProjector *pCVar14;
  CPlugBitmap *in_stack_0000005c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000060;
  void *in_stack_00000064;
  undefined4 uStack00000068;
  undefined *in_stack_0000006c;
  undefined4 uStack00000078;
  void *in_stack_00000084;
  undefined4 uStack00000088;
  undefined4 in_stack_0000008c;
  undefined4 in_stack_00000094;
  char *in_stack_ffffffc4;
  CFastString *in_stack_ffffffc8;
  SHeaderCommunity *in_stack_ffffffcc;
  ulong *puVar15;
  ulong *in_stack_ffffffd4;
  CPlugBitmapAddress *in_stack_ffffffd8;
  ulong *in_stack_ffffffdc;
  CPlugBitmapAddress *in_stack_ffffffe0;
  CPlugBitmapAddress *in_stack_ffffffe4;
  SPlugGpuLoadFx **in_stack_ffffffe8;
  CPlugShaderPass **ppCVar16;
  EPlugGpuPipeline *pEVar17;
  ulong *puVar18;
  SPlugGpuLoadFx **in_stack_fffffff8;
  
  this_00 = param_1;
  puVar18 = (ulong *)0xffffffff;
  pEVar17 = (EPlugGpuPipeline *)&LAB_00ace000;
  if (param_1 == (CSceneToySea *)0x0) {
    ExceptionList = in_stack_00000084;
    return;
  }
  ppCVar16 = ExceptionList;
  ExceptionList = &stack0xffffffec;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)param_1,(CPlugShader *)&DAT_00d6d1f8,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      (ulong *)(DAT_00cca150 ^ (uint)&stack0xffffffb8));
  if (pGVar5 != (GmVec4 *)0x0) {
    *(undefined4 *)pGVar5 = *(undefined4 *)(*(int *)(this + 0xc0) + 0x94);
  }
  puVar1 = *(ulong **)(this + 0xc0);
  puVar15 = puVar1;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)param_1,(CPlugShader *)&DAT_00d6d1fc,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      unaff_EDI);
  if (pGVar5 == (GmVec4 *)0x0) {
    CFastString::CFastString((CFastString *)&stack0xffffffe0,(CFastString *)"Normals",unaff_ESI);
    unaff_retaddr = (EPlugGpuPipeline *)0x0;
    pCVar8 = CPlugShader::FindLayerByName
                       ((CPlugShader *)param_1,(CPlugShader *)&stack0xffffffe4,unaff_EBX);
    param_1 = (CSceneToySea *)0xffffffff;
    if (ppCVar16 != (CPlugShaderPass **)PTR_DAT_00bbf7d8) {
      ppCVar6 = (CPlugShaderPass **)((int)ppCVar16 + -1);
      if ((*(byte *)((int)ppCVar16 + -1) & 0x80) != 0) {
        ppCVar6 = ppCVar16 + -1;
      }
      operator_delete__(ppCVar6);
      in_stack_ffffffe8 = (SPlugGpuLoadFx **)0x0;
      ppCVar16 = (CPlugShaderPass **)PTR_DAT_00bbf7d8;
    }
    in_stack_ffffffd8 = pCVar8;
    if (pCVar8 == (CPlugBitmapAddress *)0x0) {
      CFastString::CFastString
                ((CFastString *)&stack0xfffffff0,(CFastString *)"NormalPC2",in_stack_ffffffc4);
      param_2 = (CPlugShader *)0x1;
      in_stack_ffffffe0 =
           CPlugShader::FindLayerByName
                     ((CPlugShader *)this_00,(CPlugShader *)&stack0xfffffff4,in_stack_ffffffc8);
      in_stack_0000000c = (CPlugShaderPass **)0xffffffff;
      in_stack_ffffffd8 = pCVar8;
      pCVar8 = in_stack_ffffffe4;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffff8,in_stack_ffffffcc);
      in_stack_ffffffe4 = pCVar8;
      if (pCVar8 == (CPlugBitmapAddress *)0x0) goto LAB_007d738a;
    }
    iVar2 = *(int *)(pCVar8 + 0x1c);
    if (iVar2 != 0) {
      *(SPlugGpuLoadFx **)(iVar2 + 0x1c) = in_stack_ffffffe8[0x26];
      *(SPlugGpuLoadFx **)(iVar2 + 0x20) = in_stack_ffffffe8[0x27];
      CPlugBitmapAddress::SetUseBitmapTcScale(pCVar8,(CPlugBitmapAddress *)0x1,(int)puVar15);
    }
  }
  else {
    *(ulong *)pGVar5 = puVar1[0x26];
    *(ulong *)(pGVar5 + 4) = puVar1[0x27];
  }
LAB_007d738a:
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d200,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,puVar15
                     );
  *(GmVec4 **)(this + 0xd4) = pGVar5;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d208,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      in_stack_ffffffd4);
  *(GmVec4 **)(this + 0xe0) = pGVar5;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d20c,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      (ulong *)in_stack_ffffffd8);
  *(GmVec4 **)(this + 0xe4) = pGVar5;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d210,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      in_stack_ffffffdc);
  *(GmVec4 **)(this + 0xe8) = pGVar5;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d214,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      (ulong *)in_stack_ffffffe0);
  *(GmVec4 **)(this + 0xec) = pGVar5;
  pGVar5 = CPlugShader::GetLoadFxValue
                     ((CPlugShader *)this_00,(CPlugShader *)&DAT_00d6d218,(CMwId *)0x0,
                      (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,(EPlugGpuPipeline *)0x0,
                      (ulong *)in_stack_ffffffe4);
  *(GmVec4 **)(this + 0xf0) = pGVar5;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,(CPlugShader *)(this + 0xd8),(CMwId *)&DAT_00d6d204,
             in_stack_ffffffe8,ppCVar16,pEVar17,puVar18);
  CVar4 = CMwId::CreateFromLocalName((char *)&stack0x00000010);
  pCVar11 = (CFastStringInt *)0x2;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,(CPlugShader *)(this + 0xf4),
             (CMwId *)CONCAT31(extraout_var,CVar4),in_stack_fffffff8,unaff_EBP,unaff_retaddr,
             (ulong *)param_1);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_2);
  CVar4 = CMwId::CreateFromLocalName((char *)&stack0x00000020);
  pCVar12 = (CFastBuffer<class_CCrystalFace*> *)0x3;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,(CPlugShader *)(this + 0xfc),
             (CMwId *)CONCAT31(extraout_var_00,CVar4),(SPlugGpuLoadFx **)param_2,in_stack_0000000c,
             (EPlugGpuPipeline *)in_stack_00000010,(ulong *)in_stack_00000014);
  in_stack_00000014 = (char *)0x7d74a5;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000018);
  in_stack_00000010 = (CPlugShader *)&stack0x00000030;
  in_stack_00000014 = "HouleHeights";
  CVar4 = CMwId::CreateFromLocalName((char *)in_stack_00000010);
  in_stack_00000014 = (char *)CONCAT31(extraout_var_01,CVar4);
  in_stack_00000010 = (CPlugShader *)(this + 0x114);
  pCVar13 = (CFastString *)&DAT_00000004;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,in_stack_00000010,(CMwId *)in_stack_00000014,
             (SPlugGpuLoadFx **)in_stack_00000018,in_stack_0000001c,
             (EPlugGpuPipeline *)in_stack_00000020,(ulong *)in_stack_00000024);
  uStack00000068 = 0xffffffff;
  in_stack_00000024 = (char *)0x7d74db;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000028);
  in_stack_00000020 = (CPlugShader *)&stack0x00000040;
  in_stack_00000024 = "HouleDuDvWorldDuDvs";
  in_stack_0000001c = (CPlugShaderPass **)0x7d74ea;
  CVar4 = CMwId::CreateFromLocalName((char *)in_stack_00000020);
  in_stack_00000024 = (char *)CONCAT31(extraout_var_02,CVar4);
  in_stack_00000020 = (CPlugShader *)(this + 0x104);
  uStack00000068 = 5;
  in_stack_0000001c = (CPlugShaderPass **)0x7d7504;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,in_stack_00000020,(CMwId *)in_stack_00000024,
             (SPlugGpuLoadFx **)in_stack_00000028,in_stack_0000002c,
             (EPlugGpuPipeline *)in_stack_00000030,(ulong *)in_stack_00000034);
  uStack00000078 = 0xffffffff;
  in_stack_00000034 = (char *)0x7d7511;
  OnAccessViolation_ConcatToCrashFileName(pCVar11);
  in_stack_00000030 = (CPlugShader *)&stack0x00000050;
  in_stack_00000034 = "HouleFoamSTs";
  in_stack_0000002c = (CPlugShaderPass **)0x7d7520;
  CVar4 = CMwId::CreateFromLocalName((char *)in_stack_00000030);
  in_stack_00000034 = (char *)CONCAT31(extraout_var_03,CVar4);
  in_stack_00000030 = (CPlugShader *)(this + 0x10c);
  uStack00000078 = 6;
  in_stack_0000002c = (CPlugShaderPass **)0x7d753a;
  CPlugShader::GetLoadFxValue
            ((CPlugShader *)this_00,in_stack_00000030,(CMwId *)in_stack_00000034,
             (SPlugGpuLoadFx **)pCVar11,in_stack_0000003c,in_stack_00000040,in_stack_00000044);
  uStack00000088 = 0xffffffff;
  in_stack_00000044 = (ulong *)0x7d7547;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar12);
  this_01 = (void *)(*(int *)(this + 0xc0) + 0x14);
  in_stack_00000044 = (ulong *)0x7d755b;
  pCStack00000060 = this_01;
  pCStack00000060 =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount(this_01,pCVar12);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack00000060 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      in_stack_00000044 = (ulong *)0x7d757c;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_01,pCVar10,(ulong)in_stack_0000004c);
      iVar2 = *(int *)pSVar7;
      in_stack_0000004c = "HouleFoam";
      CFastString::CFastString
                ((CFastString *)&stack0x0000006c,(CFastString *)"HouleFoam",
                 (char *)in_stack_00000050);
      in_stack_00000094 = 7;
      in_stack_0000004c = (char *)0x7d759e;
      in_stack_00000050 = pCVar10;
      CFastString::operator<<
                ((CFastString *)&stack0x00000070,(CPlugFileGpuBuilder *)pCVar10,
                 (char *)in_stack_00000054);
      in_stack_00000054 = (CPlugShader *)&stack0x00000074;
      in_stack_00000050 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7d75aa;
      pCVar8 = CPlugShader::FindLayerByName((CPlugShader *)this_00,in_stack_00000054,pCVar13);
      pCVar14 = *(CPlugVolumeProjector **)(iVar2 + 0x44);
      pCVar3 = *(CPlugVolumeProjector **)(iVar2 + 0x40);
      if ((pCVar8 != (CPlugBitmapAddress *)0x0) &&
         ((pCVar14 != (CPlugVolumeProjector *)0x0 ||
          (pCVar14 = pCVar3, pCVar3 != (CPlugVolumeProjector *)0x0)))) {
        in_stack_00000054 = (CPlugShader *)0x7d75c7;
        CPlugBitmapSampler::SetBitmap((CPlugBitmapSampler *)pCVar8,pCVar14,in_stack_0000005c);
        pCVar13 = (CFastString *)pCVar14;
      }
      in_stack_0000008c = 0xffffffff;
      if (in_stack_0000006c != PTR_DAT_00bbf7d8) {
        puVar9 = in_stack_0000006c + -1;
        if ((in_stack_0000006c[-1] & 0x80) != 0) {
          puVar9 = in_stack_0000006c + -4;
        }
        in_stack_00000044 = (ulong *)0x7d75ed;
        operator_delete__(puVar9);
        uStack00000068 = 0;
        in_stack_0000006c = PTR_DAT_00bbf7d8;
      }
      pCVar10 = pCVar10 + 1;
      this_01 = in_stack_00000064;
    } while (pCVar10 < pCStack00000060);
  }
  ExceptionList = in_stack_00000084;
  return;
}
}

