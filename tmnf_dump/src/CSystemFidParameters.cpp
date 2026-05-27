// Class implementation: CSystemFidParameters

// =================================================
// Function: CSystemFidParameters::AddParam
// =================================================
/* WARNING: Removing unreachable block (ram,0x00429720) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSystemFidParameters::AddParam
          (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2)
{
{
  CSystemFidParameters *this_00;
  SCasterCat SVar1;
  int *piVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  int iVar5;
  int iVar6;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar7;
  undefined1 *unaff_ESI;
  ulong unaff_EDI;
  bool bVar8;
  CSystemFidParameters *pCStack_c;
  
  this_00 = this + 4;
  pCVar7 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
            *)0x0;
  pSVar3 = CFastBuffer<unsigned_short>::operator[]
                     (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 4),
                      unaff_EDI);
  SVar1 = pSVar3[1];
  if ((CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)
      (uint)(byte)SVar1 !=
      (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)0x0
     ) {
    do {
      pSVar4 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(this_00,pCVar7,*(ulong *)(param_1 + 4),(ulong)unaff_ESI);
      piVar2 = *(int **)pSVar4;
      bVar8 = 0xfffffffe < _DAT_00d554b8;
      _DAT_00d554b8 = _DAT_00d554b8 + 1;
      _DAT_00d554bc = _DAT_00d554bc + (uint)bVar8;
      unaff_ESI = &stack0x0000000c;
      (**(code **)(*piVar2 + 0x10))(param_1,&stack0x00000000);
      if (param_2 == (SParam *)0x0) {
        iVar5 = (**(code **)(*piVar2 + 4))();
        iVar6 = (**(code **)(*(int *)param_1 + 4))();
        if (iVar5 == 0) {
          if (iVar6 != 0) {
            *(int *)(pCStack_c + 0x2c) = *(int *)(pCStack_c + 0x2c) + -1;
            (**(code **)(*piVar2 + 0xc))(param_1);
            return 1;
          }
        }
        else if (iVar6 == 0) {
          *(int *)(pCStack_c + 0x2c) = *(int *)(pCStack_c + 0x2c) + 1;
        }
        (**(code **)(*piVar2 + 0xc))(param_1);
        return 1;
      }
      pCVar7 = pCVar7 + 1;
      this = pCStack_c;
    } while (pCVar7 < (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                       *)(uint)(byte)SVar1);
  }
  param_2 = (SParam *)(**(code **)(*(int *)param_1 + 8))();
  CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::AddInCat
            (this_00,(CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&param_2
             ,*(CHmsCorpus ***)(param_2 + 4),(ulong)unaff_ESI);
  iVar5 = (**(code **)(*(int *)param_1 + 4))();
  if (iVar5 == 0) {
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  }
  return 1;
}
}

// =================================================
// Function: CSystemFidParameters::CSystemFidParameters
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemFidParameters::CSystemFidParameters
          (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2)
{
{
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *pCVar1;
  GmVec3 *unaff_ESI;
  ulong unaff_EDI;
  SNormalDec3N *in_stack_0000000c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a8254b;
  local_c = ExceptionList;
  pCVar1 = (CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)
           (DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(this + 4,pCVar1);
  CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::SetCatCount
            (this + 4,(CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                       *)&DAT_0000000a,unaff_EDI);
  operator=(this,in_stack_0000000c,unaff_ESI);
  _DAT_00d554b0 = _DAT_00d554b0 + 1;
  DAT_00d554a8 = DAT_00d554a8 + 1;
  if (DAT_00d554ac < DAT_00d554a8) {
    DAT_00d554ac = DAT_00d554a8;
  }
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::DoOneRemap
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemFidParameters::DoOneRemap
          (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFid *param_2,
          CSystemPackDesc **param_3,CFastString *param_4,ulong *param_5,
          CSystemFidParameters *param_6)
{
{
  CSystemFidParameters *this_00;
  SCasterCat SVar1;
  ulong *puVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  ulong uVar5;
  CSystemFidParameters *extraout_EAX;
  int iVar6;
  undefined *puVar7;
  CSystemFidParameters *extraout_EAX_00;
  CSystemFidParameters *extraout_EAX_01;
  SParam *unaff_EBX;
  CFastStringInt *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar8;
  CSystemFidParameters *pCVar9;
  ulong unaff_EDI;
  undefined *unaff_retaddr;
  CSystemFidParameters *in_stack_0000001c;
  undefined4 *in_stack_00000020;
  CSystemFidParameters *in_stack_00000024;
  CSystemFidParameters *in_stack_00000028;
  undefined4 *in_stack_00000030;
  CSystemFidParameters *in_stack_00000034;
  SParam *pSVar10;
  SParam *in_stack_ffffffa8;
  SStringParamInt *in_stack_ffffffac;
  CFastString *in_stack_ffffffb0;
  SParam *in_stack_ffffffb4;
  undefined4 local_44;
  undefined *local_40;
  undefined *local_3c;
  undefined *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_28;
  undefined *local_24;
  undefined4 local_20;
  void *local_c;
  undefined1 *puStack_8;
  undefined *puStack_4;
  
  puVar2 = param_5;
  puStack_4 = (undefined *)0xffffffff;
  puStack_8 = &LAB_00a824c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFid::ParametrizedGetLoadableFid
            ((CSystemFid *)param_1,(CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffff98));
  this_00 = this + 4;
  pSVar3 = CFastBuffer<unsigned_short>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,unaff_EDI);
  SVar1 = pSVar3[1];
  pCVar8 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
            *)0x0;
  if ((CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)
      (uint)(byte)SVar1 !=
      (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)0x0
     ) {
    do {
      pSVar4 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(this_00,pCVar8,1,(ulong)unaff_ESI);
      pCVar9 = *(CSystemFidParameters **)pSVar4;
      if (*(CFastString **)(pCVar9 + 0x24) == param_4) {
        *param_5 = *(ulong *)(pCVar9 + 0x14);
        local_40 = *(undefined **)(pCVar9 + 0x18);
        local_44 = *(undefined4 *)(pCVar9 + 0x1c);
        CFastString::SetString
                  ((CFastString *)param_6,(CFastStringInt *)&local_44,(SStringParam *)unaff_EBP);
        *in_stack_00000020 = *(undefined4 *)(pCVar9 + 0x20);
        AddParam(in_stack_00000024,pCVar9,unaff_EBX);
        ExceptionList = param_1;
        return;
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                       *)(uint)(byte)SVar1);
  }
  pCVar8 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
            *)0x0;
  if (*(int *)(in_stack_0000001c + 0x28) != 0) {
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(in_stack_0000001c + 0x10,unaff_ESI);
    if (uVar5 < 0x65) {
      SParam_Fid::SParam_Fid((SParam_Fid *)&local_28,(SParam_Fid *)param_4,(CSystemFid *)unaff_EBP);
      unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x429829;
      unaff_EBP = (CFastStringInt *)extraout_EAX;
      AddParam(in_stack_0000001c,extraout_EAX,unaff_EBX);
      if (puStack_4 != PTR_DAT_00bbf7d8) {
        unaff_EBX = (SParam *)(puStack_4 + -1);
        if ((puStack_4[-1] & 0x80) != 0) {
          unaff_EBX = (SParam *)(puStack_4 + -4);
        }
        unaff_EBP = (CFastStringInt *)0x42984f;
        operator_delete__(unaff_EBX);
      }
    }
    else {
      *(undefined4 *)(in_stack_0000001c + 0x28) = 0;
    }
  }
  pSVar3 = CFastBuffer<unsigned_short>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009,
                      (ulong)unaff_ESI);
  SVar1 = pSVar3[1];
  pCVar9 = in_stack_0000001c;
  if ((CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)
      (uint)(byte)SVar1 !=
      (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)0x0
     ) {
    do {
      pSVar4 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(this_00,pCVar8,9,(ulong)unaff_EBP);
      pCVar9 = *(CSystemFidParameters **)pSVar4;
      if ((_DAT_00d55578 & 1) == 0) {
        _DAT_00d55578 = _DAT_00d55578 | 1;
        DAT_00d55570 = 0;
        DAT_00d55574 = (undefined2 *)PTR_DAT_00bbf7dc;
        _atexit(`protected:_void___thiscall_CSystemFidParameters::
                DoOneRemap(class_CSystemFid*,class_CSystemPackDesc_const*&,class_CFastString&,unsigned_long&,class_DoOneRemap&)const_'
                ::__l19::_dynamic_atexit_destructor_for__TempName__);
      }
      if (DAT_00d55570 != 0) {
        DAT_00d55570 = 0;
        *DAT_00d55574 = 0;
      }
      unaff_EBP = *(CFastStringInt **)(pCVar9 + 0x24);
      iVar6 = CSystemFidFile::GetFullNameUpTo
                        ((CSystemFidFile *)param_5,(CSystemFidsDrive *)&DAT_00d55570,unaff_EBP,
                         (CSystemFids *)unaff_EBX);
      if (iVar6 != 0) {
        local_3c = (undefined *)0x0;
        local_38 = PTR_DAT_00bbf7dc;
        CSystemFileName::StripExtension((CFastStringInt *)&DAT_00d55570,(CFastStringInt *)&local_3c)
        ;
        local_34 = *(undefined4 *)(pCVar9 + 0x1c);
        local_30 = *(undefined4 *)(pCVar9 + 0x18);
        local_44 = 0;
        local_40 = PTR_DAT_00bbf7dc;
        CFastStringInt::SetString
                  (&local_44,(CFastStringInt *)&local_34,(SStringParam *)in_stack_ffffffa8);
        local_24 = local_40;
        local_28 = local_3c;
        local_20 = 0;
        CFastStringInt::ConcatBefore(&local_38,(CFastStringInt *)&local_28,in_stack_ffffffac);
        if (local_38 != PTR_DAT_00bbf7dc) {
          if ((local_38[-1] & 0x80) == 0) {
            puVar7 = local_38 + -2;
          }
          else {
            puVar7 = local_38 + -4;
          }
          operator_delete__(puVar7);
        }
        CFastStringInt::GetAscii(&local_34,(CFastStringInt *)in_stack_00000028,in_stack_ffffffb0);
        *(undefined4 *)in_stack_00000028 = *(undefined4 *)(pCVar9 + 0x14);
        *in_stack_00000030 = *(undefined4 *)(pCVar9 + 0x20);
        AddParam(in_stack_00000034,pCVar9,in_stack_ffffffb4);
        if (local_28 == PTR_DAT_00bbf7dc) {
          ExceptionList = param_1;
          return;
        }
        if ((local_28[-1] & 0x80) != 0) {
          operator_delete__(local_28 + -4);
          ExceptionList = param_1;
          return;
        }
        operator_delete__(local_28 + -2);
        ExceptionList = param_1;
        return;
      }
      pCVar8 = pCVar8 + 1;
      pCVar9 = in_stack_00000028;
    } while (pCVar8 < (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                       *)(uint)(byte)SVar1);
  }
  if (*(int *)(pCVar9 + 0x28) != 0) {
    uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (pCVar9 + 0x10,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
    if (uVar5 < 0x65) {
      SParam_Fids::SParam_Fids
                ((SParam_Fids *)&local_24,(SParam_Fids *)param_5[5],(CSystemFids *)unaff_EBX);
      unaff_EBP = (CFastStringInt *)0x429a3d;
      AddParam(in_stack_00000028,extraout_EAX_00,in_stack_ffffffa8);
      param_5 = (ulong *)0xffffffff;
      if (unaff_retaddr != PTR_DAT_00bbf7d8) {
        puVar7 = unaff_retaddr + -1;
        if ((unaff_retaddr[-1] & 0x80) != 0) {
          puVar7 = unaff_retaddr + -4;
        }
        operator_delete__(puVar7);
      }
      uVar5 = puVar2[5];
      if (*(int *)(uVar5 + 0x14) != 0) {
        pSVar10 = (SParam *)0x429a80;
        iVar6 = (**(code **)(**(int **)(uVar5 + 0x14) + 0x10))();
        if (iVar6 == 0) {
          SParam_Fids::SParam_Fids
                    ((SParam_Fids *)&local_28,*(SParam_Fids **)(puVar2[5] + 0x14),
                     (CSystemFids *)unaff_EBP);
          unaff_EBP = (CFastStringInt *)extraout_EAX_01;
          AddParam(in_stack_00000028,extraout_EAX_01,pSVar10);
          if (puStack_4 != PTR_DAT_00bbf7d8) {
            puVar7 = puStack_4 + -1;
            if ((puStack_4[-1] & 0x80) != 0) {
              puVar7 = puStack_4 + -4;
            }
            unaff_EBP = (CFastStringInt *)0x429aca;
            operator_delete__(puVar7);
          }
        }
      }
    }
    else {
      *(undefined4 *)(pCVar9 + 0x28) = 0;
    }
  }
  *param_5 = 0;
  *(undefined4 *)in_stack_0000001c = 0xffffffff;
  local_3c = &DAT_00b2c878;
  local_38 = (undefined *)0x0;
  CFastString::SetString
            ((CFastString *)param_6,(CFastStringInt *)&local_3c,(SStringParam *)unaff_EBP);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::DoesMatch
// =================================================
int __cdecl CSystemFidParameters::DoesMatch(ulong *param_1,CFastBuffer<unsigned_long> *param_2)
{
{
  ulong uVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  int iVar4;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong *puVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  ulong uStack0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CFastBuffer<unsigned_long> *in_stack_00000014;
  
  if ((param_1 != (ulong *)0x0) &&
     (uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_ESI), uVar2 != 0)) {
    uStack0000000c = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (uStack0000000c == 0) {
      return 0;
    }
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_2,pCVar6,unaff_EBX);
      uVar2 = *(ulong *)pSVar3;
      uVar1 = *param_1;
      puVar5 = param_1;
      while (uVar1 != 0xffffffff) {
        unaff_EBX = *puVar5;
        iVar4 = CMwNod::StaticMwIsKindOf(uVar2,unaff_EBX);
        if (iVar4 != 0) {
          return 1;
        }
        puVar5 = puVar5 + 1;
        uVar1 = *puVar5;
      }
      pCVar6 = pCVar6 + 1;
      param_2 = in_stack_00000014;
    } while (pCVar6 < in_stack_00000010);
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CSystemFidParameters::GetCurrentParameters
// =================================================
CSystemFidParameters * __cdecl CSystemFidParameters::GetCurrentParameters(void)
{
{
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_00000008;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,unaff_retaddr);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::GetLastElem(&DAT_00d5553c,in_stack_00000008);
    return (CSystemFidParameters *)pSVar2;
  }
  return (CSystemFidParameters *)&DAT_00d55500;
}
}

// =================================================
// Function: CSystemFidParameters::GetParamValue
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSystemFidParameters::GetParamValue
          (CSystemFidParameters *this,CSystemFidParameters *param_1,SParam *param_2)
{
{
  CSystemFidParameters *this_00;
  SCasterCat SVar1;
  CSystemFidParameters *pCVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  undefined1 *unaff_ESI;
  ulong unaff_EDI;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar5;
  bool bVar6;
  
  pCVar2 = param_1;
  this_00 = this + 4;
  pSVar3 = CFastBuffer<unsigned_short>::operator[]
                     (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(param_1 + 4),
                      unaff_EDI);
  SVar1 = pSVar3[1];
  pCVar5 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
            *)0x0;
  if ((CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)
      (uint)(byte)SVar1 !=
      (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *)0x0
     ) {
    do {
      bVar6 = 0xfffffffe < _DAT_00d554b8;
      _DAT_00d554b8 = _DAT_00d554b8 + 1;
      _DAT_00d554bc = _DAT_00d554bc + (uint)bVar6;
      pSVar4 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(this_00,pCVar5,*(ulong *)(pCVar2 + 4),(ulong)unaff_ESI);
      unaff_ESI = &stack0x0000000c;
      (**(code **)(**(int **)pSVar4 + 0x10))(pCVar2,&param_1);
      if (param_2 == (SParam *)0x0) {
        pSVar4 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
                 GetElemInCat(this_00,pCVar5,*(ulong *)(pCVar2 + 4),(ulong)unaff_ESI);
        (**(code **)(*(int *)pCVar2 + 0xc))(*(undefined4 *)pSVar4);
        return 1;
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                       *)(uint)(byte)SVar1);
  }
  return 0;
}
}

// =================================================
// Function: CSystemFidParameters::Includes
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSystemFidParameters::Includes
          (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2,
          ulong param_3,int param_4)
{
{
  SCasterCat SVar1;
  int *piVar2;
  ulong uVar3;
  CFastBuffer<class_GxVertex2> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  GmQuat *pGVar7;
  int iVar8;
  SSamplerState *pSVar9;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar10;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CSystemFidParameters *this_00;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  bool bVar12;
  int unaff_retaddr;
  CSystemFidParameters *in_stack_00000018;
  CFastBuffer<unsigned_long> *in_stack_00000020;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe0;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe8;
  ulong in_stack_ffffffec;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCStack_c;
  int local_4;
  
  _DAT_00d554b4 = _DAT_00d554b4 + 1;
  if ((*(int *)(param_1 + 0x2c) == 0) && (*(int *)(this + 0x2c) == 0)) {
    _DAT_00d554c0 = _DAT_00d554c0 + 1;
    return 1;
  }
  if ((_DAT_00d5556c & 1) == 0) {
    _DAT_00d5556c = _DAT_00d5556c | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d55560,unaff_EBP);
    _atexit(`protected:_int___thiscall_CSystemFidParameters::
            Includes(class_Includes_const&,unsigned_long,int)const_'::__l5::
            _dynamic_atexit_destructor_for__SpecificParamsUsed__);
  }
  pCVar4 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x10,unaff_EDI);
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::AllocSetCount(&DAT_00d55560,pCVar4,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55560,unaff_EBX);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                         (&DAT_00d55560,pCVar11,(ulong)in_stack_ffffffe0);
      pCVar11 = pCVar11 + 1;
      *pSVar6 = (SCasterCat)0x0;
    } while (pCVar11 < pCVar5);
  }
  param_4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x10,in_stack_ffffffe0);
  pCStack_c = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
  if (param_4 != 0) {
    this_00 = param_1 + 4;
    pCVar5 = in_stack_ffffffe8;
    do {
      pGVar7 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                         (this + 4,pCStack_c,(ulong)in_stack_ffffffe4);
      piVar2 = *(int **)pGVar7;
      iVar8 = DoesMatch((ulong *)piVar2[2],in_stack_00000020);
      in_stack_ffffffe8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)piVar2[1];
      pSVar6 = CFastBuffer<unsigned_short>::operator[](this_00,in_stack_ffffffe8,(ulong)pCVar5);
      SVar1 = *pSVar6;
      in_stack_ffffffe4 = (CFastBuffer<class_CCrystalFace*> *)0x429254;
      pSVar6 = CFastBuffer<unsigned_short>::operator[](this_00,in_stack_ffffffe8,in_stack_ffffffec);
      param_4 = (int)(byte)pSVar6[1];
      pCVar10 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                 *)0x0;
      if (param_4 != 0) {
        do {
          param_3 = (ulong)CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                                     (&DAT_00d55560,
                                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                      (pCVar10 + local_4),(ulong)in_stack_ffffffe4);
          if (*(SCasterCat *)param_3 == (SCasterCat)0x0) {
            pSVar9 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
                     GetElemInCat(this_00,pCVar10,piVar2[1],(ulong)in_stack_ffffffe8);
            bVar12 = 0xfffffffe < _DAT_00d554b8;
            _DAT_00d554b8 = _DAT_00d554b8 + 1;
            _DAT_00d554bc = _DAT_00d554bc + (uint)bVar12;
            in_stack_ffffffe8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&param_2;
            in_stack_ffffffe4 = (CFastBuffer<class_CCrystalFace*> *)&stack0x00000014;
            (**(code **)(**(int **)pSVar9 + 0x10))(piVar2);
            if (unaff_retaddr == 0) {
              *param_2 = (CSystemFidParameters)0x1;
              uVar3 = param_3;
              goto LAB_004292e0;
            }
          }
          pCVar10 = pCVar10 + 1;
        } while (pCVar10 < (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                            *)(uint)(byte)SVar1);
      }
      if ((iVar8 != 0) && (iVar8 = (**(code **)(*piVar2 + 4))(), iVar8 == 0)) {
        if (piVar2[3] != 0) {
          return 0;
        }
        uVar3 = *(ulong *)(in_stack_00000018 + 0x28);
LAB_004292e0:
        if (uVar3 == 0) {
          return 0;
        }
      }
      pCStack_c = pCStack_c + 1;
      param_1 = in_stack_00000018;
      pCVar5 = in_stack_ffffffe8;
    } while (pCStack_c < (uint)param_4);
  }
  if (in_stack_00000020 == (CFastBuffer<unsigned_long> *)0x0) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(param_1 + 0x10,in_stack_ffffffe4);
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                           (&DAT_00d55560,pCVar11,(ulong)in_stack_ffffffe8);
        if (*pSVar6 == (SCasterCat)0x0) {
          in_stack_ffffffe8 = pCVar11;
          pGVar7 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                             (param_1 + 4,(CFastBufferCat<class_GmQuat,struct_SFastCat> *)pCVar11,
                              in_stack_ffffffec);
          in_stack_ffffffec = 0x429342;
          iVar8 = (**(code **)(**(int **)pGVar7 + 4))();
          if (iVar8 == 0) {
            return 0;
          }
        }
        pCVar11 = pCVar11 + 1;
      } while (pCVar11 < pCVar5);
    }
  }
  _DAT_00d554c0 = _DAT_00d554c0 + 1;
  return 1;
}
}

// =================================================
// Function: CSystemFidParameters::MergeForChildFid
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSystemFidParameters::MergeForChildFid
          (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2,
          CSystemFid *param_3,ulong param_4)
{
{
  int iVar1;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  GmFrustumIso4 *unaff_retaddr;
  int in_stack_00000014;
  
  if ((_DAT_00d55588 & 1) == 0) {
    _DAT_00d55588 = _DAT_00d55588 | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d5557c,unaff_ESI);
    _atexit(`public:_int___thiscall_CSystemFidParameters::
            MergeForChildFid(class_MergeForChildFid_const&,class_CSystemFid*,unsigned_long)'::__l2::
            _dynamic_atexit_destructor_for__TempClassIds__);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d5557c,unaff_retaddr);
  if (in_stack_00000014 != -1) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d5557c,(TiXmlAttributeSet *)&stack0x00000014,(TiXmlAttribute *)param_1);
  }
  iVar1 = MergeForClassIds(this,(CSystemFidParameters *)param_4,
                           (CSystemFidParameters *)&DAT_00d5557c,
                           (CFastBuffer<class_CSystemFid*> *)param_2);
  return iVar1;
}
}

// =================================================
// Function: CSystemFidParameters::MergeForClassIds
// =================================================
int __thiscall
CSystemFidParameters::MergeForClassIds
          (CSystemFidParameters *this,CSystemFidParameters *param_1,CSystemFidParameters *param_2,
          CFastBuffer<class_CSystemFid*> *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  int iVar3;
  CFastBuffer<class_CGamePlayerScore*> *unaff_EBX;
  CFastBuffer<class_CSystemFid*> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  GmFrustumIso4 *unaff_EDI;
  CGamePlayerScore **unaff_retaddr;
  ulong in_stack_00000018;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(&DAT_00d55554,unaff_EDI);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_3,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_3,pCVar4,(ulong)unaff_EBP);
      in_stack_00000018 = CSystemFid::GetClassId(*(CSystemFid **)pSVar2,(CSystemFid *)unaff_EBX);
      unaff_EBX = (CFastBuffer<class_CGamePlayerScore*> *)&stack0x00000018;
      unaff_EBP = (CFastBuffer<class_CSystemFid*> *)0x429c45;
      CFastBuffer<class_CGamePlayerScore*>::FindOrAdd(&DAT_00d55554,unaff_EBX,unaff_retaddr);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  iVar3 = MergeForClassIds(this,(CSystemFidParameters *)param_3,
                           (CSystemFidParameters *)&DAT_00d55554,unaff_EBP);
  return iVar3;
}
}

// =================================================
// Function: CSystemFidParameters::Pop
// =================================================
void __thiscall CSystemFidParameters::Pop(CSystemFidParameters *this,SCharStyle *param_1)
{
{
  ulong uVar1;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  CFastBuffer<class_CCrystalFace*> *in_stack_00000008;
  ulong in_stack_0000000c;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55530,unaff_retaddr);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (&DAT_00d55530,(CFastBuffer<class_CSystemFidsFolder*> *)(uVar1 - 1),(ulong)param_1);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,in_stack_00000008);
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (&DAT_00d5553c,(CFastBuffer<class_CSystemFidsFolder*> *)(uVar1 - 1),in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CSystemFidParameters::PopForFid
// =================================================
void __cdecl CSystemFidParameters::PopForFid(CSystemFid *param_1,ulong param_2)
{
{
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  CSystemFidParameters *this;
  CFastBuffer<class_CCrystalFace*> *unaff_retaddr;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,unaff_retaddr);
  if (uVar1 != 0) {
    pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem
                       (&DAT_00d55530,
                        (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                        param_1);
    Pop(this,*(SCharStyle **)pSVar2);
  }
  return;
}
}

// =================================================
// Function: CSystemFidParameters::Push
// =================================================
void __thiscall
CSystemFidParameters::Push
          (CSystemFidParameters *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  SLoadedLight *this_00;
  ulong uVar1;
  SNormalDec3N *pSVar2;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar3;
  GmQuat *pGVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar7;
  TiXmlAttribute *unaff_EDI;
  GmVec3 *unaff_retaddr;
  SNormalDec3N *in_stack_0000000c;
  int in_stack_00000010;
  int in_stack_00000018;
  CSystemFidParameters *pCVar8;
  
  CFastBuffer<class_CDx9TextureKeeper*>::Add(&DAT_00d55530,(TiXmlAttributeSet *)&param_1,unaff_EDI);
  this_00 = CFastBuffer<class_CSystemFidParameters>::AddNewElem(&DAT_00d5553c,unaff_ESI);
  if (in_stack_00000010 == 0) {
    operator=((CSystemFidParameters *)this_00,in_stack_0000000c,(GmVec3 *)unaff_EBP);
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,unaff_EBX);
    if (1 < uVar1) {
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 2);
      pCVar8 = (CSystemFidParameters *)0x42a2a4;
      pSVar6 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](&DAT_00d5553c,pCVar5,(ulong)unaff_retaddr);
      unaff_retaddr = (GmVec3 *)0x42a2ae;
      pCVar3 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (pSVar6 + 0x10,(CFastBuffer<class_CCrystalFace*> *)param_1);
      pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
      if (pCVar3 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
        do {
          pGVar4 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                             (pSVar6 + 4,pCVar7,(ulong)pCVar8);
          pCVar8 = *(CSystemFidParameters **)pGVar4;
          AddParam((CSystemFidParameters *)this_00,pCVar8,(SParam *)pCVar5);
          pCVar7 = pCVar7 + 1;
        } while (pCVar7 < pCVar3);
      }
    }
  }
  else {
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,unaff_EBP);
    if (uVar1 < 2) {
      pSVar2 = (SNormalDec3N *)&DAT_00d55500;
    }
    else {
      pSVar2 = (SNormalDec3N *)
               CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](&DAT_00d5553c,
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 - 2),
                            (ulong)unaff_EBX);
    }
    pCVar8 = (CSystemFidParameters *)0x42a242;
    operator=((CSystemFidParameters *)this_00,pSVar2,unaff_retaddr);
    unaff_retaddr = (GmVec3 *)0x42a24e;
    pCVar3 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((void *)(in_stack_00000018 + 0x10),
                        (CFastBuffer<class_CCrystalFace*> *)param_1);
    pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
    if (pCVar3 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
      do {
        pGVar4 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                           ((void *)(in_stack_00000018 + 4),pCVar7,(ulong)pCVar8);
        pCVar8 = *(CSystemFidParameters **)pGVar4;
        AddParam((CSystemFidParameters *)this_00,pCVar8,(SParam *)pSVar2);
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar3);
    }
  }
  *(undefined4 *)(this_00 + 0x28) = 0;
  Simplify((CSystemFidParameters *)this_00,(CSystemFidParameters *)0xffffffff,(ulong)unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSystemFidParameters::PushForFid
// =================================================
/* WARNING: Variable defined which should be unmapped: param_2 */

