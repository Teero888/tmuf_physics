// Class implementation: CSystemFids

// =================================================
// Function: CSystemFids::AddCompareTree
// =================================================
void __thiscall
CSystemFids::AddCompareTree
          (CSystemFids *this,CSystemFids *param_1,CFastBuffer<class_CSystemFids*> *param_2)
{
{
  CSystemFids *this_00;
  SCasterCat *pSVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CPlugTree *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  uint uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  ulong uStack0000000c;
  ulong in_stack_fffffff8;
  
  this_00 = this + 0x28;
  CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  uStack0000000c = CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EBP);
  if (uStack0000000c != 0) {
    uVar4 = 0;
    do {
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (unaff_retaddr != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar3,(ulong)unaff_ESI);
          unaff_ESI = *(CPlugTree **)(*(int *)(param_2 + 4) + uVar4 * 4);
          iVar2 = (**(code **)(**(int **)pSVar1 + 0x80))();
          if (iVar2 != 0) {
            pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar3,(ulong)unaff_ESI);
            AddCompareTree(*(CSystemFids **)pSVar1,
                           (CSystemFids *)(*(int *)(*(int *)(param_2 + 4) + uVar4 * 4) + 0x28),
                           (CFastBuffer<class_CSystemFids*> *)unaff_EBX);
            pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_00,pCVar3,in_stack_fffffff8);
            in_stack_fffffff8 = *(ulong *)pSVar1;
            unaff_EBX = *(CMwNod **)(*(int *)(param_2 + 4) + uVar4 * 4);
            unaff_ESI = (CPlugTree *)0x43133e;
            SetTravelInfo(unaff_EBX,in_stack_fffffff8);
            goto LAB_004312fb;
          }
          pCVar3 = pCVar3 + 1;
        } while (pCVar3 < unaff_retaddr);
      }
      ClearTravelInfoDown(*(CSystemFids **)(*(int *)(param_2 + 4) + uVar4 * 4),
                          (CSystemFids *)unaff_ESI);
      unaff_ESI = *(CPlugTree **)(*(int *)(param_2 + 4) + uVar4 * 4);
      AddTree(unaff_ESI);
LAB_004312fb:
      uVar4 = uVar4 + 1;
    } while (uVar4 < uStack0000000c);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::AddLeave
// =================================================
void __thiscall CSystemFids::AddLeave(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2)
{
{
  TiXmlAttribute *unaff_ESI;
  CSystemFid *unaff_EDI;
  
  ConnectLeave(this,param_1,unaff_EDI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add(this + 0x1c,(TiXmlAttributeSet *)&param_2,unaff_ESI);
  (**(code **)(*(int *)this + 0xa4))(param_1);
  return;
}
}

// =================================================
// Function: CSystemFids::AddLeaveIfNot
// =================================================
void __thiscall
CSystemFids::AddLeaveIfNot(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2)
{
{
  int iVar1;
  GxTexCoordSet *unaff_ESI;
  CSystemFid *unaff_retaddr;
  
  iVar1 = CFastArray<class_CGameMenuFrame*>::Find
                    (this + 0x1c,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
  if (iVar1 == -1) {
    AddLeave(this,(CSystemFids *)param_2,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::AddTree
// =================================================
void __cdecl CSystemFids::AddTree(CPlugTree *param_1)
{
{
  CSystemFids *in_ECX;
  TiXmlAttribute *unaff_ESI;
  CSystemFids *unaff_EDI;
  
  ConnectTree(in_ECX,(CSystemFids *)param_1,unaff_EDI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            (in_ECX + 0x28,(TiXmlAttributeSet *)&stack0x00000008,unaff_ESI);
  (**(code **)(*(int *)in_ECX + 0xa0))(param_1);
  return;
}
}

// =================================================
// Function: CSystemFids::CSystemFids
// =================================================
void __thiscall CSystemFids::CSystemFids(CSystemFids *this,CSystemFids *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_00000008;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x1c,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x28,in_stack_00000008);
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: CSystemFids::ClearChildTravelInfo
// =================================================
void __cdecl CSystemFids::ClearChildTravelInfo(CSystemFids *param_1)
{
{
  int *piVar1;
  int *piVar2;
  ulong uVar3;
  int iVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  SCasterCat *pSVar6;
  SFillValue *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EDI;
  void *in_stack_00000008;
  int *in_stack_00000010;
  SFillValue *pSVar8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffd8;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffdc;
  SScanner local_20 [4];
  int *local_1c;
  undefined *local_18;
  undefined4 local_14;
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a82e48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar3 = CFastBuffer<struct_SCtnForcedMods::SEnvMod>::GetAllocatedSize
                    (&DAT_00d55680,
                     (CFastBuffer<struct_SCtnForcedMods::SEnvMod> *)
                     (DAT_00cca150 ^ (uint)&stack0xffffffd0));
  if (uVar3 != 0) {
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_14,unaff_EDI);
    local_18 = &DAT_00d55680;
    local_14 = 0;
    iVar4 = CFastMapTable<unsigned_long>::SScanner::GetNext
                      (&local_18,local_20,(ulong *)&local_1c,unaff_ESI);
    piVar1 = local_1c;
    while (iVar4 != 0) {
      pSVar8 = (SFillValue *)0xb008000;
      local_1c = piVar1;
      iVar4 = (**(code **)(*piVar1 + 0x10))();
      piVar2 = piVar1;
      if (iVar4 != 0) {
        piVar2 = (int *)piVar1[5];
      }
      for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[5]) {
        if (piVar2 == in_stack_00000010) {
          local_1c = piVar1;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    (auStack_10,(TiXmlAttributeSet *)&local_1c,(TiXmlAttribute *)pSVar8);
          break;
        }
      }
      iVar4 = CFastMapTable<unsigned_long>::SScanner::GetNext
                        (&local_18,local_20,(ulong *)&local_1c,pSVar8);
      piVar1 = local_1c;
    }
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(&local_c,in_stack_ffffffd8);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](&local_8,pCVar7,0);
        SetTravelInfo(*(CMwNod **)pSVar6,(ulong)in_stack_ffffffdc);
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < pCVar5);
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_8,in_stack_ffffffdc);
  }
  ExceptionList = in_stack_00000008;
  return;
}
}

// =================================================
// Function: CSystemFids::ClearTravelInfoDown
// =================================================
void __thiscall CSystemFids::ClearTravelInfoDown(CSystemFids *this,CSystemFids *param_1)
{
{
  ClearChildTravelInfo(this);
  return;
}
}

// =================================================
// Function: CSystemFids::ConnectLeave
// =================================================
void __thiscall
CSystemFids::ConnectLeave(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2)
{
{
  *(CSystemFids **)(param_1 + 0x14) = this;
  return;
}
}

// =================================================
// Function: CSystemFids::ConnectTree
// =================================================
void __thiscall
CSystemFids::ConnectTree(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2)
{
{
  *(CSystemFids **)(param_1 + 0x14) = this;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(this + 0x18);
  return;
}
}

// =================================================
// Function: CSystemFids::CreateIndex
// =================================================
void __thiscall CSystemFids::CreateIndex(CSystemFids *this,CSystemFids *param_1,ulong *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong *unaff_EBP;
  CSystemFids *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  SetTravelInfo((CMwNod *)this,*(ulong *)param_1);
  *(int *)param_1 = *(int *)param_1 + 1;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x28,pCVar3,(ulong)unaff_ESI);
      unaff_ESI = param_1;
      CreateIndex(*(CSystemFids **)pSVar2,param_1,unaff_EBP);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::DeleteDown
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSystemFids::DeleteDown(CSystemFids *this,CSystemFids *param_1)
{
{
  CSystemFids *this_00;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CSystemFid *pCVar3;
  code *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CSystemFids *unaff_retaddr;
  int *in_stack_00000008;
  CFastArray<class_CCrystalEdge*> *in_stack_00000014;
  ulong uVar5;
  CSystemFids *in_stack_fffffff8;
  
  this_00 = this + 0x1c;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      pCVar4 = pCVar4 + 1;
      *(undefined4 *)(*(int *)pSVar2 + 0x14) = 0;
    } while (pCVar4 < pCVar1);
  }
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      uVar5 = 0x42fe12;
      unaff_ESI = pCVar4;
      CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,(ulong)unaff_EBP);
      unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x42fe1e;
      pCVar3 = CSystemFid::ParametrizedGetLoadableFid
                         (*(CSystemFid **)pSVar2,(CSystemFid *)unaff_EBX);
      if (pCVar3 != (CSystemFid *)*in_stack_00000008) {
        unaff_EBP = (CFastBuffer<class_CCrystalFace*> *)0x42fe2e;
        unaff_EBX = (code *)pCVar4;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)in_stack_fffffff8);
        if (*(int **)pSVar2 != (int *)0x0) {
          in_stack_fffffff8 = (CSystemFids *)0x1;
          unaff_EBX = (code *)0x42fe3d;
          (**(code **)(**(int **)pSVar2 + 4))();
        }
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,uVar5);
        *(undefined4 *)pSVar2 = 0;
      }
      pCVar4 = pCVar4 + 1;
      this = unaff_retaddr;
    } while (pCVar4 < pCVar1);
  }
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll
            (this_00,(CFastArray<class_CCrystalEdge*> *)unaff_ESI);
  this_01 = (CFastBuffer<struct_CDx9StateBlock::STexStageState> *)(this + 0x28);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_01,unaff_EBP);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_01,pCVar4,(ulong)unaff_EBX);
      unaff_EBX = (code *)0x42fe7f;
      DeleteDown(*(CSystemFids **)pSVar2,in_stack_fffffff8);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  if ((_DAT_00d5569c & 1) == 0) {
    _DAT_00d5569c = _DAT_00d5569c | 1;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
              (&DAT_00d55690,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_EBX);
    unaff_EBX = `public:_void___thiscall_CSystemFids::DeleteDown(void)'::__l10::
                _dynamic_atexit_destructor_for__Trees__;
    _atexit(`public:_void___thiscall_CSystemFids::DeleteDown(void)'::__l10::
            _dynamic_atexit_destructor_for__Trees__);
  }
  CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
            (&DAT_00d55690,this_01,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)unaff_EBX);
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll(&DAT_00d55690,in_stack_00000014);
  return;
}
}

