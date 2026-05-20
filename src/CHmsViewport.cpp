// Class implementation: CHmsViewport

// =================================================
// Function: CHmsViewport::CHmsViewport
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsViewport::CHmsViewport(CHmsViewport *this,CHmsViewport *param_1)
{
{
  int iVar1;
  undefined4 uVar2;
  SCasterCat *pSVar3;
  CHmsConfig *this_00;
  CHmsConfig *extraout_EAX;
  CHmsConfig *this_01;
  CHmsAmbientOcc *this_02;
  CMwNod *extraout_EAX_00;
  undefined4 *puVar4;
  CMwCmdFastCall *this_03;
  CMwNod *extraout_EAX_01;
  CMwNod *pCVar5;
  void *this_04;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *unaff_EBX;
  CFastArray<class_CManoeuvre*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CMwNod *unaff_EDI;
  SRenderInfo *unaff_retaddr;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000010;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000014;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000018;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000001c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000020;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000024;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000028;
  ulong in_stack_0000002c;
  ulong in_stack_00000030;
  ulong in_stack_00000034;
  ulong in_stack_00000038;
  ulong in_stack_0000003c;
  ulong in_stack_00000040;
  CFastStringInt *in_stack_00000044;
  SStringParam *in_stack_00000048;
  ulong in_stack_0000004c;
  ulong in_stack_00000050;
  ulong in_stack_00000054;
  CHmsConfig *in_stack_00000058;
  CHmsConfig *pCVar6;
  CHmsConfig *pCVar7;
  code *in_stack_00000064;
  CMwNod *in_stack_00000068;
  CFastStringInt *in_stack_0000006c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000074;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000078;
  undefined1 uStack00000084;
  char *pcStack00000088;
  undefined4 in_stack_0000008c;
  undefined1 uStack00000090;
  void *in_stack_000000a0;
  CHmsViewport *pCVar8;
  CFastArray<class_CManoeuvre*> *in_stack_ffffffec;
  CFastArray<class_CManoeuvre*> *in_stack_fffffff0;
  CFastArray<class_CManoeuvre*> *pCVar9;
  CFastArray<class_CManoeuvre*> *pCVar10;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *pCVar11;
  
  pCVar11 = (CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)0xffffffff;
  pCVar10 = (CFastArray<class_CManoeuvre*> *)&LAB_00a95452;
  pCVar9 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar8 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd8),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x14,unaff_ESI);
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined **)(this + 0x128) = PTR_DAT_00bbf7dc;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined **)(this + 0x15c) = PTR_DAT_00bbf7d8;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x164,unaff_EBP);
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(this + 0x16c,unaff_EBX);
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
            (this + 400,
             (CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)pCVar8);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x1b4,in_stack_ffffffec);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x1bc,in_stack_fffffff0);
  pCVar8 = this + 0x1c4;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(pCVar8,pCVar9);
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x1cc,pCVar10);
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(this + 0x264,pCVar11);
  SRenderInfo::SRenderInfo(this + 0x294,unaff_retaddr);
  *(undefined4 *)(this + 0x334) = 0;
  *(undefined4 *)(this + 0x338) = 0;
  *(undefined4 *)(this + 0x33c) = 0;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
            (this + 0x360,
             (CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)0x0);
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
            (this + 0x390,in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x43c,in_stack_0000000c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x454,in_stack_00000010);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x460,in_stack_00000014);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x46c,in_stack_00000018);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x478,in_stack_0000001c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x484,in_stack_00000020);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x538,in_stack_00000024);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x55c,in_stack_00000028);
  in_stack_00000054 = CONCAT31(in_stack_00000054._1_3_,0x1a);
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x22c) = 1;
  CFastBuffer<struct_CHmsViewport::SVisualLocation>::SetSizeAtLeast
            (this + 0x454,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x10,in_stack_0000002c);
  CFastBuffer<struct_CHmsViewport::SClippingFrustum>::SetSizeAtLeast
            (this + 0x460,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x10,in_stack_00000030);
  CFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject>::SetSizeAtLeast
            (this + 0x478,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x10,in_stack_00000034);
  CFastBuffer<struct_SHmsRenderRect>::SetSizeAtLeast
            (this + 0x484,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x10,in_stack_00000038);
  CFastBuffer<struct_CHmsViewport::SVisualLocation>::SetSizeAtLeast
            (this + 0x538,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)&DAT_00000020,
             in_stack_0000003c);
  *(undefined4 *)(this + 0x534) = 0;
  *(undefined4 *)(this + 0x38c) = 0;
  *(undefined4 *)(this + 0x24) = 1;
  *(undefined4 *)(this + 0x28) = 1;
  *(undefined4 *)(this + 0x2c) = 1;
  *(undefined4 *)(this + 0x30) = 1;
  *(undefined4 *)(this + 0x34) = 1;
  *(undefined4 *)(this + 0x38) = _DAT_00d674d4;
  *(undefined4 *)(this + 0x3c) = _DAT_00d674d8;
  *(undefined4 *)(this + 0x40) = _DAT_00d674dc;
  *(undefined4 *)(this + 0x44) = _DAT_00d674e0;
  CFastArray<class_CFastString>::SetCount
            (pCVar8,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_00000040);
  pCVar6 = (CHmsConfig *)&DAT_00b38ec8;
  pCVar7 = (CHmsConfig *)&DAT_00000004;
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[]
                     (pCVar8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      (ulong)&stack0x0000005c);
  CFastString::SetString((CFastString *)pSVar3,in_stack_00000044,in_stack_00000048);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this + 0x1cc,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_0000004c);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x1cc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_00000050);
  *(undefined4 *)pSVar3 = 0;
  *(undefined4 *)(this + 0x250) = 0;
  *(undefined4 *)(this + 0x254) = 0;
  *(undefined4 *)(this + 600) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0xffffffff;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x58) = 0xffffffff;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x324) = 1;
  *(undefined4 *)(this + 0x328) = 1;
  *(undefined4 *)(this + 0x330) = 1;
  *(undefined4 *)(this + 0x348) = 0;
  *(undefined4 *)(this + 0x35c) = 0;
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
            (this + 0x360,
             (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)0x2,in_stack_00000054);
  *(undefined4 *)(this + 0x414) = 1;
  *(undefined4 *)(this + 0x34c) = 0;
  *(undefined4 *)(this + 0x354) = 0;
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x418) = 1;
  *(undefined4 *)(this + 0x41c) = 0;
  *(undefined4 *)(this + 0x420) = 0;
  *(undefined4 *)(this + 0x424) = 1;
  *(undefined4 *)(this + 0x428) = 1;
  *(undefined4 *)(this + 0x42c) = 1;
  *(undefined4 *)(this + 0x3bc) = 0;
  *(undefined4 *)(this + 0x434) = 0;
  *(undefined4 *)(this + 0x438) = 0;
  *(undefined4 *)(this + 0x448) = 0;
  *(undefined4 *)(this + 0x44c) = 0;
  *(undefined4 *)(this + 0x3c0) = 0;
  *(undefined4 *)(this + 0x20c) = 0;
  *(undefined4 *)(this + 0x214) = 0;
  *(undefined4 *)(this + 0x218) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x248) = 3;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 1;
  this[0x8c] = (CHmsViewport)0x33;
  *(undefined4 *)(this + 0x90) = 4;
  *(undefined4 *)(this + 0x6c) = 1;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x288) = 0;
  *(undefined4 *)(this + 0x74) = 1;
  *(undefined4 *)(this + 0x430) = 0;
  *(undefined4 *)(this + 0x32c) = 2;
  this_00 = operator_new(0x28);
  if (this_00 == (CHmsConfig *)0x0) {
    this_01 = (CHmsConfig *)0x0;
  }
  else {
    CHmsConfig::CHmsConfig(this_00,in_stack_00000058);
    this_01 = extraout_EAX;
  }
  *(CHmsConfig **)(this + 0x244) = this_01;
  uStack00000084 = 0x1a;
  CHmsConfig::CopyFromConfig(this_01,DAT_00d674d0,pCVar6);
  ConfigSet(this,*(CHmsViewport **)(this + 0x244),pCVar7);
  this_02 = operator_new(0x2c);
  in_stack_0000008c = CONCAT31(in_stack_0000008c._1_3_,0x1c);
  if (this_02 == (CHmsAmbientOcc *)0x0) {
    pCVar5 = (CMwNod *)0x0;
  }
  else {
    CHmsAmbientOcc::CHmsAmbientOcc(this_02,(CHmsAmbientOcc *)in_stack_00000064);
    pCVar5 = extraout_EAX_00;
  }
  uStack00000090 = 0x1a;
  if (pCVar5 != *(CMwNod **)(this + 0x9c)) {
    if (pCVar5 != (CMwNod *)0x0) {
      in_stack_00000064 = (code *)0x5329d4;
      CMwNod::MwAddRef(pCVar5,in_stack_00000068);
    }
    if (*(CMwNod **)(this + 0x9c) != (CMwNod *)0x0) {
      in_stack_00000064 = (code *)0x5329e3;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x9c),in_stack_00000068);
    }
    *(CMwNod **)(this + 0x9c) = pCVar5;
  }
  in_stack_00000064 = (code *)0x28;
  *(undefined4 *)(this + 0x24c) = 0;
  puVar4 = operator_new(0x28);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
  }
  *(undefined4 **)(this + 0x31c) = puVar4;
  puVar4[9] = puVar4[9] & 0xfffffffe;
  *(uint *)(*(int *)(this + 0x31c) + 0x24) = *(uint *)(*(int *)(this + 0x31c) + 0x24) & 0xfffffffd;
  *(uint *)(*(int *)(this + 0x31c) + 0x24) = *(uint *)(*(int *)(this + 0x31c) + 0x24) & 0xfffffffb;
  *(undefined4 *)(*(int *)(this + 0x31c) + 4) = 0;
  *(undefined4 *)(*(int *)(this + 0x31c) + 8) = 0;
  *(undefined4 *)(*(int *)(this + 0x31c) + 0xc) = 0;
  uVar2 = _DAT_00b3380c;
  iVar1 = *(int *)(this + 0x31c);
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(this + 0xa8) = uVar2;
  in_stack_00000064 = (code *)(this + 0xb8);
  *(undefined4 *)(this + 0xac) = 0x3f800000;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0x50;
  *(undefined4 *)(this + 0xb0) = uVar2;
  CMwProfiler::GetTimeStamp((int64 *)in_stack_00000064);
  _memset(this + 0xc0,0,0x50);
  *(undefined4 *)(this + 0x110) = 0;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 800) = 0;
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x23c) = 0;
  this_03 = operator_new(0x24);
  uStack00000090 = 0x1d;
  if (this_03 == (CMwCmdFastCall *)0x0) {
    pCVar5 = (CMwNod *)0x0;
  }
  else {
    in_stack_00000064 = Run;
    CMwCmdFastCall::CMwCmdFastCall
              (this_03,(CMwCmdFastCall *)this,(CMwNod *)Run,(_func___cdecl_void *)in_stack_00000068,
               (ulong)in_stack_0000006c);
    pCVar5 = extraout_EAX_01;
  }
  uStack00000090 = 0x1a;
  *(CMwNod **)(this + 0x25c) = pCVar5;
  in_stack_00000064 = (code *)0x532b11;
  CMwNod::MwAddRef(pCVar5,in_stack_00000068);
  in_stack_00000068 = (CMwNod *)0x20;
  in_stack_00000064 = (code *)0x532b1e;
  CMwCmd::SetSchemeLocation
            (*(CMwCmd **)(this + 0x25c),(CMwCmd *)&DAT_00000020,(ulong)in_stack_0000006c);
  in_stack_0000006c = (CFastStringInt *)&stack0x00000088;
  *(undefined4 *)(this + 0x120) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0x200;
  *(undefined4 *)(this + 0x144) = 0x180;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  pcStack00000088 = "test";
  in_stack_0000008c = 4;
  in_stack_00000068 = (CMwNod *)0x532b82;
  CFastString::SetString((CFastString *)(this + 0x158),in_stack_0000006c,(SStringParam *)this_00);
  *(undefined4 *)(this + 0x154) = _DAT_00b55928;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x28c) = 1;
  *(undefined4 *)(this + 0x290) = 0x80;
  in_stack_0000006c = (CFastStringInt *)0x532bab;
  this_04 = operator_new(0x24);
  if (this_04 == (void *)0x0) {
    this_04 = (void *)0x0;
  }
  else {
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (this_04,in_stack_00000074);
    in_stack_00000074 = (CFastBuffer<class_CPlugFileSndGen*> *)0x532bc3;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              ((void *)((int)this_04 + 0xc),in_stack_00000078);
    in_stack_00000078 = (CFastBuffer<class_CPlugFileSndGen*> *)0x532bcb;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              ((void *)((int)this_04 + 0x18),(CFastBuffer<class_CPlugFileSndGen*> *)this_02);
  }
  *(void **)(this + 0x238) = this_04;
  *(undefined4 *)(this + 0x544) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x548) = 0;
  *(undefined4 *)(this + 0x54c) = 0;
  *(undefined4 *)(this + 0x550) = 0;
  *(undefined4 *)(this + 0x554) = 0;
  *(undefined4 *)(this + 0x558) = 0;
  ExceptionList = in_stack_000000a0;
  return;
}
}

