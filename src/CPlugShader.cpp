// Class implementation: CPlugShader

// =================================================
// Function: CPlugShader::CPlugShader
// =================================================
void __thiscall CPlugShader::CPlugShader(CPlugShader *this,CPlugShader *param_1)
{
{
  CPlug *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_retaddr;
  
  CPlug::CPlug((CPlug *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x2c,unaff_retaddr);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) & 0x80 | 0xb003f800;
  *(uint *)(this + 0x20) = *(uint *)(this + 0x20) & 0xfffafff0 | 0xfff0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x24) = 0x40;
  *(undefined2 *)(this + 0x28) = 1;
  return;
}
}

// =================================================
// Function: CPlugShader::FindBitmapRenderByClassId
// =================================================
CPlugBitmapRender * __thiscall
CPlugShader::FindBitmapRenderByClassId
          (CPlugShader *this,CPlugShader *param_1,ulong param_2,CPlugBitmap **param_3,
          CPlugBitmapAddress **param_4)
{
{
  int iVar1;
  CPlugBitmapRender *pCVar2;
  uint uVar3;
  CPlugBitmap *pCVar4;
  int iVar5;
  uint uStack_8;
  
  uVar3 = (**(code **)(*(int *)this + 0x7c))();
  uStack_8 = 0;
  if (uVar3 != 0) {
    do {
      pCVar4 = (CPlugBitmap *)(**(code **)(*(int *)this + 0x8c))(uStack_8);
      if (((pCVar4 != (CPlugBitmap *)0x0) && (iVar1 = *(int *)(pCVar4 + 0x1c), iVar1 != 0)) &&
         (*(char *)(iVar1 + 0x4d) == '\x04')) {
        pCVar2 = *(CPlugBitmapRender **)(iVar1 + 0x74);
        iVar5 = (**(code **)(*(int *)pCVar2 + 0x10))(param_1);
        if (iVar5 != 0) {
          if (param_2 != 0) {
            *(int *)param_2 = iVar1;
          }
          if (param_3 != (CPlugBitmap **)0x0) {
            *param_3 = pCVar4;
          }
          return pCVar2;
        }
      }
      uStack_8 = uStack_8 + 1;
    } while (uStack_8 < uVar3);
  }
  return (CPlugBitmapRender *)0x0;
}
}

// =================================================
// Function: CPlugShader::FindLayerByName
// =================================================
CPlugBitmapAddress * __thiscall
CPlugShader::FindLayerByName(CPlugShader *this,CPlugShader *param_1,CFastString *param_2)
{
{
  ulong uVar1;
  CPlugBitmapAddress *pCVar2;
  CFastString *unaff_ESI;
  
  uVar1 = FindLayerIndexByName(this,param_1,unaff_ESI);
  if (uVar1 != 0xffffffff) {
    pCVar2 = (CPlugBitmapAddress *)(**(code **)(*(int *)this + 0x8c))(uVar1);
    return pCVar2;
  }
  return (CPlugBitmapAddress *)0x0;
}
}

// =================================================
// Function: CPlugShader::FindLayerIndexByName
// =================================================
ulong __thiscall
CPlugShader::FindLayerIndexByName(CPlugShader *this,CPlugShader *param_1,CFastString *param_2)
{
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  ulong uVar5;
  int iStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00ad7188;
  local_14 = ExceptionList;
  uVar1 = DAT_00cca150 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  uVar2 = (**(code **)(*(int *)this + 0x7c))();
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      iStack_28 = 0;
      uStack_c = 0;
      puStack_24 = PTR_DAT_00bbf7d8;
      (**(code **)(*(int *)this + 0x88))(uVar5,&iStack_28);
      puStack_20 = *(undefined **)(param_1 + 4);
      iStack_1c = *(int *)param_1;
      if ((iStack_1c == iStack_28) &&
         (iVar3 = CFastString::CompareNoCase
                            ((CFastString *)&iStack_28,(CFastStringInt *)&puStack_20,
                             (SStringParam *)0x0,uVar1), iVar3 == 0)) {
        if (puStack_20 != PTR_DAT_00bbf7d8) {
          puVar4 = puStack_20 + -1;
          if ((puStack_20[-1] & 0x80) != 0) {
            puVar4 = puStack_20 + -4;
          }
          operator_delete__(puVar4);
        }
        ExceptionList = puStack_10;
        return uVar5;
      }
      uStack_c = 0xffffffff;
      if (puStack_24 != PTR_DAT_00bbf7d8) {
        puVar4 = puStack_24 + -1;
        if ((puStack_24[-1] & 0x80) != 0) {
          puVar4 = puStack_24 + -4;
        }
        operator_delete__(puVar4);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar2);
  }
  ExceptionList = local_14;
  return 0xffffffff;
}
}

