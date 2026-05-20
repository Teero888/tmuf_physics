// Class implementation: CPlugFileGPU

// =================================================
// Function: CPlugFileGPU::AddDxDefines
// =================================================
void __thiscall
CPlugFileGPU::AddDxDefines
          (CPlugFileGPU *this,CPlugFileGPU *param_1,
          CFastBuffer<struct_CPlugFileGPU::SDxDefine> *param_2)
{
{
  CPlugFileGPU *this_00;
  CFastBuffer<struct_CPlugFileGPU::SDxDefine> *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  ulong uVar2;
  ulong uVar3;
  SLoadedLight *pSVar4;
  SCasterCat *pSVar5;
  undefined4 extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000000c;
  ulong in_stack_00000010;
  ulong uStack00000014;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_00000018;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *in_stack_0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000028;
  
  this_01 = param_2;
  this_00 = this + 0xa4;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_ESI);
  CFastBuffer<struct_SBindingToSort>::SetSizeAtLeast
            (param_2,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(uVar2 + 4 + uVar3),unaff_EBP)
  ;
  uStack00000014 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_retaddr);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (uStack00000014 != 0) {
    do {
      pCVar6 = pCVar1;
      pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                         (this_01,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBX)
      ;
      unaff_EBX = pCVar6;
      pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar6,(ulong)param_1);
      param_1 = (CPlugFileGPU *)0x8db348;
      CMwId::GetString(pSVar5,(CMwStatsValue *)param_2,(CFastString *)in_stack_0000000c);
      *(undefined4 *)pSVar4 = extraout_EAX;
      param_2 = (CFastBuffer<struct_CPlugFileGPU::SDxDefine> *)0x8db352;
      pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar6,in_stack_00000010);
      *(undefined4 *)(pSVar4 + 4) = *(undefined4 *)(pSVar5 + 8);
      pCVar1 = pCVar6 + 1;
      in_stack_0000000c = pCVar6;
    } while (pCVar6 + 1 < in_stack_00000028);
  }
  uStack00000014 = 0x8db369;
  pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem(this_01,in_stack_00000018);
  *(char **)pSVar4 = "DGbxVersion";
  *(undefined **)(pSVar4 + 4) = &DAT_00b30a74;
  pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem(this_01,in_stack_0000001c);
  *(undefined4 *)pSVar4 = 0;
  *(undefined4 *)(pSVar4 + 4) = 0;
  return;
}
}

// =================================================
// Function: CPlugFileGPU::CPlugFileGPU
// =================================================
void __thiscall CPlugFileGPU::CPlugFileGPU(CPlugFileGPU *this,CPlugFileGPU *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  CPlugFileText *unaff_EDI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  CFastArray<class_CManoeuvre*> *in_stack_00000008;
  CFastArray<class_CManoeuvre*> *in_stack_0000000c;
  CFastArray<class_CManoeuvre*> *in_stack_00000010;
  CFastArray<class_CManoeuvre*> *in_stack_00000014;
  CFastArray<class_CManoeuvre*> *in_stack_00000018;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000001c;
  CFastArray<class_CManoeuvre*> *in_stack_00000020;
  CFastArray<class_CManoeuvre*> *in_stack_00000024;
  CFastArray<class_CManoeuvre*> *in_stack_00000028;
  CFastArray<class_CManoeuvre*> *in_stack_0000002c;
  CFastArray<class_CManoeuvre*> *in_stack_00000030;
  CFastArray<class_CManoeuvre*> *in_stack_00000034;
  
  CPlugFileText::CPlugFileText((CPlugFileText *)this,unaff_EDI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x30,unaff_ESI);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x38,unaff_retaddr);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>
            (this + 0x40,(CFastArray<class_CManoeuvre*> *)param_1);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x4c,in_stack_00000008);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x54,in_stack_0000000c);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x5c,in_stack_00000010);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 100,in_stack_00000014);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x6c,in_stack_00000018);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x74,in_stack_0000001c);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x80,in_stack_00000020);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x88,in_stack_00000024);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x90,in_stack_00000028);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x98,in_stack_0000002c);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xa4,in_stack_00000030);
  *(undefined4 *)(this + 0xac) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0xb0,in_stack_00000034);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  return;
}
}