// =================================================
// Function: CHmsViewport::ConfigSet
// =================================================
void __thiscall
CHmsViewport::ConfigSet(CHmsViewport *this,CHmsViewport *param_1,CHmsConfig *param_2)
{
{
  CHmsViewport *unaff_retaddr;
  
  *(CHmsViewport **)(this + 0x240) = param_1;
  ResetShadowVolumes(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CHmsViewport::FindOrCreateViewport
// =================================================
CHmsViewport * __thiscall
CHmsViewport::FindOrCreateViewport(CHmsViewport *this,CVisionEngine *param_1,CSystemWindow *param_2)
{
{
  SCasterCat *pSVar1;
  CHmsViewport *pCVar2;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000c,unaff_retaddr)
  ;
  pCVar2 = CVisionEngine::FindOrCreateViewport
                     (*(CVisionEngine **)pSVar1,(CVisionEngine *)param_2,(CSystemWindow *)param_1);
  return pCVar2;
}
}

// =================================================
// Function: CHmsViewport::LoadResourceCorpus
// =================================================
void __thiscall
CHmsViewport::LoadResourceCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2)
{
{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(this + 0x358);
  pcVar2 = *(code **)(*(int *)this + 0xa0);
  uVar3 = *(undefined4 *)(this + 0x35c);
  *(undefined4 *)(this + 0x358) = 0;
  *(undefined4 *)(this + 0x35c) = *(undefined4 *)(param_1 + 0x14);
  *(CHmsViewport **)(this + 0x38c) = param_1;
  (*pcVar2)(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x48) + 0x14) + 100),0,0,0);
  *(undefined4 *)(this + 0x35c) = uVar3;
  *(undefined4 *)(this + 0x358) = uVar1;
  *(undefined4 *)(this + 0x38c) = 0;
  return;
}
}

// =================================================
// Function: CHmsViewport::LoadResourceZone
// =================================================
void __thiscall
CHmsViewport::LoadResourceZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2)
{
{
  int iVar1;
  code *pcVar2;
  ulong uVar3;
  int iVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint uVar5;
  
  if (DAT_00d54248 == 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x28,unaff_EDI);
    *(CHmsViewport **)(this + 0x35c) = param_1;
    iVar4 = (**(code **)(*(int *)param_1 + 0x10))(0x6009000);
    if (iVar4 != 0) {
      *(CHmsViewport **)(this + 0x358) = param_1;
    }
    uVar5 = 0;
    if (uVar3 != 0) {
      do {
        iVar4 = *(int *)(iVar1 + uVar5 * 4);
        pcVar2 = *(code **)(*(int *)this + 0xa0);
        *(int *)(this + 0x38c) = iVar4;
        (*pcVar2)(*(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x48) + 0x14) + 100),0,0,
                  *(undefined4 *)(this + 0x358));
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
    }
    (**(code **)(*(int *)this + 0xa4))();
    *(undefined4 *)(this + 0x38c) = 0;
    *(CHmsViewport **)(this + 0x35c) = param_1;
    *(CHmsViewport **)(this + 0x358) = this;
  }
  return;
}
}

// =================================================
// Function: CHmsViewport::OverlayAdd
// =================================================
void __thiscall
CHmsViewport::OverlayAdd
          (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3)
{
{
  CHmsZoneOverlay *pCVar1;
  TiXmlAttribute *unaff_ESI;
  void *this_00;
  CHmsViewport *pCVar2;
  
  pCVar2 = param_1;
  (**(code **)(*(int *)this + 0x164))();
  this_00 = (void *)(*(int *)(this + 0x238) + 0x18);
  pCVar1 = (CHmsZoneOverlay *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar2);
  if (pCVar1 < param_2) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add(this_00,(TiXmlAttributeSet *)&param_1,unaff_ESI);
    return;
  }
  CFastBuffer<class_CNetFileTransferUpload*>::InsertElemAt
            (this_00,(CFastBuffer<struct_CInputDevice::SRumble> *)param_2,(ulong)&param_1,
             (SRumble *)unaff_ESI);
  return;
}
}

