// Class implementation: CVisionViewport

// =================================================
// Function: CVisionViewport::CVisionViewport
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CVisionViewport::CVisionViewport(CVisionViewport *this,CVisionViewport *param_1)
{
{
  SCasterCat *pSVar1;
  CSystemFid *pCVar2;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000000c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000010;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000014;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000018;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000001c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000020;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000024;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000028;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000002c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000030;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000034;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000038;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000003c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000040;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000044;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000048;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000004c;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000050;
  CFastRadixSort *in_stack_00000054;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000058;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_0000005c;
  GxClipper *in_stack_00000060;
  ulong in_stack_00000064;
  undefined1 uStack00000074;
  void *in_stack_00000080;
  undefined1 uStack00000084;
  CVisionViewport *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar5;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar6;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar7;
  
  pCVar7 = (CFastBuffer<class_CPlugFileSndGen*> *)0xffffffff;
  pCVar6 = (CFastBuffer<class_CPlugFileSndGen*> *)&LAB_00ae94e6;
  pCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar4 = this;
  CHmsViewport::CHmsViewport
            ((CHmsViewport *)this,(CHmsViewport *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)0x0;
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x568,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x578,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x584,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x590,unaff_EBX);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x59c,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar4);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x5a8,pCVar5);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x5b4,pCVar6);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x5c0,pCVar7);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x5cc,pCVar3);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x5d8,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x5e4,in_stack_00000008);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x5f0,in_stack_0000000c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x5fc,in_stack_00000010);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x608,in_stack_00000014);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x614,in_stack_00000018);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x620,in_stack_0000001c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x62c,in_stack_00000020);
  *(undefined4 *)(this + 0x638) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x63c,in_stack_00000024);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x64c,in_stack_00000028);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x658,in_stack_0000002c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x664,in_stack_00000030);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x670,in_stack_00000034);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x67c,in_stack_00000038);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x688,in_stack_0000003c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x694,in_stack_00000040);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6a0,in_stack_00000044);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6ac,in_stack_00000048);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6b8,in_stack_0000004c);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6c4,in_stack_00000050);
  uStack00000074 = 0x1d;
  CFastRadixSort::CFastRadixSort(this + 0x6d0,in_stack_00000054);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6e8,in_stack_00000058);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x6f4,in_stack_0000005c);
  in_stack_00000080 = (void *)CONCAT31(in_stack_00000080._1_3_,0x20);
  GxClipper::GxClipper((GxClipper *)(this + 0x70c),in_stack_00000060);
  *(undefined4 *)(this + 0x7ec) = _DAT_00b31460;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1e4) = 0;
  *(undefined4 *)(this + 0x1e8) = 0;
  *(undefined4 *)(this + 0x1ec) = 0;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x1fc) = 0;
  *(undefined4 *)(this + 0x200) = 0;
  *(undefined4 *)(this + 0x204) = 0;
  *(undefined4 *)(this + 0x7f0) = 0;
  *(undefined4 *)(this + 0x7f4) = 0;
  *(undefined4 *)(this + 0x7e8) = 0;
  *(undefined4 *)(this + 0x208) = 0;
  *(undefined4 *)(this + 0x210) = 0;
  *(undefined4 *)(this + 0x21c) = 0;
  *(undefined4 *)(this + 0x220) = 0;
  *(undefined4 *)(this + 0x224) = 0;
  *(undefined4 *)(this + 0x228) = 0;
  *(undefined4 *)(this + 0x7e0) = 0;
  *(undefined4 *)(this + 0x7e4) = 0;
  *(undefined4 *)(this + 0x708) = 0;
  *(undefined4 *)(this + 0x700) = 0;
  *(undefined4 *)(this + 0x704) = 0xffffffff;
  *(undefined4 *)(this + 0x648) = 0;
  *(undefined4 *)(this + 0x574) = 0;
  uStack00000084 = 0x21;
  DAT_00d75674 = this;
  DAT_00d75678 = this;
  DAT_00d7567c = this;
  operator_delete(DAT_00d705d8);
  DAT_00d705d8 = operator_new(0xc);
  if (DAT_00d705d8 == (undefined4 *)0x0) {
    DAT_00d705d8 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d705d8 =
         CFastCallbackInstance1P<class_CVisionTexturePool,class_CPlugVolumeShadow*>::vftable;
    DAT_00d705d8[1] = this + 0x620;
    DAT_00d705d8[2] = CVisionTexturePool::ShadowVolOnDestroy;
  }
  operator_delete(DAT_00d6f614);
  DAT_00d6f614 = operator_new(0xc);
  if (DAT_00d6f614 == (undefined4 *)0x0) {
    DAT_00d6f614 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f614 =
         CFastCallbackInstance1P<class_CVisionViewport,struct_CPlugTreeMapShaderFill::SFillValue*>::
         vftable;
    DAT_00d6f614[1] = this;
    DAT_00d6f614[2] = _vcall__536__flat______;
  }
  operator_delete(DAT_00d6ec94);
  DAT_00d6ec94 = operator_new(0xc);
  if (DAT_00d6ec94 == (undefined4 *)0x0) {
    DAT_00d6ec94 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6ec94 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugShader*>::vftable;
    DAT_00d6ec94[1] = this;
    DAT_00d6ec94[2] = ShaderOnPlugDelete;
  }
  operator_delete(DAT_00d6ec90);
  DAT_00d6ec90 = operator_new(0xc);
  if (DAT_00d6ec90 == (undefined4 *)0x0) {
    DAT_00d6ec90 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6ec90 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugShader*>::vftable;
    DAT_00d6ec90[1] = this;
    DAT_00d6ec90[2] = ShaderOnPlugDirty;
  }
  operator_delete(DAT_00d6e598);
  DAT_00d6e598 = operator_new(0xc);
  if (DAT_00d6e598 == (undefined4 *)0x0) {
    DAT_00d6e598 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6e598 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugBitmap*>::vftable;
    DAT_00d6e598[1] = this;
    DAT_00d6e598[2] = TextureRemove;
  }
  operator_delete(DAT_00d6e594);
  DAT_00d6e594 = operator_new(0xc);
  if (DAT_00d6e594 == (undefined4 *)0x0) {
    DAT_00d6e594 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6e594 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugBitmap*>::vftable;
    DAT_00d6e594[1] = this;
    DAT_00d6e594[2] = TextureOnPlugDirty;
  }
  operator_delete(DAT_00d6eb08);
  DAT_00d6eb08 = operator_new(0xc);
  if (DAT_00d6eb08 == (undefined4 *)0x0) {
    DAT_00d6eb08 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6eb08 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugVisual*>::vftable;
    DAT_00d6eb08[1] = this;
    DAT_00d6eb08[2] = VisualOnPlugDelete;
  }
  operator_delete(DAT_00d6eb04);
  DAT_00d6eb04 = operator_new(0xc);
  if (DAT_00d6eb04 == (undefined4 *)0x0) {
    DAT_00d6eb04 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6eb04 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugVisual*>::vftable;
    DAT_00d6eb04[1] = this;
    DAT_00d6eb04[2] = VisualOnPlugDirty;
  }
  operator_delete(DAT_00d6f174);
  DAT_00d6f174 = operator_new(0xc);
  if (DAT_00d6f174 == (undefined4 *)0x0) {
    DAT_00d6f174 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f174 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugVertexStream*>::vftable
    ;
    DAT_00d6f174[1] = this;
    DAT_00d6f174[2] = VertexStreamOnPlugDelete;
  }
  operator_delete(DAT_00d6f170);
  DAT_00d6f170 = operator_new(0xc);
  if (DAT_00d6f170 == (undefined4 *)0x0) {
    DAT_00d6f170 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f170 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugVertexStream*>::vftable
    ;
    DAT_00d6f170[1] = this;
    DAT_00d6f170[2] = VertexStreamOnPlugDirty;
  }
  operator_delete(DAT_00d6f6b4);
  DAT_00d6f6b4 = operator_new(0xc);
  if (DAT_00d6f6b4 == (undefined4 *)0x0) {
    DAT_00d6f6b4 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f6b4 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugIndexBuffer*>::vftable;
    DAT_00d6f6b4[1] = this;
    DAT_00d6f6b4[2] = IndexBufferOnPlugDelete;
  }
  operator_delete(DAT_00d6f6b0);
  DAT_00d6f6b0 = operator_new(0xc);
  if (DAT_00d6f6b0 == (undefined4 *)0x0) {
    DAT_00d6f6b0 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f6b0 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugIndexBuffer*>::vftable;
    DAT_00d6f6b0[1] = this;
    DAT_00d6f6b0[2] = IndexBufferOnPlugDirty;
  }
  operator_delete(DAT_00d6efc4);
  DAT_00d6efc4 = operator_new(0xc);
  if (DAT_00d6efc4 == (undefined4 *)0x0) {
    DAT_00d6efc4 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6efc4 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugFileGPUV*>::vftable;
    DAT_00d6efc4[1] = this;
    DAT_00d6efc4[2] = VertexShaderOnPlugDelete;
  }
  operator_delete(DAT_00d6f1a4);
  DAT_00d6f1a4 = operator_new(0xc);
  if (DAT_00d6f1a4 == (undefined4 *)0x0) {
    DAT_00d6f1a4 = (undefined4 *)0x0;
  }
  else {
    *DAT_00d6f1a4 = CFastCallbackInstance1P<class_CVisionViewport,class_CPlugFileGPUP*>::vftable;
    DAT_00d6f1a4[1] = this;
    DAT_00d6f1a4[2] = PixelShaderOnPlugDelete;
  }
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000c,
                      in_stack_00000064);
  pCVar2 = (CSystemFid *)(**(code **)(**(int **)pSVar1 + 0x88))();
  if (pCVar2 != (CSystemFid *)0x0) {
    CSystemArchiveNod::LoadFromFid<class_CVisionResourceFile>
              ((CMwNodRef<class_CVisionResourceFile> *)(this + 0x638),pCVar2,7);
  }
  ExceptionList = in_stack_00000080;
  return;
}
}