// =================================================
// Function: CSystemFids::FillPtrAtTravelIndex
// =================================================
void __thiscall
CSystemFids::FillPtrAtTravelIndex
          (CSystemFids *this,CSystemFids *param_1,CFastArray<class_CSystemFids*> *param_2)
{
{
  ulong uVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastArray<class_CSystemFids*> *unaff_EBP;
  CSystemFids *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  uVar1 = GetTravelInfo((CMwNod *)this);
  *(CSystemFids **)(*(int *)(param_1 + 4) + uVar1 * 4) = this;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x28,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = param_1;
      FillPtrAtTravelIndex(*(CSystemFids **)pSVar3,param_1,unaff_EBP);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::FindFid
// =================================================
CSystemFid * __thiscall
CSystemFids::FindFid
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3,
          EFindWay param_4)
{
{
  CSystemEngine *this_00;
  void **ppvVar1;
  CFastBuffer<class_CCrystalFace*> *pCVar2;
  int iVar3;
  CSystemFids *this_01;
  SCasterCat *pSVar4;
  CSystemFidFile *this_02;
  undefined *puVar5;
  undefined *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CSystemFid *unaff_ESI;
  int *unaff_EDI;
  bool bVar7;
  SStringParam *in_stack_ffffff90;
  ulong in_stack_ffffff94;
  CSystemManagerFile *in_stack_ffffff98;
  CFastStringInt *pCVar8;
  CSystemFid *pCVar9;
  CLoaderFidContainer *pCVar10;
  CSystemFid *pCVar11;
  ulong uStack_44;
  ulong local_40;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_3c;
  CSystemFids *local_38;
  undefined4 uStack_34;
  undefined *local_30;
  int local_2c;
  undefined *local_28;
  undefined *puStack_24;
  int iStack_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00a82df0;
  pCVar2 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  local_40 = 0;
  local_2c = 0;
  local_c = 0;
  ppvVar1 = &local_14;
  this_01 = this;
  local_38 = this;
  local_14 = ExceptionList;
  local_28 = PTR_DAT_00bbf7dc;
  while (ExceptionList = ppvVar1, this_01 != (CSystemFids *)0x0) {
    pCVar8 = (CFastStringInt *)0x4308ba;
    iVar3 = CSystemFileName::SplitFirstDirectory
                      ((CFastStringInt *)param_1,(CFastStringInt *)&local_2c,&local_40);
    if (iVar3 == 0) {
      if ((this_01 != (CSystemFids *)0x0) && (local_2c != 0)) {
        local_38 = (CSystemFids *)CFastBuffer<class_CCrystalFace*>::GetCount(this_01 + 0x1c,pCVar2);
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (local_38 != (CSystemFids *)0x0) goto LAB_00430902;
        goto LAB_00430963;
      }
      break;
    }
    this_01 = FindOneLocationDown(this_01,(CSystemFids *)&local_2c,param_2,param_3,(EFindWay)pCVar2)
    ;
    ppvVar1 = ExceptionList;
  }
  goto LAB_00430ad4;
LAB_00430902:
  do {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_01 + 0x1c,pCVar6,(ulong)pCVar2);
    this_02 = *(CSystemFidFile **)pSVar4;
    pCVar2 = (CFastBuffer<class_CCrystalFace*> *)0xb00a000;
    iVar3 = (**(code **)(*(int *)this_02 + 0x10))();
    if (iVar3 != 0) {
      puStack_24 = local_28;
      iStack_20 = local_2c;
      local_1c = 0;
      if ((local_2c == *(int *)(this_02 + 0x74)) &&
         (iVar3 = CFastStringInt::CompareNoCase
                            (this_02 + 0x74,(CFastStringInt *)&puStack_24,(SStringParam *)0x0,
                             (ulong)pCVar2), iVar3 == 0)) goto LAB_00430a2e;
    }
    pCVar6 = pCVar6 + 1;
    this = local_38;
  } while (pCVar6 < pCStack_3c);
LAB_00430963:
  if (param_2 == (CFastStringInt *)0x0) goto LAB_00430b11;
  uStack_34 = 0;
  local_30 = PTR_DAT_00bbf7dc;
  pCVar11 = (CSystemFid *)0x0;
  pCVar10 = (CLoaderFidContainer *)&uStack_34;
  local_c = CONCAT31(local_c._1_3_,1);
  pCVar9 = (CSystemFid *)0x430996;
  (**(code **)(*(int *)this_01 + 0x98))();
  local_40 = uStack_44;
  local_38 = (CSystemFids *)0x0;
  CFastStringInt::Concat(&stack0xffffffb0,(CFastStringInt *)&local_40,in_stack_ffffff90);
  iVar3 = CSystemManagerFile::IsFileExists((CFastStringInt *)&stack0xffffffb4);
  if (iVar3 != 0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                        in_stack_ffffff94);
    this_02 = CSystemManagerFile::CreateFidFile
                        (*(CSystemManagerFile **)(*(int *)pSVar4 + 0x20),in_stack_ffffff98);
    CSystemFidFile::SetFileName(this_02,(CSystemFidFile *)&pCStack_3c,pCVar8);
    AddLeave(this_01,(CSystemFids *)this_02,pCVar9);
    this_02[0x1c] = (CSystemFidFile)((byte)this_02[0x1c] | DAT_00d543c0);
    CSystemFid::UpdateFidProps((CSystemFid *)this_02,pCVar10,pCVar11);
    if (local_30 != PTR_DAT_00bbf7dc) {
      if ((local_30[-1] & 0x80) == 0) {
        puVar5 = local_30 + -2;
      }
      else {
        puVar5 = local_30 + -4;
      }
      operator_delete__(puVar5);
      uStack_34 = 0;
      local_30 = PTR_DAT_00bbf7dc;
    }
    bVar7 = local_28 == PTR_DAT_00bbf7dc;
    goto LAB_00430a38;
  }
  puStack_24 = (undefined *)((uint)puStack_24 & 0xffffff00);
  if (unaff_EBX != PTR_DAT_00bbf7dc) {
    if ((unaff_EBX[-1] & 0x80) == 0) {
      puVar5 = unaff_EBX + -2;
    }
    else {
      puVar5 = unaff_EBX + -4;
    }
    operator_delete__(puVar5);
  }
LAB_00430ad4:
  if (param_2 != (CFastStringInt *)0x0) {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                        (ulong)pCVar2);
    this_00 = *(CSystemEngine **)pSVar4;
    this_02 = CSystemEngine::FindOrAddFidAt
                        (this_00,(CSystemEngine *)this,param_1,(CFastStringInt *)0x0,unaff_EDI);
    if (*(undefined ***)(this_02 + 0x6c) != &PTR_vftable_00ccbf90) {
LAB_00430a2e:
      bVar7 = local_28 == PTR_DAT_00bbf7dc;
LAB_00430a38:
      if (!bVar7) {
        if ((local_28[-1] & 0x80) != 0) {
          operator_delete__(local_28 + -4);
          ExceptionList = local_14;
          return (CSystemFid *)this_02;
        }
        operator_delete__(local_28 + -2);
      }
      ExceptionList = local_14;
      return (CSystemFid *)this_02;
    }
    CSystemEngine::RemoveAndDeleteFid(this_00,(CSystemEngine *)this_02,unaff_ESI);
  }