void __cdecl CSystemFidParameters::PushForFid(CSystemFid *param_1,ulong param_2)
{
{
  CSystemFidParameters *pCVar1;
  ulong uVar2;
  SLoadedLight *this;
  SCasterCat *pSVar3;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar4;
  GmQuat *pGVar5;
  int iVar6;
  CFastBuffer<class_CCrystalFace*> *in_ECX;
  GmVec3 *unaff_EBX;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar7;
  TiXmlAttribute *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  SParam *in_stack_0000000c;
  CSystemFidParameters *in_stack_0000001c;
  CFastBuffer<unsigned_long> *in_stack_00000028;
  
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,in_ECX);
  if (uVar2 != 0) {
    pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
    pCVar8 = (CFastBuffer<class_CCrystalFace*> *)0x0;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d55530,(TiXmlAttributeSet *)&stack0x00000000,unaff_EDI);
    this = CFastBuffer<class_CSystemFidParameters>::AddNewElem(&DAT_00d5553c,unaff_ESI);
    operator=((CSystemFidParameters *)this,(SNormalDec3N *)&DAT_00d55500,unaff_EBX);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d5553c,pCVar8);
    pSVar3 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
             ::operator[](&DAT_00d5553c,
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar2 - 2),
                          (ulong)param_1);
    pCVar4 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pSVar3 + 0x10,(CFastBuffer<class_CCrystalFace*> *)this);
    if (pCVar4 != (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0) {
      param_2 = unaff_EBP;
      do {
        pGVar5 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll(pSVar3 + 4,pCVar7,param_2);
        pCVar1 = *(CSystemFidParameters **)pGVar5;
        param_2 = (ulong)in_stack_00000028;
        iVar6 = DoesMatch(*(ulong **)(pCVar1 + 8),in_stack_00000028);
        if (iVar6 != 0) {
          AddParam(in_stack_0000001c,pCVar1,in_stack_0000000c);
          param_2 = (ulong)pCVar1;
        }
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar4);
    }
  }
  return;
}
}

