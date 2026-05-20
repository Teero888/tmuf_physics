// Class implementation: CSystemArchiveNod

// =================================================
// Function: CSystemArchiveNod::AddInternalRef
// =================================================
int __thiscall
CSystemArchiveNod::AddInternalRef
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong *param_3,
          char *param_4)
{
{
  CSystemArchiveNod *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  SLoadedLight *pSVar3;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x34;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      if (*(CMwNod **)pSVar2 == param_2) {
        *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_4 = pCVar4;
        return 0;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  pSVar3 = CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem
                     (this_00,unaff_ESI);
  *(CMwNod **)pSVar3 = param_2;
  *(undefined4 *)(pSVar3 + 4) = 0;
  *(undefined4 *)(pSVar3 + 8) = 1;
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)param_4 = pCVar1;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::CSystemArchiveNod
// =================================================
void __thiscall
CSystemArchiveNod::CSystemArchiveNod(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  SCasterCat *pSVar1;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar2;
  CSystemFidParameters *in_stack_00000008;
  CSystemFidParameters *in_stack_0000000c;
  ulong in_stack_00000010;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  CSystemArchiveNod *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar4;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar5;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar6;
  
  pCVar6 = (CFastBuffer<class_CPlugFileSndGen*> *)0xffffffff;
  pCVar5 = (CFastBuffer<class_CPlugFileSndGen*> *)&LAB_00a80ad6;
  pCVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CClassicArchive::CClassicArchive
            ((CClassicArchive *)this,(CClassicArchive *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  pCVar2 = (CFastBuffer<class_CPlugFileSndGen*> *)0x0;
  *(undefined ***)this = vftable;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x20,unaff_EDI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x28,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x34,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar3);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x40,pCVar4);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x60,pCVar5);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x6c,pCVar6);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xa8,pCVar2);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xb4,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  uStack00000020 = 8;
  CSystemFidParameters::CSystemFidParameters
            ((CSystemFidParameters *)(this + 0xc0),in_stack_00000008,in_stack_0000000c);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      in_stack_00000010);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)pSVar1;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x90) = 8;
  *(undefined4 *)(this + 0x78) = 7;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x10) = 1;
  *(undefined2 *)(this + 0x18) = 6;
  ExceptionList = in_stack_00000024;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::Compare
// =================================================
void __thiscall
CSystemArchiveNod::Compare
          (CSystemArchiveNod *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4)
{
{
  CClassicBufferMemory *pCVar1;
  int iVar2;
  CClassicBufferMemory *unaff_ESI;
  CClassicBufferMemory *in_stack_ffffffb4;
  CClassicBufferMemory *in_stack_ffffffb8;
  CClassicBufferMemory *in_stack_ffffffbc;
  CClassicBufferMemory local_40 [4];
  CClassicBufferMemory local_3c [20];
  CClassicBufferMemory local_28 [4];
  CClassicBufferMemory local_24 [4];
  CClassicBufferMemory local_20 [20];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a810a0;
  local_c = ExceptionList;
  pCVar1 = (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffb0);
  ExceptionList = &local_c;
  *param_3 = 0;
  CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)&stack0xffffffb4,pCVar1);
  iVar2 = SaveMemoryTemp((CClassicBufferMemory *)&stack0xffffffb8,(CMwNod *)param_2,8,1);
  if (iVar2 != 0) {
    CClassicBufferMemory::CClassicBufferMemory(local_28,unaff_ESI);
    iVar2 = SaveMemoryTemp(local_24,(CMwNod *)param_4,8,1);
    if (iVar2 != 0) {
      iVar2 = CClassicBufferMemory::IsEqualBuffer
                        ((CClassicBufferMemory *)&stack0xffffffbc,local_24,in_stack_ffffffb4);
      *param_3 = iVar2;
      param_2 = (SParam *)((uint)param_2 & 0xffffff00);
      CClassicBufferMemory::~CClassicBufferMemory(local_20,in_stack_ffffffb8);
      CClassicBufferMemory::~CClassicBufferMemory(local_3c,in_stack_ffffffbc);
      ExceptionList = param_2;
      return;
    }
    param_1 = (SParam_Fids *)((uint)param_1 & 0xffffff00);
    CClassicBufferMemory::~CClassicBufferMemory(local_24,in_stack_ffffffb4);
  }
  CClassicBufferMemory::~CClassicBufferMemory(local_40,in_stack_ffffffb8);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::ComputeCrcNat32