// =================================================
// Function: CPlugShader::GenerateVshFromFixedPipe
// =================================================
void __thiscall CPlugShader::GenerateVshFromFixedPipe(CPlugShader *this,CPlugShader *param_1)
{
{
  CPlugShader *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CPlugFileVHlsl *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  if (DAT_00d6ea9c != 0) {
    this_00 = this + 0x2c;
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if ((((uVar1 == 0) ||
         (pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                              unaff_EDI), *(int *)(*(int *)pSVar2 + 0x3c) == 0)) ||
        (pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                             unaff_retaddr), *(int *)(*(int *)(*(int *)pSVar2 + 0x3c) + 0xa0) != 0))
       && (pCVar3 = CPlugFileVHlsl::GetFixedVHlsl(this), pCVar3 != (CPlugFileVHlsl *)0x0)) {
      SetVertexShader(this,(CPlugShaderPass *)0x0,(CPlugFileGPUV *)pCVar3);
    }
  }
  return;
}
}

// =================================================
// Function: CPlugShader::GetLoadFxValue
// =================================================
GmVec4 * __thiscall
CPlugShader::GetLoadFxValue
          (CPlugShader *this,CPlugShader *param_1,CMwId *param_2,SPlugGpuLoadFx **param_3,
          CPlugShaderPass **param_4,EPlugGpuPipeline *param_5,ulong *param_6)
{
{
  CPlugFileGPU *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SPlugGpuLoadFx *pSVar3;
  ulong uVar4;
  SPlugGpuLoadFx *unaff_EBX;
  ulong *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CPlugShader *this_01;
  CPlugShader *pCVar5;
  ulong unaff_EDI;
  uint uVar6;
  uint *in_stack_0000001c;
  ulong *in_stack_00000020;
  ulong in_stack_fffffff0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_c;
  
  this_01 = this + 0x2c;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_ESI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    return (GmVec4 *)0x0;
  }
  local_c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,local_c,unaff_EDI);
      this_01 = *(CPlugShader **)pSVar2;
      uVar6 = 0;
      pCVar5 = this_01 + 0x3c;
      do {
        this_00 = *(CPlugFileGPU **)pCVar5;
        if (this_00 != (CPlugFileGPU *)0x0) {
          unaff_EDI = 0;
          pSVar3 = CPlugFileGPU::LoadFxFindByName
                             (this_00,(CPlugFileGPU *)param_3,(CMwId *)0x0,unaff_EBP);
          if (pSVar3 != (SPlugGpuLoadFx *)0x0) {
            if (param_5 != (EPlugGpuPipeline *)0x0) {
              *param_5 = (EPlugGpuPipeline)pSVar3;
            }
            if (param_6 != (ulong *)0x0) {
              *param_6 = (ulong)pCVar1;
            }
            if (in_stack_0000001c != (uint *)0x0) {
              *in_stack_0000001c = uVar6;
            }
            if (in_stack_00000020 != (ulong *)0x0) {
              uVar4 = CFastArray<struct_SPlugGpuLoadFx>::GetIndexFromAdr
                                (this_00 + 0x54,(CFastArray<struct_SPlugGpuLoadFx> *)pSVar3,
                                 unaff_EBX);
              *in_stack_00000020 = uVar4;
            }
            pSVar2 = CFastBuffer<class_GxColor>::operator[]
                               (param_1 + uVar6 * 8 + 0x24,
                                (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                (*(uint *)(pSVar3 + 4) >> 0x13),in_stack_fffffff0);
            return (GmVec4 *)pSVar2;
          }
        }
        uVar6 = uVar6 + 1;
        pCVar5 = pCVar5 + 4;
      } while (uVar6 < 2);
      local_c = local_c + 1;
    } while (local_c < pCVar1);
    return (GmVec4 *)0x0;
  }
  return (GmVec4 *)0x0;
}
}