// =================================================
// Function: CSystemFidParameters::Remap
// =================================================
CMwId * __thiscall
CSystemFidParameters::Remap(CSystemFidParameters *this,SIdRemapTable *param_1,CMwId *param_2)
{
{
  CSystemPackManager *pCVar1;
  CSystemFid *pCVar2;
  CSystemFidFile *extraout_EAX;
  CMwId *pCVar3;
  undefined *puVar4;
  CMwId *extraout_EAX_00;
  CSystemFidParameters *pCVar5;
  CMwNod *unaff_EDI;
  ulong *in_stack_0000000c;
  CSystemFid *in_stack_00000010;
  CSystemFid local_28 [4];
  CSystemPackManager *local_24;
  CSystemPackDesc *local_20;
  undefined *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00a824e8;
  local_14 = ExceptionList;
  pCVar2 = (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffffc8);
  ExceptionList = &local_14;
  local_20 = (CSystemPackDesc *)0x0;
  local_1c[0] = PTR_DAT_00bbf7d8;
  pCVar5 = *(CSystemFidParameters **)param_1;
  local_c = 0;
  while( true ) {
    DoOneRemap(this,pCVar5,local_28,&local_20,(CFastString *)&local_24,in_stack_0000000c,
               (CSystemFidParameters *)pCVar2);
    pCVar1 = local_24;
    pCVar3 = (CMwId *)extraout_EAX;
    if ((local_1c[0] != (undefined *)0x0) && (DAT_00d54250 != (CSystemPackManager *)0x0)) {
      pCVar2 = in_stack_00000010;
      pCVar3 = (CMwId *)CSystemPackManager::GetPackElem
                                  (DAT_00d54250,local_24,(CSystemPackDesc *)local_1c,
                                   (CFastString *)local_20,(ulong)pCVar5,in_stack_00000010,unaff_EDI
                                  );
      *(CMwId **)param_2 = pCVar3;
    }
    if ((*(CSystemFidParameters **)param_2 == pCVar5) || (pCVar1 != (CSystemPackManager *)0x0))
    break;
    *(CSystemFidParameters **)param_1 = pCVar5;
    pCVar5 = *(CSystemFidParameters **)param_2;
  }
  if (local_1c[0] != PTR_DAT_00bbf7d8) {
    puVar4 = local_1c[0] + -1;
    if ((local_1c[0][-1] & 0x80) != 0) {
      puVar4 = local_1c[0] + -4;
    }
    operator_delete__(puVar4);
    pCVar3 = extraout_EAX_00;
  }
  ExceptionList = local_14;
  return pCVar3;
}
}