// =================================================
void __cdecl CSystemArchiveNod::ComputeCrcNat32(CMwNod *param_1,ulong *param_2)
{
{
  ulong uVar1;
  GmFrustumIso4 *unaff_ESI;
  ulong *in_stack_00000010;
  CClassicBufferMemory *in_stack_ffffffd4;
  CClassicBufferMemory local_28 [4];
  CClassicBuffer local_24 [24];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a810c8;
  local_c = ExceptionList;
  if (param_1 == (CMwNod *)0x0) {
    *param_2 = 0xffffffff;
    return;
  }
  ExceptionList = &local_c;
  CClassicBufferMemory::CClassicBufferMemory
            ((CClassicBufferMemory *)&stack0xffffffd4,
             (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  SaveMemoryTemp(local_28,param_1,8,1);
  CClassicBufferMemory::Reset(local_28,unaff_ESI);
  uVar1 = CFastAlgo::ComputeCrc32(local_24,0xffffffff);
  *in_stack_00000010 = uVar1;
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)local_24,in_stack_ffffffd4);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::ComputeCrcString
// =================================================
void __cdecl CSystemArchiveNod::ComputeCrcString(CMwNod *param_1,CFastString *param_2)
{
{
  CFastString *this;
  ulong local_4;
  
  ComputeCrcNat32(param_1,&local_4);
  CFastString::Format(this,param_2,"%08X");
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::DoDecode
// =================================================
void __thiscall
CSystemArchiveNod::DoDecode(CSystemArchiveNod *this,CSystemArchiveNod *param_1,ulong param_2)
{
{
  *(uint *)(this + 0x80) = (uint)param_1 >> 2 & 1;
  *(uint *)(this + 0xc) = (uint)param_1 & 1;
  *(CSystemArchiveNod **)(this + 0x90) = param_1;
  *(uint *)(this + 0x8c) = (uint)param_1 >> 1 & 1;
  *(uint *)(this + 0x10) = (uint)param_1 >> 3 & 1;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidLoadFile
// =================================================
int __thiscall
CSystemArchiveNod::DoFidLoadFile
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2)
{
{
  CSystemFid *this_00;
  int *piVar1;
  CSystemArchiveNod *pCVar2;
  int iVar3;
  CSystemFid *pCVar4;
  int iVar5;
  ulong uVar6;
  CMwNod *pCVar7;
  undefined4 uVar8;
  CPlugFile *pCVar9;
  CSystemArchiveNod *pCVar10;
  SCasterCat *pSVar11;
  int extraout_EAX;
  CSystemFid *unaff_EBX;
  CSystemFid *unaff_ESI;
  CSystemFid *unaff_EDI;
  CSystemArchiveNod *in_stack_ffffffd0;
  CMwNod *pCVar12;
  SCallStackFidContext *in_stack_ffffffd4;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00a80f28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  this_00 = *(CSystemFid **)(this + 0x50);
  pCVar4 = CSystemFid::ParametrizedGetLoadableFid
                     (this_00,(CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xfffffffc));
  iVar5 = DoFindNod(this,param_1,*(CMwNod ***)(this + 0x50),unaff_EDI);
  if (iVar5 != 0) {
    ExceptionList = local_10;
    return 1;
  }
  CSystemFid::SCallStackFidContext::SCallStackFidContext
            (&stack0xffffffd0,*(SCallStackFidContext **)(this + 0x50),unaff_ESI);
  local_8 = 0;
  iVar5 = CSystemFileName::IsExtensionGbx((CFastStringInt *)(pCVar4 + 0x74));
  if (iVar5 == 0) {
    iVar5 = CSystemFileName::IsExtension((CFastStringInt *)(pCVar4 + 0x74),".xml");
    if (iVar5 != 0) {
      uVar6 = CSystemFid::GetClassId(*(CSystemFid **)(this + 0x50),unaff_EBX);
      iVar5 = CMwNod::StaticMwIsKindOf(uVar6,0x9020000);
      if (iVar5 == 0) {
        pCVar7 = CSystemXmlTools::XmlToNod(*(CSystemFid **)(this + 0x50));
        *(CMwNod **)param_1 = pCVar7;
        if (pCVar7 != (CMwNod *)0x0) {
          iVar5 = (**(code **)(*(int *)pCVar7 + 0x10))();
          if (iVar5 != 0) {
            piVar1 = *(int **)param_1;
            uVar8 = (**(code **)(*piVar1 + 0x78))();
            *(undefined4 *)param_1 = uVar8;
            (**(code **)(*piVar1 + 4))();
          }
          if (*(CSystemFid **)param_1 != (CSystemFid *)0x0) {
            ParametrizedFindOrAddFid
                      (this,(CSystemArchiveNod *)this_00,*(CSystemFid **)param_1,
                       (CMwNod *)in_stack_ffffffd0);
            in_stack_ffffffd0 = *(CSystemArchiveNod **)param_1;
            ParametrizedFinalization(this,in_stack_ffffffd0,(CMwNod *)in_stack_ffffffd4);
          }
        }
        iVar5 = *(int *)param_1;
        local_8 = 0xffffffff;
        CSystemFid::SCallStackFidContext::~SCallStackFidContext
                  (&stack0xffffffd0,(SCallStackFidContext *)in_stack_ffffffd0);
        ExceptionList = local_10;
        return (uint)(iVar5 != 0);
      }
    }
    pCVar9 = CPlugFile::CreateFromFid((CSystemFidFile *)this_00);
    *(CPlugFile **)param_1 = pCVar9;
    if (pCVar9 != (CPlugFile *)0x0) {
      ParametrizedFindOrAddFid
                (this,(CSystemArchiveNod *)this_00,(CSystemFid *)pCVar9,(CMwNod *)in_stack_ffffffd0)
      ;
      pCVar4 = this_00;
      local_18 = (**(code **)(**(int **)param_1 + 0x84))();
      ParametrizedFinalization(this,*(CSystemArchiveNod **)param_1,(CMwNod *)pCVar4);
      if (local_18 == 0) {
        pCVar2 = *(CSystemArchiveNod **)param_1;
        pCVar10 = (CSystemArchiveNod *)(**(code **)(*(int *)pCVar2 + 0x7c))();
        if (pCVar10 != (CSystemArchiveNod *)0x0) {
          if (pCVar2 != pCVar10) {
            pCVar12 = (CMwNod *)0x1;
            pCVar7 = (CMwNod *)0x41a68f;
            (**(code **)(*(int *)pCVar2 + 4))();
            ParametrizedFindOrAddFid(this,(CSystemArchiveNod *)this_00,(CSystemFid *)pCVar10,pCVar7)
            ;
            ParametrizedFinalization(this,pCVar10,pCVar12);
          }
          *(CSystemArchiveNod **)param_1 = pCVar10;
          local_18 = 1;
        }
      }
      local_8 = 0xffffffff;
      CSystemFid::SCallStackFidContext::~SCallStackFidContext(&stack0xffffffd0,in_stack_ffffffd4);
      ExceptionList = local_10;
      return local_18;
    }
  }
  else {
    iVar5 = (**(code **)**(undefined4 **)(this_00 + 0x6c))();
    *(int *)(this + 4) = iVar5;
    if (iVar5 != 0) {
      pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(DAT_00d73300 + 0x20),
                           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                           (ulong)in_stack_ffffffd0);
      iVar5 = *(int *)pSVar11;
      if ((((DAT_00d72e8c == (code *)0x0) && (*(int *)(this + 0x50) != 0)) &&
          (iVar3 = *(int *)(*(int *)(this + 0x50) + 0x14), iVar3 != 0)) &&
         (((iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0 && (iVar5 != 0)) &&
          ((iVar3 == *(int *)(iVar5 + 0x28) || (iVar3 == *(int *)(iVar5 + 0x30))))))) {
        DAT_00d72e8c = CCorruptedLoadFromFidException::Throw;
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      DoLoadAll(this,param_1,(CMwNod **)in_stack_ffffffd4);
      local_8 = 0;
      FUN_0041a7ae();
      return extraout_EAX;
    }
    *(undefined4 *)param_1 = 0;
  }
  local_8 = 0xffffffff;
  CSystemFid::SCallStackFidContext::~SCallStackFidContext
            (&stack0xffffffd0,(SCallStackFidContext *)in_stack_ffffffd0);
  ExceptionList = local_10;
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidLoadMemory
// =================================================
int __thiscall
CSystemArchiveNod::DoFidLoadMemory
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2)
{
{
  int iVar1;
  CMwNod **unaff_EBX;
  CSystemFid *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  
  iVar1 = DoFindNod(this,param_1,*(CMwNod ***)(this + 0x50),unaff_ESI);
  if (iVar1 == 0) {
    iVar1 = *(int *)(this + 0x50);
    CClassicBufferMemory::Reset(*(CClassicBufferMemory **)(iVar1 + 0x74),unaff_EDI);
    *(undefined4 *)(this + 4) = *(undefined4 *)(iVar1 + 0x74);
    iVar1 = DoLoadAll(this,param_1,unaff_EBX);
    if (iVar1 == 0) {
      (**(code **)(**(int **)(this + 4) + 0xc))();
      *(undefined4 *)(this + 4) = 0;
      return 0;
    }
    (**(code **)(**(int **)(this + 4) + 0xc))();
    *(undefined4 *)(this + 4) = 0;
  }
  else if (*(int **)(this + 0x50) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x50) + 4))(1);
    return 1;
  }
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidLoadRefs
// =================================================
int __thiscall
CSystemArchiveNod::DoFidLoadRefs
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,EArchive param_2,
          CClassicBuffer *param_3)
{
{
  int iVar1;
  CSystemFid *pCVar2;
  ulong uVar3;
  CMwClassInfo *pCVar4;
  undefined4 uVar5;
  CSystemArchiveNod *unaff_EBP;
  CSystemArchiveNod *unaff_ESI;
  CSystemFid *unaff_EDI;
  
  *(undefined4 *)(*(int *)(this + 0x50) + 100) = 0xffffffff;
  *(CSystemArchiveNod **)(this + 0x78) = param_1;
  if (param_2 == 0) {
    iVar1 = (**(code **)(**(int **)(this + 0x50) + 0x10))(0xb00e000);
    if (iVar1 == 0) {
      pCVar2 = CSystemFid::ParametrizedGetLoadableFid(*(CSystemFid **)(this + 0x50),unaff_EDI);
      iVar1 = CSystemFileName::IsExtensionGbx((CFastStringInt *)(pCVar2 + 0x74));
      if (iVar1 != 0) {
        iVar1 = (**(code **)**(undefined4 **)(*(int *)(this + 0x50) + 0x6c))
                          (*(int *)(this + 0x50),1,1);
        *(int *)(this + 4) = iVar1;
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = DoLoadAllRef(this,unaff_EBP);
        (**(code **)(**(int **)(*(int *)(this + 0x50) + 0x6c) + 4))
                  (*(int *)(this + 0x50),*(undefined4 *)(this + 4));
        *(undefined4 *)(this + 4) = 0;
        return iVar1;
      }
      iVar1 = CSystemFileName::IsExtension((CFastStringInt *)(pCVar2 + 0x74),".xml");
      if (iVar1 == 0) {
        uVar3 = CPlugFile::GetClassIdFromFid(*(CSystemFidFile **)(this + 0x50));
      }
      else {
        uVar3 = CPlugFile::GetClassIdFromFid(*(CSystemFidFile **)(this + 0x50));
        if (uVar3 == 0xffffffff) {
          uVar3 = CSystemXmlTools::XmlToNodClassId(*(CSystemFid **)(this + 0x50));
          if (uVar3 == 0xffffffff) goto LAB_0041a46c;
        }
        iVar1 = CMwNod::StaticMwIsKindOf(uVar3,0xb017000);
        if (iVar1 != 0) {
          pCVar4 = CMwNod::StaticGetClassInfo(uVar3);
          uVar5 = (**(code **)(*(int *)pCVar4 + 4))();
          *(undefined4 *)(*(int *)(this + 0x50) + 100) = uVar5;
          return 1;
        }
      }
LAB_0041a46c:
      *(ulong *)(*(int *)(this + 0x50) + 100) = uVar3;
      return 1;
    }
    param_2 = *(EArchive *)(*(CSystemFid **)(this + 0x50) + 0x74);
  }
  *(EArchive *)(this + 4) = param_2;
  iVar1 = DoLoadAllRef(this,unaff_ESI);
  *(undefined4 *)(this + 4) = 0;
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidSaveFile
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
CSystemArchiveNod::DoFidSaveFile(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2)
{
{
  CSystemFid *this_00;
  CSystemFid *this_01;
  undefined4 uVar1;
  EMakeDir EVar2;
  int iVar3;
  SNationConfig *pSVar4;
  CSystemFidParameters *unaff_EBP;
  CMwNod *unaff_ESI;
  CSystemFid *unaff_EDI;
  void *unaff_retaddr;
  undefined *puStack0000000c;
  SHeaderCommunity *pSVar5;
  CSystemFidFile *pCVar6;
  CSystemFidParameters *pCVar7;
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  int iStack_118;
  undefined *puStack_114;
  undefined *puStack_110;
  SNationConfig *pSStack_10c;
  undefined *puStack_108;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80ef1;
  local_c = ExceptionList;
  local_10 = DAT_00cca150 ^ (uint)auStack_120;
  ExceptionList = &local_c;
  DoFormatFromFid(this,(CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xfffffed0));
  this_00 = *(CSystemFid **)(this + 0x50);
  this_01 = CSystemFid::ParametrizedGetLoadableFid(this_00,unaff_EDI);
  *(undefined4 *)(this + 8) = 1;
  uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
  *(undefined4 *)(this + 0x4c) = uVar1;
  if (((*(undefined ***)(*(int *)(this + 0x50) + 0x6c) != &PTR_vftable_00ccbf90) ||
      ((*(byte *)(*(int *)(this + 0x50) + 0x18) & 1) == 0)) ||
     (EVar2 = CSystemFidsFolder::MakeDir((CFastStringInt *)0x1), EVar2 != 0)) {
    iVar3 = CSystemFileName::IsExtensionGbx((CFastStringInt *)(this_01 + 0x74));
    if (iVar3 == 0) {
      puStack0000000c = (undefined *)(**(code **)(*(int *)param_1 + 0x10))();
      if (puStack0000000c != (undefined *)0x0) {
        pCVar7 = (CSystemFidParameters *)0x41a225;
        iStack_118 = (**(code **)(*(int *)this_01 + 0x88))();
        if (iStack_118 == 0) {
          puStack_114 = PTR_DAT_00bbf7dc;
          pSVar5 = (SHeaderCommunity *)0x0;
          CSystemFidFile::GetFullName
                    ((CSystemFidFile *)this_00,(CPlugFile *)&iStack_118,(CFastStringInt *)0x0);
          CFastStringInt::GetLatin1(auStack_11c,(CFastStringInt *)&puStack_114);
          sprintf_s<256>((char *)&pSStack_10c,"Cannot write file %s");
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&puStack_114,pSVar5);
          CGameCtnApp::SNationConfig::~SNationConfig(&iStack_118,(SNationConfig *)unaff_ESI);
          ExceptionList = unaff_retaddr;
          return 0;
        }
        pSVar4 = (SNationConfig *)(**(code **)(*(int *)param_1 + 0x88))();
        if (pSVar4 == (SNationConfig *)0x0) {
          puStack_108 = PTR_DAT_00bbf7dc;
          pSStack_10c = pSVar4;
          CSystemFidFile::GetFullName
                    ((CSystemFidFile *)this_00,(CPlugFile *)&pSStack_10c,(CFastStringInt *)0x0);
          CGameCtnApp::SNationConfig::~SNationConfig(&puStack_110,pSVar4);
          ExceptionList = unaff_retaddr;
          return 0;
        }
        CSystemEngine::AddFidNod
                  (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,(CMwNod *)this_00,
                   (CSystemFid *)&DAT_00d554d0,pCVar7);
        uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
LAB_0041a369:
        *(undefined4 *)(this_00 + 100) = uVar1;
        ExceptionList = unaff_retaddr;
        return 1;
      }
      pSStack_10c = (SNationConfig *)PTR_DAT_00bbf7dc;
      puStack_110 = puStack0000000c;
      CSystemFidFile::GetFullName
                ((CSystemFidFile *)this_00,(CPlugFile *)&puStack_110,(CFastStringInt *)0x0);
      if (puStack_110 != PTR_DAT_00bbf7dc) {
        if ((puStack_110[-1] & 0x80) != 0) {
          operator_delete__(puStack_110 + -4);
          ExceptionList = unaff_retaddr;
          return 0;
        }
        operator_delete__(puStack_110 + -2);
      }
    }
    else {
      iVar3 = DoSaveBodyMemory(this,param_1,unaff_ESI);
      if (iVar3 != 0) {
        CSystemEngine::AddFidNod
                  (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,(CMwNod *)this_00,
                   (CSystemFid *)&DAT_00d554d0,unaff_EBP);
        pCVar6 = (CSystemFidFile *)0x2;
        iVar3 = (**(code **)**(undefined4 **)(this_01 + 0x6c))();
        *(int *)(this + 4) = iVar3;
        if (iVar3 != 0) {
          puStack_114 = (undefined *)DoSaveAll(this,(CSystemArchiveNod *)pCVar6);
          pCVar6 = *(CSystemFidFile **)(this + 4);
          (**(code **)(**(int **)(this_01 + 0x6c) + 4))();
          *(undefined4 *)(this + 4) = 0;
          if (iStack_118 != 0) {
            CSystemFidFile::ForceUpdateFidProps((CSystemFidFile *)this_01,pCVar6);
            uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
            goto LAB_0041a369;
          }
        }
        CSystemEngine::RemoveFid
                  (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)this_00,(CSystemFid *)pCVar6);
        ExceptionList = unaff_retaddr;
        return 0;
      }
    }
  }
  ExceptionList = unaff_retaddr;
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidSaveFileSafe
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
CSystemArchiveNod::DoFidSaveFileSafe
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong param_3)
{
{
  CSystemFid *this_00;
  undefined4 uVar1;
  EMakeDir EVar2;
  int iVar3;
  ulong uVar4;
  SHeaderCommunity *pSVar5;
  SNationConfig *pSVar6;
  int *piVar7;
  CClassicBufferMemory *unaff_EBX;
  CMwNod *unaff_ESI;
  CSystemFid *unaff_EDI;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  CSystemArchiveNod *in_stack_fffffcb4;
  ulong in_stack_fffffcb8;
  CSystemFidFile *pCVar8;
  CSystemFid *in_stack_fffffcbc;
  CSystemFid *pCVar9;
  char *this_01;
  CClassicBufferMemory *in_stack_fffffcc4;
  CClassicBufferMemory *pCVar10;
  SHeaderCommunity *in_stack_fffffcc8;
  int iStack_330;
  SHeaderCommunity *pSStack_32c;
  CSystemFidFile *pCStack_328;
  CMwNod *pCStack_324;
  int iStack_320;
  CFastStringInt aCStack_31c [4];
  CSystemFid aCStack_318 [4];
  CClassicBuffer *pCStack_314;
  CMwNod *pCStack_310;
  CFastStringInt aCStack_304 [4];
  CSystemArchiveNod aCStack_300 [4];
  CSystemArchiveNod aCStack_2fc [8];
  CSystemArchiveNod aCStack_2f4 [80];
  undefined4 uStack_2a4;
  char acStack_204 [8];
  char acStack_1fc [240];
  char acStack_10c [240];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a8102d;
  local_14 = ExceptionList;
  local_1c = DAT_00cca150 ^ (uint)&stack0xfffffcb4;
  ExceptionList = &local_14;
  DoFormatFromFid(this,(CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xfffffca8));
  this_01 = *(char **)(this + 0x50);
  this_00 = CSystemFid::ParametrizedGetLoadableFid((CSystemFid *)this_01,unaff_EDI);
  *(undefined4 *)(this + 8) = 1;
  uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
  *(undefined4 *)(this + 0x4c) = uVar1;
  if (((*(undefined ***)(*(int *)(this + 0x50) + 0x6c) == &PTR_vftable_00ccbf90) &&
      ((*(byte *)(*(int *)(this + 0x50) + 0x18) & 1) != 0)) &&
     (EVar2 = CSystemFidsFolder::MakeDir((CFastStringInt *)0x1), EVar2 == 0)) {
LAB_0041ad9d:
    iVar3 = 0;
  }
  else {
    iVar3 = CSystemFileName::IsExtensionGbx((CFastStringInt *)(this_00 + 0x74));
    if (iVar3 == 0) {
      iStack_320 = (**(code **)(*(int *)param_1 + 0x10))();
      pSStack_32c = (SHeaderCommunity *)
                    CSystemFileName::IsExtension((CFastStringInt *)(this_00 + 0x74),".xml");
      if (iStack_320 == 0) {
        if (pSStack_32c != (SHeaderCommunity *)0x0) goto LAB_0041ada8;
        uStack00000014 = 0;
        pCStack_328 = (CSystemFidFile *)PTR_DAT_00bbf7dc;
LAB_0041ad8d:
        pSStack_32c = (SHeaderCommunity *)0x0;
        pSVar6 = (SNationConfig *)0x0;
        PTR_DAT_00bbf7dc = pCStack_328;
        CSystemFidFile::GetFullName
                  ((CSystemFidFile *)this_00,(CPlugFile *)&pSStack_32c,(CFastStringInt *)0x0);
        CGameCtnApp::SNationConfig::~SNationConfig(&iStack_330,pSVar6);
        goto LAB_0041ad9d;
      }
      if (pSStack_32c != (SHeaderCommunity *)0x0) {
LAB_0041ada8:
        uVar4 = CSystemXmlTools::XmlToNodClassId(this_00);
        if ((uVar4 != 0xffffffff) && (iVar3 = CMwNod::StaticMwIsKindOf(uVar4,0xb017000), iVar3 != 0)
           ) goto LAB_0041ad9d;
      }
      pSVar5 = (SHeaderCommunity *)(**(code **)(*(int *)this_00 + 0x88))();
      if (pSVar5 == (SHeaderCommunity *)0x0) {
        pCStack_328 = (CSystemFidFile *)PTR_DAT_00bbf7dc;
        uStack00000014 = 1;
        pSStack_32c = pSVar5;
        CSystemFidFile::GetFullName
                  ((CSystemFidFile *)this_00,(CPlugFile *)&pSStack_32c,(CFastStringInt *)0x0);
        CFastStringInt::GetLatin1(&iStack_330,(CFastStringInt *)&pCStack_324);
        sprintf_s<256>(acStack_204,"Cannot write file %s");
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&pCStack_324,pSVar5);
        CGameCtnApp::SNationConfig::~SNationConfig(&pSStack_32c,(SNationConfig *)in_stack_fffffcc4);
        ExceptionList = in_stack_00000010;
        return 0;
      }
      if (iStack_320 == 0) {
        if ((pSStack_32c != (SHeaderCommunity *)0x0) &&
           (iVar3 = CSystemXmlTools::NodToXml((CMwNod *)param_1,this_00), iVar3 == 0)) {
          pCStack_328 = (CSystemFidFile *)PTR_DAT_00bbf7dc;
          uStack00000014 = 3;
          goto LAB_0041ad8d;
        }
      }
      else {
        iVar3 = (**(code **)(*(int *)param_1 + 0x88))();
        if (iVar3 == 0) {
          uStack00000014 = 2;
          pCStack_328 = (CSystemFidFile *)PTR_DAT_00bbf7dc;
          goto LAB_0041ad8d;
        }
      }
      CSystemEngine::AddFidNod
                (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,pCStack_324,
                 (CSystemFid *)&DAT_00d554d0,(CSystemFidParameters *)in_stack_fffffcc4);
      uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
      *(undefined4 *)(pCStack_324 + 100) = uVar1;
    }
    else {
      CSystemEngine::UnbindFid(*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,unaff_ESI);
      CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)&pSStack_32c,unaff_EBX);
      CSystemArchiveNod(aCStack_300,in_stack_fffffcb4);
      uStack_2a4 = *(undefined4 *)(iStack_330 + 0x14);
      pSVar6 = (SNationConfig *)
               DoSaveMemory(aCStack_2fc,(CSystemArchiveNod *)&pCStack_324,
                            (CClassicBufferMemory *)param_1,*(CMwNod **)(this + 0x90),
                            in_stack_fffffcb8);
      pCStack_328 = (CSystemFidFile *)pCStack_310;
      if (*(CSystemEngine **)(param_1 + 8) != (CSystemEngine *)0x0) {
        CSystemEngine::RemoveAndDeleteFid
                  (*(CSystemEngine **)(this + 0x1c),*(CSystemEngine **)(param_1 + 8),
                   in_stack_fffffcbc);
      }
      if (iStack_330 == 0) goto LAB_0041b058;
      *(CSystemFidFile **)(this + 0x50) = pCStack_328;
      pCVar8 = pCStack_328;
      CSystemEngine::BindFidNod
                (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,(CMwNod *)pCStack_328,
                 (CSystemFid *)this_01);
      this_01 = (char *)0x41af67;
      iVar3 = CSystemFidFile::OSCheckIfExists
                        ((CSystemFidFile *)this_00,(CSystemFidFile *)in_stack_fffffcc4);
      if (iVar3 == 0) {
        if (*(undefined4 **)(this + 0x98) == (undefined4 *)0x0) {
LAB_0041b095:
          CSystemEngine::AddFidNod
                    (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,(CMwNod *)pSStack_32c
                     ,(CSystemFid *)&DAT_00d554d0,(CSystemFidParameters *)pCVar8);
          pCVar9 = (CSystemFid *)0x0;
          piVar7 = (int *)(**(code **)**(undefined4 **)(this_00 + 0x6c))();
          *(int **)(this + 4) = piVar7;
          if (piVar7 == (int *)0x0) {
            CSystemEngine::RemoveFid
                      (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)pSStack_32c,pCVar9);
LAB_0041b058:
            in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,4);
            ~CSystemArchiveNod(aCStack_2f4,(CSystemArchiveNod *)this_01);
            uStack00000014 = 0xffffffff;
            CClassicBufferMemory::~CClassicBufferMemory
                      ((CClassicBufferMemory *)aCStack_318,in_stack_fffffcc4);
            ExceptionList = in_stack_00000010;
            return 0;
          }
          pCVar8 = pCStack_328;
          (**(code **)(*piVar7 + 8))();
          CSystemFid::BufferClose(this_00,*(CSystemFid **)(this + 4),pCStack_314);
          *(undefined4 *)(this + 4) = 0;
          CSystemFidFile::ForceUpdateFidProps((CSystemFidFile *)this_00,pCVar8);
          uVar1 = (**(code **)(*(int *)param_1 + 0xc))();
          *(undefined4 *)(pCStack_328 + 100) = uVar1;
        }
        else {
          **(undefined4 **)(this + 0x98) = 1;
        }
      }
      else {
        pCStack_328 = (CSystemFidFile *)0x0;
        pCStack_324 = (CMwNod *)PTR_DAT_00bbf7dc;
        pCVar10 = (CClassicBufferMemory *)0x0;
        CSystemFidFile::GetFullName
                  ((CSystemFidFile *)this_00,(CPlugFile *)&pCStack_328,(CFastStringInt *)0x0);
        this_01 = (char *)aCStack_318;
        pSVar5 = (SHeaderCommunity *)0x41afa5;
        pCVar8 = (CSystemFidFile *)this_00;
        iVar3 = DoIsFileSame(this,(CSystemArchiveNod *)this_00,(CSystemFid *)this_01,pCVar10);
        if (*(uint **)(this + 0x98) == (uint *)0x0) {
          if (iVar3 == 0) {
            in_stack_fffffcc4 = (CClassicBufferMemory *)0x41b01b;
            iVar3 = (**(code **)(*(int *)this_00 + 0x88))();
            if (iVar3 == 0) {
              CFastStringInt::GetLatin1(&stack0xfffffcc8,aCStack_304);
              sprintf_s<256>(acStack_10c,"Cannot write file %s");
              CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(aCStack_304,pSVar5);
              CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffccc,(SNationConfig *)pCVar8);
              goto LAB_0041b058;
            }
            CGameCtnApp::SNationConfig::~SNationConfig(&stack0xfffffcc8,(SNationConfig *)pSVar5);
            goto LAB_0041b095;
          }
          CFastStringInt::GetLatin1(&pCStack_328,aCStack_31c);
          this_01 = "no change detected to %s";
          sprintf_s<256>(acStack_1fc,"no change detected to %s");
          in_stack_fffffcc4 = (CClassicBufferMemory *)0x41affa;
          CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(aCStack_31c,in_stack_fffffcc8);
          *(undefined4 *)(this + 4) = 0;
          CGameCtnApp::SNationConfig::~SNationConfig(&pCStack_324,pSVar6);
        }
        else {
          **(uint **)(this + 0x98) = (uint)(iVar3 == 0);
          in_stack_fffffcc4 = (CClassicBufferMemory *)0x41afc1;
          CGameCtnApp::SNationConfig::~SNationConfig
                    (&pCStack_328,(SNationConfig *)in_stack_fffffcc8);
        }
      }
      in_stack_00000010 = (void *)CONCAT31(in_stack_00000010._1_3_,4);
      ~CSystemArchiveNod(aCStack_2f4,(CSystemArchiveNod *)this_01);
      uStack00000014 = 0xffffffff;
      CClassicBufferMemory::~CClassicBufferMemory
                ((CClassicBufferMemory *)aCStack_318,in_stack_fffffcc4);
    }
    iVar3 = 1;
  }
  ExceptionList = in_stack_00000010;
  return iVar3;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFidSaveMemory
// =================================================
int __thiscall
CSystemArchiveNod::DoFidSaveMemory
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2)
{
{
  CClassicBufferMemory *this_00;
  undefined4 uVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  GmFrustumIso4 *unaff_ESI;
  CSystemArchiveNod *unaff_EDI;
  CSystemArchiveNod *unaff_retaddr;
  CSystemArchiveNod *in_stack_0000000c;
  
  if (*(int *)(this + 0x84) == 0) {
    DoFormatFromFid(this,unaff_EDI);
  }
  this_00 = *(CClassicBufferMemory **)(*(int *)(this + 0x50) + 0x74);
  CClassicBufferMemory::Reset(this_00,unaff_ESI);
  *(undefined4 *)(this + 8) = 1;
  uVar1 = (**(code **)(*(int *)in_stack_0000000c + 0xc))();
  *(undefined4 *)(this + 0x4c) = uVar1;
  iVar2 = DoSaveBodyMemory(this,in_stack_0000000c,unaff_EBX);
  if (iVar2 == 0) {
    return 0;
  }
  *(CClassicBufferMemory **)(this + 4) = this_00;
  iVar2 = DoSaveAll(this,unaff_retaddr);
  if (iVar2 == 0) {
    CSystemEngine::RemoveFid
              (*(CSystemEngine **)(this + 0x1c),*(CSystemEngine **)(this + 0x50),
               (CSystemFid *)param_1);
    *(undefined4 *)(this + 4) = 0;
    return 0;
  }
  *(undefined4 *)(this + 4) = 0;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFindNod
// =================================================
int __thiscall
CSystemArchiveNod::DoFindNod
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2,CSystemFid *param_3)
{
{
  CSystemFid *this_00;
  CSystemFidParameters *pCVar1;
  CPlugMaterial *pCVar2;
  CFastStringInt *unaff_ESI;
  int unaff_retaddr;
  undefined4 *in_stack_00000010;
  
  this_00 = CSystemEngine::FindFid
                      (*(CSystemEngine **)(this + 0x1c),(CSystemFids *)param_2,unaff_ESI,
                       unaff_retaddr,(EFindWay)param_1);
  if (this_00 != (CSystemFid *)0x0) {
    pCVar1 = CSystemFidParameters::GetCurrentParameters();
    pCVar2 = CSystemFid::GetNod(this_00,(CSysFidNodRef<class_CPlugMaterial> *)pCVar1);
    if (pCVar2 != (CPlugMaterial *)0x0) {
      *in_stack_00000010 = pCVar2;
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoFormatFromFid
// =================================================
void __thiscall
CSystemArchiveNod::DoFormatFromFid(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(this + 0x90) == 8) {
    uVar2 = *(uint *)(*(int *)(this + 0x50) + 0x1c) >> 9 & 1;
    *(uint *)(this + 0xc) = uVar2;
    uVar1 = *(uint *)(*(int *)(this + 0x50) + 0x1c) >> 10 & 1;
    *(uint *)(this + 0x8c) = uVar1;
    if (uVar2 != 0) {
      *(undefined4 *)(this + 0x90) = 9;
    }
    if (uVar1 != 0) {
      *(uint *)(this + 0x90) = *(uint *)(this + 0x90) | 2;
    }
  }
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::DoIsFileSame
// =================================================
int __thiscall
CSystemArchiveNod::DoIsFileSame
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFid *param_2,
          CClassicBufferMemory *param_3)
{
{
  CClassicBuffer *this_00;
  int iVar1;
  CClassicBufferMemory *unaff_EBX;
  CClassicBufferMemory *unaff_ESI;
  
  this_00 = (CClassicBuffer *)(**(code **)**(undefined4 **)(param_1 + 0x6c))(param_1,1,0);
  if (this_00 == (CClassicBuffer *)0x0) {
    return 0;
  }
  iVar1 = CClassicBuffer::IsEqualBuffer(this_00,unaff_ESI,unaff_EBX);
  (**(code **)(**(int **)(param_1 + 0x6c) + 4))(param_1,this_00);
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadAll
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadAll(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2)
{
{
  int *this_00;
  int iVar1;
  CMwNod *pCVar2;
  ulong uVar3;
  SNewTriangleVert *pSVar4;
  SLoadedLight *pSVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EBP;
  CSystemArchiveNod *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int *piVar6;
  CMwNod *unaff_retaddr;
  CSystemArchiveNod *in_stack_0000000c;
  undefined4 *in_stack_00000010;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar7;
  
  *(undefined4 *)(this + 8) = 0;
  iVar1 = DoLoadHeader(this,unaff_ESI);
  if (iVar1 != 0) {
    if (*(int *)(this + 0x78) != 3) {
      pCVar2 = CMwNod::CreateByMwClassId(*(ulong *)(this + 0x4c));
      *param_2 = pCVar2;
      if (pCVar2 == (CMwNod *)0x0) {
        return 0;
      }
      ParametrizedFindOrAddFid
                (this,*(CSystemArchiveNod **)(this + 0x50),(CSystemFid *)pCVar2,unaff_retaddr);
      CSystemFidParameters::GetCurrentParameters();
    }
    piVar6 = DAT_00d54220;
    if ((DAT_00d54220 != (int *)0x0) && (*(int *)(*(int *)(this + 0x50) + 0x18) != 8)) {
      this_00 = DAT_00d54220 + 1;
      pCVar7 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x41a055;
      uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
      if (uVar3 != 0) {
        pCVar7 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x41a061;
        pSVar4 = CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::
                 GetLastElem(this_00,unaff_EBP);
        iVar1 = *(int *)(pSVar4 + 4);
        if ((iVar1 + 1U < *(uint *)pSVar4) ||
           (uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(piVar6 + 1,unaff_EDI), uVar3 == 1)) {
          *(uint *)(pSVar4 + 4) = iVar1 + 1U;
          piVar6 = DAT_00d54220;
        }
      }
      unaff_EDI = (CFastBuffer<class_CCrystalFace*> *)0x41a091;
      (**(code **)(*piVar6 + 4))();
      pSVar5 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem(DAT_00d54220 + 1,pCVar7);
      *(undefined4 *)pSVar5 = 1;
      *(undefined4 *)(pSVar5 + 4) = 0xffffffff;
    }
    iVar1 = DoLoadRef(this,(CSystemArchiveNod *)unaff_EDI);
    if ((iVar1 != 0) &&
       ((((byte)this[0x78] & 7) == 0 ||
        (iVar1 = DoLoadBody(this,in_stack_0000000c,(CMwNod **)param_1), iVar1 != 0)))) {
      ParametrizedFinalization(this,(CSystemArchiveNod *)*in_stack_00000010,(CMwNod *)param_2);
      if ((DAT_00d54220 != (int *)0x0) && (*(int *)(*(int *)(this + 0x50) + 0x18) != 8)) {
        DAT_00d54220[1] = DAT_00d54220[1] + -1;
      }
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadAllRef
// =================================================
int __thiscall CSystemArchiveNod::DoLoadAllRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  CSystemArchiveNod *pCVar1;
  int iVar2;
  CSystemArchiveNod *unaff_ESI;
  undefined4 uStack00000008;
  void *in_stack_0000000c;
  SVertexDataLayer *in_stack_ffffffe8;
  int in_stack_ffffffec;
  CFastBuffer<struct_CDx9StateBlock::STexStageState> *in_stack_fffffff0;
  CIteratorMaterial *pCVar3;
  undefined1 *local_8;
  void *local_4;
  
  pCVar3 = ExceptionList;
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00a80e68;
  pCVar1 = (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &stack0xfffffff4;
  *(undefined4 *)(this + 8) = 0;
  iVar2 = DoLoadHeader(this,pCVar1);
  if (iVar2 == 0) {
    ExceptionList = local_4;
    return 0;
  }
  if (*(int *)(this + 0x78) != 1) {
    iVar2 = DoLoadRef(this,unaff_ESI);
    if (iVar2 == 0) {
      ExceptionList = local_4;
      return 0;
    }
    SVertexDataLayer::SVertexDataLayer(&stack0xfffffff0,in_stack_ffffffe8);
    uStack00000008 = 0;
    iVar2 = CSystemFid::LoadHeaderUserDataFromChunkId<struct_CSystemArchiveNod::SHeaderFolderDep>
                      (*(CSystemFid **)(this + 0x50),(CSystemFid *)&stack0xfffffff4,
                       (SHeaderFolderDep *)0x1001000,0,in_stack_ffffffec);
    if (iVar2 != 0) {
      CFastBuffer<class_CGameFid*>::CopyFromFastBuffer
                (this + 0x40,(CFastBuffer<struct_CDx9StateBlock::STexStageState> *)&local_8,
                 in_stack_fffffff0);
    }
    CPlugTree::CIteratorMaterial::~CIteratorMaterial(&local_4,pCVar3);
  }
  ExceptionList = in_stack_0000000c;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadBody
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadBody(CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2)
{
{
  CSystemArchiveNod *pCVar1;
  int *piVar2;
  CMwNod *this_00;
  CClassicBufferMemory *pCVar3;
  int iVar4;
  int iVar5;
  CClassicBufferMemory *extraout_EAX;
  CClassicBufferMemory *pCVar6;
  SCasterCat *pSVar7;
  SCasterCat *pSVar8;
  ulong uVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CMwCmdBufferCore *unaff_EBP;
  CClassicBuffer *unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  undefined4 uStack0000000c;
  undefined4 *in_stack_00000010;
  undefined *in_stack_ffffffe0;
  ulong *puVar12;
  CClassicBufferMemory *local_14;
  CClassicBufferMemory *pCStack_10;
  void *local_c;
  CClassicBufferMemory *pCStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pCStack_8 = (CClassicBufferMemory *)&LAB_00a80bd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFid::SCallStackFidContext::SCallStackFidContext
            (&local_14,*(SCallStackFidContext **)(this + 0x50),
             (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  piVar2 = *(int **)(this + 4);
  iVar4 = (**(code **)(*piVar2 + 0x18))();
  iVar5 = (**(code **)(*piVar2 + 0x14))();
  *(int *)(this + 0x9c) = iVar4 - iVar5;
  if (*(int *)(this + 0x78) == 3) {
    *param_2 = (CMwNod *)0x0;
    param_2 = operator_new(0x20);
    if ((CClassicBufferMemory *)param_2 == (CClassicBufferMemory *)0x0) {
      pCVar6 = (CClassicBufferMemory *)0x0;
    }
    else {
      CClassicBufferMemory::CClassicBufferMemory((CClassicBufferMemory *)param_2,unaff_EDI);
      pCVar6 = extraout_EAX;
    }
    *(CClassicBufferMemory **)(this + 0xa4) = pCVar6;
    CClassicBufferMemory::PreAlloc(pCVar6,*(CClassicBufferMemory **)(this + 0x9c),(ulong)unaff_EDI);
    iVar4 = CClassicBuffer::ReadAll
                      (*(CClassicBuffer **)(this + 4),
                       *(CClassicBuffer **)(*(int *)(this + 0xa4) + 0xc),*(void **)(this + 0x9c),
                       (ulong)unaff_ESI);
    if (iVar4 == 0) {
LAB_00417a43:
      uStack0000000c = 0xffffffff;
      CSystemFid::SCallStackFidContext::~SCallStackFidContext
                (&uStack_4,(SCallStackFidContext *)unaff_EBX);
      ExceptionList = param_2;
      return 0;
    }
    *(undefined4 *)(*(int *)(this + 0xa4) + 0x10) = *(undefined4 *)(this + 0x9c);
  }
  else {
    local_14 = *(CClassicBufferMemory **)(this + 4);
    puVar12 = (ulong *)0x0;
    if (*(int *)(this + 0x8c) != 0) {
      CMwCmdBufferCore::HighFrequencyEnterSafeSection
                (DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)unaff_EDI);
      unaff_EDI = (CClassicBufferMemory *)0x417a97;
      local_14 = CClassicBuffer::CreateUncompressedBlock(*(CClassicBuffer **)(this + 4),unaff_ESI);
      unaff_ESI = (CClassicBuffer *)0x417aa6;
      CMwCmdBufferCore::HighFrequencyLeaveSafeSection(DAT_00d731e0,unaff_EBP);
      if (pCStack_10 == (CClassicBufferMemory *)0x0) goto LAB_00417a43;
      *(CClassicBufferMemory **)(this + 4) = pCStack_10;
    }
    pCVar1 = this + 0x28;
    local_14 = (CClassicBufferMemory *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_14 != (CClassicBufferMemory *)0x0) {
      do {
        pSVar7 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (pCVar1,pCVar10,(ulong)unaff_ESI);
        pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this + 0x34,
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 8),
                            (ulong)unaff_EBP);
        unaff_ESI = (CClassicBuffer *)0x417ae3;
        pSVar8 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (pCVar1,pCVar10,(ulong)unaff_EBX);
        unaff_EBX = pCVar10;
        if (*(int *)(pSVar8 + 0x10) == 0) {
          unaff_EBP = (CMwCmdBufferCore *)0x417afc;
          pSVar8 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (pCVar1,pCVar10,(ulong)in_stack_ffffffe0);
          this_00 = *(CMwNod **)(*(int *)pSVar8 + 0x20);
          *(CMwNod **)pSVar7 = this_00;
          if (*(int *)(this + 8) == 0) {
            in_stack_ffffffe0 = &DAT_00b2e39c;
            unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
            unaff_EBP = (CMwCmdBufferCore *)0x417b15;
            uVar9 = CMwNod::MwGetNearestFather(this_00,(CMwClassInfo *)0x1,0xb2e39c,puVar12);
            if (uVar9 != 0xffffffff) {
              puVar12 = (ulong *)0x417b21;
              CMwNod::MwAddRef(*(CMwNod **)pSVar7,(CMwNod *)unaff_ESI);
              *(undefined4 *)(pSVar7 + 8) = 1;
            }
          }
        }
        else {
          unaff_EBP = (CMwCmdBufferCore *)0x417af1;
          pSVar8 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (pCVar1,pCVar10,(ulong)in_stack_ffffffe0);
          *(undefined4 *)pSVar7 = *(undefined4 *)pSVar8;
        }
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < local_14);
    }
    pCVar1 = this + 0x34;
    pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                        (ulong)unaff_ESI);
    *(undefined4 *)pSVar7 = *in_stack_00000010;
    (**(code **)(*(int *)*in_stack_00000010 + 0x34))();
    if (*(int *)(this + 8) == 0) {
      pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                CFastBuffer<class_CCrystalFace*>::GetCount
                          (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
      pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      if (pCVar10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        do {
          pSVar7 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                             (pCVar1,pCVar11,(ulong)unaff_EBX);
          if (*(int *)(pSVar7 + 8) != 0) {
            unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x417b79;
            CMwNod::MwRelease(*(CMwNod **)pSVar7,(CMwNod *)0x417b79);
          }
          pCVar11 = pCVar11 + 1;
        } while (pCVar11 < pCVar10);
      }
    }
    pCVar3 = pCStack_8;
    pCVar6 = *(CClassicBufferMemory **)(this + 4);
    if (pCVar6 != pCStack_8) {
      if (pCVar6 == pCStack_10) {
        sBufferMemoryFree(&pCStack_10);
      }
      else if (pCVar6 != (CClassicBufferMemory *)0x0) {
        (*(code *)**(undefined4 **)pCVar6)();
      }
    }
    *(CClassicBufferMemory **)(this + 4) = pCVar3;
  }
  uStack0000000c = 0xffffffff;
  CSystemFid::SCallStackFidContext::~SCallStackFidContext
            (&uStack_4,(SCallStackFidContext *)unaff_EBX);
  ExceptionList = param_2;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadFile
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadFile
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CFastStringInt *param_2,
          CMwNod **param_3,CSystemFids *param_4,EArchive param_5)
{
{
  CSystemFidFile *pCVar1;
  int iVar2;
  CSystemFid *unaff_EBX;
  CMwNod **unaff_EBP;
  CMwNod **unaff_ESI;
  int *unaff_EDI;
  undefined4 local_4;
  
  local_4 = 0;
  pCVar1 = CSystemEngine::FindOrAddFidAt
                     (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_3,
                      (CSystemFids *)param_1,(CFastStringInt *)&local_4,unaff_EDI);
  *(CSystemFidFile **)(this + 0x50) = pCVar1;
  *(EArchive *)(this + 0x78) = param_5;
  if (((byte)pCVar1[0x18] & 4) != 0) {
    iVar2 = DoLoadResource(this,(CSystemArchiveNod *)(*(uint *)(pCVar1 + 0x7c) | 0x40000000),
                           (ulong)param_3,unaff_ESI);
    return iVar2;
  }
  iVar2 = DoFidLoadFile(this,(CSystemArchiveNod *)param_3,unaff_EBP);
  if ((iVar2 == 0) && (*param_3 = (CMwNod *)0x0, param_1 != (CSystemArchiveNod *)0x0)) {
    CSystemEngine::RemoveAndDeleteFid
              (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)pCVar1,unaff_EBX);
    *(undefined4 *)(this + 0x50) = 0;
  }
  return iVar2;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadFromFid
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadFromFid
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod **param_2)
{
{
  CSystemFid *this_00;
  int *piVar1;
  CSystemArchiveNod *pCVar2;
  int iVar3;
  CSystemFid *pCVar4;
  int iVar5;
  ulong uVar6;
  CMwNod *pCVar7;
  undefined4 uVar8;
  CPlugFile *pCVar9;
  CSystemArchiveNod *pCVar10;
  SCasterCat *pSVar11;
  int extraout_EAX;
  CSystemFid *unaff_EBX;
  CSystemFid *unaff_ESI;
  CSystemFid *unaff_EDI;
  CMwNod *pCVar12;
  CSystemArchiveNod *in_stack_ffffffd0;
  SCallStackFidContext *in_stack_ffffffd4;
  int iStack_18;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_00a80f28;
  pvStack_10 = ExceptionList;
  ExceptionList = &pvStack_10;
  this_00 = *(CSystemFid **)(this + 0x50);
  pCVar4 = CSystemFid::ParametrizedGetLoadableFid
                     (this_00,(CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xfffffffc));
  iVar5 = DoFindNod(this,param_1,*(CMwNod ***)(this + 0x50),unaff_EDI);
  if (iVar5 != 0) {
    ExceptionList = pvStack_10;
    return 1;
  }
  CSystemFid::SCallStackFidContext::SCallStackFidContext
            (&stack0xffffffd0,*(SCallStackFidContext **)(this + 0x50),unaff_ESI);
  uStack_8 = 0;
  iVar5 = CSystemFileName::IsExtensionGbx((CFastStringInt *)(pCVar4 + 0x74));
  if (iVar5 == 0) {
    iVar5 = CSystemFileName::IsExtension((CFastStringInt *)(pCVar4 + 0x74),".xml");
    if (iVar5 != 0) {
      uVar6 = CSystemFid::GetClassId(*(CSystemFid **)(this + 0x50),unaff_EBX);
      iVar5 = CMwNod::StaticMwIsKindOf(uVar6,0x9020000);
      if (iVar5 == 0) {
        pCVar7 = CSystemXmlTools::XmlToNod(*(CSystemFid **)(this + 0x50));
        *(CMwNod **)param_1 = pCVar7;
        if (pCVar7 != (CMwNod *)0x0) {
          iVar5 = (**(code **)(*(int *)pCVar7 + 0x10))();
          if (iVar5 != 0) {
            piVar1 = *(int **)param_1;
            uVar8 = (**(code **)(*piVar1 + 0x78))();
            *(undefined4 *)param_1 = uVar8;
            (**(code **)(*piVar1 + 4))();
          }
          if (*(CSystemFid **)param_1 != (CSystemFid *)0x0) {
            ParametrizedFindOrAddFid
                      (this,(CSystemArchiveNod *)this_00,*(CSystemFid **)param_1,
                       (CMwNod *)in_stack_ffffffd0);
            in_stack_ffffffd0 = *(CSystemArchiveNod **)param_1;
            ParametrizedFinalization(this,in_stack_ffffffd0,(CMwNod *)in_stack_ffffffd4);
          }
        }
        iVar5 = *(int *)param_1;
        uStack_8 = 0xffffffff;
        CSystemFid::SCallStackFidContext::~SCallStackFidContext
                  (&stack0xffffffd0,(SCallStackFidContext *)in_stack_ffffffd0);
        ExceptionList = pvStack_10;
        return (uint)(iVar5 != 0);
      }
    }
    pCVar9 = CPlugFile::CreateFromFid((CSystemFidFile *)this_00);
    *(CPlugFile **)param_1 = pCVar9;
    if (pCVar9 != (CPlugFile *)0x0) {
      ParametrizedFindOrAddFid
                (this,(CSystemArchiveNod *)this_00,(CSystemFid *)pCVar9,(CMwNod *)in_stack_ffffffd0)
      ;
      pCVar4 = this_00;
      iStack_18 = (**(code **)(**(int **)param_1 + 0x84))();
      ParametrizedFinalization(this,*(CSystemArchiveNod **)param_1,(CMwNod *)pCVar4);
      if (iStack_18 == 0) {
        pCVar2 = *(CSystemArchiveNod **)param_1;
        pCVar10 = (CSystemArchiveNod *)(**(code **)(*(int *)pCVar2 + 0x7c))();
        if (pCVar10 != (CSystemArchiveNod *)0x0) {
          if (pCVar2 != pCVar10) {
            pCVar12 = (CMwNod *)0x1;
            pCVar7 = (CMwNod *)0x41a68f;
            (**(code **)(*(int *)pCVar2 + 4))();
            ParametrizedFindOrAddFid(this,(CSystemArchiveNod *)this_00,(CSystemFid *)pCVar10,pCVar7)
            ;
            ParametrizedFinalization(this,pCVar10,pCVar12);
          }
          *(CSystemArchiveNod **)param_1 = pCVar10;
          iStack_18 = 1;
        }
      }
      uStack_8 = 0xffffffff;
      CSystemFid::SCallStackFidContext::~SCallStackFidContext(&stack0xffffffd0,in_stack_ffffffd4);
      ExceptionList = pvStack_10;
      return iStack_18;
    }
  }
  else {
    iVar5 = (**(code **)**(undefined4 **)(this_00 + 0x6c))();
    *(int *)(this + 4) = iVar5;
    if (iVar5 != 0) {
      pSVar11 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          ((void *)(DAT_00d73300 + 0x20),
                           (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                           (ulong)in_stack_ffffffd0);
      iVar5 = *(int *)pSVar11;
      if ((((DAT_00d72e8c == (code *)0x0) && (*(int *)(this + 0x50) != 0)) &&
          (iVar3 = *(int *)(*(int *)(this + 0x50) + 0x14), iVar3 != 0)) &&
         (((iVar3 = *(int *)(iVar3 + 0x18), iVar3 != 0 && (iVar5 != 0)) &&
          ((iVar3 == *(int *)(iVar5 + 0x28) || (iVar3 == *(int *)(iVar5 + 0x30))))))) {
        DAT_00d72e8c = CCorruptedLoadFromFidException::Throw;
      }
      uStack_8 = CONCAT31(uStack_8._1_3_,1);
      DoLoadAll(this,param_1,(CMwNod **)in_stack_ffffffd4);
      uStack_8 = 0;
      FUN_0041a7ae();
      return extraout_EAX;
    }
    *(undefined4 *)param_1 = 0;
  }
  uStack_8 = 0xffffffff;
  CSystemFid::SCallStackFidContext::~SCallStackFidContext
            (&stack0xffffffd0,(SCallStackFidContext *)in_stack_ffffffd0);
  ExceptionList = pvStack_10;
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadHeader
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall CSystemArchiveNod::DoLoadHeader(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  int iVar1;
  ulong unaff_EBX;
  ulong unaff_ESI;
  void *in_stack_0000000c;
  undefined4 uStack00000010;
  char *in_stack_fffffe18;
  SHeaderCommunity *in_stack_fffffe1c;
  SHeaderCommunity *pSVar2;
  SStringParam *in_stack_fffffe24;
  SHeaderCommunity *pSVar3;
  SCallStackFidContext *in_stack_fffffe28;
  SStringParam *pSVar4;
  char *in_stack_fffffe30;
  SStringParam *pSVar5;
  char *pcVar6;
  SStringParam *in_stack_fffffe3c;
  char *in_stack_fffffe40;
  SStringParam *in_stack_fffffe44;
  char *in_stack_fffffe48;
  SStringParam *in_stack_fffffe4c;
  char *in_stack_fffffe50;
  SStringParam *in_stack_fffffe54;
  char *in_stack_fffffe58;
  SStringParam *in_stack_fffffe5c;
  char *in_stack_fffffe60;
  SStringParam *in_stack_fffffe64;
  CFastString local_198 [8];
  CFastString local_190 [4];
  undefined1 local_18c [4];
  CFastStringInt local_188 [4];
  undefined1 local_184 [4];
  CFastStringInt local_180 [12];
  undefined1 local_174 [4];
  CFastStringInt local_170 [4];
  undefined1 local_16c [4];
  CFastStringInt local_168 [12];
  undefined1 local_15c [4];
  CFastStringInt local_158 [4];
  undefined1 local_154 [4];
  CFastStringInt local_150 [4];
  undefined1 local_14c [4];
  CFastStringInt local_148 [12];
  undefined1 local_13c [4];
  CFastStringInt local_138 [12];
  undefined1 local_12c [4];
  CFastStringInt local_128 [4];
  undefined1 local_124 [4];
  CFastStringInt local_120 [20];
  undefined1 local_10c [4];
  CFastStringInt local_108 [4];
  undefined1 local_104 [4];
  CFastStringInt local_100 [12];
  undefined1 local_f4 [4];
  CFastStringInt local_f0 [20];
  undefined1 local_dc [4];
  CFastStringInt local_d8 [20];
  char local_c4 [168];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a80cb7;
  local_14 = ExceptionList;
  local_1c = DAT_00cca150 ^ (uint)&stack0xfffffe18;
  ExceptionList = &local_14;
  CSystemFid::SCallStackFidContext::SCallStackFidContext
            (&stack0xfffffe38,*(SCallStackFidContext **)(this + 0x50),
             (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xfffffe10));
  local_8 = 0;
  CClassicArchive::ReadData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xfffffe2c,(void *)0x3,unaff_ESI);
  if (((SUB41(in_stack_fffffe30,0) != (CFastString)0x47) ||
      ((char)((uint)in_stack_fffffe30 >> 8) != 'B')) ||
     ((char)((uint)in_stack_fffffe30 >> 0x10) != 'X')) {
    if ((*(int **)(this + 0x50) == (int *)0x0) ||
       (iVar1 = (**(code **)(**(int **)(this + 0x50) + 0x10))(), iVar1 == 0)) {
      CFastStringInt::SetString
                (&stack0xfffffe44,(CFastStringInt *)&stack0xfffffe58,in_stack_fffffe24);
    }
    else {
      CSystemFidFile::GetFullName
                (*(CSystemFidFile **)(this + 0x50),(CPlugFile *)&stack0xfffffe44,
                 (CFastStringInt *)0x0);
    }
    if (in_stack_fffffe4c != (SStringParam *)PTR_DAT_00bbf7dc) {
      if (((byte)in_stack_fffffe4c[-1] & 0x80) == 0) {
        in_stack_fffffe4c = in_stack_fffffe4c + -2;
      }
      else {
        in_stack_fffffe4c = in_stack_fffffe4c + -4;
      }
      operator_delete__(in_stack_fffffe4c);
    }
    goto LAB_00418953;
  }
  pSVar5 = (SStringParam *)0x0;
  pSVar2 = (SHeaderCommunity *)0x0;
  in_stack_fffffe28 = (SCallStackFidContext *)0x0;
  pSVar3 = (SHeaderCommunity *)PTR_DAT_00bbf7d8;
  pSVar4 = (SStringParam *)PTR_DAT_00bbf7d8;
  pcVar6 = PTR_DAT_00bbf7d8;
  CClassicArchive::ReadData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xfffffe3c,(void *)0x2,unaff_EBX);
  *(short *)(this + 0x18) = (short)in_stack_fffffe40;
  switch((CSystemArchiveNod *)((uint)in_stack_fffffe40 & 0xffff)) {
  case (CSystemArchiveNod *)0x1:
    SStringParam::SStringParam(&stack0xfffffe4c,(SStringParam *)&DAT_00b2da28,in_stack_fffffe18);
    CFastString::SetString
              ((CFastString *)&stack0xfffffe28,(CFastStringInt *)&stack0xfffffe50,
               (SStringParam *)in_stack_fffffe1c);
    SStringParam::SStringParam(local_124,(SStringParam *)&DAT_00b2d0d4,(char *)pSVar2);
    in_stack_fffffe1c = (SHeaderCommunity *)0x4185fa;
    CFastString::Concat((CFastString *)&stack0xfffffe30,local_120,(SStringParam *)pSVar3);
    pSVar2 = (SHeaderCommunity *)0x418608;
    SStringParam::SStringParam(local_18c,(SStringParam *)&DAT_00b2e414,(char *)in_stack_fffffe28);
    pSVar3 = (SHeaderCommunity *)0x418616;
    CFastString::Concat((CFastString *)&stack0xfffffe38,local_188,pSVar4);
    in_stack_fffffe28 = (SCallStackFidContext *)0x418627;
    SStringParam::SStringParam(local_104,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe30);
    CFastString::Concat((CFastString *)&stack0xfffffe40,local_100,pSVar5);
    SStringParam::SStringParam(local_16c,(SStringParam *)&DAT_00b2e40c,pcVar6);
    CFastString::Concat((CFastString *)&stack0xfffffe48,local_168,in_stack_fffffe3c);
    SStringParam::SStringParam(local_124,(SStringParam *)"August",in_stack_fffffe40);
    CFastString::SetString((CFastString *)&stack0xfffffe58,local_120,in_stack_fffffe44);
    SStringParam::SStringParam(local_14c,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe48);
    CFastString::Concat((CFastString *)&stack0xfffffe60,local_148,in_stack_fffffe4c);
    SStringParam::SStringParam(local_174,(SStringParam *)&DAT_00b2e408,in_stack_fffffe50);
    CFastString::Concat(local_198,local_170,in_stack_fffffe54);
    SStringParam::SStringParam(local_12c,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe58);
    CFastString::Concat(local_190,local_128,in_stack_fffffe5c);
    SStringParam::SStringParam(local_f4,(SStringParam *)&DAT_00b2e40c,in_stack_fffffe60);
    CFastString::Concat((CFastString *)local_188,local_f0,in_stack_fffffe64);
    break;
  case (CSystemArchiveNod *)0x2:
    SStringParam::SStringParam(local_15c,(SStringParam *)"August",in_stack_fffffe18);
    CFastString::SetString
              ((CFastString *)&stack0xfffffe28,local_158,(SStringParam *)in_stack_fffffe1c);
    SStringParam::SStringParam(&stack0xfffffe64,(SStringParam *)&DAT_00b2d0d4,(char *)pSVar2);
    in_stack_fffffe1c = (SHeaderCommunity *)0x41876c;
    CFastString::Concat((CFastString *)&stack0xfffffe30,(CFastStringInt *)local_198,
                        (SStringParam *)pSVar3);
    pSVar2 = (SHeaderCommunity *)0x41877a;
    SStringParam::SStringParam(local_184,(SStringParam *)&DAT_00b2e408,(char *)in_stack_fffffe28);
    pSVar3 = (SHeaderCommunity *)0x418788;
    CFastString::Concat((CFastString *)&stack0xfffffe38,local_180,pSVar4);
    in_stack_fffffe28 = (SCallStackFidContext *)0x418796;
    SStringParam::SStringParam(local_16c,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe30);
    CFastString::Concat((CFastString *)&stack0xfffffe40,local_168,pSVar5);
    SStringParam::SStringParam(local_154,(SStringParam *)&DAT_00b2e40c,pcVar6);
    CFastString::Concat((CFastString *)&stack0xfffffe48,local_150,in_stack_fffffe3c);
    SStringParam::SStringParam(local_13c,(SStringParam *)"August",in_stack_fffffe40);
    CFastString::SetString((CFastString *)&stack0xfffffe58,local_138,in_stack_fffffe44);
    SStringParam::SStringParam(local_124,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe48);
    CFastString::Concat((CFastString *)&stack0xfffffe60,local_120,in_stack_fffffe4c);
    SStringParam::SStringParam(local_10c,(SStringParam *)&DAT_00b2e3bc,in_stack_fffffe50);
    CFastString::Concat(local_198,local_108,in_stack_fffffe54);
    SStringParam::SStringParam(local_f4,(SStringParam *)&DAT_00b2d0d4,in_stack_fffffe58);
    CFastString::Concat(local_190,local_f0,in_stack_fffffe5c);
    SStringParam::SStringParam(local_dc,(SStringParam *)&DAT_00b2e40c,in_stack_fffffe60);
    CFastString::Concat((CFastString *)local_188,local_d8,in_stack_fffffe64);
    break;
  case (CSystemArchiveNod *)0x3:
  case (CSystemArchiveNod *)0x4:
  case (CSystemArchiveNod *)0x5:
  case (CSystemArchiveNod *)0x6:
    iVar1 = LoadCurrentHeader(this,(CSystemArchiveNod *)((uint)in_stack_fffffe40 & 0xffff),
                              (EVersion)in_stack_fffffe18);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe30,in_stack_fffffe1c);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe2c,pSVar2);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe44,pSVar3);
    uStack00000010 = 0xffffffff;
    CSystemFid::SCallStackFidContext::~SCallStackFidContext(&stack0xfffffe54,in_stack_fffffe28);
    ExceptionList = in_stack_0000000c;
    return iVar1;
  default:
    goto switchD_004185b5_default;
  }
  sprintf_s<256>(local_c4,"Wrong .Gbx format : request a GameBox version between the %s and the %s")
  ;
switchD_004185b5_default:
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe30,in_stack_fffffe1c);
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe2c,pSVar2);
  CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&stack0xfffffe44,pSVar3);
LAB_00418953:
  uStack00000010 = 0xffffffff;
  CSystemFid::SCallStackFidContext::~SCallStackFidContext(&stack0xfffffe54,in_stack_fffffe28);
  ExceptionList = in_stack_0000000c;
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadMemory
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadMemory
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2,
          CMwNod **param_3)
{
{
  CSystemFid *pCVar1;
  CSystemFidMemory *pCVar2;
  int iVar3;
  CFastStringInt *unaff_ESI;
  CSystemEngine *unaff_EDI;
  void *in_stack_00000010;
  undefined4 uStack00000014;
  CSystemArchiveNod *in_stack_0000001c;
  int in_stack_ffffff78;
  EFindWay in_stack_ffffff7c;
  CSystemManagerFile *in_stack_ffffff80;
  CSystemFidMemory *in_stack_ffffff84;
  CSystemManagerFile local_70 [4];
  CSystemFids *local_6c;
  CMwNod **local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80f5b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFidMemory::CSystemFidMemory
            ((CSystemFidMemory *)&stack0xffffff78,
             (CSystemFidMemory *)(DAT_00cca150 ^ (uint)&stack0xffffff70));
  local_6c = CSystemEngine::GetLocationBuffer(*(CSystemEngine **)(this + 0x1c),unaff_EDI);
  local_c = param_3;
  pCVar1 = CSystemEngine::FindFid
                     (*(CSystemEngine **)(this + 0x1c),(CSystemFids *)&stack0xffffff80,unaff_ESI,
                      in_stack_ffffff78,in_stack_ffffff7c);
  if (pCVar1 == (CSystemFid *)0x0) {
    pCVar2 = CSystemManagerFile::CreateFidMemory
                       (*(CSystemManagerFile **)(*(int *)(this + 0x1c) + 0x20),in_stack_ffffff80);
    in_stack_ffffff80 = local_70;
    (**(code **)(*(int *)pCVar2 + 0x7c))();
    *(CSystemFidMemory **)(this + 0x50) = pCVar2;
  }
  else {
    *(CSystemFid **)(this + 0x50) = pCVar1;
  }
  iVar3 = DoFidLoadMemory(this,in_stack_0000001c,(CMwNod **)in_stack_ffffff80);
  uStack00000014 = 0xffffffff;
  CSystemFidMemory::~CSystemFidMemory((CSystemFidMemory *)local_70,in_stack_ffffff84);
  ExceptionList = in_stack_00000010;
  return iVar3;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadMemoryTemp
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadMemoryTemp
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2,
          CMwNod **param_3)
{
{
  CSystemEngine *pCVar1;
  int iVar2;
  CSystemFid *unaff_EBX;
  int unaff_EBP;
  CMwNod **unaff_ESI;
  CMwNod *pCVar3;
  CSystemFid *unaff_EDI;
  undefined4 *in_stack_00000014;
  undefined4 *in_stack_00000018;
  
  pCVar1 = *(CSystemEngine **)param_2;
  pCVar3 = (CMwNod *)0x0;
  if ((pCVar1 != (CSystemEngine *)0x0) &&
     (pCVar3 = *(CMwNod **)(pCVar1 + 8), pCVar3 != (CMwNod *)0x0)) {
    CSystemEngine::UnbindFidNod(*(CSystemEngine **)(this + 0x1c),pCVar1,pCVar3,unaff_EDI);
  }
  iVar2 = DoLoadMemory(this,(CSystemArchiveNod *)param_2,(CClassicBufferMemory *)&stack0x00000000,
                       unaff_ESI);
  CSystemEngine::DetachBuffer(*(CSystemEngine **)(this + 0x1c),(CClassicArchive *)param_2,unaff_EBP)
  ;
  if (pCVar3 != (CMwNod *)0x0) {
    CSystemEngine::BindFidNod
              (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_2,pCVar3,unaff_EBX);
    *in_stack_00000018 = param_2;
    return iVar2;
  }
  *in_stack_00000014 = param_2;
  return iVar2;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadRef
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall CSystemArchiveNod::DoLoadRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  bool bVar1;
  CSystemFidParameters *pCVar2;
  SCasterCat *pSVar3;
  CSystemFids *this_00;
  CSystemFids *extraout_EAX;
  int iVar4;
  CSystemFidsFolder *pCVar5;
  SNewTriangleVert *pSVar6;
  CSystemFid *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CSystemFidFile *this_01;
  CSystemArchiveNod *pCVar9;
  undefined *puVar10;
  CFastBufferWheel<float> *pCVar11;
  CPlugMaterial *pCVar12;
  CSystemFidParameters *this_02;
  CSystemFidParameters *extraout_ECX;
  CSystemFidParameters *extraout_ECX_00;
  CSystemFidParameters *extraout_ECX_01;
  int unaff_EBX;
  CSystemFids *pCVar13;
  CSystemFidsDrive *unaff_ESI;
  CSystemFidFile *unaff_EDI;
  void *in_stack_00000034;
  ulong in_stack_fffffb6c;
  CSystemEngine *in_stack_fffffb70;
  GmVec3 *in_stack_fffffb78;
  CSystemFids *in_stack_fffffb7c;
  int in_stack_fffffb80;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffb84;
  ulong *puVar14;
  ulong in_stack_fffffb88;
  CPlugFile *pCVar15;
  CSystemFidFile *in_stack_fffffb8c;
  TiXmlAttribute *in_stack_fffffb90;
  CClassicArchive *pCVar16;
  SStringParam *pSVar17;
  int *piVar18;
  TiXmlAttribute *pTVar19;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *in_stack_fffffb94;
  CSystemFidFile *pCVar20;
  CSystemFid *pCVar21;
  CClassicArchive *in_stack_fffffb98;
  CSystemArchiveNod *pCVar22;
  CFastBuffer<class_CGamePlayerScore*> *in_stack_fffffb9c;
  CClassicArchive *in_stack_fffffba0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffba4;
  CSystemFidFile *pCStack_458;
  CSystemFidFile *local_454;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_450;
  CSystemFid *pCStack_44c;
  CSystemFidFile *pCStack_448;
  CPlugMaterial *pCStack_444;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_440;
  CSystemFidsFolder *pCStack_43c;
  CSystemFidsFolder *local_438;
  CFastBuffer<class_GxVertex2> *pCStack_434;
  CFastBuffer<struct_CCrystal::SSmoothingGroup> *local_430;
  CFastBufferWheel<float> *local_42c;
  CFastBufferWheel<float> *pCStack_428;
  undefined *puStack_424;
  undefined4 local_420;
  undefined *puStack_41c;
  int local_418;
  CPlugMaterial *local_414;
  undefined *puStack_410;
  CPlugMaterial *pCStack_40c;
  undefined *puStack_408;
  undefined *local_404;
  undefined *local_400;
  undefined *local_3fc;
  GmIso4 *local_3f8;
  CClassicArchive aCStack_3f4 [4];
  CSystemManagerFile *local_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3e8;
  undefined *puStack_3e4;
  undefined4 uStack_3dc;
  undefined *local_3d8;
  undefined4 uStack_3d4;
  undefined *puStack_3d0;
  undefined4 uStack_3cc;
  undefined *local_3c8 [2];
  undefined *puStack_3c0;
  undefined4 uStack_3bc;
  undefined *puStack_3b4;
  undefined **local_3b0;
  undefined1 auStack_3ac [8];
  CSystemFidsDrive aCStack_3a4 [16];
  CSystemFidFile local_394 [20];
  undefined1 local_380 [20];
  undefined **local_36c;
  CSystemFidFile aCStack_358 [132];
  CSystemArchiveNod aCStack_2d4 [4];
  CSystemArchiveNod aCStack_2d0 [4];
  CSystemArchiveNod aCStack_2cc [76];
  CSystemFidFile *pCStack_280;
  undefined4 uStack_258;
  char acStack_1ec [464];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00a80e24;
  local_14 = ExceptionList;
  local_1c = DAT_00cca150 ^ (uint)&stack0xfffffb6c;
  ExceptionList = &local_14;
  pCVar9 = this;
  CSystemFid::SCallStackFidContext::SCallStackFidContext
            (&local_3f0,*(SCallStackFidContext **)(this + 0x50),
             (CSystemFid *)(DAT_00cca150 ^ (uint)&stack0xfffffb60));
  local_8 = 0;
  CSystemFidFile::CSystemFidFile(local_394,unaff_EDI);
  CSystemFidsDrive::CSystemFidsDrive((CSystemFidsDrive *)&local_3d8,unaff_ESI);
  pCVar2 = CSystemFidParameters::GetCurrentParameters();
  local_414 = CSystemFid::GetNod(*(CSystemFid **)(this + 0x50),
                                 (CSysFidNodRef<class_CPlugMaterial> *)pCVar2);
  CClassicArchive::ReadNatural
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xfffffb9c,(ulong *)0x1,0,unaff_EBX);
  if (in_stack_fffffba0 == (CClassicArchive *)0x0) goto LAB_00419bcc;
  local_420 = 0;
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(DAT_00d73300 + 0x20),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000b,
                      in_stack_fffffb6c);
  this_00 = CSystemEngine::GetLocationData(*(CSystemEngine **)pSVar3,in_stack_fffffb70);
  iVar4 = *(int *)(this + 0x50);
  if (*(int *)(iVar4 + 0x18) == 8) {
    if (this_00 == (CSystemFids *)0x0) goto LAB_004191f3;
    *(CSystemFids **)(iVar4 + 0x14) = this_00;
  }
  else if (this_00 == (CSystemFids *)0x0) {
LAB_004191f3:
    local_3b0 = local_3c8;
    *(undefined1 **)(this + 0x50) = local_380;
    local_418 = iVar4;
    local_36c = local_3b0;
  }
  CClassicArchive::ReadNatural
            ((CClassicArchive *)this,(CClassicArchive *)&local_3fc,(ulong *)0x1,0,(int)pCVar9);
  CSystemFids::GetUp(*(CSystemFids **)(*(int *)(this + 0x50) + 0x14),local_3f8,in_stack_fffffb78);
  if ((extraout_EAX == (CSystemFids *)0x0) ||
     (((pCVar13 = extraout_EAX, (*(uint *)(*(int *)(this + 0x50) + 0x18) & 1) != 0 &&
       (pCVar13 = extraout_EAX, (*(uint *)(*(int *)(this + 0x50) + 0x18) & 4) == 0)) &&
      (iVar4 = CSystemFids::IsOneBaseOf(this_00,extraout_EAX,in_stack_fffffb7c),
      pCVar13 = extraout_EAX, iVar4 == 0)))) {
    pCVar13 = this_00;
  }
  CClassicArchive::ReadNatural
            (in_stack_fffffb98,(CClassicArchive *)&local_438,(ulong *)0x1,0,in_stack_fffffb80);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&local_404,in_stack_fffffb84);
  CFastBuffer<int>::SetSizeAtLeast(&local_400,local_430,in_stack_fffffb88);
  pCVar2 = (CSystemFidParameters *)0x0;
  if (local_42c != (CFastBufferWheel<float> *)0x0) {
    do {
      pCVar5 = CSystemManagerFile::CreateFidsFolder
                         (*(CSystemManagerFile **)(*(int *)(in_stack_fffffba4 + 0x1c) + 0x20),
                          (CSystemManagerFile *)in_stack_fffffb8c);
      local_438 = pCVar5;
      CFastBuffer<class_CDx9TextureKeeper*>::Add
                (&local_3f8,(TiXmlAttributeSet *)&local_438,in_stack_fffffb90);
      in_stack_fffffb90 = *(TiXmlAttribute **)(*(int *)(local_454 + 0x1c) + 0x20);
      in_stack_fffffb8c = local_454;
      (**(code **)(*(int *)pCVar5 + 0x84))();
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < local_42c);
  }
  pCVar15 = (CPlugFile *)&local_3fc;
  pCVar9 = (CSystemArchiveNod *)in_stack_fffffba4;
  InsertExternalLocations
            ((CSystemArchiveNod *)in_stack_fffffba4,(CSystemArchiveNod *)pCVar13,
             (CSystemFids *)pCVar15,(CFastBuffer<class_CSystemFids*> *)in_stack_fffffb8c);
  CFastBuffer<struct_SInputActionDesc_const*>::ResetAndFreeMemory
            (&local_3f8,(CFastBuffer<struct_SInputActionDesc_const*> *)in_stack_fffffb90);
  if ((DAT_00d54220 != 0) && (*(int *)(*(int *)(in_stack_fffffba4 + 0x50) + 0x18) != 8)) {
    pSVar6 = CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>::GetLastElem
                       ((void *)(DAT_00d54220 + 4),in_stack_fffffb94);
    *(CFastBuffer<class_GxVertex2> **)pSVar6 = pCStack_434 + *(int *)pSVar6;
  }
  local_454 = (CSystemFidFile *)(in_stack_fffffba4 + 0x28);
  CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey>::AllocSetCount
            (local_454,pCStack_434,(ulong)in_stack_fffffb98);
  pCStack_43c = (CSystemFidsFolder *)0x0;
  if (local_430 != (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x0) {
LAB_00419342:
    pCVar20 = (CSystemFidFile *)0x1;
    pCVar16 = aCStack_3f4;
    iVar4 = 0x419352;
    CClassicArchive::ReadNatural
              ((CClassicArchive *)in_stack_fffffba4,pCVar16,(ulong *)0x1,0,(int)in_stack_fffffb9c);
    pCVar22 = (CSystemArchiveNod *)0x419362;
    pCVar7 = CSystemManagerFile::CreateFidFromType
                       (*(CSystemManagerFile **)(*(int *)(in_stack_fffffba4 + 0x1c) + 0x20),
                        local_3f0,(EFidType)in_stack_fffffba0);
    *(undefined4 *)(pCVar7 + 0x18) = uStack_3ec;
    in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)0x41937c;
    in_stack_fffffba0 = (CClassicArchive *)in_stack_fffffba4;
    local_42c = (CFastBufferWheel<float> *)pCVar7;
    (**(code **)(*(int *)pCVar7 + 0x80))();
    pCVar8 = pCStack_450;
    puVar14 = (ulong *)0x0;
    pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                       (in_stack_fffffb9c,pCStack_450,1);
    CClassicArchive::ReadNatural
              ((CClassicArchive *)in_stack_fffffba4,(CClassicArchive *)(pSVar3 + 8),puVar14,
               (ulong)pCVar15,iVar4);
    pCStack_444 = (CPlugMaterial *)0x1;
    if (*(ushort *)(in_stack_fffffba4 + 0x18) < 5) {
      pCVar15 = (CPlugFile *)0x4193ed;
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (pCVar9,pCVar8,(ulong)pCVar16);
      *(undefined4 *)(pSVar3 + 0x10) = 0;
    }
    else {
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (pCVar9,pCVar8,1);
      pCVar15 = (CPlugFile *)0x4193bf;
      CClassicArchive::ReadBool
                ((CClassicArchive *)in_stack_fffffba4,(CClassicArchive *)(pSVar3 + 0x10),
                 (int *)pCVar16,(ulong)pCVar20);
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (local_454,pCVar8,(ulong)pCVar22);
      local_438 = (CSystemFidsFolder *)(uint)(*(int *)(pSVar3 + 0x10) == 0);
      pCVar20 = (CSystemFidFile *)pCVar8;
    }
    if (((byte)pCVar7[0x18] & 4) == 0) {
      pCVar15 = (CPlugFile *)&pCStack_434;
      CClassicArchive::ReadNatural
                ((CClassicArchive *)in_stack_fffffba4,(CClassicArchive *)pCVar15,(ulong *)0x1,0,
                 (int)pCVar20);
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (local_454,pCStack_440,(ulong)pCVar22);
      *(CFastBufferWheel<float> **)(pSVar3 + 0xc) = local_42c;
      pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         ((CClassicArchive *)(in_stack_fffffba4 + 0x20),
                          (CFastBuffer<class_CCrystalFace*> *)in_stack_fffffb9c);
      if (pCVar8 < pCStack_428) {
        *(CFastBufferWheel<float> **)(pCVar7 + 0x14) = pCStack_428;
        pCVar22 = (CSystemArchiveNod *)0x41943d;
        in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)pCVar7;
        pCVar20 = CSystemEngine::FindFidFile
                            (*(CSystemEngine **)(in_stack_fffffba4 + 0x1c),(CSystemEngine *)pCVar7,
                             (CSystemFidFile *)in_stack_fffffba0);
      }
      else {
        pCVar22 = (CSystemArchiveNod *)0x419447;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((CClassicArchive *)(in_stack_fffffba4 + 0x20),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_428,
                            (ulong)in_stack_fffffba0);
        *(undefined4 *)(pCVar7 + 0x14) = *(undefined4 *)pSVar3;
        in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)0x419455;
        in_stack_fffffba0 = (CClassicArchive *)pCVar7;
        pCVar20 = CSystemEngine::FindFidFile
                            (*(CSystemEngine **)(in_stack_fffffba4 + 0x1c),(CSystemEngine *)pCVar7,
                             (CSystemFidFile *)pCVar9);
      }
    }
    else {
      pCVar20 = (CSystemFidFile *)
                CSystemEngine::FindFidResource
                          (*(CSystemEngine **)(in_stack_fffffba4 + 0x1c),(CSystemEngine *)pCVar7,
                           pCVar20);
    }
    pCStack_458 = pCVar20;
    if (pCVar20 == (CSystemFidFile *)0x0) {
      pCStack_44c = (CSystemFid *)0x0;
      pCVar15 = (CPlugFile *)0x419483;
      pCVar20 = CSystemEngine::FindOrAddFidAt
                          (*(CSystemEngine **)(in_stack_fffffba4 + 0x1c),
                           *(CSystemEngine **)(pCVar7 + 0x14),(CSystemFids *)(pCVar7 + 0x74),
                           (CFastStringInt *)&pCStack_44c,(int *)pCVar22);
      local_454 = pCVar20;
    }
    local_42c = (CFastBufferWheel<float> *)0x0;
    this_01 = (CSystemFidFile *)0x0;
    if (pCVar20 != (CSystemFidFile *)0x0) {
      pCVar2 = CSystemFidParameters::GetCurrentParameters();
      pCVar7 = CSystemFid::ParametrizedGetFid
                         ((CSystemFid *)pCStack_458,(CSystemFid *)pCVar2,
                          (CSystemFidParameters *)pCVar22);
      this_01 = local_454;
      if (pCVar7 != (CSystemFid *)0x0) {
        pCStack_428 = (CFastBufferWheel<float> *)(pCVar7 + 0x34);
        pCVar22 = (CSystemArchiveNod *)0x0;
        CSystemFidParameters::Push(this_02,pCStack_428,(float *)0x0);
        this_01 = (CSystemFidFile *)pCVar7;
        pCStack_44c = pCVar7;
      }
    }
    pCStack_448 = this_01;
    if ((this_01 != (CSystemFidFile *)0x0) && (*(int *)(in_stack_fffffba4 + 0x5c) != 0)) {
      pCVar2 = CSystemFidParameters::GetCurrentParameters();
      pCVar15 = (CPlugFile *)&pCStack_448;
      CSystemFidParameters::Remap(pCVar2,(SIdRemapTable *)pCVar15,(CMwId *)&pCStack_458);
      this_01 = pCStack_458;
    }
    do {
      in_stack_fffffba4 = pCStack_450;
      if ((*(int *)(pCStack_450 + 0x5c) == 0) || (this_01 == (CSystemFidFile *)0x0)) {
        pCStack_44c = (CSystemFid *)0xffffffff;
LAB_00419603:
        pCVar7 = (CSystemFid *)this_01;
        pCVar5 = pCStack_43c;
        if (pCStack_43c == (CSystemFidsFolder *)0x0) goto LAB_00419554;
LAB_00419615:
        this_01 = (CSystemFidFile *)0x0;
        if (pCVar7 == (CSystemFid *)0x0) goto LAB_00419554;
        pCVar2 = CSystemFidParameters::GetCurrentParameters();
        pCStack_444 = CSystemFid::GetNod((CSystemFid *)pCStack_458,
                                         (CSysFidNodRef<class_CPlugMaterial> *)pCVar2);
        this_01 = pCStack_458;
      }
      else {
        pCStack_448 = (CSystemFidFile *)
                      CSystemFid::GetClassId((CSystemFid *)this_01,(CSystemFid *)pCVar22);
        pCVar5 = local_438;
        this_01 = local_454;
        if (pCStack_448 == (CSystemFidFile *)0xffffffff) goto LAB_00419603;
        pCVar7 = (CSystemFid *)local_454;
        if (local_438 != (CSystemFidsFolder *)0x0) goto LAB_00419615;
        pCStack_43c = (CSystemFidsFolder *)
                      CSystemFid::ParametrizedGetLoadableFid
                                ((CSystemFid *)local_454,(CSystemFid *)0x41953f);
        in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)&pCStack_43c;
        pCVar22 = (CSystemArchiveNod *)0x419550;
        CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                  ((CClassicArchive *)(in_stack_fffffba4 + 0x60),in_stack_fffffb9c,
                   (CGamePlayerScore **)in_stack_fffffba0);
        this_01 = (CSystemFidFile *)pCStack_44c;
LAB_00419554:
        pCStack_444 = (CPlugMaterial *)0x0;
      }
      if (((this_01 != (CSystemFidFile *)0x0) &&
          ((pCVar5 == (CSystemFidsFolder *)0x0 || (pCStack_444 != (CPlugMaterial *)0x0)))) ||
         (((byte)*(CClassicArchive *)(in_stack_fffffba4 + 0x78) & 4) == 0)) goto LAB_004198b1;
      pCVar7 = (CSystemFid *)this_01;
      if (this_01 == (CSystemFidFile *)0x0) {
        pCVar7 = (CSystemFid *)local_438;
      }
      pCStack_40c = (CPlugMaterial *)0x0;
      pCVar21 = pCStack_44c;
      CSystemFidParameters::PushForFid((CSystemFid *)this_01,(ulong)pCStack_44c);
      if (pCStack_43c == (CSystemFidsFolder *)0x0) {
LAB_0041963b:
        bVar1 = true;
      }
      else {
        CSystemArchiveNod(aCStack_2d4,pCVar22);
        pCVar22 = (CSystemArchiveNod *)&puStack_408;
        in_stack_00000034 = (void *)CONCAT31(in_stack_00000034._1_3_,4);
        uStack_258 = 7;
        pCVar21 = (CSystemFid *)0x4195d7;
        pCStack_280 = (CSystemFidFile *)pCVar7;
        iVar4 = DoLoadFromFid(aCStack_2d0,pCVar22,(CMwNod **)in_stack_fffffb9c);
        in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)0x4195ed;
        ~CSystemArchiveNod(aCStack_2cc,(CSystemArchiveNod *)in_stack_fffffba0);
        if (iVar4 == 0) goto LAB_0041963b;
        bVar1 = false;
      }
      pCVar15 = (CPlugFile *)0x41964f;
      CSystemFidParameters::PopForFid((CSystemFid *)pCVar9,(ulong)pCStack_450);
      if (!bVar1) goto LAB_0041987e;
      if ((pCStack_44c == (CSystemFid *)0x0) || (pCVar9 == (CSystemArchiveNod *)pCStack_44c))
      goto LAB_004197c8;
      pCStack_40c = (CPlugMaterial *)0x0;
      puStack_408 = PTR_DAT_00bbf7dc;
      local_404 = (undefined *)0x0;
      local_400 = PTR_DAT_00bbf7dc;
      pSVar17 = (SStringParam *)0xb00a000;
      iVar4 = (**(code **)(*(int *)pCVar9 + 0x10))();
      if (iVar4 == 0) {
        puStack_3b4 = &DAT_00b2e4f8;
        local_3b0 = (undefined **)0x3;
        pCVar15 = (CPlugFile *)0x4196d4;
        CFastStringInt::SetString((CPlugFile *)&puStack_410,(CFastStringInt *)&puStack_3b4,pSVar17);
      }
      else {
        pCVar15 = (CPlugFile *)0x0;
        CSystemFidFile::GetFullName
                  ((CSystemFidFile *)in_stack_fffffba0,(CPlugFile *)&puStack_410,
                   (CFastStringInt *)0x0);
      }
      iVar4 = (**(code **)(*(int *)pCStack_44c + 0x10))();
      if (iVar4 == 0) {
        puStack_3c0 = &DAT_00b2e4f8;
        uStack_3bc = 3;
        CFastStringInt::SetString(&local_404,(CFastStringInt *)&puStack_3c0,(SStringParam *)pCVar21)
        ;
        pCVar2 = extraout_ECX_00;
      }
      else {
        pCVar15 = (CPlugFile *)&local_404;
        CSystemFidFile::GetFullName((CSystemFidFile *)pCStack_44c,pCVar15,(CFastStringInt *)0x0);
        pCVar2 = extraout_ECX;
      }
      if (local_42c != (CFastBufferWheel<float> *)0x0) {
        CSystemFidParameters::Pop(pCVar2,(SCharStyle *)local_42c);
        pCVar2 = extraout_ECX_01;
      }
      pCVar20 = (CSystemFidFile *)0x0;
      if (pCStack_448 != (CSystemFidFile *)0x0) {
        local_42c = (CFastBufferWheel<float> *)(pCStack_448 + 0x34);
        CSystemFidParameters::Push(pCVar2,local_42c,(float *)0x0);
        pCVar20 = (CSystemFidFile *)pCStack_440;
      }
      pCStack_458 = pCVar20;
      if (local_3fc != PTR_DAT_00bbf7dc) {
        puVar10 = local_3fc + -4;
        if ((local_3fc[-1] & 0x80) == 0) {
          puVar10 = local_3fc + -2;
        }
        operator_delete__(puVar10);
        local_400 = (undefined *)0x0;
        local_3fc = PTR_DAT_00bbf7dc;
      }
      this_01 = pCStack_458;
      if (local_404 != PTR_DAT_00bbf7dc) {
        puVar10 = local_404 + -4;
        if ((local_404[-1] & 0x80) == 0) {
          puVar10 = local_404 + -2;
        }
        operator_delete__(puVar10);
        local_404 = PTR_DAT_00bbf7dc;
        puStack_408 = (undefined *)0x0;
        this_01 = pCStack_458;
      }
    } while( true );
  }
LAB_00419bac:
  if (local_3f0 != (CSystemManagerFile *)0x0) {
    *(CSystemManagerFile **)(in_stack_fffffba4 + 0x50) = local_3f0;
  }
  in_stack_00000034 = (void *)CONCAT31(in_stack_00000034._1_3_,2);
  in_stack_fffffb98 = (CClassicArchive *)0x419bc8;
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&uStack_3ec,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_fffffb9c);
  this = (CSystemArchiveNod *)pCStack_448;
LAB_00419bcc:
  pCVar20 = (CSystemFidFile *)0x419bd6;
  iVar4 = (**(code **)(**(int **)(this + 4) + 0x14))();
  *(int *)(this + 0xa0) = iVar4;
  CSystemFidsDrive::~CSystemFidsDrive(aCStack_3a4,(CSystemFidsDrive *)in_stack_fffffb98);
  CSystemFidFile::~CSystemFidFile(aCStack_358,pCVar20);
  CSystemFid::SCallStackFidContext::~SCallStackFidContext
            (auStack_3ac,(SCallStackFidContext *)in_stack_fffffba0);
  iVar4 = 1;
LAB_00419c20:
  in_stack_00000034 = (void *)((uint)in_stack_00000034 & 0xffffff00);
  ExceptionList = in_stack_00000034;
  return iVar4;
LAB_004197c8:
  bVar1 = false;
  switch(*(undefined4 *)(pCVar7 + 0x18)) {
  case 1:
  case 3:
  case 5:
  case 7:
    local_420 = 0;
    puStack_41c = PTR_DAT_00bbf7dc;
    piVar18 = (int *)0x0;
    pCVar15 = (CPlugFile *)&local_420;
    CSystemFidFile::GetFullName((CSystemFidFile *)pCVar7,pCVar15,(CFastStringInt *)0x0);
    if (pCStack_444 == (CPlugMaterial *)0x0) {
      pCVar15 = (CPlugFile *)0x41981b;
      iVar4 = CSystemManagerFile::IsFileExists((CFastStringInt *)&puStack_424);
      if (iVar4 != 0) {
        pCVar15 = (CPlugFile *)&puStack_424;
        pCVar9 = (CSystemArchiveNod *)
                 CSystemEngine::FindOrAddFidAt
                           (*(CSystemEngine **)(pCStack_458 + 0x1c),(CSystemEngine *)0x0,
                            (CSystemFids *)pCVar15,(CFastStringInt *)0x0,piVar18);
        bVar1 = true;
      }
    }
    if (puStack_41c != PTR_DAT_00bbf7dc) {
      if ((puStack_41c[-1] & 0x80) == 0) {
        puVar10 = puStack_41c + -2;
      }
      else {
        puVar10 = puStack_41c + -4;
      }
      operator_delete__(puVar10);
      local_420 = 0;
      puStack_41c = PTR_DAT_00bbf7dc;
    }
    if (bVar1) {
LAB_0041987e:
      pCVar7 = (CSystemFid *)pCVar9;
      if (puStack_410 != (undefined *)0x0) {
        pCVar7 = *(CSystemFid **)(puStack_410 + 8);
      }
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (pCStack_458,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCStack_444,
                          (ulong)pCVar21);
      *(CSystemFid **)pSVar3 = pCVar7;
      pCStack_444 = pCStack_40c;
      this_01 = pCStack_458;
      in_stack_fffffba4 = pCStack_450;
LAB_004198b1:
      pCVar12 = pCStack_444;
      if (local_42c != (CFastBufferWheel<float> *)0x0) {
        CSystemFidParameters::Pop((CSystemFidParameters *)local_42c,(SCharStyle *)local_42c);
        this_01 = local_454;
      }
      pCVar8 = pCStack_440;
      if (this_01 == (CSystemFidFile *)0x0) {
        if (((byte)*(CClassicArchive *)(in_stack_fffffba4 + 0x78) & 4) == 0) {
          local_414 = (CPlugMaterial *)0x0;
          puStack_410 = PTR_DAT_00bbf7dc;
          pCStack_428 = (CFastBufferWheel<float> *)0x0;
          puStack_424 = PTR_DAT_00bbf7dc;
          CSystemFidFile::GetFullName
                    (*(CSystemFidFile **)(in_stack_fffffba4 + 0x50),(CPlugFile *)&local_414,
                     (CFastStringInt *)0x0);
          pTVar19 = (TiXmlAttribute *)0x0;
          CSystemFidFile::GetFullName
                    ((CSystemFidFile *)pCStack_43c,(CPlugFile *)&local_42c,(CFastStringInt *)0x0);
          iVar4 = CSystemManagerFile::IsFileExists((CFastStringInt *)&local_430);
          if (iVar4 == 0) {
            CFastStringInt::GetLatin1(&local_430,(CFastStringInt *)&uStack_3dc);
            CFastStringInt::GetLatin1(&puStack_41c,(CFastStringInt *)&uStack_3e8);
            sprintf_s<512>(acStack_1ec,"Ref error : %s reference unexisting file %s");
            if (puStack_3e4 != PTR_DAT_00bbf7d8) {
              puVar10 = puStack_3e4 + -1;
              if ((puStack_3e4[-1] & 0x80) != 0) {
                puVar10 = puStack_3e4 + -4;
              }
              operator_delete__(puVar10);
              uStack_3e8 = 0;
              puStack_3e4 = PTR_DAT_00bbf7d8;
            }
            if (local_3d8 != PTR_DAT_00bbf7d8) {
              puVar10 = local_3d8 + -1;
              if ((local_3d8[-1] & 0x80) != 0) {
                puVar10 = local_3d8 + -4;
              }
              operator_delete__(puVar10);
              uStack_3dc = 0;
              local_3d8 = PTR_DAT_00bbf7d8;
            }
          }
          else {
            CFastStringInt::GetLatin1(&local_430,(CFastStringInt *)&uStack_3d4);
            CFastStringInt::GetLatin1(&puStack_41c,(CFastStringInt *)&uStack_3cc);
            sprintf_s<512>(acStack_1ec,"Ref warning : %s reference unlisted file %s");
            if (local_3c8[0] != PTR_DAT_00bbf7d8) {
              puVar10 = local_3c8[0] + -1;
              if ((local_3c8[0][-1] & 0x80) != 0) {
                puVar10 = local_3c8[0] + -4;
              }
              operator_delete__(puVar10);
              uStack_3cc = 0;
              local_3c8[0] = PTR_DAT_00bbf7d8;
            }
            if (puStack_3d0 != PTR_DAT_00bbf7d8) {
              puVar10 = puStack_3d0 + -1;
              if ((puStack_3d0[-1] & 0x80) != 0) {
                puVar10 = puStack_3d0 + -4;
              }
              operator_delete__(puVar10);
              uStack_3d4 = 0;
              puStack_3d0 = PTR_DAT_00bbf7d8;
            }
          }
          pCVar15 = (CPlugFile *)0x419aef;
          CFastBuffer<class_CDx9TextureKeeper*>::Add
                    ((CClassicArchive *)(in_stack_fffffba4 + 0xa8),(TiXmlAttributeSet *)&pCStack_440
                     ,pTVar19);
          if (pCStack_428 != (CFastBufferWheel<float> *)PTR_DAT_00bbf7dc) {
            if (((byte)pCStack_428[-1] & 0x80) == 0) {
              pCVar11 = pCStack_428 + -2;
            }
            else {
              pCVar11 = pCStack_428 + -4;
            }
            operator_delete__(pCVar11);
            local_42c = (CFastBufferWheel<float> *)0x0;
            pCStack_428 = (CFastBufferWheel<float> *)PTR_DAT_00bbf7dc;
          }
          if (local_414 != (CPlugMaterial *)PTR_DAT_00bbf7dc) {
            if (((byte)local_414[-1] & 0x80) == 0) {
              pCVar12 = local_414 + -2;
            }
            else {
              pCVar12 = local_414 + -4;
            }
            operator_delete__(pCVar12);
            local_418 = 0;
            local_414 = (CPlugMaterial *)PTR_DAT_00bbf7dc;
          }
        }
        pCVar8 = pCStack_440;
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (local_454,pCStack_440,(ulong)pCVar22);
        *(CFastBuffer<class_GxVertex2> **)pSVar3 = pCStack_434;
      }
      else {
        if (pCVar12 != (CPlugMaterial *)0x0) {
          this_01 = *(CSystemFidFile **)(pCVar12 + 8);
        }
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (local_454,pCStack_440,(ulong)pCVar22);
        *(CSystemFidFile **)pSVar3 = this_01;
        if (local_454 != (CSystemFidFile *)pCStack_434) {
          (**(code **)(*(int *)pCStack_434 + 4))();
        }
      }
      if (((*(int *)(in_stack_fffffba4 + 0x5c) != 0) && (local_438 != (CSystemFidsFolder *)0x0)) &&
         (pCStack_440 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (pCStack_450,pCVar8,(ulong)in_stack_fffffb9c);
        pCStack_444 = *(CPlugMaterial **)pSVar3;
        in_stack_fffffb9c = (CFastBuffer<class_CGamePlayerScore*> *)&pCStack_444;
        CFastBuffer<class_CGamePlayerScore*>::FindOrAdd
                  ((CClassicArchive *)(in_stack_fffffba4 + 0x6c),in_stack_fffffb9c,
                   (CGamePlayerScore **)in_stack_fffffba0);
      }
      pCStack_43c = (CSystemFidsFolder *)(pCVar8 + 1);
      if (local_430 <= pCStack_43c) goto LAB_00419bac;
      goto LAB_00419342;
    }
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (aCStack_3f4,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar21);
  CSystemFidsDrive::~CSystemFidsDrive(aCStack_3a4,(CSystemFidsDrive *)pCVar22);
  CSystemFidFile::~CSystemFidFile(aCStack_358,(CSystemFidFile *)in_stack_fffffb9c);
  CSystemFid::SCallStackFidContext::~SCallStackFidContext
            (auStack_3ac,(SCallStackFidContext *)in_stack_fffffba0);
  iVar4 = 0;
  goto LAB_00419c20;
}
}

// =================================================
// Function: CSystemArchiveNod::DoLoadResource
// =================================================
int __thiscall
CSystemArchiveNod::DoLoadResource
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,ulong param_2,CMwNod **param_3)
{
{
  CMwNod *pCVar1;
  CSystemFidFile *pCVar2;
  int iVar3;
  CMwNod **unaff_EBX;
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  *(undefined4 *)param_2 = 0;
  pCVar1 = CSystemEngine::GetResourceFromId
                     (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,unaff_EDI);
  if (pCVar1 != (CMwNod *)0x0) {
    *(CMwNod **)param_2 = pCVar1;
    return 1;
  }
  pCVar2 = CSystemEngine::GetFidFromResource
                     (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_1,unaff_ESI);
  *(CSystemFidFile **)(this + 0x50) = pCVar2;
  *(undefined4 *)(this + 0x78) = 7;
  iVar3 = DoFidLoadFile(this,(CSystemArchiveNod *)param_2,unaff_EBX);
  return iVar3;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSave
// =================================================
int __thiscall
CSystemArchiveNod::DoSave
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2,ulong param_3,
          EArchive param_4,int param_5)
{
{
  CSystemFid *this_00;
  int iVar1;
  CSystemArchiveNod *unaff_EBX;
  CSystemFid *unaff_ESI;
  ulong unaff_EDI;
  CSystemFid *pCVar2;
  
  DoDecode(this,(CSystemArchiveNod *)param_2,unaff_EDI);
  *(EArchive *)(this + 0x78) = param_4;
  if (param_2 != (CMwNod *)0x0) {
    pCVar2 = *(CSystemFid **)(param_2 + 8);
    *(CSystemFid **)(this + 0x50) = pCVar2;
    if ((pCVar2 != (CSystemFid *)0x0) && (*(int *)(pCVar2 + 0x60) == 0)) {
      if (param_4 != 1) {
        if (param_5 != 0) {
          iVar1 = DoFidSaveFileSafe(this,(CSystemArchiveNod *)param_2,param_2,(ulong)unaff_ESI);
          return iVar1;
        }
        iVar1 = DoFidSaveFile(this,(CSystemArchiveNod *)param_2,(CMwNod *)unaff_ESI);
        return iVar1;
      }
      this_00 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_ESI);
      pCVar2 = this_00;
      iVar1 = (**(code **)**(undefined4 **)(this_00 + 0x6c))(this_00,2,1);
      *(int *)(this + 4) = iVar1;
      if (iVar1 != 0) {
        iVar1 = DoSaveHeader(this,unaff_EBX);
        CSystemFid::BufferClose(this_00,*(CSystemFid **)(this + 4),(CClassicBuffer *)pCVar2);
        *(undefined4 *)(this + 4) = 0;
        return iVar1;
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveAll
// =================================================
int __thiscall CSystemArchiveNod::DoSaveAll(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  int iVar1;
  CSystemArchiveNod *unaff_ESI;
  CSystemArchiveNod *unaff_retaddr;
  
  iVar1 = DoSaveHeader(this,unaff_ESI);
  if (iVar1 != 0) {
    iVar1 = DoSaveRef(this,unaff_retaddr);
    if (iVar1 != 0) {
      iVar1 = DoSaveBody(this,param_1);
      return (uint)(iVar1 != 0);
    }
  }
  return 0;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveBody
// =================================================
int __thiscall CSystemArchiveNod::DoSaveBody(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  int iVar1;
  CClassicBufferMemory *unaff_retaddr;
  
  if (*(int *)(this + 0x8c) != 0) {
    CClassicBuffer::AddCompressedBlock
              (*(CClassicBuffer **)(this + 4),*(CClassicBuffer **)(this + 0xa4),unaff_retaddr);
    return 1;
  }
  iVar1 = CClassicBuffer::WriteAll
                    (*(CClassicBuffer **)(this + 4),
                     *(CClassicBuffer **)(*(CClassicBuffer **)(this + 0xa4) + 0xc),
                     *(void **)(this + 0x9c),(ulong)unaff_retaddr);
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveBodyMemory
// =================================================
int __thiscall
CSystemArchiveNod::DoSaveBodyMemory
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2)
{
{
  undefined *puVar1;
  CClassicBufferMemory *pCVar2;
  CClassicBufferMemory *this_00;
  CClassicBufferMemory *extraout_EAX;
  undefined4 uVar3;
  char *unaff_ESI;
  ulong unaff_EDI;
  CSystemArchiveNod *in_stack_0000000c;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a80b9b;
  local_c = ExceptionList;
  pCVar2 = (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  this_00 = operator_new(0x20);
  local_4 = (void *)0x0;
  if (this_00 == (CClassicBufferMemory *)0x0) {
    pCVar2 = (CClassicBufferMemory *)0x0;
  }
  else {
    CClassicBufferMemory::CClassicBufferMemory(this_00,pCVar2);
    pCVar2 = extraout_EAX;
  }
  *(CClassicBufferMemory **)(this + 0xa4) = pCVar2;
  CClassicBufferMemory::PreAlloc(pCVar2,(CClassicBufferMemory *)0xc800,unaff_EDI);
  puVar1 = PTR_s_DoNodPtr_00ccb56c;
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0xa4);
  AddInternalRef(this,in_stack_0000000c,(CMwNod *)&stack0x0000000c,(ulong *)puVar1,unaff_ESI);
  (**(code **)(*(int *)in_stack_0000000c + 0x34))();
  uVar3 = (**(code **)(**(int **)(this + 0xa4) + 0x18))();
  *(undefined4 *)(this + 0x9c) = uVar3;
  ExceptionList = local_4;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveFile
// =================================================
int __thiscall
CSystemArchiveNod::DoSaveFile
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CFastStringInt *param_2,
          CMwNod *param_3,CSystemFids *param_4,ulong param_5,EArchive param_6,int param_7)
{
{
  CSystemFidFile *this_00;
  CSystemFidFile *this_01;
  undefined *puVar1;
  CPlugMaterial *pCVar2;
  int iVar3;
  CSystemFid *unaff_EBP;
  CMwNod *unaff_ESI;
  CSystemFid *unaff_EDI;
  int in_stack_00000020;
  CSystemFid *pCVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined *local_14;
  undefined4 local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a81070;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DoDecode(this,(CSystemArchiveNod *)param_4,DAT_00cca150 ^ (uint)&stack0xffffffd0);
  *(undefined4 *)(this + 0x94) = 1;
  local_1c = 0;
  this_01 = CSystemEngine::FindOrAddFidAt
                      (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_4,
                       (CSystemFids *)param_2,(CFastStringInt *)&local_1c,(int *)unaff_EDI);
  *(int *)(this + 0x78) = param_7;
  this_00 = *(CSystemFidFile **)(param_4 + 8);
  if (this_00 != this_01) {
    if (this_00 != (CSystemFidFile *)0x0) {
      local_c = (undefined *)0x0;
      local_8 = PTR_DAT_00bbf7dc;
      unaff_EDI = (CSystemFid *)0x0;
      param_1 = (CSystemArchiveNod *)0x0;
      CSystemFidFile::GetFullName(this_01,(CPlugFile *)&local_c,(CFastStringInt *)0x0);
      local_18 = 0;
      local_14 = PTR_DAT_00bbf7dc;
      pCVar4 = (CSystemFid *)0x0;
      CSystemFidFile::GetFullName(this_00,(CPlugFile *)&local_18,(CFastStringInt *)0x0);
      CSystemEngine::UnbindFidNod
                (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_4,(CMwNod *)this_00,pCVar4)
      ;
      if (local_14 != PTR_DAT_00bbf7dc) {
        if ((local_14[-1] & 0x80) == 0) {
          puVar1 = local_14 + -2;
        }
        else {
          puVar1 = local_14 + -4;
        }
        operator_delete__(puVar1);
        local_18 = 0;
        local_14 = PTR_DAT_00bbf7dc;
      }
      if (local_c != PTR_DAT_00bbf7dc) {
        if ((local_c[-1] & 0x80) == 0) {
          puVar1 = local_c + -2;
        }
        else {
          puVar1 = local_c + -4;
        }
        operator_delete__(puVar1);
        local_10 = 0;
        local_c = PTR_DAT_00bbf7dc;
      }
    }
    pCVar2 = CSystemFid::GetNod((CSystemFid *)this_01,
                                (CSysFidNodRef<class_CPlugMaterial> *)&DAT_00d554d0);
    if (pCVar2 != (CPlugMaterial *)0x0) {
      CSystemEngine::UnbindFidNod
                (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)pCVar2,(CMwNod *)this_01,
                 unaff_EDI);
    }
  }
  *(CSystemFidFile **)(this + 0x50) = this_01;
  CSystemEngine::AddFidNod
            (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_4,(CMwNod *)this_01,
             (CSystemFid *)&DAT_00d554d0,(CSystemFidParameters *)unaff_EDI);
  if (in_stack_00000020 == 0) {
    iVar3 = DoFidSaveFile(this,(CSystemArchiveNod *)param_4,unaff_ESI);
  }
  else {
    iVar3 = DoFidSaveFileSafe(this,(CSystemArchiveNod *)param_4,(CMwNod *)param_6,(ulong)unaff_ESI);
  }
  if ((iVar3 == 0) && (local_14 != (undefined *)0x0)) {
    CSystemEngine::RemoveAndDeleteFid
              (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)this_01,unaff_EBP);
    *(undefined4 *)(this + 0x50) = 0;
  }
  ExceptionList = param_1;
  return iVar3;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveHeader
// =================================================
int __thiscall CSystemArchiveNod::DoSaveHeader(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  int iVar1;
  ulong unaff_ESI;
  CSystemFid *unaff_EDI;
  ulong uVar2;
  ulong in_stack_00000008;
  ulong in_stack_0000000c;
  CSystemArchiveNod *in_stack_00000010;
  CClassicArchive *in_stack_00000014;
  CFastBuffer<class_CCrystalFace*> *in_stack_00000018;
  int in_stack_0000001c;
  ulong uStack00000028;
  CClassicArchive *pCVar3;
  ulong in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  CSystemFid::ResetHeaderUserDatas(*(CSystemFid **)(this + 0x50),unaff_EDI);
  iVar1 = *(int *)(this + 0xc);
  CClassicArchive::WriteData
            ((CClassicArchive *)this,(CClassicArchive *)&DAT_00b2e398,(void *)0x3,unaff_ESI);
  uVar2 = 6;
  CClassicArchive::WriteData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0x00000000,(void *)0x2,
             in_stack_fffffff8);
  *(undefined2 *)(this + 0x18) = 6;
  if (iVar1 == 0) {
    pCVar3 = (CClassicArchive *)&DAT_00b2e390;
  }
  else {
    pCVar3 = (CClassicArchive *)&DAT_00b2e394;
  }
  CClassicArchive::WriteData((CClassicArchive *)this,pCVar3,(void *)0x1,in_stack_fffffffc);
  if (*(int *)(this + 0x7c) == 0) {
    pCVar3 = (CClassicArchive *)&DAT_00b2e38c;
  }
  else {
    pCVar3 = (CClassicArchive *)&DAT_00b2c99c;
  }
  CClassicArchive::WriteData((CClassicArchive *)this,pCVar3,(void *)0x1,uVar2);
  if (*(int *)(this + 0x8c) == 0) {
    pCVar3 = (CClassicArchive *)&DAT_00b2e38c;
  }
  else {
    pCVar3 = (CClassicArchive *)&DAT_00b2c99c;
  }
  CClassicArchive::WriteData((CClassicArchive *)this,pCVar3,(void *)0x1,(ulong)param_1);
  if (*(int *)(this + 0x10) == 0) {
    pCVar3 = (CClassicArchive *)&DAT_00b2e384;
  }
  else {
    pCVar3 = (CClassicArchive *)&DAT_00b2e388;
  }
  CClassicArchive::WriteData((CClassicArchive *)this,pCVar3,(void *)0x1,in_stack_00000008);
  CClassicArchive::WriteMask
            ((CClassicArchive *)this,(CClassicArchive *)(this + 0x4c),(ulong *)0x1,in_stack_0000000c
            );
  if (*(int *)(this + 0x88) == 0) {
    CSystemFid::BuildHeaderUserData
              (*(CSystemFid **)(this + 0x50),(CSystemFid *)this,in_stack_00000010);
  }
  CSystemFid::ArchiveHeaderUserData
            (*(CSystemFid **)(this + 0x50),(CSystemFid *)this,in_stack_00000014);
  uStack00000028 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x34,in_stack_00000018);
  CClassicArchive::WriteNatural
            ((CClassicArchive *)this,(CClassicArchive *)&stack0x00000028,(ulong *)0x1,0,
             in_stack_0000001c);
  *(undefined4 *)(*(int *)(this + 0x50) + 100) = *(undefined4 *)(this + 0x4c);
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveMemory
// =================================================
int __thiscall
CSystemArchiveNod::DoSaveMemory
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2,
          CMwNod *param_3,ulong param_4)
{
{
  CSystemFidMemory *pCVar1;
  CSystemFids *pCVar2;
  CSystemFid *pCVar3;
  int iVar4;
  CSystemManagerFile *unaff_ESI;
  ulong unaff_EDI;
  CSystemEngine *unaff_retaddr;
  CSystemFidParameters *in_stack_00000014;
  CMwNod *in_stack_00000018;
  CSystemEngine *in_stack_00000020;
  
  DoDecode(this,(CSystemArchiveNod *)param_3,unaff_EDI);
  pCVar1 = CSystemManagerFile::CreateFidMemory
                     (*(CSystemManagerFile **)(*(int *)(this + 0x1c) + 0x20),unaff_ESI);
  *(CMwNod **)(pCVar1 + 0x74) = param_3;
  pCVar2 = CSystemEngine::GetLocationBuffer(*(CSystemEngine **)(this + 0x1c),unaff_retaddr);
  *(CSystemFids **)(pCVar1 + 0x14) = pCVar2;
  *(CSystemFidMemory **)(this + 0x50) = pCVar1;
  pCVar3 = CSystemEngine::FindFid
                     (*(CSystemEngine **)(this + 0x1c),(CSystemFids *)pCVar1,
                      (CFastStringInt *)param_1,(int)param_2,(EFindWay)param_3);
  if (pCVar3 != (CSystemFid *)0x0) {
    (**(code **)(*(int *)pCVar1 + 4))();
    return 0;
  }
  CSystemEngine::UnbindFid(*(CSystemEngine **)(this + 0x1c),in_stack_00000020,(CMwNod *)param_4);
  CSystemEngine::AddFidNod
            (*(CSystemEngine **)(this + 0x1c),in_stack_00000020,*(CMwNod **)(this + 0x50),
             (CSystemFid *)&DAT_00d554d0,in_stack_00000014);
  iVar4 = DoFidSaveMemory(this,(CSystemArchiveNod *)in_stack_00000020,in_stack_00000018);
  return iVar4;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveMemoryTemp
// =================================================
int __thiscall
CSystemArchiveNod::DoSaveMemoryTemp
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CClassicBufferMemory *param_2,
          CMwNod *param_3,ulong param_4,int param_5)
{
{
  CMwNod *pCVar1;
  CSystemFid *unaff_EBX;
  int unaff_EBP;
  ulong unaff_ESI;
  CSystemFid *unaff_EDI;
  int iStack00000018;
  int in_stack_00000020;
  
  *(undefined4 *)(this + 0x84) = 1;
  *(ulong *)(this + 0x88) = param_4;
  pCVar1 = *(CMwNod **)(param_2 + 8);
  if (pCVar1 != (CMwNod *)0x0) {
    CSystemEngine::UnbindFidNod
              (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_2,pCVar1,unaff_EDI);
  }
  iStack00000018 =
       DoSaveMemory(this,(CSystemArchiveNod *)param_2,param_2,(CMwNod *)param_4,unaff_ESI);
  CSystemEngine::DetachBuffer(*(CSystemEngine **)(this + 0x1c),(CClassicArchive *)param_2,unaff_EBP)
  ;
  if (pCVar1 != (CMwNod *)0x0) {
    CSystemEngine::BindFidNod
              (*(CSystemEngine **)(this + 0x1c),(CSystemEngine *)param_2,pCVar1,unaff_EBX);
  }
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  return in_stack_00000020;
}
}

// =================================================
// Function: CSystemArchiveNod::DoSaveRef
// =================================================
int __thiscall CSystemArchiveNod::DoSaveRef(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  CClassicArchive *pCVar1;
  CSystemFids *pCVar2;
  CSystemFids *pCVar3;
  CSystemFids *this_00;
  SCasterCat *pSVar4;
  CSystemFid *this_01;
  CSystemFids *pCVar5;
  undefined4 uVar6;
  int unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CSystemEngine *unaff_ESI;
  CSystemFidsDrive *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  void *in_stack_00000028;
  undefined4 uStack0000002c;
  CSystemFidsDrive *in_stack_ffffff0c;
  CSystemFids *pCVar8;
  CFastBuffer<class_CSystemFids*> *in_stack_ffffff10;
  int in_stack_ffffff14;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffff18;
  int iVar9;
  CClassicArchive *pCVar10;
  CSystemArchiveNod *in_stack_ffffff28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_cc;
  CMwNod *local_c8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_c4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_c0;
  int iStack_b8;
  CSystemFids *local_b0 [7];
  CSystemFidFile local_94 [20];
  undefined1 local_80 [20];
  CSystemFids *local_6c;
  CSystemFidFile aCStack_64 [88];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80d76;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemFidFile::CSystemFidFile(local_94,(CSystemFidFile *)(DAT_00cca150 ^ (uint)&stack0xfffffefc))
  ;
  CSystemFidsDrive::CSystemFidsDrive((CSystemFidsDrive *)&stack0xffffff28,unaff_EDI);
  pCVar2 = CSystemEngine::GetLocationData(*(CSystemEngine **)(this + 0x1c),unaff_ESI);
  iVar9 = *(int *)(*(int *)(*(int *)(this + 0x50) + 0x14) + 0x18);
  pCVar3 = (CSystemFids *)CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x28,unaff_EBP);
  CClassicArchive::WriteNatural
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xffffff24,(ulong *)0x1,0,unaff_EBX);
  if (in_stack_ffffff28 != (CSystemArchiveNod *)0x0) {
    pCVar5 = pCVar3;
    if (*(int *)(*(int *)(this + 0x50) + 0x18) == 8) {
      local_6c = *(CSystemFids **)(this + 0x58);
      *(undefined1 **)(this + 0x50) = local_80;
      if (local_6c == (CSystemFids *)0x0) {
        if (pCVar2 == (CSystemFids *)0x0) {
          pCVar5 = (CSystemFids *)&local_c8;
          local_b0[0] = pCVar5;
          local_6c = pCVar5;
        }
        else {
          pCVar5 = *(CSystemFids **)(pCVar2 + 0x18);
          local_6c = pCVar2;
        }
      }
      else {
        pCVar5 = *(CSystemFids **)(local_6c + 0x18);
      }
    }
    pCVar2 = (CSystemFids *)0x0;
    ExtractExternalLocations
              (this,(CSystemArchiveNod *)&stack0xffffff20,(CFastBuffer<class_CSystemFids*> **)pCVar5
               ,in_stack_ffffff0c);
    pCVar8 = pCVar5;
    pCVar3 = pCVar5;
    this_00 = (CSystemFids *)CSystemFids::GetTravelInfo(*(CMwNod **)(*(int *)(this + 0x50) + 0x14));
    local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CSystemFids::TravelFindNbBackRoot(this_00,pCVar8,in_stack_ffffff10);
    CClassicArchive::WriteNatural
              ((CClassicArchive *)this,(CClassicArchive *)&local_c4,(ulong *)0x1,0,in_stack_ffffff14
              );
    local_c4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(pCVar5,in_stack_ffffff18);
    CClassicArchive::WriteNatural
              ((CClassicArchive *)this,(CClassicArchive *)&local_c4,(ulong *)0x1,0,iVar9);
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_c0 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar5,pCVar7,(ulong)pCVar2);
        pCVar2 = *(CSystemFids **)(*(int *)(this + 0x1c) + 0x20);
        (**(code **)(**(int **)pSVar4 + 0x84))();
        pCVar7 = pCVar7 + 1;
      } while (pCVar7 < local_c0);
    }
    local_cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_c4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (this + 0x28,local_cc,(ulong)pCVar2);
        this_01 = *(CSystemFid **)pSVar4;
        if (*(int *)(this + 0x84) == 0) {
          this_01 = CSystemFid::ParametrizedGetLoadableFid(this_01,(CSystemFid *)pCVar3);
        }
        pCVar2 = (CSystemFids *)0x1;
        pCVar1 = (CClassicArchive *)(this_01 + 0x18);
        iVar9 = 0x419026;
        pCVar10 = pCVar1;
        CClassicArchive::WriteNatural
                  ((CClassicArchive *)this,pCVar1,(ulong *)0x1,0,(int)in_stack_ffffff28);
        pCVar3 = (CSystemFids *)0x419033;
        in_stack_ffffff28 = this;
        (**(code **)(*(int *)this_01 + 0x80))();
        CClassicArchive::WriteNatural
                  ((CClassicArchive *)this,(CClassicArchive *)(pSVar4 + 8),(ulong *)0x1,0,iVar9);
        if (4 < *(ushort *)(this + 0x18)) {
          CClassicArchive::WriteBool
                    ((CClassicArchive *)this,(CClassicArchive *)(pSVar4 + 0x10),(int *)0x1,
                     (ulong)pCVar10);
        }
        if (((byte)*pCVar1 & 4) == 0) {
          CClassicArchive::WriteNatural
                    ((CClassicArchive *)this,(CClassicArchive *)(pSVar4 + 0xc),(ulong *)0x1,0,
                     (int)pCVar2);
        }
        local_cc = local_cc + 1;
      } while (local_cc < local_c4);
    }
    pCVar5 = (CSystemFids *)CSystemFids::GetTravelInfo(local_c8);
    CSystemFids::DeleteDown(pCVar5,pCVar2);
    if (pCVar5 != (CSystemFids *)0x0) {
      (**(code **)(*(int *)pCVar5 + 4))();
    }
    if (iStack_b8 != 0) {
      *(int *)(this + 0x50) = iStack_b8;
    }
  }
  uVar6 = (**(code **)(**(int **)(this + 4) + 0x14))();
  *(undefined4 *)(this + 0xa0) = uVar6;
  in_stack_00000028 = (void *)((uint)in_stack_00000028 & 0xffffff00);
  CSystemFidsDrive::~CSystemFidsDrive((CSystemFidsDrive *)local_b0,(CSystemFidsDrive *)pCVar3);
  uStack0000002c = 0xffffffff;
  CSystemFidFile::~CSystemFidFile(aCStack_64,(CSystemFidFile *)in_stack_ffffff28);
  ExceptionList = in_stack_00000028;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::Duplicate