// =================================================
// Function: CHmsViewport::OverlayRemove
// =================================================
int __thiscall
CHmsViewport::OverlayRemove(CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2)
{
{
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  GxTexCoordSet *unaff_EDI;
  CHmsZoneOverlay *pCVar2;
  
  pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     ((void *)(*(int *)(this + 0x238) + 0x18),
                      (CFastArray<class_GxTexCoordSet> *)&param_1,unaff_EDI);
  if (pCVar1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) {
    pCVar2 = param_2;
    (**(code **)(*(int *)this + 0x168))(param_2,0);
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt
              ((void *)(*(int *)(this + 0x238) + 0x18),pCVar1,1,(ulong)pCVar2);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CHmsViewport::OverlaySetIndex
// =================================================
void __thiscall
CHmsViewport::OverlaySetIndex
          (CHmsViewport *this,CHmsViewport *param_1,CHmsZoneOverlay *param_2,ulong param_3)
{
{
  int iVar1;
  ulong uVar2;
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar3;
  ulong uVar4;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  void *this_00;
  GxTexCoordSet *unaff_EDI;
  TiXmlAttribute *unaff_retaddr;
  
  iVar1 = *(int *)(this + 0x238);
  pCVar3 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     ((void *)(iVar1 + 0x18),(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_EDI);
  uVar2 = param_3;
  if ((pCVar3 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) &&
     (pCVar3 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)param_3)) {
    CFastBuffer<class_CTrackManiaEditorIcon*>::RemoveAt((void *)(iVar1 + 0x18),pCVar3,1,unaff_EBX);
    this_00 = (void *)(*(int *)(this + 0x238) + 0x18);
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if (uVar4 < uVar2) {
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (this_00,(TiXmlAttributeSet *)&stack0x00000010,unaff_retaddr);
      return;
    }
    CFastBuffer<class_CNetFileTransferUpload*>::InsertElemAt
              (this_00,(CFastBuffer<struct_CInputDevice::SRumble> *)uVar2,(ulong)&stack0x00000010,
               (SRumble *)unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CHmsViewport::PortalSetVisualLocation
// =================================================
void __thiscall
CHmsViewport::PortalSetVisualLocation(CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2)
{
{
  SCasterCat *this_00;
  SNewTriangleVert *pSVar1;
  ulong unaff_EBX;
  ulong unaff_EBP;
  CPlugTree *unaff_ESI;
  CHmsPortal *unaff_EDI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffd0;
  GmIso4 *in_stack_ffffffd4;
  GmIso4 *in_stack_ffffffd8;
  SPlugFaceCull local_1c [28];
  
  if (*(int *)(param_1 + 0x84) == 0) {
    CHmsPortal::RefreshPortal((CHmsPortal *)param_1,unaff_EDI);
  }
  CPlugTree::GetThisToRootTransfo
            (*(CPlugTree **)(param_1 + 0x84),(CPlugTree *)&stack0xffffffd4,(GmIso4 *)0x1,0,unaff_ESI
            );
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_EBP);
  this_00 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                      (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EBX)
  ;
  pSVar1 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this + 0x454,in_stack_ffffffd0);
  GmIso4::SetMult(this_00,local_1c,*(SPlugFaceCull **)(param_1 + 0x7c),in_stack_ffffffd4);
  GmIso4::SetMult(this_00 + 0x70,(SPlugFaceCull *)this_00,(SPlugFaceCull *)pSVar1,in_stack_ffffffd8)
  ;
  (**(code **)(*(int *)this + 0x1a4))();
  return;
}
}

// =================================================
// Function: CHmsViewport::RenderCorpus
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsViewport::RenderCorpus(CHmsViewport *this,CHmsViewport *param_1,CHmsCorpus *param_2)
{
{
  CHmsViewport *this_00;
  ulong uVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  SNewTriangleVert *pSVar6;
  ulong uVar7;
  undefined4 *puVar8;
  SCasterCat *pSVar9;
  SNewTriangleVert *pSVar10;
  SCasterCat *pSVar11;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar12;
  void *this_01;
  GxTexCoordSet *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmIso4 *unaff_ESI;
  CHmsCorpus *pCVar13;
  float *this_02;
  SPlugFaceCull *pSVar14;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  float *pfVar15;
  float10 fVar16;
  float10 extraout_ST0;
  GmVector3<unsigned_long> *pGVar17;
  CHmsCorpus *in_stack_0000000c;
  int in_stack_0000001c;
  ulong in_stack_ffffff64;
  ulong in_stack_ffffff68;
  GmIso4 *in_stack_ffffff6c;
  GmFrustumIso4 *in_stack_ffffff70;
  CPlugTree *in_stack_ffffff74;
  ulong in_stack_ffffff78;
  CHmsItem *in_stack_ffffff7c;
  GmVec3 *in_stack_ffffff80;
  GmVec3 *in_stack_ffffff84;
  GmIso3 *in_stack_ffffff88;
  GmVector3<unsigned_long> *pGVar18;
  GmVec3 *pGVar19;
  GmIso4 *in_stack_ffffffa0;
  SNewTriangleVert *in_stack_ffffffa4;
  SNewTriangleVert *this_03;
  float local_58;
  float fStack_54;
  float *pfStack_50;
  CHmsItem *pCStack_4c;
  SCasterCat *pSStack_48;
  GmIso3 *pGStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined4 local_34;
  undefined4 local_2c;
  SPlugFaceCull *pSStack_28;
  float fStack_24;
  SNewTriangleVert *pSStack_20;
  float fStack_1c;
  undefined1 auStack_14 [4];
  SPlugFaceCull aSStack_10 [16];
  
  iVar5 = CFastArray<class_CGameMenuFrame*>::Find
                    (this + 0x43c,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_EBX);
  pCVar13 = param_2;
  if (iVar5 != -1) {
    return;
  }
  *(CHmsCorpus **)(this + 0x38c) = param_2;
  uVar1 = *(ulong *)(param_2 + 0x48);
  if ((*(uint *)(uVar1 + 0x18) & 0x2000000) != 0) {
    pSVar6 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this + 0x454,unaff_EDI);
    pCVar13 = pCVar13 + 0x18;
    pfVar15 = &local_58;
    for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar15 = *(float *)pCVar13;
      pCVar13 = pCVar13 + 4;
      pfVar15 = pfVar15 + 1;
    }
    local_34 = *(undefined4 *)(pSVar6 + 0x54);
    local_2c = *(undefined4 *)(pSVar6 + 0x5c);
    CHmsCorpus::SetLocation(in_stack_0000000c,(CPlugTree *)&local_58,unaff_ESI);
  }
  if ((*(uint *)(uVar1 + 0x1c) & 0x8000) == 0) goto LAB_00531c08;
  if ((*(int *)(uVar1 + 0x24) != 0) &&
     (piVar2 = *(int **)(*(int *)(uVar1 + 0x24) + 4), piVar2 != (int *)0x0)) {
    iVar5 = *(int *)(this + 0x34c);
    in_stack_ffffff7c = (CHmsItem *)0x1;
    if (((iVar5 == 0) && (iVar5 = *(int *)(this + 0x350), iVar5 == 0)) ||
       ((**(code **)(*piVar2 + 0xc))(uVar1,iVar5,&stack0xffffff7c),
       in_stack_ffffff7c == (CHmsItem *)0x0)) goto LAB_00531936;
  }
  if ((*(ushort *)(this + 900) != 0) &&
     (*(ushort *)(this + 0x386) != (*(ushort *)(this + 900) & *(ushort *)(uVar1 + 0x20)))) {
LAB_00531936:
    *(undefined4 *)(this + 0x38c) = 0;
    return;
  }
  if ((*(int *)(uVar1 + 0x24) == 0) ||
     (piVar2 = *(int **)(*(int *)(uVar1 + 0x24) + 0x14), piVar2 == (int *)0x0)) {
    *(undefined4 *)(this + 0x3b4) = 0xffffffff;
  }
  else {
    uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x390,unaff_EBP);
    *(ulong *)(this + 0x3b4) = uVar7;
    CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
              (this + 0x390,
               (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                *)(uVar7 + 1),in_stack_ffffff64);
    unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x5318fc;
    in_stack_ffffff64 = uVar1;
    puVar8 = (undefined4 *)(**(code **)(*piVar2 + 0xc))();
    *puVar8 = *(undefined4 *)(this + 0x3b4);
  }
  uVar3 = *(uint *)(*(int *)(*(int *)(uVar1 + 0x14) + 100) + 0x9c);
  if (((uVar3 & 8) == 0) && ((((byte)this[0x414] & 4) == 0 || ((uVar3 & 0x4000) == 0))))
  goto LAB_00531936;
  pSVar6 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                     (this + 0x454,
                      (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                      unaff_EBP);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this + 0x538,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,in_stack_ffffff64);
  pSVar9 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                     (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      in_stack_ffffff68);
  puVar8 = (undefined4 *)(in_stack_0000001c + 0x18);
  pSVar11 = pSVar9;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pSVar11 = *puVar8;
    puVar8 = puVar8 + 1;
    pSVar11 = pSVar11 + 4;
  }
  GmIso4::SetMult(pSVar9 + 0x70,(SPlugFaceCull *)pSVar9,(SPlugFaceCull *)in_stack_ffffffa0,
                  in_stack_ffffff6c);
  (**(code **)(*(int *)this + 0x1a4))();
  if (*(int *)(this + 0x3c0) != 0) {
    *(int *)(this + 0x230) = in_stack_0000001c;
    *(undefined4 *)(this + 0x234) = 0;
  }
  piVar2 = *(int **)(in_stack_ffffffa4 + 0x54);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    pSVar10 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                        (this + 0x454,
                         (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                         pSVar9);
    pSVar9 = (SCasterCat *)0x5319f5;
    in_stack_ffffffa4 = pSVar10;
    CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
              (this + 0x460,
               (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
               in_stack_ffffff70);
    CFastBuffer<struct_SHmsRenderRect>::GetLastElem
              (this + 0x484,
               (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
               in_stack_ffffff74);
    in_stack_ffffff74 = (CPlugTree *)0x0;
    in_stack_ffffff70 = (GmFrustumIso4 *)0x531a18;
    pSVar11 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                        (this + 0x538,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         in_stack_ffffff78);
    pSStack_48 = pSVar11;
    if (piVar2[2] != 0) {
      if (piVar2[1] != 0) {
        in_stack_ffffff74 = (CPlugTree *)0x531a36;
        GmMat3::SetTranspose(pSVar11,(GmMat2 *)pSVar10,(GmMat2 *)in_stack_ffffff7c);
      }
      pfVar15 = pfStack_50;
      pGVar19 = (GmVec3 *)piVar2[4];
      this_02 = pfStack_50 + 0xd;
      in_stack_ffffff78 = 0x531a50;
      GmBoxAligned::GetDiag(this_02,(GmBoxAligned *)&stack0xffffffa0,in_stack_ffffff80);
      pSVar10 = in_stack_ffffffa4;
      if (in_stack_ffffffa0 == (GmIso4 *)0x0) {
        fVar16 = (float10)func_0x009c1b40();
        in_stack_ffffffa4 = (SNewTriangleVert *)(float)fVar16;
      }
      if (*(int *)pGVar19 == 0) {
        this_03 = (SNewTriangleVert *)*this_02;
        local_58 = pfVar15[0xe];
        fStack_54 = pfVar15[0xf];
        in_stack_ffffff7c = (CHmsItem *)0x531c3d;
        GmVec3::Mult(&stack0xffffffa4,(GmIso3 *)pSVar11,(GmIso3 *)in_stack_ffffff84);
        GmVec3::Mult(&local_58,pGStack_44,in_stack_ffffff88);
        pGVar18 = (GmVector3<unsigned_long> *)&fStack_54;
        pSVar10 = this_03;
        pGVar17 = (GmVector3<unsigned_long> *)GmFrustum::GetNearZ(this_03,(GmFrustum *)pCStack_4c);
        GmFunc::Max(this_01,pGVar17,pGVar18);
        GmFrustum::GetRectZ(this_03,(GmFrustum *)(float)extraout_ST0,(float)in_stack_ffffffa4,
                            (GmRectAligned *)pSVar6);
        fVar4 = fStack_54 + fStack_54;
        if (pSStack_48 == (SCasterCat *)0x0) {
          pCStack_4c = (CHmsItem *)(fStack_3c - (float)pGStack_44);
          fStack_54 = (fStack_38 - fStack_40) + (float)pCStack_4c;
          goto LAB_00531ae2;
        }
        pCStack_4c = (CHmsItem *)(fStack_3c - (float)pGStack_44);
        fStack_54 = fVar4 / (float)pCStack_4c;
LAB_00531abd:
        fVar4 = (pfStack_50[2] - *pfStack_50) * (float)_DAT_00b313b8;
      }
      else {
        in_stack_ffffff7c = (CHmsItem *)0x531aac;
        GmBoxAligned::GetDiag(pGVar19 + 4,(GmBoxAligned *)&stack0xffffffa4,in_stack_ffffff84);
        fVar4 = (float)pSVar6 + (float)pSVar6;
        if (pSVar10 != (SNewTriangleVert *)0x0) {
          fStack_54 = fVar4 / local_58;
          goto LAB_00531abd;
        }
        fStack_54 = fStack_54 + local_58;
LAB_00531ae2:
        fStack_54 = fVar4 / (fStack_54 * (float)_DAT_00b313b8);
        fVar4 = ((pfStack_50[3] - pfStack_50[1]) + (pfStack_50[2] - *pfStack_50)) *
                (float)_DAT_00b3d298;
      }
      fStack_54 = fVar4 * fStack_54;
      pfStack_50 = (float *)(1.0 - (float)piVar2[5] / fStack_54);
      fStack_24 = (float)pfStack_50 * (float)piVar2[7];
      pSStack_20 = (SNewTriangleVert *)((float)piVar2[8] * (float)pfStack_50);
      fStack_1c = (float)pfStack_50 * (float)piVar2[9];
      GmIso4::SetUScaleTrans
                (&stack0x00000018,(GmIso4 *)((float)piVar2[5] / fStack_54),(float)&fStack_24,pGVar19
                );
      GmIso4::SetMult(auStack_14,(SPlugFaceCull *)&stack0x0000001c,(SPlugFaceCull *)pSVar11,
                      in_stack_ffffffa0);
      in_stack_ffffffa4 = pSStack_20;
      pSVar14 = aSStack_10;
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pSVar11 = *(undefined4 *)pSVar14;
        pSVar14 = pSVar14 + 4;
        pSVar11 = pSVar11 + 4;
      }
      GmIso4::SetMult(pSStack_20 + 0x70,aSStack_10,pSStack_28,(GmIso4 *)pSVar10);
      (**(code **)(*(int *)this + 0x1a4))();
    }
  }
  this_00 = this + 0x46c;
  *(int *)(this + 0x38c) = in_stack_0000001c;
  pCVar12 = (CFastBuffer<class_CSystemFidsFolder*> *)
            CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_00,(CFastBuffer<class_CCrystalFace*> *)pSVar9);
  if (piVar2 != (int *)0x0) {
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,in_stack_ffffff70);
  }
  *(undefined4 *)(this + 0x3b8) = 0;
  iVar5 = RenderTree(this,(CHmsViewport *)in_stack_ffffffa4,in_stack_ffffff74);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount(this_00,pCVar12,in_stack_ffffff78);
  if (iVar5 != 0) {
    CHmsItem::OnVisible_WakeOrKeepAwake(pCStack_4c,in_stack_ffffff7c);
  }
  *(undefined4 *)(this + 0x3b4) = 0xffffffff;
LAB_00531c08:
  *(undefined4 *)(this + 0x38c) = 0;
  return;
}
}

