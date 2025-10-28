
/* public: virtual __thiscall
 * CTrackManiaPlayerInfo::~CTrackManiaPlayerInfo(void) */

void __thiscall CTrackManiaPlayerInfo::~CTrackManiaPlayerInfo(
    CTrackManiaPlayerInfo *this)

{
  wchar_t *pwVar1;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a8baf0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 4;
  SRpcPlayerQuickInfo::~SRpcPlayerQuickInfo(
      (SRpcPlayerQuickInfo *)(this + 0x39c));
  CInputEventsStore::~CInputEventsStore((CInputEventsStore *)(this + 0x350));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x324));
  pwVar1 = *(wchar_t **)(this + 0x310);
  if (pwVar1 != L"") {
    if ((*(byte *)((int)pwVar1 + -1) & 0x80) == 0) {
      pwVar1 = pwVar1 + -1;
    } else {
      pwVar1 = pwVar1 + -2;
    }
    operator_delete[](pwVar1);
    *(undefined4 *)(this + 0x30c) = 0;
    *(wchar_t **)(this + 0x310) = L"";
  }
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 0x300));
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 0x2f8));
  local_4 = 0xffffffff;
  CGamePlayerInfo::~CGamePlayerInfo((CGamePlayerInfo *)this);
  ExceptionList = local_c;
  return;
}
