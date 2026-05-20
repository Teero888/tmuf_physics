// Class implementation: CPlugFileVHlsl

// =================================================
// Function: CPlugFileVHlsl::ApplyFidParameter_Crypted
// =================================================
void __thiscall
CPlugFileVHlsl::ApplyFidParameter_Crypted
          (CPlugFileVHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2)
{
{
  uint uVar1;
  CPlugFilePHlsl *this_00;
  SParam_Id *pSVar2;
  CMwId *pCVar3;
  int iVar4;
  int iVar5;
  CPlugFileGpuBuilder *pCVar6;
  undefined1 *puVar7;
  CPlugFilePHlsl *pCVar8;
  undefined *puVar9;
  CFastStringInt *pCVar10;
  undefined4 *this_01;
  char *pcVar11;
  char *unaff_EBX;
  char *pcVar12;
  GxTexCoordSet *unaff_ESI;
  char *pcVar13;
  char *pcVar14;
  char *unaff_EDI;
  int iVar15;
  undefined *in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined1 uStack00000018;
  undefined1 in_stack_0000001c;
  void *in_stack_00000024;
  undefined4 in_stack_0000002c;
  char *pcVar16;
  CPlugFileGpuBuilder *pCVar17;
  CPlugFileGpuBuilder *pCVar18;
  CPlugFileGpuBuilder *pCVar19;
  char *in_stack_ffffffb4;
  CPlugFileGpuBuilder *in_stack_ffffffb8;
  CPlugFileGpuBuilder *in_stack_ffffffbc;
  CFastString *in_stack_ffffffc0;
  SHeaderCommunity *pSVar20;
  CPlugFileGpuBuilder *in_stack_ffffffc4;
  CFastString *in_stack_ffffffc8;
  char *pcVar21;
  SHeaderCommunity *in_stack_ffffffcc;
  char *in_stack_ffffffd0;
  CFastString *in_stack_ffffffd4;
  CFastString *pCVar22;
  SHeaderCommunity *in_stack_ffffffd8;
  CFastString *pCVar23;
  CFastString *pCVar24;
  CFastStringInt *in_stack_ffffffdc;
  int local_20;
  undefined *local_1c;
  CFastString local_18 [4];
  undefined *local_14;
  undefined1 *local_10;
  undefined *local_c;
  undefined4 local_8;
  
  pSVar2 = param_2;
  local_c = (undefined *)0xffffffff;
  local_10 = &LAB_00ad7fa8;
  local_14 = ExceptionList;
  pCVar3 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffa8);
  ExceptionList = &local_14;
  iVar4 = *(int *)(param_2 + 0x10);
  if (iVar4 == DAT_00d6ece0) {
    CFastString::CFastString
              ((CFastString *)&stack0xffffffd0,(CFastString *)&DAT_00b30a78,(char *)pCVar3);
    pCVar8 = param_1;
    local_8 = 0;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f05c,(CMwId *)&stack0xffffffd4,
               (CFastString *)unaff_EDI);
    if (in_stack_ffffffdc != (CFastStringInt *)PTR_DAT_00bbf7d8) {
      pCVar10 = in_stack_ffffffdc + -1;
      if (((byte)in_stack_ffffffdc[-1] & 0x80) != 0) {
        pCVar10 = in_stack_ffffffdc + -4;
      }
      operator_delete__(pCVar10);
    }
    iVar4 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar8 + 0x88,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f0ec,unaff_ESI);
    iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar8 + 0x88,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f060,
                       (GxTexCoordSet *)unaff_EBX);
    iVar15 = (-(uint)(iVar4 != -1) & 0x21) + 0xb;
    pcVar13 = (char *)((-(uint)(iVar4 != -1) & 0x21) + 0xc);
    if (iVar5 == -1) {
      CFastString::CFastString
                ((CFastString *)&local_20,
                 (CFastString *)"\\\r\n\tuniform const float4x4\tGbxVisualPw01Shadow0;",
                 in_stack_ffffffb4);
      param_2 = (SParam_Id *)0x3;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)(&DAT_00d6f038 + iVar15),(CMwId *)&local_1c,
                 (CFastString *)in_stack_ffffffb8);
      in_stack_0000000c = (void *)0xffffffff;
      if (local_14 != PTR_DAT_00bbf7d8) {
        puVar9 = local_14 + -1;
        if ((local_14[-1] & 0x80) != 0) {
          puVar9 = local_14 + -4;
        }
        operator_delete__(puVar9);
      }
      CFastString::CFastString
                (local_18,(CFastString *)
                          "\\\r\n\tOutput.TcShadowBuffer = mul(v.Position, GbxVisualPw01Shadow0);",
                 (char *)in_stack_ffffffbc);
      in_stack_00000010 = 4;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)(&DAT_00d6f038 + (int)pcVar13),
                 (CMwId *)&local_14,in_stack_ffffffc0);
      if (local_c == PTR_DAT_00bbf7d8) {
        ExceptionList = in_stack_00000024;
        return;
      }
      puVar9 = local_c + -1;
      if ((local_c[-1] & 0x80) != 0) {
        puVar9 = local_c + -4;
      }
      operator_delete__(puVar9);
      ExceptionList = in_stack_0000000c;
      return;
    }
    pcVar12 = *(char **)(param_2 + 0x14);
    if ((char *)0x3 < pcVar12) {
      pcVar12 = (char *)0x3;
    }
    pcVar14 = (char *)0x0;
    pCVar23 = (CFastString *)0x0;
    pcVar21 = (char *)0x0;
    param_1 = (CPlugFilePHlsl *)0x2;
    pCVar18 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
    if (pcVar12 != (char *)0x0) {
      do {
        pCVar19 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        pCVar6 = CFastString::operator<<
                           ((CFastString *)&stack0xffffffd8,
                            (CPlugFileGpuBuilder *)
                            "\\\r\n\tuniform const float4x4\tGbxVisualPw01Shadow",pcVar14);
        pCVar6 = CFastString::operator<<((CFastString *)pCVar6,pCVar19,in_stack_ffffffb4);
        CFastString::operator<<((CFastString *)pCVar6,in_stack_ffffffb8,(char *)in_stack_ffffffbc);
        in_stack_ffffffbc = (CPlugFileGpuBuilder *)&DAT_00bb1468;
        in_stack_ffffffb4 = " = mul(v.Position, GbxVisualPw01Shadow";
        pcVar11 = pcVar14;
        pCVar6 = CFastString::operator<<
                           ((CFastString *)&stack0xffffffd4,
                            (CPlugFileGpuBuilder *)"\\\r\n\tOutput.TcGbxShadow",pcVar14);
        pCVar6 = CFastString::operator<<
                           ((CFastString *)pCVar6,(CPlugFileGpuBuilder *)in_stack_ffffffb4,pcVar11);
        in_stack_ffffffb8 = (CPlugFileGpuBuilder *)0x87e58a;
        pCVar6 = CFastString::operator<<
                           ((CFastString *)pCVar6,in_stack_ffffffbc,(char *)in_stack_ffffffc0);
        in_stack_ffffffc0 = (CFastString *)0x87e591;
        pCVar6 = CFastString::operator<<((CFastString *)pCVar6,in_stack_ffffffc4,pcVar21);
        pcVar21 = (char *)0x87e598;
        CFastString::operator<<((CFastString *)pCVar6,pCVar18,pcVar13);
        pcVar14 = pcVar14 + 1;
      } while (pcVar14 < pcVar12);
    }
    pCVar8 = param_1;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)(&DAT_00d6f038 + iVar15),(CMwId *)&local_8,
               in_stack_ffffffd4);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)(&DAT_00d6f038 + (int)local_c),
               (CMwId *)&local_14,pCVar23);
    if (local_c != PTR_DAT_00bbf7d8) {
      puVar9 = local_c + -1;
      if ((local_c[-1] & 0x80) != 0) {
        puVar9 = local_c + -4;
      }
      operator_delete__(puVar9);
      local_10 = (undefined1 *)0x0;
      local_c = PTR_DAT_00bbf7d8;
    }
    if (param_1 == (CPlugFilePHlsl *)PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_00000024;
      return;
    }
    pCVar8 = param_1 + -1;
    if (((byte)param_1[-1] & 0x80) != 0) {
      pCVar8 = param_1 + -4;
    }
    operator_delete__(pCVar8);
    ExceptionList = in_stack_00000024;
    return;
  }
  if (iVar4 == DAT_00d6ece4) {
    CFastString::CFastString
              ((CFastString *)&stack0xffffffd8,(CFastString *)&DAT_00b30a78,(char *)pCVar3);
    pCVar8 = param_1;
    pCVar3 = (CMwId *)&stack0xffffffdc;
    pCVar18 = (CPlugFileGpuBuilder *)&DAT_00d6f06c;
    local_8 = 5;
    pcVar13 = (char *)0x87e720;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f06c,pCVar3,(CFastString *)unaff_EDI
              );
    if (local_1c != PTR_DAT_00bbf7d8) {
      unaff_EDI = local_1c + -1;
      if ((local_1c[-1] & 0x80) != 0) {
        unaff_EDI = local_1c + -4;
      }
      pCVar3 = (CMwId *)0x87e73f;
      operator_delete__(unaff_EDI);
    }
    pcVar14 = (char *)0x0;
    pCVar24 = (CFastString *)0x0;
    pCVar23 = (CFastString *)0x0;
    pCVar6 = (CPlugFileGpuBuilder *)0x0;
    pcVar12 = *(char **)(pSVar2 + 0x14);
    if ((char *)0x3 < pcVar12) {
      pcVar12 = (char *)0x3;
    }
    pcVar21 = PTR_DAT_00bbf7d8;
    pCVar22 = (CFastString *)PTR_DAT_00bbf7d8;
    if (pcVar12 != (char *)0x0) {
      do {
        pCVar17 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        pcVar11 = pcVar14 + *(int *)(pCVar8 + 0xdc);
        pcVar16 = " : TEXCOORD";
        pCVar19 = CFastString::operator<<
                            ((CFastString *)&stack0xffffffc8,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfloat4 TcGbxShadowMask",pcVar14);
        pCVar19 = CFastString::operator<<
                            ((CFastString *)pCVar19,(CPlugFileGpuBuilder *)pcVar16,pcVar11);
        pCVar19 = CFastString::operator<<((CFastString *)pCVar19,pCVar17,pcVar13);
        pcVar13 = (char *)0x87e7ba;
        pCVar18 = CFastString::operator<<((CFastString *)pCVar19,pCVar18,(char *)pCVar3);
        CFastString::operator<<
                  ((CFastString *)pCVar18,(CPlugFileGpuBuilder *)unaff_EDI,(char *)unaff_ESI);
        pCVar17 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        pCVar18 = (CPlugFileGpuBuilder *)0x87e7d5;
        pCVar19 = CFastString::operator<<
                            ((CFastString *)&stack0xffffffd4,
                             (CPlugFileGpuBuilder *)
                             "\\\r\n\tuniform const float4x4\tGbxVisualPw01ShadowMask",pcVar14);
        pCVar19 = CFastString::operator<<((CFastString *)pCVar19,pCVar17,unaff_EBX);
        CFastString::operator<<
                  ((CFastString *)pCVar19,(CPlugFileGpuBuilder *)in_stack_ffffffb4,
                   (char *)in_stack_ffffffb8);
        in_stack_ffffffb8 = (CPlugFileGpuBuilder *)&DAT_00bb1468;
        unaff_EBX = " = mul(PosInVisual, GbxVisualPw01ShadowMask";
        unaff_EDI = "\\\r\n\tOutput.TcGbxShadowMask";
        pCVar3 = (CMwId *)0x87e7fd;
        pcVar11 = pcVar14;
        pCVar19 = CFastString::operator<<
                            ((CFastString *)&stack0xffffffd8,
                             (CPlugFileGpuBuilder *)"\\\r\n\tOutput.TcGbxShadowMask",pcVar14);
        unaff_ESI = (GxTexCoordSet *)0x87e804;
        pCVar19 = CFastString::operator<<
                            ((CFastString *)pCVar19,(CPlugFileGpuBuilder *)unaff_EBX,pcVar11);
        in_stack_ffffffb4 = (char *)0x87e80b;
        pCVar19 = CFastString::operator<<
                            ((CFastString *)pCVar19,in_stack_ffffffb8,(char *)in_stack_ffffffbc);
        in_stack_ffffffbc = (CPlugFileGpuBuilder *)0x87e812;
        pCVar19 = CFastString::operator<<
                            ((CFastString *)pCVar19,(CPlugFileGpuBuilder *)in_stack_ffffffc0,
                             (char *)in_stack_ffffffc4);
        in_stack_ffffffc4 = (CPlugFileGpuBuilder *)0x87e819;
        CFastString::operator<<((CFastString *)pCVar19,pCVar6,pcVar21);
        pcVar14 = pcVar14 + 1;
      } while (pcVar14 < pcVar12);
    }
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)&DAT_00d6f070,(CMwId *)&stack0xfffffffc,
               pCVar23);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)&DAT_00d6f074,(CMwId *)&local_8,pCVar22);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar8,(CPlugFileGPU *)&DAT_00d6f078,(CMwId *)&local_c,pCVar24);
    if (PTR_DAT_00bbf7d8 != &DAT_00000008) {
      puVar7 = &DAT_00000007;
      if ((DAT_00000007 & 0x80) != 0) {
        puVar7 = &DAT_00000004;
      }
      operator_delete__(puVar7);
      local_8 = 0;
    }
    if (param_1 != (CPlugFilePHlsl *)PTR_DAT_00bbf7d8) {
      pCVar8 = param_1 + -1;
      if (((byte)param_1[-1] & 0x80) != 0) {
        pCVar8 = param_1 + -4;
      }
      operator_delete__(pCVar8);
      param_1 = (CPlugFilePHlsl *)PTR_DAT_00bbf7d8;
    }
    if (in_stack_0000000c == PTR_DAT_00bbf7d8) {
      ExceptionList = in_stack_00000024;
      return;
    }
    puVar9 = in_stack_0000000c + -1;
    if ((in_stack_0000000c[-1] & 0x80) != 0) {
      puVar9 = in_stack_0000000c + -4;
    }
    operator_delete__(puVar9);
    ExceptionList = in_stack_00000024;
    return;
  }
  if (iVar4 != DAT_00d6ecf0) {
    ExceptionList = in_stack_00000024;
    return;
  }
  uVar1 = *(uint *)(param_2 + 0x14);
  pSVar20 = (SHeaderCommunity *)0x3;
  CMwId::CMwId(&stack0xffffffb8,pCVar3);
  local_8 = 9;
  CMwId::CMwId(&stack0xffffffb8,(CMwId *)unaff_EDI);
  this_00 = param_1;
  pCVar8 = param_1 + 0x88;
  iVar4 = CFastArray<class_CGameMenuFrame*>::Find
                    (pCVar8,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f084,unaff_ESI);
  if (iVar4 == -1) {
    iVar4 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar8,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f08c,
                       (GxTexCoordSet *)unaff_EBX);
    if (iVar4 == -1) {
      iVar4 = CFastArray<class_CGameMenuFrame*>::Find
                        (pCVar8,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f094,
                         (GxTexCoordSet *)in_stack_ffffffb4);
      if (iVar4 != -1) {
        in_stack_ffffffd4 = (CFastString *)0x2;
        in_stack_ffffffc8 = DAT_00d6f094;
        in_stack_ffffffcc = DAT_00d6f090;
      }
    }
    else {
      in_stack_ffffffd0 = (char *)0x1;
      in_stack_ffffffc4 = DAT_00d6f08c;
      in_stack_ffffffc8 = DAT_00d6f088;
    }
  }
  else {
    in_stack_ffffffcc = (SHeaderCommunity *)0x0;
    pSVar20 = DAT_00d6f084;
    in_stack_ffffffc4 = DAT_00d6f080;
  }
  CFastString::CFastString
            ((CFastString *)&local_14,(CFastString *)&DAT_00b30a78,(char *)in_stack_ffffffb8);
  in_stack_0000000c = (undefined *)CONCAT31(in_stack_0000000c._1_3_,0xb);
  CPlugFileGPU::DefineAddOrSet
            ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&DAT_00d6f07c,(CMwId *)&local_10,
             (CFastString *)in_stack_ffffffbc);
  in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,10);
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_c,pSVar20);
  if ((uVar1 & 0x400) == 0) {
    if (local_20 == 0) {
      CFastString::CFastString
                ((CFastString *)&local_8,
                 (CFastString *)"\\\r\n\tuniform const float4x3\tGbxVisualPz01Projector0;",
                 (char *)in_stack_ffffffc4);
      uStack00000018 = 0xe;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&stack0xffffffdc,(CMwId *)&stack0xfffffffc,
                 in_stack_ffffffc8);
      in_stack_0000001c = 10;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffcc);
      CFastString::CFastString
                ((CFastString *)&param_1,
                 (CFastString *)
                 "\\\r\n\tOutput.Position\t  = v.Position;\\\r\n\tOutput.Normal\t  = v.Normal;\\\r\n\tOutput.TcProjector = mul(v.Position, GbxVisualPz01Projector0).xyzz;"
                 ,in_stack_ffffffd0);
      in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0xf);
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_1c,(CMwId *)&param_2,
                 in_stack_ffffffd4);
      this_01 = &stack0x0000000c;
      goto LAB_0087eb1e;
    }
    if (local_20 != 1) {
      CFastString::CFastString
                ((CFastString *)&local_8,
                 (CFastString *)"\\\r\n\tuniform const float4x3\tGbxVisualPz01Projector0;",
                 (char *)in_stack_ffffffc4);
      uStack00000018 = 0x11;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&stack0xffffffdc,(CMwId *)&stack0xfffffffc,
                 in_stack_ffffffc8);
      in_stack_0000001c = 10;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffcc);
      CFastString::CFastString
                ((CFastString *)&stack0x0000000c,
                 (CFastString *)
                 "\\\r\n\tOutput.Position\t  = v.Position;\\\r\n\tOutput.TcProjector = mul(v.Position, GbxVisualPz01Projector0).xyzz;"
                 ,in_stack_ffffffd0);
      in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0x12);
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_1c,(CMwId *)&stack0x00000010,
                 in_stack_ffffffd4);
      this_01 = (undefined4 *)&stack0x00000014;
      goto LAB_0087eb1e;
    }
    CFastString::CFastString
              ((CFastString *)&local_8,
               (CFastString *)
               "\\\r\n\tOutput.Position\t  = v.Position;\\\r\n\tOutput.Normal\t  = v.Normal;",
               (char *)in_stack_ffffffc4);
    uStack00000018 = 0x10;
  }
  else {
    CFastString::CFastString
              ((CFastString *)&local_8,
               (CFastString *)"\\\r\n\tuniform const float4x3\tGbxVisualPz01Camera;",
               (char *)in_stack_ffffffc4);
    uStack00000018 = 0xc;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&stack0xffffffdc,(CMwId *)&stack0xfffffffc,
               in_stack_ffffffc8);
    in_stack_0000001c = 10;
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffcc);
    CFastString::CFastString
              ((CFastString *)&param_1,
               (CFastString *)
               "\\\r\n\tOutput.Position\t  = mul(v.Position, GbxVisualPz01Camera).xyzz;",
               in_stack_ffffffd0);
    in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0xd);
  }
  CPlugFileGPU::DefineAddOrSet
            ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_1c,(CMwId *)&param_2,in_stack_ffffffd4);
  this_01 = &stack0x0000000c;
