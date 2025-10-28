
/* public: void __thiscall CHmsDyna::SetDynamicType(enum CHmsDyna::EDynamicType)
 */

void __thiscall CHmsDyna::SetDynamicType(CHmsDyna *this, EDynamicType param_1)

{
  int iVar1;

  *(EDynamicType *)(this + 0x340) = param_1;
  iVar1 = *(int *)(this + 0x328);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  iVar1 = *(int *)(this + 0x328);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  iVar1 = *(int *)(this + 0x32c);
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  return;
}
