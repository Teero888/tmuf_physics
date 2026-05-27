// Class implementation: CNetFileTransferForm

// =================================================
// Function: CNetFileTransferForm::GetSize
// =================================================
void __thiscall
CNetFileTransferForm::GetSize
          (CNetFileTransferForm *this,CControlGrid *param_1,ulong *param_2,ulong *param_3)
{
{
  SHeaderCommunity *unaff_ESI;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a92ce0;
  local_c = ExceptionList;
  switch(*(undefined4 *)(this + 0x1c)) {
  case 0:
    return;
  case 1:
    return;
  case 2:
    local_14 = 0;
    local_10 = PTR_DAT_00bbf7d8;
    local_4 = (void *)0x0;
    ExceptionList = &local_c;
    CFastStringInt::GetUtf8
              (this + 0x6c,(CFastStringInt *)&local_14,(CFastString *)0x0,
               DAT_00cca150 ^ (uint)&stack0xffffffe8);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_10,unaff_ESI);
    ExceptionList = local_4;
    return;
  case 3:
    return;
  case 4:
    break;
  case 5:
    return;
  case 6:
    local_14 = 0;
    local_10 = PTR_DAT_00bbf7d8;
    local_4 = (void *)0x1;
    ExceptionList = &local_c;
    CFastStringInt::GetUtf8
              (this + 0x6c,(CFastStringInt *)&local_14,(CFastString *)0x0,
               DAT_00cca150 ^ (uint)&stack0xffffffe8);
    CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_10,unaff_ESI);
    ExceptionList = local_4;
    return;
  default:
    return;
  }
  if (*(int *)(this + 0x88) != 0) {
    ExceptionList = &local_c;
    (**(code **)(**(int **)(this + 0x88) + 0x18))();
  }
  ExceptionList = local_c;
  return;
}
}