// =================================================
// Function: CHmsViewport::RenderPortal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsViewport::RenderPortal
          (CHmsViewport *this,CHmsViewport *param_1,CHmsPortal *param_2,GmFrustum *param_3,
          int param_4)
{
{
  CHmsViewport *this_00;
  CHmsViewport *this_01;
  CHmsViewport *pCVar1;
  CHmsPortal *pCVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  SLoadedLight *pSVar7;
  SNewTriangleVert *pSVar8;
  int iVar9;
  SCasterCat *pSVar10;
  SCasterCat *pSVar11;
  GmScaleTrans2 *unaff_EBX;
  SHmsCameraLocation *unaff_EBP;
  GmFrustum *pGVar12;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  float in_stack_00000014;
  CMwCmdScriptVarBool *in_stack_00000018;
  float in_stack_0000001c;
  GmFrustum *in_stack_00000020;
  undefined4 uStack00000024;
  undefined4 in_stack_00000028;
  int in_stack_0000002c;
  int in_stack_00000034;
  int in_stack_ffffffb4;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffb8;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffbc;
  GmIso4 *in_stack_ffffffc0;
  CHmsZone *in_stack_ffffffc4;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffffc8;
  void *pvStack_30;
  int iStack_28;
  SNewTriangleVert *pSStack_24;
  int iStack_14;
  undefined4 uStack_10;
  float fStack_c;
  
  this_00 = this + 0x454;
  pSVar7 = CFastBuffer<struct_SHmsCameraLocation>::AddNewElem(this_00,unaff_EDI);
  *(int *)this_00 = *(int *)this_00 + -1;
  pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this_00,unaff_ESI);
  pGVar12 = param_3;
  CHmsPortal::TransformLocation
            ((CHmsPortal *)param_3,(CHmsPortal *)pSVar7,(SHmsCameraLocation *)pSVar8,unaff_EBP);
  GmIso4::SetInverse(pSVar7,(GmScaleTrans2 *)(pSVar7 + 0x30),unaff_EBX);
  (**(code **)(*(int *)this + 0x19c))();
  this_01 = this + 0x460;
  pSVar7 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::AddNewElem
                     (this_01,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pSVar7);
  *(int *)this_01 = *(int *)this_01 + -1;
  GmFrustum::Set(pSVar7,in_stack_00000018,in_stack_ffffffb4);
  if (in_stack_00000020 == (GmFrustum *)0x0) {
    iVar9 = (**(code **)(*(int *)this + 0x184))(pGVar12);
    if (iVar9 == 0) {
      PortalSetVisualLocation(this,(CHmsViewport *)pGVar12,(CHmsPortal *)in_stack_ffffffb8);
      if (*(int *)(pGVar12 + 0x84) == 0) {
        CHmsPortal::RefreshPortal((CHmsPortal *)pGVar12,(CHmsPortal *)in_stack_ffffffbc);
      }
      (**(code **)(*(int *)this + 0x170))(*(undefined4 *)(pGVar12 + 0x84));
      return;
    }
  }
  *(int *)this_00 = *(int *)this_00 + 1;
  *(int *)this_01 = *(int *)this_01 + 1;
  CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem(this_01,in_stack_ffffffb8);
  pSStack_24 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this_00,in_stack_ffffffbc);
  if (*(int *)(this + 0x2f4) != 0) {
    pSVar10 = CFastBuffer<struct_SHmsRenderRect>::operator[]
                        (this + 0x484,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)in_stack_ffffffc0);
    pSVar11 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                        (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                         (ulong)in_stack_ffffffc4);
    in_stack_00000014 = *(float *)(iStack_28 + 4);
    in_stack_00000018 = *(CMwCmdScriptVarBool **)(iStack_28 + 8);
    in_stack_0000001c = *(float *)(iStack_28 + 0x10);
    in_stack_00000020 = *(GmFrustum **)(iStack_28 + 0x14);
    fVar3 = (*(float *)(pSVar10 + 0x2c) - *(float *)(pSVar10 + 0x24)) /
            (*(float *)(pSVar11 + 0x10) - *(float *)(pSVar11 + 4));
    fVar4 = (*(float *)(pSVar10 + 0x30) - *(float *)(pSVar10 + 0x28)) /
            (*(float *)(pSVar11 + 0x14) - *(float *)(pSVar11 + 8));
    fVar5 = *(float *)(pSVar10 + 0x2c) + fVar3 * (in_stack_0000001c - *(float *)(pSVar11 + 0x10));
    fVar6 = *(float *)(pSVar10 + 0x30) +
            fVar4 * ((float)in_stack_00000020 - *(float *)(pSVar11 + 0x14));
    fStack_c = fVar5 - fVar3 * (in_stack_0000001c - in_stack_00000014);
    fVar3 = (float)*(int *)(this + 0x2a4);
    if (*(int *)(this + 0x2a4) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    pCVar1 = (CHmsViewport *)
             (int)ROUND(fVar3 * (1.0 - fVar5) * (float)_DAT_00b313b8 - (float)_DAT_00b313b8);
    if ((int)pCVar1 < 1) {
      param_1 = (CHmsViewport *)0x0;
    }
    else {
      param_1 = *(CHmsViewport **)(this + 0x2a4);
      if ((int)pCVar1 < (int)*(CHmsViewport **)(this + 0x2a4)) {
        param_1 = pCVar1;
      }
    }
    fVar3 = (float)*(int *)(this + 0x2a8);
    if (*(int *)(this + 0x2a8) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    pCVar2 = (CHmsPortal *)
             (int)ROUND(fVar3 * (1.0 - fVar6) * (float)_DAT_00b313b8 - (float)_DAT_00b313b8);
    if ((int)pCVar2 < 1) {
      param_2 = (CHmsPortal *)0x0;
    }
    else {
      param_2 = *(CHmsPortal **)(this + 0x2a8);
      if ((int)pCVar2 < (int)*(CHmsPortal **)(this + 0x2a8)) {
        param_2 = pCVar2;
      }
    }
    fVar3 = (float)*(int *)(this + 0x2a4);
    if (*(int *)(this + 0x2a4) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    pGVar12 = (GmFrustum *)
              (int)ROUND((float)_DAT_00b313b8 + fVar3 * (1.0 - fStack_c) * (float)_DAT_00b313b8);
    if ((int)pGVar12 < 1) {
      param_3 = (GmFrustum *)0x0;
    }
    else {
      param_3 = *(GmFrustum **)(this + 0x2a4);
      if ((int)pGVar12 < (int)*(GmFrustum **)(this + 0x2a4)) {
        param_3 = pGVar12;
      }
    }
    fVar3 = (float)*(int *)(this + 0x2a8);
    if (*(int *)(this + 0x2a8) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    pSStack_24 = (SNewTriangleVert *)
                 ((float)_DAT_00b313b8 +
                 fVar3 * (1.0 - (fVar6 - fVar4 * ((float)in_stack_00000020 -
                                                 (float)in_stack_00000018))) * (float)_DAT_00b313b8)
    ;
    in_stack_0000002c = (int)ROUND((float)pSStack_24);
    if (in_stack_0000002c < 1) {
      param_4 = 0;
    }
    else {
      param_4 = *(int *)(this + 0x2a8);
      if (in_stack_0000002c < *(int *)(this + 0x2a8)) {
        param_4 = in_stack_0000002c;
      }
    }
    in_stack_ffffffc4 = (CHmsZone *)&param_1;
    in_stack_ffffffc0 = (GmIso4 *)0x52dd02;
    (**(code **)(*(int *)this + 0x1b4))();
    pGVar12 = in_stack_00000020;
  }
  SClippingFrustum::ComputePlaneEqs
            (pvStack_30,(SClippingFrustum *)(pSStack_24 + 0x30),in_stack_ffffffc0);
  uStack00000024 = *(undefined4 *)(this + 0x3c0);
  *(undefined4 *)(this + 0x3c0) = 0;
  *(undefined4 *)(this + 0x38c) = 0;
  RenderZone(this,*(CHmsViewport **)(*(int *)(pGVar12 + 0x1c) + 0x80),in_stack_ffffffc4);
  *(int *)this_00 = *(int *)this_00 + -1;
  *(undefined4 *)(this + 0x3c0) = in_stack_00000028;
  pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this_00,in_stack_ffffffc8);
  *(uint *)(pSVar8 + 0xa0) = *(uint *)(pSVar8 + 0xa0) | 2;
  *(int *)this_01 = *(int *)this_01 + -1;
  if (iStack_14 != 0) {
    (**(code **)(*(int *)this + 0x1b4))(0);
  }
  if (in_stack_00000034 == 0) {
    *(undefined4 *)(this + 0x35c) = uStack_10;
    *(float *)(this + 0x38c) = fStack_c;
    (**(code **)(*(int *)this + 0x188))(pGVar12);
    *(undefined4 *)(this + 0x38c) = 0;
  }
  return;
}
}