// =================================================
CPlugVisual * __thiscall
CSystemArchiveNod::Duplicate(CSystemArchiveNod *this,CPlugVisualVertexs *param_1)
{
{
  CClassicBufferMemory *pCVar1;
  ulong unaff_ESI;
  CClassicBufferMemory *unaff_retaddr;
  CMwNod **in_stack_00000008;
  CMwNod *in_stack_00000010;
  
  pCVar1 = sBufferMemoryGetNew();
  CMwCmdBufferCore::HighFrequencyYield(DAT_00d731e0,(CMwCmdBufferCore *)0x1,unaff_ESI);
  SaveMemoryTemp(unaff_retaddr,*in_stack_00000008,8,1);
  CMwCmdBufferCore::HighFrequencyYield(DAT_00d731e0,(CMwCmdBufferCore *)0x1,(ulong)pCVar1);
  if (in_stack_00000010 == (CMwNod *)0x0) {
    in_stack_00000010 = (CMwNod *)0x0;
    LoadMemoryTemp((CClassicBufferMemory *)param_1,&stack0x00000010);
    *in_stack_00000008 = in_stack_00000010;
  }
  else {
    LoadMemoryTemp((CClassicBufferMemory *)param_1,in_stack_00000008);
  }
  sBufferMemoryFree((CClassicBufferMemory **)&param_1);
  return (CPlugVisual *)0x1;
}
}