LAB_0087eb1e:
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(this_01,in_stack_ffffffd8);
  in_stack_0000002c = CONCAT31(in_stack_0000002c._1_3_,9);
  OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffdc);
  in_stack_0000002c = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffdc);
  ExceptionList = in_stack_00000024;
  return;
}
}

// =================================================
// Function: CPlugFileVHlsl::CPlugFileVHlsl
// =================================================
void __thiscall CPlugFileVHlsl::CPlugFileVHlsl(CPlugFileVHlsl *this,CPlugFileVHlsl *param_1)
{
{
  CPlugFileGPUV *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  CPlugFileGPUV::CPlugFileGPUV((CPlugFileGPUV *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xd4,unaff_retaddr);
  *(undefined4 *)(this + 0x20) = 0x101;
  *(undefined4 *)(this + 0xdc) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CPlugFileVHlsl::Compile
// =================================================
void __thiscall CPlugFileVHlsl::Compile(CPlugFileVHlsl *this,CDx9PixelShader *param_1,int param_2)
{
{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  CFastString CVar4;
  CFastBuffer<struct_CPlugFileGPU::SDxDefine> *pCVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  ulong uVar9;
  undefined4 uVar10;
  CFastString *pCVar11;
  SCasterCat *pSVar12;
  void *pvVar13;
  uint uVar14;
  char **ppcVar15;
  undefined3 extraout_var;
  CPlugFileGpuBuilder *pCVar16;
  undefined *puVar17;
  CFastString *extraout_ECX;
  CFastString *extraout_ECX_00;
  CFastString *extraout_ECX_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar18;
  CPlugFileGPU *unaff_EBP;
  ulong unaff_ESI;
  CFastStringInt *unaff_EDI;
  char *pcVar19;
  STarget *pSVar20;
  bool bVar21;
  void *in_stack_00000014;
  CPlugFileGPU *in_stack_0000001c;
  CFastStringInt *pCVar22;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar23;
  CPlugFileGPU *pCVar24;
  SStringParam *pSVar25;
  SHeaderCommunity *pSVar26;
  SStringParamInt *pSVar27;
  CFastString *pCVar28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar29;
  CPlugFileGPU *in_stack_fffffefc;
  CMwId *pCVar30;
  CMwId *pCVar31;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar32;
  CFastString *pCVar33;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff08;
  SHeaderCommunity *in_stack_ffffff0c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff10;
  undefined *in_stack_ffffff14;
  int *piStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  STarget *pSStack_dc;
  undefined4 uStack_d8;
  char **appcStack_d4 [2];
  STarget *pSStack_cc;
  int iStack_c8;
  char **ppcStack_c4;
  ulong uStack_c0;
  STarget *pSStack_bc;
  undefined *puStack_b8;
  CFastBuffer<struct_CPlugFileGPU::SDxDefine> aCStack_b4 [8];
  char *pcStack_ac;
  int iStack_a8;
  undefined *puStack_a4;
  undefined *puStack_a0;
  undefined4 uStack_9c;
  CPlugFileVHlsl *pCStack_98;
  ulong uStack_94;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *apCStack_90 [2];
  CFastString *pCStack_88;
  CSystemFids *pCStack_84;
  char *pcStack_80;
  ulong uStack_7c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_78;
  undefined4 uStack_74;
  char *pcStack_70;
  int iStack_6c;
  char *pcStack_68;
  undefined4 uStack_64;
  char *pcStack_60;
  undefined4 uStack_5c;
  char *pcStack_58;
  undefined4 uStack_54;
  char *pcStack_50;
  undefined4 uStack_4c;
  char *pcStack_48;
  undefined4 uStack_44;
  char *pcStack_40;
  undefined4 uStack_3c;
  char *pcStack_38;
  undefined4 uStack_34;
  char *pcStack_30;
  undefined4 uStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  char *pcStack_18;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ade193;
  pvStack_c = ExceptionList;
  pCVar5 = (CFastBuffer<struct_CPlugFileGPU::SDxDefine> *)(DAT_00cca150 ^ (uint)&stack0xfffffeec);
  ExceptionList = &pvStack_c;
  pCVar23 = (CFastBuffer<class_CPlugFileSndGen*> *)0x9074000;
  iVar6 = (**(code **)(*(int *)this + 0x10))();
  piVar2 = *(int **)(this + 0xb8);
  puVar17 = (undefined *)(uint)(iVar6 == 0);
  puStack_b8 = puVar17;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(this + 0xb8) = 0;
  }
  pcStack_80 = "vs_1_1";
  uStack_7c = 0xfffe0101;
  pCStack_78 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xbbd2e8;
  uStack_74 = 0xfffe0200;
  pcStack_70 = "vs_2_a";
  iVar6 = (uint)(puVar17 != (undefined *)0x0) * 4;
  pCVar28 = (CFastString *)(iVar6 + 5);
  iStack_6c = -0x1fdff;
  pcStack_68 = "vs_2_sw";
  uStack_64 = 0xfffe02ff;
  pcStack_60 = "vs_3_0";
  uStack_5c = 0xfffe0300;
  pcStack_58 = "ps_1_1";
  uStack_54 = 0xffff0101;
  pcStack_50 = "ps_1_2";
  uStack_4c = 0xffff0102;
  pcStack_48 = "ps_1_3";
  uStack_44 = 0xffff0103;
  pcStack_40 = "ps_1_4";
  uStack_3c = 0xffff0104;
  pcStack_38 = "ps_2_0";
  uStack_34 = 0xffff0200;
  pcStack_30 = "ps_2_b";
  uStack_2c = 0xffff0202;
  pcStack_28 = "ps_2_a";
  uStack_24 = 0xffff0201;
  pcStack_20 = "ps_2_sw";
  uStack_1c = 0xffff02ff;
  pcStack_18 = "ps_3_0";
  uStack_14 = 0xffff0300;
  if (puVar17 == (undefined *)0x0) {
    appcStack_d4[0] = &pcStack_80;
  }
  else {
    appcStack_d4[0] = &pcStack_58;
  }
  apCStack_90[0] = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar28;
  pSStack_dc = (STarget *)(**(code **)(*(int *)this + 0xa0))();
  pCStack_98 = this + 0x14;
  pCVar30 = (CMwId *)0x0;
  pCVar29 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar32 = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&ppcStack_c4,pCVar23);
  iStack_4 = 0;
  apCStack_90[0] = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if ((DAT_00d705e0 == (code *)0x0) ||
     (iVar7 = (*DAT_00d705e0)(this,apCStack_90,&uStack_c0), iVar7 != 0)) {
    CPlugFileGPU::AddDxDefines((CPlugFileGPU *)this,(CPlugFileGPU *)&uStack_c0,pCVar5);
    if (*(int *)(this + 8) == 0) {
      pCStack_84 = (CSystemFids *)0x0;
    }
    else {
      pCStack_84 = *(CSystemFids **)(*(int *)(this + 8) + 0x14);
    }
    pCVar33 = (CFastString *)(iVar6 + 4);
    iStack_c8 = -0x7789f79a;
    pCVar31 = pCVar30;
    if (pCVar33 < pCVar28) {
      pSVar20 = pSStack_cc + (int)pCVar33 * 8;
      do {
        pCVar18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        pCVar24 = in_stack_fffffefc;
        pCVar31 = pCVar30;
        pSStack_dc = pSVar20;
        if (in_stack_ffffff08 != (CFastBuffer<class_CCrystalFace*> *)0x0) {
          (**(code **)(*(int *)in_stack_ffffff08 + 8))(in_stack_ffffff08);
          in_stack_ffffff08 = (CFastBuffer<class_CCrystalFace*> *)0x0;
          pCVar24 = in_stack_fffffefc;
          pCVar31 = pCVar30;
        }
        if (pCVar31 != (CMwId *)0x0) {
          (**(code **)(*(int *)pCVar31 + 8))(pCVar31);
          pCVar31 = (CMwId *)0x0;
        }
        if (in_stack_ffffff0c != (SHeaderCommunity *)0x0) {
          (**(code **)(*(int *)in_stack_ffffff0c + 8))(in_stack_ffffff0c);
          in_stack_ffffff0c = (SHeaderCommunity *)0x0;
        }
        if ((DAT_00d705e4 == (code *)0x0) ||
           (iVar6 = (*DAT_00d705e4)(*(undefined4 *)(pSVar20 + 4)), in_stack_fffffefc = pCVar24,
           pCVar30 = pCVar31, iVar6 != 0)) {
          pcStack_ac = *(char **)pSVar20;
          if (pcStack_ac == (char *)0x0) {
            iStack_a8 = 0;
          }
          else {
            pcVar8 = pcStack_ac;
            do {
              cVar1 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar1 != '\0');
            iStack_a8 = (int)pcVar8 - (int)(pcStack_ac + 1);
          }
          uVar9 = CFastString::FindFirst
                            ((CFastString *)apCStack_90[0],(CFastStringInt *)&pcStack_ac,0,1);
          in_stack_fffffefc = pCVar24;
          pCVar30 = pCVar31;
          if (uVar9 != 0xffffffff) {
            CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
                      (this + 0x30,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,(ulong)unaff_EDI);
            CFastArray<class_CFastString>::SetCount
                      (this + 0x38,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,unaff_ESI);
            unaff_EDI = (CFastStringInt *)&stack0xffffff14;
            uStack_c0 = CPlugGpuCompileCache::CacheOrCompileHR
                                  ((CPlugFileGPU *)this,aCStack_b4,(ulong)pCStack_84,pSVar20,
                                   (EPlugGpuPipeline)puVar17,&stack0xffffff10,&stack0xffffff08,
                                   unaff_EDI,*(CPlugGpuCompileCache **)(this + 0xac));
            in_stack_fffffefc = pCVar24;
            if ((((-1 < (int)uStack_c0) &&
                 (in_stack_ffffff10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) &&
                (pCVar30 = pCVar31, in_stack_ffffff14 != (undefined *)0x0)) ||
               (pCVar30 = (CMwId *)0x0, in_stack_ffffff08 == (CFastBuffer<class_CCrystalFace*> *)0x0
               )) break;
            unaff_EDI = (CFastStringInt *)0x8dd34e;
            pCVar30 = pCVar31;
            iVar6 = (**(code **)(*(int *)in_stack_ffffff08 + 0x10))();
            in_stack_fffffefc = pCVar24;
            pCVar31 = pCVar30;
            if ((iVar6 == 0) || (pCVar33 == (CFastString *)0x0)) break;
            in_stack_ffffff10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            in_stack_ffffff14 = PTR_DAT_00bbf7d8;
            uVar10 = (**(code **)(*(int *)pCVar30 + 0xc))(pCVar30);
            pCVar31 = (CMwId *)0x8dd390;
            in_stack_fffffefc = pCVar24;
            pCStack_98 = (CPlugFileVHlsl *)(**(code **)(*(int *)pCVar24 + 0x10))();
            uStack_9c = uVar10;
            CFastString::SetString
                      ((CFastString *)&piStack_e8,(CFastStringInt *)&uStack_9c,
                       (SStringParam *)unaff_EBP);
            unaff_ESI = 0;
            unaff_EDI = (CFastStringInt *)&pSStack_dc;
            pSStack_dc = (STarget *)0xbbd27c;
            uStack_d8 = 10;
            pSVar26 = (SHeaderCommunity *)0x8dd3c6;
            uVar9 = CFastString::FindFirst((CFastString *)&uStack_e4,unaff_EDI,0,0);
            if (uVar9 == 0xffffffff) {
              unaff_EDI = (CFastStringInt *)0x8dd3de;
              CMwId::CreateFromLocalName((char *)appcStack_d4);
              unaff_EBP = (CPlugFileGPU *)appcStack_d4;
              pCVar28 = (CFastString *)0x8dd3f5;
              pCVar11 = CPlugFileGPU::DefineGetValue
                                  ((CPlugFileGPU *)this,unaff_EBP,(CMwId *)pCVar29);
              if (pCVar11 != (CFastString *)0x0) {
                pCVar29 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                unaff_EBP = (CPlugFileGPU *)0x0;
                pCVar28 = (CFastString *)&pcStack_70;
                unaff_EDI = (CFastStringInt *)0x8dd40e;
                iVar6 = CFastString::GetNatural
                                  (pCVar11,pCVar28,(ulong *)0x0,0,(ulong)in_stack_fffffefc);
                if ((iVar6 != 0) && (iStack_6c != 0)) {
                  pCStack_84 = (CSystemFids *)0x0;
                  pcStack_80 = PTR_DAT_00bbf7d8;
                  unaff_EBP = (CPlugFileGPU *)0x0;
                  unaff_ESI = 0;
                  unaff_EDI = (CFastStringInt *)0x0;
                  in_stack_00000014 = (void *)CONCAT31(in_stack_00000014._1_3_,3);
                  CFastString::SetNatural
                            ((CFastString *)&pCStack_84,(CFastString *)(iStack_6c + -1),0,0,0,0,1,
                             (int)pCVar30);
                  pCVar30 = (CMwId *)&pcStack_80;
                  in_stack_fffffefc = (CPlugFileGPU *)&iStack_c8;
                  pCVar29 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x8dd465;
                  CPlugFileGPU::DefineAddOrSet
                            ((CPlugFileGPU *)this,in_stack_fffffefc,pCVar30,pCVar33);
                  pCVar33 = (CFastString *)0x8dd46e;
                  uStack_7c = CFastBuffer<class_CCrystalFace*>::GetCount
                                        (&puStack_a0,in_stack_ffffff08);
                  if (uStack_7c != 0) {
                    do {
                      pCVar33 = (CFastString *)0x8dd485;
                      pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                          (&uStack_9c,pCVar18,(ulong)in_stack_ffffff0c);
                      iVar6 = 0x21;
                      bVar21 = true;
                      pcVar8 = *(char **)pSVar12;
                      pcVar19 = "DGbxShadowSoftPC3_DichotomyCount";
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        bVar21 = *pcVar8 == *pcVar19;
                        pcVar8 = pcVar8 + 1;
                        pcVar19 = pcVar19 + 1;
                      } while (bVar21);
                      if (bVar21) {
                        pCVar28 = CPlugFileGPU::DefineGetValue
                                            ((CPlugFileGPU *)this,(CPlugFileGPU *)&pSStack_bc,
                                             (CMwId *)in_stack_ffffff10);
                        uVar10 = *(undefined4 *)(pCVar28 + 4);
                        in_stack_ffffff0c = (SHeaderCommunity *)0x8dd4b6;
                        pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                            (&uStack_94,pCVar18,(ulong)in_stack_ffffff14);
                        *(undefined4 *)(pSVar12 + 4) = uVar10;
                        pSVar20 = pSStack_bc;
                        in_stack_ffffff10 = pCVar18;
                        break;
                      }
                      pCVar18 = pCVar18 + 1;
                      pSVar20 = pSStack_bc;
                    } while (pCVar18 < pCStack_78);
                  }
                  pSStack_dc = pSStack_dc + 1;
                  in_stack_ffffff08 = (CFastBuffer<class_CCrystalFace*> *)0x8dd4ce;
                  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                            (&pCStack_78,in_stack_ffffff0c);
                  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffff10);
                  in_stack_ffffff0c = (SHeaderCommunity *)0x8dd4f0;
                  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                            (&pSStack_cc,(SHeaderCommunity *)in_stack_ffffff10);
                  puVar17 = puStack_a0;
                  pSVar20 = pSVar20 + 8;
                  goto LAB_008dd646;
                }
              }
              CMwId::CreateFromLocalName((char *)&uStack_e4);
              pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
              pCVar11 = CPlugFileGPU::DefineGetValue
                                  ((CPlugFileGPU *)this,(CPlugFileGPU *)&uStack_e4,pCVar31);
              if (((pCVar11 == (CFastString *)0x0) ||
                  (iVar6 = CFastString::GetNatural
                                     (pCVar11,(CFastString *)&pCStack_84,(ulong *)0x0,0,
                                      (ulong)pCVar24), iVar6 == 0)) || (pcStack_80 == (char *)0x0))
              {
                iStack_4._0_1_ = 2;
                OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pSVar26);
                pSStack_cc = (STarget *)0x88760866;
                iStack_4._0_1_ = 1;
                OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pSVar26);
                iStack_4 = (uint)iStack_4._1_3_ << 8;
                CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xffffff0c,pSVar26);
                pCVar31 = pCVar30;
                break;
              }
              iStack_c8 = 0;
              ppcStack_c4 = (char **)PTR_DAT_00bbf7d8;
              iStack_4 = CONCAT31(iStack_4._1_3_,5);
              CFastString::SetNatural
                        ((CFastString *)&iStack_c8,(CFastString *)(pcStack_80 + -1),0,0,0,0,1,
                         (int)pSVar26);
              CPlugFileGPU::DefineAddOrSet
                        ((CPlugFileGPU *)this,(CPlugFileGPU *)&uStack_d8,(CMwId *)&ppcStack_c4,
                         (CFastString *)unaff_EDI);
              unaff_EDI = (CFastStringInt *)0x8dd592;
              uStack_94 = CFastBuffer<class_CCrystalFace*>::GetCount
                                    (&puStack_b8,(CFastBuffer<class_CCrystalFace*> *)pCVar28);
              if (uStack_94 != 0) {
                pCVar18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
                do {
                  unaff_EDI = (CFastStringInt *)0x8dd5af;
                  pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                      (aCStack_b4,pCVar18,(ulong)unaff_EBP);
                  iVar6 = 0x20;
                  bVar21 = true;
                  pcVar8 = *(char **)pSVar12;
                  pcVar19 = "DGbxPDefinedPC3_Shadow_Bilinear";
                  do {
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    bVar21 = *pcVar8 == *pcVar19;
                    pcVar8 = pcVar8 + 1;
                    pcVar19 = pcVar19 + 1;
                  } while (bVar21);
                  if (bVar21) {
                    pCVar28 = CPlugFileGPU::DefineGetValue
                                        ((CPlugFileGPU *)this,(CPlugFileGPU *)&pSStack_cc,
                                         (CMwId *)pCVar29);
                    uVar10 = *(undefined4 *)(pCVar28 + 4);
                    unaff_EBP = (CPlugFileGPU *)0x8dd5e0;
                    pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                                        (&pcStack_ac,pCVar18,(ulong)in_stack_fffffefc);
                    *(undefined4 *)(pSVar12 + 4) = uVar10;
                    pCVar29 = pCVar18;
                    break;
                  }
                  pCVar18 = pCVar18 + 1;
                } while (pCVar18 < apCStack_90[0]);
              }
              in_stack_ffffff0c = in_stack_ffffff0c + 1;
              appcStack_d4[0] = appcStack_d4[0] + 2;
              unaff_ESI = 0x8dd5f6;
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                        (&pSStack_bc,(SHeaderCommunity *)unaff_EBP);
              OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar29);
              OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar29);
              unaff_EBP = (CPlugFileGPU *)0x8dd629;
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                        (&uStack_e4,(SHeaderCommunity *)pCVar29);
              puVar17 = puStack_a0;
              pSVar20 = pSStack_cc;
            }
            else {
              unaff_EBP = (CPlugFileGPU *)0x8dd642;
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                        (&uStack_e4,(SHeaderCommunity *)pCVar29);
              puVar17 = puStack_a0;
            }
          }
        }