// =================================================
// Function: CSystemFidParameters::RemappedLoadFromFid
// =================================================
int __cdecl
CSystemFidParameters::RemappedLoadFromFid(CMwNod **param_1,CSystemFid *param_2,CMwNod *param_3)
{
{
  CSystemFidParameters *pCVar1;
  CSystemFidParameters *this;
  ulong uVar2;
  int iVar3;
  CSystemFidParameters *unaff_EDI;
  CSystemFidParameters *in_stack_00000014;
  CSystemFid *pCVar4;
  CSystemFidParameters local_3c [4];
  SIdRemapTable local_38 [4];
  CSystemFid local_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a82578;
  local_c = ExceptionList;
  pCVar1 = (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  this = GetCurrentParameters();
  CSystemFidParameters(local_3c,pCVar1,unaff_EDI);
  pCVar4 = local_34;
  Remap(this,local_38,(CMwId *)&stack0x00000010);
  uVar2 = CSystemFid::GetClassId(param_2,pCVar4);
  PushForFid(param_2,uVar2);
  iVar3 = CSystemArchiveNod::LoadFromFid((CMwNod **)param_2,param_2,7);
  PopForFid(param_2,uVar2);
  ~CSystemFidParameters((CSystemFidParameters *)local_38,in_stack_00000014);
  ExceptionList = local_4;
  return iVar3;
}
}

// =================================================
// Function: CSystemFidParameters::RemappedLoadFromFid<class_CMwNod>
// =================================================
int __cdecl
CSystemFidParameters::RemappedLoadFromFid<class_CMwNod>
          (CMwNodRef<class_CMwNod> *param_1,CSystemFid *param_2,CMwNod *param_3)
{
{
  int iVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *local_4;
  
  iVar1 = RemappedLoadFromFid(&local_4,param_2,param_3);
  if (local_4 != *(CMwNod **)param_1) {
    if (local_4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
    }
    if (*(CMwNod **)param_1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)param_1,unaff_ESI);
    }
    *(CMwNod **)param_1 = local_4;
  }
  return iVar1;
}
}

