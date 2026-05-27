// Class implementation: CDx9ShaderKeeper

// =================================================
// Function: CDx9ShaderKeeper::ContextAllSetShaderConstants
// =================================================
void __thiscall
CDx9ShaderKeeper::ContextAllSetShaderConstants
          (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CMwId *param_2,GmVec4 *param_3,
          ulong param_4,int param_5)
{
{
  GmVec4 *pGVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  EPlugGpuPipeline *unaff_EBX;
  CPlugShaderPass **unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SPlugGpuLoadFx **unaff_EDI;
  CMwId *unaff_retaddr;
  void *in_stack_00000018;
  CMwId *in_stack_0000001c;
  CMwId *in_stack_00000020;
  GmVec4 *in_stack_00000030;
  int in_stack_00000034;
  CFastBuffer<class_CCrystalFace*> *pCVar5;
  
  pCVar5 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  if (param_4 == 0) {
    pGVar1 = CPlugShader::GetLoadFxValue
                       (*(CPlugShader **)(this + 0xc),(CPlugShader *)&stack0xfffffff8,
                        (CMwId *)param_1,unaff_EDI,unaff_ESI,unaff_EBX,(ulong *)0x0);
    if (pGVar1 != (GmVec4 *)0x0) {
      _memcpy(param_2,in_stack_00000018,(int)in_stack_0000001c << 4);
    }
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x50,pCVar5);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x50,pCVar4,(ulong)unaff_retaddr);
      if (*(CPlugShader **)(pSVar3 + 4) != (CPlugShader *)0x0) {
        unaff_retaddr = in_stack_0000001c;
        pGVar1 = CPlugShader::GetLoadFxValue
                           (*(CPlugShader **)(pSVar3 + 4),(CPlugShader *)&param_4,in_stack_0000001c,
                            (SPlugGpuLoadFx **)param_1,(CPlugShaderPass **)param_2,
                            (EPlugGpuPipeline *)param_3,(ulong *)param_4);
        if (pGVar1 != (GmVec4 *)0x0) {
          param_4 = in_stack_00000034 << 4;
          param_3 = in_stack_00000030;
          param_2 = in_stack_00000020;
          param_1 = (CDx9ShaderKeeper *)0x96a1fa;
          _memcpy(in_stack_00000020,in_stack_00000030,param_4);
        }
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CDx9ShaderKeeper::ParseBitmapPixelUpdates
// =================================================
void __thiscall
CDx9ShaderKeeper::ParseBitmapPixelUpdates
          (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShader *param_2)
{
{
  CPlugShader *pCVar1;
  CPlugShader *pCVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  TiXmlAttribute *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  void *unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x3c,unaff_EDI);
  pCVar2 = param_2;
  uVar3 = (**(code **)(*(int *)param_2 + 0x98))();
  uVar6 = 0;
  if (uVar3 != 0) {
    do {
      iVar4 = (**(code **)(*(int *)pCVar2 + 0x9c))(uVar6);
      pCVar1 = *(CPlugShader **)(iVar4 + 0x1c);
      param_2 = pCVar1;
      if (pCVar1 != (CPlugShader *)0x0) {
        if (*(int *)(pCVar1 + 0x14) == 0) {
          (**(code **)(*DAT_00d75824 + 0xb0))(pCVar1);
        }
        switch(pCVar1[0x4d]) {
        case (CPlugShader)0x1:
        case (CPlugShader)0x3:
        case (CPlugShader)0x7:
LAB_0096bc22:
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (unaff_retaddr,(TiXmlAttributeSet *)&param_2,unaff_ESI);
          break;
        case (CPlugShader)0x2:
        case (CPlugShader)0x4:
        case (CPlugShader)0x5:
          uVar5 = *(uint *)(pCVar1 + 0x4c) & 0xff;
          if (((((uVar5 == 3) || (uVar5 == 0xf)) || (uVar5 == 0x16)) || (uVar5 == 7)) &&
             ((pCVar1[0x4d] != (CPlugShader)0x4 ||
              ((*(uint *)(*(int *)(pCVar1 + 0x74) + 0x18) & 0x200) == 0)))) goto LAB_0096bc22;
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
  }
  return;
}
}

// =================================================
// Function: CDx9ShaderKeeper::SetKeeperAllBitmapNoDirty
// =================================================
void __thiscall
CDx9ShaderKeeper::SetKeeperAllBitmapNoDirty
          (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,CPlugShaderApply *param_2,
          CPlugBitmap *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CPlugBitmap *unaff_EBX;
  SCasterCat *pSVar3;
  CDx9ShaderKeeper *this_00;
  CPlugVolumeProjector *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CPlugBitmap *unaff_ESI;
  CDx9StateBlock *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CPlugVolumeProjector *in_stack_00000014;
  CDx9ShaderKeeper *pCStack_8;
  
  if (*(int *)(param_2 + 0x14) == 0) {
    (**(code **)(*DAT_00d75824 + 0xb0))(param_2);
  }
  this_00 = this + 0x34;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastArray<struct_CDx9ShaderKeeper::SPassDesc>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      pCVar5 = (CDx9StateBlock *)0x0;
      if ((*(uint *)(pSVar2 + 0x80) & 0x7fffffff) != 0) {
        pSVar3 = pSVar2 + 0x88;
        do {
          if (((*(uint *)pSVar3 & 2) != 0) && ((*(uint *)pSVar3 & 4) != 0)) {
            CDx9StateBlock::RecordSetTexture(pSVar2,pCVar5,(ulong)param_3,unaff_ESI);
          }
          pCVar5 = pCVar5 + 1;
          pSVar3 = pSVar3 + 8;
          this_00 = pCStack_8;
        } while (pCVar5 < (CDx9StateBlock *)(*(uint *)(pSVar2 + 0x80) & 0x7fffffff));
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  DAT_00d7582c = 0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (param_2 + 0x94,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x10000;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_2 + 0x94,pCVar4,(ulong)unaff_EBP);
      unaff_EBP = in_stack_00000014;
      CPlugBitmapSampler::SetBitmap(*(CPlugBitmapSampler **)pSVar2,in_stack_00000014,unaff_EBX);
      pCVar4 = pCVar4 + 1;
      *(uint *)(param_2 + 0x1c) =
           (*(uint *)(param_2 + 0x1c) & 0xfffeffff | (uint)in_stack_00000014) & 0xfffdffff |
           (uint)param_2;
    } while (pCVar4 < pCVar1);
  }
  ParseBitmapPixelUpdates(param_1,(CDx9ShaderKeeper *)param_2,(CPlugShader *)unaff_EBP);
  return;
}
}

// =================================================
// Function: CDx9ShaderKeeper::SetShaderBitmapNoDirty
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CDx9ShaderKeeper::SetShaderBitmapNoDirty
          (CDx9ShaderKeeper *this,CDx9ShaderKeeper *param_1,ulong param_2,CPlugBitmap *param_3,
          CPlugBitmapSampler *param_4,EGxTexFilter *param_5)
{
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  CPlugBitmap *pCVar4;
  SCasterCat *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CPlugBitmapSampler *this_00;
  SCasterCat *pSVar7;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  _D3DSAMPLERSTATETYPE unaff_ESI;
  CDx9StateBlock *pCVar9;
  int *this_01;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int *piVar10;
  CPlugBitmap *pCVar11;
  CPlugBitmap *pCVar12;
  CDx9ShaderKeeper *pCVar13;
  float fStack_8;
  
  pCVar13 = param_1;
  iVar3 = (**(code **)(**(int **)(this + 0xc) + 0xa4))();
  if (((*(CDx9ShaderKeeper **)(iVar3 + 0x1c) != param_1) || (param_2 != 0)) ||
     (param_3 != (CPlugBitmap *)0x0)) {
    if (DAT_00d7582c == this) {
      DAT_00d7582c = (CDx9ShaderKeeper *)0x0;
    }
    pCVar4 = (CPlugBitmap *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,unaff_EDI);
    param_3 = (CPlugBitmap *)0x0;
    if (pCVar4 != (CPlugBitmap *)0x0) {
      do {
        pCVar11 = (CPlugBitmap *)0x96dec5;
        pCVar12 = param_3;
        pSVar5 = CFastArray<struct_CDx9ShaderKeeper::SPassDesc>::operator[]
                           (this + 0x34,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_3,
                            (ulong)pCVar13);
        pCVar9 = (CDx9StateBlock *)0x0;
        if ((CDx9StateBlock *)(*(uint *)(pSVar5 + 0x80) & 0x7fffffff) != (CDx9StateBlock *)0x0) {
          pSVar7 = pSVar5 + 0x88;
          do {
            if ((((*(uint *)pSVar7 & 2) != 0) && ((*(uint *)pSVar7 & 4) != 0)) &&
               (*(uint *)(pSVar7 + -4) == param_2)) {
              if (*(int *)(param_1 + 0x14) == 0) {
                pCVar12 = (CPlugBitmap *)0x96df1b;
                pCVar13 = param_1;
                (**(code **)(*DAT_00d75824 + 0xb0))();
              }
              CDx9StateBlock::RecordSetTexture(pSVar5,pCVar9,(ulong)param_1,pCVar11);
              if (param_2 == 0) {
                if (param_3 != (CPlugBitmap *)0x0) {
                  CDx9StateBlock::RecordSetSamplerFilter
                            (pSVar5,pCVar9,*(ulong *)param_3,*(uint *)(param_1 + 0x4c) >> 0x14 & 1,
                             (int)pCVar12);
                }
              }
              else {
                CDx9StateBlock::RecordSetSamplerFilter
                          (pSVar5,pCVar9,*(uint *)(param_2 + 0x20) >> 1 & 3,
                           *(uint *)(param_1 + 0x4c) >> 0x14 & 1,(int)pCVar12);
                if ((*(uint *)(DAT_00d75828 + 0x488) & 0x2000) != 0) {
                  fStack_8 = *(float *)(param_2 + 0x28);
                  if (fStack_8 < _DAT_00d123e8 != (fStack_8 == _DAT_00d123e8)) {
                    fStack_8 = _DAT_00d123e8;
                  }
                  CDx9StateBlock::RecordSetSamplerState
                            (pSVar5,pCVar9,8,(_D3DSAMPLERSTATETYPE)fStack_8,(ulong)pCVar13);
                }
                CDx9StateBlock::RecordSetSamplerState
                          (pSVar5,pCVar9,1,
                           *(_D3DSAMPLERSTATETYPE *)
                            (&DAT_00d75810 + (*(uint *)(param_2 + 0x20) >> 3 & 3) * 4),unaff_ESI);
                unaff_ESI = *(_D3DSAMPLERSTATETYPE *)
                             (&DAT_00d75810 + (*(uint *)(param_2 + 0x20) >> 5 & 3) * 4);
                pCVar13 = (CDx9ShaderKeeper *)0x2;
                CDx9StateBlock::RecordSetSamplerState(pSVar5,pCVar9,2,unaff_ESI,unaff_EBP);
              }
              break;
            }
            pCVar9 = pCVar9 + 1;
            pSVar7 = pSVar7 + 8;
          } while (pCVar9 < (CDx9StateBlock *)(*(uint *)(pSVar5 + 0x80) & 0x7fffffff));
        }
      } while (((CDx9StateBlock *)(*(uint *)(pSVar5 + 0x80) & 0x7fffffff) <= pCVar9) &&
              (param_3 = param_3 + 1, param_3 < pCVar4));
    }
    if (param_3 != pCVar4) {
      piVar10 = *(int **)(this + 0xc);
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (DAT_00d75824 + 0x161,(CFastBuffer<class_CCrystalFace*> *)pCVar13);
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      param_5 = (EGxTexFilter *)0x0;
      if ((*(uint *)((int)fStack_8 + 0x10) & 0x3fff) != 0) {
        do {
          if (pCVar8 < pCVar6) {
            this_01 = DAT_00d75824 + 0x161;
            do {
              pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 (this_01,pCVar8,unaff_ESI);
              piVar10 = *(int **)pSVar5;
              if ((CPlugBitmap *)piVar10[5] == pCVar4) break;
              pCVar8 = pCVar8 + 1;
            } while (pCVar8 < pCVar6);
          }
          if (pCVar8 == pCVar6) {
            return;
          }
          pCVar12 = (CPlugBitmap *)param_2;
          this_00 = (CPlugBitmapSampler *)(**(code **)(*piVar10 + 0xa4))();
          uVar2 = piVar10[7];
          bVar1 = *(byte *)((int)piVar10 + 0x1e);
          piVar10[7] = uVar2 | 0x10000;
          CPlugBitmapSampler::SetBitmap(this_00,(CPlugVolumeProjector *)param_2,pCVar12);
          piVar10[7] = ((uVar2 >> 0x11 & 1) * 2 | bVar1 & 1) << 0x10 | piVar10[7] & 0xfffcffffU;
          param_5 = (EGxTexFilter *)((int)param_5 + 1);
          pCVar8 = pCVar8 + 1;
        } while (param_5 < (EGxTexFilter *)(*(uint *)((int)fStack_8 + 0x10) & 0x3fff));
      }
    }
  }
  return;
}
}

