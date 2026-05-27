// Class implementation: CSceneObject

// =================================================
// Function: CSceneObject::CSceneObject
// =================================================
void __thiscall CSceneObject::CSceneObject(CSceneObject *this,CSceneObject *param_1)
{
{
  CMwId *unaff_ESI;
  CMwNod *unaff_EDI;
  void *unaff_retaddr;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acbda8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x18,unaff_ESI);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CSceneObject::Chunk
// =================================================
void __thiscall
CSceneObject::Chunk(CSceneObject *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CFuncSegment *pCVar1;
  CFuncSegment *pCVar2;
  int iVar3;
  CClassicArchive *unaff_EDI;
  CMwNod *pCVar4;
  
  pCVar1 = param_1;
  if (param_2 < (CClassicArchive *)0xa005004) {
    if (param_2 == (CClassicArchive *)0xa005003) {
      param_2 = *(CClassicArchive **)(this + 0x20);
      if (((*(int *)(param_1 + 8) != 0) && (param_2 != (CClassicArchive *)0x0)) &&
         (iVar3 = (**(code **)(*(int *)param_2 + 0xc4))(), iVar3 == 0)) {
        param_2 = (CClassicArchive *)0x0;
      }
      pCVar4 = (CMwNod *)&param_2;
      (**(code **)(*(int *)pCVar1 + 4))();
      pCVar2 = param_1;
      if ((*(int *)(pCVar1 + 8) == 0) && (param_1 != *(CFuncSegment **)(this + 0x20))) {
        if (param_1 != (CFuncSegment *)0x0) {
          CMwNod::MwAddRef((CMwNod *)param_1,pCVar4);
        }
        if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0x20),pCVar4);
        }
        *(CFuncSegment **)(this + 0x20) = pCVar2;
      }
    }
    else if (param_2 != (CClassicArchive *)0xa005000) {
      if (param_2 == (CClassicArchive *)0xa005001) {
        CMwId::Archive(this + 0x18,(CFastCrypt<unsigned_long> *)param_1,unaff_EDI);
        return;
      }
      if (param_2 == (CClassicArchive *)0xa005002) {
        CClassicArchive::DoBool
                  ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(int *)0x1,
                   (ulong)unaff_EDI);
        return;
      }
      goto LAB_007b5ab6;
    }
  }
  else {
    if (param_2 == (CClassicArchive *)0xa005004) {
      CClassicArchive::DoNatural
                ((CClassicArchive *)param_1,(CClassicArchive *)&param_1,(ulong *)0x1,0,
                 (int)unaff_EDI);
      return;
    }
    if (param_2 != (CClassicArchive *)0xffffffff) {
LAB_007b5ab6:
      CMwNod::Chunk((CMwNod *)this,param_1,param_2,(ulong)unaff_EDI);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CSceneObject::GetChunkInfo
// =================================================
ulong __thiscall CSceneObject::GetChunkInfo(CSceneObject *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 < (CFuncSegment *)0xa005004) {
    if (param_1 == (CFuncSegment *)0xa005003) {
      return 3;
    }
    if (param_1 != (CFuncSegment *)0xa005000) {
      if (param_1 == (CFuncSegment *)0xa005001) {
        return 3;
      }
      if (param_1 != (CFuncSegment *)0xa005002) goto LAB_007b56fe;
    }
  }
  else if (param_1 != (CFuncSegment *)0xa005004) {
    if (param_1 == (CFuncSegment *)0xffffffff) {
      return 0xffffffff;
    }
LAB_007b56fe:
    uVar1 = CMwNod::GetChunkInfo((CMwNod *)this,param_1,param_2);
    return uVar1;
  }
  return 1;
}
}

// =================================================
// Function: CSceneObject::OnEnterScene
// =================================================
void __thiscall CSceneObject::OnEnterScene(CSceneObject *this,CSceneToyBroomstick *param_1)
{
{
  *(uint *)(this + 0x24) = *(uint *)(this + 0x24) | 0x1000;
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 0xb8))(*(undefined4 *)(this + 0x14));
  }
  return;
}
}

// =================================================
// Function: CSceneObject::OnLeaveScene
// =================================================
void __thiscall CSceneObject::OnLeaveScene(CSceneObject *this,CSceneToyRock *param_1)
{
{
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 0xc0))(*(undefined4 *)(this + 0x14));
    (**(code **)(**(int **)(this + 0x20) + 0x80))();
  }
  *(uint *)(this + 0x24) = *(uint *)(this + 0x24) & 0xffffefff;
  return;
}
}