LAB_00430b11:
  if (local_28 != PTR_DAT_00bbf7dc) {
    if ((local_28[-1] & 0x80) == 0) {
      puVar5 = local_28 + -2;
    }
    else {
      puVar5 = local_28 + -4;
    }
    operator_delete__(puVar5);
  }
  ExceptionList = local_14;
  return (CSystemFid *)0x0;
}
}

// =================================================
// Function: CSystemFids::FindFidFromBaseNameAndClassId
// =================================================
CSystemFid * __thiscall
CSystemFids::FindFidFromBaseNameAndClassId
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong param_3)
{
{
  CSystemFid *this_00;
  void **ppvVar1;
  CFastStringInt *pCVar2;
  int iVar3;
  undefined *puVar4;
  SCasterCat *pSVar5;
  ulong uVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CSystemFids *this_01;
  ulong unaff_EDI;
  CFastStringInt *this_02;
  ulong local_50;
  CSystemFids *local_4c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_48;
  ulong local_44;
  SStringParam *local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined *puStack_34;
  undefined *puStack_30;
  SStringParam *pSStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  undefined1 uStack_8;
  
  local_10 = &LAB_00a82d30;
  local_14 = ExceptionList;
  pCVar2 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffa0);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_50 = 0;
  local_40 = (SStringParam *)0x0;
  local_3c = PTR_DAT_00bbf7dc;
  local_c = 0;
  ppvVar1 = &local_14;
  if (this == (CSystemFids *)0x0) {
    return (CSystemFid *)0x0;
  }
  do {
    ExceptionList = ppvVar1;
    iVar3 = CSystemFileName::SplitFirstDirectory
                      ((CFastStringInt *)param_1,(CFastStringInt *)&local_40,&local_50);
    if (iVar3 == 0) {
      if ((this != (CSystemFids *)0x0) && (local_40 != (SStringParam *)0x0)) {
        this_01 = this + 0x1c;
        local_4c = this_01;
        local_44 = CFastBuffer<class_CCrystalFace*>::GetCount
                             (this_01,(CFastBuffer<class_CCrystalFace*> *)pCVar2);
        if (local_44 != 0) goto LAB_0042fc64;
      }
      break;
    }
    this = FindOneLocationDown(this,(CSystemFids *)&local_40,(CFastStringInt *)0x0,0,
                               (EFindWay)pCVar2);
    ppvVar1 = ExceptionList;
  } while (this != (CSystemFids *)0x0);
  goto LAB_0042fc1b;
LAB_0042fc64:
  do {
    pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar7,(ulong)pCVar2)
    ;
    this_00 = *(CSystemFid **)pSVar5;
    pCVar2 = (CFastStringInt *)0xb00a000;
    iVar3 = (**(code **)(*(int *)this_00 + 0x10))();
    if (iVar3 != 0) {
      puStack_30 = local_3c;
      this_02 = (CFastStringInt *)(this_00 + 0x74);
      pSStack_2c = local_40;
      uStack_28 = 0;
      puVar4 = (undefined *)
               CFastStringInt::CompareNoCase
                         (this_02,(CFastStringInt *)&puStack_30,local_40,(ulong)pCVar2);
      if (puVar4 == (undefined *)0x0) {
        if (param_2 == (CFastStringInt *)0xffffffff) {
LAB_0042fd59:
          CGameCtnApp::SNationConfig::~SNationConfig(&local_40,(SNationConfig *)pCVar2);
          ExceptionList = local_10;
          return this_00;
        }
        puStack_30 = PTR_DAT_00bbf7dc;
        pCVar2 = (CFastStringInt *)&puStack_34;
        uStack_8 = 1;
        puStack_34 = puVar4;
        CSystemFileName::ExtractShortBaseName(this_02,pCVar2);
        uStack_20 = local_38;
        puStack_1c = local_3c;
        uStack_18 = 0;
        if (local_3c == puStack_34) {
          pCVar2 = (CFastStringInt *)0x0;
          this_02 = (CFastStringInt *)&uStack_20;
          iVar3 = CFastStringInt::CompareNoCase(&puStack_34,this_02,(SStringParam *)0x0,unaff_EDI);
          if (iVar3 == 0) {
            unaff_EDI = 0x42fd1a;
            uVar6 = CSystemFid::GetClassId(this_00,(CSystemFid *)this_02);
            if (uVar6 != 0xffffffff) {
              pCVar2 = (CFastStringInt *)0x42fd29;
              iVar3 = CMwNod::StaticMwIsKindOf(uVar6,(ulong)param_2);
              unaff_EDI = uVar6;
              if (iVar3 != 0) {
                CGameCtnApp::SNationConfig::~SNationConfig(&pSStack_2c,(SNationConfig *)this_02);
                goto LAB_0042fd59;
              }
            }
          }
        }
        local_10 = (undefined1 *)((uint)local_10 & 0xffffff00);
        CGameCtnApp::SNationConfig::~SNationConfig(&local_3c,(SNationConfig *)this_02);
      }
    }
    pCVar7 = pCVar7 + 1;
    this_01 = local_4c;
  } while (pCVar7 < pCStack_48);
