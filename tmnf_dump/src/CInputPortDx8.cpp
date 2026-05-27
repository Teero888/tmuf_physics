// Class implementation: CInputPortDx8

// =================================================
// Function: CInputPortDx8::ApplyMouseSettings
// =================================================
void __thiscall CInputPortDx8::ApplyMouseSettings(CInputPortDx8 *this,CInputPortDx8 *param_1)
{
{
  bool bVar1;
  bool bVar2;
  ulong *puVar3;
  int iVar4;
  uint uVar5;
  uint bShow;
  char cVar6;
  CMwTimerAdapter *unaff_EDI;
  int unaff_retaddr;
  int local_c;
  int local_8;
  int local_4;
  
  if (DAT_00d72ebc == 0) {
    puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
    iVar4 = *(int *)(this + 0x20);
    if ((iVar4 == 0) || (bVar2 = true, *(int *)(iVar4 + 0x18) == 0)) {
      bVar2 = false;
    }
    cVar6 = !bVar2;
    if ((iVar4 == 0) || ((*(int *)(iVar4 + 0x14) != 0 && (*(int *)(iVar4 + 0x1c) == 0)))) {
      cVar6 = '\x02';
    }
    if (*(int *)(this + 0x9c) != 0) {
      cVar6 = '\0';
    }
    if ((*(int *)(this + 0x90) == 0) || (*(int *)(this + 0x94) != 0)) {
      cVar6 = '\x02';
      bVar1 = false;
    }
    else if ((cVar6 == '\0') || ((cVar6 == '\x01' && (*(int *)(this + 0xe8) + 5000U < *puVar3)))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((PTR_DAT_00cdae90 != (undefined *)0x0) &&
       (*(uint *)(PTR_DAT_00cdae90 + 0xc) = (uint)!bVar1, *(int *)PTR_DAT_00cdae90 != 0)) {
      bVar1 = true;
    }
    bShow = (uint)!bVar1;
    uVar5 = *(uint *)(this + 0xf4);
    while ((uVar5 != 0) != bShow) {
      iVar4 = ShowCursor(bShow);
      if (iVar4 == -1) {
        *(uint *)(this + 0xf4) = bShow;
        break;
      }
      uVar5 = (uint)(-1 < iVar4);
      *(uint *)(this + 0xf4) = uVar5;
    }
    if ((bVar2) && (cVar6 == '\0')) {
      GetWindowRect(*(HWND *)(*(int *)(this + 0xd0) + 0x90),(LPRECT)&local_c);
      SetCursorPos((local_4 - local_c) / 2 + local_c,(unaff_retaddr - local_8) / 2 + local_8);
    }
  }
  return;
}
}

// =================================================
// Function: CInputPortDx8::NotifyMouseWheel
// =================================================
void __thiscall
CInputPortDx8::NotifyMouseWheel(CInputPortDx8 *this,CInputPortDx8 *param_1,float param_2)
{
{
  void *this_00;
  SInputEvent *pSVar1;
  CMwTimerAdapter *unaff_ESI;
  ulong in_stack_fffffff8;
  undefined *local_4;
  
  if ((((DAT_00d72ebc == 0) && (*(int *)(this + 0x34) != 2)) && (*(int *)(this + 0x20) != 0)) &&
     (*(int *)(*(int *)(this + 0x20) + 0x14) != 0)) {
    if (*(int *)(this + 0x34) == 0) {
      this_00 = *(void **)(DAT_00d731e0 + 0x14);
      if (this_00 == (void *)0x0) {
        this_00 = (void *)(DAT_00d731e0 + 0xa0);
      }
      pSVar1 = (SInputEvent *)CMwTimerAdapter::GetTime(this_00,unaff_ESI);
    }
    else {
      pSVar1 = *(SInputEvent **)(this + 0x38);
    }
    local_4 = PTR_DAT_00d1fc68;
    CInputEventsStore::InsertSorted
              (this + 0x40,(CInputEventsStore *)&local_4,pSVar1,in_stack_fffffff8);
  }
  return;
}
}

// =================================================
// Function: CInputPortDx8::UpdateAsync
// =================================================
void __thiscall CInputPortDx8::UpdateAsync(CInputPortDx8 *this,CInputPortDx8 *param_1)
{
{
  CInputPortDx8 *unaff_ESI;
  CInputPortDx8 *in_stack_00000008;
  
  CInputPort::UpdateAsync((CInputPort *)this,unaff_ESI);
  ApplyMouseSettings(this,in_stack_00000008);
  return;
}
}