// =================================================
// Function: CPlugFileGPU::DefineAddOrSet
// =================================================
void __thiscall
CPlugFileGPU::DefineAddOrSet
          (CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2,CFastString *param_3)
{
{
  CPlugFileGPU *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  SPackedDesc *pSVar4;
  SStringParam *unaff_EBX;
  SStringParam *unaff_EBP;
  CFastArray<struct_CDx9StateBlock::SPackedDesc> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0xa4;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar5,(ulong)unaff_ESI);
      if (*(int *)pSVar3 == iVar1) {
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar5,(ulong)&stack0x00000000);
        CFastString::SetString((CFastString *)(pSVar3 + 4),(CFastStringInt *)unaff_EBP,unaff_EBX);
        return;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  pSVar4 = CFastArray<struct_SPlugGpuDefine>::AddNewTailElem(this_00,unaff_ESI);
  *(undefined4 *)pSVar4 = *(undefined4 *)param_3;
  CFastString::SetString((CFastString *)(pSVar4 + 4),(CFastStringInt *)&stack0x00000000,unaff_EBP);
  return;
}
}

// =================================================
// Function: CPlugFileGPU::DefineGetValue
// =================================================
CFastString * __thiscall
CPlugFileGPU::DefineGetValue(CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xa4,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    iVar1 = *(int *)param_2;
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0xa4,pCVar4,unaff_ESI);
      if (*(int *)pSVar3 == iVar1) {
        return (CFastString *)(pSVar3 + 4);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (CFastString *)0x0;
}
}

// =================================================
// Function: CPlugFileGPU::DefineIdUpdateFromText
// =================================================
void __thiscall CPlugFileGPU::DefineIdUpdateFromText(CPlugFileGPU *this,CPlugFileGPU *param_1)
{
{
  CFastString *this_00;
  char *pcVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined *puVar5;
  SStringParam *unaff_EDI;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar6;
  CFastArray<class_GxTexCoordSet> aCStack_40 [4];
  char *pcStack_3c;
  undefined4 uStack_38;
  undefined *puStack_34;
  char *pcStack_30;
  char *pcStack_2c;
  int iStack_24;
  undefined1 *puStack_20;
  char *pcStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00ad8d68;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastArray<class_CMwId>::SetCount
            (this + 0x88,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,
             DAT_00cca150 ^ (uint)&stack0xffffffb0);
  pCVar6 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x9074000;
  iVar2 = (**(code **)(*(int *)this + 0x10))();
  if (((iVar2 != 0) || (iVar2 = (**(code **)(*(int *)this + 0x10))(0x9077000), iVar2 != 0)) ||
     (iVar2 = (**(code **)(*(int *)this + 0x10))(0x9045000), iVar2 != 0)) {
    pcVar1 = "DGbx";
    do {
      pcStack_3c = pcVar1;
      pcVar1 = pcStack_3c + 1;
    } while (*pcStack_3c != '\0');
    pcStack_3c = pcStack_3c + -0xbb45c8;
    pcStack_30 = "DGbx";
    pcVar1 = "DGbx";
    do {
      pcStack_2c = pcVar1;
      pcVar1 = pcStack_2c + 1;
    } while (*pcStack_2c != '\0');
    pcStack_2c = pcStack_2c + -0xbb45c8;
    this_00 = (CFastString *)(this + 0x14);
    uVar3 = CFastString::FindFirst(this_00,(CFastStringInt *)&pcStack_30,0,1);
    while (uVar3 != 0xffffffff) {
      pcStack_30 = " \t\r\n(){}[],;:!?.!=<>+-*/";
      pcStack_2c = (char *)0x18;
      uVar4 = CFastString::FindFirstCharInSet
                        (this_00,(CFastString *)&pcStack_30,(SStringParam *)(pcStack_3c + uVar3),
                         (ulong)pCVar6);
      if (uVar4 == 0xffffffff) {
        ExceptionList = local_14;
        return;
      }
      iStack_24 = *(int *)(this + 0x18) + uVar3;
      puStack_20 = (undefined1 *)(uVar4 - uVar3);
      puStack_34 = (undefined *)0x0;
      pcStack_30 = PTR_DAT_00bbf7d8;
      uStack_8 = 0;
      CFastString::SetString((CFastString *)&puStack_34,(CFastStringInt *)&iStack_24,unaff_EDI);
      CMwId::CreateFromLocalName((char *)&uStack_38);
      unaff_EDI = (SStringParam *)&uStack_38;
      pCVar6 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x893a5b;
      iVar2 = (**(code **)(*(int *)this + 0xac))();
      if ((iVar2 != 0) &&
         (iVar2 = CFastArray<class_CGameMenuFrame*>::Find
                            (this + 0x88,aCStack_40,(GxTexCoordSet *)pCVar6), iVar2 == -1)) {
        pCVar6 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)&pcStack_3c;
        CFastArray<class_CMwId>::AddTail(this + 0x88,pCVar6,(SFormat *)unaff_EDI);
      }
      puStack_20 = &DAT_00bb45c8;
      pcVar1 = "DGbx";
      do {
        pcStack_1c = pcVar1;
        pcVar1 = pcStack_1c + 1;
      } while (*pcStack_1c != '\0');
      pcStack_1c = pcStack_1c + -0xbb45c8;
      uVar3 = CFastString::FindFirst(this_00,(CFastStringInt *)&puStack_20,uVar3 + 1,1);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar6);
      uStack_c = 0xffffffff;
      if (puStack_34 != PTR_DAT_00bbf7d8) {
        puVar5 = puStack_34 + -1;
        if ((puStack_34[-1] & 0x80) != 0) {
          puVar5 = puStack_34 + -4;
        }
        operator_delete__(puVar5);
        uStack_38 = 0;
        puStack_34 = PTR_DAT_00bbf7d8;
      }
    }
  }
  ExceptionList = local_14;
  return;
}
}