// =================================================
// Function: CSystemArchiveNod::ExtractExternalLocations
// =================================================
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
CSystemArchiveNod::ExtractExternalLocations
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,
          CFastBuffer<class_CSystemFids*> **param_2,CSystemFidsDrive *param_3)
{
{
  CSystemArchiveNod *this_00;
  CSystemFidFile *this_01;
  undefined *puVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSystemFidsDrive *this_02;
  CSystemFids *extraout_EAX;
  ulong uVar4;
  CSystemFids *pCVar5;
  CSystemFids *pCVar6;
  CSystemFids *unaff_EBX;
  CSystemFids *unaff_EBP;
  CSystemFids *unaff_ESI;
  CSystemFids *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  void *in_stack_00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffdc8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffdcc;
  undefined *puVar8;
  CSystemFids *in_stack_fffffdd4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  CSystemFids *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffddc;
  CSystemFids *in_stack_fffffde0;
  CSystemFids *local_214;
  CMwNod *local_20c;
  ulong uStack_208;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_204;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_1fc;
  undefined4 local_1f4;
  CSystemFids aCStack_1ec [476];
  uint local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a80d2a;
  local_c = ExceptionList;
  local_10 = DAT_00cca150 ^ (uint)&stack0xfffffdc8;
  ExceptionList = &local_c;
  this_00 = this + 0x28;
  pCVar10 = (CSystemFids *)this;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xfffffdb8));
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar10 = *(CSystemFids **)(*(int *)(this + 0x1c) + 0x24);
    do {
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar7,(ulong)unaff_EDI);
      puVar1 = PTR_DAT_00bbf7d8;
      this_01 = *(CSystemFidFile **)pSVar3;
      if (*(int *)(this_01 + 0x14) == 0) {
        pCVar6 = (CSystemFids *)0x0;
      }
      else {
        pCVar6 = *(CSystemFids **)(*(int *)(this_01 + 0x14) + 0x18);
      }
      if (pCVar10 == (CSystemFids *)in_stack_fffffddc) {
        if (pCVar6 != pCVar10) {
          puVar8 = (undefined *)0x0;
          CSystemFidFile::GetFullName(this_01,(CPlugFile *)&stack0xfffffdd0,(CFastStringInt *)0x0);
          CFastStringInt::GetLatin1(&stack0xfffffdcc,(CFastStringInt *)&stack0xfffffddc);
          sprintf_s<512>((char *)&local_20c,
                         "Cannot save a reference to local < %s >, within a resource file");
          if (in_stack_fffffde0 != (CSystemFids *)PTR_DAT_00bbf7d8) {
            pCVar10 = in_stack_fffffde0 + -1;
            if (((byte)in_stack_fffffde0[-1] & 0x80) != 0) {
              pCVar10 = in_stack_fffffde0 + -4;
            }
            operator_delete__(pCVar10);
          }
          if (puVar8 != PTR_DAT_00bbf7dc) {
            if ((puVar8[-1] & 0x80) == 0) {
              puVar8 = puVar8 + -2;
            }
            else {
              puVar8 = puVar8 + -4;
            }
            operator_delete__(puVar8);
          }
          if (puVar1 == PTR_DAT_00bbf7d8) {
            ExceptionList = in_stack_00000018;
            return 0;
          }
          puVar8 = puVar1 + -1;
          if ((puVar1[-1] & 0x80) != 0) {
            puVar8 = puVar1 + -4;
          }
          operator_delete__(puVar8);
          ExceptionList = in_stack_00000018;
          return 0;
        }
      }
      else if (pCVar6 == (CSystemFids *)in_stack_fffffddc) {
        if (((byte)this_01[0x18] & 4) == 0) {
          puVar8 = (undefined *)0x0;
          CSystemFidFile::GetFullName(this_01,(CPlugFile *)&stack0xfffffdd0,(CFastStringInt *)0x0);
          CFastStringInt::GetLatin1(&stack0xfffffdcc,(CFastStringInt *)&stack0xfffffddc);
          sprintf_s<512>((char *)&local_20c,
                         "Cannot save a reference to resource-local < %s >, within a local file");
          if (in_stack_fffffde0 != (CSystemFids *)PTR_DAT_00bbf7d8) {
            pCVar10 = in_stack_fffffde0 + -1;
            if (((byte)in_stack_fffffde0[-1] & 0x80) != 0) {
              pCVar10 = in_stack_fffffde0 + -4;
            }
            operator_delete__(pCVar10);
          }
          if (puVar8 != PTR_DAT_00bbf7dc) {
            if ((puVar8[-1] & 0x80) == 0) {
              puVar8 = puVar8 + -2;
            }
            else {
              puVar8 = puVar8 + -4;
            }
            operator_delete__(puVar8);
          }
          if (puVar1 == PTR_DAT_00bbf7d8) {
            ExceptionList = in_stack_00000018;
            return 0;
          }
          puVar8 = puVar1 + -1;
          if ((puVar1[-1] & 0x80) != 0) {
            puVar8 = puVar1 + -4;
          }
          operator_delete__(puVar8);
          ExceptionList = in_stack_00000018;
          return 0;
        }
      }
      else if ((pCVar6 != pCVar10) && (*(int *)(this + 0x88) == 0)) {
        ExceptionList = in_stack_00000018;
        return 0;
      }
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar2);
  }
  CSystemFids::ClearTravelInfoDown(in_stack_fffffdd4,unaff_EDI);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar7,(ulong)unaff_ESI);
      unaff_ESI = (CSystemFids *)0x418bf5;
      CSystemFids::TravelMarkUp(*(CSystemFids **)(*(int *)pSVar3 + 0x14),unaff_EBP);
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar2);
  }
  CSystemFids::TravelMarkUp(*(CSystemFids **)(*(int *)(this + 0x50) + 0x14),unaff_ESI);
  this_02 = operator_new(0x48);
  if (this_02 == (CSystemFidsDrive *)0x0) {
    pCVar6 = (CSystemFids *)0x0;
  }
  else {
    CSystemFidsDrive::CSystemFidsDrive(this_02,(CSystemFidsDrive *)unaff_EBP);
    pCVar6 = extraout_EAX;
  }
  CSystemFids::TravelDuplicateFrom(pCVar6,in_stack_fffffde0,unaff_EBX);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar2,(ulong)in_stack_fffffdc8);
      uVar4 = CSystemFids::GetTravelInfo(*(CMwNod **)(*(int *)pSVar3 + 0x14));
      in_stack_fffffdc8 = pCVar2;
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar2,(ulong)in_stack_fffffdcc);
      *(ulong *)(pSVar3 + 0xc) = uVar4;
      pCVar2 = pCVar2 + 1;
      pCVar7 = local_204;
    } while (pCVar2 < local_204);
  }
  CSystemFids::GetTravelInfo(*(CMwNod **)(*(int *)(local_214 + 0x50) + 0x14));
  RecursiveSortFidsTrees(pCVar6);
  CSystemFids::ClearTravelInfoDown(pCVar6,(CSystemFids *)in_stack_fffffdc8);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar7 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar2,(ulong)in_stack_fffffdcc);
      if (*(CSystemFids **)(*(int *)(*(int *)pSVar3 + 0x14) + 0x18) == local_214) {
        in_stack_fffffdcc = pCVar2;
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (this_00,pCVar2,(ulong)param_2);
        param_2 = (CFastBuffer<class_CSystemFids*> **)0x418d4e;
        CSystemFids::TravelCountUp(*(CSystemFids **)(pSVar3 + 0xc),(CSystemFids *)this_02);
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCVar7);
  }
  CSystemFids::TravelCountUp(local_214,(CSystemFids *)in_stack_fffffdcc);
  pCVar5 = (CSystemFids *)CSystemFids::GetTravelInfo((CMwNod *)pCVar6);
  pCVar6 = CSystemFids::TravelGetTreesNbRefDown(pCVar6,pCVar5,(ulong)param_2);
  pCVar6 = pCVar6 + 0x28;
  *(CSystemFids **)pCStack_1fc = pCVar6;
  local_1f4 = 1;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (pCVar6,(CFastBuffer<class_CCrystalFace*> *)this_02);
  pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (pCVar6,pCVar7,(ulong)pCVar10);
      pCVar10 = aCStack_1ec;
      CSystemFids::CreateIndex(*(CSystemFids **)pSVar3,pCVar10,(ulong *)in_stack_fffffddc);
      pCVar7 = pCVar7 + 1;
    } while (pCVar7 < pCVar2);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_1fc != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x418dc0;
      pCVar9 = pCVar2;
      pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                         (this_00,pCVar2,(ulong)pCVar10);
      if ((*(byte *)(*(int *)pSVar3 + 0x18) & 4) == 0) {
        uVar4 = *(ulong *)(*(int *)pSVar3 + 0x14);
        pCVar10 = (CSystemFids *)pCVar2;
        if (*(ulong *)(uVar4 + 0x18) == uStack_208) {
          pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x418ddc;
          pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (this_00,pCVar2,(ulong)in_stack_fffffddc);
          in_stack_fffffddc =
               (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CSystemFids::GetTravelInfo(*(CMwNod **)(*(int *)pSVar3 + 0x14));
          if (in_stack_fffffddc == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)local_20c) {
            pCVar10 = (CSystemFids *)0x418df8;
            in_stack_fffffddc = pCVar2;
            pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                               (this_00,pCVar2,(ulong)in_stack_fffffde0);
            *(undefined4 *)(pSVar3 + 0xc) = 0;
            goto LAB_00418e17;
          }
          pCVar10 = (CSystemFids *)0x418e07;
          uVar4 = CSystemFids::GetTravelInfo((CMwNod *)in_stack_fffffddc);
          pCVar7 = pCVar2;
        }
        pSVar3 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (this_00,pCVar7,(ulong)pCVar9);
        *(ulong *)(pSVar3 + 0xc) = uVar4;
      }
