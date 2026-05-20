// Class implementation: CPlugFilePHlsl

// =================================================
// Function: CPlugFilePHlsl::ApplyFidParameter_Crypted
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPlugFilePHlsl::ApplyFidParameter_Crypted
          (CPlugFilePHlsl *this,CPlugFilePHlsl *param_1,SParam_Id *param_2)
{
{
  uint uVar1;
  CPlugFilePHlsl *this_00;
  SParam_Id *pSVar2;
  char *pcVar3;
  CPlugFileGPU *pCVar4;
  int iVar5;
  int iVar6;
  CPlugFileGpuBuilder *pCVar7;
  undefined *puVar8;
  CFastStringInt *pCVar9;
  CFastString *pCVar10;
  CPlugFileGpuBuilder *pCVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  CPlugFileGpuBuilder *pCVar14;
  GxTexCoordSet *unaff_EBX;
  CPlugFileGpuBuilder *pCVar15;
  GxTexCoordSet *unaff_ESI;
  CPlugFilePHlsl *pCVar16;
  CPlugFileGpuBuilder *pCVar17;
  CFastString *unaff_EDI;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined1 uStack00000018;
  undefined1 uStack0000001c;
  void *in_stack_00000024;
  undefined4 in_stack_0000002c;
  SStringParam *in_stack_fffffefc;
  CPlugFileGpuBuilder *in_stack_ffffff00;
  char *in_stack_ffffff04;
  char *in_stack_ffffff08;
  char *in_stack_ffffff0c;
  char *in_stack_ffffff10;
  char *pcVar18;
  char *in_stack_ffffff14;
  char *in_stack_ffffff18;
  char *pcVar19;
  char *in_stack_ffffff1c;
  CPlugFileGpuBuilder *in_stack_ffffff20;
  CPlugFileGpuBuilder *pCVar20;
  char *in_stack_ffffff24;
  CPlugFileGpuBuilder *in_stack_ffffff28;
  char *in_stack_ffffff2c;
  CPlugFileGpuBuilder *in_stack_ffffff30;
  char *in_stack_ffffff34;
  char *pcVar21;
  CPlugFileGpuBuilder *in_stack_ffffff38;
  char *in_stack_ffffff3c;
  char *in_stack_ffffff40;
  CPlugFileGpuBuilder *in_stack_ffffff44;
  CPlugFileGpuBuilder *pCVar22;
  char *in_stack_ffffff48;
  CPlugFileGpuBuilder *in_stack_ffffff4c;
  char *in_stack_ffffff50;
  CPlugFileGpuBuilder *in_stack_ffffff54;
  char *in_stack_ffffff58;
  CPlugFileGpuBuilder *in_stack_ffffff5c;
  char *in_stack_ffffff60;
  char *pcVar23;
  char *pcVar24;
  CPlugFileGpuBuilder *in_stack_ffffff64;
  CPlugFileGpuBuilder *pCVar25;
  char *in_stack_ffffff68;
  CPlugFileGpuBuilder *in_stack_ffffff6c;
  CPlugFileGpuBuilder *in_stack_ffffff70;
  char *in_stack_ffffff74;
  CPlugFileGpuBuilder *in_stack_ffffff78;
  char *in_stack_ffffff7c;
  CPlugFileGpuBuilder *in_stack_ffffff80;
  CFastString *in_stack_ffffff84;
  char *in_stack_ffffff88;
  CFastString *pCVar26;
  int iVar27;
  CFastString *pCVar28;
  ulong uVar29;
  char *pcVar30;
  CFastString *in_stack_ffffffa4;
  CFastString *in_stack_ffffffa8;
  GxTexCoordSet *in_stack_ffffffac;
  CFastString *in_stack_ffffffb0;
  SHeaderCommunity *in_stack_ffffffb4;
  CFastString *in_stack_ffffffb8;
  SHeaderCommunity *in_stack_ffffffbc;
  char *in_stack_ffffffc0;
  int in_stack_ffffffc4;
  SHeaderCommunity *in_stack_ffffffc8;
  CFastStringInt *in_stack_ffffffcc;
  undefined4 local_30;
  undefined *local_2c;
  int local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  CFastString local_18 [4];
  undefined *local_14;
  undefined1 *local_10;
  undefined *local_c;
  undefined4 local_8;
  
  pSVar2 = param_2;
  local_c = (undefined *)0xffffffff;
  local_10 = &LAB_00ada100;
  local_14 = ExceptionList;
  pcVar3 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffff98);
  ExceptionList = &local_14;
  iVar5 = *(int *)(param_2 + 0x10);
  if (iVar5 == DAT_00d6ece0) {
    pCVar15 = (CPlugFileGpuBuilder *)(*(uint *)(param_2 + 0x14) & 0xff);
    if ((CPlugFileGpuBuilder *)0x3 < pCVar15) {
      pCVar15 = (CPlugFileGpuBuilder *)0x3;
    }
    pCVar4 = (CPlugFileGPU *)(*(uint *)(param_2 + 0x14) >> 8 & 1);
    CFastString::CFastString((CFastString *)&local_30,(CFastString *)&DAT_00b30a78,pcVar3);
    pCVar26 = (CFastString *)&DAT_00d6f854;
    local_8 = 0;
    pcVar3 = (char *)0x8a3a40;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f854,(CMwId *)&local_2c,unaff_EDI);
    if (local_24 != PTR_DAT_00bbf7d8) {
      puVar12 = local_24 + -1;
      if ((local_24[-1] & 0x80) != 0) {
        puVar12 = local_24 + -4;
      }
      operator_delete__(puVar12);
    }
    pCVar16 = param_1 + 0x88;
    iVar27 = 0x8a3a7e;
    iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar16,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f84c,unaff_ESI);
    pCVar28 = (CFastString *)0x8a3a94;
    iVar6 = CFastArray<class_CGameMenuFrame*>::Find
                      (pCVar16,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f864,unaff_EBX);
    iVar5 = (uint)(iVar5 == -1) * 8 + 8;
    if (iVar6 == -1) {
      CFastString::CFastString
                (local_18,(CFastString *)
                          "\\\r\n\tsampler2D MapGbxShadow0;\\\r\n\tuniform const float4x2 GbxSamplerBilinearCorners_GbxShadow0;\\\r\n\tuniform const float4   GbxSampler_W_H_0x5_1_GbxShadow0;\\\r\n\tstatic  const fpart4   GbxShadowInShaderRgb1 = 0.15f;\\\r\n\tuniform const fpart4   GbxAmbientOccMidGray;"
                 ,(char *)in_stack_ffffffa4);
      pCVar16 = param_1;
      pcVar30 = (char *)(&DAT_00d6f828 + in_stack_ffffffc4);
      param_2 = (SParam_Id *)&DAT_00000004;
      uVar29 = 0x8a3d43;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)param_1,(CPlugFileGPU *)pcVar30,(CMwId *)&local_14,
                 (CFastString *)pCVar4);
      in_stack_0000000c = 0xffffffff;
      if (local_c != PTR_DAT_00bbf7d8) {
        puVar12 = local_c + -1;
        if ((local_c[-1] & 0x80) != 0) {
          puVar12 = local_c + -4;
        }
        operator_delete__(puVar12);
      }
      if (iVar5 == 0) {
        CFastString::CFastString
                  ((CFastString *)&local_10,
                   (CFastString *)
                   "\\\r\n\tfpart  ShadowSpecular = SoftShadow(MapGbxShadow0, v.TcShadowBuffer, GbxSamplerBilinearCorners_GbxShadow0, GbxSampler_W_H_0x5_1_GbxShadow0);\\\r\n\tfpart4 ShadowDiffus = saturate(GbxShadowInShaderRgb1+(1-GbxShadowInShaderRgb1)*ShadowSpecular);\\\r\n\tfpart  VDepAmbOcc = 1;"
                   ,(char *)in_stack_ffffffac);
        in_stack_00000010 = 6;
      }
      else {
        CFastString::CFastString
                  ((CFastString *)&local_10,
                   (CFastString *)
                   "\\\r\n\tfpart4 ShadowBuffer = tex2Dproj(MapGbxShadow0, v.TcShadowBuffer);\\\r\n\tfpart  ShadowSpecular = ShadowBuffer.x;\\\r\n\tfpart4 ShadowDiffus = saturate(GbxShadowInShaderRgb1+(1-GbxShadowInShaderRgb1)*ShadowSpecular);\\\r\n\tfpart4 VDepAmbOcc = lerp(saturate(ShadowBuffer.a*2-1), saturate(ShadowBuffer.a*2), GbxAmbientOccMidGray);"
                   ,(char *)in_stack_ffffffac);
        in_stack_00000010 = 5;
      }
      pCVar4 = (CPlugFileGPU *)(&DAT_00d6f828 + (int)local_2c);
      in_stack_ffffffa4 = (CFastString *)0x8a3db4;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)pCVar16,pCVar4,(CMwId *)&local_c,in_stack_ffffffb0);
      in_stack_00000014 = 0xffffffff;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_8,in_stack_ffffffb4);
    }
    else {
      pCVar17 = (CPlugFileGpuBuilder *)0x0;
      local_20 = 0;
      local_1c = PTR_DAT_00bbf7d8;
      local_30 = 0;
      local_2c = PTR_DAT_00bbf7d8;
      pcVar30 = 
      "\\\r\n\tfpart3 ShadowDiffs[3] = {fpart3(1,1,1),fpart3(1,1,1),fpart3(1,1,1)};\\\r\n\tfpart  ShadowSpecs[3] = {1,1,1};"
      ;
      param_1 = (CPlugFilePHlsl *)0x3;
      uVar29 = 0x8a3b04;
      puVar12 = PTR_DAT_00bbf7d8;
      CFastString::operator<<
                ((CFastString *)&local_30,
                 (CPlugFileGpuBuilder *)
                 "\\\r\n\tfpart3 ShadowDiffs[3] = {fpart3(1,1,1),fpart3(1,1,1),fpart3(1,1,1)};\\\r\n\tfpart  ShadowSpecs[3] = {1,1,1};"
                 ,(char *)in_stack_ffffffa4);
      if (pCVar15 != (CPlugFileGpuBuilder *)0x0) {
        do {
          pcVar23 = "GbxShadow";
          pCVar25 = (CPlugFileGpuBuilder *)&DAT_00000009;
          CFastString::SetString
                    ((CFastString *)&stack0xffffff30,(CFastStringInt *)&stack0xffffff60,
                     (SStringParam *)in_stack_ffffff1c);
          CFastString::operator<<((CFastString *)&stack0xffffff34,pCVar17,(char *)in_stack_ffffff20)
          ;
          pCVar20 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
          pcVar24 = &stack0xffffff38;
          pcVar19 = ";\\\r\n\tfloat4   GbxSampler_W_H_0x5_1_";
          pcVar18 = ";\\\r\n\tfloat4x2 GbxSamplerBilinearCorners_";
          pcVar21 = pcVar24;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)&stack0xffffff60,
                              (CPlugFileGpuBuilder *)"\\\r\n\tsampler2D Map",pcVar24);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar18,pcVar24);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)pcVar19,pcVar21);
          pCVar7 = CFastString::operator<<((CFastString *)pCVar7,pCVar20,in_stack_ffffff24);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff28,in_stack_ffffff2c);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff30,in_stack_ffffff34);
          CFastString::operator<<((CFastString *)pCVar7,in_stack_ffffff38,in_stack_ffffff3c);
          in_stack_ffffff3c = &DAT_00bb1468;
          pcVar24 = &stack0xffffff54;
          in_stack_ffffff34 = ", GbxSampler_W_H_0x5_1_";
          in_stack_ffffff2c = ", GbxSamplerBilinearCorners_";
          in_stack_ffffff24 = ", v.Tc";
          in_stack_ffffff1c = "] = SoftShadow(Map";
          pcVar21 = pcVar24;
          pcVar18 = pcVar24;
          pcVar19 = pcVar24;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)&stack0xffffff6c,
                              (CPlugFileGpuBuilder *)"\\\r\n\tShadowSpecs[",(char *)pCVar17);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff1c,pcVar24
                             );
          in_stack_ffffff20 = (CPlugFileGpuBuilder *)0x8a3bc9;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff24,pcVar21
                             );
          in_stack_ffffff28 = (CPlugFileGpuBuilder *)0x8a3bd0;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff2c,pcVar18
                             );
          in_stack_ffffff30 = (CPlugFileGpuBuilder *)0x8a3bd7;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff34,pcVar19
                             );
          in_stack_ffffff38 = (CPlugFileGpuBuilder *)0x8a3bde;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff3c,
                              in_stack_ffffff40);
          in_stack_ffffff40 = (char *)0x8a3be5;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff44,in_stack_ffffff48);
          in_stack_ffffff48 = (char *)0x8a3bec;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff4c,in_stack_ffffff50);
          in_stack_ffffff50 = (char *)0x8a3bf3;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff54,in_stack_ffffff58);
          pCVar7 = CFastString::operator<<((CFastString *)pCVar7,in_stack_ffffff5c,pcVar23);
          CFastString::operator<<((CFastString *)pCVar7,pCVar25,in_stack_ffffff68);
          in_stack_ffffff68 = &DAT_00bb773c;
          pcVar24 = "] = saturate(GbxShadowInShaderRgb1+(1-GbxShadowInShaderRgb1)*ShadowSpecs[";
          in_stack_ffffff58 = "\\\r\n\tShadowDiffs[";
          in_stack_ffffff54 = (CPlugFileGpuBuilder *)0x8a3c1b;
          pCVar7 = pCVar17;
          pCVar20 = CFastString::operator<<
                              ((CFastString *)&stack0xffffff98,
                               (CPlugFileGpuBuilder *)"\\\r\n\tShadowDiffs[",(char *)pCVar17);
          in_stack_ffffff5c = (CPlugFileGpuBuilder *)0x8a3c22;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar20,(CPlugFileGpuBuilder *)pcVar24,(char *)pCVar7);
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,(CPlugFileGpuBuilder *)in_stack_ffffff68,
                              (char *)in_stack_ffffff6c);
          in_stack_ffffff6c = (CPlugFileGpuBuilder *)0x8a3c30;
          pCVar7 = CFastString::operator<<
                             ((CFastString *)pCVar7,in_stack_ffffff70,in_stack_ffffff74);
          in_stack_ffffff74 = (char *)0x8a3c37;
          CFastString::operator<<((CFastString *)pCVar7,in_stack_ffffff78,in_stack_ffffff7c);
          pCVar17 = pCVar17 + 1;
        } while (pCVar17 < pCVar15);
      }
      CFastString::operator<<
                ((CFastString *)&stack0xffffffbc,
                 (CPlugFileGpuBuilder *)"\\\r\n\tuniform const fpart3 GbxShadowInShaderRgb1;",
                 (char *)in_stack_ffffff80);
      pCVar16 = param_1;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)param_1,(CPlugFileGPU *)(&DAT_00d6f828 + (int)pcVar30),
                 (CMwId *)&stack0xffffffc0,in_stack_ffffff84);
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)(&DAT_00d6f828 + (int)in_stack_ffffffac),
                 (CMwId *)&stack0xffffffb4,(CFastString *)in_stack_ffffff88);
      if (in_stack_ffffffa4 != (CFastString *)PTR_DAT_00bbf7d8) {
        pCVar10 = in_stack_ffffffa4 + -1;
        if (((byte)in_stack_ffffffa4[-1] & 0x80) != 0) {
          pCVar10 = in_stack_ffffffa4 + -4;
        }
        operator_delete__(pCVar10);
        pcVar30 = (char *)0x0;
        in_stack_ffffffa4 = (CFastString *)PTR_DAT_00bbf7d8;
      }
      if (puVar12 != PTR_DAT_00bbf7d8) {
        puVar8 = puVar12 + -1;
        if ((puVar12[-1] & 0x80) != 0) {
          puVar8 = puVar12 + -4;
        }
        operator_delete__(puVar8);
      }
      local_14 = (undefined *)0xffffffff;
      if (in_stack_ffffffcc != (CFastStringInt *)PTR_DAT_00bbf7d8) {
        pCVar9 = in_stack_ffffffcc + -1;
        if (((byte)in_stack_ffffffcc[-1] & 0x80) != 0) {
          pCVar9 = in_stack_ffffffcc + -4;
        }
        operator_delete__(pCVar9);
      }
    }
    pCVar10 = (CFastString *)&DAT_00b30a78;
    if (DAT_00d173f4 != 1) {
      pCVar10 = (CFastString *)&DAT_00b2efac;
    }
    CFastString::CFastString((CFastString *)&local_30,pCVar10,pcVar3);
    pCVar16 = param_1;
    local_10 = (undefined1 *)0x7;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f858,(CMwId *)&local_2c,pCVar26);
    if (local_24 != PTR_DAT_00bbf7d8) {
      puVar12 = local_24 + -1;
      if ((local_24[-1] & 0x80) != 0) {
        puVar12 = local_24 + -4;
      }
      operator_delete__(puVar12);
    }
    local_c = &DAT_00000008;
    CFastString::SetNatural
              ((CFastString *)&stack0xffffffc8,
               (CFastString *)((DAT_00d173f4 != 3) - 1 & _DAT_00d173f8),0,0,0,0,1,iVar27);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f850,(CMwId *)&stack0xffffffcc,
               pCVar28);
    CFastString::SetReal((CFastString *)&local_30,_DAT_00d173fc,4.2039e-45,uVar29);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f860,(CMwId *)&local_2c,
               (CFastString *)pcVar30);
    pCVar26 = (CFastString *)&DAT_00b30a78;
    if (DAT_00d173f4 != 2) {
      pCVar26 = (CFastString *)&DAT_00b2efac;
    }
    CFastString::CFastString(local_18,pCVar26,(char *)in_stack_ffffffa4);
    param_2 = (SParam_Id *)CONCAT31(param_2._1_3_,9);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f85c,(CMwId *)&local_14,
               (CFastString *)pCVar4);
    if (local_c != PTR_DAT_00bbf7d8) {
      puVar13 = local_c + -1;
      if ((local_c[-1] & 0x80) != 0) {
        puVar13 = local_c + -4;
      }
      operator_delete__(puVar13);
    }
    if (local_1c != PTR_DAT_00bbf7d8) {
      puVar12 = local_1c + -1;
      if ((local_1c[-1] & 0x80) != 0) {
        puVar12 = local_1c + -4;
      }
      operator_delete__(puVar12);
      ExceptionList = param_1;
      return;
    }
  }
  else if (iVar5 == DAT_00d6ece4) {
    CFastString::CFastString((CFastString *)&local_28,(CFastString *)&DAT_00b30a78,pcVar3);
    pCVar16 = param_1;
    pCVar17 = (CPlugFileGpuBuilder *)&DAT_00d6f874;
    local_8 = 10;
    pCVar15 = (CPlugFileGpuBuilder *)0x8a3f56;
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f874,(CMwId *)&local_24,unaff_EDI);
    if (local_1c != PTR_DAT_00bbf7d8) {
      puVar12 = local_1c + -1;
      if ((local_1c[-1] & 0x80) != 0) {
        puVar12 = local_1c + -4;
      }
      operator_delete__(puVar12);
    }
    pCVar7 = (CPlugFileGpuBuilder *)(uint)(byte)pSVar2[0x14];
    if ((CPlugFileGpuBuilder *)0x3 < pCVar7) {
      pCVar7 = (CPlugFileGpuBuilder *)0x3;
    }
    pCVar20 = (CPlugFileGpuBuilder *)0x0;
    local_28 = 0;
    local_24 = PTR_DAT_00bbf7d8;
    pcVar3 = (char *)0x8a3fc8;
    puVar12 = PTR_DAT_00bbf7d8;
    CFastString::operator<<
              ((CFastString *)&stack0xffffffc8,
               (CPlugFileGpuBuilder *)"\\\r\n\tsampler2D MapGbxShadowSlopeZ;",(char *)unaff_ESI);
    pcVar30 = "\\\r\n\tfpart3 ShadowDiffus = 1;\\\r\n\tfpart3 ShadowSpecular = 1;";
    pCVar25 = (CPlugFileGpuBuilder *)0x8a3fd6;
    CFastString::operator<<
              ((CFastString *)&stack0xffffffc4,
               (CPlugFileGpuBuilder *)
               "\\\r\n\tfpart3 ShadowDiffus = 1;\\\r\n\tfpart3 ShadowSpecular = 1;",
               (char *)unaff_EBX);
    if (pCVar7 != (CPlugFileGpuBuilder *)0x0) {
      do {
        pcVar18 = "GbxShadowMask";
        pCVar22 = (CPlugFileGpuBuilder *)&DAT_0000000d;
        CFastString::SetString
                  ((CFastString *)&stack0xffffff18,(CFastStringInt *)&stack0xffffff40,
                   in_stack_fffffefc);
        CFastString::operator<<((CFastString *)&stack0xffffff1c,pCVar20,(char *)in_stack_ffffff00);
        in_stack_ffffff00 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        pCVar14 = pCVar20 + *(int *)(pCVar16 + 200);
        pcVar24 = " : TEXCOORD";
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff40,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfloat4 Tc",&stack0xffffff20);
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pcVar24,(char *)pCVar14);
        in_stack_fffffefc = (SStringParam *)0x8a403c;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff00,in_stack_ffffff04);
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)in_stack_ffffff08,
                             in_stack_ffffff0c);
        CFastString::operator<<
                  ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)in_stack_ffffff10,in_stack_ffffff14
                  );
        pCVar14 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff44,
                             (CPlugFileGpuBuilder *)"\\\r\n\tsampler2D Map",&stack0xffffff34);
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar14,in_stack_ffffff18);
        CFastString::operator<<
                  ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)in_stack_ffffff1c,
                   (char *)in_stack_ffffff20);
        in_stack_ffffff20 = (CPlugFileGpuBuilder *)&DAT_00bb1468;
        pcVar24 = &stack0xffffff40;
        in_stack_ffffff18 = ", v.Tc";
        in_stack_ffffff10 = " = tex2D(Map";
        in_stack_ffffff08 = "\\\r\n\tfpart3 ShadowMask";
        in_stack_ffffff04 = (char *)0x8a4096;
        pcVar21 = pcVar24;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff48,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfpart3 ShadowMask",(char *)pCVar20);
        in_stack_ffffff0c = (char *)0x8a409d;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)in_stack_ffffff10,pcVar24
                            );
        in_stack_ffffff14 = (char *)0x8a40a4;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)in_stack_ffffff18,pcVar21
                            );
        in_stack_ffffff1c = (char *)0x8a40ab;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff20,in_stack_ffffff24);
        in_stack_ffffff24 = (char *)0x8a40b2;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff28,in_stack_ffffff2c);
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff30,in_stack_ffffff34);
        CFastString::operator<<((CFastString *)pCVar11,in_stack_ffffff38,in_stack_ffffff3c);
        pCVar14 = (CPlugFileGpuBuilder *)&DAT_00bb729c;
        pcVar24 = &stack0xffffff5c;
        pcVar21 = " = tex2D(MapGbxShadowSlopeZ, v.Tc";
        in_stack_ffffff2c = "\\\r\n\tfpart3 ShadowSlop";
        in_stack_ffffff28 = (CPlugFileGpuBuilder *)0x8a40de;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff64,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfpart3 ShadowSlop",(char *)pCVar20);
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pcVar21,pcVar24);
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar14,pcVar18);
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar22,in_stack_ffffff48);
        CFastString::operator<<((CFastString *)pCVar11,in_stack_ffffff4c,in_stack_ffffff50);
        pcVar21 = ");";
        pcVar24 = "ShadowSlop";
        pCVar22 = (CPlugFileGpuBuilder *)&DAT_00bb7250;
        in_stack_ffffff3c = " = saturate(ShadowMask";
        in_stack_ffffff34 = "\\\r\n\tfpart3 ShadowSpec";
        in_stack_ffffff30 = (CPlugFileGpuBuilder *)0x8a411f;
        pCVar11 = pCVar20;
        in_stack_ffffff4c = pCVar20;
        pCVar14 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff78,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfpart3 ShadowSpec",(char *)pCVar20);
        in_stack_ffffff38 = (CPlugFileGpuBuilder *)0x8a4126;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar14,(CPlugFileGpuBuilder *)in_stack_ffffff3c,
                             (char *)pCVar11);
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar22,pcVar24);
        in_stack_ffffff48 = (char *)0x8a4134;
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,in_stack_ffffff4c,pcVar21);
        in_stack_ffffff50 = (char *)0x8a413b;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff54,in_stack_ffffff58);
        in_stack_ffffff58 = (char *)0x8a4142;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff5c,in_stack_ffffff60);
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff64,in_stack_ffffff68);
        CFastString::operator<<((CFastString *)pCVar11,in_stack_ffffff6c,(char *)in_stack_ffffff70);
        in_stack_ffffff70 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        in_stack_ffffff68 = " = ShadowSpec";
        in_stack_ffffff60 = "\\\r\n\tfpart3 ShadowDiff";
        in_stack_ffffff5c = (CPlugFileGpuBuilder *)0x8a416a;
        pCVar11 = pCVar20;
        pCVar14 = CFastString::operator<<
                            ((CFastString *)&stack0xffffff98,
                             (CPlugFileGpuBuilder *)"\\\r\n\tfpart3 ShadowDiff",(char *)pCVar20);
        in_stack_ffffff64 = (CPlugFileGpuBuilder *)0x8a4171;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar14,(CPlugFileGpuBuilder *)in_stack_ffffff68,
                             (char *)pCVar11);
        in_stack_ffffff6c = (CPlugFileGpuBuilder *)0x8a4178;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff70,in_stack_ffffff74);
        in_stack_ffffff74 = (char *)0x8a417f;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)pCVar11,in_stack_ffffff78,in_stack_ffffff7c);
        CFastString::operator<<((CFastString *)pCVar11,in_stack_ffffff80,(char *)in_stack_ffffff84);
        pCVar14 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        in_stack_ffffff7c = "\\\r\n\tShadowDiffus *= ShadowDiff";
        in_stack_ffffff78 = (CPlugFileGpuBuilder *)0x8a419a;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffffac,
                             (CPlugFileGpuBuilder *)"\\\r\n\tShadowDiffus *= ShadowDiff",
                             (char *)pCVar20);
        in_stack_ffffff80 = (CPlugFileGpuBuilder *)0x8a41a1;
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar14,in_stack_ffffff88);
        CFastString::operator<<((CFastString *)pCVar11,pCVar15,(char *)pCVar17);
        pCVar17 = (CPlugFileGpuBuilder *)&DAT_00b2c994;
        in_stack_ffffff88 = "\\\r\n\tShadowSpecular*=ShadowSpec";
        in_stack_ffffff84 = (CFastString *)0x8a41bc;
        pCVar11 = CFastString::operator<<
                            ((CFastString *)&stack0xffffffb8,
                             (CPlugFileGpuBuilder *)"\\\r\n\tShadowSpecular*=ShadowSpec",
                             (char *)pCVar20);
        pCVar15 = (CPlugFileGpuBuilder *)0x8a41c3;
        pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar17,pcVar3);
        pcVar3 = (char *)0x8a41ca;
        CFastString::operator<<((CFastString *)pCVar11,pCVar25,pcVar30);
        pCVar20 = pCVar20 + 1;
      } while (pCVar20 < pCVar7);
    }
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f878,(CMwId *)&local_24,
               (CFastString *)unaff_EBX);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f87c,(CMwId *)&local_30,
               in_stack_ffffffa4);
    CPlugFileGPU::DefineAddOrSet
              ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f880,(CMwId *)&stack0xffffffcc,
               in_stack_ffffffa8);
    if (puVar12 != PTR_DAT_00bbf7d8) {
      puVar8 = puVar12 + -1;
      if ((puVar12[-1] & 0x80) != 0) {
        puVar8 = puVar12 + -4;
      }
      operator_delete__(puVar8);
    }
    if (local_2c != PTR_DAT_00bbf7d8) {
      puVar12 = local_2c + -1;
      if ((local_2c[-1] & 0x80) != 0) {
        puVar12 = local_2c + -4;
      }
      operator_delete__(puVar12);
      local_30 = 0;
      local_2c = PTR_DAT_00bbf7d8;
    }
    if (local_24 != PTR_DAT_00bbf7d8) {
      puVar12 = local_24 + -1;
      if ((local_24[-1] & 0x80) != 0) {
        puVar12 = local_24 + -4;
      }
      operator_delete__(puVar12);
      local_28 = 0;
      local_24 = PTR_DAT_00bbf7d8;
    }
    if (local_14 != PTR_DAT_00bbf7d8) {
      puVar12 = local_14 + -1;
      if ((local_14[-1] & 0x80) != 0) {
        puVar12 = local_14 + -4;
      }
      operator_delete__(puVar12);
      ExceptionList = param_1;
      return;
    }
  }
  else {
    if (iVar5 == DAT_00d6ecf0) {
      uVar1 = *(uint *)(param_2 + 0x14);
      CFastString::CFastString((CFastString *)&local_28,(CFastString *)&DAT_00b30a78,pcVar3);
      this_00 = param_1;
      local_8 = 0xf;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f884,(CMwId *)&local_24,unaff_EDI)
      ;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&local_20,(SHeaderCommunity *)unaff_ESI);
      pCVar26 = (CFastString *)0x3;
      CMwId::CMwId(&stack0xffffffbc,(CMwId *)unaff_EBX);
      param_1 = (CPlugFilePHlsl *)0x10;
      CMwId::CMwId(&stack0xffffffb8,(CMwId *)in_stack_ffffffa4);
      pCVar16 = this_00 + 0x88;
      param_2 = (SParam_Id *)CONCAT31(param_2._1_3_,0x11);
      iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                        (pCVar16,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f88c,
                         (GxTexCoordSet *)in_stack_ffffffa8);
      if (iVar5 == -1) {
        iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                          (pCVar16,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f894,
                           in_stack_ffffffac);
        if (iVar5 == -1) {
          iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                            (pCVar16,(CFastArray<class_GxTexCoordSet> *)&DAT_00d6f89c,
                             (GxTexCoordSet *)in_stack_ffffffb0);
          if (iVar5 != -1) {
            local_28 = 2;
            local_30 = DAT_00d6f898;
            in_stack_ffffffc8 = DAT_00d6f89c;
          }
        }
        else {
          local_2c = (undefined *)0x1;
          pCVar26 = DAT_00d6f894;
          in_stack_ffffffcc = DAT_00d6f890;
        }
      }
      else {
        local_30 = 0;
        in_stack_ffffffc0 = DAT_00d6f88c;
        in_stack_ffffffc8 = DAT_00d6f888;
      }
      if ((uVar1 & 0x400) == 0) {
        if (local_28 == 0) {
          CFastString::CFastString
                    ((CFastString *)&local_8,
                     (CFastString *)
                     "\\\r\n\tsampler2D MapProjector;\\\r\n\tuniform const float4 GbxProjectorPos_wInvFarZ20;\\\r\n\tuniform const fpart4 GbxProjectorRgb0;"
                     ,(char *)in_stack_ffffffb4);
          uStack00000018 = 0x14;
          CPlugFileGPU::DefineAddOrSet
                    ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_2c,(CMwId *)&stack0xfffffffc,
                     in_stack_ffffffb8);
          uStack0000001c = 0x11;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffbc)
          ;
          CFastString::CFastString
                    ((CFastString *)&param_1,
                     (CFastString *)
                     "\\\r\n\tfloat3 ProjectorEyeV = GbxProjectorPos_wInvFarZ20-v.PosInVisual;\\\r\n\tfpart3 ProjectorDir = normalize(ProjectorEyeV);\\\r\n\tfpart  ProjectorDot = dot(Normal, ProjectorDir);\\\r\n\tProjectorDot = saturate(ProjectorDot);\\\r\n\tfloat4 ProjectorTc = v.TcProjector;\\\r\n\tfpart4 ProjectorMask = tex2Dproj(MapProjector, ProjectorTc)*(ProjectorTc.w>0);\\\r\n\tfpart  ProjectorAtt = saturate(v.PosInVisual.w-GbxProjectorPos_wInvFarZ20.w*dot(ProjectorEyeV,ProjectorEyeV));\\\r\n\tfpart4 ProjectorTmp = ProjectorMask*GbxProjectorRgb0*ProjectorAtt;\\\r\n\tfpart4 ProjectorAmbient = ProjectorTmp;\\\r\n\tfpart4 ProjectorDiffus = saturate(ProjectorTmp*sqrt(ProjectorDot));\\\r\n\tfpart4 ProjectorSpecular = ProjectorTmp;"
                     ,in_stack_ffffffc0);
          in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0x15);
        }
        else if (local_28 == 1) {
          CFastString::CFastString
                    ((CFastString *)&local_8,
                     (CFastString *)
                     "\\\r\n\tsampler2D MapProjector;\\\r\n\tuniform const float4   GbxProjectorPos_wInvFarZ20;\\\r\n\tuniform const float4x3 GbxVisualPz01Projector0;\\\r\n\tuniform const fpart4   GbxProjectorRgb0;"
                     ,(char *)in_stack_ffffffb4);
          uStack00000018 = 0x16;
          CPlugFileGPU::DefineAddOrSet
                    ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_2c,(CMwId *)&stack0xfffffffc,
                     in_stack_ffffffb8);
          uStack0000001c = 0x11;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffbc)
          ;
          CFastString::CFastString
                    ((CFastString *)&param_1,
                     (CFastString *)
                     "\\\r\n\tfloat3 ProjectorEyeV = GbxProjectorPos_wInvFarZ20-v.PosInVisual;\\\r\n\tfpart3 ProjectorDir = normalize(ProjectorEyeV);\\\r\n\tfpart  ProjectorDot = dot(Normal, ProjectorDir);\\\r\n\tProjectorDot = saturate(ProjectorDot);\\\r\n\tfloat4 ProjectorTc = mul(v.PosInVisual, GbxVisualPz01Projector0).xyzz;\\\r\n\tfpart4 ProjectorMask = tex2Dproj(MapProjector, ProjectorTc)*(ProjectorTc.w>0);\\\r\n\tfpart  ProjectorAtt = saturate(v.PosInVisual.w-GbxProjectorPos_wInvFarZ20.w*dot(ProjectorEyeV,ProjectorEyeV));\\\r\n\tfpart4 ProjectorTmp = ProjectorMask*GbxProjectorRgb0*ProjectorAtt;\\\r\n\tfpart4 ProjectorAmbient = ProjectorTmp;\\\r\n\tfpart4 ProjectorDiffus = saturate(ProjectorTmp*sqrt(ProjectorDot));\\\r\n\tfpart4 ProjectorSpecular = ProjectorTmp;"
                     ,in_stack_ffffffc0);
          in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0x17);
        }
        else {
          CFastString::CFastString
                    ((CFastString *)&local_8,
                     (CFastString *)
                     "\\\r\n\tsampler2D MapProjector;\\\r\n\tuniform const float4 GbxProjectorPos_wInvFarZ20;\\\r\n\tuniform const fpart4 GbxProjectorBaseRgb0;"
                     ,(char *)in_stack_ffffffb4);
          uStack00000018 = 0x18;
          CPlugFileGPU::DefineAddOrSet
                    ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_2c,(CMwId *)&stack0xfffffffc,
                     in_stack_ffffffb8);
          uStack0000001c = 0x11;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffbc)
          ;
          CFastString::CFastString
                    ((CFastString *)&param_1,
                     (CFastString *)
                     "\\\r\n\tfloat3 ProjectorEyeV = GbxProjectorPos_wInvFarZ20-v.PosInVisual;\\\r\n\tfloat4 ProjectorTc = v.TcProjector;\\\r\n\tfpart4 ProjectorMask = tex2Dproj(MapProjector, ProjectorTc)*(ProjectorTc.w>0);\\\r\n\tfpart  ProjectorAtt = saturate(v.PosInVisual.w-GbxProjectorPos_wInvFarZ20.w*dot(ProjectorEyeV,ProjectorEyeV));\\\r\n\tfpart4 ProjectorTmp = ProjectorMask*GbxProjectorBaseRgb0*ProjectorAtt;\\\r\n\tfpart4 ProjectorAmbient = ProjectorTmp;\\\r\n\tfpart4 ProjectorDiffus = ProjectorTmp;\\\r\n\tfpart4 ProjectorSpecular = ProjectorTmp;"
                     ,in_stack_ffffffc0);
          in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0x19);
        }
      }
      else {
        CFastString::CFastString
                  ((CFastString *)&local_8,
                   (CFastString *)
                   "\\\r\n\tsampler2D MapProjector;\\\r\n\tconst fpart GbxProjectorDeferedScale;",
                   (char *)in_stack_ffffffb4);
        uStack00000018 = 0x12;
        CPlugFileGPU::DefineAddOrSet
                  ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_2c,(CMwId *)&stack0xfffffffc,
                   in_stack_ffffffb8);
        uStack0000001c = 0x11;
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x00000000,in_stack_ffffffbc);
        CFastString::CFastString
                  ((CFastString *)&param_1,
                   (CFastString *)
                   "\tfpart4 ProjectorBuffer = tex2Dproj(MapProjector, v.PosInVisual)*GbxProjectorDeferedScale;\\\r\n\tfpart4 ProjectorDiffus = saturate(fpart4(ProjectorBuffer.rgb, 1));\\\r\n\tfpart4 ProjectorSpecular = ProjectorBuffer.a;"
                   ,in_stack_ffffffc0);
        in_stack_00000024 = (void *)CONCAT31(in_stack_00000024._1_3_,0x13);
      }
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)this_00,(CPlugFileGPU *)&local_28,(CMwId *)&param_2,pCVar26);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0x0000000c,in_stack_ffffffc8);
      in_stack_0000002c = CONCAT31(in_stack_0000002c._1_3_,0x10);
      OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffcc);
      in_stack_0000002c = 0xffffffff;
      OnAccessViolation_ConcatToCrashFileName(in_stack_ffffffcc);
      ExceptionList = in_stack_00000024;
      return;
    }
    if (iVar5 == DAT_00d6ecec) {
      CFastString::CFastString
                ((CFastString *)&local_28,(CFastString *)"\\\r\n\\\r\n\tsampler2D MapWaterFog;",
                 pcVar3);
      pCVar16 = param_1;
      local_8 = 0x1a;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)param_1,(CPlugFileGPU *)&DAT_00d6f8a0,(CMwId *)&local_24,unaff_EDI)
      ;
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&local_20,(SHeaderCommunity *)unaff_ESI);
      CFastString::CFastString
                ((CFastString *)&local_14,
                 (CFastString *)
                 "\\\r\n\tfpart4 ShadowSpecular = SoftShadow(MapShadowBuffer, v.TcShadowBuffer);\\\r\n\tfpart4 ShadowDiffus = saturate(GbxShadowInShaderRgb1+(1-GbxShadowInShaderRgb1)*ShadowSpecular);"
                 ,(char *)unaff_EBX);
      param_1 = (CPlugFilePHlsl *)0x1b;
      CPlugFileGPU::DefineAddOrSet
                ((CPlugFileGPU *)pCVar16,(CPlugFileGPU *)&DAT_00d6f8a4,(CMwId *)&local_10,
                 in_stack_ffffffa4);
      CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                (&local_c,(SHeaderCommunity *)in_stack_ffffffa8);
    }
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CPlugFilePHlsl::CPlugFilePHlsl
// =================================================
void __thiscall CPlugFilePHlsl::CPlugFilePHlsl(CPlugFilePHlsl *this,CPlugFilePHlsl *param_1)
{
{
  CPlugFileGPUP *unaff_ESI;
  
  CPlugFileGPUP::CPlugFileGPUP((CPlugFileGPUP *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x20) = 0x101;
  *(undefined4 *)(this + 200) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CPlugFilePHlsl::LoadCommonPHlsl
// =================================================
void __cdecl CPlugFilePHlsl::LoadCommonPHlsl(void)
{
{
  CMwNod *pCVar1;
  CFastStringInt *unaff_EBX;
  CMwId *unaff_ESI;
  CPlugFileGpuBuilder *pCVar2;
  CMwNod *unaff_EDI;
  undefined *puVar3;
  CMwNod *local_2c [2];
  CFastString aCStack_24 [4];
  CFastString local_20 [4];
  CFastString local_1c [4];
  CMwId *pCStack_18;
  undefined *local_14;
  CMwId *local_10;
  undefined *local_c;
  
  local_c = (undefined *)0xffffffff;
  local_10 = (CMwId *)&LAB_00ada130;
  local_14 = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_14;
  CSystemArchiveNod::LoadResource(0x40000022,local_2c);
  if (local_2c[0] != DAT_00d6f824) {
    if (local_2c[0] != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_2c[0],pCVar1);
    }
    if (DAT_00d6f824 != (CMwNod *)0x0) {
      CMwNod::MwRelease(DAT_00d6f824,unaff_EDI);
    }
    DAT_00d6f824 = local_2c[0];
  }
  pCVar2 = (CPlugFileGpuBuilder *)0x0;
  puVar3 = &DAT_00d6f7ec;
  do {
    CFastString::CFastString(aCStack_24,(CFastString *)"GbxShadow",(char *)unaff_EDI);
    CFastString::operator<<(local_20,pCVar2,(char *)unaff_ESI);
    unaff_EDI = (CMwNod *)0x8a468c;
    unaff_ESI = pCStack_18;
    CMwId::SetLocalName(puVar3,pCStack_18,unaff_EBX);
    if (local_14 != PTR_DAT_00bbf7d8) {
      unaff_EBX = (CFastStringInt *)(local_14 + -1);
      if ((local_14[-1] & 0x80) != 0) {
        unaff_EBX = (CFastStringInt *)(local_14 + -4);
      }
      unaff_ESI = (CMwId *)0x8a46ae;
      operator_delete__(unaff_EBX);
      pCStack_18 = (CMwId *)0x0;
      local_14 = PTR_DAT_00bbf7d8;
    }
    pCVar2 = pCVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (pCVar2 < (CPlugFileGpuBuilder *)&DAT_00000007);
  pCVar2 = (CPlugFileGpuBuilder *)0x0;
  puVar3 = &DAT_00d6f808;
  do {
    CFastString::CFastString(local_1c,(CFastString *)"GbxShadowMask",(char *)unaff_EDI);
    CFastString::operator<<((CFastString *)&pCStack_18,pCVar2,(char *)unaff_ESI);
    unaff_EDI = (CMwNod *)0x8a470c;
    unaff_ESI = local_10;
    CMwId::SetLocalName(puVar3,local_10,unaff_EBX);
    if (local_c != PTR_DAT_00bbf7d8) {
      unaff_EBX = (CFastStringInt *)(local_c + -1);
      if ((local_c[-1] & 0x80) != 0) {
        unaff_EBX = (CFastStringInt *)(local_c + -4);
      }
      unaff_ESI = (CMwId *)0x8a472e;
      operator_delete__(unaff_EBX);
      local_10 = (CMwId *)0x0;
      local_c = PTR_DAT_00bbf7d8;
    }
    pCVar2 = pCVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (pCVar2 < (CPlugFileGpuBuilder *)&DAT_00000007);
  ExceptionList = (void *)0x1;
  return;
}
}

