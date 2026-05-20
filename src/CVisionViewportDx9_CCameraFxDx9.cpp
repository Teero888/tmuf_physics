// Class implementation: CVisionViewportDx9_CCameraFxDx9

// =================================================
// Function: CVisionViewportDx9::CCameraFxDx9::CameraToTexture_ForceShader
// =================================================
void __thiscall
CVisionViewportDx9::CCameraFxDx9::CameraToTexture_ForceShader(CCameraFxDx9 *this,undefined4 param_1)
{
{
  int iVar1;
  int in_stack_fffffec8;
  CPlugBitmapRenderCamera *in_stack_fffffecc;
  CPlugShader *in_stack_fffffed0;
  CFixedArray<class_CPlugBitmap*,4,unsigned_long> *in_stack_fffffed4;
  CPlugShader *pCVar2;
  CVisionViewportDx9 *pCVar3;
  uint uStack_120;
  void *local_c;
  CVisionViewportDx9 *pCStack_8;
  CVisionViewportDx9 *pCStack_4;
  
  pCStack_4 = (CVisionViewportDx9 *)0xffffffff;
  pCStack_8 = (CVisionViewportDx9 *)&LAB_00aeadab;
  local_c = ExceptionList;
  uStack_120 = DAT_00cca150 ^ (uint)&stack0xfffffee4;
  ExceptionList = &local_c;
  pCVar3 = *(CVisionViewportDx9 **)(this + 0x14);
  (**(code **)(*(int *)DAT_00d77b18 + 0x178))();
  if (*(int *)(this + 0x24) == 0) {
    iVar1 = RenderTargetPushEmpty(DAT_00d77b18,pCVar3);
    if (iVar1 == 0) {
      ExceptionList = local_c;
      return;
    }
    *(undefined4 *)(this + 0x24) = 1;
  }
  pCVar2 = (CPlugShader *)0x98d082;
  (**(code **)(*(int *)DAT_00d77b18 + 0x214))();
  CVisionViewport::ShaderUndirtyAll
            ((CVisionViewport *)DAT_00d77b18,(CVisionViewport *)0x0,in_stack_fffffec8);
  CPlugBitmapRenderCamera::CPlugBitmapRenderCamera
            ((CPlugBitmapRenderCamera *)&stack0xfffffed8,in_stack_fffffecc);
  *(undefined4 *)(DAT_00d77b18 + 0x8e4) = param_1;
  SetShaderForced(DAT_00d77b18,pCStack_4,in_stack_fffffed0);
  *(undefined4 *)(DAT_00d77b18 + 0x904) = param_1;
  TexRender_RenderTexture
            (DAT_00d77b18,pCStack_8,(CPlugBitmap *)&uStack_120,(CPlugBitmapRender *)0x0,
             in_stack_fffffed4);
  *(undefined4 *)(DAT_00d77b18 + 0x8e4) = 0xffffffff;
  SetShaderForced(DAT_00d77b18,(CVisionViewportDx9 *)0x0,pCVar2);
  *(undefined4 *)(DAT_00d77b18 + 0x904) = 0;
  pCStack_8 = (CVisionViewportDx9 *)0xffffffff;
  CPlugBitmapRenderCamera::~CPlugBitmapRenderCamera
            ((CPlugBitmapRenderCamera *)&stack0xfffffee8,(CPlugBitmapRenderCamera *)pCVar3);
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CVisionViewportDx9::CCameraFxDx9::ForceShadowVolumeUpdate
// =================================================
void __thiscall
CVisionViewportDx9::CCameraFxDx9::ForceShadowVolumeUpdate(CCameraFxDx9 *this,CCameraFxDx9 *param_1)
{
{
  int iVar1;
  uint uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  CVisionViewportDx9 *unaff_EBX;
  CVisionViewportDx9 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CVisionViewportDx9 *in_stack_00000010;
  
  iVar1 = *(int *)(DAT_00d77b18 + 0x240);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x20),unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x20),pCVar5,(ulong)unaff_ESI);
      uVar2 = *(uint *)(*(int *)pSVar4 + 0x30);
      if ((uVar2 & 0x10000) != 0) {
        *(uint *)(*(int *)pSVar4 + 0x30) = uVar2 | 0x20000;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  VisibleZoneCleanShadowAndProjectors(DAT_00d77b18,unaff_ESI);
  VisibleZonePrepareShadowAndProjectors(DAT_00d77b18,unaff_EBX);
  TexRender_UpdateTextures_FromLastFrame_LightDepOnly(DAT_00d77b18,in_stack_00000010);
  return;
}
}