// =================================================
// Function: CPlugShader::GetLoadFxValues
// =================================================
int __thiscall
CPlugShader::GetLoadFxValues
          (CPlugShader *this,CPlugShader *param_1,CFastBuffer<struct_CPlugShader::SFxValue> *param_2
          ,CMwId *param_3)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  SPlugGpuLoadFx *pSVar3;
  SLoadedLight *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  void *this_00;
  ulong *unaff_EBP;
  undefined4 *puVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CPlugShader *this_01;
  ulong unaff_EDI;
  CPlugFileGPU *in_stack_00000010;
  ulong in_stack_fffffff0;
  int iStack_c;
  CPlugShader *pCStack_4;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_ESI);
  if ((uVar1 != 0) &&
     (pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0, this_01 = this + 0x2c,
     uVar1 != 0)) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar5,unaff_EDI);
      this_00 = (void *)(*(int *)pSVar2 + 0x24);
      puVar6 = (undefined4 *)(*(int *)pSVar2 + 0x3c);
      do {
        if ((CPlugFileGPU *)*puVar6 != (CPlugFileGPU *)0x0) {
          unaff_EDI = 0;
          pSVar3 = CPlugFileGPU::LoadFxFindByName
                             ((CPlugFileGPU *)*puVar6,in_stack_00000010,(CMwId *)0x0,unaff_EBP);
          if (pSVar3 != (SPlugGpuLoadFx *)0x0) {
            pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                               (in_stack_00000010,
                                (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)unaff_EBX);
            *(SPlugGpuLoadFx **)pSVar4 = pSVar3;
            unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (*(uint *)(pSVar3 + 4) >> 0x13);
            unaff_EBP = (ulong *)0x86dbf4;
            pSVar2 = CFastBuffer<class_GxColor>::operator[](this_00,unaff_EBX,in_stack_fffffff0);
            *(SCasterCat **)(pSVar4 + 4) = pSVar2;
          }
        }
        puVar6 = puVar6 + 1;
        this_00 = (void *)((int)this_00 + 8);
        iStack_c = iStack_c + -1;
      } while (iStack_c != 0);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3;
      this_01 = pCStack_4;
    } while (3 < uVar1);
  }
  return 0;
}
}

// =================================================
// Function: CPlugShader::RemovePasses
// =================================================
void __thiscall CPlugShader::RemovePasses(CPlugShader *this,CPlugShader *param_1)
{
{
  CFastArray<class_CManoeuvre*>::DeleteAll(this + 0x2c,(CFastArray<class_CCrystalEdge*> *)param_1);
  return;
}
}