LAB_00418e17:
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCStack_1fc);
  }
  CSystemFids::SetTravelInfo(*(CMwNod **)(*(int *)(local_204 + 0x50) + 0x14),uStack_208);
  ExceptionList = in_stack_00000018;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::InsertExternalLocations
// =================================================
int __thiscall
CSystemArchiveNod::InsertExternalLocations
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFids *param_2,
          CFastBuffer<class_CSystemFids*> *param_3)
{
{
  CMwNod *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  CFastArray<class_CSystemFids*> *unaff_EBX;
  CSystemFids *unaff_EBP;
  undefined1 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSystemFids *this_00;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CSystemFidsFolder*> *this_01;
  int unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000018;
  CMwNod *pCVar6;
  
  pCVar6 = (CMwNod *)0x1;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_2,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  this_01 = (CFastBuffer<class_CSystemFidsFolder*> *)0x1;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_2,pCVar5,(ulong)unaff_ESI);
      unaff_ESI = (undefined1 *)register0x00000010;
      CSystemFids::CreateIndex
                (*(CSystemFids **)pSVar3,(CSystemFids *)&stack0x00000000,(ulong *)unaff_EBP);
      pCVar5 = pCVar5 + 1;
      this_01 = (CFastBuffer<class_CSystemFidsFolder*> *)param_1;
    } while (pCVar5 < pCVar2);
  }
  this_00 = (CSystemFids *)(unaff_retaddr + 0x20);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount(this_00,this_01,(ulong)unaff_ESI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_2,pCVar5,(ulong)unaff_EBP);
      unaff_EBP = this_00;
      CSystemFids::FillPtrAtTravelIndex(*(CSystemFids **)pSVar3,this_00,unaff_EBX);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  CSystemFids::AddCompareTree
            ((CSystemFids *)this_01,param_2,(CFastBuffer<class_CSystemFids*> *)unaff_EBP);
  pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_EBX
                     );
  *(CFastBuffer<class_CSystemFidsFolder*> **)pSVar3 = this_01;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
  if ((CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1 < in_stack_00000018) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar2,(ulong)pCVar6);
      pCVar1 = *(CMwNod **)pSVar3;
      pCVar6 = pCVar1;
      uVar4 = CSystemFids::GetTravelInfo(pCVar1);
      if (uVar4 == 0) {
        *(undefined4 *)(pCVar1 + 0x18) = *(undefined4 *)(in_stack_00000018 + 0x18);
      }
      else {
        pCVar6 = (CMwNod *)pCVar2;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar2,(ulong)this);
        *(ulong *)pSVar3 = uVar4;
        if (pCVar1 != (CMwNod *)0x0) {
          this = (CSystemArchiveNod *)0x1;
          pCVar6 = (CMwNod *)0x41789e;
          (**(code **)(*(int *)pCVar1 + 4))();
        }
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < in_stack_00000018);
  }
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadCurrentHeader
// =================================================
int __thiscall
CSystemArchiveNod::LoadCurrentHeader
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,EVersion param_2)
{
{
  CSystemArchiveNod *this_00;
  uint *puVar1;
  int iVar2;
  SCasterCat *pSVar3;
  ulong unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  char cVar6;
  undefined4 unaff_retaddr;
  int iVar5;
  ulong in_stack_0000000c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000010;
  CClassicArchive CStack00000014;
  CFastBuffer<struct_SMeshOctreeCell> *in_stack_00000018;
  CFastBuffer<class_CSystemFidsFolder*> *in_stack_0000001c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000002c;
  undefined4 in_stack_fffffff8;
  ulong uVar7;
  undefined4 in_stack_fffffffc;
  CSystemFid *pCVar8;
  
  uVar7 = CONCAT22((short)((uint)in_stack_fffffff8 >> 0x10),CONCAT11(0x58,(char)in_stack_fffffff8));
  CClassicArchive::ReadData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xfffffff9,(void *)0x1,unaff_EDI);
  cVar6 = (char)((uint)in_stack_fffffffc >> 8);
  if (cVar6 == 'T') {
    *(undefined4 *)(this + 0xc) = 1;
  }
  else {
    if (cVar6 != 'B') {
      return 0;
    }
    *(undefined4 *)(this + 0xc) = 0;
  }
  pCVar8 = (CSystemFid *)
           CONCAT13((char)((uint)in_stack_fffffffc >> 0x18),CONCAT12(0x58,(short)in_stack_fffffffc))
  ;
  CClassicArchive::ReadData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0xfffffffe,(void *)0x1,unaff_ESI);
  cVar6 = (char)((uint)unaff_retaddr >> 0x10);
  if (cVar6 == 'C') {
    *(undefined4 *)(this + 0x7c) = 1;
  }
  else {
    if (cVar6 != 'U') {
      return 0;
    }
    *(undefined4 *)(this + 0x7c) = 0;
  }
  iVar5 = CONCAT13(0x58,(int3)unaff_retaddr);
  CClassicArchive::ReadData
            ((CClassicArchive *)this,(CClassicArchive *)&stack0x00000003,(void *)0x1,unaff_EBP);
  pCVar4 = in_stack_00000010;
  if (param_1._3_1_ == 'C') {
    *(undefined4 *)(this + 0x8c) = 1;
  }
  else {
    if (param_1._3_1_ != 'U') {
      return 0;
    }
    *(undefined4 *)(this + 0x8c) = 0;
  }
  if (3 < (int)in_stack_00000010) {
    in_stack_00000010 =
         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)CONCAT31(in_stack_00000010._1_3_,0x58);
    CClassicArchive::ReadData
              ((CClassicArchive *)this,(CClassicArchive *)&stack0x00000010,(void *)0x1,unaff_EBX);
    if (CStack00000014 == (CClassicArchive)0x52) {
      *(undefined4 *)(this + 0x10) = 1;
      goto LAB_0041766d;
    }
    if (CStack00000014 != (CClassicArchive)0x45) {
      return 0;
    }
  }
  *(undefined4 *)(this + 0x10) = 0;