// =================================================
// Function: CVisionViewport::ForceDeviceSynchro
// =================================================
int __thiscall
CVisionViewport::ForceDeviceSynchro(CVisionViewport *this,CVisionViewportDx9 *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CHmsZone *unaff_EBX;
  CHmsViewport *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  if (*(int *)(this + 0x2f8) != 0) {
    return 0;
  }
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x264,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0x264,pCVar3,(ulong)unaff_ESI);
      unaff_ESI = *(CHmsViewport **)(pSVar2 + 8);
      CHmsViewport::LoadResourceZone((CHmsViewport *)this,unaff_ESI,unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 1;
}
}

// =================================================
// Function: CVisionViewport::ShaderGetKeeper
// =================================================
CVisionShaderKeeper * __thiscall
CVisionViewport::ShaderGetKeeper
          (CVisionViewport *this,CVisionViewport *param_1,CPlugShader *param_2)
{
{
  CVisionViewport *this_00;
  CVisionViewport *pCVar1;
  CVisionShaderKeeper *pCVar2;
  CClassicBufferMemory *this_01;
  CVisionShaderKeeper *extraout_EAX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CClassicBufferMemory *extraout_EAX_00;
  int iVar5;
  CVisionShaderKeeper *unaff_ESI;
  CClassicBufferMemory *pCVar6;
  CClassicBufferMemory *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  bool bVar8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffb0;
  CMwNod *in_stack_ffffffb4;
  SUser **ppSVar9;
  CClassicBufferMemory *pCVar10;
  CVisionViewport *pCVar11;
  TiXmlAttributeSet *pTVar12;
  CClassicBufferMemory *pCVar13;
  int iStack_2c;
  CVisionViewport *local_28;
  int iStack_24;
  CVisionViewport *pCStack_20;
  int iStack_1c;
  undefined4 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae9056;
  local_c = ExceptionList;
  pCVar1 = (CVisionViewport *)(DAT_00cca150 ^ (uint)&stack0xffffffc4);
  ExceptionList = &local_c;
  iVar5 = *(int *)(param_1 + 0x34);
  local_28 = this;
  if (((iVar5 != 0) && (*(int *)(iVar5 + 4) == 0)) && (*(int *)(*(int *)(iVar5 + 8) + 0x14) != 0)) {
    (*DAT_00d67490)(param_1);
  }
  if ((((byte)this_00[0x1e] & 1) != 0) && (DAT_00d6ea9c != 0)) {
    CPlugShader::GenerateVshFromFixedPipe((CPlugShader *)this_00,(CPlugShader *)pCVar1);
  }
  pCVar2 = *(CVisionShaderKeeper **)(this_00 + 0x14);
  if (pCVar2 == (CVisionShaderKeeper *)0x0) {
    pTVar12 = (TiXmlAttributeSet *)&param_1;
    pCVar10 = (CClassicBufferMemory *)0x95677c;
    CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x584,pTVar12,(TiXmlAttribute *)pCVar1);
    pCVar13 = (CClassicBufferMemory *)0x956789;
    (**(code **)(*(int *)this_00 + 0xac))();
    if (DAT_00cdae98 == 0) {
      pCVar2 = (CVisionShaderKeeper *)(**(code **)(*(int *)this + 0x210))();
      *(undefined4 *)(this_00 + 0x14) = 0;
      (**(code **)(*(int *)pCVar2 + 8))(this_00);
    }
    else {
      CMwProfiler::GetTimeStamp((int64 *)&iStack_24);
      this_01 = operator_new(0x20);
      uStack_14 = 0;
      if (this_01 == (CClassicBufferMemory *)0x0) {
        unaff_EDI = (CClassicBufferMemory *)0x0;
      }
      else {
        CClassicBufferMemory::CClassicBufferMemory
                  (this_01,(CClassicBufferMemory *)in_stack_ffffffb0);
        unaff_ESI = extraout_EAX;
      }
      uStack_14 = 0xffffffff;
      DAT_00d6eda8 = 1;
      CSystemArchiveNod::SaveMemoryTemp(unaff_EDI,(CMwNod *)this_00,8,1);
      DAT_00d6eda8 = 0;
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x614,in_stack_ffffffb0);
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             ((CClassicBufferMemory *)(this + 0x614),pCVar7,(ulong)in_stack_ffffffb4
                             );
          pCVar2 = *(CVisionShaderKeeper **)pSVar4;
          pCVar6 = *(CClassicBufferMemory **)(pCVar2 + 8);
          this = (CVisionViewport *)this_01;
          if (pCVar6 == (CClassicBufferMemory *)0x0) {
            pCVar6 = pCVar13;
            if ((*(uint *)(pCVar2 + 0x10) & 0x4000) != 0) {
              local_28 = operator_new(0x20);
              local_c = (void *)0x1;
              if (local_28 == (CVisionViewport *)0x0) {
                pCVar6 = (CClassicBufferMemory *)0x0;
              }
              else {
                CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)local_28,pCVar10)
                ;
                pCVar6 = extraout_EAX_00;
              }
              puStack_8 = (undefined1 *)0xffffffff;
              DAT_00d6eda8 = 1;
              pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(iStack_2c + 0x584),pCVar7,(ulong)pTVar12);
              in_stack_ffffffb4 = *(CMwNod **)pSVar4;
              CSystemArchiveNod::SaveMemoryTemp(pCVar6,in_stack_ffffffb4,8,1);
              DAT_00d6eda8 = 0;
              pCVar10 = (CClassicBufferMemory *)0x9568bd;
              CVisionShaderKeeper::SetSaveBuffer(pCVar2,(CVisionShaderKeeper *)pCVar6,pCVar13);
              goto LAB_009568bd;
            }
          }
          else {
LAB_009568bd:
            pTVar12 = (TiXmlAttributeSet *)0x9568c7;
            iVar5 = CClassicBufferMemory::IsEqualBuffer
                              ((CClassicBufferMemory *)local_28,pCVar6,unaff_EDI);
            if (iVar5 != 0) break;
          }
          pCVar7 = pCVar7 + 1;
          pCVar13 = pCVar6;
        } while (pCVar7 < pCVar3);
      }
      CMwProfiler::GetTimeStamp((int64 *)&local_28);
      bVar8 = CARRY4(DAT_00d75428,(int)local_28 - (int)pCStack_20);
      DAT_00d75428 = DAT_00d75428 + ((int)local_28 - (int)pCStack_20);
      DAT_00d7542c = DAT_00d7542c + ((iStack_24 - iStack_1c) - (uint)(local_28 < pCStack_20)) +
                     (uint)bVar8;
      DAT_00d75424 = DAT_00d75424 + 1;
      if (pCVar7 < pCVar3) {
        if (unaff_ESI != (CVisionShaderKeeper *)0x0) {
          (*(code *)**(undefined4 **)unaff_ESI)(1);
        }
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((CClassicBufferMemory *)(this + 0x614),pCVar7,(ulong)in_stack_ffffffb4);
        pCVar2 = *(CVisionShaderKeeper **)pSVar4;
        CVisionShaderKeeper::ShaderAddRef(pCVar2,(CVisionShaderKeeper *)pCVar10);
        *(CVisionShaderKeeper **)(this_00 + 0x14) = pCVar2;
        CPlugShader::SetDirty((CPlugShader *)this_00,(CPlugVertexStream *)0x0,0);
        CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
                  ((CClassicBufferMemory *)(this + 0x590),
                   (CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&stack0x00000000,
                   (SUser **)pTVar12);
        ExceptionList = local_c;
        return pCVar2;
      }
      pCVar2 = (CVisionShaderKeeper *)(**(code **)(*(int *)this + 0x210))();
      *(undefined4 *)(this_00 + 0x14) = 0;
      CVisionShaderKeeper::SetSaveBuffer(pCVar2,unaff_ESI,(CClassicBufferMemory *)in_stack_ffffffb4)
      ;
      (**(code **)(*(int *)pCVar2 + 8))(this_00);
    }
    CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
              (this + 0x590,(CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&uStack_4,
               (SUser **)pCVar10);
    *(CVisionShaderKeeper **)(this_00 + 0x14) = pCVar2;
    ShaderUpdateSortIndexs(this,(CVisionViewport *)pTVar12);
  }
  else if (((*(uint *)(this_00 + 0x1c) & 0x20000) != 0) &&
          ((*(uint *)(pCVar2 + 0x10) & 0x4000) != 0)) {
    if (1 < (*(uint *)(pCVar2 + 0x10) & 0x3fff)) {
      ppSVar9 = (SUser **)0x95672a;
      CVisionShaderKeeper::ShaderRelease
                (pCVar2,(CVisionShaderKeeper *)this_00,(CPlugShader *)pCVar1);
      *(undefined4 *)(this_00 + 0x14) = 0;
      pCVar2 = (CVisionShaderKeeper *)(**(code **)(*(int *)this + 0x210))();
      pCVar11 = (CVisionViewport *)0x956745;
      pCVar1 = this_00;
      (**(code **)(*(int *)pCVar2 + 8))();
      CFastBuffer<struct_CGameRemoteBuffer::SUser*>::ReplaceByLastIfFound
                (this + 0x590,(CFastBuffer<struct_CGameRemoteBuffer::SUser*> *)&uStack_4,ppSVar9);
      *(CVisionShaderKeeper **)(this_00 + 0x14) = pCVar2;
      ShaderUpdateSortIndexs(this,pCVar11);
    }
    CVisionShaderKeeper::SetCanBeShared(pCVar2,(CVisionShaderKeeper *)0x0,(int)pCVar1);
  }
  ExceptionList = local_c;
  return pCVar2;
}
}