// =================================================
// Function: CHmsViewport::RenderTree
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CHmsViewport::RenderTree(CHmsViewport *this,CHmsViewport *param_1,CPlugTree *param_2)
{
{
  SPlugFaceCull *pSVar1;
  float *this_00;
  CHmsViewport CVar2;
  SPlugVisibleId *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SNewTriangleVert *pSVar5;
  int iVar6;
  SPlugVisibleId *pSVar7;
  SNewTriangleVert *pSVar8;
  ulong uVar9;
  SNewTriangleVert *pSVar10;
  SNewTriangleVert *this_01;
  int iVar11;
  float fVar12;
  SCasterCat *pSVar13;
  CHmsViewport *pCVar14;
  float *pfVar15;
  SPlugFaceCull *pSVar16;
  SNewTriangleVert *pSVar17;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EBX;
  uint uVar18;
  CPlugVolumeProjector *unaff_EBP;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar19;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  int *piVar20;
  CHmsViewport *in_stack_00000010;
  int in_stack_00000020;
  int *in_stack_00000028;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffee4;
  GmIso4 *pGVar21;
  CFastBuffer<class_CCrystalFace*> *pCVar22;
  GmVec4 *pGVar23;
  SPlugFaceCull *pSVar24;
  undefined4 uVar25;
  GmIso4 *in_stack_fffffefc;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_ffffff04;
  SPlugFaceCull *in_stack_ffffff08;
  SPlugFaceCull *in_stack_ffffff0c;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar26;
  SNewTriangleVert *in_stack_ffffff14;
  SNewTriangleVert *in_stack_ffffff18;
  SNewTriangleVert *in_stack_ffffff1c;
  SNewTriangleVert *local_dc;
  SNewTriangleVert *local_d8;
  SNewTriangleVert *local_d4;
  SNewTriangleVert *local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  SNewTriangleVert *pSStack_c0;
  float fStack_bc;
  float local_b8;
  float fStack_b4;
  float local_b0;
  float local_ac;
  float fStack_a8;
  SNewTriangleVert *pSStack_a4;
  SNewTriangleVert *pSStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  float fStack_80;
  undefined4 uStack_7c;
  float fStack_78;
  float fStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  SNewTriangleVert *pSStack_64;
  float fStack_60;
  float fStack_5c;
  SNewTriangleVert *pSStack_58;
  int iStack_54;
  float fStack_50;
  SNewTriangleVert *pSStack_4c;
  float local_48;
  float local_44;
  SNewTriangleVert *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  CPlugVolumeProjector *local_30;
  float local_2c;
  undefined4 local_28;
  CPlugVolumeProjector *local_24;
  undefined4 local_20;
  SNewTriangleVert *local_1c;
  CPlugVolumeProjector *local_18;
  float local_14;
  SNewTriangleVert *local_10;
  CPlugVolumeProjector *local_c;
  int local_4;
  
  if (((*(uint *)(param_1 + 0x9c) & 8) == 0) &&
     ((((byte)this[0x414] & 4) == 0 || ((*(uint *)(param_1 + 0x9c) & 0x4000) == 0)))) {
    return 0;
  }
  pGVar21 = (GmIso4 *)0x52fe85;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem(this + 0x460,unaff_ESI);
  pSVar17 = (SNewTriangleVert *)(this + 0x538);
  pCVar22 = (CFastBuffer<class_CCrystalFace*> *)0x52fe9a;
  this_01 = pSVar17;
  pSVar5 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(pSVar17,unaff_EBX);
  if ((*(uint *)(param_1 + 0x9c) & 0x2000) == 0) {
    local_d8 = (SNewTriangleVert *)0x1;
    GmBoxAligned::SetMult
              (&local_b8,(SPlugFaceCull *)(param_1 + 0x34),(SPlugFaceCull *)(pSVar5 + 0x70),
               (GmIso4 *)unaff_EDI);
  }
  else {
    pSVar1 = (SPlugFaceCull *)(param_1 + 0x34);
    in_stack_ffffff18 =
         CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem(this + 0x460,unaff_EDI);
    local_dc = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                         (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                   *)unaff_EBP);
    unaff_EBP = (CPlugVolumeProjector *)(local_dc + 0x70);
    pGVar23 = (GmVec4 *)0x52fed9;
    pSVar24 = pSVar1;
    GmBoxAligned::SetMult(&local_b0,pSVar1,(SPlugFaceCull *)unaff_EBP,in_stack_fffffefc);
    if (*(int *)(this + 0x418) != 0) {
      in_stack_fffffefc = (GmIso4 *)0x0;
      unaff_EBP = (CPlugVolumeProjector *)&local_ac;
      pSVar24 = (SPlugFaceCull *)0x52fef2;
      iVar6 = GmFrustum::TestInter(this_01,unaff_EBP,(GmBoxAligned *)0x0,(GmIso4 *)pCVar4);
      if (iVar6 == 0) {
        local_c8 = 0.0;
        goto LAB_00530326;
      }
    }
    if (((*(int *)in_stack_ffffff04 == 0) && (*(int *)(this + 0x38c) != 0)) &&
       ((*(uint *)(*(int *)(*(int *)(this + 0x38c) + 0x48) + 0x18) & 0x600) != 0)) {
      uStack_68 = *(undefined4 *)(param_1 + 0x40);
      pSVar5 = *(SNewTriangleVert **)(in_stack_ffffff04 + 0x1c);
      pSStack_64 = *(SNewTriangleVert **)(param_1 + 0x44);
      pfVar15 = &fStack_60;
      in_stack_ffffff08 = (SPlugFaceCull *)&DAT_00000008;
      fStack_60 = *(float *)(param_1 + 0x48);
      fStack_5c = -*(float *)(param_1 + 0x40);
      pSStack_58 = *(SNewTriangleVert **)(param_1 + 0x44);
      iStack_54 = *(int *)(param_1 + 0x48);
      fStack_50 = *(float *)(param_1 + 0x40);
      pSStack_4c = (SNewTriangleVert *)-*(float *)(param_1 + 0x44);
      local_48 = *(float *)(param_1 + 0x48);
      local_44 = fStack_5c;
      local_40 = pSStack_4c;
      local_3c = *(undefined4 *)(param_1 + 0x48);
      local_38 = *(undefined4 *)(param_1 + 0x40);
      local_34 = *(undefined4 *)(param_1 + 0x44);
      unaff_EBP = (CPlugVolumeProjector *)-*(float *)(param_1 + 0x48);
      local_30 = unaff_EBP;
      local_2c = fStack_5c;
      local_28 = *(undefined4 *)(param_1 + 0x44);
      local_24 = unaff_EBP;
      local_20 = *(undefined4 *)(param_1 + 0x40);
      local_1c = pSStack_4c;
      local_10 = pSStack_4c;
      local_18 = unaff_EBP;
      local_c = unaff_EBP;
      local_14 = fStack_5c;
      do {
        pfVar15[-2] = *(float *)pSVar1 + pfVar15[-2];
        pfVar15[-1] = pfVar15[-1] + *(float *)(param_1 + 0x38);
        *pfVar15 = *pfVar15 + *(float *)(param_1 + 0x3c);
        GmVec3::Mult(pfVar15 + -2,(GmIso3 *)in_stack_ffffff0c,(GmIso3 *)in_stack_fffffee4);
        pfVar15 = pfVar15 + 3;
        in_stack_ffffff0c = in_stack_ffffff0c + -1;
      } while (in_stack_ffffff0c != (SPlugFaceCull *)0x0);
      in_stack_ffffff0c = (SPlugFaceCull *)0x0;
      if (in_stack_ffffff14 != (SNewTriangleVert *)0x0) {
        pSVar16 = in_stack_ffffff08 + 0x28;
        do {
          uVar18 = 0;
          pfVar15 = &fStack_5c;
          do {
            in_stack_fffffefc =
                 (GmIso4 *)
                 (*(float *)pSVar16 * *pfVar15 +
                  pfVar15[-1] * *(float *)(pSVar16 + -4) + pfVar15[-2] * *(float *)(pSVar16 + -8) +
                 *(float *)(pSVar16 + 4));
            if ((float)in_stack_fffffefc < 0.0 != ((float)in_stack_fffffefc == 0.0)) break;
            in_stack_fffffefc =
                 (GmIso4 *)
                 (pfVar15[3] * *(float *)pSVar16 +
                  pfVar15[2] * *(float *)(pSVar16 + -4) + pfVar15[1] * *(float *)(pSVar16 + -8) +
                 *(float *)(pSVar16 + 4));
            if ((float)in_stack_fffffefc < 0.0 != ((float)in_stack_fffffefc == 0.0)) {
              uVar18 = uVar18 + 1;
              break;
            }
            in_stack_fffffefc =
                 (GmIso4 *)
                 (pfVar15[6] * *(float *)pSVar16 +
                  pfVar15[5] * *(float *)(pSVar16 + -4) + pfVar15[4] * *(float *)(pSVar16 + -8) +
                 *(float *)(pSVar16 + 4));
            if ((float)in_stack_fffffefc < 0.0 != ((float)in_stack_fffffefc == 0.0)) {
              uVar18 = uVar18 + 2;
              break;
            }
            in_stack_fffffefc =
                 (GmIso4 *)
                 (pfVar15[9] * *(float *)pSVar16 +
                  pfVar15[8] * *(float *)(pSVar16 + -4) + pfVar15[7] * *(float *)(pSVar16 + -8) +
                 *(float *)(pSVar16 + 4));
            if ((float)in_stack_fffffefc < 0.0 != ((float)in_stack_fffffefc == 0.0)) {
              uVar18 = uVar18 + 3;
              break;
            }
            uVar18 = uVar18 + 4;
            pfVar15 = pfVar15 + 0xc;
          } while (uVar18 < 8);
          if (uVar18 == 8) goto LAB_005302fc;
          in_stack_ffffff0c = in_stack_ffffff0c + 1;
          pSVar16 = pSVar16 + 0x10;
        } while (in_stack_ffffff0c < in_stack_ffffff14);
      }
    }
    if (local_4 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(local_4 + 0x94);
      if ((iVar6 != 0) && (*(int *)(this + 0x448) != 0)) {
        iVar6 = (**(code **)(*(int *)this + 0x150))(iVar6);
      }
    }
    *(undefined4 *)(this + 0x430) = 0;
    uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x46c,in_stack_fffffee4);
    if ((uVar9 != 0) &&
       ((iVar6 == 0 ||
        (((*(uint *)(iVar6 + 0x1c) & 0x40000000) == 0 &&
         (((byte)*(uint *)(iVar6 + 0x1c) & 0x7c) < 0x78)))))) {
      GmIso4::UScaleSetInverse(&pSStack_64,(GmIso4 *)pSVar5,pGVar21);
      in_stack_ffffff18 =
           (SNewTriangleVert *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x46c,pCVar22);
      pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (in_stack_ffffff18 != (SNewTriangleVert *)0x0) {
        do {
          pSVar13 = CFastBuffer<class_GxColor>::operator[](this + 0x46c,pCVar19,(ulong)&fStack_5c);
          GmVec4::PlaneEqSetMult(&local_d4,(GmVec4 *)pSVar13,pGVar23,(GmIso4 *)pSVar24);
          fVar12 = local_c4 +
                   local_c8 * *(float *)(param_1 + 0x3c) +
                   local_cc * *(float *)(param_1 + 0x38) + (float)local_d0 * *(float *)pSVar1;
          in_stack_ffffff0c =
               (SPlugFaceCull *)
               (ABS(local_c8) * *(float *)(param_1 + 0x48) +
               ABS((float)local_d0) * *(float *)(param_1 + 0x40) +
               ABS(local_cc) * *(float *)(param_1 + 0x44));
          if (fVar12 < -(float)in_stack_ffffff0c) goto LAB_005302fc;
          if (fVar12 <= (float)in_stack_ffffff0c) {
            *(uint *)(this + 0x430) = *(uint *)(this + 0x430) | 1 << ((byte)pCVar19 & 0x1f);
          }
          else {
            *(uint *)(this + 0x430) = *(uint *)(this + 0x430) & ~(1 << ((byte)pCVar19 & 0x1f));
          }
          pCVar19 = pCVar19 + 1;
        } while (pCVar19 < this_01);
      }
    }
    local_d4 = (SNewTriangleVert *)0x1;
    param_1 = in_stack_00000010;
  }
