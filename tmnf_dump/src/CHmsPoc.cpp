// Class implementation: CHmsPoc

// =================================================
// Function: CHmsPoc::CHmsPoc
// =================================================
void __thiscall CHmsPoc::CHmsPoc(CHmsPoc *this,CHmsPoc *param_1)
{
{
  GmMat43 *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a96d48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CHmsZoneElem::CHmsZoneElem
            ((CHmsZoneElem *)this,(CHmsZoneElem *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x54) = 0;
  GmIso4::SetIdentity(this + 0x18,unaff_ESI);
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CHmsPoc::VirtualParam_Set
// =================================================
ulong __thiscall
CHmsPoc::VirtualParam_Set(CHmsPoc *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x6007000) {
    if (*(int *)param_2 == 0) {
      if (*(int *)(this + 0x54) != 0) {
        (**(code **)(*(int *)this + 0x88))();
      }
    }
    else if (*(int *)(this + 0x54) == 0) {
      (**(code **)(*(int *)this + 0x84))();
      return 0;
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CHmsPoc::~CHmsPoc
// =================================================
void __thiscall CHmsPoc::~CHmsPoc(CHmsPoc *this,CHmsPoc *param_1)
{
{
  *(undefined ***)this = vftable;
  CHmsZoneElem::~CHmsZoneElem((CHmsZoneElem *)this,(CHmsZoneElem *)param_1);
  return;
}
}