// =================================================
// Function: CVisionViewport::ShaderUndirtyAll
// =================================================
void __thiscall
CVisionViewport::ShaderUndirtyAll(CVisionViewport *this,CVisionViewport *param_1,int param_2)
{
{
  CVisionViewport *this_00;
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  int iVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  GxTexCoordSet *unaff_retaddr;
  CFastArray<class_GxTexCoordSet> *pCVar4;
  CFastArray<class_GxTexCoordSet> *pCVar5;
  
  this_00 = this + 0x590;
  pCVar4 = (CFastArray<class_GxTexCoordSet> *)this;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
  if ((uVar1 != 0) &&
     (uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX), uVar1 != 0)) {
    do {
      pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this_00,unaff_EDI);
      pCVar5 = *(CFastArray<class_GxTexCoordSet> **)pSVar2;
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
      unaff_EDI = (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                  0x955e4f;
      CFastBuffer<class_CSystemFidsFolder*>::SetCount
                (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)(uVar1 - 1),(ulong)pCVar4);
      pCVar4 = (CFastArray<class_GxTexCoordSet> *)&stack0x00000010;
      unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x955e5b;
      iVar3 = CFastArray<class_CGameMenuFrame*>::Find(this + 0x584,pCVar4,unaff_retaddr);
      if (iVar3 != -1) {
        unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x955e6f;
        (**(code **)(*(int *)this + 0x1bc))();
        pCVar4 = pCVar5;
      }
      unaff_retaddr = (GxTexCoordSet *)0x955e76;
      uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (this_00,(CFastBuffer<class_CCrystalFace*> *)param_1);
    } while (uVar1 != 0);
  }
  return;
}
}

// =================================================
// Function: CVisionViewport::ShaderUpdateSortIndexs
// =================================================
void __thiscall
CVisionViewport::ShaderUpdateSortIndexs(CVisionViewport *this,CVisionViewport *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x614,unaff_EDI);
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < pCVar1) {
    func_0x009c1270(*(undefined4 *)(this + 0x618),pCVar1,4,CompareShaderKeeper);
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x614,pCVar3,(ulong)unaff_ESI);
        unaff_ESI = pCVar3;
        CVisionShaderKeeper::SetIndexToSort
                  (*(CVisionShaderKeeper **)pSVar2,(CVisionShaderKeeper *)pCVar3,unaff_EBX);
        pCVar3 = pCVar3 + 1;
      } while (pCVar3 < pCVar1);
    }
  }
  return;
}
}