LAB_0042fc1b:
  if (local_3c != PTR_DAT_00bbf7dc) {
    if ((local_3c[-1] & 0x80) == 0) {
      puVar4 = local_3c + -2;
    }
    else {
      puVar4 = local_3c + -4;
    }
    operator_delete__(puVar4);
  }
  ExceptionList = local_14;
  return (CSystemFid *)0x0;
}
}

// =================================================
// Function: CSystemFids::FindLocationDown
// =================================================
CSystemFids * __thiscall
CSystemFids::FindLocationDown
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3,
          EFindWay param_4)
{
{
  int iVar1;
  undefined *puVar2;
  EFindWay unaff_EDI;
  ulong local_28;
  undefined4 local_24;
  undefined *local_20;
  CFastStringInt local_1c [4];
  undefined *puStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00a82d90;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastStringInt::CFastStringInt
            (&local_20,(CFastStringInt *)param_1,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
  local_8 = 0;
  CSystemFileName::FixFileName(local_1c,3);
  local_28 = 0;
  local_24 = 0;
  local_20 = PTR_DAT_00bbf7dc;
  local_8 = CONCAT31(local_8._1_3_,1);
  if (this != (CSystemFids *)0x0) {
    do {
      iVar1 = CSystemFileName::SplitFirstDirectory(local_1c,(CFastStringInt *)&local_24,&local_28);
      if (iVar1 == 0) break;
      this = FindOneLocationDown(this,(CSystemFids *)&local_24,param_2,param_3,unaff_EDI);
    } while (this != (CSystemFids *)0x0);
    if (local_20 != PTR_DAT_00bbf7dc) {
      puVar2 = local_20 + -4;
      if ((local_20[-1] & 0x80) == 0) {
        puVar2 = local_20 + -2;
      }
      operator_delete__(puVar2);
      local_24 = 0;
      local_20 = PTR_DAT_00bbf7dc;
    }
  }
  if (puStack_18 != PTR_DAT_00bbf7dc) {
    puVar2 = puStack_18 + -4;
    if ((puStack_18[-1] & 0x80) == 0) {
      puVar2 = puStack_18 + -2;
    }
    operator_delete__(puVar2);
  }
  ExceptionList = puStack_10;
  return this;
}
}

// =================================================
// Function: CSystemFids::FindOneLocationDown
// =================================================
CSystemFids * __thiscall
CSystemFids::FindOneLocationDown
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3,
          EFindWay param_4)
{
{
  SStringParam *pSVar1;
  int iVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CSystemFidsFolder *this_00;
  CSystemFids *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SStringParam *pSVar7;
  SStringParam *in_stack_ffffffbc;
  CSystemFids **ppCVar8;
  ulong uVar9;
  CSystemManagerFile *pCVar10;
  CSystemFids *pCStack_28;
  undefined *local_24;
  SStringParam *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a82cf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_24 = &DAT_00b30500;
  local_20 = (SStringParam *)0x3;
  local_1c = 1;
  if (*(int *)param_1 == 3) {
    in_stack_ffffffbc = (SStringParam *)0x0;
    iVar2 = CFastStringInt::CompareNoCase
                      (param_1,(CFastStringInt *)&local_24,(SStringParam *)0x0,
                       DAT_00cca150 ^ (uint)&stack0xffffffc4);
    if (iVar2 == 0) {
      if (param_4 != 1) {
        ExceptionList = local_8;
        return (CSystemFids *)0x0;
      }
      ExceptionList = local_8;
      return *(CSystemFids **)(this + 0x14);
    }
  }
  uVar9 = 0x42f911;
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar5 = this;
  if (uVar3 != 0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar5 + 0x28,pCVar6,(ulong)in_stack_ffffffbc);
      pCVar5 = *(CSystemFids **)pSVar4;
      pSVar7 = *(SStringParam **)(pCVar5 + 0x40);
      pSVar1 = *(SStringParam **)param_1;
      if (pSVar7 + 1 == pSVar1) {
        local_24 = *(undefined **)(param_1 + 4);
        local_1c = 0;
        local_20 = pSVar1;
        if (((pSVar7 != (SStringParam *)0x0) || (pSVar1 == (SStringParam *)0x0)) &&
           (iVar2 = CFastStringInt::CompareNoCase
                              (pCVar5 + 0x40,(CFastStringInt *)&local_24,pSVar7,uVar9),
           in_stack_ffffffbc = pSVar7, iVar2 == 0)) {
          ExceptionList = local_8;
          return pCVar5;
        }
      }
      pCVar6 = pCVar6 + 1;
      pCVar5 = pCStack_28;
    } while (pCVar6 < param_2);
  }
  if (uVar3 != 0) {
    pCStack_28 = (CSystemFids *)0x0;
    local_24 = PTR_DAT_00bbf7dc;
    pCVar10 = (CSystemManagerFile *)0x0;
    ppCVar8 = &pCStack_28;
    pSVar7 = (SStringParam *)0x42f9a7;
    (**(code **)(*(int *)pCVar5 + 0x98))();
    local_1c = *(undefined4 *)param_1;
    local_20 = *(SStringParam **)(param_1 + 4);
    local_18 = 0;
    CFastStringInt::Concat(&stack0xffffffcc,(CFastStringInt *)&local_20,pSVar7);
    iVar2 = CSystemManagerFile::IsFolderExists((CFastStringInt *)&stack0xffffffd0);
    if (iVar2 != 0) {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(DAT_00d73300 + 0x20),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                          (ulong)ppCVar8);
      this_00 = CSystemManagerFile::CreateFidsFolder
                          (*(CSystemManagerFile **)(*(int *)pSVar4 + 0x20),pCVar10);
      CSystemFidsFolder::SetDirName
                (this_00,(CSystemFidsFolder *)param_1,(CFastStringInt *)unaff_EDI);
      AddTree((CPlugTree *)this_00);
      if (local_24 == PTR_DAT_00bbf7dc) {
        ExceptionList = local_8;
        return (CSystemFids *)this_00;
      }
      if ((local_24[-1] & 0x80) != 0) {
        operator_delete__(local_24 + -4);
        ExceptionList = local_8;
        return (CSystemFids *)this_00;
      }
      operator_delete__(local_24 + -2);
      ExceptionList = local_8;
      return (CSystemFids *)this_00;
    }
    if (this != (CSystemFids *)PTR_DAT_00bbf7dc) {
      if (((byte)this[-1] & 0x80) == 0) {
        pCVar5 = this + -2;
      }
      else {
        pCVar5 = this + -4;
      }
      operator_delete__(pCVar5);
    }
  }
  ExceptionList = local_8;
  return (CSystemFids *)0x0;
}
}

