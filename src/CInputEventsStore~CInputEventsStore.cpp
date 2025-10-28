
/* public: __thiscall CInputEventsStore::~CInputEventsStore(void) */

void __thiscall CInputEventsStore::~CInputEventsStore(CInputEventsStore *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00a84cd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = 1;
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x38));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x2c));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)(this + 0x20));
  CFastBuffer<>::~CFastBuffer<>((CFastBuffer<> *)this);
  ExceptionList = local_c;
  return;
}
