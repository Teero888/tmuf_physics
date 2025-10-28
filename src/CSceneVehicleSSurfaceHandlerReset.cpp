
/* public: void __thiscall CSceneVehicle::SSurfaceHandler::Reset(void) */

void __thiscall CSceneVehicle::SSurfaceHandler::Reset(SSurfaceHandler *this)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar2 = (undefined4 *)(this + 4);
  puVar3 = (undefined4 *)(this + 0x34);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