// =================================================
// Function: CSystemFids::FindOrAddFid
// =================================================
CSystemFid * __thiscall
CSystemFids::FindOrAddFid
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4
          )
{
{
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  int iVar2;
  CSystemFids *this_00;
  CPlugFileGpuBuilder *pCVar3;
  SCasterCat *pSVar4;
  CSystemFidFile *this_01;
  CFastStringInt *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSystemManagerFile *unaff_ESI;
  CFastStringInt *unaff_EDI;
  void *unaff_retaddr;
  char *pcVar6;
  LPCSTR *ppCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> **ppCVar8;
  CPlugFileGpuBuilder *pCVar9;
  CFastStringInt *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  undefined *local_30;
  int local_2c;
  undefined *local_28;
  undefined *puStack_24;
  undefined *puStack_20;
  undefined *puStack_1c;
  undefined *puStack_18;
  undefined *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  void *local_8;
  
  local_14 = ExceptionList;
  puStack_10 = &LAB_00a82e20;
  pCVar1 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffb8);
  ExceptionList = &local_14;
  if (param_2 != (CFastStringInt *)0x0) {
    *(undefined4 *)param_2 = 0;
  }
  pCVar10 = (CFastStringInt *)0x0;
  local_2c = 0;
  local_c = 0;
  this_00 = this;
  local_28 = PTR_DAT_00bbf7dc;
  do {
    if (this_00 == (CSystemFids *)0x0) {
LAB_00430bdc:
      local_34 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_30 = PTR_DAT_00bbf7dc;
      pCVar9 = (CPlugFileGpuBuilder *)0x0;
      ppCVar8 = &local_34;
      local_c = CONCAT31(local_c._1_3_,1);
      (**(code **)(*(int *)this + 0x98))();
      if (DAT_00d71e54 != 0) {
        DAT_00d71e54 = 0;
        *DAT_00d71e58 = 0;
      }
      ppCVar7 = &lpOutputString_00b2bcc4;
      pcVar6 = "\r\n\t_FileName=";
      pCVar3 = CFastString::operator<<
                         ((CFastString *)&DAT_00d71e54,
                          (CPlugFileGpuBuilder *)"CSystemFids::FindOrAddFid fails with :\r\n\tthis="
                          ,&stack0xffffffc4);
      pCVar3 = CFastString::operator<<
                         ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)pcVar6,(char *)param_1);
      pCVar3 = CFastString::operator<<
                         ((CFastString *)pCVar3,(CPlugFileGpuBuilder *)ppCVar7,(char *)ppCVar8);
      pCVar9 = CFastString::operator<<((CFastString *)pCVar3,pCVar9,(char *)pCVar1);
      CFastString::operator<<
                ((CFastString *)pCVar9,(CPlugFileGpuBuilder *)unaff_EDI,(char *)unaff_ESI);
      CClassicLog::AddLogStringInFile();
      if (puStack_24 != PTR_DAT_00bbf7dc) {
        if ((puStack_24[-1] & 0x80) == 0) {
          puStack_24 = puStack_24 + -2;
        }
        else {
          puStack_24 = puStack_24 + -4;
        }
        operator_delete__(puStack_24);
        local_28 = (undefined *)0x0;
        puStack_24 = PTR_DAT_00bbf7dc;
      }
      if (puStack_1c != PTR_DAT_00bbf7dc) {
        if ((puStack_1c[-1] & 0x80) == 0) {
          puStack_1c = puStack_1c + -2;
        }
        else {
          puStack_1c = puStack_1c + -4;
        }
        operator_delete__(puStack_1c);
      }
      ExceptionList = local_8;
      return (CSystemFid *)0x0;
    }
    iVar2 = CSystemFileName::SplitFirstDirectory
                      ((CFastStringInt *)param_1,(CFastStringInt *)&local_2c,
                       (ulong *)&stack0xffffffc4);
    if (iVar2 == 0) {
      if ((this_00 != (CSystemFids *)0x0) && (local_2c != 0)) {
        local_34 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBuffer<class_CCrystalFace*>::GetCount(this_00 + 0x1c,pCVar1);
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (local_34 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) goto LAB_00430d03;
        break;
      }
      goto LAB_00430bdc;
    }
    this_00 = FindOrAddOneLocationDown(this_00,(CSystemFids *)&local_2c,param_2,param_3,(int)pCVar1)
    ;
  } while( true );
  do {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00 + 0x1c,pCVar5,(ulong)unaff_EDI);
    this_01 = *(CSystemFidFile **)pSVar4;
    unaff_EDI = (CFastStringInt *)0xb00a000;
    iVar2 = (**(code **)(*(int *)this_01 + 0x10))();
    if (iVar2 != 0) {
      puStack_18 = puStack_1c;
      local_14 = puStack_20;
      puStack_10 = (undefined1 *)0x0;
      if (puStack_20 == *(undefined **)(this_01 + 0x74)) {
        unaff_ESI = (CSystemManagerFile *)0x0;
        unaff_EDI = (CFastStringInt *)&puStack_18;
        iVar2 = CFastStringInt::CompareNoCase
                          (this_01 + 0x74,unaff_EDI,(SStringParam *)0x0,(ulong)unaff_EBX);
        if (iVar2 == 0) {
          if (param_3 != (ulong *)0x0) {
            CSystemFidFile::SetFileName(this_01,(CSystemFidFile *)&puStack_1c,pCVar10);
          }
          if (local_14 == PTR_DAT_00bbf7dc) {
            ExceptionList = unaff_retaddr;
            return (CSystemFid *)this_01;
          }
          if ((local_14[-1] & 0x80) != 0) {
            operator_delete__(local_14 + -4);
            ExceptionList = unaff_retaddr;
            return (CSystemFid *)this_01;
          }
          goto LAB_00430dc0;
        }
      }
    }
    pCVar5 = pCVar5 + 1;
  } while (pCVar5 < local_34);
