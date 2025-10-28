
/* public: void __thiscall CInputEventsStore::Lock(unsigned long) */

void __thiscall CInputEventsStore::Lock(CInputEventsStore *this, ulong param_1)

{
  *(ulong *)(this + 0x14) = param_1;
  return;
}