LAB_0041766d:
  CClassicArchive::ReadMask
            ((CClassicArchive *)this,(CClassicArchive *)(this + 0x4c),(ulong *)0x1,uVar7);
  if ((int)pCVar4 < 6) {
    CSystemFid::SetNoHeaderUserDatas(*(CSystemFid **)(this + 0x50),pCVar8);
  }
  else {
    iVar2 = CSystemFid::ArchiveHeaderUserData
                      (*(CSystemFid **)(this + 0x50),(CSystemFid *)this,(CClassicArchive *)pCVar8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  CClassicArchive::ReadNatural((CClassicArchive *)this,&stack0x00000014,(ulong *)0x1,0,iVar5);
  if ((CFastBuffer<struct_SMeshOctreeCell> *)0xc350 < in_stack_00000018) {
    return 0;
  }
  if (in_stack_00000018 != (CFastBuffer<struct_SMeshOctreeCell> *)0x0) {
    this_00 = this + 0x34;
    CFastBuffer<struct_CSceneTrafficGraph::SEdge>::InitSize
              (this_00,in_stack_00000018,(ulong)param_1);
    CFastBuffer<class_CSystemFidsFolder*>::SetCount(this_00,in_stack_0000001c,param_2);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (in_stack_0000001c != (CFastBuffer<class_CSystemFidsFolder*> *)0x0) {
      do {
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar4,in_stack_0000000c);
        *(undefined4 *)pSVar3 = 0;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar4,(ulong)in_stack_00000010);
        *(undefined4 *)(pSVar3 + 8) = 0;
        in_stack_0000000c = 0x4176f6;
        in_stack_00000010 = pCVar4;
        pSVar3 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,pCVar4,_CStack00000014);
        pCVar4 = pCVar4 + 1;
        *(undefined4 *)(pSVar3 + 4) = 0;
      } while (pCVar4 < in_stack_0000002c);
    }
  }
  *(undefined4 *)(*(int *)(this + 0x50) + 100) = *(undefined4 *)(this + 0x4c);
  puVar1 = (uint *)(*(int *)(this + 0x50) + 0x1c);
  *puVar1 = *puVar1 ^ ((uint)(*(int *)(this + 0xc) != 0) << 9 ^
                      *(uint *)(*(int *)(this + 0x50) + 0x1c)) & 0x200;
  puVar1 = (uint *)(*(int *)(this + 0x50) + 0x1c);
  *puVar1 = *puVar1 ^ ((uint)(*(int *)(this + 0x8c) != 0) << 10 ^
                      *(uint *)(*(int *)(this + 0x50) + 0x1c)) & 0x400;
  return 1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFileFrom
