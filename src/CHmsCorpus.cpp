// Class implementation: CHmsCorpus

// =================================================
// Function: CHmsCorpus::CHmsCorpus
// =================================================
void __thiscall CHmsCorpus::CHmsCorpus(CHmsCorpus *this,CHmsCorpus *param_1)
{
{
  CHmsZoneElem *unaff_ESI;
  
  CHmsZoneElem::CHmsZoneElem((CHmsZoneElem *)this,unaff_ESI);
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x54) = 0xffffffff;
  return;
}
}

// =================================================
// Function: CHmsCorpus::ComputeCurrentState
// =================================================
void __thiscall CHmsCorpus::ComputeCurrentState(CHmsCorpus *this,CHmsCorpus *param_1,float param_2)
{
{
  int iVar1;
  undefined4 *puVar2;
  float unaff_EDI;
  CHmsCorpus *pCVar3;
  undefined1 local_30 [4];
  undefined4 local_2c [11];
  
  iVar1 = *(int *)(this + 0x58);
  if (iVar1 != 0) {
    GmIso4::SetBlend(local_30,(SParam *)(*(int *)(iVar1 + 0x328) + 0x10),
                     (SParam *)(*(int *)(iVar1 + 0x32c) + 0x10),(SParam *)param_1,unaff_EDI);
    puVar2 = local_2c;
    pCVar3 = this + 0x18;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pCVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      pCVar3 = pCVar3 + 4;
    }
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::GetLocation
// =================================================
void __thiscall CHmsCorpus::GetLocation(CHmsCorpus *this,GmLocFreeVal *param_1,GmIso4 *param_2)
{
{
  if (*(int *)(this + 0x58) != 0) {
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::GetMwClassId
// =================================================
ulong __thiscall CHmsCorpus::GetMwClassId(CHmsCorpus *this,CControlStyle *param_1)
{
{
  return 0x6002000;
}
}

// =================================================
// Function: CHmsCorpus::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CHmsCorpus::MwGetClassInfo(CHmsCorpus *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6764c;
}
}

// =================================================
// Function: CHmsCorpus::MwIsKindOf
// =================================================
int __thiscall CHmsCorpus::MwIsKindOf(CHmsCorpus *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if ((param_1 != (CMwCmdAffectParam *)0x6002000) && (param_1 != (CMwCmdAffectParam *)0x6008000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CHmsCorpus::MwNewCHmsCorpus
// =================================================
CMwNod * __cdecl CHmsCorpus::MwNewCHmsCorpus(void)
{
{
  CHmsCorpus *pCVar1;
  CMwNod *extraout_EAX;
  CHmsCorpus *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a9615b;
  local_c = ExceptionList;
  pCVar1 = (CHmsCorpus *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x5c);
  local_4 = 0;
  if (local_10 != (CHmsCorpus *)0x0) {
    CHmsCorpus(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CHmsCorpus::OldRestoreStaticState
// =================================================
void __thiscall
CHmsCorpus::OldRestoreStaticState
          (CHmsCorpus *this,CHmsCorpus *param_1,CClassicBufferMemory *param_2,int param_3,
          uchar param_4,int param_5)
{
{
  uchar unaff_retaddr;
  
  if (*(void **)(this + 0x58) != (void *)0x0) {
    CHmsDyna::OldRestoreStaticState
              (*(void **)(this + 0x58),param_1,param_2,param_3,unaff_retaddr,(int)param_1);
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::OnCrashDump
// =================================================
int __thiscall CHmsCorpus::OnCrashDump(CHmsCorpus *this,CMwNod *param_1,CFastString *param_2)
{
{
  int *piVar1;
  int iVar2;
  CFastString *this_00;
  GmVec3 *unaff_EBX;
  int unaff_ESI;
  CFastString *unaff_EDI;
  CMwNod *pCVar3;
  char *pcVar4;
  
  iVar2 = CMwNod::OnCrashDump((CMwNod *)this,param_1,unaff_EDI);
  if (iVar2 == 0) {
    return 0;
  }
  (**(code **)(DAT_00d5546c + 0x14))();
  iVar2 = (**(code **)(*(int *)this + 0x78))();
  pcVar4 = "Translation=";
  pCVar3 = param_1;
  this_00 = (CFastString *)(**(code **)(DAT_00d5546c + 0x1c))();
  CFastString::operator<<(this_00,(CPlugFileGpuBuilder *)pCVar3,pcVar4);
  CSystemCrashDump::StringCatVec3
            ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)param_1,
             (CFastString *)(iVar2 + 0x24),unaff_EBX);
  piVar1 = *(int **)(this + 0x48);
  iVar2 = CSystemCrashDump::IsValid_DumpFidAndMwId
                    ((CSystemCrashDump *)&DAT_00d5546c,(CSystemCrashDump *)param_1,
                     (CFastString *)"HmsItem",(char *)piVar1,(CMwNod *)0x1,unaff_ESI);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x58))();
  }
  (**(code **)(DAT_00d5546c + 0x18))();
  return 1;
}
}

// =================================================
// Function: CHmsCorpus::RefreshFromSolid
// =================================================
void __thiscall CHmsCorpus::RefreshFromSolid(CHmsCorpus *this,CHmsCorpus *param_1)
{
{
  if (*(int *)(this + 0x58) != 0) {
    *(int *)(*(int *)(this + 0x58) + 0x108) = *(int *)(*(int *)(this + 0x48) + 0x14) + 0x18;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::Reset
// =================================================
void __thiscall CHmsCorpus::Reset(CHmsCorpus *this,GmFrustumIso4 *param_1)
{
{
  if (*(void **)(this + 0x58) != (void *)0x0) {
    CHmsDyna::Reset(*(void **)(this + 0x58),param_1);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::RestoreStaticState
// =================================================
void __thiscall
CHmsCorpus::RestoreStaticState
          (CHmsCorpus *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,int param_3,
          ulong param_4,ulong param_5,int param_6)
{
{
  if (*(void **)(this + 0x58) != (void *)0x0) {
    CHmsDyna::RestoreStaticState
              (*(void **)(this + 0x58),param_1,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::RotateOf
// =================================================
void __thiscall CHmsCorpus::RotateOf(CHmsCorpus *this,CHmsCorpus *param_1,GmMat3 *param_2)
{
{
  GmIso3 *pGVar1;
  int unaff_ESI;
  GmIso3 *in_stack_ffffffd0;
  GmMat3 *in_stack_ffffffd4;
  GmIso4 *in_stack_ffffffd8;
  CPlugTree aCStack_24 [28];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(void **)(this + 0x58) != (void *)0x0) {
    CHmsDyna::RotateOf(*(void **)(this + 0x58),param_1,param_2);
    return;
  }
  GmMat3::Set(&stack0xffffffd0,(CMwCmdScriptVarBool *)param_1,unaff_ESI);
  pGVar1 = (GmIso3 *)(**(code **)(*(int *)this + 0x78))();
  uStack_8 = *(undefined4 *)(pGVar1 + 0x24);
  uStack_4 = *(undefined4 *)(pGVar1 + 0x28);
  GmMat3::Mult(&stack0xffffffd4,pGVar1,in_stack_ffffffd0);
  GmMat3::OrthoNormalize(&stack0xffffffd8,in_stack_ffffffd4);
  SetLocation(this,aCStack_24,in_stack_ffffffd8);
  return;
}
}

// =================================================
// Function: CHmsCorpus::SetItem
// =================================================
void __thiscall CHmsCorpus::SetItem(CHmsCorpus *this,CHmsCorpus *param_1,CHmsItem *param_2)
{
{
  CHmsDyna *pCVar1;
  void *pvVar2;
  void *extraout_EAX;
  CHmsDyna *unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a9618b;
  local_c = ExceptionList;
  pCVar1 = (CHmsDyna *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  pvVar2 = *(void **)(this + 0x58);
  *(CHmsCorpus **)(this + 0x48) = param_1;
  if (pvVar2 != (void *)0x0) {
    CHmsDyna::~CHmsDyna(pvVar2,pCVar1);
    operator_delete(pvVar2);
  }
  *(undefined4 *)(this + 0x58) = 0;
  if ((*(uint *)(param_1 + 0x18) >> 0xb & 3) != 0) {
    pvVar2 = operator_new(0x590);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      CHmsDyna::CHmsDyna(pvVar2,unaff_EDI);
      pvVar2 = extraout_EAX;
    }
    *(void **)(this + 0x58) = pvVar2;
    CHmsDyna::SetDynamicType
              (pvVar2,(CHmsItem *)((*(uint *)(param_1 + 0x18) >> 0xb & 3) - 1),
               (EDynamicType)unaff_EDI);
  }
  RefreshFromSolid(this,(CHmsCorpus *)unaff_EDI);
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CHmsCorpus::SetLocation
// =================================================
void __thiscall CHmsCorpus::SetLocation(CHmsCorpus *this,CPlugTree *param_1,GmIso4 *param_2)
{
{
  void *this_00;
  int iVar1;
  CPlugTree *pCVar2;
  CHmsCorpus *pCVar3;
  
  this_00 = *(void **)(this + 0x58);
  pCVar2 = param_1;
  pCVar3 = this + 0x18;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    pCVar3 = pCVar3 + 4;
  }
  if (this_00 != (void *)0x0) {
    CHmsDyna::SetLocation(this_00,param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::SetTranslation
// =================================================
void __thiscall CHmsCorpus::SetTranslation(CHmsCorpus *this,GmIso4 *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)param_1;
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 8);
  if (*(void **)(this + 0x58) != (void *)0x0) {
    CHmsDyna::SetTranslation(*(void **)(this + 0x58),param_1,param_2);
    return;
  }
  return;
}
}

// =================================================
// Function: CHmsCorpus::WaterGetPlaneEqInZone
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CHmsCorpus::WaterGetPlaneEqInZone(CHmsCorpus *this,CHmsCorpus *param_1,GmVec4 *param_2)
{
{
  CPlugShader *this_00;
  CPlugBitmapRender *pCVar1;
  GmIso3 *pGVar2;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  void *in_stack_00000010;
  undefined4 *in_stack_00000018;
  CPlugBitmapAddress **in_stack_ffffffa0;
  CPlugTree *in_stack_ffffffa4;
  GmIso3 *in_stack_ffffffa8;
  GmIso4 *in_stack_ffffffac;
  CFastBuffer<class_CPlugFileGPUV*> *in_stack_ffffffb0;
  int local_4c [2];
  float local_44;
  int local_40;
  undefined1 auStack_38 [8];
  CPlugTree local_30 [4];
  undefined1 auStack_2c [4];
  GmVec4 aGStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a961b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(*(int *)(this + 0x48) + 0x14) != 0) {
    CPlugTree::CIteratorShader::CIteratorShader
              (&stack0xffffffb0,*(CIteratorShader **)(*(int *)(*(int *)(this + 0x48) + 0x14) + 100),
               (CPlugTree *)0x0,(EMode)((uint)DAT_00cca150 ^ (uint)&stack0xffffff9c));
    while (local_40 != 0) {
      this_00 = CPlugTree::CIteratorShader::GetNextShader
                          (local_4c,(CIteratorShader *)&stack0xffffffa4,(CPlugTree **)unaff_ESI);
      if ((*(uint *)(this_00 + 0x20) & 0xc00000) == 0x800000) {
        unaff_ESI = (CFastBuffer<class_CPlugFileGPUV*> *)0x0;
        pCVar1 = CPlugShader::FindBitmapRenderByClassId
                           (this_00,(CPlugShader *)0x9087000,0,(CPlugBitmap **)0x0,in_stack_ffffffa0
                           );
        if (pCVar1 != (CPlugBitmapRender *)0x0) {
          CPlugTree::GetThisToRootTransfo
                    ((CPlugTree *)in_stack_ffffffac,local_30,(GmIso4 *)0x1,0,in_stack_ffffffa4);
          pGVar2 = (GmIso3 *)(**(code **)(*(int *)this + 0x78))();
          GmIso4::Mult(auStack_2c,pGVar2,in_stack_ffffffa8);
          local_44 = *(float *)(*(int *)(local_4c[0] + 0x90) + 0x38);
          *in_stack_00000018 = 0;
          in_stack_00000018[1] = 0x3f800000;
          in_stack_00000018[2] = 0;
          in_stack_00000018[3] = ((float)_DAT_00b56ec0 * 0.0 - local_44) - 0.0;
          GmVec4::PlaneEqMult(in_stack_00000018,aGStack_28,in_stack_ffffffac);
          CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
                    (auStack_38,in_stack_ffffffb0);
          ExceptionList = in_stack_00000010;
          return 1;
        }
      }
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(local_4c,unaff_ESI);
  }
  ExceptionList = pvStack_4;
  return 0;
}
}

// =================================================
// Function: CHmsCorpus::_vector_deleting_destructor_
// =================================================
void * __thiscall
CHmsCorpus::_vector_deleting_destructor_(CHmsCorpus *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CHmsCorpus *unaff_ESI;
  
  ~CHmsCorpus(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CHmsCorpus::~CHmsCorpus
// =================================================
void __thiscall CHmsCorpus::~CHmsCorpus(CHmsCorpus *this,CHmsCorpus *param_1)
{
{
  void *this_00;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar1;
  CHmsDyna *unaff_ESI;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EDI;
  void *unaff_retaddr;
  CHmsZoneElem *this_01;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00a961e8;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CPlugFileGPUV*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  this_00 = *(void **)(this + 0x4c);
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              ((void *)((int)this_00 + 0xc),pCVar1);
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,unaff_EDI);
    operator_delete(this_00);
  }
  this_01 = *(CHmsZoneElem **)(this + 0x58);
  if (this_01 != (CHmsZoneElem *)0x0) {
    CHmsDyna::~CHmsDyna(this_01,unaff_ESI);
    operator_delete(this_01);
    unaff_ESI = (CHmsDyna *)this_01;
  }
  CHmsZoneElem::~CHmsZoneElem((CHmsZoneElem *)this,(CHmsZoneElem *)unaff_ESI);
  ExceptionList = unaff_retaddr;
  return;
}
}

