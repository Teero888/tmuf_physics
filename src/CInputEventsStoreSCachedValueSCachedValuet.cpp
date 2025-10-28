
/* public: __thiscall CInputEventsStore::SCachedValue::SCachedValue(unsigned
 * long) */

void __thiscall CInputEventsStore::SCachedValue::SCachedValue(
    SCachedValue *this, ulong param_1)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(ulong *)(this + 8) = param_1 << 0x18;
  return;
}