// =================================================
// Function: CSystemFidParameters::Simplify
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemFidParameters::Simplify
          (CSystemFidParameters *this,CSystemFidParameters *param_1,ulong param_2)
{
{
  CSystemFidParameters *this_00;
  int *piVar1;
  ulong uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int iVar5;
  GmQuat *pGVar6;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCVar7;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CSystemFidParameters *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  bool bVar9;
  int unaff_retaddr;
  ulong in_stack_0000000c;
  int in_stack_00000010;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe4;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffe8;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCStack_10;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *pCStack_c;
  CSystemFidParameters *local_8;
  CFastBufferCat<class_GmQuat,struct_SFastCat> *local_4;
  
  CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x10,unaff_EDI);
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                    (this + 0x10,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  if (DAT_00d554c4 < uVar2) {
    DAT_00d554c4 = uVar2;
  }
  if (in_stack_0000000c != 0xffffffff) {
    unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x429cb2;
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55548,unaff_EBP);
    pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d55548,pCVar8,(ulong)unaff_EBX);
        unaff_EBX = *(CFastBuffer<class_CCrystalFace*> **)pSVar4;
        unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x429cd4;
        iVar5 = CMwNod::StaticMwIsKindOf(in_stack_0000000c,(ulong)unaff_EBX);
        if (iVar5 != 0) {
          unaff_EBX = (CFastBuffer<class_CCrystalFace*> *)0x429cec;
          CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::DeleteAll
                    (this + 4,(CFastArray<class_CCrystalEdge*> *)0x429cec);
          *(undefined4 *)(this + 0x28) = 1;
          *(undefined4 *)(this + 0x2c) = 0;
          break;
        }
        pCVar8 = pCVar8 + 1;
      } while (pCVar8 < pCVar3);
    }
  }
  this_01 = this + 0x10;
  local_4 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)0x0;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBX);
  if (uVar2 != 0) {
    this_00 = this + 4;
    do {
      uVar2 = 0x429d28;
      pCVar10 = (CFastBuffer<class_CCrystalFace*> *)local_4;
      pGVar6 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                         (this_00,local_4,(ulong)in_stack_ffffffe4);
      pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pGVar6;
      pCVar8 = unaff_ESI;
      if (*(int *)(this + 0x28) == 0) {
        in_stack_ffffffe4 = (CFastBuffer<class_CCrystalFace*> *)0x429d3a;
        iVar5 = (**(code **)(*(int *)pCVar3 + 4))();
        pCVar8 = unaff_ESI;
        if (iVar5 == 0) goto LAB_00429d3e;
LAB_00429d53:
        iVar5 = (**(code **)(*(int *)pCVar3 + 4))();
        if (iVar5 == 0) {
          *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
        }
        (*(code *)**(undefined4 **)pCVar3)(1);
        unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_4;
        CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
        ReplaceByLastInAllAt
                  (this_00,(CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>
                            *)local_4,uVar2);
        local_4 = local_4 + -1;
        pCStack_10 = pCStack_10 + -1;
      }
      else {
LAB_00429d3e:
        iVar5 = DoesMatch(*(ulong **)(pCVar3 + 8),(CFastBuffer<unsigned_long> *)param_2);
        if (iVar5 == 0) goto LAB_00429d53;
        unaff_ESI = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pCVar3 + 4);
        pSVar4 = CFastBuffer<unsigned_short>::operator[](this_00,unaff_ESI,(ulong)pCVar8);
        pCStack_c = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)(uint)(byte)*pSVar4;
        pSVar4 = CFastBuffer<unsigned_short>::operator[](this_00,unaff_ESI,uVar2);
        pCVar7 = pCStack_10;
        if (pCStack_10 < pCStack_c) {
          pCVar7 = pCStack_c;
        }
        pCStack_c = pCStack_c + (byte)pSVar4[1];
        this = local_8;
        if (pCVar7 < pCStack_c) {
          do {
            pGVar6 = CFastBufferCat<int,struct_SFastCat>::GetElemInAll
                               (this_00,pCVar7,(ulong)pCVar10);
            piVar1 = *(int **)pGVar6;
            bVar9 = 0xfffffffe < _DAT_00d554b8;
            _DAT_00d554b8 = _DAT_00d554b8 + 1;
            _DAT_00d554bc = _DAT_00d554bc + (uint)bVar9;
            pCVar10 = (CFastBuffer<class_CCrystalFace*> *)&param_1;
            unaff_ESI = pCVar3;
            (**(code **)(*piVar1 + 0x10))(pCVar3,&stack0x0000000c);
            if (unaff_retaddr == 0) {
              iVar5 = (**(code **)(*piVar1 + 4))();
              if (iVar5 == 0) {
                *(int *)(local_8 + 0x2c) = *(int *)(local_8 + 0x2c) + -1;
              }
              uVar2 = 1;
              (**(code **)*piVar1)();
              unaff_ESI = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar7;
              CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
              ReplaceByLastInAllAt
                        (this_00,(CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>
                                  *)pCVar7,uVar2);
              pCVar7 = pCVar7 + -1;
              pCStack_c = pCStack_c + -1;
            }
            pCVar7 = pCVar7 + 1;
          } while (pCVar7 < pCStack_c);
        }
      }
      pCStack_10 = pCStack_10 + 1;
      this_01 = this + 0x10;
      local_4 = local_4 + 1;
      pCVar7 = (CFastBufferCat<class_GmQuat,struct_SFastCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this_01,pCVar10);
    } while (local_4 < pCVar7);
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,in_stack_ffffffe4);
  if (DAT_00d554c8 < uVar2) {
    DAT_00d554c8 = uVar2;
  }
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_01,in_stack_ffffffe8);
  if (DAT_00d554cc < in_stack_00000010 - uVar2) {
    DAT_00d554cc = in_stack_00000010 - uVar2;
  }
  return;
}
}

// =================================================
// Function: CSystemFidParameters::~CSystemFidParameters
// =================================================
void __thiscall
CSystemFidParameters::~CSystemFidParameters
          (CSystemFidParameters *this,CSystemFidParameters *param_1)
{
{
  CFastArray<class_CCrystalEdge*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  void *unaff_retaddr;
  CSystemFidParameters *pCVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a8240b;
  local_c = ExceptionList;
  pCVar1 = (CFastArray<class_CCrystalEdge*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  pCVar2 = this;
  CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::DeleteAll
            (this + 4,pCVar1);
  DAT_00d554a8 = DAT_00d554a8 + -1;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x10,unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 4,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar2);
  ExceptionList = unaff_retaddr;
  return;
}
}