// =================================================
// Function: CPlugShader::SetBiasZ
// =================================================
void __thiscall CPlugShader::SetBiasZ(CPlugShader *this,CPlugShader *param_1,uchar param_2)
{
{
  if (0x1f < (byte)param_1) {
    param_1._0_1_ = 0x1f;
  }
  *(uint *)(this + 0x1c) =
       *(uint *)(this + 0x1c) ^ ((uint)(byte)param_1 * 4 ^ *(uint *)(this + 0x1c)) & 0x7c;
  SetDirty(this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShader::SetDirty
// =================================================
void __thiscall CPlugShader::SetDirty(CPlugShader *this,CPlugVertexStream *param_1,int param_2)
{
{
  uint uVar1;
  
  *(uint *)(this + 0x1c) =
       *(uint *)(this + 0x1c) ^ ((uint)(param_2 != 0) << 0x11 ^ *(uint *)(this + 0x1c)) & 0x20000;
  uVar1 = *(uint *)(this + 0x1c);
  if ((((uVar1 >> 0x10 & 1) != (uint)(param_1 != (CPlugVertexStream *)0x0)) &&
      (*(uint *)(this + 0x1c) =
            ((uint)(param_1 != (CPlugVertexStream *)0x0) << 0x10 ^ uVar1) & 0x10000 ^ uVar1,
      param_1 != (CPlugVertexStream *)0x0)) && (DAT_00d6ec90 != (undefined4 *)0x0)) {
    (**(code **)*DAT_00d6ec90)(this);
  }
  return;
}
}

// =================================================
// Function: CPlugShader::SetDoubleSided
// =================================================
void __thiscall CPlugShader::SetDoubleSided(CPlugShader *this,CPlugShader *param_1,int param_2)
{
{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0x1c);
  if ((uVar1 >> 10 & 1) != (uint)(param_1 != (CPlugShader *)0x0)) {
    *(uint *)(this + 0x1c) = ((uint)(param_1 != (CPlugShader *)0x0) << 10 ^ uVar1) & 0x400 ^ uVar1;
    SetDirty(this,(CPlugVertexStream *)0x1,1);
  }
  return;
}
}

// =================================================
// Function: CPlugShader::SetFogEnable
// =================================================
void __thiscall
CPlugShader::SetFogEnable(CPlugShader *this,CPlugShader *param_1,int param_2,int param_3)
{
{
  *(uint *)(this + 0x1c) =
       ((uint)(param_2 != 0) * 2 | (uint)(param_1 != (CPlugShader *)0x0)) << 0xd |
       *(uint *)(this + 0x1c) & 0xffff9fff;
  SetDirty(this,(CPlugVertexStream *)0x1,1);
  return;
}
}

// =================================================
// Function: CPlugShader::SetIgnoreUserClipPlanes
// =================================================
void __thiscall
CPlugShader::SetIgnoreUserClipPlanes(CPlugShader *this,CPlugShader *param_1,int param_2)
{
{
  *(uint *)(this + 0x1c) =
       *(uint *)(this + 0x1c) ^
       ((uint)(param_1 != (CPlugShader *)0x0) << 0x1e ^ *(uint *)(this + 0x1c)) & 0x40000000;
  return;
}
}

// =================================================
// Function: CPlugShader::SetPixelShader
// =================================================
void __thiscall
CPlugShader::SetPixelShader(CPlugShader *this,CPlugShaderPass *param_1,CPlugFileGPUP *param_2)
{
{
  int iVar1;
  CPlugShaderPass *pCVar2;
  CPlugShaderPass *this_00;
  CPlugShaderPass *extraout_EAX;
  SCasterCat *pSVar3;
  ulong uVar4;
  ulong unaff_EBX;
  CPlugShaderPass *unaff_EBP;
  CPlugShader *unaff_ESI;
  CPlugShader *this_01;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugShaderPass *in_stack_00000010;
  CPlugShaderPass *in_stack_0000001c;
  CPlugShaderPass **ppCVar5;
  
  ppCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  if (param_2 == (CPlugFileGPUP *)0x0) {
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this + 0x2c,
                       (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
    if (uVar4 == 0) {
      ExceptionList = &LAB_00ad72fb;
      return;
    }
    param_1 = (CPlugShaderPass *)0x0;
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0xb8))(param_1,param_2);
    if (iVar1 == 0) {
      ExceptionList = &LAB_00ad72fb;
      return;
    }
    pCVar2 = (CPlugShaderPass *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EDI);
    if (param_1 == pCVar2) {
      this_00 = operator_new(0x58);
      pCVar2 = (CPlugShaderPass *)0x0;
      if (this_00 != (CPlugShaderPass *)0x0) {
        CPlugShaderPass::CPlugShaderPass(this_00,(CPlugShaderPass *)unaff_ESI);
        pCVar2 = extraout_EAX;
      }
      in_stack_00000010 = pCVar2;
      CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
                (this + 0x2c,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0x00000010,
                 (SFormat *)unaff_EBP);
      unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x86f1aa;
      unaff_ESI = this;
      unaff_EBP = param_1;
      CPlugShaderPass::AttachShader(pCVar2,(CPlugShaderPass *)this,(CPlugShader *)param_1,unaff_EBX)
      ;
      param_2 = (CPlugFileGPUP *)in_stack_0000001c;
    }
  }
  this_01 = this + 0x2c;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      (ulong)unaff_EDI);
  CPlugShaderPass::SetPixelShader
            (*(CPlugShaderPass **)pSVar3,(CPlugShaderPass *)param_2,(CPlugFileGPUP *)unaff_ESI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      (ulong)unaff_EBP);
  if ((*(int *)(*(int *)pSVar3 + 0x3c) == 0) && (*(int *)(*(int *)pSVar3 + 0x40) == 0)) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EBX)
    ;
    CFastArray<class_CPlugShaderPass*>::DeleteOneAt
              (this_01,(CFastArray<class_CPlugShaderPass*> *)pSVar3,ppCVar5);
  }
  SetDirty(this,(CPlugVertexStream *)0x1,1);
  ExceptionList = &LAB_00ad72fb;
  return;
}
}