LAB_00530326:
  if (local_d4 == (SNewTriangleVert *)0x0) {
    return 0;
  }
  if (((*(uint *)(param_1 + 0x9c) & 0x1000) != 0) &&
     ((pSVar3 = *(SPlugVisibleId **)(param_1 + 0x94), pSVar3 == (SPlugVisibleId *)0x0 ||
      ((iVar6 = SPlugVisibleFilterOptim::IsIdRejected
                          (this + 0x388,(SPlugVisibleFilterOptim *)(pSVar3 + 0x28),
                           (SPlugVisibleId *)unaff_EBP), iVar6 == 0 &&
       ((*(int *)(this + 0x448) == 0 ||
        (unaff_EBP = (CPlugVolumeProjector *)pSVar3,
        pSVar7 = (SPlugVisibleId *)(**(code **)(*(int *)this + 0x150))(), pSVar7 == pSVar3)))))))) {
    iVar6 = (**(code **)(*(int *)param_1 + 0xc))();
    if (iVar6 == 0x904f000) {
      if ((*(int *)(this + 0x38c) != 0) &&
         (uVar25 = *(undefined4 *)(*(int *)(this + 0x38c) + 0x48),
         in_stack_ffffff0c = (SPlugFaceCull *)DAT_00d67560, DAT_00d67560 != (SNewTriangleVert *)0x0)
         ) {
        CVar2 = in_stack_00000010[0x9c];
        pSVar5 = in_stack_ffffff14 + 0x70;
        piVar20 = &iStack_54;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar20 = *(int *)pSVar5;
          pSVar5 = pSVar5 + 4;
          piVar20 = piVar20 + 1;
        }
        if (((byte)CVar2 & 4) != 0) {
          GmIso4::LeftMult(&iStack_54,(GmScaleTrans2 *)(in_stack_00000010 + 0x5c),
                           (GmScaleTrans2 *)unaff_EBP);
        }
        (**(code **)(*(int *)in_stack_ffffff0c + 0xc))
                  (uVar25,in_stack_00000010,&iStack_54,*(undefined4 *)(this + 0x34c),
                   *(undefined4 *)(this + 0x414));
        param_1 = in_stack_00000010;
      }
    }
    else {
      uVar25 = *(undefined4 *)(this + 0x414);
      iVar6 = *(int *)param_1;
      pSVar5 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                         (this + 0x454,
                          (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *
                          )&local_d4);
      (**(code **)(iVar6 + 0xd4))
                (in_stack_ffffff0c,&local_b0,in_stack_ffffff18 + 0x70,pSVar5 + 0x30,uVar25);
    }
  }
  if (local_d4 == (SNewTriangleVert *)0x0) {
    return 0;
  }
  pSVar8 = (SNewTriangleVert *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pSVar17,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
  pSVar5 = pSVar8;
  if (((byte)param_1[0x9c] & 4) != 0) {
    uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (pSVar17,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffefc);
    in_stack_fffffefc = (GmIso4 *)(uVar9 + 1);
    CFastBuffer<struct_CHmsViewport::SVisualLocation>::SetSizeAtLeast
              (pSVar17,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)in_stack_fffffefc,
               (ulong)pCVar4);
    pSVar10 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(pSVar17,in_stack_ffffff04);
    *(int *)pSVar17 = *(int *)pSVar17 + 1;
    in_stack_ffffff1c =
         CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                   (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                             *)in_stack_ffffff08);
    *(uint *)(pSVar10 + 0xa0) = *(uint *)(pSVar10 + 0xa0) | 1;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x5304bc;
    pSVar5 = this_01;
    GmIso4::SetMult(in_stack_ffffff1c,(SPlugFaceCull *)(param_1 + 0x5c),(SPlugFaceCull *)pSVar10,
                    (GmIso4 *)in_stack_ffffff0c);
    in_stack_ffffff08 = (SPlugFaceCull *)(param_1 + 0x5c);
    in_stack_ffffff04 =
         (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x5304d0;
    this_01 = pSVar5;
    GmIso4::SetMult(pSVar5 + 0x70,in_stack_ffffff08,(SPlugFaceCull *)(pSVar10 + 0x70),
                    (GmIso4 *)pSVar8);
    in_stack_ffffff0c = (SPlugFaceCull *)0x5304de;
    (**(code **)(*(int *)this + 0x1a4))();
  }
  if ((*(uint *)(param_1 + 0x9c) & 0x100) != 0) {
    pCVar26 = *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)
               (this + 0x344);
    local_b0 = 0.0;
    local_ac = 0.0;
    fStack_a8 = 0.0;
    local_cc = (1.0 / (float)pCVar26 + 1.0) * (float)_DAT_00b313b8;
    local_c8 = (float)_DAT_00b313b8 * ((float)pCVar26 + 1.0);
    local_c4 = 1.0;
    GmIso4::SetNUScaleTrans
              (&fStack_50,(GmIso4 *)&local_cc,(GmVec3 *)&local_b0,(GmVec3 *)in_stack_fffffefc);
    uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (pSVar17,(CFastBuffer<class_CCrystalFace*> *)pCVar4);
    if (((byte)param_1[0x9c] & 4) == 0) {
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar9 + 1);
      in_stack_fffffefc = (GmIso4 *)0x5305ad;
      CFastBuffer<struct_CHmsViewport::SVisualLocation>::SetSizeAtLeast
                (pSVar17,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)pCVar4,
                 (ulong)in_stack_ffffff04);
      pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                         (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                   *)in_stack_ffffff08);
      *(int *)pSVar17 = *(int *)pSVar17 + 1;
      this_01 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(pSVar17,pCVar26);
      *(uint *)(pSVar8 + 0xa0) = *(uint *)(pSVar8 + 0xa0) | 1;
      in_stack_ffffff04 =
           (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x5305db;
      GmIso4::SetMult(this_01,(SPlugFaceCull *)&local_3c,(SPlugFaceCull *)pSVar8,(GmIso4 *)pSVar5);
      pSVar8 = pSVar8 + 0x70;
      in_stack_ffffff0c = (SPlugFaceCull *)&local_38;
    }
    else {
      pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar9 - 2);
      in_stack_fffffefc = (GmIso4 *)0x530561;
      CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                (pSVar17,pCVar4,(ulong)in_stack_ffffff04);
      pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                         (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                   *)in_stack_ffffff08);
      local_d8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(this + 0x454,pCVar26);
      in_stack_ffffff04 =
           (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x530590;
      GmMat3::SetMult(pSVar8,(SPlugFaceCull *)(param_1 + 0x5c),(SPlugFaceCull *)&local_3c,
                      (GmIso4 *)pSVar5);
      in_stack_ffffff0c = (SPlugFaceCull *)0x53059c;
      GmMat3::Mult(pSVar8,(GmIso3 *)local_dc,(GmIso3 *)in_stack_ffffff14);
      local_dc = pSVar8;
      in_stack_ffffff14 = local_d0;
    }
    in_stack_ffffff08 = (SPlugFaceCull *)0x5305f3;
    GmIso4::SetMult(local_dc + 0x70,in_stack_ffffff0c,(SPlugFaceCull *)pSVar8,
                    (GmIso4 *)in_stack_ffffff14);
    pSVar5 = (SNewTriangleVert *)0x530601;
    (**(code **)(*(int *)this + 0x1a4))();
    in_stack_ffffff14 = local_dc;
  }
  if (((byte)param_1[0x9c] & 0x40) != 0) {
    *(CHmsViewport **)(this + 0x234) = param_1;
  }
  local_dc = (SNewTriangleVert *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (param_1 + 0x28,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffefc);
  iVar6 = *(int *)(param_1 + 0x90);
  if (((iVar6 == 0) || (*(int *)(param_1 + 0x94) == 0)) ||
     ((*(int *)(this + 0x24) != 0 && (((byte)param_1[0x9c] & 1) != 0)))) goto LAB_00530dd2;
  if (((*(uint *)(param_1 + 0x9c) & 0x2000) == 0) ||
     (((*(int *)(param_1 + 0x8c) == 0 && (local_dc == (SNewTriangleVert *)0x0)) &&
      (*(int *)(iVar6 + 0x4c) == 0)))) {
    if (local_cc == 0.0) goto LAB_00530dd2;
  }
  else {
    pCVar22 = *(CFastBuffer<class_CCrystalFace*> **)(iVar6 + 0x4c);
    pSVar1 = (SPlugFaceCull *)(iVar6 + 0x34);
    local_dc = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
                         (this + 0x460,
                          (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *
                          )pCVar4);
    pSVar8 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(pSVar17,in_stack_ffffff04);
    pSVar24 = (SPlugFaceCull *)(pSVar8 + 0x70);
    GmBoxAligned::SetMult(&local_44,pSVar1,pSVar24,(GmIso4 *)in_stack_ffffff08);
    if (*(int *)(this + 0x418) == 0) {
LAB_005306c8:
      if (((*(int *)local_d0 == 0) && (*(int *)(this + 0x38c) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(this + 0x38c) + 0x48) + 0x18) & 0x600) != 0)) {
        fStack_9c = *(float *)(iVar6 + 0x40);
        local_c8 = *(float *)(local_d0 + 0x1c);
        fStack_98 = *(float *)(iVar6 + 0x44);
        pfVar15 = &fStack_94;
        local_d4 = (SNewTriangleVert *)&DAT_00000008;
        fStack_94 = *(float *)(iVar6 + 0x48);
        fStack_90 = -*(float *)(iVar6 + 0x40);
        uStack_8c = *(undefined4 *)(iVar6 + 0x44);
        uStack_88 = *(undefined4 *)(iVar6 + 0x48);
        uStack_84 = *(undefined4 *)(iVar6 + 0x40);
        fStack_80 = -*(float *)(iVar6 + 0x44);
        uStack_7c = *(undefined4 *)(iVar6 + 0x48);
        fStack_78 = fStack_90;
        fStack_74 = fStack_80;
        uStack_70 = *(undefined4 *)(iVar6 + 0x48);
        uStack_6c = *(undefined4 *)(iVar6 + 0x40);
        uStack_68 = *(undefined4 *)(iVar6 + 0x44);
        this_01 = (SNewTriangleVert *)-*(float *)(iVar6 + 0x48);
        pSStack_64 = this_01;
        fStack_60 = fStack_90;
        fStack_5c = *(float *)(iVar6 + 0x44);
        pSStack_58 = this_01;
        iStack_54 = *(int *)(iVar6 + 0x40);
        fStack_50 = fStack_80;
        local_44 = fStack_80;
        pSStack_4c = this_01;
        local_40 = this_01;
        local_48 = fStack_90;
        do {
          this_00 = pfVar15 + -2;
          *this_00 = *(float *)pSVar1 + *this_00;
          pfVar15[-1] = pfVar15[-1] + *(float *)(iVar6 + 0x38);
          *pfVar15 = *pfVar15 + *(float *)(iVar6 + 0x3c);
          GmVec3::Mult(this_00,(GmIso3 *)pSVar8,(GmIso3 *)pSVar24);
          pfVar15 = pfVar15 + 3;
          local_dc = local_dc + -1;
        } while (local_dc != (SNewTriangleVert *)0x0);
        local_dc = (SNewTriangleVert *)0x0;
        if (local_d0 != (SNewTriangleVert *)0x0) {
          pSVar17 = local_d8 + 0x28;
          do {
            uVar18 = 0;
            pfVar15 = &fStack_9c;
            do {
              pCVar22 = (CFastBuffer<class_CCrystalFace*> *)
                        (*(float *)pSVar17 * *pfVar15 +
                         pfVar15[-1] * *(float *)(pSVar17 + -4) +
                         pfVar15[-2] * *(float *)(pSVar17 + -8) + *(float *)(pSVar17 + 4));
              if ((float)pCVar22 < 0.0 != ((float)pCVar22 == 0.0)) break;
              pCVar22 = (CFastBuffer<class_CCrystalFace*> *)
                        (pfVar15[3] * *(float *)pSVar17 +
                         pfVar15[1] * *(float *)(pSVar17 + -8) +
                         pfVar15[2] * *(float *)(pSVar17 + -4) + *(float *)(pSVar17 + 4));
              if ((float)pCVar22 < 0.0 != ((float)pCVar22 == 0.0)) {
                uVar18 = uVar18 + 1;
                break;
              }
              pCVar22 = (CFastBuffer<class_CCrystalFace*> *)
                        (pfVar15[6] * *(float *)pSVar17 +
                         pfVar15[4] * *(float *)(pSVar17 + -8) +
                         pfVar15[5] * *(float *)(pSVar17 + -4) + *(float *)(pSVar17 + 4));
              if ((float)pCVar22 < 0.0 != ((float)pCVar22 == 0.0)) {
                uVar18 = uVar18 + 2;
                break;
              }
              pCVar22 = (CFastBuffer<class_CCrystalFace*> *)
                        (pfVar15[9] * *(float *)pSVar17 +
                         pfVar15[7] * *(float *)(pSVar17 + -8) +
                         pfVar15[8] * *(float *)(pSVar17 + -4) + *(float *)(pSVar17 + 4));
              if ((float)pCVar22 < 0.0 != ((float)pCVar22 == 0.0)) {
                uVar18 = uVar18 + 3;
                break;
              }
              uVar18 = uVar18 + 4;
              pfVar15 = pfVar15 + 0xc;
            } while (uVar18 < 8);
            if (uVar18 == 8) goto LAB_00530db0;
            local_dc = local_dc + 1;
            pSVar17 = pSVar17 + 0x10;
          } while (local_dc < local_d0);
        }
      }
      local_cc = *(float *)(in_stack_00000020 + 0x94);
      if ((local_cc != 0.0) && (*(int *)(this + 0x448) != 0)) {
        local_cc = (float)(**(code **)(*(int *)this + 0x150))(local_cc);
      }
      if (((this_01 != (SNewTriangleVert *)0x0) &&
          (uVar18 = *(uint *)(this + 0x414) >> 9 & 3, uVar18 < 2)) &&
         ((local_cc == 0.0 || ((*(uint *)((int)local_cc + 0x1c) & 0x400) == 0)))) {
        pSVar10 = CFastBuffer<struct_SHmsCameraProjection>::GetLastElem
                            (this + 0x478,
                             (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                              *)in_stack_ffffff08);
        pSVar17 = local_dc + uVar18 * 0x1c;
        fStack_bc = *(float *)(pSVar8 + 8) * *(float *)(pSVar17 + 8) +
                    *(float *)pSVar8 * *(float *)pSVar17 +
                    *(float *)(local_dc + uVar18 * 0x1c + 4) * *(float *)(pSVar8 + 4) +
                    *(float *)(pSVar8 + 0x24);
        local_b8 = *(float *)(pSVar8 + 0x14) * *(float *)(pSVar17 + 8) +
                   *(float *)(pSVar17 + 4) * *(float *)(pSVar8 + 0x10) +
                   *(float *)(pSVar8 + 0xc) * *(float *)pSVar17 + *(float *)(pSVar8 + 0x28);
        fStack_b4 = *(float *)(pSVar8 + 0x20) * *(float *)(pSVar17 + 8) +
                    *(float *)(pSVar17 + 4) * *(float *)(pSVar8 + 0x1c) +
                    *(float *)(pSVar8 + 0x18) * *(float *)pSVar17 + *(float *)(pSVar8 + 0x2c);
        local_b0 = *(float *)(pSVar17 + 0x14) * *(float *)(pSVar8 + 8) +
                   *(float *)(pSVar17 + 0x10) * *(float *)(pSVar8 + 4) +
                   *(float *)pSVar8 * *(float *)(pSVar17 + 0xc);
        local_ac = *(float *)(pSVar17 + 0x14) * *(float *)(pSVar8 + 0x14) +
                   *(float *)(pSVar8 + 0xc) * *(float *)(pSVar17 + 0xc) +
                   *(float *)(pSVar17 + 0x10) * *(float *)(pSVar8 + 0x10);
        fStack_a8 = *(float *)(pSVar17 + 0x14) * *(float *)(pSVar8 + 0x20) +
                    *(float *)(pSVar8 + 0x18) * *(float *)(pSVar17 + 0xc) +
                    *(float *)(pSVar17 + 0x10) * *(float *)(pSVar8 + 0x1c);
        pSStack_a4 = *(SNewTriangleVert **)(pSVar17 + 0x18);
        pSVar17 = pSStack_c0;
        if ((*(uint *)(pSVar10 + 0xcc) & 2) == 0) {
          if ((*(uint *)(pSVar10 + 0xcc) & 4) == 0) {
            if (*(int *)local_d4 == 0) {
              pSVar17 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                                  (this + 0x454,
                                   (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                    *)pSVar5);
              fStack_9c = *(float *)(pSVar17 + 0x54) - local_b8;
              fStack_98 = *(float *)(pSVar17 + 0x58) - fStack_b4;
              fStack_94 = *(float *)(pSVar17 + 0x5c) - local_b0;
              local_d4 = (SNewTriangleVert *)
                         (fStack_94 * (float)pSStack_a4 +
                         fStack_9c * local_ac + fStack_98 * fStack_a8);
              if ((int)((uint)pSStack_a0 ^ (uint)local_d4) < 0) {
                uVar18 = ~(uint)local_d4;
                this_01 = pSStack_a0;
              }
              else {
                uVar18 = ~(uint)local_d4 ^
                         (uint)((float)local_d4 * (float)local_d4 -
                               (fStack_9c * fStack_9c + fStack_98 * fStack_98 +
                               fStack_94 * fStack_94) * (float)pSStack_a0 * (float)pSStack_a0);
                this_01 = local_d4;
              }
              if ((int)uVar18 < 0) {
                fVar12 = 0.0;
                pSVar17 = pSStack_c0;
                goto LAB_00530d78;
              }
            }
          }
          else {
            in_stack_ffffff1c =
                 (SNewTriangleVert *)
                 (*(float *)(pSVar10 + 200) * fStack_a8 +
                 *(float *)(pSVar10 + 0xc0) * local_b0 + *(float *)(pSVar10 + 0xc4) * local_ac);
            if ((float)pSStack_a4 < -(float)in_stack_ffffff1c !=
                ((float)pSStack_a4 == -(float)in_stack_ffffff1c)) {
              fVar12 = 0.0;
              goto LAB_00530d78;
            }
          }
        }
        else {
          pSStack_a0 = (SNewTriangleVert *)(*(float *)(pSVar10 + 0xc0) - fStack_bc);
          fStack_9c = *(float *)(pSVar10 + 0xc4) - local_b8;
          fStack_98 = *(float *)(pSVar10 + 200) - fStack_b4;
          local_dc = (SNewTriangleVert *)
                     (fStack_98 * fStack_a8 + fStack_9c * local_ac + (float)pSStack_a0 * local_b0);
          if ((int)((uint)pSStack_a4 ^ (uint)local_dc) < 0) {
            uVar18 = ~(uint)local_dc;
            in_stack_ffffff1c = pSStack_a4;
          }
          else {
            pSVar10 = (SNewTriangleVert *)
                      ((float)local_dc * (float)local_dc -
                      ((float)pSStack_a0 * (float)pSStack_a0 + fStack_9c * fStack_9c +
                      fStack_98 * fStack_98) * (float)pSStack_a4 * (float)pSStack_a4);
            uVar18 = ~(uint)local_dc ^ (uint)pSVar10;
            in_stack_ffffff1c = local_dc;
            local_dc = pSVar10;
          }
          if ((int)uVar18 < 0) {
            fVar12 = 0.0;
            goto LAB_00530d78;
          }
        }
      }
      *(undefined4 *)(this + 0x430) = 0;
      uVar9 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0x46c,(CFastBuffer<class_CCrystalFace*> *)pSVar5);
      if ((uVar9 != 0) &&
         ((pSStack_c0 == (SNewTriangleVert *)0x0 ||
          (((*(uint *)(pSStack_c0 + 0x1c) & 0x40000000) == 0 &&
           (((byte)*(uint *)(pSStack_c0 + 0x1c) & 0x7c) < 0x78)))))) {
        GmIso4::UScaleSetInverse(&fStack_98,(GmIso4 *)pSVar8,(GmIso4 *)in_stack_ffffff14);
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x46c,pCVar22);
        pCVar19 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        pSVar5 = pSVar8;
        if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
          do {
            pSVar5 = (SNewTriangleVert *)0x530cc1;
            pSVar13 = CFastBuffer<class_GxColor>::operator[](this + 0x46c,pCVar19,(ulong)&fStack_90)
            ;
            GmVec4::PlaneEqSetMult
                      (&fStack_a8,(GmVec4 *)pSVar13,(GmVec4 *)in_stack_ffffff1c,(GmIso4 *)this_01);
            local_c4 = fStack_98 +
                       fStack_9c * *(float *)(iVar6 + 0x3c) +
                       (float)pSStack_a4 * *(float *)pSVar1 +
                       (float)pSStack_a0 * *(float *)(iVar6 + 0x38);
            local_cc = ABS(fStack_9c) * *(float *)(iVar6 + 0x48) +
                       ABS((float)pSStack_a0) * *(float *)(iVar6 + 0x44) +
                       ABS((float)pSStack_a4) * *(float *)(iVar6 + 0x40);
            if (local_c4 < -local_cc) goto LAB_00530db0;
            if (local_c4 <= local_cc) {
              *(uint *)(this + 0x430) = *(uint *)(this + 0x430) | 1 << ((byte)pCVar19 & 0x1f);
            }
            else {
              *(uint *)(this + 0x430) = *(uint *)(this + 0x430) & ~(1 << ((byte)pCVar19 & 0x1f));
            }
            pCVar19 = pCVar19 + 1;
          } while (pCVar19 < pCVar4);
        }
      }
      fVar12 = 1.4013e-45;
      pSVar17 = pSStack_c0;
    }
    else {
      in_stack_ffffff08 = (SPlugFaceCull *)0x0;
      pSVar24 = (SPlugFaceCull *)&local_40;
      iVar11 = GmFrustum::TestInter
                         (local_d4,(CPlugVolumeProjector *)pSVar24,(GmBoxAligned *)0x0,
                          (GmIso4 *)in_stack_ffffff0c);
      fVar12 = 0.0;
      if (iVar11 != 0) goto LAB_005306c8;
    }
