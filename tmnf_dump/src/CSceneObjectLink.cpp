// Class implementation: CSceneObjectLink

// =================================================
// Function: CSceneObjectLink::CSceneObjectLink
// =================================================
void __thiscall CSceneObjectLink::CSceneObjectLink(CSceneObjectLink *this,CSceneObjectLink *param_1)
{
{
  CMwCmdFastCall *this_00;
  CMwNod *extraout_EAX;
  CMwId *unaff_EBP;
  CMwId *unaff_ESI;
  CMwNod *unaff_EDI;
  CMwNod *this_01;
  undefined1 uStack00000008;
  void *in_stack_0000000c;
  undefined1 uStack00000010;
  undefined1 uStack00000014;
  CSceneObjectLink *pCVar1;
  ulong in_stack_fffffff0;
  CMwNod *pCVar2;
  
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe0),unaff_EDI);
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x18) = 0;
  CMwId::CMwId(this + 0x24,unaff_ESI);
  uStack00000008 = 2;
  CMwId::CMwId(this + 0x28,unaff_EBP);
  *(undefined4 *)(this + 0x60) = 0;
  in_stack_0000000c = (void *)CONCAT31(in_stack_0000000c._1_3_,4);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(uint *)(this + 0x14) = *(uint *)(this + 0x14) & 0xffffffd0 | 0x10;
  GmIso4::SetIdentity(this + 0x2c,(GmMat43 *)pCVar1);
  *(uint *)(this + 0x14) = *(uint *)(this + 0x14) & 0x3f;
  this_00 = operator_new(0x24);
  uStack00000010 = 5;
  if (this_00 == (CMwCmdFastCall *)0x0) {
    this_01 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (this_00,(CMwCmdFastCall *)this,(CMwNod *)_vcall__120__flat______,
               (_func___cdecl_void *)0x19,in_stack_fffffff0);
    this_01 = extraout_EAX;
  }
  uStack00000014 = 4;
  if (this_01 != *(CMwNod **)(this + 0x60)) {
    if (this_01 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_01,pCVar2);
    }
    if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x60),pCVar2);
    }
    *(CMwNod **)(this + 0x60) = this_01;
  }
  ExceptionList = in_stack_0000000c;
  return;
}
}

// =================================================
// Function: CSceneObjectLink::InternalUpdateIsInstalled
// =================================================
void __thiscall
CSceneObjectLink::InternalUpdateIsInstalled(CSceneObjectLink *this,CSceneObjectLink *param_1)
{
{
  code *pcVar1;
  
  if (((*(int *)(this + 0x5c) == 0) || (((byte)this[0x14] & 1) == 0)) ||
     ((*(int *)(this + 0x1c) != 0 &&
      ((*(uint *)(*(int *)(*(int *)(this + 0x1c) + 0x28) + 0x18) & 0x100) != 0)))) {
    pcVar1 = *(code **)(**(int **)(this + 0x60) + 0x80);
  }
  else {
    pcVar1 = *(code **)(**(int **)(this + 0x60) + 0x7c);
  }
  (*pcVar1)();
  if (((*(int *)(this + 0x5c) != 0) && (((byte)this[0x14] & 1) != 0)) &&
     ((*(byte *)(*(int *)(this + 0x60) + 0x18) & 1) == 0)) {
                    /* WARNING: Could not recover jumptable at 0x007b65d6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)this + 0x78))();
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneObjectLink::OnEnterScene
// =================================================
void __thiscall CSceneObjectLink::OnEnterScene(CSceneObjectLink *this,CSceneToyBroomstick *param_1)
{
{
  CSceneObjectLink *unaff_retaddr;
  
  *(CSceneToyBroomstick **)(this + 0x5c) = param_1;
  InternalUpdateIsInstalled(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneObjectLink::OnLeaveScene
// =================================================
void __thiscall CSceneObjectLink::OnLeaveScene(CSceneObjectLink *this,CSceneToyRock *param_1)
{
{
  *(undefined4 *)(this + 0x5c) = 0;
  InternalUpdateIsInstalled(this,(CSceneObjectLink *)param_1);
  return;
}
}

// =================================================
// Function: CSceneObjectLink::SetIsActive
// =================================================
void __thiscall
CSceneObjectLink::SetIsActive(CSceneObjectLink *this,CSceneObjectLink *param_1,int param_2)
{
{
  CSceneObjectLink *unaff_retaddr;
  
  *(uint *)(this + 0x14) = *(uint *)(this + 0x14) ^ (*(uint *)(this + 0x14) ^ (uint)param_1) & 1;
  InternalUpdateIsInstalled(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSceneObjectLink::SetMobil
// =================================================
void __thiscall
CSceneObjectLink::SetMobil(CSceneObjectLink *this,CSceneObjectLink *param_1,CSceneMobil *param_2)
{
{
  CPlugTree *unaff_ESI;
  
  SetMobilTree(this,(CSceneObjectLink *)0x0,unaff_ESI);
  *(CSceneMobil **)(this + 0x1c) = param_2;
  return;
}
}

// =================================================
// Function: CSceneObjectLink::SetMobilTree
// =================================================
void __thiscall
CSceneObjectLink::SetMobilTree(CSceneObjectLink *this,CSceneObjectLink *param_1,CPlugTree *param_2)
{
{
  undefined4 *puVar1;
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x20),(CMwNod *)this,unaff_ESI);
  }
  *(CPlugTree **)(this + 0x20) = param_2;
  if (param_2 != (CPlugTree *)0x0) {
    CMwNod::MwAddDependant((CMwNod *)param_2,(CMwNod *)this,unaff_retaddr);
    puVar1 = (undefined4 *)(**(code **)(**(int **)(this + 0x20) + 0x14))();
    *(undefined4 *)(this + 0x24) = *puVar1;
  }
  return;
}
}

// =================================================
// Function: CSceneObjectLink::SetObject
// =================================================
void __thiscall
CSceneObjectLink::SetObject(CSceneObjectLink *this,CSceneObjectLink *param_1,CSceneObject *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CSceneObjectLink **)(this + 0x18)) {
    if (param_1 != (CSceneObjectLink *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x18) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x18),unaff_ESI);
    }
    *(CSceneObjectLink **)(this + 0x18) = param_1;
  }
  return;
}
}