// =================================================
// Function: CPlugShader::SetReceiverDisable
// =================================================
void __thiscall CPlugShader::SetReceiverDisable(CPlugShader *this,CPlugShader *param_1)
{
{
  ulong unaff_ESI;
  int unaff_retaddr;
  
  SetReceiverShadowGroupMask(this,(CPlugShader *)0x0,unaff_ESI);
  CHmsItem::SetIsForcePointDynamicCollisionResponse((CHmsItem *)this,(CHmsItem *)0x0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugShader::SetReceiverShadowGroupMask
// =================================================
void __thiscall
CPlugShader::SetReceiverShadowGroupMask(CPlugShader *this,CPlugShader *param_1,ulong param_2)
{
{
  *(uint *)(this + 0x20) =
       *(uint *)(this + 0x20) ^ ((int)param_1 << 4 ^ *(uint *)(this + 0x20)) & 0xfff0;
  return;
}
}

// =================================================
// Function: CPlugShader::SetVertexShader
// =================================================
void __thiscall
CPlugShader::SetVertexShader(CPlugShader *this,CPlugShaderPass *param_1,CPlugFileGPUV *param_2)
{
{
  int iVar1;
  CPlugShaderPass *pCVar2;
  CPlugShaderPass *this_00;
  CPlugShaderPass *extraout_EAX;
  SCasterCat *pSVar3;
  ulong uVar4;
  ulong unaff_EBX;
  CPlugShaderPass *unaff_EBP;
  CPlugShader *unaff_ESI;
  CPlugShader *this_01;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugShaderPass *in_stack_00000010;
  CPlugShaderPass *in_stack_0000001c;
  CPlugShaderPass **ppCVar5;
  
  ppCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  if (param_2 == (CPlugFileGPUV *)0x0) {
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this + 0x2c,
                       (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
    if (uVar4 == 0) {
      ExceptionList = &LAB_00ad72cb;
      return;
    }
    param_1 = (CPlugShaderPass *)0x0;
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0xb4))(param_1,param_2);
    if (iVar1 == 0) {
      ExceptionList = &LAB_00ad72cb;
      return;
    }
    pCVar2 = (CPlugShaderPass *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_EDI);
    if (param_1 == pCVar2) {
      this_00 = operator_new(0x58);
      pCVar2 = (CPlugShaderPass *)0x0;
      if (this_00 != (CPlugShaderPass *)0x0) {
        CPlugShaderPass::CPlugShaderPass(this_00,(CPlugShaderPass *)unaff_ESI);
        pCVar2 = extraout_EAX;
      }
      in_stack_00000010 = pCVar2;
      CFastArray<class_CFastBuffer<class_CSceneMobil*>*>::AddTail
                (this + 0x2c,(CFastArray<struct_CDx9DeviceCaps::SFormat> *)&stack0x00000010,
                 (SFormat *)unaff_EBP);
      unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x86f08a;
      unaff_ESI = this;
      unaff_EBP = param_1;
      CPlugShaderPass::AttachShader(pCVar2,(CPlugShaderPass *)this,(CPlugShader *)param_1,unaff_EBX)
      ;
      param_2 = (CPlugFileGPUV *)in_stack_0000001c;
    }
  }
  this_01 = this + 0x2c;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      (ulong)unaff_EDI);
  CPlugShaderPass::SetVertexShader
            (*(CPlugShaderPass **)pSVar3,(CPlugShaderPass *)param_2,(CPlugFileGPUV *)unaff_ESI);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,
                      (ulong)unaff_EBP);
  if ((*(int *)(*(int *)pSVar3 + 0x3c) == 0) && (*(int *)(*(int *)pSVar3 + 0x40) == 0)) {
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_01,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_1,unaff_EBX)
    ;
    CFastArray<class_CPlugShaderPass*>::DeleteOneAt
              (this_01,(CFastArray<class_CPlugShaderPass*> *)pSVar3,ppCVar5);
  }
  (**(code **)(*(int *)this + 0xa8))();
  SetDirty(this,(CPlugVertexStream *)0x1,1);
  ExceptionList = &LAB_00ad72cb;
  return;
}
}

// =================================================
// Function: CPlugShader::SetVisibleId
// =================================================
void __thiscall
CPlugShader::SetVisibleId(CPlugShader *this,CPlugShader *param_1,SPlugVisibleId *param_2)
{
{
  *(undefined2 *)(this + 0x28) = *(undefined2 *)param_1;
  return;
}
}