LAB_00530d78:
    fStack_bc = fVar12;
    if (fVar12 == 0.0) {
      if (local_cc == 0.0) {
        if (*(SNewTriangleVert **)pSVar17 != local_dc) {
          *(SNewTriangleVert **)pSVar17 = local_dc;
          pSVar17 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                              (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                        *)pSVar5);
          *(uint *)(pSVar17 + 0xa0) = *(uint *)(pSVar17 + 0xa0) | 1;
        }
        return 0;
      }
      goto LAB_00530dd2;
    }
  }
  (**(code **)(*(int *)this + 0x170))(in_stack_00000028);
LAB_00530dd2:
  iVar6 = in_stack_00000028[0xb];
  uVar25 = *(undefined4 *)(this + 0x234);
  fVar12 = 0.0;
  if (local_cc != 0.0) {
    do {
      RenderTree(this,*(CHmsViewport **)(iVar6 + (int)fVar12 * 4),(CPlugTree *)pSVar5);
      fVar12 = (float)((int)fVar12 + 1);
      *(undefined4 *)(this + 0x234) = uVar25;
    } while ((uint)fVar12 < (uint)local_c8);
  }
  pCVar14 = (CHmsViewport *)(**(code **)(*in_stack_00000028 + 0xd0))();
  if (pCVar14 != (CHmsViewport *)0x0) {
    RenderTree(this,pCVar14,(CPlugTree *)pSVar5);
    *(undefined4 *)(this + 0x234) = uVar25;
  }
  if (*(SNewTriangleVert **)pSVar17 != local_dc) {
    *(SNewTriangleVert **)pSVar17 = local_dc;
    pSVar17 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                        (pSVar17,(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                  *)pSVar5);
    *(uint *)(pSVar17 + 0xa0) = *(uint *)(pSVar17 + 0xa0) | 1;
  }
  return 1;
LAB_005302fc:
  local_d4 = (SNewTriangleVert *)0x0;
  param_1 = in_stack_00000010;
  goto LAB_00530326;
LAB_00530db0:
  fVar12 = 0.0;
  pSVar17 = pSStack_c0;
  goto LAB_00530d78;
}
}