LAB_008dd646:
        pCVar33 = pCVar33 + -1;
        pSVar20 = pSVar20 + -8;
        pCVar31 = pCVar30;
        pSStack_dc = pSVar20;
      } while (pCVar33 < pCStack_88);
    }
    if (((in_stack_ffffff08 != (CFastBuffer<class_CCrystalFace*> *)0x0) &&
        (in_stack_ffffff0c != (SHeaderCommunity *)0x0)) && (pCVar30 == (CMwId *)0x0)) {
      *(undefined4 *)(this + 0x20) = *(undefined4 *)(pSStack_cc + (int)pCVar33 * 8 + 4);
    }
    if (((-1 < iStack_c8) && (in_stack_ffffff08 != (CFastBuffer<class_CCrystalFace*> *)0x0)) &&
       (in_stack_ffffff0c != (SHeaderCommunity *)0x0)) {
      if (pCVar30 != (CMwId *)0x0) {
        (**(code **)(*(int *)pCVar30 + 0x10))(pCVar30);
      }
      pvVar13 = (void *)(**(code **)(*(int *)in_stack_ffffff08 + 0xc))(in_stack_ffffff08);
      *(CFastBuffer<class_CCrystalFace*> **)(this + 0xb8) = in_stack_ffffff08;
      pCVar28 = pCVar33;
      uVar14 = (**(code **)(*(int *)pCVar33 + 0x10))();
      CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
                (this + 0xb0,(CFastBuffer<class_CSystemFidsFolder*> *)(uVar14 >> 2),(ulong)pCVar33);
      pvVar3 = *(void **)(this + 0xb4);
      uVar14 = (**(code **)(*(int *)pCVar28 + 0x10))(pCVar28);
      _memcpy(pvVar3,pvVar13,uVar14);
      CPlugFileGPU::UpdatePlugFromByteCode((CPlugFileGPU *)this,in_stack_0000001c,(int)pCVar31);
      if (DAT_00d705e8 != (code *)0x0) {
        (*DAT_00d705e8)();
      }
      if (piStack_e0 != (int *)0x0) {
        (**(code **)(*piStack_e0 + 8))();
      }
      if (piStack_e8 != (int *)0x0) {
        (**(code **)(*piStack_e8 + 8))();
      }
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                (&puStack_a4,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar28);
      ExceptionList = in_stack_00000014;
      return;
    }
    if (pCVar33 < pCStack_88) {
      pcStack_ac = *(char **)(pSStack_cc + (int)pCVar33 * 8);
    }
    else {
      pcStack_ac = "Target?";
    }
    piStack_e8 = (int *)0xbbd264;
    uStack_e4 = 0xc;
    if (pcStack_ac == (char *)0x0) {
      iStack_a8 = 0;
    }
    else {
      pcVar8 = pcStack_ac;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      iStack_a8 = (int)pcVar8 - (int)(pcStack_ac + 1);
    }
    puStack_a4 = &DAT_00bbd260;
    puStack_a0 = (undefined *)0x2;
    ppcStack_c4 = appcStack_d4[0];
    if (appcStack_d4[0] == (char **)0x0) {
      uStack_c0 = 0;
    }
    else {
      ppcVar15 = appcStack_d4[0];
      do {
        cVar1 = *(char *)ppcVar15;
        ppcVar15 = (char **)((int)ppcVar15 + 1);
      } while (cVar1 != '\0');
      uStack_c0 = (int)ppcVar15 - (int)((int)appcStack_d4[0] + 1);
    }
    pSVar27 = (SStringParamInt *)&piStack_e8;
    pSVar25 = (SStringParam *)&pcStack_ac;
    pCVar22 = (CFastStringInt *)&puStack_a4;
    pCStack_98 = (CPlugFileVHlsl *)0xbbd244;
    uStack_94 = 0x1b;
    CFastString::CFastString
              ((CFastString *)appcStack_d4,(CFastString *)&pCStack_98,(char *)&ppcStack_c4);
    pCVar32 = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,7);
    CPlugFile::GetFullName((CPlugFile *)this,(CPlugFile *)&stack0xffffff04,pCVar22);
    CFastStringInt::Concat(&stack0xffffff08,(CFastStringInt *)&stack0xffffff10,pSVar25);
    CVar4 = CFastStringInt::GetLatin1(&stack0xffffff0c,(CFastStringInt *)&iStack_a8);
    piStack_e8 = *(int **)CONCAT31(extraout_var,CVar4);
    iStack_4 = CONCAT31(iStack_4._1_3_,8);
    CFastString::ConcatBefore((CFastString *)&uStack_d8,(CFastStringInt *)&stack0xffffff14,pSVar27);
    pCVar28 = extraout_ECX;
    if (puStack_a0 != PTR_DAT_00bbf7d8) {
      puVar17 = puStack_a0 + -1;
      if ((puStack_a0[-1] & 0x80) != 0) {
        puVar17 = puStack_a0 + -4;
      }
      operator_delete__(puVar17);
      pCVar28 = extraout_ECX_00;
    }
    if ((pCVar31 == (CMwId *)0x0) ||
       (iVar6 = (**(code **)(*(int *)pCVar31 + 0x10))(pCVar31), pCVar28 = extraout_ECX_01,
       iVar6 == 0)) {
      if (iStack_c8 == -0x7789f79a) {
        piStack_e8 = (int *)0xbbd218;
        uStack_e4 = 0x29;
        CFastString::Concat((CFastString *)appcStack_d4,(CFastStringInt *)&piStack_e8,
                            (SStringParam *)unaff_EDI);
      }
      else {
        if (iStack_c8 < 0) {
          pcVar8 = "0x%08X";
        }
        else {
          pcVar8 = "Don\'t know why (hr=0x%08X)";
        }
        CFastString::ConcatFormat(pCVar28,(CFastStringInt *)appcStack_d4,pcVar8);
      }
    }
    else {
      Dx9Buffer_GetErrors((ID3DXBuffer *)pCVar31,(CFastString *)apCStack_90[0],
                          (CFastString *)appcStack_d4,pCStack_84);
    }
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar16 = CFastString::operator<<
                        ((CFastString *)&DAT_00d71e54,
                         (CPlugFileGpuBuilder *)"Shader compilation error",
                         (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)pCVar16,(CPlugFileGpuBuilder *)unaff_EBP,(char *)pCVar29)
    ;
    CClassicLog::AddLogStringInFile();
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    pCVar16 = CFastString::operator<<
                        ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)&ppcStack_c4,
                         (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<
              ((CFastString *)pCVar16,(CPlugFileGpuBuilder *)in_stack_fffffefc,(char *)pCVar31);
    CClassicLog::AddLogStringInFile();
    if (piStack_e0 != (int *)0x0) {
      (**(code **)(*piStack_e0 + 8))();
    }
    if (piStack_e8 != (int *)0x0) {
      (**(code **)(*piStack_e8 + 8))();
    }
    if (pSStack_dc != (STarget *)0x0) {
      (**(code **)(*(int *)pSStack_dc + 8))();
    }
    if (appcStack_d4[0] != (char **)PTR_DAT_00bbf7dc) {
      if ((*(byte *)((int)appcStack_d4[0] + -1) & 0x80) == 0) {
        ppcVar15 = (char **)((int)appcStack_d4[0] + -2);
      }
      else {
        ppcVar15 = appcStack_d4[0] + -1;
      }
      operator_delete__(ppcVar15);
      uStack_d8 = 0;
      appcStack_d4[0] = (char **)PTR_DAT_00bbf7dc;
    }
    if (puStack_b8 != PTR_DAT_00bbf7d8) {
      puVar17 = puStack_b8 + -1;
      if ((puStack_b8[-1] & 0x80) != 0) {
        puVar17 = puStack_b8 + -4;
      }
      operator_delete__(puVar17);
      pSStack_bc = (STarget *)0x0;
      puStack_b8 = PTR_DAT_00bbf7d8;
    }
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(&puStack_a4,pCVar32);
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CPlugFileVHlsl::GetFixedVHlsl
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CPlugFileVHlsl * __cdecl CPlugFileVHlsl::GetFixedVHlsl(CPlugShader *param_1)
{
{
  CPlugShader *this;
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CPlugFileGpuBuilder *pCVar10;
  SLoadedLight *pSVar11;
  CPlugFileVHlsl *pCVar12;
  CMwNod *extraout_EAX;
  CFastString *pCVar13;
  int *piVar14;
  CPlugFileGpuBuilder *pCVar15;
  CFastString *this_00;
  undefined *puVar16;
  CFastString *this_01;
  CFastString *this_02;
  CFastString *this_03;
  CFastString *this_04;
  CFastString *this_05;
  CFastString *this_06;
  undefined1 *puVar17;
  CFastString *this_07;
  CFastString *this_08;
  int iVar18;
  uint uVar19;
  uint uVar20;
  SCasterCat *pSVar21;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_ESI;
  uint uVar22;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar23;
  CMwNod *this_09;
  ulong unaff_EDI;
  void *unaff_retaddr;
  undefined4 uStack00000008;
  undefined1 uStack00000018;
  undefined1 uStack0000001c;
  undefined1 uStack00000020;
  undefined1 uStack00000038;
  undefined1 uStack0000003c;
  undefined1 uStack00000040;
  undefined1 uStack00000044;
  undefined1 uStack00000048;
  undefined1 uStack0000004c;
  undefined1 uStack00000068;
  undefined1 uStack0000006c;
  void *in_stack_00000088;
  char *in_stack_fffffd54;
  CPlugFileGpuBuilder *pCVar24;
  char *in_stack_fffffd58;
  CPlugFileGpuBuilder *in_stack_fffffd5c;
  char *in_stack_fffffd60;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_fffffd64;
  char *pcVar25;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar26;
  char *pcVar27;
  CPlugFileGpuBuilder *in_stack_fffffd6c;
  char *in_stack_fffffd70;
  CPlugFileGpuBuilder *in_stack_fffffd74;
  char *in_stack_fffffd78;
  char *in_stack_fffffd80;
  char *in_stack_fffffd84;
  CFastString *in_stack_fffffd88;
  char *in_stack_fffffd8c;
  CFastString *in_stack_fffffd90;
  char *in_stack_fffffd94;
  CFastString *in_stack_fffffd98;
  char *in_stack_fffffd9c;
  CFastString *in_stack_fffffda0;
  char *in_stack_fffffda4;
  CFastString *in_stack_fffffda8;
  char *in_stack_fffffdac;
  char *pcVar28;
  CFastString *pCVar29;
  CFastString *pCVar30;
  CFastString *pCVar31;
  char *pcVar32;
  CPlugFileGpuBuilder *pCVar33;
  CFastString *pCVar34;
  CFastString *pCVar35;
  CPlugFileGpuBuilder *pCVar36;
  char *in_stack_fffffdd0;
  CPlugFileGpuBuilder *in_stack_fffffdd4;
  NvStripInfo *in_stack_fffffdd8;
  CPlugFileGpuBuilder *in_stack_fffffddc;
  CPlugFileGpuBuilder *in_stack_fffffde0;
  char *in_stack_fffffde4;
  char *in_stack_fffffde8;
  char *in_stack_fffffdec;
  char *in_stack_fffffdf0;
  CPlugFileGpuBuilder *in_stack_fffffdf4;
  char *in_stack_fffffdf8;
  CPlugFileGpuBuilder *in_stack_fffffdfc;
  undefined *in_stack_fffffe00;
  CPlugFileGpuBuilder *pCVar37;
  CPlugFileGpuBuilder *in_stack_fffffe04;
  SLoadedLight *pSVar38;
  CPlugFileGpuBuilder *pCVar39;
  CPlugFileGpuBuilder *in_stack_fffffe0c;
  CPlugFileGpuBuilder *in_stack_fffffe10;
  CPlugFileGpuBuilder *in_stack_fffffe14;
  CPlugFileGpuBuilder *in_stack_fffffe18;
  CPlugFileGpuBuilder *in_stack_fffffe1c;
  CPlugFileGpuBuilder *in_stack_fffffe20;
  char *in_stack_fffffe24;
  undefined *puStack_1d8;
  undefined4 uStack_1d4;
  int *piStack_1d0;
  int iStack_1cc;
  CFastString aCStack_1c8 [4];
  CPlugFileGpuBuilder aCStack_1c4 [8];
  CPlugFileGpuBuilder aCStack_1bc [12];
  int iStack_1b0;
  CPlugFileGpuBuilder aCStack_1ac [4];
  CPlugFileGpuBuilder aCStack_1a8 [8];
  CPlugFileGpuBuilder aCStack_1a0 [4];
  undefined4 auStack_19c [3];
  CPlugFileGpuBuilder aCStack_190 [4];
  CPlugFileGpuBuilder aCStack_18c [8];
  CPlugFileGpuBuilder aCStack_184 [4];
  undefined4 uStack_180;
  int aiStack_17c [2];
  undefined *puStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  undefined *puStack_168;
  undefined *puStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined *puStack_158;
  undefined4 uStack_154;
  undefined1 *puStack_150;
  undefined4 uStack_14c;
  undefined *puStack_148;
  undefined4 uStack_144;
  undefined1 *puStack_140;
  undefined4 uStack_13c;
  undefined *puStack_138;
  undefined4 uStack_134;
  CPlugFileGpuBuilder aCStack_130 [4];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined1 *puStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  CPlugFileGpuBuilder aCStack_10c [4];
  CPlugFileGpuBuilder aCStack_108 [4];
  undefined4 uStack_104;
  undefined4 uStack_100;
  CPlugFileGpuBuilder aCStack_fc [4];
  undefined4 uStack_f8;
  CPlugFileGpuBuilder aCStack_f0 [4];
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  void *local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00ad8347;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  this = param_1 + 0x2c;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this,(CFastBuffer<class_CCrystalFace*> *)
                          (DAT_00cca150 ^ (uint)&stack0xfffffd48));
  if ((uVar3 != 0) &&
     (pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI),
     *(int *)(*(int *)pSVar4 + 0x3c) != 0)) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    if (*(int *)(*(int *)(*(int *)pSVar4 + 0x3c) + 0xa0) == 0) {
      ExceptionList = local_8;
      return (CPlugFileVHlsl *)0x0;
    }
    CPlugShader::SetVertexShader(param_1,(CPlugShaderPass *)0x0,(CPlugFileGPUV *)0x0);
  }
  iVar5 = (**(code **)(*(int *)param_1 + 0x10))();
  if (iVar5 == 0) {
    ExceptionList = local_8;
    return (CPlugFileVHlsl *)0x0;
  }
  (**(code **)(*(int *)param_1 + 0xa8))();
  uVar6 = (**(code **)(*(int *)param_1 + 0x98))();
  if (8 < uVar6) {
    uVar6 = 8;
  }
  uVar22 = 0;
  pcVar28 = (char *)0xffffffff;
  pCVar29 = (CFastString *)0xffffffff;
  pCVar30 = (CFastString *)0xffffffff;
  pCVar31 = (CFastString *)0xffffffff;
  pcVar32 = (char *)0xffffffff;
  pCVar33 = (CPlugFileGpuBuilder *)0xffffffff;
  pCVar34 = (CFastString *)0xffffffff;
  pCVar35 = (CFastString *)0xffffffff;
  if (uVar6 != 0) {
    do {
      iVar7 = (**(code **)(*(int *)param_1 + 0x9c))();
      uVar1 = *(uint *)(iVar7 + 0x30);
      iVar5 = *(int *)(iVar7 + 0x1c);
      uVar19 = uVar1 & 0xff;
      (&stack0xfffffdb0)[uVar22 * 4] = (char)*(undefined4 *)(&DAT_00d52788 + uVar19 * 4);
      if (((uVar19 == 0) && (*(int *)(iVar7 + 0x34) == 0)) && (*(int *)(iVar7 + 0x38) == 0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = 1;
      }
      uVar19 = (iVar7 << 8 ^ *(uint *)(&stack0xfffffdb0 + uVar22 * 4)) & 0x100 ^
               *(uint *)(&stack0xfffffdb0 + uVar22 * 4);
      *(uint *)(&stack0xfffffdb0 + uVar22 * 4) = uVar19;
      if ((iVar5 == 0) || ((*(uint *)(iVar5 + 0x4c) & 0x80000) == 0)) {
        iVar7 = 0;
      }
      else {
        iVar7 = 1;
      }
      uVar19 = (iVar7 << 9 ^ uVar19) & 0x200 ^ uVar19;
      *(uint *)(&stack0xfffffdb0 + uVar22 * 4) = uVar19;
      if ((iVar5 == 0) || (((byte)*(undefined4 *)(*(int *)(iVar5 + 0x48) + 0x24) & 3) != 3)) {
        uVar20 = 0;
      }
      else {
        uVar20 = 1;
      }
      *(uint *)(&stack0xfffffdb0 + uVar22 * 4) =
           (((int)((uVar1 & 0x78000) << 0xc) >> 0x1b) * 2 | uVar20) << 10 | uVar19 & 0x3ff;
      uVar22 = uVar22 + 1;
    } while (uVar22 < uVar6);
  }
  uVar6 = *(uint *)(param_1 + 0x8c);
  if (((uVar6 & 1) == 0) || ((uVar6 & 2) == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  uVar22 = uVar6 >> 2 & 1;
  if ((uVar22 == 0) || ((uVar6 & 8) == 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  if (((uVar6 & 0x20) == 0) || ((uVar6 & 0x40) == 0)) {
    iVar18 = 0;
  }
  else {
    iVar18 = 1;
  }
  if ((((uVar22 == 0) || ((uVar6 & 8) != 0)) ||
      (in_stack_fffffd64 =
            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
            ABS(*(float *)(param_1 + 0x44) - 0.0), _DAT_00bb0a68 <= (float)in_stack_fffffd64)) ||
     ((in_stack_fffffd64 =
            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
            ABS(*(float *)(param_1 + 0x48) - 0.0), _DAT_00bb0a68 <= (float)in_stack_fffffd64 ||
      (in_stack_fffffd64 =
            (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)
            ABS(*(float *)(param_1 + 0x4c) - 0.0), _DAT_00bb0a68 <= (float)in_stack_fffffd64)))) {
    iVar8 = 0;
  }
  else {
    iVar8 = 1;
  }
  uVar6 = (*(uint *)(param_1 + 0x1c) >> 7 & 0x40 | iVar18 << 5 |
          (uVar6 >> 1 & 0x10 | uVar6 & 5) ^ iVar5 * 2 ^ iVar7 * 8) ^ iVar8 << 7;
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d6f100,unaff_EBX);
  pCVar23 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar26 = pCVar9;
  if (pCVar9 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                         (&DAT_00d6f100,pCVar23,(ulong)in_stack_fffffd54);
      if (*(uint *)pSVar4 == uVar6) {
        uVar22 = 0;
        pSVar21 = pSVar4;
        while (pSVar21 = pSVar21 + 4,
              pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)in_stack_fffffd6c,
              *(int *)pSVar21 == *(int *)(&stack0xfffffdb8 + uVar22 * 4)) {
          uVar22 = uVar22 + 1;
          if (7 < uVar22) {
            ExceptionList = unaff_retaddr;
            return *(CPlugFileVHlsl **)(pSVar4 + 0x24);
          }
        }
      }
      pCVar23 = pCVar23 + 1;
    } while (pCVar23 < pCVar9);
  }
  CFastString::CFastString
            ((CFastString *)&puStack_1d8,(CFastString *)"FixedGenVHlsl",in_stack_fffffd54);
  pCVar24 = (CPlugFileGpuBuilder *)&DAT_00b30988;
  uStack00000008 = 0;
  pCVar10 = CFastString::operator<<
                      ((CFastString *)&uStack_1d4,(CPlugFileGpuBuilder *)&DAT_00b30b34,
                       (char *)pCVar23);
  pCVar10 = CFastString::operator<<((CFastString *)pCVar10,pCVar24,in_stack_fffffd58);
  CFastString::operator<<((CFastString *)pCVar10,in_stack_fffffd5c,in_stack_fffffd60);
  pSVar11 = CFastBuffer<struct_SFixedVHlsl>::AddNewElem(&DAT_00d6f100,in_stack_fffffd64);
  *(uint *)pSVar11 = uVar6;
  *(CFastString **)(pSVar11 + 4) = pCVar34;
  *(CFastString **)(pSVar11 + 8) = pCVar35;
  *(char **)(pSVar11 + 0xc) = in_stack_fffffdd0;
  *(CPlugFileGpuBuilder **)(pSVar11 + 0x10) = in_stack_fffffdd4;
  *(NvStripInfo **)(pSVar11 + 0x14) = in_stack_fffffdd8;
  *(CPlugFileGpuBuilder **)(pSVar11 + 0x18) = in_stack_fffffddc;
  *(CPlugFileGpuBuilder **)(pSVar11 + 0x1c) = in_stack_fffffde0;
  *(char **)(pSVar11 + 0x20) = in_stack_fffffde4;
  pSVar38 = pSVar11;
  pCVar12 = operator_new(0xe0);
  uStack00000018 = 1;
  if (pCVar12 == (CPlugFileVHlsl *)0x0) {
    this_09 = (CMwNod *)0x0;
  }
  else {
    CPlugFileVHlsl(pCVar12,(CPlugFileVHlsl *)pCVar26);
    this_09 = extraout_EAX;
  }
  uStack0000001c = 0;
  if (this_09 != *(CMwNod **)(pSVar11 + 0x24)) {
    if (this_09 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_09,(CMwNod *)in_stack_fffffd6c);
    }
    if (*(CMwNod **)(pSVar11 + 0x24) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pSVar11 + 0x24),(CMwNod *)in_stack_fffffd6c);
    }
    *(CMwNod **)(pSVar11 + 0x24) = this_09;
  }
  *(undefined4 *)(*(int *)(pSVar11 + 0x24) + 0xa0) = 1;
  CPlugFileGpuBuilder::CPlugFileGpuBuilder(aCStack_1a0,in_stack_fffffd6c);
  uStack00000020 = 2;
  pCVar10 = (CPlugFileGpuBuilder *)&DAT_00b9f8a4;
  if (DAT_00d123b8._2_2_ < 3) {
    pCVar10 = (CPlugFileGpuBuilder *)&DAT_00b9f98c;
  }
  CPlugFileGpuBuilder::Reset((CPlugFileGpuBuilder *)auStack_19c,*(GmFrustumIso4 **)(pSVar11 + 0x24))
  ;
  pcVar27 = "///////////////////////////////////////////////////////////";
  pcVar25 = "The shader won\'t save any reference to this code";
  auStack_19c[0] = 0;
  pCVar24 = CPlugFileGpuBuilder::operator<<
                      (aCStack_1a0,
                       (CPlugFileGpuBuilder *)
                       "///////////////////////////////////////////////////////////",
                       "WARNING: This code has been generated from fixed-pipeline");
  pCVar24 = CPlugFileGpuBuilder::operator<<(pCVar24,(CPlugFileGpuBuilder *)pcVar25,pcVar27);
  pCVar10 = CPlugFileGpuBuilder::operator<<(pCVar24,pCVar10,in_stack_fffffd70);
  CPlugFileGpuBuilder::operator<<(pCVar10,in_stack_fffffd74,in_stack_fffffd78);
  CPlugFileGpuBuilder::AddInOut(aCStack_190,(CPlugFileGpuBuilder *)0x0,0,0,(char *)pCVar12);
  CPlugFileGpuBuilder::AddInOut(aCStack_18c,(CPlugFileGpuBuilder *)0x1,0,0,in_stack_fffffd80);
  CFastString::CFastString
            ((CFastString *)&stack0xfffffd9c,(CFastString *)"const float4x4 GbxVisualPrCamera",
             in_stack_fffffd84);
  uStack00000038 = 3;
  uStack_180 = 4;
  CPlugFileGpuBuilder::AddStr(aCStack_184,(CPlugFileGpuBuilder *)&stack0xfffffda0,in_stack_fffffd88)
  ;
  uStack0000003c = 2;
  if (in_stack_fffffda8 != (CFastString *)PTR_DAT_00bbf7d8) {
    pCVar13 = in_stack_fffffda8 + -1;
    if (((byte)in_stack_fffffda8[-1] & 0x80) != 0) {
      pCVar13 = in_stack_fffffda8 + -4;
    }
    operator_delete__(pCVar13);
  }
  CFastString::CFastString
            ((CFastString *)&stack0xfffffda4,(CFastString *)"const float4 GbxEyeInVisual",
             in_stack_fffffd8c);
  uStack00000040 = 4;
  aiStack_17c[1] = 4;
  CPlugFileGpuBuilder::AddStr
            ((CPlugFileGpuBuilder *)aiStack_17c,(CPlugFileGpuBuilder *)&stack0xfffffda8,
             in_stack_fffffd90);
  uStack00000044 = 2;
  if (pcVar28 != PTR_DAT_00bbf7d8) {
    pcVar25 = pcVar28 + -1;
    if ((pcVar28[-1] & 0x80U) != 0) {
      pcVar25 = pcVar28 + -4;
    }
    operator_delete__(pcVar25);
  }
  CFastString::CFastString
            ((CFastString *)&stack0xfffffdac,
             (CFastString *)"Output.Position = mul(v.Position, GbxVisualPrCamera)",in_stack_fffffd94
            );
  uStack00000048 = 5;
  uStack_170 = 5;
  CPlugFileGpuBuilder::AddStr
            ((CPlugFileGpuBuilder *)&puStack_174,(CPlugFileGpuBuilder *)&stack0xfffffdb0,
             in_stack_fffffd98);
  uStack0000004c = 2;
  if (pCVar30 != (CFastString *)PTR_DAT_00bbf7d8) {
    pCVar13 = pCVar30 + -1;
    if (((byte)pCVar30[-1] & 0x80) != 0) {
      pCVar13 = pCVar30 + -4;
    }
    operator_delete__(pCVar13);
  }
  if ((uVar6 & 0x40) != 0) {
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdb4,(CFastString *)"float1 Fog : FOG",in_stack_fffffd9c);
    puStack_168 = (undefined *)0x3;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&uStack_16c,(CPlugFileGpuBuilder *)&stack0xfffffdb8,
               in_stack_fffffda0);
    if (pcVar32 != PTR_DAT_00bbf7d8) {
      pcVar25 = pcVar32 + -1;
      if ((pcVar32[-1] & 0x80U) != 0) {
        pcVar25 = pcVar32 + -4;
      }
      operator_delete__(pcVar25);
    }
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdbc,
               (CFastString *)
               "Output.Fog = GetFogInvIntens(v.Position, GbxEyeInVisual, Output.Position)",
               in_stack_fffffda4);
    uStack_160 = 5;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&puStack_164,(CPlugFileGpuBuilder *)&stack0xfffffdc0,
               in_stack_fffffda8);
    if (pCVar34 != (CFastString *)PTR_DAT_00bbf7d8) {
      pCVar13 = pCVar34 + -1;
      if (((byte)pCVar34[-1] & 0x80) != 0) {
        pCVar13 = pCVar34 + -4;
      }
      operator_delete__(pCVar13);
    }
  }
  CPlugFileGpuBuilder::AddInOut
            ((CPlugFileGpuBuilder *)&uStack_160,(CPlugFileGpuBuilder *)0x1,8,0,in_stack_fffffdac);
  if ((*(uint *)(param_1 + 0x8c) & 0x25) == 0) {
    CPlugFileGpuBuilder::AddInOut
              ((CPlugFileGpuBuilder *)&uStack_15c,(CPlugFileGpuBuilder *)0x0,8,0,pcVar28);
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdcc,(CFastString *)"Output.Color0 = v.Color0",
               (char *)pCVar29);
    uStack00000068 = 8;
    puStack_150 = &DAT_00000005;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&uStack_154,(CPlugFileGpuBuilder *)&stack0xfffffdd0,pCVar30);
    uStack0000006c = 2;
    if (in_stack_fffffdd8 == (NvStripInfo *)PTR_DAT_00bbf7d8) goto LAB_0088080c;
  }
  else {
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdc8,(CFastString *)"Output.Color0.rgb = 0",pcVar28);
    uStack_154 = 5;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&puStack_158,(CPlugFileGpuBuilder *)&stack0xfffffdcc,pCVar29);
    uStack00000068 = 2;
    if (in_stack_fffffdd4 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
      pCVar10 = in_stack_fffffdd4 + -1;
      if (((byte)in_stack_fffffdd4[-1] & 0x80) != 0) {
        pCVar10 = in_stack_fffffdd4 + -4;
      }
      operator_delete__(pCVar10);
    }
    CFastString::CFastString
              ((CFastString *)&stack0xfffffdd0,(CFastString *)"Output.Color0.a   = 1",
               (char *)pCVar30);
    uStack0000006c = 10;
    uStack_14c = 5;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&puStack_150,(CPlugFileGpuBuilder *)&stack0xfffffdd4,pCVar31);
    if (in_stack_fffffddc != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
      pCVar10 = in_stack_fffffddc + -1;
      if (((byte)in_stack_fffffddc[-1] & 0x80) != 0) {
        pCVar10 = in_stack_fffffddc + -4;
      }
      operator_delete__(pCVar10);
    }
    if ((*(uint *)(param_1 + 0x8c) & 1) != 0) {
      if ((*(uint *)(param_1 + 0x8c) & 2) == 0) {
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffdd8,
                   (CFastString *)"const float4 GbxMaterialAmbientRGB1",pcVar32);
        uStack_144 = 4;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&puStack_148,(CPlugFileGpuBuilder *)&stack0xfffffddc,
                   (CFastString *)pCVar33);
        if (in_stack_fffffde4 != PTR_DAT_00bbf7d8) {
          pCVar33 = (CPlugFileGpuBuilder *)(in_stack_fffffde4 + -1);
          if (((byte)*(CPlugFileGpuBuilder *)(in_stack_fffffde4 + -1) & 0x80) != 0) {
            pCVar33 = (CPlugFileGpuBuilder *)(in_stack_fffffde4 + -4);
          }
          operator_delete__(pCVar33);
        }
        pcVar32 = (char *)0x880231;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffde0,
                   (CFastString *)"float3\tMAmbient = GbxMaterialAmbientRGB1",(char *)pCVar34);
        uStack_13c = 5;
        pCVar33 = (CPlugFileGpuBuilder *)0x880251;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&puStack_140,(CPlugFileGpuBuilder *)&stack0xfffffde4,
                   pCVar35);
        if (in_stack_fffffdec != PTR_DAT_00bbf7d8) {
          pCVar35 = (CFastString *)(in_stack_fffffdec + -1);
          if ((in_stack_fffffdec[-1] & 0x80U) != 0) {
            pCVar35 = (CFastString *)(in_stack_fffffdec + -4);
          }
          goto LAB_00880272;
        }
      }
      else {
        CPlugFileGpuBuilder::AddInOut
                  ((CPlugFileGpuBuilder *)&uStack_14c,(CPlugFileGpuBuilder *)0x0,8,0,pcVar32);
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffddc,(CFastString *)"float3\tMAmbient = v.Color0",
                   (char *)pCVar33);
        pCVar33 = (CPlugFileGpuBuilder *)&stack0xfffffde0;
        puStack_140 = &DAT_00000005;
        pcVar32 = (char *)0x88019e;
        CPlugFileGpuBuilder::AddStr((CPlugFileGpuBuilder *)&uStack_144,pCVar33,pCVar34);
        if (in_stack_fffffde8 != PTR_DAT_00bbf7d8) {
LAB_00880272:
          operator_delete__(pCVar35);
        }
      }
      pCVar34 = (CFastString *)0x880288;
      CFastString::CFastString
                ((CFastString *)&stack0xfffffde8,
                 (CFastString *)"Output.Color0.rgb+= MAmbient*GbxLightAmbient",in_stack_fffffdd0);
      uStack_134 = 5;
      pCVar35 = (CFastString *)0x8802a8;
      CPlugFileGpuBuilder::AddStr
                ((CPlugFileGpuBuilder *)&puStack_138,(CPlugFileGpuBuilder *)&stack0xfffffdec,
                 (CFastString *)in_stack_fffffdd4);
      in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,2);
      if (in_stack_fffffdf4 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
        pCVar10 = in_stack_fffffdf4 + -1;
        if (((byte)in_stack_fffffdf4[-1] & 0x80) != 0) {
          pCVar10 = in_stack_fffffdf4 + -4;
        }
        operator_delete__(pCVar10);
      }
    }
    if ((*(uint *)(param_1 + 0x8c) & 4) != 0) {
      if ((((*(uint *)(param_1 + 0x8c) & 8) != 0) ||
          (in_stack_fffffdec = (char *)ABS(*(float *)(param_1 + 0x44) - 0.0),
          _DAT_00bb0a68 <= (float)in_stack_fffffdec)) ||
         ((in_stack_fffffdec = (char *)ABS(*(float *)(param_1 + 0x48) - 0.0),
          _DAT_00bb0a68 <= (float)in_stack_fffffdec ||
          (in_stack_fffffdec = (char *)ABS(*(float *)(param_1 + 0x4c) - 0.0),
          _DAT_00bb0a68 <= (float)in_stack_fffffdec)))) {
        pcVar25 = &DAT_00000005;
        pCVar35 = (CFastString *)0x0;
        pcVar28 = (char *)0x88043f;
        CPlugFileGpuBuilder::AddInOut
                  ((CPlugFileGpuBuilder *)&uStack_134,(CPlugFileGpuBuilder *)0x0,5,0,
                   (char *)in_stack_fffffdd8);
        if (((byte)param_1[0x8c] & 8) == 0) {
          pCVar29 = (CFastString *)0x8804de;
          CFastString::CFastString
                    ((CFastString *)&stack0xfffffdf4,
                     (CFastString *)"const float4 GbxMaterialDiffuseRGBA",(char *)in_stack_fffffddc)
          ;
          uStack_128 = 4;
          in_stack_fffffdd8 = (NvStripInfo *)0x880502;
          CPlugFileGpuBuilder::AddStr
                    ((CPlugFileGpuBuilder *)&uStack_12c,(CPlugFileGpuBuilder *)&stack0xfffffdf8,
                     (CFastString *)in_stack_fffffde0);
          if (in_stack_fffffe00 != PTR_DAT_00bbf7d8) {
            puVar16 = in_stack_fffffe00 + -1;
            if ((in_stack_fffffe00[-1] & 0x80) != 0) {
              puVar16 = in_stack_fffffe00 + -4;
            }
            operator_delete__(puVar16);
          }
          in_stack_fffffddc = (CPlugFileGpuBuilder *)0x880539;
          CFastString::CFastString
                    ((CFastString *)&stack0xfffffdfc,
                     (CFastString *)"float3\tMDiffuse = GbxMaterialDiffuseRGBA",in_stack_fffffde4);
          puStack_120 = &DAT_00000005;
          in_stack_fffffde0 = (CPlugFileGpuBuilder *)0x880559;
          CPlugFileGpuBuilder::AddStr
                    ((CPlugFileGpuBuilder *)&uStack_124,(CPlugFileGpuBuilder *)&stack0xfffffe00,
                     (CFastString *)in_stack_fffffde8);
          if (pSVar38 != (SLoadedLight *)PTR_DAT_00bbf7d8) {
            pSVar11 = pSVar38 + -1;
            if (((byte)pSVar38[-1] & 0x80) != 0) {
              pSVar11 = pSVar38 + -4;
            }
            operator_delete__(pSVar11);
          }
          in_stack_fffffde8 = "Output.Color0.a = GbxMaterialDiffuseRGBA.a";
          in_stack_fffffde4 = (char *)0x880590;
          CFastString::CFastString
                    ((CFastString *)&stack0xfffffe04,
                     (CFastString *)"Output.Color0.a = GbxMaterialDiffuseRGBA.a",in_stack_fffffdec);
        }
        else {
          pCVar29 = (CFastString *)&DAT_00000008;
          pcVar25 = (char *)0x0;
          pCVar35 = (CFastString *)0x88045e;
          CPlugFileGpuBuilder::AddInOut
                    (aCStack_130,(CPlugFileGpuBuilder *)0x0,8,0,(char *)in_stack_fffffddc);
          in_stack_fffffdd8 = (NvStripInfo *)0x88046c;
          CFastString::CFastString
                    ((CFastString *)&stack0xfffffdf8,(CFastString *)"float3\tMDiffuse = v.Color0",
                     (char *)in_stack_fffffde0);
          uStack_124 = 5;
          in_stack_fffffddc = (CPlugFileGpuBuilder *)0x88048c;
          CPlugFileGpuBuilder::AddStr
                    ((CPlugFileGpuBuilder *)&uStack_128,(CPlugFileGpuBuilder *)&stack0xfffffdfc,
                     (CFastString *)in_stack_fffffde4);
          if (in_stack_fffffe04 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
            pCVar10 = in_stack_fffffe04 + -1;
            if (((byte)in_stack_fffffe04[-1] & 0x80) != 0) {
              pCVar10 = in_stack_fffffe04 + -4;
            }
            operator_delete__(pCVar10);
          }
          in_stack_fffffde4 = "Output.Color0.a = v.Color0.a";
          in_stack_fffffde0 = (CPlugFileGpuBuilder *)0x8804c3;
          CFastString::CFastString
                    ((CFastString *)&stack0xfffffe00,(CFastString *)"Output.Color0.a = v.Color0.a",
                     in_stack_fffffde8);
        }
        uStack_144 = 5;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&puStack_148,(CPlugFileGpuBuilder *)&stack0xfffffddc,
                   (CFastString *)pCVar33);
        if (in_stack_fffffde4 != PTR_DAT_00bbf7d8) {
          pCVar33 = (CPlugFileGpuBuilder *)(in_stack_fffffde4 + -1);
          if (((byte)*(CPlugFileGpuBuilder *)(in_stack_fffffde4 + -1) & 0x80) != 0) {
            pCVar33 = (CPlugFileGpuBuilder *)(in_stack_fffffde4 + -4);
          }
          operator_delete__(pCVar33);
        }
        pcVar32 = (char *)0x8805e7;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffde0,
                   (CFastString *)
                   "float3 LDiffuse = GbxLightDirRgb0*max(0, dot(v.Normal, -GbxLightDirDir0))",
                   pcVar28);
        uStack_13c = 5;
        pCVar33 = (CPlugFileGpuBuilder *)0x880607;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&puStack_140,(CPlugFileGpuBuilder *)&stack0xfffffde4,
                   pCVar35);
        if (in_stack_fffffdec != PTR_DAT_00bbf7d8) {
          pcVar28 = in_stack_fffffdec + -1;
          if ((in_stack_fffffdec[-1] & 0x80U) != 0) {
            pcVar28 = in_stack_fffffdec + -4;
          }
          operator_delete__(pcVar28);
        }
        pCVar34 = (CFastString *)0x88063e;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffde8,
                   (CFastString *)"Output.Color0.rgb+= MDiffuse*LDiffuse",pcVar25);
        uStack_134 = 5;
        pCVar35 = (CFastString *)0x88065e;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&puStack_138,(CPlugFileGpuBuilder *)&stack0xfffffdec,
                   pCVar29);
        in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,2);
        if (in_stack_fffffdf4 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar10 = in_stack_fffffdf4 + -1;
          if (((byte)in_stack_fffffdf4[-1] & 0x80) != 0) {
            pCVar10 = in_stack_fffffdf4 + -4;
          }
          goto LAB_0088067f;
        }
      }
      else {
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffdf0,
                   (CFastString *)"const float4 GbxMaterialDiffuseRGBA",(char *)in_stack_fffffdd8);
        uStack_12c = 4;
        pCVar10 = (CPlugFileGpuBuilder *)0x8803a9;
        CPlugFileGpuBuilder::AddStr
                  (aCStack_130,(CPlugFileGpuBuilder *)&stack0xfffffdf4,
                   (CFastString *)in_stack_fffffddc);
        if (in_stack_fffffdfc != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar24 = in_stack_fffffdfc + -1;
          if (((byte)in_stack_fffffdfc[-1] & 0x80) != 0) {
            pCVar24 = in_stack_fffffdfc + -4;
          }
          operator_delete__(pCVar24);
        }
        in_stack_fffffdd8 = (NvStripInfo *)0x8803e0;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffdf8,
                   (CFastString *)"Output.Color0.a = GbxMaterialDiffuseRGBA.a",
                   (char *)in_stack_fffffde0);
        in_stack_fffffde0 = (CPlugFileGpuBuilder *)&stack0xfffffdfc;
        uStack_124 = 5;
        in_stack_fffffddc = (CPlugFileGpuBuilder *)0x880400;
        CPlugFileGpuBuilder::AddStr
                  ((CPlugFileGpuBuilder *)&uStack_128,in_stack_fffffde0,
                   (CFastString *)in_stack_fffffde4);
        if (in_stack_fffffe04 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          in_stack_fffffde4 = (char *)(in_stack_fffffe04 + -1);
          if (((byte)in_stack_fffffe04[-1] & 0x80) != 0) {
            in_stack_fffffde4 = (char *)(in_stack_fffffe04 + -4);
          }
LAB_0088067f:
          operator_delete__(pCVar10);
        }
      }
    }
    if ((*(uint *)(param_1 + 0x8c) & 0x20) == 0) goto LAB_0088080c;
    if ((*(uint *)(param_1 + 0x8c) & 0x40) == 0) {
      pcVar28 = (char *)0x880711;
      CFastString::CFastString
                ((CFastString *)&stack0xfffffdf0,
                 (CFastString *)"const float4 GbxMaterialEmissiveRGB1",(char *)in_stack_fffffdd8);
      uStack_12c = 4;
      pCVar29 = (CFastString *)0x880735;
      CPlugFileGpuBuilder::AddStr
                (aCStack_130,(CPlugFileGpuBuilder *)&stack0xfffffdf4,
                 (CFastString *)in_stack_fffffddc);
      if (in_stack_fffffdfc != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
        pCVar10 = in_stack_fffffdfc + -1;
        if (((byte)in_stack_fffffdfc[-1] & 0x80) != 0) {
          pCVar10 = in_stack_fffffdfc + -4;
        }
        operator_delete__(pCVar10);
      }
      in_stack_fffffdd8 = (NvStripInfo *)0x88076c;
      CFastString::CFastString
                ((CFastString *)&stack0xfffffdf8,
                 (CFastString *)"float3\tMEmissive= GbxMaterialEmissiveRGB1",
                 (char *)in_stack_fffffde0);
      in_stack_fffffde0 = (CPlugFileGpuBuilder *)&stack0xfffffdfc;
      uStack_124 = 5;
      in_stack_fffffddc = (CPlugFileGpuBuilder *)0x88078c;
      CPlugFileGpuBuilder::AddStr
                ((CPlugFileGpuBuilder *)&uStack_128,in_stack_fffffde0,
                 (CFastString *)in_stack_fffffde4);
      if (in_stack_fffffe04 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
        in_stack_fffffde4 = (char *)(in_stack_fffffe04 + -1);
        if (((byte)in_stack_fffffe04[-1] & 0x80) != 0) {
          in_stack_fffffde4 = (char *)(in_stack_fffffe04 + -4);
        }
        goto LAB_008807ad;
      }
    }
    else {
      pcVar28 = &DAT_00000008;
      pCVar35 = (CFastString *)0x0;
      CPlugFileGpuBuilder::AddInOut
                ((CPlugFileGpuBuilder *)&uStack_134,(CPlugFileGpuBuilder *)0x0,8,0,
                 (char *)in_stack_fffffdd8);
      pCVar29 = (CFastString *)0x8806b9;
      CFastString::CFastString
                ((CFastString *)&stack0xfffffdf4,(CFastString *)"float3\tMEmissive= v.Color0",
                 (char *)in_stack_fffffddc);
      in_stack_fffffddc = (CPlugFileGpuBuilder *)&stack0xfffffdf8;
      uStack_128 = 5;
      in_stack_fffffdd8 = (NvStripInfo *)0x8806d9;
      CPlugFileGpuBuilder::AddStr
                ((CPlugFileGpuBuilder *)&uStack_12c,in_stack_fffffddc,
                 (CFastString *)in_stack_fffffde0);
      if (in_stack_fffffe00 != PTR_DAT_00bbf7d8) {
        in_stack_fffffde0 = (CPlugFileGpuBuilder *)(in_stack_fffffe00 + -1);
        if ((in_stack_fffffe00[-1] & 0x80) != 0) {
          in_stack_fffffde0 = (CPlugFileGpuBuilder *)(in_stack_fffffe00 + -4);
        }
LAB_008807ad:
        operator_delete__(pCVar35);
      }
    }
    pCVar34 = (CFastString *)0x8807c3;
    CFastString::CFastString
              ((CFastString *)&stack0xfffffde8,(CFastString *)"Output.Color0.rgb+= MEmissive",
               pcVar28);
    uStack_134 = 5;
    CPlugFileGpuBuilder::AddStr
              ((CPlugFileGpuBuilder *)&puStack_138,(CPlugFileGpuBuilder *)&stack0xfffffdec,pCVar29);
    in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,2);
    if (in_stack_fffffdf4 == (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) goto LAB_0088080c;
    in_stack_fffffdd4 = in_stack_fffffdf4 + -1;
    if (((byte)in_stack_fffffdf4[-1] & 0x80) != 0) {
      in_stack_fffffdd4 = in_stack_fffffdf4 + -4;
    }
  }
  operator_delete__(in_stack_fffffdd4);