// =================================================
int __cdecl
CSystemArchiveNod::LoadFileFrom
          (CFastStringInt *param_1,CMwNod **param_2,CSystemFids *param_3,EArchive param_4)
{
{
  int iVar1;
  EArchive unaff_ESI;
  CSystemFids *in_stack_00000014;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [232];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a806eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  iVar1 = DoLoadFile(local_f8,(CSystemArchiveNod *)param_2,(CFastStringInt *)param_3,
                     (CMwNod **)param_4,in_stack_00000014,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFromFid
// =================================================
int __cdecl CSystemArchiveNod::LoadFromFid(CMwNod **param_1,CSystemFid *param_2,EArchive param_3)
{
{
  int iVar1;
  CMwNod **unaff_ESI;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [76];
  EArchive local_a8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80fbb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  local_a8 = param_3;
  iVar1 = DoLoadFromFid(local_f8,(CSystemArchiveNod *)param_2,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFromFid<class_CMwNod>
// =================================================
int __cdecl
CSystemArchiveNod::LoadFromFid<class_CMwNod>
          (CMwNodRef<class_CMwNod> *param_1,CSystemFid *param_2,EArchive param_3)
{
{
  int iVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  CMwNod *local_4;
  
  local_4 = (CMwNod *)0x0;
  iVar1 = LoadFromFid(&local_4,param_2,param_3);
  if ((iVar1 != 0) && (local_4 != (CMwNod *)0x0)) {
    pCVar4 = *(CMwNod **)(PTR_DAT_00bc61bc + 4);
    pCVar3 = (CMwNod *)0x7577d2;
    iVar2 = (**(code **)(*(int *)local_4 + 0x10))();
    if (iVar2 == 0) {
      CMwNod::MwAddRef(unaff_ESI,pCVar3);
      CMwNod::MwRelease(unaff_EBX,pCVar4);
      local_4 = (CMwNod *)0x0;
      iVar1 = 0;
    }
  }
  pCVar4 = local_4;
  if (local_4 != *(CMwNod **)param_1) {
    if (local_4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
    }
    if (*(CMwNod **)param_1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)param_1,unaff_EDI);
    }
    *(CMwNod **)param_1 = pCVar4;
  }
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFromFid<class_CPlugSolid>
// =================================================
int __cdecl
CSystemArchiveNod::LoadFromFid<class_CPlugSolid>
          (CMwNodRef<class_CPlugSolid> *param_1,CSystemFid *param_2,EArchive param_3)
{
{
  int iVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  CMwNod *local_4;
  
  local_4 = (CMwNod *)0x0;
  iVar1 = LoadFromFid(&local_4,param_2,param_3);
  if ((iVar1 != 0) && (local_4 != (CMwNod *)0x0)) {
    pCVar4 = *(CMwNod **)(PTR_DAT_00badd04 + 4);
    pCVar3 = (CMwNod *)0x574c02;
    iVar2 = (**(code **)(*(int *)local_4 + 0x10))();
    if (iVar2 == 0) {
      CMwNod::MwAddRef(unaff_ESI,pCVar3);
      CMwNod::MwRelease(unaff_EBX,pCVar4);
      local_4 = (CMwNod *)0x0;
      iVar1 = 0;
    }
  }
  pCVar4 = local_4;
  if (local_4 != *(CMwNod **)param_1) {
    if (local_4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
    }
    if (*(CMwNod **)param_1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)param_1,unaff_EDI);
    }
    *(CMwNod **)param_1 = pCVar4;
  }
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFromFid<class_CPlugSound>
// =================================================
int __cdecl
CSystemArchiveNod::LoadFromFid<class_CPlugSound>
          (CMwNodRef<class_CPlugSound> *param_1,CSystemFid *param_2,EArchive param_3)
{
{
  int iVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  CMwNod *local_4;
  
  local_4 = (CMwNod *)0x0;
  iVar1 = LoadFromFid(&local_4,param_2,param_3);
  if ((iVar1 != 0) && (local_4 != (CMwNod *)0x0)) {
    pCVar4 = *(CMwNod **)(PTR_DAT_00bb2298 + 4);
    pCVar3 = (CMwNod *)0x5e5412;
    iVar2 = (**(code **)(*(int *)local_4 + 0x10))();
    if (iVar2 == 0) {
      CMwNod::MwAddRef(unaff_ESI,pCVar3);
      CMwNod::MwRelease(unaff_EBX,pCVar4);
      local_4 = (CMwNod *)0x0;
      iVar1 = 0;
    }
  }
  pCVar4 = local_4;
  if (local_4 != *(CMwNod **)param_1) {
    if (local_4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
    }
    if (*(CMwNod **)param_1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)param_1,unaff_EDI);
    }
    *(CMwNod **)param_1 = pCVar4;
  }
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadFromFid<class_CVisionResourceFile>
// =================================================
int __cdecl
CSystemArchiveNod::LoadFromFid<class_CVisionResourceFile>
          (CMwNodRef<class_CVisionResourceFile> *param_1,CSystemFid *param_2,EArchive param_3)
{
{
  int iVar1;
  int iVar2;
  CMwNod *unaff_EBX;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  CMwNod *local_4;
  
  local_4 = (CMwNod *)0x0;
  iVar1 = LoadFromFid(&local_4,param_2,param_3);
  if ((iVar1 != 0) && (local_4 != (CMwNod *)0x0)) {
    pCVar4 = *(CMwNod **)(PTR_DAT_00bd0b40 + 4);
    pCVar3 = (CMwNod *)0x9563a2;
    iVar2 = (**(code **)(*(int *)local_4 + 0x10))();
    if (iVar2 == 0) {
      CMwNod::MwAddRef(unaff_ESI,pCVar3);
      CMwNod::MwRelease(unaff_EBX,pCVar4);
      local_4 = (CMwNod *)0x0;
      iVar1 = 0;
    }
  }
  pCVar4 = local_4;
  if (local_4 != *(CMwNod **)param_1) {
    if (local_4 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(local_4,unaff_EDI);
    }
    if (*(CMwNod **)param_1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)param_1,unaff_EDI);
    }
    *(CMwNod **)param_1 = pCVar4;
  }
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadMemoryTemp
// =================================================
int __cdecl CSystemArchiveNod::LoadMemoryTemp(CClassicBufferMemory *param_1,CMwNod **param_2)
{
{
  int iVar1;
  CMwNod **unaff_ESI;
  CClassicBufferMemory *in_stack_0000000c;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [116];
  undefined4 local_80;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a810fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  local_80 = 7;
  iVar1 = DoLoadMemoryTemp(local_f8,(CSystemArchiveNod *)param_2,in_stack_0000000c,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::LoadResource
// =================================================
int __cdecl CSystemArchiveNod::LoadResource(ulong param_1,CMwNod **param_2)
{
{
  int iVar1;
  CMwNod **unaff_ESI;
  ulong in_stack_0000000c;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [232];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aa233b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  iVar1 = DoLoadResource(local_f8,(CSystemArchiveNod *)param_2,in_stack_0000000c,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::ParametrizedFinalization
// =================================================
void __thiscall
CSystemArchiveNod::ParametrizedFinalization
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CMwNod *param_2)
{
{
  CSystemFidParameters *pCVar1;
  CSystemFidParameters *pCVar2;
  CMwNod *pCVar3;
  CMwNod *pCVar4;
  SCasterCat *pSVar5;
  CSystemFid *pCVar6;
  SSamplerState *pSVar7;
  int iVar8;
  CSystemFid *pCVar9;
  ulong uVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CFastString *unaff_EBX;
  ulong unaff_EBP;
  CSystemFid *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  CMwNod *unaff_EDI;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *pCVar13;
  GmFrustumIso4 *unaff_retaddr;
  CSystemFidParameters *in_stack_0000000c;
  CMwNod *in_stack_00000014;
  int in_stack_00000020;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff0;
  CSystemFid *pCVar14;
  CMwNod *in_stack_fffffffc;
  
  pCVar6 = *(CSystemFid **)(param_1 + 8);
  if (*(int *)(this + 0x5c) == 0) {
    CSystemFidParameters::operator=
              ((CSystemFidParameters *)(pCVar6 + 0x34),(SNormalDec3N *)&DAT_00d554d0,
               (GmVec3 *)unaff_EDI);
    return;
  }
  pCVar14 = pCVar6;
  pCVar3 = (CMwNod *)CSystemFidParameters::GetCurrentParameters();
  pCVar4 = (CMwNod *)CSystemFid::GetClassId(pCVar6,unaff_ESI);
  pCVar1 = (CSystemFidParameters *)(pCVar3 + 4);
  pSVar5 = CFastBuffer<unsigned_short>::operator[]
                     (pCVar1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x3,unaff_EBP);
  pCVar6 = (CSystemFid *)(uint)(byte)pSVar5[1];
  if (pCVar6 != (CSystemFid *)0x0) {
    pCVar13 = (CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
               *)0x0;
    pCVar3 = in_stack_fffffffc;
    do {
      pSVar7 = CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>::
               GetElemInCat(pCVar1,pCVar13,3,(ulong)unaff_EDI);
      pCVar2 = *(CSystemFidParameters **)pSVar7;
      unaff_EDI = (CMwNod *)0x417d15;
      iVar8 = (**(code **)(*(int *)pCVar2 + 4))();
      if ((iVar8 == 0) &&
         (iVar8 = CSystemFidParameters::DoesMatch
                            (*(ulong **)(pCVar2 + 8),(CFastBuffer<unsigned_long> *)pCVar14),
         iVar8 != 0)) {
        CSystemFidParameters::AddParam
                  (*(CSystemFidParameters **)(this + 0x5c),pCVar2,(SParam *)unaff_EDI);
        unaff_EDI = (CMwNod *)0x417d40;
        pCVar9 = CSystemFid::ParametrizedGetLoadableFid(pCVar6,(CSystemFid *)unaff_EBX);
        if (*(CSystemFid **)(pCVar2 + 0x10) == pCVar9) {
          unaff_EBX = (CFastString *)(pCVar2 + 0x1c);
          unaff_EDI = (CMwNod *)(pCVar2 + 0x14);
          CMwNod::Param_Set(in_stack_00000014,unaff_EDI,unaff_EBX,
                            (CFastStringInt *)in_stack_fffffff0);
        }
      }
      pCVar13 = pCVar13 + 1;
      in_stack_fffffffc = pCVar3;
    } while (pCVar13 < pCVar6);
  }
  pCVar1 = (CSystemFidParameters *)(this + 0x6c);
  InternalApplyFidParameters
            (pCVar3,*(ulong *)(this + 0x5c),(CSystemFidParameters *)(this + 0x60),pCVar1,
             (CFastBuffer<class_CSystemFid*> *)unaff_EDI,(CFastBuffer<class_CSystemFid*> *)unaff_EBX
            );
  uVar10 = CFastBuffer<class_CCrystalFace*>::GetCount
                     (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
  if (uVar10 != 0) {
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar1,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar1,pCVar12,(ulong)in_stack_fffffff0);
        if (*(int *)(*(int *)pSVar5 + 0x5c) == 0) {
          if (pCVar12 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            in_stack_fffffff0 = (CFastBuffer<class_CCrystalFace*> *)0x0;
            CFastBuffer<class_CGameFid*>::SwapElemsAt
                      (pCVar1,(CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> *)pCVar12,0,
                       (ulong)pCVar4);
          }
          break;
        }
        pCVar12 = pCVar12 + 1;
      } while (pCVar12 < pCVar11);
    }
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(pCVar1,in_stack_fffffff0);
    pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar1,pCVar12,(ulong)pCVar4);
        pCVar4 = param_2;
        CSystemFidParameters::MergeForChildFid
                  (*(CSystemFidParameters **)(this + 0x5c),*(CSystemFidParameters **)pSVar5 + 0x34,
                   *(CSystemFidParameters **)pSVar5,(CSystemFid *)param_2,(ulong)pCVar14);
        pCVar12 = pCVar12 + 1;
      } while (pCVar12 < pCVar11);
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,(GmFrustumIso4 *)pCVar4);
    pCVar3 = (CMwNod *)in_stack_0000000c;
  }
  pCVar1 = (CSystemFidParameters *)(this + 0x60);
  uVar10 = CFastBuffer<class_CCrystalFace*>::GetCount
                     (pCVar1,(CFastBuffer<class_CCrystalFace*> *)pCVar14);
  if (uVar10 != 0) {
    CSystemFidParameters::MergeForClassIds
              (*(CSystemFidParameters **)(this + 0x5c),(CSystemFidParameters *)pCVar3,pCVar1,
               (CFastBuffer<class_CSystemFid*> *)in_stack_fffffffc);
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,unaff_retaddr);
  }
  if (*(int *)(*(CSystemFidParameters **)(this + 0x5c) + 0x28) == 0) {
    CSystemFidParameters::MergeForClassIds
              (*(CSystemFidParameters **)(this + 0x5c),(CSystemFidParameters *)pCVar3,
               (CSystemFidParameters *)in_stack_00000014,(CFastBuffer<class_CSystemFid*> *)pCVar6);
  }
  CSystemFidParameters::Simplify
            (*(CSystemFidParameters **)(this + 0x5c),(CSystemFidParameters *)in_stack_00000014,
             (ulong)pCVar6);
  CSystemFidParameters::operator=
            ((CSystemFidParameters *)(in_stack_00000020 + 0x34),*(SNormalDec3N **)(this + 0x5c),
             (GmVec3 *)param_2);
  *(undefined4 *)(this + 0x5c) = 0;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::ParametrizedFindOrAddFid
// =================================================
void __thiscall
CSystemArchiveNod::ParametrizedFindOrAddFid
          (CSystemArchiveNod *this,CSystemArchiveNod *param_1,CSystemFid *param_2,CMwNod *param_3)
{
{
  CFastString *this_00;
  CSystemFidParameters *pCVar1;
  CSystemFidParameters *pCVar2;
  CSystemArchiveNod *this_01;
  undefined4 *extraout_EAX;
  CSystemFid *pCVar3;
  CSystemFid *unaff_EBX;
  SStringParam *unaff_EBP;
  void *in_stack_0000002c;
  CSystemEngine *in_stack_0000003c;
  ulong uVar4;
  GmVec3 *in_stack_ffffffb4;
  GmVec3 *in_stack_ffffffb8;
  CSystemFid *in_stack_ffffffbc;
  undefined *in_stack_ffffffc0;
  CSystemFid *in_stack_ffffffc4;
  CSystemFidParameters *in_stack_ffffffc8;
  int local_34;
  int local_30;
  SNormalDec3N *local_2c;
  CSystemFid *local_28;
  undefined *local_24;
  undefined *local_20;
  char *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a80ea8;
  local_c = ExceptionList;
  pCVar1 = (CSystemFidParameters *)(DAT_00cca150 ^ (uint)&stack0xffffff98);
  ExceptionList = &local_c;
  pCVar2 = CSystemFidParameters::GetCurrentParameters();
  uVar4 = 0;
  if ((*(int *)(param_1 + 0x18) == 1) || (*(int *)(param_1 + 0x18) == 3)) {
    this_01 = (CSystemArchiveNod *)
              CSystemFid::ParametrizedGetFid((CSystemFid *)param_1,(CSystemFid *)pCVar2,pCVar1);
    this_00 = DAT_00d54224;
    if (this_01 == (CSystemArchiveNod *)0x0) {
      in_stack_ffffffb8 = (GmVec3 *)0x0;
      DAT_00d54224 = DAT_00d54224 + 1;
      in_stack_ffffffbc = (CSystemFid *)PTR_DAT_00bbf7d8;
      CFastString::Format(this_00,(CFastString *)&stack0xffffffb8,"%d");
      in_stack_ffffffc8 = (CSystemFidParameters *)0x0;
      local_28 = in_stack_ffffffc4;
      local_24 = in_stack_ffffffc0;
      CFastStringInt::CFastStringInt(&local_30,(CFastStringInt *)&local_28,unaff_EBP);
      local_14 = extraout_EAX[1];
      local_10 = *extraout_EAX;
      local_c = (void *)0x0;
      pCVar3 = CSystemFid::ParametrizedGetLoadableFid((CSystemFid *)param_1,unaff_EBX);
      local_4 = *(undefined4 *)(pCVar3 + 0x78);
      local_18 = "%1?%2";
      local_14 = 5;
      CFastStringInt::SetCompose
                (&local_30,(CFastStringInt *)&local_18,(SStringParam *)&local_4,
                 (SStringParamInt *)&local_10);
      if (local_24 != PTR_DAT_00bbf7dc) {
        if ((local_24[-1] & 0x80) == 0) {
          local_24 = local_24 + -2;
        }
        else {
          local_24 = local_24 + -4;
        }
        operator_delete__(local_24);
        local_28 = (CSystemFid *)0x0;
        local_24 = PTR_DAT_00bbf7dc;
      }
      this_01 = (CSystemArchiveNod *)
                CSystemEngine::FindOrAddFidAt
                          (*(CSystemEngine **)(in_stack_ffffffbc + 0x1c),
                           *(CSystemEngine **)(param_1 + 0x14),(CSystemFids *)&local_30,
                           (CFastStringInt *)0x0,(int *)this);
      CSystemFid::SetVirtualLoader
                ((CSystemFid *)this_01,(CSystemFid *)&PTR_vftable_00ccbf94,(CLoader *)0x0,uVar4);
      uVar4 = CSystemFid::GetClassId((CSystemFid *)param_1,(CSystemFid *)pCVar2);
      *(ulong *)(this_01 + 100) = uVar4;
      local_34 = 1;
      if (local_20 != PTR_DAT_00bbf7dc) {
        if ((local_20[-1] & 0x80) == 0) {
          local_20 = local_20 + -2;
        }
        else {
          local_20 = local_20 + -4;
        }
        operator_delete__(local_20);
        local_24 = (undefined *)0x0;
        local_20 = PTR_DAT_00bbf7dc;
      }
      if (local_28 != (CSystemFid *)PTR_DAT_00bbf7d8) {
        pCVar3 = local_28 + -1;
        if (((byte)local_28[-1] & 0x80) != 0) {
          pCVar3 = local_28 + -4;
        }
        operator_delete__(pCVar3);
        local_2c = (SNormalDec3N *)0x0;
        local_28 = (CSystemFid *)PTR_DAT_00bbf7d8;
      }
    }
    pCVar1 = in_stack_ffffffc8 + 0xc0;
    CSystemFidParameters::operator=(pCVar1,(SNormalDec3N *)&DAT_00d554d0,in_stack_ffffffb4);
    *(CSystemFidParameters **)(local_34 + 0x5c) = pCVar1;
    if (local_30 != 0) {
      CSystemFidParameters::operator=
                ((CSystemFidParameters *)(this_01 + 0x34),local_2c,in_stack_ffffffb8);
      pCVar1 = (CSystemFidParameters *)
               CSystemFid::GetClassId((CSystemFid *)param_1,in_stack_ffffffbc);
      CSystemFidParameters::Simplify
                ((CSystemFidParameters *)(this_01 + 0x34),pCVar1,(ulong)in_stack_ffffffc0);
      CSystemFid::ParametrizedAddFid((CSystemFid *)param_1,(CSystemFid *)this_01,in_stack_ffffffc4);
    }
  }
  else {
    *(undefined4 *)(this + 0x5c) = 0;
    this_01 = param_1;
  }
  CSystemEngine::AddFidNod
            (*(CSystemEngine **)(local_24 + 0x1c),in_stack_0000003c,(CMwNod *)this_01,
             (CSystemFid *)(this_01 + 0x34),in_stack_ffffffc8);
  ExceptionList = in_stack_0000002c;
  return;
}
}

// =================================================
// Function: CSystemArchiveNod::Save
// =================================================
int __cdecl CSystemArchiveNod::Save(CMwNod *param_1,ulong param_2,int param_3)
{
{
  int iVar1;
  int unaff_ESI;
  EArchive in_stack_00000010;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [232];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a806bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  iVar1 = DoSave(local_f8,(CSystemArchiveNod *)param_2,(CMwNod *)param_3,7,in_stack_00000010,
                 unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::SaveFile
// =================================================
int __cdecl
CSystemArchiveNod::SaveFile
          (CFastStringInt *param_1,CMwNod *param_2,CSystemFids *param_3,ulong param_4,
          EArchive param_5,int param_6)
{
{
  int iVar1;
  int unaff_ESI;
  EArchive in_stack_0000001c;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [232];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a8115b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  iVar1 = DoSaveFile(local_f8,(CSystemArchiveNod *)param_2,(CFastStringInt *)param_3,
                     (CMwNod *)param_4,(CSystemFids *)param_5,param_6,in_stack_0000001c,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::SaveMemoryTemp
// =================================================
int __cdecl
CSystemArchiveNod::SaveMemoryTemp
          (CClassicBufferMemory *param_1,CMwNod *param_2,ulong param_3,int param_4)
{
{
  int iVar1;
  int unaff_ESI;
  ulong in_stack_00000014;
  CSystemArchiveNod *in_stack_ffffff04;
  CSystemArchiveNod local_f8 [4];
  CSystemArchiveNod local_f4 [232];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00a80f8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSystemArchiveNod((CSystemArchiveNod *)&stack0xffffff04,
                    (CSystemArchiveNod *)(DAT_00cca150 ^ (uint)&stack0xffffff00));
  iVar1 = DoSaveMemoryTemp(local_f8,(CSystemArchiveNod *)param_2,(CClassicBufferMemory *)param_3,
                           (CMwNod *)param_4,in_stack_00000014,unaff_ESI);
  ~CSystemArchiveNod(local_f4,in_stack_ffffff04);
  ExceptionList = (void *)0x0;
  return iVar1;
}
}

// =================================================
// Function: CSystemArchiveNod::SaveMemoryToFile
// =================================================
int __cdecl CSystemArchiveNod::SaveMemoryToFile(CSystemFid *param_1,CClassicBufferMemory *param_2)
{
{
  EMakeDir EVar1;
  CClassicBuffer *this;
  void *pvVar2;
  int iVar3;
  CSystemFid *pCVar4;
  
  if (param_2 == (CClassicBufferMemory *)0x0) {
    return 0;
  }
  EVar1 = CSystemFidsFolder::MakeDir((CFastStringInt *)0x1);
  if (EVar1 == 0) {
    return 0;
  }
  pCVar4 = param_1;
  this = (CClassicBuffer *)(**(code **)**(undefined4 **)(param_1 + 0x6c))(param_1,2,0);
  if (this == (CClassicBuffer *)0x0) {
    return 0;
  }
  pvVar2 = (void *)(**(code **)(*(int *)param_2 + 0x18))();
  iVar3 = CClassicBuffer::WriteAll(this,*(CClassicBuffer **)(param_2 + 0xc),pvVar2,(ulong)pCVar4);
  (**(code **)(**(int **)(param_1 + 0x6c) + 4))(param_1,this);
  return iVar3;
}
}

// =================================================
// Function: CSystemArchiveNod::~CSystemArchiveNod
// =================================================
void __thiscall
CSystemArchiveNod::~CSystemArchiveNod(CSystemArchiveNod *this,CSystemArchiveNod *param_1)
{
{
  CFastArray<class_CCrystalEdge*> *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBX;
  CSystemFidParameters *unaff_ESI;
  CFastArray<class_CCrystalEdge*> *unaff_EDI;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_retaddr;
  CFastArray<class_CFuncShader*> *in_stack_00000008;
  CClassicArchive *in_stack_0000000c;
  void *in_stack_00000024;
  undefined4 uStack00000028;
  CSystemArchiveNod *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  
  pCVar3 = ExceptionList;
  pCVar4 = (CFastBuffer<class_CPlugFileGPUV*> *)&LAB_00a80b74;
  pCVar1 = (CFastArray<class_CCrystalEdge*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar5 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_00000009;
  pCVar2 = this;
  if (*(undefined4 **)(this + 0xa4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(this + 0xa4))(1);
  }
  *(undefined4 *)(this + 0xa4) = 0;
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll(this + 0xa8,pCVar1);
  CFastBuffer<class_CPlugBitmapPackInput*>::DeleteAll(this + 0xb4,unaff_EDI);
  param_1 = (CSystemArchiveNod *)CONCAT31(param_1._1_3_,8);
  CSystemFidParameters::~CSystemFidParameters((CSystemFidParameters *)(this + 0xc0),unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0xb4,unaff_EBX);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0xa8,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar2);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x6c,pCVar3);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x60,pCVar4);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x40,pCVar5);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x34,unaff_retaddr);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x28,(CFastBuffer<class_CPlugFileGPUV*> *)param_1);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x20,in_stack_00000008);
  uStack00000028 = 0xffffffff;
  CClassicArchive::~CClassicArchive((CClassicArchive *)this,in_stack_0000000c);
  ExceptionList = in_stack_00000024;
  return;
}
}