// =================================================
// Function: CPlugFileGPU::LoadDescsOnUpdate
// =================================================
void __thiscall CPlugFileGPU::LoadDescsOnUpdate(CPlugFileGPU *this,CPlugFileGPU *param_1)
{
{
  ulong uVar1;
  SNewTriangleVert *this_00;
  SLoadDesc *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastArray<struct_SPlugGpuLoadFx> *unaff_retaddr;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x4c,unaff_EDI);
  if (uVar1 == 0) {
    *(undefined4 *)(this + 0x48) = 0;
    return;
  }
  this_00 = CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::GetLastElem
                      (this + 0x4c,
                       (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                       (this + 0x54));
  uVar1 = SLoadDesc::GetNextRegisterIndex(this_00,unaff_ESI,unaff_retaddr);
  *(ulong *)(this + 0x48) = uVar1;
  return;
}
}

// =================================================
// Function: CPlugFileGPU::LoadFxFindByName
// =================================================
SPlugGpuLoadFx * __thiscall
CPlugFileGPU::LoadFxFindByName
          (CPlugFileGPU *this,CPlugFileGPU *param_1,CMwId *param_2,ulong *param_3)
{
{
  SPlugGpuLoadFx *pSVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000010;
  undefined4 *in_stack_00000018;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x54,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pSVar1 = *(SPlugGpuLoadFx **)param_2;
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x54,pCVar4,unaff_ESI);
      if (*(ulong **)pSVar3 == param_3) {
        if (in_stack_00000010 != (undefined4 *)0x0) {
          *in_stack_00000010 = 0xffffffff;
          pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount
                             (this + 0x4c,(CFastBuffer<class_CCrystalFace*> *)0x892bb0);
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            while( true ) {
              pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x4c,pCVar5,unaff_EBX);
              if (((*(uint *)pSVar3 & 1) == 0) &&
                 ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(*(uint *)pSVar3 >> 1) == pCVar4
                 )) break;
              pCVar5 = pCVar5 + 1;
              if (pCVar2 <= pCVar5) {
                return (SPlugGpuLoadFx *)param_3;
              }
            }
            *in_stack_00000018 = *(undefined4 *)(pSVar3 + 4);
          }
        }
        return pSVar1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return (SPlugGpuLoadFx *)0x0;
}
}

