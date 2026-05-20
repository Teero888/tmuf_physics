// Class implementation: CScenePickerManager

// =================================================
// Function: CScenePickerManager::CScenePickerManager
// =================================================
void __thiscall
CScenePickerManager::CScenePickerManager(CScenePickerManager *this,CScenePickerManager *param_1)
{
{
  CHmsPicker *this_00;
  CMwCmd *extraout_EAX;
  CMwCmd *this_01;
  CScenePickedItem *unaff_EBX;
  CScenePickedItem *unaff_EBP;
  CScenePickedItem *unaff_ESI;
  CMwNod *unaff_EDI;
  _func___cdecl_void_CScenePickedItem_ptr *unaff_retaddr;
  ulong in_stack_00000008;
  ulong in_stack_0000000c;
  CMwNod *in_stack_00000010;
  undefined1 uStack00000014;
  undefined1 uStack00000018;
  CMwCmdFastCall *pCStack0000001c;
  undefined1 uStack00000028;
  void *in_stack_00000030;
  CScenePickerManager *pCVar1;
  CHmsPicker *in_stack_fffffff0;
  CHmsPicker *pCVar2;
  code *pcVar3;
  _func___cdecl_void_CScenePickedItem_ptr *p_Var4;
  
  p_Var4 = (_func___cdecl_void_CScenePickedItem_ptr *)0xffffffff;
  pcVar3 = FUN_00ace236;
  pCVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffdc),unaff_EDI);
  *(undefined ***)this = vftable;
  CScenePickedItem::CScenePickedItem((CScenePickedItem *)(this + 0x14),unaff_ESI);
  in_stack_00000008 = CONCAT31(in_stack_00000008._1_3_,1);
  CScenePickedItem::CScenePickedItem((CScenePickedItem *)(this + 0x174),unaff_EBP);
  in_stack_0000000c = CONCAT31(in_stack_0000000c._1_3_,2);
  CScenePickedItem::CScenePickedItem((CScenePickedItem *)(this + 0x2d4),unaff_EBX);
  this_00 = (CHmsPicker *)(this + 0x434);
  in_stack_00000010 = (CMwNod *)CONCAT31(in_stack_00000010._1_3_,3);
  CHmsPicker::CHmsPicker(this_00,(CHmsPicker *)pCVar1);
  uStack00000014 = 4;
  CHmsPicker::CHmsPicker((CHmsPicker *)(this + 0x540),in_stack_fffffff0);
  *(undefined4 *)(this + 0x504) = 0x3f800000;
  uStack00000018 = 5;
  *(undefined4 *)(this + 0x508) = 0;
  *(undefined4 *)(this + 0x50c) = 0;
  *(undefined4 *)(this + 0x448) = 1;
  CHmsPicker::CopyFromPicker((CHmsPicker *)(this + 0x540),this_00,pCVar2);
  *(CHmsPicker **)(this + 0x64c) = this_00;
  CScenePickedItem::SetKilledCallBack
            ((CScenePickedItem *)(this + 0x14),(CScenePickedItem *)this,(CMwNod *)OnItemKilled,
             pcVar3);
  CScenePickedItem::SetKilledCallBack
            ((CScenePickedItem *)(this + 0x174),(CScenePickedItem *)this,(CMwNod *)OnItemKilled,
             p_Var4);
  CScenePickedItem::SetKilledCallBack
            ((CScenePickedItem *)(this + 0x2d4),(CScenePickedItem *)this,(CMwNod *)EndFocus,
             unaff_retaddr);
  pCStack0000001c = operator_new(0x24);
  uStack00000028 = 6;
  if (pCStack0000001c == (CMwCmdFastCall *)0x0) {
    this_01 = (CMwCmd *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack0000001c,(CMwCmdFastCall *)this,(CMwNod *)UpdateCurPickedItem,
               (_func___cdecl_void *)0x0,in_stack_00000008);
    this_01 = extraout_EAX;
  }
  in_stack_00000030 = (void *)CONCAT31(in_stack_00000030._1_3_,5);
  *(CMwCmd **)(this + 0x65c) = this_01;
  CMwCmd::SetSchemeLocation(this_01,(CMwCmd *)0x21,in_stack_0000000c);
  CMwNod::MwAddRef(*(CMwNod **)(this + 0x65c),in_stack_00000010);
  (**(code **)(**(int **)(this + 0x65c) + 0x7c))();
  *(undefined4 *)(this + 0x650) = 0;
  *(undefined4 *)(this + 0x654) = 0;
  *(undefined4 *)(this + 0x658) = 0;
  ExceptionList = in_stack_00000030;
  return;
}
}

// =================================================
// Function: CScenePickerManager::EndFocus
// =================================================
void __thiscall
CScenePickerManager::EndFocus
          (CScenePickerManager *this,CScenePickerManager *param_1,CScenePickedItem *param_2)
{
{
  CSceneInfoMouse *unaff_EDI;
  CScenePickerManager local_24 [4];
  CScenePickedItem *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FillSceneInfoMouse(this,local_24,unaff_EDI);
  if ((*(int **)(param_2 + 0x14) != (int *)0x0) &&
     (local_14 = *(int *)(param_2 + 0xf0), local_14 != 0)) {
    local_20 = param_2 + 0x18;
    local_1c = *(undefined4 *)(param_2 + 0x124);
    local_18 = *(undefined4 *)(param_2 + 0xec);
    (**(code **)(**(int **)(param_2 + 0x14) + 0xe4))(&local_20);
    CScenePickedItem::Reset((CScenePickedItem *)(this + 0x2d4),(GmFrustumIso4 *)0x1);
    CScenePickedItem::Reset(param_2,(GmFrustumIso4 *)0x1);
  }
  return;
}
}

// =================================================
// Function: CScenePickerManager::FillSceneInfoMouse
// =================================================
void __thiscall
CScenePickerManager::FillSceneInfoMouse
          (CScenePickerManager *this,CScenePickerManager *param_1,CSceneInfoMouse *param_2)
{
{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(this + 0x450);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(this + 0x454);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(this + 0x650);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(this + 0x654);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(this + 0x658);
  return;
}
}

// =================================================
// Function: CScenePickerManager::Reset
// =================================================
void __thiscall CScenePickerManager::Reset(CScenePickerManager *this,GmFrustumIso4 *param_1)
{
{
  CScenePickedItem *unaff_EDI;
  
  if ((*(int *)(this + 0x2e8) != 0) && (*(int *)(this + 0x3c4) != 0)) {
    EndFocus(this,this + 0x2d4,unaff_EDI);
  }
  CScenePickedItem::Reset((CScenePickedItem *)(this + 0x14),(GmFrustumIso4 *)0x1);
  CScenePickedItem::Reset((CScenePickedItem *)(this + 0x174),(GmFrustumIso4 *)0x1);
  *(undefined4 *)(this + 0x50c) = 0;
  *(undefined4 *)(this + 0x508) = 0;
  *(undefined4 *)(this + 0x618) = 0;
  *(undefined4 *)(this + 0x614) = 0;
  return;
}
}