LAB_00430d03:
  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)unaff_EDI);
  this_01 = CSystemManagerFile::CreateFidFile
                      (*(CSystemManagerFile **)(*(int *)pSVar4 + 0x20),unaff_ESI);
  CSystemFidFile::SetFileName(this_01,(CSystemFidFile *)&puStack_20,unaff_EBX);
  *(uint *)(this_01 + 0x1c) = *(uint *)(this_01 + 0x1c) & 0xfffff7ff;
  AddLeave(this_00,(CSystemFids *)this_01,(CSystemFid *)pCVar10);
  if (param_2 != (CFastStringInt *)0x0) {
    *(int *)param_2 = *(int *)param_2 + 1;
  }
  if (local_14 != PTR_DAT_00bbf7dc) {
    if ((local_14[-1] & 0x80) != 0) {
      operator_delete__(local_14 + -4);
      ExceptionList = unaff_retaddr;
      return (CSystemFid *)this_01;
    }
LAB_00430dc0:
    operator_delete__(local_14 + -2);
  }
  ExceptionList = unaff_retaddr;
  return (CSystemFid *)this_01;
}
}

// =================================================
// Function: CSystemFids::FindOrAddLocationDown
// =================================================
CSystemFids * __thiscall
CSystemFids::FindOrAddLocationDown
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4
          )
{
{
  int iVar1;
  undefined *puVar2;
  int unaff_EDI;
  ulong local_28;
  undefined4 local_24;
  undefined *local_20;
  CFastStringInt local_1c [4];
  undefined *puStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00a82dc0;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)param_1 != 0) {
    CFastStringInt::CFastStringInt
              (&local_20,(CFastStringInt *)param_1,
               (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
    local_8 = 0;
    CSystemFileName::FixFileName(local_1c,3);
    if (param_2 != (CFastStringInt *)0x0) {
      *(undefined4 *)param_2 = 0;
    }
    local_28 = 0;
    local_24 = 0;
    local_20 = PTR_DAT_00bbf7dc;
    local_8 = CONCAT31(local_8._1_3_,1);
    if (this != (CSystemFids *)0x0) {
      do {
        iVar1 = CSystemFileName::SplitFirstDirectory(local_1c,(CFastStringInt *)&local_24,&local_28)
        ;
        if (iVar1 == 0) break;
        this = FindOrAddOneLocationDown(this,(CSystemFids *)&local_24,param_2,param_3,unaff_EDI);
      } while (this != (CSystemFids *)0x0);
      if (local_20 != PTR_DAT_00bbf7dc) {
        puVar2 = local_20 + -4;
        if ((local_20[-1] & 0x80) == 0) {
          puVar2 = local_20 + -2;
        }
        operator_delete__(puVar2);
        local_24 = 0;
        local_20 = PTR_DAT_00bbf7dc;
      }
    }
    if (puStack_18 != PTR_DAT_00bbf7dc) {
      puVar2 = puStack_18 + -4;
      if ((puStack_18[-1] & 0x80) == 0) {
        puVar2 = puStack_18 + -2;
      }
      operator_delete__(puVar2);
    }
  }
  ExceptionList = puStack_10;
  return this;
}
}

// =================================================
// Function: CSystemFids::FindOrAddOneLocationDown
// =================================================
CSystemFids * __thiscall
CSystemFids::FindOrAddOneLocationDown
          (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4
          )
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSystemFidsFolder *pCVar4;
  SStringParam *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSystemManagerFile *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_0000001c;
  SStringParam *pSVar6;
  CSystemFids *pCVar7;
  CSystemFids *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = (CSystemFids *)&DAT_00b30500;
  local_8 = 3;
  local_4 = 1;
  pCVar7 = this;
  if ((*(int *)param_1 == 3) &&
     (iVar1 = CFastStringInt::CompareNoCase
                        (param_1,(CFastStringInt *)&local_c,(SStringParam *)0x0,unaff_ESI),
     iVar1 == 0)) {
    return (CSystemFids *)0x0;
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x28,pCVar5,(ulong)unaff_EBX);
      pCVar4 = *(CSystemFidsFolder **)pSVar3;
      pSVar6 = *(SStringParam **)(pCVar4 + 0x40);
      if ((pSVar6 + 1 == *(SStringParam **)param_1) &&
         (((pSVar6 != (SStringParam *)0x0 || (*(SStringParam **)param_1 == (SStringParam *)0x0)) &&
          (iVar1 = CFastStringInt::CompareNoCase
                             (pCVar4 + 0x40,(CFastStringInt *)&stack0x00000000,pSVar6,
                              (ulong)unaff_EBP), unaff_EBX = pSVar6, iVar1 == 0)))) {
        if (in_stack_0000001c == 0) {
          return (CSystemFids *)pCVar4;
        }
        CSystemFidsFolder::SetDirName(pCVar4,(CSystemFidsFolder *)param_1,(CFastStringInt *)pCVar7);
        return (CSystemFids *)pCVar4;
      }
      pCVar5 = pCVar5 + 1;
      this = local_c;
    } while (pCVar5 < pCVar2);
  }
  if (param_4 != 0) {
    *(int *)param_4 = *(int *)param_4 + 1;
  }
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      (ulong)unaff_EBX);
  pCVar4 = CSystemManagerFile::CreateFidsFolder
                     (*(CSystemManagerFile **)(*(int *)pSVar3 + 0x20),unaff_EBP);
  CSystemFidsFolder::SetDirName(pCVar4,(CSystemFidsFolder *)param_1,(CFastStringInt *)pCVar7);
  AddTree((CPlugTree *)pCVar4);
  return (CSystemFids *)pCVar4;
}
}