// =================================================
// Function: CPlugFileGPU::UpdatePlugFromByteCode
// =================================================
void __thiscall
CPlugFileGPU::UpdatePlugFromByteCode(CPlugFileGPU *this,CPlugFileGPU *param_1,int param_2)
{
{
  undefined *puVar1;
  CFastString CVar2;
  ulong uVar3;
  ID3DXConstantTable *pIVar4;
  int iVar5;
  int *piVar6;
  CPlugFileGpuBuilder *pCVar7;
  CPlugFileGpuBuilder *pCVar8;
  int *piVar9;
  CPlugFileGpuBuilder *pCVar10;
  CPlugFileGpuBuilder *pCVar11;
  undefined4 *puVar12;
  undefined3 extraout_var;
  CFastArray<struct_SPlugGpuLoadFx> *pCVar13;
  CFastBuffer<class_GxVertex> *pCVar14;
  undefined *puVar15;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  ID3DXConstantTable *pIVar16;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  ID3DXConstantTable *pIVar17;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *pCVar18;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  uint uVar19;
  undefined1 uStack00000014;
  char *pcVar20;
  CPlugFileGpuBuilder *pCVar21;
  ID3DXConstantTable *pIVar22;
  CFastStringInt *pCVar23;
  char *pcVar24;
  char *pcVar25;
  CPlugFileGpuBuilder *pCVar26;
  char *in_stack_fffffcd0;
  CPlugFileGPU *in_stack_fffffcd4;
  ID3DXConstantTable *in_stack_fffffcd8;
  LPCSTR *ppCVar27;
  CPlugFileGPU *in_stack_fffffce0;
  ID3DXConstantTable *in_stack_fffffce4;
  ulong in_stack_fffffce8;
  GxVertex *in_stack_fffffcec;
  CPlugFileGPU *in_stack_fffffcf0;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *in_stack_fffffcf4;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *in_stack_fffffcf8;
  CPlugFileGPU *pCVar28;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *pCVar29;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *in_stack_fffffd04;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *in_stack_fffffd08;
  CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *pCVar30;
  ID3DXConstantTable *pIVar31;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar32;
  CFastBuffer<class_CCrystalFace*> *pCVar33;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffd28;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffd2c;
  ID3DXConstantTable *pIVar34;
  _func___cdecl_int_SKey_ptr_SKey_ptr *p_Var35;
  _func___cdecl_int_SKey_ptr_SKey_ptr *in_stack_fffffd34;
  CFastBuffer<class_CCrystalFace*> *pCVar36;
  undefined1 auStack_2b8 [4];
  CFastBuffer<class_CCrystalFace*> *pCStack_2b4;
  CFastString aCStack_2ac [4];
  undefined4 local_2a8;
  CFastBuffer<struct_CPlugFileGPU::SSampler> aCStack_2a4 [4];
  CFastBuffer<class_CCrystalFace*> *pCStack_2a0;
  undefined1 auStack_298 [4];
  CFastBuffer<struct_CPlugFileGPU::SSampler> aCStack_294 [4];
  undefined1 auStack_290 [4];
  CFastBuffer<class_CCrystalFace*> *pCStack_28c;
  SGpuConst aSStack_288 [4];
  undefined1 auStack_284 [12];
  undefined1 auStack_278 [4];
  int aiStack_274 [2];
  undefined1 auStack_26c [4];
  CFastStringInt aCStack_268 [4];
  undefined4 auStack_264 [2];
  char acStack_25c [4];
  undefined1 auStack_258 [12];
  undefined1 auStack_24c [4];
  undefined1 auStack_248 [20];
  uint uStack_234;
  int iStack_230;
  int iStack_22c;
  undefined1 uStack_68;
  undefined1 uStack_60;
  undefined1 uStack_5c;
  void *local_14;
  undefined1 *local_10;
  uint uStack_c;
  undefined4 local_8;
  
  pCVar32 = (CFastBuffer<class_CPlugFileSndGen*> *)&stack0xfffffffc;
  uStack_c = 0xffffffff;
  local_10 = &LAB_00ade107;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar28 = this;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0xb0,
                     (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xfffffd18));
  if (uVar3 != 0) {
    pIVar17 = *(ID3DXConstantTable **)(this + 0xb8);
    pIVar16 = *(ID3DXConstantTable **)(this + 0xb4);
    pIVar22 = pIVar16;
    if (pIVar17 == (ID3DXConstantTable *)0x0) {
      func_0x009f0a88();
      pIVar17 = *(ID3DXConstantTable **)(this + 0xb8);
      if (pIVar17 == (ID3DXConstantTable *)0x0) {
        ExceptionList = local_10;
        return;
      }
    }
    puVar1 = PTR_DAT_00bbf7d8;
    local_8 = 0;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_2a8,unaff_EDI);
    pCVar30 = (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)0x8dc9db;
    pIVar31 = pIVar16;
    pIVar4 = pIVar17;
    GetHlslSamplers((ulong *)pIVar16,pIVar17,aCStack_2a4);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(auStack_298,unaff_ESI);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(aSStack_288,pCVar32);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(auStack_278,unaff_EBX);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (aCStack_268,in_stack_fffffd28);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (auStack_258,in_stack_fffffd2c);
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (auStack_248,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar28);
    p_Var35 = (_func___cdecl_int_SKey_ptr_SKey_ptr *)&uStack_234;
    uStack00000014 = 2;
    pIVar34 = pIVar17;
    (**(code **)(*(int *)pIVar17 + 0x14))();
    uVar19 = 0;
    if (uStack_234 != 0) {
      do {
        pIVar4 = (ID3DXConstantTable *)(**(code **)(*(int *)pIVar17 + 0x20))();
        local_2a8 = 1;
        pCVar30 = (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)0x8dca63;
        pIVar31 = pIVar17;
        (**(code **)(*(int *)pIVar17 + 0x18))();
        if ((iStack_230 != 0) && (iStack_22c != 3)) {
          pIVar4 = (ID3DXConstantTable *)0x8dca95;
          ParseHlslConstant((_D3DXCONSTANT_DESC *)&iStack_230,aCStack_2ac,aSStack_288,
                            (CFastArray<struct_CPlugFileGPU::SSemantic> *)0x0,aCStack_294);
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 < uStack_234);
    }
    pCVar33 = (CFastBuffer<class_CCrystalFace*> *)0x8dcab2;
    CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
              (aCStack_294,
               (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)Sampler_Sort,
               (_func___cdecl_int_SKey_ptr_SKey_ptr *)pIVar34);
    CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
              (auStack_284,
               (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)LoadDesc_Sort,
               p_Var35);
    CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
              (acStack_25c,
               (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)LoadDesc_Sort,
               in_stack_fffffd34);
    CFastArray<struct_CPlugVertexStream::SDataDecl>::QSort
              (auStack_24c,
               (CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *)LoadDesc_Sort,
               (_func___cdecl_int_SKey_ptr_SKey_ptr *)pIVar22);
    pCVar36 = (CFastBuffer<class_CCrystalFace*> *)0x9074000;
    iVar5 = (**(code **)(*(int *)this + 0x10))();
    pCVar18 = (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)(uint)(iVar5 == 0);
    pIVar17 = pIVar16;
    pCVar29 = pCVar18;
    if (pCVar18 == (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)0x0) {
      pCVar26 = (CPlugFileGpuBuilder *)&stack0xfffffce4;
      pcVar25 = acStack_25c;
      _D3DXGetShaderOutputSemantics_12();
      pCVar28 = this + 0xc4;
    }
    else {
      pCVar26 = (CPlugFileGpuBuilder *)&stack0xfffffce4;
      pcVar25 = acStack_25c;
      _D3DXGetShaderInputSemantics_12();
      pCVar28 = this + 0xbc;
    }
    *(uint *)pCVar28 = 0;
    ppCVar27 = (LPCSTR *)0x0;
    if (in_stack_fffffcd8 != (ID3DXConstantTable *)0x0) {
      pCVar23 = aCStack_268;
      this = in_stack_fffffce0;
      pIVar16 = in_stack_fffffce4;
      pCVar18 = in_stack_fffffcf4;
      do {
        iVar5 = *(int *)pCVar23;
        pCVar8 = *(CPlugFileGpuBuilder **)(pCVar23 + 4);
        uVar19 = 0;
        piVar6 = &DAT_00bbd010;
        do {
          if ((*piVar6 == iVar5) && ((CPlugFileGpuBuilder *)piVar6[1] == pCVar8)) {
            *(uint *)pCVar28 = *(uint *)pCVar28 | 1 << ((byte)uVar19 & 0x1f);
            break;
          }
          uVar19 = uVar19 + 1;
          piVar6 = piVar6 + 2;
        } while (uVar19 < 0xd);
        if (uVar19 == 0xd) {
          pcVar24 = "\"";
          pCVar7 = CFastString::operator<<
                             ((CFastString *)&stack0xfffffcec,
                              (CPlugFileGpuBuilder *)"Unknown vertex->pixel semantic \"",
                              (&PTR_s_POSITION_00d1a780)[iVar5]);
          pCVar8 = CFastString::operator<<((CFastString *)pCVar7,pCVar8,pcVar24);
          pCVar8 = CFastString::operator<<
                             ((CFastString *)pCVar8,(CPlugFileGpuBuilder *)pIVar17,pcVar25);
          pcVar25 = (char *)0x8dcbbd;
          CFastString::operator<<((CFastString *)pCVar8,pCVar26,in_stack_fffffcd0);
        }
        ppCVar27 = (LPCSTR *)((int)ppCVar27 + 1);
        pCVar23 = pCVar23 + 8;
        in_stack_fffffce0 = this;
        in_stack_fffffce4 = pIVar16;
        in_stack_fffffcf4 = pCVar18;
      } while (ppCVar27 < in_stack_fffffcd8);
    }
    pCVar8 = (CPlugFileGpuBuilder *)&stack0xfffffcd8;
    pCVar23 = aCStack_268;
    pIVar22 = pIVar16;
    if (pCVar18 == (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)0x0) {
      _D3DXGetShaderInputSemantics_12();
      *(undefined4 *)(this + 0xbc) = 0;
      pCVar7 = (CPlugFileGpuBuilder *)0x0;
      if (pCVar26 != (CPlugFileGpuBuilder *)0x0) {
        piVar6 = aiStack_274;
        this = in_stack_fffffcd4;
        pIVar16 = in_stack_fffffcd8;
        do {
          iVar5 = *piVar6;
          pCVar11 = (CPlugFileGpuBuilder *)piVar6[1];
          uVar19 = 0;
          piVar9 = &DAT_00bbcf60;
          do {
            if ((*piVar9 == iVar5) && ((CPlugFileGpuBuilder *)piVar9[1] == pCVar11)) {
              *(uint *)(this + 0xbc) = *(uint *)(this + 0xbc) | (&DAT_00d143d0)[uVar19];
              break;
            }
            uVar19 = uVar19 + 1;
            piVar9 = piVar9 + 2;
          } while (uVar19 < 0x16);
          if (uVar19 == 0x16) {
            pcVar24 = "\"";
            pCVar10 = CFastString::operator<<
                                ((CFastString *)&stack0xfffffce0,
                                 (CPlugFileGpuBuilder *)"Unknown input semantic \"",
                                 (&PTR_s_POSITION_00d1a780)[iVar5]);
            pCVar11 = CFastString::operator<<((CFastString *)pCVar10,pCVar11,pcVar24);
            pCVar11 = CFastString::operator<<
                                ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pIVar22,
                                 (char *)pCVar23);
            pCVar23 = (CFastStringInt *)0x8dcc82;
            CFastString::operator<<((CFastString *)pCVar11,pCVar8,(char *)pIVar17);
          }
          pCVar7 = pCVar7 + 1;
          piVar6 = piVar6 + 2;
          in_stack_fffffcd4 = this;
          in_stack_fffffcd8 = pIVar16;
        } while (pCVar7 < pCVar26);
      }
      iVar5 = 8;
      uVar19 = *(uint *)(this + 0xbc);
      do {
        if ((uVar19 & 0x6000000) != 0) break;
        iVar5 = iVar5 + -1;
        uVar19 = uVar19 * 4;
      } while (iVar5 != 0);
      *(int *)(this + 0xc0) = iVar5;
      if ((*(uint *)(this + 0xbc) & 1) == 0) {
        CFastString::operator<<
                  ((CFastString *)&stack0xfffffce0,
                   (CPlugFileGpuBuilder *)"\"POSITION\" input semantic must be present.",
                   (char *)pIVar22);
      }
    }
    else {
      _D3DXGetShaderOutputSemantics_12();
      *(undefined4 *)(this + 0xc0) = 0;
      pCVar7 = (CPlugFileGpuBuilder *)0x0;
      if (pCVar26 != (CPlugFileGpuBuilder *)0x0) {
        piVar6 = aiStack_274;
        this = in_stack_fffffcd4;
        pIVar16 = in_stack_fffffcd8;
        do {
          pcVar24 = (char *)*piVar6;
          pcVar20 = (char *)piVar6[1];
          uVar19 = 0;
          puVar12 = &DAT_00d1a7b8;
          do {
            if (((char *)*puVar12 == pcVar24) && ((char *)puVar12[1] == pcVar20)) {
              *(uint *)(this + 0xc0) = *(uint *)(this + 0xc0) | 1 << ((byte)uVar19 & 0x1f);
              break;
            }
            uVar19 = uVar19 + 1;
            puVar12 = puVar12 + 2;
          } while (uVar19 < 5);
          if (uVar19 == 5) {
            pCVar21 = (CPlugFileGpuBuilder *)&DAT_00b2ec78;
            pCVar10 = (CPlugFileGpuBuilder *)&DAT_00b2c990;
            pCVar11 = CFastString::operator<<
                                ((CFastString *)&stack0xfffffce0,
                                 (CPlugFileGpuBuilder *)"Unknown output semantic \"",pcVar24);
            pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar10,pcVar20);
            pCVar11 = CFastString::operator<<((CFastString *)pCVar11,pCVar21,(char *)pIVar22);
            pIVar22 = (ID3DXConstantTable *)0x8dcd71;
            pCVar11 = CFastString::operator<<
                                ((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pCVar23,
                                 (char *)pCVar8);
            pCVar8 = (CPlugFileGpuBuilder *)0x8dcd78;
            CFastString::operator<<((CFastString *)pCVar11,(CPlugFileGpuBuilder *)pIVar17,pcVar25);
          }
          pCVar7 = pCVar7 + 1;
          piVar6 = piVar6 + 2;
          in_stack_fffffcd4 = this;
          in_stack_fffffcd8 = pIVar16;
        } while (pCVar7 < pCVar26);
      }
    }
    uVar3 = 0;
    if (in_stack_fffffce0 != (CPlugFileGPU *)0x0) {
      in_stack_fffffce8 = 0;
      uStack_68 = 3;
      in_stack_fffffcec = (GxVertex *)PTR_DAT_00bbf7dc;
      CPlugFile::GetFullName
                ((CPlugFile *)this,(CPlugFile *)&stack0xfffffce8,(CFastStringInt *)pIVar22);
      ppCVar27 = &lpOutputString_00b2bcc4;
      CFastStringInt::Concat
                (&stack0xfffffcec,(CFastStringInt *)&stack0xfffffcdc,(SStringParam *)pCVar23);
      CVar2 = CFastStringInt::GetLatin1(&stack0xfffffcf0,(CFastStringInt *)&stack0xfffffcf8);
      uVar3 = ((undefined4 *)CONCAT31(extraout_var,CVar2))[1];
      in_stack_fffffce4 = *(ID3DXConstantTable **)CONCAT31(extraout_var,CVar2);
      pCVar23 = (CFastStringInt *)&stack0xfffffce0;
      uStack_60 = 4;
      pIVar22 = (ID3DXConstantTable *)0x8dce14;
      CFastString::ConcatBefore((CFastString *)&stack0xfffffce8,pCVar23,(SStringParamInt *)pCVar8);
      if (pCVar29 != (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)PTR_DAT_00bbf7d8) {
        pCVar8 = (CPlugFileGpuBuilder *)(pCVar29 + -1);
        if (((byte)pCVar29[-1] & 0x80) != 0) {
          pCVar8 = (CPlugFileGpuBuilder *)(pCVar29 + -4);
        }
        pCVar23 = (CFastStringInt *)0x8dce32;
        operator_delete__(pCVar8);
      }
      uStack_5c = 2;
      if (in_stack_fffffcf8 != (CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)PTR_DAT_00bbf7dc) {
        if (((byte)in_stack_fffffcf8[-1] & 0x80) == 0) {
          pCVar8 = (CPlugFileGpuBuilder *)(in_stack_fffffcf8 + -2);
        }
        else {
          pCVar8 = (CPlugFileGpuBuilder *)(in_stack_fffffcf8 + -4);
        }
        pCVar23 = (CFastStringInt *)0x8dce5d;
        operator_delete__(pCVar8);
      }
    }
    *(uint *)(this + 0x20) = (uint)*(ushort *)pIVar16;
    *(undefined4 *)(this + 0x2c) = 1;
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xfffffcf8,(CFastBuffer<class_CCrystalFace*> *)pCVar28);
    CFastArray<struct_SPlugGpuLoadFx>::SetArray
              ((CPlugFile *)(this + 0x40),pCVar13,(ulong)pIVar22,(SPlugGpuLoadFx *)pCVar23);
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (&stack0xfffffd0c,(CFastBuffer<class_CCrystalFace*> *)pIVar31);
    CFastArray<class_GmVec3>::SetArray
              ((CPlugFile *)(this + 0x4c),pCVar13,(ulong)pCVar8,(SPlugGpuLoadFx *)pIVar17);
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(&stack0xfffffd20,pCVar33);
    CFastArray<struct_SPlugGpuLoadFx>::SetArray
              ((CPlugFile *)(this + 0x54),pCVar13,(ulong)pcVar25,(SPlugGpuLoadFx *)pCVar26);
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(&stack0xfffffd34,pCVar36);
    CFastArray<class_GmVec3>::SetArray
              ((CPlugFile *)(this + 0x5c),pCVar13,(ulong)pCVar7,(SPlugGpuLoadFx *)in_stack_fffffcd4)
    ;
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(auStack_2b8,pCStack_2b4);
    CFastArray<class_GmVec3>::SetArray
              ((CPlugFile *)(this + 100),pCVar13,(ulong)in_stack_fffffcd8,(SPlugGpuLoadFx *)ppCVar27
              );
    pCVar13 = (CFastArray<struct_SPlugGpuLoadFx> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(aCStack_2a4,pCStack_2a0);
    CFastArray<class_GmVec3>::SetArray
              ((CPlugFile *)(this + 0x6c),pCVar13,uVar3,(SPlugGpuLoadFx *)in_stack_fffffce4);
    pCVar14 = (CFastBuffer<class_GxVertex> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(auStack_290,pCStack_28c);
    CFastBuffer<class_CMwId>::SetBuffer
              ((CPlugFile *)(this + 0x74),pCVar14,in_stack_fffffce8,in_stack_fffffcec);
    LoadDescsOnUpdate(this,in_stack_fffffcf0);
    CMwNod::MwSendMessage((CMwNod *)this,(CMwNod *)0x9040000,0,(ulong *)in_stack_fffffcf4);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems(&stack0xfffffd38,in_stack_fffffcf8);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems
              (auStack_2b8,(CFastBuffer<struct_CPlugFileGPU::SLoadDesc> *)pCVar28);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems(&local_2a8,pCVar29);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems(auStack_298,in_stack_fffffd04);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems(aSStack_288,in_stack_fffffd08);
    CFastBuffer<struct_CPlugFileGPU::SLoadDesc>::DetachElems(auStack_26c,pCVar30);
    local_10 = (undefined1 *)CONCAT31(local_10._1_3_,1);
    SGpuConst::~SGpuConst(aCStack_2a4,(SGpuConst *)pIVar31);
    uStack_c = uStack_c & 0xffffff00;
    CFastBuffer<struct_CPlugFileGPU::SSampler>::~CFastBuffer<struct_CPlugFileGPU::SSampler>
              (aCStack_2ac,(CFastBuffer<struct_CPlugFileGPU::SSampler> *)pIVar4);
    if (puVar1 != PTR_DAT_00bbf7d8) {
      puVar15 = puVar1 + -1;
      if ((puVar1[-1] & 0x80) != 0) {
        puVar15 = puVar1 + -4;
      }
      operator_delete__(puVar15);
    }
  }
  ExceptionList = local_10;
  return;
}
}