// =================================================
// Function: CHmsViewport::RenderVisibleZone2ds
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CHmsViewport::RenderVisibleZone2ds
          (CHmsViewport *this,CHmsViewport *param_1,CFastBuffer<class_CHmsZoneOverlay*> *param_2,
          int param_3)
{
{
  code *pcVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  SNewTriangleVert *pSVar6;
  int iVar7;
  TiXmlAttributeSet *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  undefined4 *puVar9;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  ulong unaff_retaddr;
  undefined *in_stack_00000010;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_00000014;
  CHmsViewport *pCVar10;
  
  pCVar10 = this;
  if ((_DAT_00d6750c & 1) == 0) {
    _DAT_00d6750c = _DAT_00d6750c | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d67500,unaff_EDI);
    _atexit(`protected:_void___thiscall_CHmsViewport::
            RenderVisibleZone2ds(class_CFastBuffer<class_CHmsZoneOverlay*>&,int)'::__l2::
            _dynamic_atexit_destructor_for__VisibleZone2ds__);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d67500,unaff_ESI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)param_3,unaff_EBP);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)param_3,pCVar8,(ulong)unaff_EBX);
      in_stack_00000014 =
           *(CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> **)pSVar3;
      if (*(int *)(in_stack_00000014 + 0x18) != 0) {
        unaff_EBX = (TiXmlAttributeSet *)&stack0x00000014;
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (&DAT_00d67500,unaff_EBX,(TiXmlAttribute *)pCVar10);
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar2);
  }
  if ((((in_stack_00000014 !=
         (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)0x0) &&
       (*(ulong *)(this + 0x33c) != 0)) && (*(int *)(this + 0x29c) != 0)) &&
     (*(int *)(PTR_DAT_00cdae90 + 0xc) != 0)) {
    in_stack_00000010 = (undefined *)*(ulong *)(this + 0x33c);
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d67500,(TiXmlAttributeSet *)&stack0x00000010,(TiXmlAttribute *)unaff_EBX);
  }
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (&DAT_00d67500,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
  if (uVar4 != 0) {
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x454,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)pCVar10);
    pSVar5 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                       (this + 0x454,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        unaff_retaddr);
    puVar9 = &DAT_00d670f8;
    pSVar3 = pSVar5;
    for (iVar7 = 0x29; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pSVar3 = *puVar9;
      puVar9 = puVar9 + 1;
      pSVar3 = pSVar3 + 4;
    }
    *(uint *)(pSVar5 + 0xa0) = *(uint *)(pSVar5 + 0xa0) & 0xfffffffd;
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x460,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,(ulong)param_1);
    pSVar3 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::operator[]
                       (this + 0x460,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)pCVar2);
    puVar9 = &DAT_00d67340;
    for (iVar7 = 0x4e; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pSVar3 = *puVar9;
      puVar9 = puVar9 + 1;
      pSVar3 = pSVar3 + 4;
    }
    CFastBuffer<class_CSystemFidsFolder*>::SetCount
              (this + 0x478,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,param_3);
    pSVar3 = CFastBuffer<struct_SHmsCameraProjection>::operator[]
                       (this + 0x478,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)in_stack_00000010);
    puVar9 = &DAT_00d671a0;
    if (((byte)this[0x414] & 2) == 0) {
      puVar9 = &DAT_00d67270;
    }
    pSVar5 = pSVar3;
    for (iVar7 = 0x34; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)pSVar5 = *puVar9;
      puVar9 = puVar9 + 1;
      pSVar5 = pSVar5 + 4;
    }
    *(uint *)(pSVar3 + 0xcc) = *(uint *)(pSVar3 + 0xcc) & 0xfffffffe;
    in_stack_00000010 = (undefined *)0x52d599;
    pSVar6 = CFastBuffer<struct_SHmsRenderRect>::GetLastElem(this + 0x484,in_stack_00000014);
    *(undefined4 *)pSVar6 = 0;
    in_stack_00000010 = &DAT_00d67500;
    *(undefined4 *)(pSVar6 + 4) = 0x3f800000;
    *(undefined2 *)(this + 900) = 0;
    *(undefined2 *)(this + 0x386) = 0;
    *(undefined2 *)(this + 0x388) = 0;
    *(undefined2 *)(this + 0x38a) = 0;
    pcVar1 = *(code **)(*(int *)this + 0x194);
    *(undefined4 *)(this + 0x450) = 3;
    (*pcVar1)();
    *(undefined4 *)(this + 0x358) = 0;
    *(undefined4 *)(this + 0x35c) = 0;
  }
  return;
}
}

// =================================================
// Function: CHmsViewport::RenderZone
// =================================================
void __thiscall CHmsViewport::RenderZone(CHmsViewport *this,CHmsViewport *param_1,CHmsZone *param_2)
{
{
  int iVar1;
  code *pcVar2;
  SLoadedLight *pSVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  SNewTriangleVert *pSVar6;
  int iVar7;
  GmFrustum *unaff_EBX;
  CHmsPortal *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CHmsViewport *pCVar9;
  undefined4 in_stack_00000014;
  CHmsZone *in_stack_ffffffb0;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *pCVar10;
  GmIso4 *pGVar11;
  GmIso4 *pGVar12;
  CHmsPortal *this_00;
  GmIso4 *in_stack_ffffffc4;
  SLoadedLight *pSVar13;
  SLoadedLight *pSVar14;
  SLoadedLight *local_34;
  int local_30;
  CHmsViewport *local_2c;
  CPlugVisual *pCStack_28;
  GmFrustum *local_24;
  SNewTriangleVert *pSStack_20;
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  ulong uStack_10;
  CHmsPortal aCStack_c [12];
  
  *(undefined4 *)(this + 0x430) = 0;
  *(CHmsViewport **)(this + 0x35c) = param_1;
  if (*(int *)(this + 0x41c) == 0) {
    local_30 = *(int *)(param_1 + 0x44);
    in_stack_ffffffb0 = (CHmsZone *)0x52d682;
    local_34 = (SLoadedLight *)CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x40,unaff_EDI);
  }
  pSVar14 = (SLoadedLight *)0x0;
  pCVar9 = param_1;
  if (local_34 != (SLoadedLight *)0x0) {
    do {
      iVar1 = *(int *)(local_2c + (int)pSVar14 * 4);
      local_24 = *(GmFrustum **)(*(int *)(iVar1 + 0x48) + 0x30);
      if (local_24 != (GmFrustum *)0x0) {
        pCVar9 = this + 0x454;
        pCVar10 = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                  0x52d6c6;
        pSVar3 = CFastBuffer<struct_SHmsCameraLocation>::AddNewElem(pCVar9,unaff_ESI);
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (pCVar9,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
        pSVar5 = CFastBuffer<struct_CHmsViewport::SVisualLocation>::operator[]
                           (pCVar9,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar4 - 2),
                            (ulong)unaff_EBX);
        *(uint *)(pSVar3 + 0xa0) =
             *(uint *)(pSVar3 + 0xa0) ^ (*(uint *)(pSVar5 + 0xa0) ^ *(uint *)(pSVar3 + 0xa0)) & 1;
        unaff_EBP = (CHmsPortal *)(iVar1 + 0x18);
        unaff_ESI = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x52d6fb;
        GmIso4::SetMult(pSVar3,(SPlugFaceCull *)unaff_EBP,(SPlugFaceCull *)pSVar5,in_stack_ffffffc4)
        ;
        unaff_EBX = (GmFrustum *)0x52d704;
        GmIso4::SetInverse(pSVar3 + 0x30,(GmScaleTrans2 *)pSVar3,(GmScaleTrans2 *)pSVar14);
        in_stack_ffffffc4 = (GmIso4 *)0x52d711;
        (**(code **)(*(int *)this + 0x19c))();
        RenderZone(this,local_2c,in_stack_ffffffb0);
        *(int *)pCVar9 = *(int *)pCVar9 + -1;
        in_stack_ffffffb0 = (CHmsZone *)0x52d727;
        pSVar14 = pSVar3;
        pSVar6 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem(pCVar9,pCVar10);
        *(uint *)(pSVar6 + 0xa0) = *(uint *)(pSVar6 + 0xa0) | 2;
        pCVar9 = (CHmsViewport *)param_2;
      }
      pSVar14 = pSVar14 + 1;
    } while (pSVar14 < local_34);
  }
  pcVar2 = *(code **)(*(int *)this + 0x180);
  *(CHmsViewport **)(this + 0x35c) = pCVar9;
  pGVar11 = (GmIso4 *)pCVar9;
  (*pcVar2)();
  if ((*(int *)(this + 0x24) != 0) && (pSVar3 = (SLoadedLight *)0x0, pSVar14 != (SLoadedLight *)0x0)
     ) {
    do {
      local_24 = *(GmFrustum **)(local_30 + (int)pSVar3 * 4);
      iVar1 = *(int *)(local_24 + 0x48);
      pSVar13 = pSVar3;
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0x460,(CFastBuffer<class_CCrystalFace*> *)pGVar11);
      if (uVar4 < *(int *)(this + 0x28) + 1U) {
        pGVar11 = (GmIso4 *)0x52d7b4;
        pSStack_20 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                               (this + 0x454,
                                (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                 *)0x52d7b4);
        pGVar12 = (GmIso4 *)0x52d7bf;
        pSStack_20 = CFastBuffer<struct_CHmsViewport::SClippingFrustum>::GetLastElem
                               (this + 0x460,
                                (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>
                                 *)unaff_EBP);
        unaff_EBP = (CHmsPortal *)0x52d7cd;
        pSVar3 = pSVar13;
        uStack_10 = CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(iVar1 + 0x28),(CFastBuffer<class_CCrystalFace*> *)unaff_EBX)
        ;
        pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (uStack_10 != 0) {
          do {
            pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(iVar1 + 0x28),pCVar8,(ulong)pGVar11);
            this_00 = *(CHmsPortal **)pSVar5;
            if (*(int *)(this_00 + 0x20) != 0) {
              pGVar11 = (GmIso4 *)&local_30;
              iVar7 = CHmsPortal::IsVisible(this_00,pCStack_28,local_24,pGVar11);
              if (iVar7 != 0) {
                GmFrustum::Set(auStack_18,(CMwCmdScriptVarBool *)pCStack_28,(int)pGVar12);
                pGVar12 = (GmIso4 *)&uStack_14;
                pGVar11 = (GmIso4 *)pSStack_20;
                iVar7 = CHmsPortal::TransformView
                                  (this_00,(CHmsPortal *)pSStack_20,pGVar12,(GmFrustum *)unaff_EBP);
                if (iVar7 != 0) {
                  unaff_EBP = (CHmsPortal *)0x52d83a;
                  iVar7 = GmFrustum::IsValid(&uStack_10,(CGameScoresVersion *)pGVar11);
                  if (iVar7 != 0) {
                    *(undefined4 *)(this + 0x35c) = in_stack_00000014;
                    unaff_EBP = aCStack_c;
                    *(undefined4 *)(this + 0x38c) = uStack_14;
                    pGVar11 = (GmIso4 *)0x52d864;
                    unaff_EBX = local_24;
                    RenderPortal(this,(CHmsViewport *)this_00,unaff_EBP,local_24,(int)pSVar3);
                    *(undefined4 *)(this + 0x38c) = 0;
                    pGVar12 = (GmIso4 *)this_00;
                    if (pSStack_20 != (SNewTriangleVert *)0x0) {
                      return;
                    }
                  }
                }
              }
            }
            pCVar8 = pCVar8 + 1;
          } while (pCVar8 < pSStack_20);
        }
      }
      pSVar3 = pSVar3 + 1;
      pCVar9 = param_1;
    } while (pSVar3 < pSVar14);
  }
  pcVar2 = *(code **)(*(int *)this + 0x18c);
  *(CHmsViewport **)(this + 0x35c) = pCVar9;
  (*pcVar2)(pCVar9);
  return;
}
}

// =================================================
// Function: CHmsViewport::ResetShadowVolumes
// =================================================
void __thiscall CHmsViewport::ResetShadowVolumes(CHmsViewport *this,CHmsViewport *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  iVar1 = *(int *)(this + 0x240);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x20),unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x20),pCVar4,(ulong)unaff_ESI);
      pCVar4 = pCVar4 + 1;
      *(undefined4 *)(*(int *)pSVar3 + 0x58) = 0;
    } while (pCVar4 < pCVar2);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x264,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0x264,pCVar4,unaff_EBP);
      if (*(int *)(*(int *)(pSVar3 + 8) + 0x118) != 0) {
        unaff_EBP = 0x52f683;
        (**(code **)(**(int **)(*(int *)(pSVar3 + 8) + 0x118) + 4))();
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