// =================================================
// Function: CSceneObject::OnNodLoaded
// =================================================
void __thiscall CSceneObject::OnNodLoaded(CSceneObject *this,CDx9DeviceCaps *param_1)
{
{
  if (*(int **)(this + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x20) + 0x94))(this);
                    /* WARNING: Could not recover jumptable at 0x007b5b51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x20) + 0xa4))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneObject::RemoveFromScene
// =================================================
void __thiscall CSceneObject::RemoveFromScene(CSceneObject *this,CSceneObject *param_1)
{
{
  if (*(int *)(this + 0x14) != 0) {
    (**(code **)(**(int **)(this + 0x14) + 0x7c))(this);
  }
  return;
}
}

// =================================================
// Function: CSceneObject::RemoveMotion
// =================================================
void __thiscall
CSceneObject::RemoveMotion(CSceneObject *this,CSceneObject *param_1,CMotion *param_2)
{
{
  int iVar1;
  ulong uVar2;
  CMwNod *this_00;
  CMwNod *unaff_EDI;
  CMotion *pCVar3;
  CFastBuffer<class_CCrystalFace*> *pCVar4;
  
  this_00 = *(CMwNod **)(this + 0x20);
  if (param_1 != (CSceneObject *)this_00) {
    if (this_00 == (CMwNod *)0x0) {
      return;
    }
    pCVar4 = (CFastBuffer<class_CCrystalFace*> *)0x8028000;
    pCVar3 = (CMotion *)0x7b5cdf;
    iVar1 = (**(code **)(*(int *)this_00 + 0x10))();
    if (iVar1 == 0) {
      return;
    }
    CMotions::RemoveMotion(*(CMotions **)(this + 0x20),param_1,pCVar3);
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount
                      ((void *)(*(int *)(this + 0x20) + 0x18),pCVar4);
    if (uVar2 != 0) {
      return;
    }
    this_00 = *(CMwNod **)(this + 0x20);
  }
  if (this_00 != (CMwNod *)0x0) {
    CMwNod::MwRelease(this_00,unaff_EDI);
    *(undefined4 *)(this + 0x20) = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneObject::SceneLocGet
// =================================================
SSceneLoc __thiscall CSceneObject::SceneLocGet(CSceneObject *this,CSceneObject *param_1)
{
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *unaff_retaddr;
  
  uVar1 = (**(code **)(*(int *)this + 0x78))();
  puVar2 = (undefined4 *)(**(code **)(*(int *)this + 0x7c))(uVar1);
  puVar4 = unaff_retaddr;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  unaff_retaddr[0xc] = uVar1;
  return SUB41(unaff_retaddr,0);
}
}

// =================================================
// Function: CSceneObject::SetMotion
// =================================================
CMotion * __thiscall
CSceneObject::SetMotion(CSceneObject *this,CSceneObject *param_1,CMwNod *param_2,int param_3)
{
{
  CSceneObject *this_00;
  CMwNod *pCVar1;
  int iVar2;
  CMwNod *this_01;
  CMotions *this_02;
  CMotions *extraout_EAX;
  CSceneObject *unaff_ESI;
  int unaff_EDI;
  CMotions *this_03;
  CMwNod *in_stack_ffffffc4;
  CMwId *in_stack_ffffffc8;
  int in_stack_ffffffcc;
  CMwNod *in_stack_ffffffd0;
  CMwId *pCVar3;
  CGameCamera *pCVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acbe0b;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  ExceptionList = &local_c;
  this_01 = (CMwNod *)0x0;
  if (param_1 != (CSceneObject *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x8001000);
    if (iVar2 == 0) {
      this_01 = (CMwNod *)CMotionEngine::CreateMotionFromNod((CMwNod *)this,(CMwNod *)param_1);
    }
    else {
      (**(code **)(*(int *)param_1 + 0x94))(this);
      this_01 = (CMwNod *)param_1;
    }
  }
  if (param_2 != (CMwNod *)0x0) {
    this_00 = this + 0x20;
    if ((*(int **)(this + 0x20) != (int *)0x0) && (this_01 != (CMwNod *)0x0)) {
      pCVar4 = (CGameCamera *)0x8028000;
      iVar2 = (**(code **)(**(int **)(this + 0x20) + 0x10))();
      if (iVar2 == 0) {
        this_02 = operator_new(0x24);
        this_03 = (CMotions *)0x0;
        puStack_8 = (undefined1 *)0x0;
        if (this_02 != (CMotions *)0x0) {
          CMotions::CMotions(this_02,(CMotions *)pCVar4);
          this_03 = extraout_EAX;
        }
        puStack_8 = (undefined1 *)0xffffffff;
        pCVar3 = (CMwId *)0x7b5c4a;
        (**(code **)(*(int *)this_03 + 0x94))();
        CMotions::AddMotion(this_03,unaff_ESI,in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc)
        ;
        CMotions::AddMotion(this_03,(CSceneObject *)this_01,in_stack_ffffffd0,pCVar3,(int)this);
      }
      else {
        iVar2 = (**(code **)(*(int *)this_01 + 0x10))(0x8028000);
        this_03 = (CMotions *)this_01;
        if (iVar2 == 0) {
          CMotions::AddMotion(*(CMotions **)this_00,(CSceneObject *)this_01,(CMwNod *)pCVar4,
                              (CMwId *)pCVar1,unaff_EDI);
          ExceptionList = local_c;
          return (CMotion *)this_01;
        }
      }
      CMwNodRef<class_CGameCamera>::MwSetNod(this_00,(CMwNodRef<class_CGameCamera> *)this_03,pCVar4)
      ;
      ExceptionList = local_c;
      return (CMotion *)this_01;
    }
  }
  if (this_01 != *(CMwNod **)(this + 0x20)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,pCVar1);
    }
    if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x20),pCVar1);
    }
    *(CMwNod **)(this + 0x20) = this_01;
  }
  ExceptionList = local_c;
  return (CMotion *)this_01;
}
}

// =================================================
// Function: CSceneObject::VirtualParam_Add
// =================================================
ulong __thiscall
CSceneObject::VirtualParam_Add
          (CSceneObject *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if ((iVar2 != 0xa005001) && (iVar2 != -1)) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Add((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneObject::VirtualParam_Get
// =================================================
ulong __thiscall
CSceneObject::VirtualParam_Get
          (CSceneObject *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwValueStd *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa005001) {
    if (iVar1 + -1 < 0) {
      *(CMwNod **)param_2 = DAT_00bc61c0;
      return 0;
    }
    CMwNod::Param_Get(DAT_00bc61c0,(CMwNod *)param_1,param_2,unaff_ESI);
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneObject::VirtualParam_Set
// =================================================
ulong __thiscall
CSceneObject::VirtualParam_Set
          (CSceneObject *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  ulong *unaff_EBX;
  CFastStringInt *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa005001) {
    param_2 = (CMwStack *)0xffffffff;
    uVar3 = CMwStack::GetArgument
                      ((CMwStack *)param_1,(CMwStack *)0x0,0x10000004,(EStackType)&param_2,unaff_EBX
                      );
    puVar4 = (undefined4 *)
             CMwStack::GetArgument
                       ((CMwStack *)param_1,(CMwStack *)0x1,0x10000002,(EStackType)&param_3,
                        (ulong *)unaff_EDI);
    if ((uVar3 != 0) && (puVar4 != (undefined4 *)0x0)) {
      (**(code **)(*(int *)this + 0x88))(uVar3,*puVar4);
    }
  }
  else {
    if (iVar2 == 0xa005002) {
      if (-1 < iVar1 + -1) {
        CMwNod::Param_Set(*(CMwNod **)(this + 0x20),(CMwNod *)param_1,(CFastString *)param_2,
                          unaff_EDI);
        return 0;
      }
      (**(code **)(*(int *)this + 0xa8))(param_2,0);
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_EDI);
      return uVar3;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSceneObject::VirtualParam_Sub
// =================================================
ulong __thiscall
CSceneObject::VirtualParam_Sub
          (CSceneObject *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if ((iVar2 != 0xa005001) && (iVar2 != -1)) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Sub((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneObject::~CSceneObject
// =================================================
void __thiscall CSceneObject::~CSceneObject(CSceneObject *this,CSceneObject *param_1)
{
{
  CMwNod *pCVar1;
  CFastStringInt *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00acbde3;
  local_c = ExceptionList;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x1;
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20),pCVar1);
  }
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  CMwNod::~CMwNod((CMwNod *)this,(CMwNod *)unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