LAB_0088080c:
  pCVar10 = (CPlugFileGpuBuilder *)0x0;
  pCVar24 = (CPlugFileGpuBuilder *)0x0;
  if (in_stack_fffffe04 != (CPlugFileGpuBuilder *)0x0) {
    do {
      pCVar37 = pCVar24;
      piVar14 = (int *)(**(code **)(*(int *)param_1 + 0x9c))();
      pCVar36 = (CPlugFileGpuBuilder *)0x880844;
      piStack_1d0 = piVar14;
      iVar5 = (**(code **)(*piVar14 + 0x10))();
      if (((iVar5 == 0) || ((piVar14[0xf] & 0x3800U) == 0)) && (piVar14[7] != 0)) {
        if ((CPlugFileGpuBuilder *)&DAT_00000007 < pCVar24) {
          uStack_1d4 = 0;
          piStack_1d0 = (int *)PTR_DAT_00bbf7d8;
          pCVar36 = (CPlugFileGpuBuilder *)0x8808b8;
          OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_1);
          in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,2);
          if (piStack_1d0 != (int *)PTR_DAT_00bbf7d8) {
            piVar14 = (int *)((int)piStack_1d0 + -1);
            if ((*(byte *)((int)piStack_1d0 + -1) & 0x80) != 0) {
              piVar14 = piStack_1d0 + -1;
            }
            operator_delete__(piVar14);
            uStack_1d4 = 0;
            piStack_1d0 = (int *)PTR_DAT_00bbf7d8;
          }
        }
        pCVar24 = (CPlugFileGpuBuilder *)(*(uint *)(iStack_1cc + 0x30) & 0xff);
        pCVar35 = (CFastString *)((int)(*(uint *)(iStack_1cc + 0x30) << 0xc) >> 0x1b);
        uVar2 = *(undefined4 *)(&DAT_00d52788 + (int)pCVar24 * 4);
        if ((CFastString *)&DAT_00000007 < pCVar35) {
          pcVar28 = "BadIndex";
        }
        else {
          pcVar28 = (&PTR_s_TexCoord0_00d14240)[(int)pCVar35];
        }
        pcVar25 = (char *)0x88092b;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffe24,(CFastString *)pcVar28,(char *)in_stack_fffffdd8)
        ;
        pcVar27 = (char *)0x880948;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffe20,
                   (CFastString *)(&PTR_s_TexCoord0_00d14240)[(int)in_stack_fffffe04],
                   (char *)in_stack_fffffddc);
        pcVar28 = "Crd3d";
        if (in_stack_fffffe10 == (CPlugFileGpuBuilder *)0x0) {
          pcVar28 = "Coord";
        }
        in_stack_fffffdd8 = (NvStripInfo *)0x88096b;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffe1c,(CFastString *)pcVar28,(char *)in_stack_fffffde0)
        ;
        in_stack_fffffddc = (CPlugFileGpuBuilder *)0x880981;
        CFastString::operator<<((CFastString *)&stack0xfffffe20,in_stack_fffffe0c,in_stack_fffffde4)
        ;
        pCVar39 = (CPlugFileGpuBuilder *)0x0;
        in_stack_fffffe0c = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffe1c,(CFastString *)"const float4x",in_stack_fffffde8)
        ;
        in_stack_fffffde4 = &DAT_00b30a70;
        if (in_stack_fffffe1c == (CPlugFileGpuBuilder *)0x0) {
          in_stack_fffffde4 = &DAT_00b30a74;
        }
        in_stack_fffffde0 = (CPlugFileGpuBuilder *)0x8809d1;
        pCVar15 = CFastString::operator<<
                            ((CFastString *)&stack0xfffffe20,
                             (CPlugFileGpuBuilder *)in_stack_fffffde4," ");
        in_stack_fffffde8 = (char *)0x8809d8;
        CFastString::operator<<((CFastString *)pCVar15,pCVar10,in_stack_fffffdf0);
        switch(uVar2) {
        case 0:
          if (((pCVar24 == (CPlugFileGpuBuilder *)0x0) && (*(int *)(iStack_1b0 + 0x34) == 0)) &&
             (*(int *)(iStack_1b0 + 0x38) == 0)) {
            in_stack_fffffde0 = (CPlugFileGpuBuilder *)0x880a17;
            CPlugFileGpuBuilder::AddInOut
                      ((CPlugFileGpuBuilder *)&uStack_118,(CPlugFileGpuBuilder *)0x0,(EInOut)pCVar35
                       ,1,(char *)0x0);
            CFastString::CFastString
                      ((CFastString *)aiStack_17c,(CFastString *)"Output.",(char *)in_stack_fffffdf4
                      );
            in_stack_fffffdf4 = aCStack_1bc;
            pCVar10 = aCStack_1c4;
            in_stack_fffffde8 = (char *)0x880a46;
            pCVar33 = CFastString::operator<<(this_00,pCVar10," = v.");
            in_stack_fffffdf0 = (char *)0x880a4d;
            pCVar33 = CFastString::operator<<
                                ((CFastString *)pCVar33,in_stack_fffffdf4,in_stack_fffffdf8);
            in_stack_fffffdf8 = (char *)0x880a54;
            pCVar33 = CFastString::operator<<
                                ((CFastString *)pCVar33,in_stack_fffffdfc,(char *)pCVar37);
            pCVar37 = *(CPlugFileGpuBuilder **)(pCVar33 + 4);
            uStack_104 = 5;
            in_stack_fffffdfc = (CPlugFileGpuBuilder *)0x880a6f;
            CPlugFileGpuBuilder::operator<<(aCStack_108,pCVar37,(char *)in_stack_fffffe04);
            in_stack_fffffde4 = (char *)pCVar24;
            if (puStack_164 != PTR_DAT_00bbf7d8) {
              puVar16 = puStack_164 + -1;
              if ((puStack_164[-1] & 0x80) != 0) {
                puVar16 = puStack_164 + -4;
              }
              pCVar37 = (CPlugFileGpuBuilder *)0x880aa0;
              operator_delete__(puVar16);
              puStack_168 = (undefined *)0x0;
              puStack_164 = PTR_DAT_00bbf7d8;
              in_stack_fffffde4 = (char *)pCVar24;
            }
          }
          else {
            in_stack_fffffde4 = (char *)0x0;
            in_stack_fffffde0 = (CPlugFileGpuBuilder *)0x880acf;
            CPlugFileGpuBuilder::AddInOut
                      ((CPlugFileGpuBuilder *)&uStack_118,(CPlugFileGpuBuilder *)0x0,(EInOut)pCVar35
                       ,3,(char *)0x0);
            pCVar10 = (CPlugFileGpuBuilder *)0x880ae0;
            CFastString::CFastString
                      ((CFastString *)aCStack_184,(CFastString *)"GbxVTexCoordToTex",
                       (char *)in_stack_fffffdf4);
            pCVar33 = CFastString::operator<<
                                (this_01,(CPlugFileGpuBuilder *)&iStack_1cc,in_stack_fffffdf8);
            puStack_138 = *(undefined **)(pCVar33 + 4);
            uStack_134 = *(undefined4 *)pCVar33;
            CFastString::SetString
                      ((CFastString *)&stack0xfffffe1c,(CFastStringInt *)&puStack_138,
                       (SStringParam *)in_stack_fffffdfc);
            if (puStack_174 != PTR_DAT_00bbf7d8) {
              puVar16 = puStack_174 + -1;
              if ((puStack_174[-1] & 0x80) != 0) {
                puVar16 = puStack_174 + -4;
              }
              operator_delete__(puVar16);
              aiStack_17c[1] = 0;
              puStack_174 = PTR_DAT_00bbf7d8;
            }
            pCVar33 = CFastString::operator<<
                                ((CFastString *)&iStack_1cc,(CPlugFileGpuBuilder *)&stack0xfffffe20,
                                 (char *)pCVar37);
            uStack_104 = 4;
            CPlugFileGpuBuilder::AddStr(aCStack_108,pCVar33,(CFastString *)in_stack_fffffe04);
            CFastString::CFastString
                      ((CFastString *)&uStack_144,(CFastString *)"Output.",(char *)pCVar39);
            pcVar25 = ")";
            in_stack_fffffe04 = (CPlugFileGpuBuilder *)&uStack_1d4;
            pcVar28 = ", ";
            in_stack_fffffdfc = aCStack_1a8;
            in_stack_fffffdf4 = (CPlugFileGpuBuilder *)&iStack_1b0;
            in_stack_fffffdf0 = (char *)0x880bc0;
            pCVar33 = CFastString::operator<<(this_02,in_stack_fffffdf4," = mul(v.");
            in_stack_fffffdf8 = (char *)0x880bc7;
            pCVar33 = CFastString::operator<<((CFastString *)pCVar33,in_stack_fffffdfc,pcVar28);
            pCVar37 = (CPlugFileGpuBuilder *)0x880bce;
            pCVar33 = CFastString::operator<<((CFastString *)pCVar33,in_stack_fffffe04,pcVar25);
            pCVar39 = (CPlugFileGpuBuilder *)0x880bd5;
            pCVar33 = CFastString::operator<<
                                ((CFastString *)pCVar33,in_stack_fffffe0c,(char *)in_stack_fffffe10)
            ;
            in_stack_fffffe10 = (CPlugFileGpuBuilder *)0x880bdc;
            pCVar33 = CFastString::operator<<
                                ((CFastString *)pCVar33,in_stack_fffffe14,(char *)in_stack_fffffe18)
            ;
            in_stack_fffffe18 = (CPlugFileGpuBuilder *)0x880be3;
            pCVar33 = CFastString::operator<<
                                ((CFastString *)pCVar33,in_stack_fffffe1c,(char *)in_stack_fffffe20)
            ;
            in_stack_fffffe20 = *(CPlugFileGpuBuilder **)(pCVar33 + 4);
            uStack_e4 = 5;
            in_stack_fffffe1c = (CPlugFileGpuBuilder *)0x880bfe;
            CPlugFileGpuBuilder::operator<<
                      ((CPlugFileGpuBuilder *)&uStack_e8,in_stack_fffffe20,in_stack_fffffe24);
            in_stack_fffffde8 = (char *)pCVar35;
            if (puStack_120 != PTR_DAT_00bbf7d8) {
              puVar17 = puStack_120 + -1;
              if ((puStack_120[-1] & 0x80) != 0) {
                puVar17 = puStack_120 + -4;
              }
              in_stack_fffffe20 = (CPlugFileGpuBuilder *)0x880c2f;
              operator_delete__(puVar17);
              uStack_124 = 0;
              puStack_120 = PTR_DAT_00bbf7d8;
              in_stack_fffffde8 = (char *)pCVar35;
            }
          }
          break;
        case 1:
          pCVar10 = (CPlugFileGpuBuilder *)0x880c5d;
          CFastString::CFastString
                    ((CFastString *)&puStack_148,(CFastString *)"GbxVPositionToTex",
                     (char *)in_stack_fffffdf4);
          in_stack_fffffdf0 = (char *)0x880c71;
          pCVar33 = CFastString::operator<<
                              (this_03,(CPlugFileGpuBuilder *)&iStack_1cc,in_stack_fffffdf8);
          puStack_120 = *(undefined1 **)(pCVar33 + 4);
          uStack_11c = *(undefined4 *)pCVar33;
          in_stack_fffffdf4 = (CPlugFileGpuBuilder *)0x880c95;
          CFastString::SetString
                    ((CFastString *)&stack0xfffffe1c,(CFastStringInt *)&puStack_120,
                     (SStringParam *)in_stack_fffffdfc);
          if (puStack_138 != PTR_DAT_00bbf7d8) {
            puVar16 = puStack_138 + -1;
            if ((puStack_138[-1] & 0x80) != 0) {
              puVar16 = puStack_138 + -4;
            }
            operator_delete__(puVar16);
            uStack_13c = 0;
            puStack_138 = PTR_DAT_00bbf7d8;
          }
          pCVar33 = CFastString::operator<<
                              ((CFastString *)&iStack_1cc,(CPlugFileGpuBuilder *)&stack0xfffffe20,
                               (char *)pCVar37);
          uStack_104 = 4;
          CPlugFileGpuBuilder::AddStr(aCStack_108,pCVar33,(CFastString *)in_stack_fffffe04);
          CFastString::CFastString
                    ((CFastString *)&uStack_13c,(CFastString *)"Output.",(char *)pCVar39);
          pcVar28 = ")";
          in_stack_fffffe04 = (CPlugFileGpuBuilder *)&uStack_1d4;
          in_stack_fffffdfc = (CPlugFileGpuBuilder *)&iStack_1b0;
          in_stack_fffffdf8 = (char *)0x880d33;
          pCVar33 = CFastString::operator<<(this_04,in_stack_fffffdfc," = mul(v.Position, ");
          pCVar37 = (CPlugFileGpuBuilder *)0x880d3a;
          pCVar33 = CFastString::operator<<((CFastString *)pCVar33,in_stack_fffffe04,pcVar28);
          pCVar39 = (CPlugFileGpuBuilder *)0x880d41;
          pCVar33 = CFastString::operator<<
                              ((CFastString *)pCVar33,in_stack_fffffe0c,(char *)in_stack_fffffe10);
          in_stack_fffffe10 = (CPlugFileGpuBuilder *)0x880d48;
          pCVar33 = CFastString::operator<<
                              ((CFastString *)pCVar33,in_stack_fffffe14,(char *)in_stack_fffffe18);
          in_stack_fffffe18 = *(CPlugFileGpuBuilder **)(pCVar33 + 4);
          uStack_ec = 5;
          in_stack_fffffe14 = (CPlugFileGpuBuilder *)0x880d63;
          CPlugFileGpuBuilder::operator<<(aCStack_f0,in_stack_fffffe18,(char *)in_stack_fffffe1c);
          if (puStack_120 != PTR_DAT_00bbf7d8) {
            puVar17 = puStack_120 + -1;
            if ((puStack_120[-1] & 0x80) != 0) {
              puVar17 = puStack_120 + -4;
            }
            in_stack_fffffe18 = (CPlugFileGpuBuilder *)0x880d94;
            operator_delete__(puVar17);
            uStack_124 = 0;
            puStack_120 = PTR_DAT_00bbf7d8;
          }
          break;
        case 2:
          pCVar10 = (CPlugFileGpuBuilder *)0x880dc1;
          CFastString::CFastString
                    ((CFastString *)&uStack_160,(CFastString *)"GbxVNormalToTex",
                     (char *)in_stack_fffffdf4);
          pCVar33 = CFastString::operator<<
                              (this_05,(CPlugFileGpuBuilder *)&iStack_1cc,in_stack_fffffdf8);
          uStack_128 = *(undefined4 *)(pCVar33 + 4);
          uStack_124 = *(undefined4 *)pCVar33;
          CFastString::SetString
                    ((CFastString *)&stack0xfffffe1c,(CFastStringInt *)&uStack_128,
                     (SStringParam *)in_stack_fffffdfc);
          if (puStack_150 != PTR_DAT_00bbf7d8) {
            puVar17 = puStack_150 + -1;
            if ((puStack_150[-1] & 0x80) != 0) {
              puVar17 = puStack_150 + -4;
            }
            operator_delete__(puVar17);
            uStack_154 = 0;
            puStack_150 = PTR_DAT_00bbf7d8;
          }
          in_stack_fffffdf8 = &DAT_00000005;
          in_stack_fffffdf4 = (CPlugFileGpuBuilder *)0x0;
          in_stack_fffffdf0 = (char *)0x880e4f;
          CPlugFileGpuBuilder::AddInOut(aCStack_10c,(CPlugFileGpuBuilder *)0x0,5,0,(char *)pCVar37);
          pCVar33 = CFastString::operator<<
                              (aCStack_1c8,(CPlugFileGpuBuilder *)&stack0xfffffe24,
                               (char *)in_stack_fffffe04);
          uStack_100 = 4;
          CPlugFileGpuBuilder::AddStr
                    ((CPlugFileGpuBuilder *)&uStack_104,pCVar33,(CFastString *)pCVar39);
          CFastString::CFastString
                    ((CFastString *)&uStack_15c,(CFastString *)"Output.",(char *)in_stack_fffffe0c);
          pcVar28 = ")";
          pCVar39 = (CPlugFileGpuBuilder *)&piStack_1d0;
          pCVar37 = aCStack_1ac;
          in_stack_fffffdfc = (CPlugFileGpuBuilder *)0x880ea9;
          pCVar33 = CFastString::operator<<(this_06,pCVar37," = mul(float4(v.Normal,1), ");
          in_stack_fffffe04 = (CPlugFileGpuBuilder *)0x880eb0;
          pCVar33 = CFastString::operator<<((CFastString *)pCVar33,pCVar39,pcVar28);
          in_stack_fffffe0c = (CPlugFileGpuBuilder *)0x880eb7;
          pCVar33 = CFastString::operator<<
                              ((CFastString *)pCVar33,in_stack_fffffe10,(char *)in_stack_fffffe14);
          in_stack_fffffe14 = (CPlugFileGpuBuilder *)0x880ebe;
          pCVar33 = CFastString::operator<<
                              ((CFastString *)pCVar33,in_stack_fffffe18,(char *)in_stack_fffffe1c);
          in_stack_fffffe1c = *(CPlugFileGpuBuilder **)(pCVar33 + 4);
          uStack_e8 = 5;
          in_stack_fffffe18 = (CPlugFileGpuBuilder *)0x880ed9;
          CPlugFileGpuBuilder::operator<<
                    ((CPlugFileGpuBuilder *)&uStack_ec,in_stack_fffffe1c,(char *)in_stack_fffffe20);
          if (puStack_140 != PTR_DAT_00bbf7d8) {
            puVar17 = puStack_140 + -1;
            if ((puStack_140[-1] & 0x80) != 0) {
              puVar17 = puStack_140 + -4;
            }
            in_stack_fffffe1c = (CPlugFileGpuBuilder *)0x880f0a;
            operator_delete__(puVar17);
            uStack_144 = 0;
            puStack_140 = PTR_DAT_00bbf7d8;
          }
          break;
        case 3:
          pCVar10 = (CPlugFileGpuBuilder *)0x880f37;
          CFastString::CFastString
                    ((CFastString *)&puStack_168,(CFastString *)"GbxVReflectToTex",
                     (char *)in_stack_fffffdf4);
          pCVar24 = CFastString::operator<<
                              (this_07,(CPlugFileGpuBuilder *)&iStack_1cc,in_stack_fffffdf8);
          uStack_118 = *(undefined4 *)(pCVar24 + 4);
          uStack_114 = *(undefined4 *)pCVar24;
          CFastString::SetString
                    ((CFastString *)&stack0xfffffe1c,(CFastStringInt *)&uStack_118,
                     (SStringParam *)in_stack_fffffdfc);
          if (puStack_158 != PTR_DAT_00bbf7d8) {
            puVar16 = puStack_158 + -1;
            if ((puStack_158[-1] & 0x80) != 0) {
              puVar16 = puStack_158 + -4;
            }
            operator_delete__(puVar16);
            uStack_15c = 0;
            puStack_158 = PTR_DAT_00bbf7d8;
          }
          in_stack_fffffdf8 = &DAT_00000005;
          in_stack_fffffdf4 = (CPlugFileGpuBuilder *)0x0;
          in_stack_fffffdf0 = (char *)0x880fc9;
          CPlugFileGpuBuilder::AddInOut(aCStack_10c,(CPlugFileGpuBuilder *)0x0,5,0,(char *)pCVar37);
          in_stack_fffffdfc = (CPlugFileGpuBuilder *)0x880fd7;
          in_stack_fffffe04 =
               CFastString::operator<<
                         (aCStack_1c8,(CPlugFileGpuBuilder *)&stack0xfffffe24,
                          (char *)in_stack_fffffe04);
          uStack_100 = 4;
          pCVar37 = (CPlugFileGpuBuilder *)0x880fef;
          CPlugFileGpuBuilder::AddStr
                    ((CPlugFileGpuBuilder *)&uStack_104,in_stack_fffffe04,(CFastString *)pCVar39);
          if (in_stack_fffffe20 == (CPlugFileGpuBuilder *)0x0) {
            in_stack_fffffe20 = (CPlugFileGpuBuilder *)0x1;
            in_stack_fffffe04 = (CPlugFileGpuBuilder *)0x881012;
            CFastString::CFastString
                      ((CFastString *)&puStack_174,
                       (CFastString *)
                       "float4 TcReflect = float4(normalize(reflect(v.Position - GbxEyeInVisual, v.Normal)),1)"
                       ,(char *)in_stack_fffffe0c);
            in_stack_fffffe0c = (CPlugFileGpuBuilder *)&uStack_170;
            uStack_f8 = 5;
            pCVar39 = (CPlugFileGpuBuilder *)0x881035;
            CPlugFileGpuBuilder::AddStr
                      (aCStack_fc,in_stack_fffffe0c,(CFastString *)in_stack_fffffe10);
            if (puStack_168 != PTR_DAT_00bbf7d8) {
              in_stack_fffffe10 = (CPlugFileGpuBuilder *)(puStack_168 + -1);
              if ((puStack_168[-1] & 0x80) != 0) {
                in_stack_fffffe10 = (CPlugFileGpuBuilder *)(puStack_168 + -4);
              }
              in_stack_fffffe0c = (CPlugFileGpuBuilder *)0x88105e;
              operator_delete__(in_stack_fffffe10);
              uStack_16c = 0;
              puStack_168 = PTR_DAT_00bbf7d8;
            }
          }
          CFastString::CFastString((CFastString *)&stack0xfffffdd8,(CFastString *)"Output.",pcVar32)
          ;
          pcVar28 = ")";
          pCVar24 = (CPlugFileGpuBuilder *)&stack0xfffffde4;
          pCVar15 = CFastString::operator<<
                              (this_08,(CPlugFileGpuBuilder *)&stack0xfffffe08," = mul(TcReflect, ")
          ;
          pCVar24 = CFastString::operator<<((CFastString *)pCVar15,pCVar24,pcVar28);
          pcVar32 = (char *)0x8810b4;
          pCVar33 = CFastString::operator<<((CFastString *)pCVar24,pCVar33,(char *)pCVar34);
          pCVar33 = CFastString::operator<<((CFastString *)pCVar33,pCVar36,pcVar25);
          uStack_134 = 5;
          CPlugFileGpuBuilder::operator<<
                    ((CPlugFileGpuBuilder *)&puStack_138,*(CPlugFileGpuBuilder **)(pCVar33 + 4),
                     pcVar27);
          in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,0x21);
          if (in_stack_fffffdf4 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
            pCVar33 = in_stack_fffffdf4 + -1;
            if (((byte)in_stack_fffffdf4[-1] & 0x80) != 0) {
              pCVar33 = in_stack_fffffdf4 + -4;
            }
            operator_delete__(pCVar33);
            in_stack_fffffdf0 = (char *)0x0;
            in_stack_fffffdf4 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
          }
        }
        pCVar34 = (CFastString *)0x1;
        pCVar33 = (CPlugFileGpuBuilder *)0x88112b;
        CPlugFileGpuBuilder::AddInOut
                  ((CPlugFileGpuBuilder *)&uStack_134,(CPlugFileGpuBuilder *)0x1,(EInOut)pCVar37,
                   (pCVar39 != (CPlugFileGpuBuilder *)0x0) + 1,(char *)0x0);
        if (in_stack_fffffe10 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar24 = in_stack_fffffe10 + -1;
          if (((byte)in_stack_fffffe10[-1] & 0x80) != 0) {
            pCVar24 = in_stack_fffffe10 + -4;
          }
          operator_delete__(pCVar24);
          in_stack_fffffe0c = (CPlugFileGpuBuilder *)0x0;
          in_stack_fffffe10 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
        }
        if (in_stack_fffffdfc != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar24 = in_stack_fffffdfc + -1;
          if (((byte)in_stack_fffffdfc[-1] & 0x80) != 0) {
            pCVar24 = in_stack_fffffdfc + -4;
          }
          operator_delete__(pCVar24);
          in_stack_fffffdf8 = (char *)0x0;
          in_stack_fffffdfc = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
        }
        if (in_stack_fffffe18 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar24 = in_stack_fffffe18 + -1;
          if (((byte)in_stack_fffffe18[-1] & 0x80) != 0) {
            pCVar24 = in_stack_fffffe18 + -4;
          }
          operator_delete__(pCVar24);
          in_stack_fffffe14 = (CPlugFileGpuBuilder *)0x0;
          in_stack_fffffe18 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
        }
        if (in_stack_fffffe20 != (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8) {
          pCVar24 = in_stack_fffffe20 + -1;
          if (((byte)in_stack_fffffe20[-1] & 0x80) != 0) {
            pCVar24 = in_stack_fffffe20 + -4;
          }
          operator_delete__(pCVar24);
          in_stack_fffffe1c = (CPlugFileGpuBuilder *)0x0;
          in_stack_fffffe20 = (CPlugFileGpuBuilder *)PTR_DAT_00bbf7d8;
        }
        in_stack_00000088 = (void *)CONCAT31(in_stack_00000088._1_3_,2);
        if (puStack_1d8 != PTR_DAT_00bbf7d8) {
          puVar16 = puStack_1d8 + -1;
          if ((puStack_1d8[-1] & 0x80) != 0) {
            puVar16 = puStack_1d8 + -4;
          }
          operator_delete__(puVar16);
          in_stack_fffffe24 = (char *)0x0;
          puStack_1d8 = PTR_DAT_00bbf7d8;
        }
      }
      pCVar24 = pCVar37 + 1;
    } while (pCVar24 < in_stack_fffffe04);
  }
  CPlugFileGpuBuilder::Build
            ((CPlugFileGpuBuilder *)&uStack_134,in_stack_fffffdd8,
             (vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> *)in_stack_fffffddc
             ,(vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *)
              in_stack_fffffde0);
  pCVar33 = (CPlugFileGpuBuilder *)0x1;
  (**(code **)(**(int **)(aiStack_17c[0] + 0x24) + 0xa4))();
  pCVar12 = *(CPlugFileVHlsl **)(aiStack_17c[0] + 0x24);
  CPlugFileGpuBuilder::~CPlugFileGpuBuilder(aCStack_130,pCVar33);
  if (puStack_148 != PTR_DAT_00bbf7d8) {
    puVar16 = puStack_148 + -1;
    if ((puStack_148[-1] & 0x80) != 0) {
      puVar16 = puStack_148 + -4;
    }
    operator_delete__(puVar16);
  }
  ExceptionList = in_stack_00000088;
  return pCVar12;
}
}

// =================================================
// Function: CPlugFileVHlsl::LoadCommonVHlsl
// =================================================
void __cdecl CPlugFileVHlsl::LoadCommonVHlsl(void)
{
{
  CMwNod *pCVar1;
  CMwNod *unaff_ESI;
  CMwNod *this;
  CMwNod *pCVar2;
  
  CSystemArchiveNod::LoadResource(0x40000021,(CMwNod **)&stack0xfffffffc);
  pCVar1 = DAT_00d6f024;
  if (this != DAT_00d6f024) {
    pCVar2 = this;
    if (this != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this,unaff_ESI);
    }
    pCVar1 = this;
    if (DAT_00d6f024 != (CMwNod *)0x0) {
      CMwNod::MwRelease(DAT_00d6f024,pCVar2);
      pCVar1 = this;
    }
  }
  DAT_00d6f024 = pCVar1;
  return;
}
}

