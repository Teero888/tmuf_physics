// Class implementation: SGridAddChildContext

// =================================================
// Function: SGridAddChildContext::AddChild
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

CControlBase * __thiscall
SGridAddChildContext::AddChild
          (void *this,SGridAddChildContext *param_1,char *param_2,CMwNod *param_3,char *param_4,
          ulong param_5)
{
{
  int iVar1;
  CControlBase *pCVar2;
  CMwNod *local_c;
  float local_8;
  undefined4 local_4;
  
  local_c = (CMwNod *)0x0;
  local_8 = (float)(int)param_4;
  if ((int)param_4 < 0) {
    local_8 = local_8 + _DAT_00c418d0;
  }
  local_4 = 0;
  iVar1 = *(int *)*(CControlContainer **)this;
  pCVar2 = CControlContainer::CreateControl
                     (*(CControlContainer **)this,(CControlContainer *)param_1,(char *)param_1,
                      "Label",(char *)0x0,(CMwNod *)0x0,*(char **)((int)this + 4),
                      (CControlStyle *)&local_c);
  (**(code **)(iVar1 + 0x1f8))(pCVar2);
  pCVar2 = CControlBase::CreateFromStack
                     ((CMwNod *)param_1,param_2,*(CControlStyle **)((int)this + 4),1);
  if (pCVar2 != (CControlBase *)0x0) {
    local_c = param_3;
    local_8 = 0.0;
    (**(code **)(**(int **)this + 0x1f8))(pCVar2,&stack0xfffffff0);
  }
  return pCVar2;
}
}