// =================================================
// Function: CSystemFids::GetTravelInfo
// =================================================
ulong __cdecl CSystemFids::GetTravelInfo(CMwNod *param_1)
{
{
  CFastString CVar1;
  undefined3 extraout_var;
  ulong local_4;
  
  CVar1 = CFastMapTable<unsigned_long>::GetElem
                    ((CFastMapTable<unsigned_long> *)&DAT_00d55680,
                     (CVirtualisedBuffer<class_CFastString> *)param_1,(ulong)&local_4);
  if (CONCAT31(extraout_var,CVar1) == 0) {
    return 0;
  }
  return local_4;
}
}

// =================================================
// Function: CSystemFids::GetUp
// =================================================
void __thiscall CSystemFids::GetUp(CSystemFids *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  if (param_1 != (GmIso4 *)0x0) {
    while (this = *(CSystemFids **)(this + 0x14), this != (CSystemFids *)0x0) {
      param_1 = param_1 + -1;
      if (param_1 == (GmIso4 *)0x0) {
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CSystemFids::IsOneBaseOf
// =================================================
int __thiscall CSystemFids::IsOneBaseOf(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2)
{
{
  while( true ) {
    if (param_1 == (CSystemFids *)0x0) {
      return 0;
    }
    if (this == param_1) break;
    param_1 = *(CSystemFids **)(param_1 + 0x14);
  }
  return 1;
}
}

// =================================================
// Function: CSystemFids::RefreshVirtualRecursive
// =================================================
void __thiscall
CSystemFids::RefreshVirtualRecursive(CSystemFids *this,CSystemFids *param_1,int param_2)
{
{
  CSystemFids CVar1;
  uint uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  
  CVar1 = this[0x34];
  do {
    if (((byte)CVar1 & 1) != 0) {
      return;
    }
    if (param_1 == (CSystemFids *)0x0) {
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_ESI);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)pCVar5;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x28,pCVar5,(ulong)unaff_EBP);
          if ((*(byte *)(*(int *)pSVar4 + 0x34) & 1) != 0) goto LAB_0042ffd8;
          pCVar5 = pCVar5 + 1;
        } while (pCVar5 < pCVar3);
      }
      unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x430012;
      pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (this + 0x1c,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x430028;
          unaff_EBP = pCVar5;
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this + 0x1c,pCVar5,unaff_EBX);
          if (*(undefined ***)(*(int *)pSVar4 + 0x6c) != &PTR_vftable_00ccbf90) goto LAB_0042ffd8;
          pCVar5 = pCVar5 + 1;
        } while (pCVar5 < pCVar3);
      }
      param_1 = (CSystemFids *)0x0;
    }
    else {
LAB_0042ffd8:
      param_1 = (CSystemFids *)0x1;
    }
    uVar2 = *(uint *)(this + 0x34);
    if ((CSystemFids *)(uVar2 & 1) == param_1) {
      return;
    }
    *(uint *)(this + 0x34) = (uVar2 ^ (uint)param_1) & 1 ^ uVar2;
    this = *(CSystemFids **)(this + 0x14);
    if (this == (CSystemFids *)0x0) {
      return;
    }
    CVar1 = this[0x34];
  } while( true );
}
}

// =================================================
// Function: CSystemFids::RemoveLeaveSafe
// =================================================
void __thiscall
CSystemFids::RemoveLeaveSafe(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2)
{
{
  CFastBufferRef<class_CGameMobil> *pCVar1;
  GxTexCoordSet *unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBufferRef<class_CGameMobil> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this + 0x1c,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
  if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
    *(undefined4 *)(param_2 + 0x14) = 0;
    CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this + 0x1c,pCVar1,1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::RemoveTreeSafe
// =================================================
void __thiscall
CSystemFids::RemoveTreeSafe(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2)
{
{
  CFastBufferRef<class_CGameMobil> *pCVar1;
  GxTexCoordSet *unaff_ESI;
  ulong unaff_retaddr;
  
  pCVar1 = (CFastBufferRef<class_CGameMobil> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     (this + 0x28,(CFastArray<class_GxTexCoordSet> *)&param_1,unaff_ESI);
  if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
    *(undefined4 *)(param_2 + 0x14) = 0;
    CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this + 0x28,pCVar1,1,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::SetTravelInfo
// =================================================
void __cdecl CSystemFids::SetTravelInfo(CMwNod *param_1,ulong param_2)
{
{
  ulong uVar1;
  CFastString CVar2;
  undefined3 extraout_var;
  uint *unaff_EDI;
  ulong *local_4;
  
  uVar1 = param_2;
  if (param_2 == 0) {
    CFastMapTable<unsigned_long>::RemoveIfFound
              ((CFastMapTable<unsigned_long> *)&DAT_00d55680,(CFastBuffer<unsigned_int> *)param_1,
               unaff_EDI);
    return;
  }
  CVar2 = CFastMapTable<unsigned_long>::GetElem
                    ((CFastMapTable<unsigned_long> *)&DAT_00d55680,
                     (CVirtualisedBuffer<class_CFastString> *)param_1,(ulong)&local_4);
  if (CONCAT31(extraout_var,CVar2) != 0) {
    *local_4 = uVar1;
    return;
  }
  CFastMapTable<unsigned_long>::Add
            ((CFastMapTable<unsigned_long> *)&DAT_00d55680,(TiXmlAttributeSet *)&param_2,
             (TiXmlAttribute *)param_1);
  return;
}
}

// =================================================
// Function: CSystemFids::TravelCountUp
// =================================================
void __thiscall CSystemFids::TravelCountUp(CSystemFids *this,CSystemFids *param_1)
{
{
  CMwNod *pCVar1;
  ulong uVar2;
  
  uVar2 = GetTravelInfo((CMwNod *)this);
  SetTravelInfo((CMwNod *)this,uVar2 + 1);
  for (pCVar1 = *(CMwNod **)(this + 0x14); pCVar1 != (CMwNod *)0x0;
      pCVar1 = *(CMwNod **)(pCVar1 + 0x14)) {
    uVar2 = GetTravelInfo(pCVar1);
    SetTravelInfo(pCVar1,uVar2 + 1);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::TravelDuplicateFrom
// =================================================
void __thiscall
CSystemFids::TravelDuplicateFrom(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong uVar3;
  CSystemFids *this_00;
  ulong unaff_EBP;
  CMwNod *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CMwNod *unaff_EDI;
  CSystemFids *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_retaddr;
  CSystemFids *pCVar5;
  CSystemFids *pCVar6;
  
  pCVar5 = param_1;
  (**(code **)(*(int *)this + 0x94))();
  SetTravelInfo((CMwNod *)this,(ulong)param_1);
  SetTravelInfo((CMwNod *)param_1,(ulong)this);
  this_01 = param_1 + 0x28;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_01,(CFastBuffer<class_CCrystalFace*> *)pCVar5);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_01,pCVar4,(ulong)unaff_EDI);
      unaff_EDI = *(CMwNod **)pSVar2;
      GetTravelInfo(unaff_EDI);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  CFastBuffer<int>::SetSizeAtLeast
            (this + 0x28,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0,(ulong)unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_01,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = *(CMwNod **)pSVar2;
      uVar3 = GetTravelInfo(unaff_ESI);
      if (uVar3 != 0) {
        pCVar6 = (CSystemFids *)0x4311f6;
        unaff_ESI = (CMwNod *)pCVar4;
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_01,pCVar4,unaff_EBP)
        ;
        unaff_EBP = 0x4311ff;
        this_00 = (CSystemFids *)(**(code **)(**(int **)pSVar2 + 0x7c))();
        pCVar5 = this_00;
        AddTree((CPlugTree *)this_00);
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_01,pCVar4,(ulong)pCVar5);
        TravelDuplicateFrom(this_00,*(CSystemFids **)pSVar2,pCVar6);
        pCVar1 = unaff_retaddr;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::TravelFindNbBackRoot
// =================================================
ulong __thiscall
CSystemFids::TravelFindNbBackRoot
          (CSystemFids *this,CSystemFids *param_1,CFastBuffer<class_CSystemFids*> *param_2)
{
{
  ulong uVar1;
  CFastBuffer<class_CSystemFids*> *unaff_retaddr;
  
  if (param_1 == this + 0x28) {
    return 0;
  }
  uVar1 = TravelFindNbBackRoot(*(CSystemFids **)(this + 0x14),param_1,unaff_retaddr);
  return uVar1 + 1;
}
}

// =================================================
// Function: CSystemFids::TravelGetTreesNbRefDown
// =================================================
CSystemFids * __thiscall
CSystemFids::TravelGetTreesNbRefDown(CSystemFids *this,CSystemFids *param_1,ulong param_2)
{
{
  CMwNod *this_00;
  CSystemFids *pCVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CMwNod *unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CSystemFids *)GetTravelInfo((CMwNod *)this);
  if (param_1 != pCVar1) {
    return this;
  }
  while( true ) {
    this_00 = (CMwNod *)(this + 0x28);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    if (uVar2 != 1) {
      return this;
    }
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_ESI);
    pCVar1 = (CSystemFids *)GetTravelInfo(*(CMwNod **)pSVar3);
    if (pCVar1 != param_1) break;
    unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x4305a6;
    pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_EBX);
    this = *(CSystemFids **)pSVar3;
    unaff_ESI = 0x4305ae;
    unaff_EBX = (CMwNod *)this;
    pCVar1 = (CSystemFids *)GetTravelInfo((CMwNod *)this);
    if (param_1 != pCVar1) {
      return this;
    }
  }
  return this;
}
}

// =================================================
// Function: CSystemFids::TravelMarkUp
// =================================================
void __thiscall CSystemFids::TravelMarkUp(CSystemFids *this,CSystemFids *param_1)
{
{
  ulong uVar1;
  
  uVar1 = GetTravelInfo((CMwNod *)this);
  while( true ) {
    if (uVar1 != 0) {
      return;
    }
    SetTravelInfo((CMwNod *)this,1);
    this = *(CSystemFids **)(this + 0x14);
    if (this == (CSystemFids *)0x0) break;
    uVar1 = GetTravelInfo((CMwNod *)this);
  }
  return;
}
}

// =================================================
// Function: CSystemFids::TruncLocals
// =================================================
int __thiscall
CSystemFids::TruncLocals(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2,int param_3)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int unaff_EBX;
  CSystemFid *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  
  iVar1 = (**(code **)(*(int *)this + 0x8c))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x28,pCVar4,(ulong)unaff_EBP);
      unaff_EBP = param_2;
      iVar1 = TruncLocals(*(CSystemFids **)pSVar3,(CSystemFids *)param_2,param_2,unaff_EBX);
      if (iVar1 != 0) {
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  iVar1 = (**(code **)(*(int *)this + 0x88))(param_1,param_2);
  return iVar1;
}
}

// =================================================
// Function: CSystemFids::~CSystemFids
// =================================================
void __thiscall CSystemFids::~CSystemFids(CSystemFids *this,CSystemFids *param_1)
{
{
  CSystemFids *this_00;
  CSystemFids *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  CMwNod *in_stack_ffffffec;
  void *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8;
  undefined4 local_4;
  
  pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00a82e8e;
  local_c = ExceptionList;
  pCVar1 = (CSystemFids *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 2;
  if (*(CSystemFids **)(this + 0x14) != (CSystemFids *)0x0) {
    RemoveTreeSafe(*(CSystemFids **)(this + 0x14),this,pCVar1);
  }
  pCVar1 = this + 0x28;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar1,pCVar4,(ulong)unaff_ESI);
      if (*(CSystemFids **)(*(int *)pSVar3 + 0x14) == this) {
        unaff_ESI = pCVar4;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar1,pCVar4,(ulong)unaff_EBP);
        *(undefined4 *)(*(int *)pSVar3 + 0x14) = 0;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  this_00 = this + 0x1c;
  pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this_00,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_8 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar2,(ulong)unaff_EBP);
      if (*(CSystemFids **)(*(int *)pSVar3 + 0x14) == this) {
        unaff_EBP = pCVar2;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar2,(ulong)unaff_EBX);
        *(undefined4 *)(*(int *)pSVar3 + 0x14) = 0;
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCStack_8);
  }
  SetTravelInfo((CMwNod *)this,0);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (pCVar1,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EBP);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,unaff_EBX);
  uStack00000010 = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,in_stack_ffffffec);
  ExceptionList = in_stack_0000000c;
  return;
}
}

